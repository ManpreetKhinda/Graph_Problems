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
int minmultiplications(vector<int>&arr, int start, int end){
    queue<pair<int,int>>q;
    q.push({start,0});
    vector<int> dist(100000, 1e6);
    dist[start]=0;
    while(!q.empty()){
        auto p=q.front();
        int node=p.ff;
        int steps=p.ss;
        q.pop();
        for(auto it:arr){
            int num=(node*it)%100000;
            if(steps+1<dist[num])dist[num]=steps+1;
            if(num==end)return 1+steps;
            q.push({num,steps+1});
        }
    }
    return -1;
}
