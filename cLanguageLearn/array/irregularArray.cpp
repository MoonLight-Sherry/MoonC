int testIrregularArray(void)
{
	int numberOfRows = 5;

	int length[5] = { 1,2,3,4,5 };

	int** irregularArray = new int*[numberOfRows];

	for (int i = 0; i <= numberOfRows; i++)
		irregularArray[i] = new int [length[i]];
	
	return 0;
}