// Find the two non-repeating elements in an array of repeating elements

#include <stdio.h>
#include <limits.h>
#include <vector>
#include <iostream>
using namespace std;
typedef vector<int> VI;

int main() {
	int arr[] = {2, 4, 7, 9, 2, 4};

	int xsum = 0;
	for(auto ele : arr) {
		xsum ^=ele;
	}
	unsigned int i= xsum & ~(xsum-1);

	int val1=0, val2=0;
	for(auto ele : arr) {
		if(ele&i) {
			val1^=ele;
		}
		else {
			val2^=ele;
		}
	}

	cout<<"val1->"<<val1<<" val2->"<<val2<<endl;
	return 0;
}
