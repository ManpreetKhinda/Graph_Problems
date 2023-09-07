/*its vertices can be divided into two disjoint
and independent sets u and v such that every edge connects a vertex in u to one in v
the graph does not contain any odd-length cycles
the graph is 2 colorable*/
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
bool bipart;
vvi adj;
vector<bool> vis;
vector<int> col;
bool dfs(int node, int curr, int col[], vector<int> adj[]){
    col[node]=curr;
    for(auto i: adj[node]){
        if(col[i]==-1){
            if(dfs(i,!curr, col,adj)==false){
                return false;
            }
        }
        else if(col[i]==curr){
            return false;
        }
    }
    return true;
}
bool isbipartite(int v, vector<int> adj[]){
    int col[v];
    for(int i=0;i<v;i++){
        col[i]=-1;
    }
    for(int i=0;i<v;i++){
        if(col[i]==-1){
            if(dfs(i,0,col,adj)==false){
                return false;
            }
        }
    }
    return true;
}


bool bfs(int start, vector<int> adj[], vector<int>&col){
    queue<int> q;
    q.push(start);
    col[start]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(col[it]!=-1){
                q.push(it);
                col[it]=!col[node];
            }
            else if(col[it]==col[node])return false;
        }
    }
    return true;
}
bool isbipartite(int v, vector<int> adj[]){
    vector<int> col(v,-1);
    for(int i=0;i<v;i++){
        if(col[i]!=-1){
            if(!bfs(i,adj,col))return false;
        }
    }
    return true;
    
}
