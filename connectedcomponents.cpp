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
vvi adj;
vi comp;
vector<bool> vis;
int get_com(int idx){
    if(vis[idx]){
        return 0;
    }
    vis[idx]=true;
    int ans=1;
    for(auto i:adj[idx]){
        if(!vis[i]){
            ans+=get_com(i);
            vis[i]=true;
        }
    }
    return ans;
}
/*
void dfs(int idx,vector<vector<int>> &adj, int vis[]){
        
        vis[idx]=1;
        for(int i=0;i<adj[idx].size();i++){
            if(adj[idx][i]==1 && vis[i]==false){
                dfs(i,adj,vis);
            }
        }
       
        
    }
    int numProvinces(vector<vector<int>> &adj, int v) {
        
        // code here
        
        int vis[v]={0};
        int count=0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                count++;
                dfs(i,adj,vis);
            }
        }
        return count;
    }*/
int main(){
    int n=5,m=3;
    adj= vvi(n);
    vis=vector<bool>(n,0);
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            comp.push_back(get_com(i));
        }
    }
    int ans=0;
    for(auto i:comp){
        ans+=i*(n-i)/2;
    }
    cout<<ans;
}