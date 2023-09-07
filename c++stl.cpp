#include <iostream>
#include <cmath>
#include <stack>
#include <cstring>
#include <stdlib.h>
#include <unordered_set>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii vector<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
const int N=10;
vi parent(N);
vi sz(N);

vector<int> v;
v.emplace_back(2);
vector<int> v2(v); // copy of v;
vector<int> :: iterator it=v.begin();
cout<*(it);
v.insert(v.begin(),300);
v.insert(v.begin()+1,2,10);

list<int> ls;
ls.push_back(2);
ls.emplace_back(4);
ls.push_front();

deque<int> dq;
dq.push_back();
dq.push_front();
dq.emplace_back();
dq.emplace_back();
dq.pop_front();
dq.pop_back();


stack<int> st;
st.emplace(5);

queue<int> q;
q.emplace(1);
q.back();
q.front();


priority_queue<int> pq;
priority_queue<int,vector<int>,greater<int>> pq; 

set<int> s;
auto it=set.count(1);
multiset<int> st;
unordered_set<int> st;
map<int> mp;/* store unique keys in sorted order*/
auto it: mpp.find(3);
cout<<*(it).second;
int cnt=__builtin_popcount();

string s;
do{
    cout<<s<<endl;
}while(next_permutation(s.begin(),s.end()));
/*multimap unordered map*/

/* sorted and unique*/
/*
in case of pairs  no need for braces*/
