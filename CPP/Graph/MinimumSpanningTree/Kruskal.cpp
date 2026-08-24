/*
Topic: Graph
Sub-Topic: Kruskal Algorithm (Minimum Spanning Tree)
Author: kornkin
*/

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int V = 5;

struct Edge{
    int a, b, w;

    bool operator < (const Edge &r) const{
        return w < r.w;
    }
};

void addE(int a, int b, int w);

vector<Edge> allE;
vector<int> par;
vector<int> rnk;

int findPar(int x){
    return (x == par[x]? x : par[x] = findPar(par[x]));
}

void unionSet(int a, int b){
    a = findPar(a);
    b = findPar(b);

    if(a == b) return;

    if(rnk[a] < rnk[b]) swap(a, b);

    par[b] = a;

    if(rnk[a] == rnk[b]) rnk[a]++;
}

void Kruskal(){
    vector<Edge> ans;

    sort(allE.begin(), allE.end());
    
    par.clear();
    rnk.clear();
    par.resize(V); for(int i = 0; i < V; i++) par[i] = i;
    rnk.resize(V, 0);

    for(Edge e : allE){
        if(findPar(e.a) == findPar(e.b)) continue;

        unionSet(e.a, e.b);

        ans.push_back(e);
    }

    for(Edge e : ans){
        cout << "Node " << e.a << " to " << e.b << " w: " << e.w << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    addE(0, 1, 2);
    addE(0, 3, 6);
    addE(1, 2, 3);
    addE(1, 3, 8);
    addE(1, 4, 5);
    addE(2, 4, 7);
    addE(3, 4, 9);

    Kruskal();

    return 0;
}

void addE(int a, int b, int w){
    allE.push_back({a, b, w});
}