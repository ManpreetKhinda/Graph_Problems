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

/*
using dfs if back edge found its cyclic
*/

bool detect(int src, vector<int> adj[], int vis[]){
    vis[src]=1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto i:adj[node]){
            if(!vis[i]){
                vis[i]=1;
                q.push({i,node});
            }
            else if(parent!=i){
                return true;
            }
        }
    }
    return false;
}
bool iscycle(int v, vector<int> adj[]){
    int vis[v]={0};
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(detect(i,adj,vis)){
                return true;
            }
        }
        
    }
    return false;
}
bool icycle(int src,vvi &adj,vector<bool> &vis,int par){
    vis[src]=true;
    for(auto i: adj[src]){
        if(i!=par){
            if(vis[i]){
                return true;
            }
            if(!vis[i]&&icycle(i,adj,vis,src)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n=4,m=3;
    vvi adj(n);
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool cycle =false;
    vector<bool> vis(n,false);
    rep(i,0,n){
        if(!vis[i]&& icycle(i,adj,vis,-1)){
            cycle=true;
        }
    }
    cout<<cycle;
}
