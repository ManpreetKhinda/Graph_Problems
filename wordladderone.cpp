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
int sequencelength(string start, string target,vector<string>&dict){
    queue<pair<string,int>>q;
    q.push({start,1});
    unordered_set<string>st(dict.begin(),dict.end());
    st.erase(start);
    while(!q.empty()){
        string word=q.front().ff;
        int dis=q.front().ss;
        q.pop();
        if(word==target)return dis;
        for(int i=0;i<word.size();i++){
            char originalchar=word[i];
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(st.find(word)!=st.end()){
                    st.erase(word);
                    q.push({word,steps+1});
                }

            }
            word[i]=originalchar;
        }
    }
    return 0;
}
/* word ladder 2 output the sequence*/
vector<vector<string>> findSequences(string start, string target, vector<string>& wordList){
    unordered_set<string> st(wordlist.begin(),wordlist.end());
    queue<vector<string>> q;
    q.push({start});
    vector<string>usedonlevel;
    int level=0;
    usedonlevel.push(start);
    vector<vector<string>> ans;
    while(!q.empty()){
        vector<string> a=q.front();
        q.pop();
        if(a.size()>level){
            level++;
            for(auto it: usedonlevel){
                st.erase(it);
            }
        }
        string str=a.back();
        if(str==target){
            if(ans.size()==0){
                ans.push_back(a);
            }
            else if(ans[0].size()==a.size()){
                ans.push_back(a);
            }
        }
        for(int i=0;i<word.size();i++){
            char original=word[i];
            for(char c='a';c<='z';c++){
                word[i]=c;
                if(st.count(str)>0){
                    a.push_back(str);
                    q.push(a);
                    usedonlevel.push_back(str);
                    a.pop_back();
                }
            }
            word[i]=original;
        }
    }
    return ans;

}
