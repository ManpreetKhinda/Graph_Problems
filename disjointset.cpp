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
const int N=10;

class DisjointSet {
    
public: 
    vector<int> rank, parent, size; 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};
vector<pair<int,int>>mstkruskal(int v, vector<vector<int>>adj[]){
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<v;i++){
        for(auto it:adj[i]){
            int adjnode=it[0];
            int wt=it[1];
            int node=i;
            edges.push_back({wt,{node,adjnode}});
        }
    }
    int mstwt=0;
    vector<pair<int,int>> mst;
    sort(edges.begin(),edges.end());
    DisjointSet ds(v);
    vector<pair<int,int>> mst;
    for(auto it:edges){
        int wt=it.ff;
        int u=it.ss.ff;
        int v=it.ss.ss;
        if(ds.findUPar(u)!=ds.findUPar(v)){
            mstwt+=wt;
            mst.push_back({u,v});
            ds.unionBySize(u,v);
        }
    }
    return mst;

}
int numProvinces(vector<vector<int>> &adj, int v){
    DisjointSet ds(v);
    for(int i=0;i< v;i++){
        for(int j=0;j<v;j++){
            if(adj[i][j]==1){
                ds.unionBySize(i,j);
            }
        }
    }
    int cnt=0;
    for(int i=0;i<v;i++){
        if(ds.parent[i]==i){
            cnt++;
        }
    }
    return cnt;
}
/*number of operation to make a network connected 
remove edges from existing graphs and use them */
int makeconnected(int n, vector<vector<int>>&edge){
    DisjointSet ds(n);
        int cntextra=0;
        for(auto it: edge){
            int u=it[0];
            int v=it[1];
            if(ds.findUPar(u)==ds.findUPar(v)){
                cntextra++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                cnt++;
            }
        }
        int ans=cnt-1;
        if(cntextra>=ans)return ans;
        return -1;
}
/*mergeaccounts*/
vector<vector<string>> accountsmerge(vector<vector<string>>&details){
    int n=details.size();
    DisjointSet ds(n);
    unordered_map<string,int>mp;
    for(int i=0;i<n;i++){
        for(int j=1;j<details[i].size();j++){
            string mail=details[i][j];
            if(mp.find(mail)==mp.end())mp[mail]=i;
            else ds.unionBySize(mp[mail],i);
        }
    }
    vector<vector<string>> mergedmails(n);
    for(auto it:mp){
        string mail=it.first;
        int node=ds.findUPar(it.ss);
        mergedmails[node].push_back(mail);
    }
    vector<vector<string>> ans;
    for(int i=0;i<n;i++){
        if(mergedmails[i].size()==0)continue;
        sort(mergedmails[i].begin(),mergedmails[i].end());
        vector<string> temp;
        temp.push_back(details[i][0]);
        for(auto it:mergedmails[i]){
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    sort(ans.begin(),ans.end(),greater<vector<string>>());
    return ans;   
}
/*maximum stones removed
stones can be removed only if only horizontal and vertical have other stones*/
int maxstonesremoved(int n, vector<vector<int>>&stones){
    int maxr=0;
    int maxc=0;
    for(auto it:stones){
        maxr=max(maxr,it[0]);
        maxc=max(maxc,it[1]);
    }
    DisjointSet ds(maxr+maxc+1);
    unordered_map<int,int>stonenode;
    for(auto it:stones){
        int noder=it[0];
        int nodec=it[1];
        ds.unionBySize(noder,nodec+maxr+1);
        stonenode[noder]=1;
        stonenode[nodec+maxr+1]=1;
    }
    int cnt=0;
    for(auto it: stonenode){
        if(ds.findUPar(it.first)==it.first)cnt++;
    }
    return n-cnt;
}
/*In a binary matrix any 0 can be changed to 1
return largest group of connected ones*/
int maxconnection(vector<vector<int>>&grid){
    int n=grid.size();
    DisjointSet ds(n*n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0)continue;
            int dr[4]={-1,0,1,0};
            int dc[4]={0,1,0,-1};
            for(int x=0;x<4;x++){
                int adcr=i+dr[x];
                int adcc=j+dc[x];
                if(adcr>=0 &&adcr<n && adcc>=0 && adcc<n &&grid[adcr][adcc]){
                    int nodeno=i*n+j;
                    int adjnodeno=adcr*n+adcc;
                    ds.unionBySize(nodeno,adjnodeno);
                }
            }
        }
    }
    int maxim=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1)continue;
            int dr[4]={-1,0,1,0};
            int dc[4]={0,1,0,-1};
            set<int> components;
            for(int x=0;x<4;x++){
                int adcr=i+dr[x];
                int adcc=j+dc[x];
                if(adcr>=0 && adcc>=0 && adcr<n && adcc<n && grid[adcr][adcc]){
                    components.insert(ds.findUPar(adcr*n+adcc));
                }
            }
            int sizetotal=0;
            for(auto it:components){
                sizetotal+=ds.size[it];
            }
            maxim=max(maxim,sizetotal+1);
        }
    }
    for(int q=0;q<n*n;q++){
        maxim=max(maxim,ds.size[ds.findUPar(q)]);
    }
    return maxim;

}