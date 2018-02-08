#include "Bitset.h"
#include <iostream>
#include <string>
#include <random>
#include <time.h>
using namespace std;

int main()
{
	Bitset* set = new Bitset(25);
	
	int counter = 0;
	srand((unsigned)(time(NULL)));

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			set->setBit(counter, rand() % 2);
			cout << "Bit (" << i << ", " << j << ") has the value " << (*set)(i, j) << endl;
			cout << "The " << counter << "th bit has the value " << (*set)[counter] << endl;
			counter++;
		}
	}
	system("pause");

	delete set;
	
	
}