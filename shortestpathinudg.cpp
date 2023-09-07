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
/* shortes path in undirected graph from a src to all other 
vertices */
/* n vertices m edges*/
vector<int> shortestpath(int src, vector<vector<int>>&edges,int n,int m){
    vector<vector<int>> adj(n);
    for(auto i:adj){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    vector<int> dist(n,1e7);
    dist[src]=0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto i:adj[node]){
            if(dist[node]+1<dist[i]){
                dist[i]=dist[node]+1;
                q.push(i);
            }
            
        }
    }
    for(int i=0;i<n;i++){
        if(dist[i]==1e7)dist[i]=-1;
    }
    return dist;
}
/*shortest path in a weighted undirected graph*/
vector<int> shortestpath2(int n,int m, vector<vector<int>>&edges){
    vector<vector<pair<int,int>>>adj(n+1);
    for(auto it:edges){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n+1,1e7),parent(n+1);
    for(int i=1;i<=n;i++)parent[i]=i;
    pq.push({0,1});
    dist[1]=0;
    while(!pq.empty()){
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it:adj[node]){
            int edgewt=it.second;
            int adjnode=it.first;
            if(dis+edgewt<dist[adjnode]){
                dist[adjnode]=dis+edgewt;
                pq.push({dist[edgewt],adjnode});
                parent[adjnode]=node;
            }
        }
    }
    vector<int> ans;
    if(dist[n]==1e7)return {-1};
    int node=n;
    while(parent[node]!=node){
        ans.push_back(node);
        node=parent[node];
    }
    ans.push_back(1);
    reverse(ans.begin(),ans.end());
    return ans;
}