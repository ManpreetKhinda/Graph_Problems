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
const int N=1e5+2;
bool vis[N];
vi adj[N];
void dfs(int row, int col, int n,int m, vector<vector<int>> &vis, vector<vector<char>>& grid){
    if(row<0 ||row>=n||col<0||col>=m|| vis[row][col]=='1'|| grid[row][col]=='0'){
        return;
    }
    vis[row][col]=1;
    /*
    write recurison calls for dfs*/

}

void dfs(int node){
    vis[node]=1;
    vi ::iterator it;
    for(it=adj[node].begin();it!=adj[node].end();it++){
        if(!vis[*it]){
            dfs(*it);
        }
    }
    cout<<node<<" ";

}
int main(){
    int n=7,m=7;
    rep(i,0,n){
        vis[i]=false;
    }
    
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }
    dfs(1);
    return 0;
}
void dfs(int v, vector<bool>&vis, vi adj[], vi&ans){
    vis[v]=1;
    ans.push_back(v);
    for(auto i:adj[v]){
        if(!vis[i])dfs(i,vis,adj,ans);
    }
}
vector<int> dfs(int v, vi adj[]){
    vector<bool> vis(v,0);
    vector<int> ans;
    dfs(0,vis, ans,adj);
    return ans;

}