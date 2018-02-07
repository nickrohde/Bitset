#include "Bitset.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Bitset* set = new Bitset(25);

	for (int i = 0; i < 25; i++)
	{
		set->setBit(i, 1);
		cout << "Bit " << i  << " after setting it: " << (*set)[i] << endl;
		set->setBit(i, 0);
		cout << "Bit " << i << " after resetting it: " << (*set)[i] << endl;
		cout << " - - - - - - - - - - - - - -" << endl << endl;
	}

	delete set;
	
	system("pause");
}