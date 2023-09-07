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
vector<int> toposort(int k,vector<vector<int>>&adj){
    vector<int> indeg(k);
    for(int i=0;i<k;i++){
        for(auto it: adj[i])
        indeg[it]++;
    }
    queue<int> q;
    for(int i=0;i<k;i++){
        if(indeg[i]==0)q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto i:adj[node]){
            indeg[i]--;
            if(indeg[i]==0){
                q.push(i);
            }
        }
    }
    return topo;
}
string alienorder(vector<string>&dict, int k){
    int n=dict.size();
    vector<vector<int>> adj(k);
    for(int i=0;i<n-1;i++){
        string s1=dict[i];
        string s2=dict[i+1];
        int minlen=min(s1.size(),s2.size());
        for(int j=0;j<minlen;j++){
            if(s1[j]!=s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }
    vector<int> topo=toposort(k,adj);
    string ans="";
    for(auto i:topo){
        ans=ans+char(i+'a');
    }
    return ans;
}