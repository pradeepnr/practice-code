#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>

using namespace std;

typedef vector<int> VI;

string expand(string s, int left, int right) {
        string max;
        while(left>=0 && right<s.length() && s[left]==s[right]) { left--; right++; }
        if(left<right) {
        	max=string(s,left+1,right - left -1);
        }
        return max;
    }
    string longestPalindrome(string s) {
        string max;
        for(int i=0;i<s.length();++i) {
            string str = expand(s,i,i);
            if(str.length()>max.length()) {
                max = str;
            }

            str = expand(s,i,i+1);
			if(str.length()>max.length()) {
				max = str;
			}
        }
        return max;
    }

int main() {
		string st = longestPalindrome(string("aaaaaba"));
		cout<<st<<endl;
		return 0;
}
