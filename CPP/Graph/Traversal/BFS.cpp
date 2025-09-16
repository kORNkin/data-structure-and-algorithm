/*
Topic: Graph
Sub-Topic: Breadth First Search Traversal
Author: kornkin
*/

#include<bits/stdc++.h>
using namespace std;

void addE(int a, int b); // add 2-way edge function

vector<int> g[1001]; // adjacency list graph

vector<bool> visit(1001, 0); // visited node checker

void BFS(int start) {
    queue<int> q; // queue for Breadth First Search 
    
    q.push(start); // push starting node

    while(!q.empty()){
        
        int current_node = q.front();
        q.pop();

        if(visit[current_node]) continue; // check if visited already
        visit[current_node] = 1;

        for(int node : g[current_node]){ // traverse all nodes connected with current node
            if(visit[node]) continue;

            q.push(node); // push new node in queue
        }

        cout << current_node << ' ';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // add edges
    addE(1,2);
    addE(1,3);
    addE(1,4);
    addE(2,5);
    addE(3,6);
    addE(3,7);
    addE(4,8);
    addE(5,9);
    addE(6,10);    

    BFS(1);

    return 0;
}

void addE(int a, int b){ 
    g[a].push_back(b);
    g[b].push_back(a);
}