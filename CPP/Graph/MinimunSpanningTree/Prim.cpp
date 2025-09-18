/*
Topic: Graph
Sub-Topic: Prim Algorithm (Minimum Spanning Tree)
Author: kornkin
*/

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int V = 5;

void addE(int a, int b, int w);

vector<pii> g[V];

void Prim(int start){
    vector<int> par(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, start});

    while(!pq.empty()){
        int current_node = pq.top().second;
        pq.pop();

        if(inMST[current_node]) continue;
        inMST[current_node] = 1;

        for(auto &[weight, node] : g[current_node]){
            if(!inMST[node] && weight < key[node]){
                key[node] = weight;
                par[node] = current_node;

                pq.push({weight, node});
            }
        }
    }

    int totalWeight = 0;

    for(int i = 0; i < V; i++)
        if(par[i] != -1)
            cout << par[i] << " to " << i << " weight: " << key[i] << '\n', totalWeight += key[i];

    cout << "Total Weight is " << totalWeight;
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

    Prim(0);

    return 0;
}

void addE(int a, int b, int w){
    g[a].push_back({w, b});
    g[b].push_back({w, a});
}