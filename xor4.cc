// Count number of bits to be flipped to convert A to B

#include <stdio.h>
#include <limits.h>
#include <vector>
#include <iostream>
#include <bitset>
using namespace std;
typedef vector<int> VI;

int count(int val1, int val2);
int main() {
	cout<<count(6, 5)<<endl;
	return 0;
}

int count(int val1, int val2)
{
	int c =0;
	val1 = val1 ^ val2;
	while(val1) {
		if(val1&1)
			c++;
		val1=val1>>1;
	}
	return c;
}

