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

void dfs(int i,int j,vector<vector<char>>&grid, vector<vector<bool>>&vis){
    vis[i][j]=1;
    int n=grid.size();
    int m=grid[0].size();
    int row[4]={-1,0,1,0};
    int col[4]={0,1,0,-1};
    for(int x=0;x<4;x++){
        int nrow=i+row[x];
        int ncol=j+col[x];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
            dfs(nrow,ncol, grid,vis);
        }
    }

}
int islands(vector<vector<char>>&grid){
    int n=grid.size();
    int m=grid[0].size();
    int cnt=0;
    vector<vector<bool>>vis(n,vector<bool>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]=='1'){
                cnt++;
                dfs(i,j,grid,vis);
            }
        }
    }
    return cnt;
}