//http://www.geeksforgeeks.org/next-greater-element/
// Next Greater Element
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

typedef vector<int> VI;

string printBinary1(double num) {
	stringstream ss;
	if(num >=1 || num <=0) {
		return string("ERROR");
	}
	ss<<".";
	while(num > 0) {
		num*=2;
		if(num>=1) {
			ss<<1;
			num-=1;
		}
		else {
			ss<<0;
		}
	}
	return ss.str();
}

string printBinary2(double num) {
	stringstream ss;
	if(num >=1 || num <=0) {
		return string("ERROR");
	}
	ss<<".";
	double frac = 0.5;
	while(num > 0) {
		if(num>=frac) {
			ss<<1;
			num -=frac;
		}
		else {
			ss<<0;
		}
		frac/=2;
	}
	return ss.str();
}

int main()
{
	cout<<"to string->"<<printBinary1(0.75)<<endl;
	cout<<"to string->"<<printBinary2(0.75)<<endl;
    return 0;
}
