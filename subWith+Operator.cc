/*substract using only + operator
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>
using namespace std;

typedef vector<int> VI;
typedef queue<int> QI;

int diff(int a, int b) {
	int now=-1;
	int prev=0;

	int max = a>b?a:b;
	int min = a>b?b:a;
	int inc=1;

	while(max+now != min) {
		if(max+now > min) {
			prev=now;
			now+=now;
		}
		else if(max+now < min) {
			//now = (now+prev)/2;
			now+=1;
		}
	}
	return now;
}

int main()
{
	cout<<diff(1000,34)<<endl;
    return 0;
}
