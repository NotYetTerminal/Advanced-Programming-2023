// Hello World example
// This example shows basic usage of DOM-style API.

#include "rapidjson/document.h"     // rapidjson's DOM-style API
#include "rapidjson/prettywriter.h" // for stringify JSON
#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>
using namespace rapidjson;
using namespace std;

int main(int, char* []) {
    ////////////////////////////////////////////////////////////////////////////
    // 1. Parse a JSON text string to a document.
    std::string line;

    //place example.txt in the same folder in the project as this cpp file is in.
    std::ifstream myfile("Level.json");
    char json[10000] = "";
    int ji = 0;
    if (myfile.is_open())
    {
        while (std::getline(myfile, line))
        {
            for (int i = 0; i < line.length(); i++)
            {
                // line.at(i) returns char at position i in string.
                char c = line.at(i);
                json[ji++] = c;
            }

        }
        myfile.close();
    }
    else
    {

    }




    Document document;  // Default template parameter uses UTF8 and MemoryPoolAllocator.

    // parse the char array into document
    if (document.Parse(json).HasParseError())
        return 1;

    
    printf("\nParsing to document succeeded.\n");
    int  type = document["compressionlevel"].GetInt();
    cout << type;
    ////////////////////////////////////////////////////////////////////////////
    // 2. Access values in document. 

    printf("\nAccess values in document:\n");
    assert(document.IsObject());    // Document is a JSON value represents the root of DOM. Root can be either an object or array.



    const Value& layers = document["layers"]; //layers is an array
    //put in error checking if you want

    assert(layers.IsArray());
    //loop through each...there is only one in element in the layers array in this file,...
    for (SizeType layersIndex = 0; layersIndex < layers.Size(); layersIndex++)
    {

        const Value& data = layers[layersIndex]["data"];
        assert(data.IsArray());
        for (SizeType dataIndex = 0; dataIndex < data.Size(); dataIndex++)
        {   //loop through int  data...
            //note:printf is original way of outputting to screen
            //you can use cout
            printf("a[%d] = %d\n", dataIndex, data[dataIndex].GetInt());

        }
        int w = layers[layersIndex]["height"].GetInt();
        std::cout << w;
        string  type = layers[layersIndex]["type"].GetString();
        std::cout << type;
    }
 
    // adding a 10 to the first data array
    Value& dataArray = document["layers"][0]["data"];
    dataArray.IsArray();
    
      
    dataArray.PushBack(10, document.GetAllocator());
   
    // creating an object
    Value o(kObjectType);

    o.AddMember("secondgid", 10, document.GetAllocator());
    o.AddMember("source", "test.tsx", document.GetAllocator());

    // adding it to tilesets array
    Value& tilesets = document["tilesets"];
    tilesets.PushBack(o, document.GetAllocator());

    printf("\nModified JSON with reformatting:\n");
    std::ofstream outfilefile("LevelAltered.json");
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);
    document.Accept(writer);    
    puts(sb.GetString());
    std::string jsonOut(sb.GetString(), sb.GetSize());
    outfilefile << jsonOut;



    

    return 0;
}
