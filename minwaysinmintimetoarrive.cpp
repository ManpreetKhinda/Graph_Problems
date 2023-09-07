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
int MOD=1e9+7;
int countpaths(int n ,vector<vector<int>>&paths){
    vector<vector<pair<int,long long int>>> adj(n);
    for(auto it:paths){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    priority_queue<pair<long long, int>, vector<pair<long long ,int>>, greater<pair<long long,int>>> pq;
    vector<long long> dist(n,INT_MAX);
    vector<long long> ways(n,0);
    pq.push({0,0});
    dist[0]=0;
    ways[0]=1;
    while(!pq.empty()){
        auto p=pq.top();pq.pop();
        long long distance=p.ff;
        int node=p.ss;
        for(auto it:adj[node]){
            long long adjdist=it.ss;
            int adjnode=it.ff;
            if(distance+adjdist<dist[adjnode]){
                dist[adjnode]=distance+adjdist;
                ways[adjnode]=ways[node];
                pq.push({distance+adjdist,adjnode});
            }
            else if(distance+adjdist==dist[adjnode]){
                ways[adjnode]=(ways[node]+ways[adjnode])%MOD;
            }
        }
    }
    return ways[n-1];
}