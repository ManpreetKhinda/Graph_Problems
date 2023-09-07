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
void floodfill(vector<vector<char>>&mat, int i, int j, int n, int m, char initial, char next){
    if(i<0 ||i>=n ||j<0||j>=m||mat[i][j]!=initial)return;
    mat[i][j]=next;
    floodfill(mat,i+1,j,n,m,initial,next);
    floodfill(mat,i-1,j,n,m,initial,next);
    floodfill(mat,i,j-1,n,m,initial,next);
    floodfill(mat,i,j+1,n,m,initial,next);
}
vector<vector<char>> fill(vector<vector<char>>&mat){
    int n=mat.size();
    int m=mat[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='O')mat[i][j]='$';
        }
    }
    for(int i=0;i<n;i++){
        if(mat[i][0]=='$'){
            floodfill(mat,i,0,n,m,'$','O');
        }
    }
    for(int i=0;i<n;i++){
        if(mat[i][m-1]=='$'){
            floodfill(mat,i,m-1,n,m,'$','O');
        }
    }
    for(int i=0;i<m;i++){
        if(mat[0][i]=='$'){
            floodfill(mat,0,i,n,m,'$','O');
        }
    }
    for(int i=0;i<m;i++){
        if(mat[n-1][i]=='$'){
            floodfill(mat,n-1,i,n,m,'$','O');
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]=='$')mat[i][j]='X';
        }
    }
    return mat;
}