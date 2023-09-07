/* for dg and udg
not for negative edges and cyclles
singel source shortest path from a vertex u to all the vertices in the graph*/
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
/*
using priority queue
vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        // Code here
        priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(v);
        for(int i=0;i<v;i++){
            dist[i]=1e9;
        }
        dist[s]=0;
        pq.push({0,s});
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for( auto it:adj[node]){
                int edgeWeight=it[1];
                int adjNode=it[0];
                if(dis+edgeWeight<dist[adjNode]){
                    dist[adjNode]=dis+edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
}*/

/* usign set*/
vector<int> dijkstra(int v, vector<vector<int>> adj[], int s){
    set<pair<int,int>> st;
    vector<int> dist(v,1e9);
    st.insert({0,s});
    dist[s]=0;
    while(!st.empty()){
        auto it=*(st.begin());
        int node=it.ss;
        int dis=it.ff;
        st.erase(it);
        for(auto i:adj[node]){
            int edgeweight=i[1];
            int adjnode=i[0];
            if(dis+edgeweight<dist[adjnode]){
                if(dist[adjnode]!=1e9){
                    st.erase({dist[adjnode],adjnode});
                }
                dist[adjnode]=dis+edgeweight;
                st.insert({dist[adjnode],adjnode});
            }
        }
    }
    return dist;
}

int main(){
    int n=4,m=4;
    vi dist(n+1,INT_MAX);
    vector<vector<pair<int,int>>> graph(n+1);
    rep(i,0,m){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});

    }
    int source;
    cin>>source;
    dist[source]=0;
    set<pair<int,int>>s;
    s.insert({0,source});
    while(!s.empty()){
        auto x=*(s.begin());
        int node=it.second;
        int dis=it.first;
        s.erase(it);
        for(auto it: adj[node]){
            int adjNode=it[0];
            int edgW=it[1];
            if(dis+edgW<dist[adjNode]){
                if(dist[adjNode]!=1e9){
                    s.erase({dist[adjNode],adjNode});

                    dist[adjNode]=dis+edgW;
                    s.insert({dist[adjNode], adjNode});
                }
            }

        }

        s.erase(x);
        for(auto it: graph[x.second]){
            if(dist[it.first] > dist[x.second]+it.second){
                s.erase({dist[it.first],it.first});
                dist[it.first]=dist[x.second]+it.second;
                s.insert({dist[it.first],it.first});

            }
        }
    }
    rep(i,1,n+1){
        if(dist[i]<INT_MAX){
            cout<<dist[i]<<" ";
        }
        else{
            cout<<-1;
        }
    }

}