/*
http://www.practice.geeksforgeeks.org/problem-page.php?pid=667
Input:

2

5 2

1 2 3 4 5

8 46

5 7 9 22 15 344 92 8

Output:

Yes

No*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef vector<int> VI;
typedef map<int,int> MII;

bool isProductPaitPresent(VI& vec, int pro) {
    MII mmap;
    for(auto ele : vec) {
        mmap[ele] = 1;
    }
    for(auto ele : vec) {
        if((pro%ele == 0) && (mmap[pro/ele] == 1))
            return true;
    }
    return false;
}
int main() {
	//code
	int T;
	cin>>T;
	for(int t=0;t<T;++t) {
	    int n, pro;
	    cin>>n>>pro;
	    VI vec(n);
	    for(int i=0;i<n;++i) {
	        cin>>vec[i];
	    }
	    if(isProductPaitPresent(vec, pro)) {
	        cout<<"Yes\n";
	    }
	    else {
	        cout<<"No\n";
	    }
	}
	return 0;
}