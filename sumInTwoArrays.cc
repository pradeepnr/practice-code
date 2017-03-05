/*Describe a ‚.n lg n/-time algorithm that, given a set S of n integers and another
integer x, determines whether or not there exist two elements in S whose sum is
exactly x.
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>
using namespace std;

typedef vector<int> VI;
typedef queue<int> QI;

void merge(VI& arr, int l, int m, int r) {
	int lenL = m-l+1;
	int lenR = r-m;
	VI temp(lenL+lenR);

	int i=l, j=m+1;
	int k=0;
	while(i<=m && j<=r) {
		if(arr[i]<arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}
	while(i<=m) {
		temp[k++] = arr[i++];
	}
	while(j<=r) {
		temp[k++] = arr[j++];
	}

	for(i=0;i<lenL+lenR;++i) {
		arr[l+i] = temp[i];
	}
}

void mSort(VI& arr, int l, int r) {
	if(l==r)
		return;
	int m=(r-l)/2;
	mSort(arr,l,m+l);
	mSort(arr,m+l+1,r);
	merge(arr,l,m+l,r);
}

bool IsPresent(VI& arr, int val) {
	int l=0;
	int r=arr.size()-1;

	while(l<r) {
		int m=(l+r)/2;
		if(arr[m]==val)
			return true;
		else if(val<arr[m]) {
			r=m;
		}
		else {
			l=m+1;
		}
	}
	return false;
}

bool IsSumPresent(VI& arr1, VI& arr2, int key) {
	mSort(arr1, 0, arr1.size()-1);
	mSort(arr2, 0, arr2.size()-1);

	for(auto ele : arr1) {
		int diff = key - ele;
		if(IsPresent(arr2, diff))
			return true;
	}

	return false;
}

int main()
{
	VI arr1 {9,8,7,6,4,5,3,2,1};
	VI arr2 { 15,14,13,12,11,10,9};
	int key = 24;
	bool sumPresent = IsSumPresent(arr1, arr2, key);
	cout<<"Sum "<<key<<" is->"<<sumPresent<<endl;
    return 0;
}
