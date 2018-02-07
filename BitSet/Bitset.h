#ifndef NULL
#define NULL 0
#endif // !NULL

// offset for byte
#ifndef __BYTEOFFSET
#define __BYTEOFFSET 8
#endif // !__BYTEOFFSET

// masks to extract bit k
#ifndef __BIT0MASK
#define __BIT0MASK 0x01
#endif // !__BIT0MASK
#ifndef __BIT1MASK
#define __BIT1MASK 0x02
#endif // !__BIT1MASK
#ifndef __BIT2MASK
#define __BIT2MASK 0x04
#endif // !__BIT2MASK
#ifndef __BIT3MASK
#define __BIT3MASK 0x08
#endif // !__BIT3MASK
#ifndef __BIT4MASK
#define __BIT4MASK 0x10
#endif // !__BIT4MASK
#ifndef __BIT5MASK
#define __BIT5MASK 0x20
#endif // !__BIT5MASK
#ifndef __BIT6MASK
#define __BIT6MASK 0x40
#endif // !__BIT6MASK
#ifndef __BIT7MASK
#define __BIT7MASK 0x80
#endif // !__BIT7MASK


#ifndef __BITSET_T

#define __BITSET_T


class Bitset
{
private:
	int capacity;
	int size;
	char * set;

	int getBitAt(int i, int j);

	bool testBit(int i, int j);

	int countCharsInFile(std::string s_fileName);

public:
	Bitset(char ** ca_matrix, int i_size); // square matrix of size size

	Bitset(char ** ca_matrix, int i_rows, int i_cols); // matrix with the given # of rows and columns in matrix

	Bitset(int i_size); // size is the number of bits to store

	Bitset(std::string s_fileName); // builds a bitset from the data in the file named s_fileName

	int operator()(int i, int j); // retrieves the bit located in the ith byte, at the offset j
	int operator[](int i); // retrieves the ith bit in the set

	void setBit(int i, int val);
	void setBit(int i, int j, int val);

	void resize(int i_size); // resizes the bitset to the new size

	void writeSetToFile(std::string s_fileName); // writes this bitset to the file named s_fileName

	friend ofstream& operator<<(ofstream&, Bitset); // stream insertion operator for outputting bitset
}; // end Class Bitset









#endif // !__BITSET_T




