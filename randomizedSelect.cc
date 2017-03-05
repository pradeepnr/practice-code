#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>
#include <cstdlib>
#include <time.h>

using namespace std;

typedef vector<int> VI;
void swap(VI& vec, int i, int j) {
	int temp = vec[i];
	vec[i] = vec[j];
	vec[j] = temp;
}

int randomizedPartition(VI& vec, int a, int p) {
	int pivot = rand() % (p-a+1);
	pivot +=a;
	swap(vec, pivot, p);
	int i=a-1;
	int j=a;
	for(;j<p;j++) {
		if(vec[j]<vec[p]) {
			i++;
			swap(vec,i,j);
		}
	}
	i++;
	swap(vec,i,j);
	return i;
}

int randomizedSelect(VI& vec, int a, int p, int i) {
	if(i<=a && i>=p)
		return -1;
	int pos = randomizedPartition(vec, a, p);
#if 0
	cout<<"a->"<<a<<" p->"<<p<<" i->"<<i<<" pos->"<<pos<<" vec->";
	for(auto ele:vec)
		cout<<ele<<" ";
	cout<<endl;
#endif
	if(i<pos) {
		return randomizedSelect(vec,a,pos-1, i);
	}
	else if(i>pos) {
		return randomizedSelect(vec,pos+1,p,i);
	}
	return vec[pos];
}
int main() {
		srand(time(NULL));
		VI vec{8,7,6,5,4,3,2,1,0};
		int val = randomizedSelect(vec, 0, vec.size()-1, 9);
		cout<<"val->"<<val<<endl;
		return 0;
}
