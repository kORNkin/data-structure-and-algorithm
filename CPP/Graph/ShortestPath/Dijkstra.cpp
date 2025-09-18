/*
Topic : Graph
Sub-Topic: Dijkstra Algorithm (Shortest Path)
Author: kornkin
*/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void addE(int a, int b, int weight); // add edge and weight function

vector<pii> g[1001]; // adjacency list graph with weight

int Dijkstra(int source, int target){
    vector<int> distance (1001, INT_MAX);

    distance[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, source});

    while(!pq.empty()){
        int current_node = pq.top().second;
        pq.pop();

        for(auto [weight, node] : g[current_node]){
            if(distance[node] > distance[current_node] + weight){
                distance[node] = distance[current_node] + weight;
                pq.push({distance[node], node});
            }
        }
    }

    return distance[target];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // add weighted edges
    addE(0,1,3);
    addE(0,2,2);
    addE(1,2,2);
    addE(1,4,4);
    addE(1,3,1);
    addE(2,3,3);
    addE(2,5,5);
    addE(2,6,6);
    addE(3,6,2);
    addE(4,6,1);
    addE(5,6,2);

    cout << "Shortest path from node 0 to node 6 weighs ";
    cout << Dijkstra(0, 5);
    
    return 0;
}

void addE(int a, int b, int weight) {
    g[a].push_back({weight, b});
    g[b].push_back({weight, a});
}