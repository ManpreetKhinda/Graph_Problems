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
int shortestpath(pair<int,int> src, pair<int,int> des, vector<vector<int>>&grid){
    queue<pair<int,pair<int,int>>> q;
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>dist(n,vector<int>(m,1e9));
    dist[src.ff][src.ss]=0;
    q.push({0,{src.ff,src.ss}});
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        int dis=p.first;
        int xr=p.second.first;
        int xc=p.second.second;
        for(int x=0;x<4;x++){
            int nrow=xr+dr[x];
            int ncol=xc+dc[x];
            if(nrow>=0 &&nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] && dist[nrow][ncol]>dis+1){
                dist[nrow][ncol]=1+dis;
                if(nrow==des.ff && ncol==des.ss)return 1+dis;
                q.push({1+dis,{nrow,ncol}});
            }
        }
    }
    if(src==des)return 0;
    return -1;
}