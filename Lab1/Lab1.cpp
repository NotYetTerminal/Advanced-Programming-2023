#include "functions.h"
// Test for Questions 1 to 8
int main()
{
	std::cout << "Leapyear" << std::endl;
	if (!isLeapYear(1700))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (isLeapYear(1600))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (isLeapYear(2016))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	std::cout << "NumberReversed" << std::endl;
	if (Reversed(123) == 321)
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}

	if (Reversed(1) == 1)
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (Reversed(1234) != 321)
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}

	std::cout << "Palindrome" << std::endl;
	if (isAPalindrome(1))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (isAPalindrome(121))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (!isAPalindrome(1213))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	std::cout << "Prime Number" << std::endl;
	if (isAPrimeNumber(3))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (isAPrimeNumber(2147483647))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (!isAPrimeNumber(4))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	std::cout << "Binary to Decimal" << std::endl;
	if (convertBinarytoDecimal(110) == 6)
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (convertBinarytoDecimal(111) == 7)
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	std::cout << "5 chars to int" << std::endl;
	int convertedInt = input5CharsConvertToInt();
	std::cout << convertedInt << std::endl;

	std::cout << "Triangles" << std::endl;
	drawRightAngledTriangle();
	drawIsocelesTriangle();
	drawIsocelesTriangle2();

	int testValue = 2;
	int testArray[] = {1, 3, 2, 10, 19, 7, 6};
	std::cout << "Find " << testValue << " in ";
	printArrayElements(7, testArray);
	std::cout << std::endl;
	std::cout << "Index: " << find(7, testArray, testValue) << std::endl;
	int testArray2[] = {1, 3, 10, 19, 7, 6};
	std::cout << "Find " << testValue << " in ";
	printArrayElements(6, testArray2);
	std::cout << std::endl;
	std::cout << "Index: " << find(6, testArray2, testValue) << std::endl;

	std::cout << "Find 2nd largest in ";
	printArrayElements(6, testArray2);
	std::cout << std::endl;
	std::cout << "Index: " << find2ndLargest(6, testArray2) << std::endl;
	int testArray3[] = {3, 3, 3};
	std::cout << "Find 2nd largest in ";
	printArrayElements(3, testArray3);
	std::cout << std::endl;
	std::cout << "Index: " << find2ndLargest(3, testArray3) << std::endl;

	int testArray4[] = {1, 2, 4};
	std::cout << "Copy ";
	printArrayElements(3, testArray4);
	std::cout << " to ";
	printArrayElements(3, testArray3);
	std::cout << std::endl;
	copyArraytoArray(3, testArray4, testArray3);
	std::cout << "Arrays ";
	printArrayElements(3, testArray4);
	printArrayElements(3, testArray3);
	std::cout << std::endl;

	int insertingElement = 20;
	int testArray5Size = 10;
	int testArray5[testArray5Size] = {3, 4, 6, 7, 8};
	int testArray5Count = 5;
	int insertIndex = 1;
	std::cout << "Inserting " << insertingElement << " at " << insertIndex << " into ";
	printArrayElements(testArray5Size, testArray5);
	std::cout << std::endl;
	std::cout << "Success: " << insertElement(testArray5Size, testArray5Count, testArray5, insertingElement, insertIndex) << std::endl;
	std::cout << "Count " << testArray5Count << " of ";
	printArrayElements(testArray5Size, testArray5);
	std::cout << std::endl;
	int testArray6Size = 3;
	int testArray6[testArray6Size] = {2, 3, 4};
	int testArray6Count = 3;
	std::cout << "Inserting " << insertingElement << " at " << insertIndex << " into ";
	printArrayElements(testArray6Size, testArray6);
	std::cout << std::endl;
	std::cout << "Success: " << insertElement(testArray6Size, testArray6Count, testArray6, insertingElement, insertIndex) << std::endl;
	std::cout << "Count " << testArray6Count << " of ";
	printArrayElements(testArray6Size, testArray6);
	std::cout << std::endl;

	int testArray7Size = 5;
	int testArray7[testArray7Size] = {1, 2, 3, 4};
	int testArray7Count = 4;
	int deleteIndex = 2;
	std::cout << "Delete at " << deleteIndex << " from ";
	printArrayElements(testArray7Size, testArray7);
	std::cout << std::endl;
	std::cout << "Success: " << deleteElement(testArray7Size, testArray7Count, testArray7, deleteIndex) << std::endl;
	std::cout << "Count " << testArray7Count << " of ";
	printArrayElements(testArray7Size, testArray7);
	std::cout << std::endl;
	deleteIndex = 3;
	std::cout << "Delete at " << deleteIndex << " from ";
	printArrayElements(testArray7Size, testArray7);
	std::cout << std::endl;
	std::cout << "Success: " << deleteElement(testArray7Size, testArray7Count, testArray7, deleteIndex) << std::endl;
	std::cout << "Count " << testArray7Count << " of ";
	printArrayElements(testArray7Size, testArray7);
	std::cout << std::endl;

	int testArray8Size = 6;
	int testArray8[testArray8Size] = {2, 3, 3, 4, 3, 2};
	int countValue = 3;
	std::cout << "Frequency of " << countValue << " in ";
	printArrayElements(testArray8Size, testArray8);
	std::cout << std::endl;
	std::cout << "Frequency: " << frequencyCount(testArray8Size, testArray8, countValue) << std::endl;

	std::cout << "Number of duplicates in ";
	printArrayElements(testArray8Size, testArray8);
	std::cout << " is : " << countDuplicates(testArray8Size, testArray8) << std::endl;

	int testArray9Size = 5;
	int testArray9[testArray9Size] = {1, 2, 3, 4, 5};
	printArrayElements(testArray9Size, testArray9);
	std::cout << " reversed is ";
	reverse(testArray9Size, testArray9);
	printArrayElements(testArray9Size, testArray9);
	std::cout << std::endl;

	printArrayElements(testArray9Size, testArray9);
	std::cout << " left rotated is ";
	rotateLeft(testArray9Size, testArray9);
	printArrayElements(testArray9Size, testArray9);
	std::cout << std::endl;

	int testArray10Size = 6;
	int testArray10[testArray10Size] = {30, 40, 45,80, 60 ,40};
	int flightLength = 85;
	std::cout << "Movie lengths: ";
	printArrayElements(testArray8Size, testArray8);
	std::cout << std::endl;
	std::cout << "Flight of length " << flightLength << " success: " << twoMovies(flightLength, testArray10, testArray10Size) << std::endl;
	flightLength = 190;
	std::cout << "Flight of length " << flightLength << " success: " << twoMovies(flightLength, testArray10, testArray10Size) << std::endl;

	int characterArraySize = 10;
	char characterArray[characterArraySize] = {'h', 'i', ' ', 't', 'h', ' ', '4', '5', ' ', 'r'};
	std::cout << "Number of words in ";
	printArrayElements(characterArraySize, characterArray);
	std::cout << " is " << wordCounter(characterArraySize, characterArray) << std::endl;
}
