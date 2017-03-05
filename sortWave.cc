#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
#include <list>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef list<int> LI;
typedef pair<int,int> PII;
typedef vector<PII> VP;

void swap(VI& vec, int i, int j) {
	int temp = vec[i];
	vec[i] = vec[j];
	vec[j] = temp;
}

int main() {
	VI vec{14, 13, 12, 11, 3, 4, 7, 8};
	for(int i=0;i<vec.size()-1;++i) {
		if(i%2==0) {
			if(vec[i] < vec[i+1]) {
				swap(vec,i,i+1);
			}
		}
		else {
			if(vec[i] > vec[i+1]) {
				swap(vec,i,i+1);
			}
		}
	}
	for(auto ele:vec)
		cout<<ele<<" ";
	cout<<endl;
	return 0;
}
