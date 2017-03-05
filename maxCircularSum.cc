//http://www.geeksforgeeks.org/next-greater-element/
// Next Greater Element
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

typedef vector<int> VI;

int kadane(VI& a) {
	int sum=0;
	int max = 0;
	for(auto ele : a) {
		sum+=ele;
		if(sum>0) {
			if(sum>max)
				max=sum;
		}
		else {
			sum=0;
		}
	}
	return max;
}

int maxCircularSum(VI& a) {
	int kadane_max = kadane(a);
	int sum=0;
	for(int i=0;i<a.size();++i) {
		sum+=a[i];
		a[i]=-a[i];
	}
	int circular_max = sum + kadane(a);
	return kadane_max > circular_max ? kadane_max : circular_max;
}

int main()
{
    //VI a {11, 10, -20, 5, -3, -5, 8, -13, 10}; // ans 31
	//VI a { -8, -8, 20, -3, 3, 4, -6, 7, -9}; // ans
	//VI a {8, -8, 9, -9, 10, -11, 12}; // ans 22
//	VI a{10, -3, -4, 7, 6, 5, -4, -1}; // ans 23
	VI a{-1, 40, -14, 7, 6, 5, -4, -1}; // ans 52
	//cout<<"Maximum kadane sum is "<<kadane(a)<<endl;
    cout<<"Maximum circular sum is "<<maxCircularSum(a)<<endl;
    return 0;
}
