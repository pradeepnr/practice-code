#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <limits.h>

using namespace std;
typedef vector<int> VI;

void swap(VI& vec, int i,int j) {
	int temp=vec[i];
	vec[i] = vec[j];
	vec[j] = temp;
}

void sortOnesZeros(VI& vec) {
	int i=0;
	int j=vec.size()-1;
	int p=0;

	while(p<=j) {
		if(vec[p]==0) {
			swap(vec,p,i);
			i++;
			p++;
		}
		else if(vec[p]==2){
			swap(vec,p,j);
			j--;
		}
		else {
			p++;
		}
	}
}

int main() {
	//VI vec{0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,2,0,1,2};
	VI vec{1,0,2,0,1,2};
	sortOnesZeros(vec);
	for( auto v:vec) {
		cout<<v<<" ";
	}
	cout<<endl;
	return 0;
}
