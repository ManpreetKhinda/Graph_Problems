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
int cheapestflight(int n, vector<vector<int>>&flights,int src, int des, int k){
    vector<vector<pair<int,int>>> adj(n);
    for(auto it:flights){
        adj[it[0]].push_back({it[1],it[2]});
    }
    queue<pair<int,pair<int,int>>> q;
    vector<int> dist(n,1e7);
    dist[src]=0;
    q.push({0,{src,0}});
    while(!q.empty()){
        auto p=q.front();q.pop();
        int stops=p.ff;
        int node=p.ss.ff;
        int dis=p.ss.ss;
        if(stops>k)continue;
        for(auto it:adj[node]){
            int adjnode=it.ff;
            int adjdist=it.ss;
            if(dis+adjdist<dist[adjnode] && stops<=k){
                dist[adjnode]=dis+adjdist;
                q.push({stops+1,{adjnode,dis+adjdist}});
            }
        }
    }
    if(dist[des]==1e9)return -1;
    return dist[des];
}