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
const int N = 1e5 + 2;
vi adj[N];
/*
adjacency matrix
adjacency list
dfs bfs

dfs in post pre
implemented using stacks
bfs queue
tree edges=n-1

*/
int main()
{
    int n = 7, m = 7;
    // vvi adjm(n+1,vi(n+1,0));
    // rep(i,0,m){
    //     int x,y;
    //     cin>>x>>y;
    //     adjm[x][y]=1;
    //     adjm[y][x]=1;
    // }
    // rep(i,1,n+1){
    //     rep(j,1,n+1){
    //         cout<<adjm[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    rep(i, 0, m)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    rep(i, 1, n + 1)
    {
        cout << i << "->";
        vi::iterator it;

        for (it = adj[i].begin(); it != adj[i].end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
}
