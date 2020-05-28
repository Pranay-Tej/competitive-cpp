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

vector<int> bfs_list;

vector<int> dfs_list;

vector<int> shortest_distances;


// BFS

void BFS(int start_node){
    visited.clear();
    
    queue<int> Q;

    Q.push(start_node);

    while(!Q.empty()){
        int current_node = Q.front();
        Q.pop();
        
        visited.insert(current_node);
        // cout<<current_node<<" ";
        bfs_list.push_back(current_node);
        
        for(int i=0;i<adjacency_list[current_node].size();i++){
            int adjacent_node = adjacency_list[current_node][i]; 
            if(visited.count(adjacent_node) != 0){
                continue;
            }
            Q.push(adjacent_node);
        }
    }

}

void BFSPrint(int start_node){
    visited.clear();
    bfs_list.clear();
    BFS(start_node);
    cout<<"Breadth First Search: ";
    for(int i=0;i<bfs_list.size();i++){
        cout<<bfs_list[i]<<" ";
    }
    cout<<endl;
}

// DFS

void DFS(int node){
    if(visited.count(node) != 0){
        return;
    }
    
    // cout<<node<<" ";
    dfs_list.push_back(node);

    visited.insert(node);
    for(int i=0;i<adjacency_list[node].size();i++){
        int adjacent_node = adjacency_list[node][i];
        if(adjacent_node == node){
            continue;
        }
        DFS(adjacent_node);
    }
}

void DFSPrint(int start_node){
    visited.clear();
    dfs_list.clear();
    DFS(start_node);
    cout<<"Depth First Search: ";
    for(int i=0;i<dfs_list.size();i++){
        cout<<dfs_list[i]<<" ";
    }
    cout<<endl;
}

// Connected Components

void ConnectedComponents(){

    vector< vector<int> > connected_components;

    // Using BFS
    visited.clear();
    for(int i=0;i<adjacency_list.size();i++){
        if(visited.count(i) > 0){
            continue;
        }
        bfs_list.clear();
        BFS(i);
        connected_components.push_back(bfs_list);
    }

    cout<<"Using BFS: "<<endl;

    // print connected components
    for(int i=0;i<connected_components.size();i++){
        for(int j=0;j<connected_components[i].size();j++){
            cout<<connected_components[i][j]<<" ";
        }
        cout<<endl;
    }


    // Using DFS
    connected_components.clear();
    visited.clear();
    for(int i=0;i<adjacency_list.size();i++){
        if(visited.count(i) > 0){
            continue;
        }
        dfs_list.clear();
        DFS(i);
        connected_components.push_back(dfs_list);
    }

    cout<<"Using DFS: "<<endl;

    // print connected components
    for(int i=0;i<connected_components.size();i++){
        for(int j=0;j<connected_components[i].size();j++){
            cout<<connected_components[i][j]<<" ";
        }
        cout<<endl;
    }

}

// ShortestReachFromSource
void ShortestReachWithBFS(int start_node){
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
    // number of nodes, edges
    int nodes,edges;
    cin>>nodes>>edges;
    adjacency_list.resize(nodes);

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

    BFSPrint(start_node);
    DFSPrint(start_node);

    ConnectedComponents();

    shortest_distances.clear();
    shortest_distances.resize(nodes + 1, -1);

    ShortestReachWithBFS(start_node);
    
    for(int i=1;i<=nodes;i++){
        if(i != start_node){
            cout<<shortest_distances[i]<<" ";
        }
    }
    cout<<endl;
}