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
given a undirected and connected graph G(v,e), a spanning tree of the
graph  g is a tree that spans G(that is it includes every vertex ofG)
and is a subgrpah of g(every edge in the tree belongs to G)
cost of a spanning tree is the sum of the weights of all the edges in the tree
there can be many spanning trees

*/
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
    int n=8,m=9;
    vvi edges;
    rep(i,0,m){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(),edges.end());
    int cost=0;
    for(auto i:edges){
        int w=i[0];
        int u=i[1];
        int v=i[2];
        int x=find_set(u);
        int y=find_set(v);
        if(x==y){
            continue;
        }
        else{
            cout<<u<<" "<<v<<"\n";
            cost+=w;
            union_sets(u,v);
        }



    }
    cout<<cost;
    
}
