//http://www.geeksforgeeks.org/next-greater-element/
// Next Greater Element
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
typedef stack<int> ST;
typedef vector<int> VI;
int main() {
	//code
	int T;
	cin>>T;
	for(int t=0;t<T;++t) {
	    ST st;
    	VI vec;
    	int val;
    	int n;
    	cin>>n;
    	VI op;
    	for(int i=0;i<n;++i) {
    	    cin>>val;
    	    vec.push_back(val);
    	    op.push_back(-1);
    	}
    	st.push(0);
    	for(int i=1;i<n;++i) {
    	    if(!st.empty() && vec[i]>vec[st.top()]) {
    	        while(!st.empty() && vec[i]>vec[st.top()]) {
    	            op[st.top()] = vec[i];
    	            st.pop();
    	        }
    	    }
    	    st.push(i);
    	}
    	for(int i=0;i<n;++i) {
    	    cout<<op[i]<<" ";
    	}
    	cout<<endl;
	}
	return 0;
}
