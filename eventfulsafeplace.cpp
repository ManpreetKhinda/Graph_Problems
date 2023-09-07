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
bool dfs(int start, vector<int>&vis, vector<int>&pathvis,
vector<int>&check,vector<int> adj[]){
    vis[start]=1;
    pathvis[start]=1;
    check[start]=0;
    for(auto it:adj[start]){
        if(!vis[it]){
            if(dfs(it, vis,pathvis,check,adj)){
                check[start]=0;
                return true;
            }
        }
        else if(pathvis[it]){
            check[start]=0;
            return true;
        }
    }
    check[start]=1;
    pathvis[start]=0;
    return false;
}
vector<int> eventualSafeNodes(int v, vector<int>adj[]){
    vector<int>vis(v,0);
    vector<int>pathvis(v,0);
    vector<int>check(v,0);
    vector<int> safenode;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,vis,pathvis,check,adj);
        }
    }
    for(int i=0;i<v;i++){
        if(check[i]==1){
            safenode.push_back(i);
        }
    }
    return safenode;
}
vector<int> eventfulsafe(int v, vector<int> adj[]){
    vector<int> adjrev[v];
    int indeg[v]={0};
    for(int i=0;i<v;i++){
        for(auto it: adj[i]){
            
                adjrev[it].push_back(i);
                indeg[i]++;
            }
    }
    queue<int> q;
    vector<int> safenode;
    for(int i=0;i<v;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        safenode.push_back(node);
        for(auto it: adjrev[node]){
            indeg[it]--;
            if(indeg[it]==0){
                q.push(it);
            }
        }
    }
    sort(safenode.begin(),safenode.end());
}
