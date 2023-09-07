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
void bfs(int i,int j, vector<vector<bool>> &vis, vector<vector<int>>&grid,
                                vector<pair<int,int>>&vec,int row0, int col0){
    queue<pair<int,int>> q;
    q.push({i,j});
    vis[i][j]=1;
    vec.push_back({0,0});
    int n=grid.size();
    int m=grid[0].size();
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    while(!q.empty()){
        auto p=q.front();
        int n1=p.first;
        int n2=p.second;
        vec.push_back({n1-row0, n2-col0});
        q.pop();
        for(int x=0;x<4;x++){
            int nrow=n1+dr[x];
            int ncol=n2+dc[x];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]){
                q.push({nrow,ncol});
                vis[nrow][ncol]=1;
                
            }
        }
    }

}

int countdistinctislands(vector<vector<int>>&grid){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<bool>> vis(n,vector<bool>(m,0));
    set<vector<pair<int,int>>>st;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]==1){
                vector<pair<int,int>>vec;
                bfs(i,j,vis,grid,vec, i,j);
                st.insert(vec);
            }
        }
    }
    return st.size();

}