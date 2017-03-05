// http://www.geeksforgeeks.org/increasing-subsequence-of-length-three-with-maximum-product/
// https://github.com/mission-peace/interview/blob/master/src/com/interview/array/IncreasingSubsequnceOfLength3WithMaxProduct.java
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>
using namespace std;

typedef vector<int> VI;
typedef queue<int> QI;

int maxProduct(VI arr){
	int len = arr.size();
	VI RGN(len);
	VI LGN(len);

	//Fill RGN
	// Fill in with Maximum values from right side
	RGN[len-1] = arr[len-1];
	int max = arr[len-1];
	for(int i=len-2;i>=0;i--) {
		if(arr[i]>max) {
			max=arr[i];
		}
		RGN[i] = max;
	}
	cout<<"RGN->";
	for(int i=0;i<len;++i) {
		cout<<RGN[i]<<" ";
	}
	cout<<endl;

	// FILL LGN
	// Greatest value which is less than the current ith value on left side
	LGN[0] = 0;
	for(int i=1;i<len;++i) {
		int max=INT_MIN;
		for(int j=0;j<i;j++) {
			if(arr[j]<arr[i]) {
				if(arr[j]>max) {
					max=arr[j];
				}
			}
		}
		LGN[i]=max;
	}
	cout<<"LGN->";
	for(int i=0;i<len;++i) {
		cout<<LGN[i]<<" ";
	}
	cout<<endl;

	int maxProduct=0;
	for(int i=1;i<len-1;++i) {
		int product = LGN[i]*arr[i]*RGN[i];
		if(product > maxProduct)
			maxProduct=product;
	}

	return maxProduct;
}

int main()
{
	VI arr{-60, -40, 8, 1, 2, 3, 9, 100};
	int maxx = maxProduct(arr);
	cout<<"max->"<<maxx<<endl;
    return 0;
}
