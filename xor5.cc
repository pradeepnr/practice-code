// Find the element that appears once othes 3 times
// Given an array where every element occurs three times, except one element which occurs only once.
// Find the element that occurs once. Expected time complexity is O(n) and O(1) extra space.

#include <stdio.h>
#include <limits.h>
#include <vector>
#include <iostream>
#include <bitset>
using namespace std;
typedef vector<int> VI;


int getSingle(int arr[], int n)
{
    int ones = 0;
    int twos = 0;
    int not_threes;

    for(int i=0;i<n;++i) {
    	int ele = arr[i];
    	twos |= ones & ele;
    	ones = ones ^ ele;
    	not_threes = ~(twos & ones);

    	ones &= not_threes;
    	twos &= not_threes;
    }

    return ones;
}

int main() {
	int arr[] = {3, 3, 1, 3, 2, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout<<getSingle(arr, n)<<endl;
	return 0;
}
