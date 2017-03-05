/*
 * https://www.hackerrank.com/contests/uf-codedash/challenges/jesse-and-os
 * Jesse is building his own operating system and now faces the task of building the process scheduling and the memory management feature. He has laid down the rules of how he is going to do it. It's as follows:

If a process needs to be executed and memory is available, the process is given the required amount of memory.
If a process needs to be executed and memory is not available, Jesse will wait until a few processes are completed which will free up enough memory and then he will assign it to the process.
Once a process is assigned some memory, it can't be removed from the memory until it's completed.
The processes should be executed in the given order. A process  can't be allocated memory before process , if .
Jesse is busy with other stuff and needs your help in implementing this. Can you help him do this?

Assume that the time taken to allocate memory to a process is 0.

Input Format

The first line contains two integers n  and m , where n is the number of processes and m is the amount of memory available initially. Then  lines follow, each line contains two integers  and  where  is the time needed for the current process to complete and  is the amount of memory it needs.
Input:
5 20
5 10
6 11
4 8
2 9
3 10

Output
14

 *
 *
 *
 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;

typedef unsigned long long ULL;
typedef pair<ULL,ULL> PII;
typedef unsigned int UINT;
typedef priority_queue<PII, std::vector<PII>, std::greater<PII> > PQ;
typedef queue<PII> QP;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int pro;
    ULL mem;
    cin>>pro>>mem;
    PQ pq;
    QP que;
    for(ULL i=0;i<pro;++i) {
        UINT timeR, memR;
        cin>>timeR>>memR;
        que.push(make_pair(timeR, memR));
    }
    ULL remain = mem;
    ULL time=0;
    while(!que.empty() && que.front().second<=remain) {
    	PII front = que.front();
    	pq.push(front);
    	remain -= front.second;
    	que.pop();
    }

    while(!pq.empty()) {

		PII low = pq.top();
		//cout<<"low time->"<<low.first<<endl;

		pq.pop();
		time=low.first;
		remain+=low.second;

		while(!que.empty() && que.front().second<=remain) {
			PII front = que.front();
			front.first+=low.first;
			pq.push(front);
			remain -= front.second;
			que.pop();
		}
    }
    cout<<time<<endl;
    return 0;
}
