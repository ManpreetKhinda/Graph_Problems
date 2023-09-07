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
const int N=1e5+3;
int spanningTree(int v, vector<vector<int>> adj[])
{
        priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<bool> vis(v,0);
        int sum=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int wt=it.first;
            if(vis[node]){
                continue;
            }
            vis[node]=true;
            sum+=wt;
            for(auto it:adj[node]){
                int adjNode=it[0];
                int edw=it[1];
                if(!vis[adjNode]){
                    pq.push({edw,adjNode});
                }
            }
        }
        return sum;
}
vector<pair<int,int>> mstprims(int v,vector<vector<int>> adj[]){
    vector<pair<int,int>> mst;
    vector<bool> vis(v,0);
    priority_queue<pair<int,pair<int,int>>, 
    vector<pair<int,pair<int,int>>>, 
    greater<pair<int,pair<int,int>>>>pq;
    pq.push({0,{0,-1}});
    while(!pq.empty()){
        auto p=pq.top();pq.pop();
        int dis=p.first;
        int node=p.ss.ff;
        int parent=p.ss.ss;
        if(vis[node])continue;
        if(parent!=-1)mst.push_back({node,parent});
        vis[node]=1;
        for(auto it:adj[node]){
            int adjnode=it[0];
            int edgewt=it[1];
            if(!vis[adjnode])pq.push({edgewt,{adjnode,node}});
        }
    }
    return mst;
}

vvi g[N];
int cost=0;
int n=4,m=5;
vi dis(N);
vi parent(N);
vector<bool> vis(N);
void primst(int src){
    rep(i,1,n){
        dis[i]=INT_MAX;

    }
    set<vi>s;
    dis[src]=0;
    s.insert({0,src});
    while(!s.empty()){
        auto x=*(s.begin());
        s.erase(x);
        vis[x[1]]=true;
        int u=x[1];
        int v=parent[x[1]];
        int w=x[0];
        cout<<u<<" "<<v<<" "<<w;
        cost+=w;
        for(auto it:g[x[1]]){
            if(vis[it[0]]){
                continue;
            }
            if(dis[it[0]]>it[1]){
                s.erase({dis[it[0]],it[0]});
                dis[it[0]]=it[1];
                s.insert({dis[it[0]],it[0]});
                parent[it[0]]=x[1];
            }
                    
        }


    }
    
}
int main(){
    
    rep(i,0,m){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});

    }
    primst(0);
    cout<<cost;
}