#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <memory>
#include <map>

using namespace std;
typedef map<int, bool> MI;
typedef unsigned int ULL;
typedef map<ULL, int> MLI;

int getBytes(char ch) {
//	cout<<hex<<(int)ch<<endl;
	int c = 0;
	if(!(ch & 0x80)) {
		c = 1;
	} else if((ch & 0xF8) == 0xF0) {
		c = 4;
	} else if((ch & 0xF0) == 0xE0) {
		c = 3;
	} else if((ch & 0xC0) == 0xC0) {
		c = 2;
	}
	return c;
}

ULL getUnicode(char* ch, int len) {
	ULL code = 0;
	switch(len) {
		case 1:
		{
			code = ch[0];
			break;
		}
		case 2:
		{
			code = (ch[0]&0x1F)<<6 |(ch[1]&0x3F);
			break;
		}
		case 3:
		{
			code = (ch[0]&0x0f)<<12 | (ch[1]&0x3F)<<6 |(ch[2]&0x3F);
			break;
		}
		case 4:
		{
			code = (ch[0]&0x7)<<18 | (ch[1]&0x3F)<<12 | (ch[2]&0x3F)<<6 | (ch[3]&0x3F);
			break;
		}
	}
	return code;
}

int main() {
	string str = "ಉರು";
	//string str = "p";
	MLI mmap;
	int i=0;
	cout<<str.length()<<endl;
	int len = getBytes(str[i]);
//	ULL l = getUnicode(&str[i],len);
//	cout<<hex<<l<<endl;
	while(i<str.length()) {
		int len = getBytes(str[i]);
		ULL l = getUnicode(&str[i],len);
		cout<<hex<<l<<endl;
		mmap[l]++;
		i+=len;
	}
	for(MLI::iterator it =mmap.begin();it!=mmap.end();++it) {
		cout<<it->first<<","<<it->second<<endl;
	}
	return 0;
}

