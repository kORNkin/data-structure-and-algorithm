/*
Topic: Graph
Sub-Topic: Depth First Search Traversal
Author: kornkin
*/

#include<bits/stdc++.h>
using namespace std;

void addE(int a, int b); // add 2-way edge function 

vector<int> g[1001]; // adjacency list graph

vector<bool> visit(1001, 0); // visited node checker

void DFS_Stack(int start){
    stack<int> st; // stack for Depth First Search

    st.push(start); // push starting node

    while(!st.empty()){
        int current_node = st.top();
        st.pop();

        if(visit[current_node]) continue; // check if visited already
        visit[current_node] = 1;

        for(int node : g[current_node]){ // traverse all nodes connected wiht current node
            if(visit[node]) continue;

            st.push(node);
        }

        cout << current_node << ' ';
    }
}

void DFS_Recursion(int current_node){
    if(visit[current_node]) return; // check if visited already
    visit[current_node] = 1;

    cout << current_node << ' ';

    for(int node : g[current_node]){ // traverse all nodes connected wiht current node
        if(visit[node]) continue;

        DFS_Recursion(node); // recurse next node deeply
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
    
    cout << "DFS with Stack: ";
    DFS_Stack(1);

    fill(visit.begin(), visit.end(), 0);
    cout << '\n';

    cout << "DFS with Recursive Function: ";
    DFS_Recursion(1);

    return 0;
}

void addE(int a, int b){
    g[a].push_back(b);
    g[b].push_back(a);
}