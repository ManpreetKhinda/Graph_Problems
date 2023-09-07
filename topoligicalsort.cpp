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
/*
only dag has topological ordering
topological ordering it the ordering of the node in a directed graph from node a to
node b node a appear before node b in ordering*/


/*
using dfs*/
void dfs(int start, int vis[] ,vector<int> adj[], stack<int> &st){
	vis[start]=1;
	    for(auto i: adj[start]){
	        if(!vis[i]){
	            dfs(i,vis,adj,st);
	        }
	    }
	    st.push(start);
	    
	    
	}
vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    // code here
	    int vis[v]={0};
	    stack<int> st;
	    for(int i=0;i<v;i++){
	        if(!vis[i]){
	            dfs(i,vis, adj,st);
	        }
	    }
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
}
vector<int> topoSort(int v, vector<int> adj[]){
    vector<int> indeg(v,0);
    for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            indeg[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<v;i++){
        if(indeg[i]==0)q.push(i);
    }
    vector<int>toposort;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        toposort.push_back(node);
        for(auto it: adj[node]){
            indeg[it]--;
            if(indeg[it]==0)q.push(it);
        }
    }
    return toposort;
}

