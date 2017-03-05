//http://www.geeksforgeeks.org/next-greater-element/
// Next Greater Element
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef vector<int> VI;

void swap(int arr[], int i, int j) {
	int tem = arr[i];
	arr[i] = arr[j];
	arr[j] = tem;
}
int partition(int arr[], int s, int len) {
	int i,j;
	i=s-1;
	srand(time(0));
	int pos = (rand()%len) + s;
	swap(arr, pos, s+len-1);
	int key = arr[s+len-1];
	for(int j=s;j<s+len;j++) {
		if(arr[j]<key) {
			swap(arr, j, ++i);
		}
	}
	swap(arr,++i,s+len-1);
	return i;
}

int kthelement(int arr[], int len, int k) {
	int i=-1;
	int s=0;
	int l=len;
	while(i != k) {
		i = partition(arr, s, l);
		if(k>i) {
			l = l-(i-s+1);
			s = i+1;
		}
		else if(k<i) {
			l = i - s;
		}
	}
	return arr[i];
}

int main() {
	//code
	int arr[] = {6, 2, 1, 6, 8, 9, 6, 4,7,5,3};
	int len = sizeof(arr)/sizeof(int);
	for(int i=0;i<len;++i)
	cout<<"kthelement->"<<kthelement(arr, len, i)<<endl;
	return 0;
}
