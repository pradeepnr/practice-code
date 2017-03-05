#include <iostream>
#include <map>
#include <math.h>
#include <stack>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef stack<int> SI;

void printNextSmaller(VI& vec) {
	VI op(vec.size(), -1);
	SI stk;
	stk.push(0);
	for(int i=1;i<vec.size();++i) {
		while(!stk.empty() && vec[i] < vec[stk.top()]) {
			op[stk.top()] = vec[i];
			stk.pop();
		}
		stk.push(i);
	}
	for(auto ele:op) {
		cout<<ele<<" ";
	}
	cout<<endl;
}
int main() {
	VI vec {4, 6, 2, 1, 5, 3};
	printNextSmaller(vec);
	return 0;
}
