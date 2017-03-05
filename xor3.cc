// swap two bits in a number

#include <stdio.h>
#include <limits.h>
#include <vector>
#include <iostream>
#include <bitset>
using namespace std;
typedef vector<int> VI;

int swap(int val, int i, int j);
int main() {
	cout<<swap(6, 1,2)<<endl;
	return 0;
}

int swap(int val, int i, int j)
{
	i--; j--;
	int bit1 = val>>i & 1;
	int bit2 = val>>j & 1;

	int sum = bit1 ^ bit2;

	sum = sum<<i | sum<<j;

	val = val ^ sum;

	return val;
}

