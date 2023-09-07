/*

*/

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
vi parent(N);
vi sz(N);

void make_set(int v){
    parent[v]=v;
    sz[v]=1;
}

int find_set(int v){
    if(v==parent[v]){
        return v;
    }
    return parent[v]=find_set(parent[v]);
}

void union_sets(int a, int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(sz[a]<sz[b]){
            swap(a,b);
        }
        parent[b]=a;
        sz[a]+=sz[b];

    }
}
int main(){
    rep(i,0,N){
        make_set(i);
    }
    int n=4,m=4;
    vvi edges;
    rep(i,0,m){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    bool cycle=false;
    for(auto i:edges){
        int u=i[0];
        int v=i[1];
        int x=find_set(u);
        int y=find_set(v);
        if(x==y){
            cycle=true;
        }
        else{
            union_sets(u,v);
        }
    }
    cout<<cycle;

    
}
