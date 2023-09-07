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
using bfs toposort*/
bool iscyclic(int v, vector<int> adj[]){
    vector<int> indeg(v,0);
    for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            indeg[it]++;
        }
    }   
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indeg[i]==0)q.push(i);
    } 
    vector<int> topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            indeg[it]--;
            if(indeg[it]==0)q.push(it);
        }
    }
    if(topo.size()!=v)return true;
    return false;
}
/*
 using dfs traversal

*/
bool dfscheck(int start, vector<int> adj[], int vis[], int pathvis[]){
    vis[start]=1;
    pathvis[start]=1;
    for(auto it: adj[start]){
        if(!vis[it]){
            if(dfscheck(it,adj,vis,pathvis)==true){
                return true;
            }
        }
        else if( pathvis[it]){
            return true;
        }
    }
    pathvis[start]=0;
    return false;
}
bool iscyclic(int v, vector<int> adj[]){
    int vis[v]={0};
    int pathvis[v]={0};
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(dfscheck(i,adj,vis,pathvis)==true){
                return true;
            }
        }
    }
    return false;
}
/*
using stack
*/
bool iscycle(int src, vvi&adj, vector<bool> &vis, vi&stck){
    stck[src]=true;
    if(!vis[src]){
        vis[src]=true;
        for(auto i:adj[src]){
            if(!vis[i]&&iscycle(i,adj,vis,stck)){
                return true;
            }
            if(stck[i]){
                return true;
            }
        }
    }
    stck[src]=false;
    return false;
}

int main(){
    int n=4,m=3;
    vvi adj(n);
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);

    }
    bool cycle=false;
    vi stck(n,0);
    vector<bool> vis(n,0);
    rep(i,0,n){
        if(!vis[i]&& iscycle(i,adj,vis,stck)){
            cycle =true;
        }
    }
    cout<<cycle;
}
/*
[[-52,31],[-73,-26],[82,97],[-65,-11],[-62,-49],[95,99],[58,95],[-31,49],[66,98],[-63,2],[30,47],[-40,-26]]

*/