#include<bits/stdc++.h>
using namespace std;

// Assumptions:
// Undirected Graph
// Connected Graph => n nodes have atleast n-1 edges
// Count Starts from 0

// Example
    //         0
        // 1           2       3
    // 4       5                6
    //                             7

//  variables

vector< vector<int> > adjacency_list;

set<int> visited;

vector<int> shortest_distances;

// BFS

void BFS(int start_node){
    visited.clear();
    
    queue<int> Q;

    Q.push(start_node);
    visited.insert(start_node);
    shortest_distances[start_node] = 0;

    while(!Q.empty()){
        int current_node = Q.front();
        Q.pop();
        for(int i=0;i<adjacency_list[current_node].size();i++){
            int adjacent_node = adjacency_list[current_node][i]; 
            if(visited.count(adjacent_node) != 0){
                continue;
            }
            Q.push(adjacent_node);
            visited.insert(adjacent_node);
            shortest_distances[adjacent_node] = shortest_distances[current_node] + 6;
        }
    }

}


int main(){
    int q;
    cin>>q;
    while(q--){
        // number of nodes, edges
        int nodes,edges;
        cin>>nodes>>edges;
        adjacency_list.clear();
        adjacency_list.resize(nodes + 1);

        // loop through the edges
        for(int i=0;i<edges;i++){
            // vertices of each edge
            int node_x,node_y;
            cin>>node_x>>node_y;

            // mark connections to each other
            adjacency_list[node_x].push_back(node_y);
            adjacency_list[node_y].push_back(node_x);
        }

        int start_node;
        cin>>start_node;

        shortest_distances.clear();
        shortest_distances.resize(nodes + 1, -1);
        BFS(start_node);
        for(int i=1;i<=nodes;i++){
            if(i != start_node){
                cout<<shortest_distances[i]<<" ";
            }
        }
        cout<<endl;
    }
}
