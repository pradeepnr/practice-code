/*
Input:
2
20 20 20 10 10 20 10 10
10 10 10 10 20 10 20 30

Output:
1
0
*/
#include <iostream>
#include <map>
#include <math.h>
using namespace std;

typedef map<int,int> MII;

int calsqDist(int x1, int y1, int x2, int y2) {
    //cout<<x1<<y1<<x2<<y2<<endl;
    int x = (x2-x1);
    int y = (y2-y1);
    return (x*x + y*y);
}

bool isSquare(MII& mmap) {
    if(mmap.size()>2)
        return false;
    
    MII::iterator it = mmap.begin();
    int dmin = (*it).first;
    it++;
    int dmax = (*it).first;
    dmin = dmin<dmax?dmin:dmax;
    dmax = dmin<dmax?dmax:dmin;
    if(2*dmin!=dmax)
        return false;
    return true;
}

int main() {
    //code
    int T;
    cin>>T;
    for(int t=0;t<T;++t) {
        int points[4][2];
        MII mmap;
        for(int i=0;i<4;++i) {
            cin>>points[i][0];
            cin>>points[i][1];
        }
        for(int i=0;i<4;i++) {
            for(int j=0;j<4;j++) {
                if(i==j)
                    continue;
                int sqdistance = calsqDist(points[i][0],points[i][1],
                                           points[j][0],points[j][1]);
                mmap[sqdistance]++;
            }
        }
        if(isSquare(mmap))
            cout<<"1\n";
        else
            cout<<"0\n";
        
    }
    return 0;
}
