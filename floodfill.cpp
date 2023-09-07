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
void floodfill(vvi &screen, int sr,int sc, int row, int col, int source,int color){
    if(sr<0||sr>=row|| sc<0||sc>=col){
        return;
    }
    if(screen[sr][sc]!=source){
        return ;

    }
    screen[sr][sc]=color;
    floodfill(screen,sr-1,sc,row,col,source,color);
    floodfill(screen,sr+1,sc,row,col,source,color);
    floodfill(screen,sr,sc-1,row,col,source,color);
    floodfill(screen,sr,sc+1,row,col,source,color);
}
void bfs(vvi&ans, vvi&grid, int i, int j, int inicolor, int color){
    queue<pair<int,int>> q;
    int n=grid.size();
    int m=grid[0].size();
    // vector<vector<bool>> vis(n,vector<bool>(m,0));
    q.push({i,j});
    // vis[i][j]=1;
    ans[i][j]=color;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    while(!q.empty()){
        auto p=q.front();
        int row=p.first;
        int col=p.second;
        q.pop();
        for(int x=0;x<4;x++){
            int nrow=row+dr[x];
            int ncol=col+dc[x];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==inicolor
            && ans[nrow][ncol]!=color){
                ans[nrow][ncol]=color;
                q.push({nrow,ncol});
            }
        }
    }
}

vector<vector<int>> floodfillbfs(vvi& image,int sr,int sc, int color){
    int inicolor=image[sr][sc];
    vvi ans=image;
    bfs(ans,image,sr,sc,inicolor,color);
    return ans;
}