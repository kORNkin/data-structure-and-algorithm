
/*
Topic: Disjoint Set Union (DSU)
Sub-topic: Find A Number of Connected Graph
Author: kornkin
*/

#include<bits/stdc++.h>
using namespace std;

const int V = 6;
vector<int> g[V];

void addE(int a, int b);

vector<int> par;
vector<int> rnk;

//-------------------

int findPar(int x){
    return (x == par[x] ? x : par[x] = findPar(par[x]));
}

void unionSet(int a, int b){
    a = findPar(a);
    b = findPar(b);

    if(a == b) return;

    if(rnk[a] < rnk[b]) swap(a, b);

    par[b] = a;

    if(rnk[a] == rnk[b]) rnk[a]++;
}

//-------------------

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    addE(1, 2);
    addE(3, 4);
    addE(4, 5);

    par.resize(V + 1); for(int i = 1; i <= V; i++) par[i] = i;
    rnk.resize(V + 1, 0);

    for(int i = 0; i < V; i++)
        for(auto node : g[i])
            unionSet(i, node);

    int cnt = 0;

    for(int i = 0; i < V; i++)
        if(i == findPar(i)) cnt++;

    cout << cnt;

    return 0;   
}

void addE (int a, int b){
    g[a].push_back(b);
    g[b].push_back(a);
}