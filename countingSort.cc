#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> VI;

VI sortCounting(VI vec) {
	int max = INT_MIN;
	for(int i=0;i<vec.size();++i) {
		if(vec[i]>max)
			max=vec[i];
	}
	VI worker(max+1,0);
	for(int i=0;i<vec.size();++i) {
		worker[vec[i]]++;
	}
	for(int i=1;i<worker.size();++i) {
		worker[i]+=worker[i-1];
	}

	VI res(vec.size());
	for(int i=vec.size()-1;i>=0;--i) {
		int pos = --worker[vec[i]];
		res[pos] = vec[i];
	}
	return res;
}

int main() {
	VI res = {2,5,3,0,2,3,0,3};
	res = sortCounting(res);
	for(auto ele:res) {
		cout<<ele<<" ";
	}
	cout<<endl;
	return 0;
}
