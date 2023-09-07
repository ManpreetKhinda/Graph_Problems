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
/*shortes path from source to all vertices in a dag*/
void toposort(int node, vector<vector<pair<int,int>>>&adj, vector<bool>&vis,
stack<int> &st){
    vis[node]=1;
    for(auto i:adj[node]){
        int v=i.ff;
        if(!vis[v]){
            toposort(v,adj,vis,st);
        }
    }
    st.push(node);
}
vector<int> shortestpathfrompath(int n,int m, vector<vector<int>>&edges){
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        adj[u].push_back({v,wt});
    }
    stack<int> st;
    vector<bool> vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            toposort(i,adj,vis,st);
        }
    }
    vector<int> dist(n,1e5);
    dist[0]=0;
    while(!st.empty()){
        int node=st.top();
        st.top();
        for(auto it:adj[node]){
            int v=it.first;
            int wt=it.second;
            if(dist[node]+wt<dist[v]){
                dist[v]=dist[node]+wt;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dist[i]==1e5)dist[i]=-1;
    }
    return dist;
}