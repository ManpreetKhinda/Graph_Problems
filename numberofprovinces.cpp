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
/* find number of connected components*/
void dfs(int node, vvi&adj, vector<bool>&vis){
    vis[node]=1;
    for(int i=0;i<adj[node].size();i++){
        if(adj[node][i] && !vis[i])dfs(i,adj,vis);
    }
}
int provinces(vvi&adj){
    int v=adj[0].size();
    vector<bool> vis(v,0);
    int count=0;
    for(auto i:vis){
        if(i==0){
            count++;
            dfs(i,adj,vis);
        }
    }
    return count;
}