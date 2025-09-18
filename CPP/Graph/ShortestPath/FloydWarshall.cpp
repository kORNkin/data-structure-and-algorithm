/*
Topic: Garph
Sub-topic: Floyd Warshall Algor (All Pair Shortest Paths)
Author: kornkin
*/

#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

void floyd_warshall(vector<vector<int>>& dis){
    int V = dis.size();

    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            for(int k = 0; k < V; k++)
                if(dis[i][j] != INF && dis[j][k] != INF)
                    dis[i][k] = min(dis[i][k], dis[i][j] + dis[j][k]); 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<vector<int>> dis = {
        {0, 4, INF, 5, INF},
        {INF, 0, 1, INF, 6},
        {2, INF, 0, 3, INF},
        {INF, INF, 1, 0, 2},
        {1, INF, INF, 4, 0}
    };

    floyd_warshall(dis);

    for(int i = 0; i < dis.size(); i++)
        for(int j = 0; j < dis.size(); j++)
            cout << "Node " << i << " to " << j << " : " << dis[i][j] << '\n';

    return 0; 
}