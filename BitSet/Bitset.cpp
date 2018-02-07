#include "Bitset.h"
#include <string>
#include <fstream>

using namespace std;

Bitset::Bitset(int size)
{
	int temp = size % __BYTEOFFSET;

	if (temp) // size is not a multiple of 8
	{		
		this->size = size - temp + __BYTEOFFSET;		
	} // end if
	else // size is a multiple of 8
	{
		this->size = size;
	} // end else

	this->capacity = this->size;
	this->set = new char[this->size];

	for (int i = 0; i < this->size; i++)
	{
		set[i] = (char)NULL;
	} // end for
} // end Constructor(int)                             


Bitset::Bitset(std::string s_fileName)
{
	int size = countCharsInFile(s_fileName);

	ifstream file(s_fileName.c_str());

	this->set = new char[size];
	this->capacity = size;
	this->size = size;

	if (file.is_open() && !file.bad())
	{
		char c;
		int counter = 0;
		while (file >> c && counter < size)
		{
			if (c)
			{
				setBit(counter, 1);
			} // end if
			else
			{
				setBit(counter, 0);
			} // end else

			counter++;
		} // end while
	} // end if

	file.close();

}// end Constructor(string, int)


Bitset::Bitset(char ** matrix, int size) : Bitset(size*size)
{
	int counter = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			char temp = matrix[i][j];

			if (temp)
			{
				setBit(counter, 1);
			} // end if
			else
			{
				setBit(counter, 0);
			} // end else

			counter++;
		} // end for j
	} // end for i
} // end Constructor(char**, int)                       


Bitset::Bitset(char ** matrix, int rows, int cols) : Bitset(rows*cols)
{
	int counter = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			char temp = matrix[i][j];

			if (temp)
			{
				setBit(counter, 1);
			} // end if
			else
			{
				setBit(counter, 0);
			} // end else

			counter++;
		} // end for j
	} // end for i
} // end Constructor(char**, int, int)                                 


void Bitset::setBit(int i, int i_val)
{
	int byte = i / __BYTEOFFSET;
	int bit = i % __BYTEOFFSET;

	setBit(byte, bit, i_val);
} // end setBit(int,int)

void Bitset::setBit(int i, int j, int i_val)
{
	char temp = set[i];

	if (i_val && !testBit(i,j)) // bit is to be set and bit is not set
	{

	} // end if
	else if(!i_val && testBit(i,j)) // bit is to be reset and bit is set
	{

	} // end else


}


bool Bitset::testBit(int i, int j)
{
	if (i >= size)
	{
		string error = "Not a valid byte. Received: " + i;
		error += " Expected: 0-" + size;
		throw new invalid_argument(error);
	} // end if

	char temp = set[i];

	switch (j)
	{
	case 0:
		return temp & __BIT0MASK;
	case 1:
		return temp & __BIT1MASK;
	case 2:
		return temp & __BIT2MASK;
	case 3:
		return temp & __BIT3MASK;
	case 4:
		return temp & __BIT4MASK;
	case 5:
		return temp & __BIT5MASK;
	case 6:
		return temp & __BIT6MASK;
	case 7:
		return temp & __BIT7MASK;
	default:
		string error = "Not a valid bit. Received: " + j;
		error += " Expected: 0-7";
		throw new invalid_argument(error);
	} // end switch;
} // end method testBit                                             