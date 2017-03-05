// add two numbers using xor

#include <stdio.h>
#include <limits.h>
#include <vector>
#include <iostream>
#include <bitset>
using namespace std;
typedef vector<int> VI;

int sum(int i, int j);
int main() {
	cout<<sum(7,4)<<endl;
	return 0;
}

int sum(int x, int y)
{
    while(y) {
    	int carry = x & y;

    	x = x ^ y;

    	y = carry<<1;
    }

    return x;
}

