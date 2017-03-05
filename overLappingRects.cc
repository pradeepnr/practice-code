/*
http://www.practice.geeksforgeeks.org/problem-page.php?pid=789
Input:

2
0 10 10 0
5 5 15 0
0 2 1 1
-2 -3 0 2

Output:

1
0
*/
#include <iostream>
using namespace std;

typedef struct Point{
    int x;
    int y;
}Point;

typedef struct Rect {
    Point lt;
    Point rb;
} Pect;

bool isRectangleOverLapping(Rect rect[2]) {
    //Is above or below
    if(rect[0].rb.y >= rect[1].lt.y || rect[1].rb.y >= rect[0].lt.y)
        return false;
    // Is towards left or right
    if(rect[0].rb.x <=rect[1].lt.x || rect[1].rb.x <= rect[0].lt.x)
        return false;
    return true;
}

int main() {
	//code
	int T;
	cin>>T;
	for(int t=0;t<T;++t) {
	    Rect rect [2];
	    for(int i=0;i<2;++i) {
	        cin>>rect[i].lt.x;
	        cin>>rect[i].lt.y;
	        cin>>rect[i].rb.x;
	        cin>>rect[i].rb.y;
	    }
	    
	    if(isRectangleOverLapping(rect)) {
	        cout<<"1\n";
	    }
	    else {
	        cout<<"0\n";
	    }
	}
	return 0;
}