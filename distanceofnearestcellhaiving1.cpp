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
vector<vector<int>> nearest(vector<vector<int>> &grid){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> ans(n,vector<int>(m,0));
    vector<vector<bool>> vis(n,vector<bool>(m,0));
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]){
                vis[i][j]=1;
                ans[i][j]=0;
                q.push({{i,j},0});
            }
        }
    }
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        int row=p.first.first;
        int col=p.first.second;
        int dis=p.second;
        ans[row][col]=dis;
        for(int x=0;x<4;x++){
            int nrow=row+dr[x];
            int ncol=col+dc[x];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m&&
            !vis[nrow][ncol]){
                vis[nrow][ncol]=1;
                q.push({{nrow,ncol},dis+1});
            }
        }
    }
    return ans;
}