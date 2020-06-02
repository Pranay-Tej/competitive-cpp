#include <bits/stdc++.h>
using namespace std;

// (id, distance)
vector< vector< pair<int,int> > > adjacency_list;

vector<int> findShortestDistancesFromSource(int source_node){
    int nodes = adjacency_list.size();
    // initialize a vector with length nodes and values as infinity
    vector<int> shortest_distances(nodes, INT_MAX);
    // set to keep track of nodes for which distance is finalized
    set<int> finalized;
    
    shortest_distances[source_node] = 0;
    
    // loop until all nodes are finalized
    while(finalized.size() < nodes){

        // find the closest node
        int closest_node;
        int current_shortest_distance = INT_MAX;
        for(int i=0;i<shortest_distances.size();i++){
            if(finalized.count(i) > 0){
                // skip finalized nodes
                continue;
            }

            if(shortest_distances[i] < current_shortest_distance){
                current_shortest_distance = shortest_distances[i];
                closest_node = i;
            }
        }

        // finalize the node with closest distance
        finalized.insert(closest_node);

        // explore the nodes adjacent to closest_node
        // and find their distances via closest_node
        for(int i=0;i<adjacency_list[closest_node].size();i++){
            int adjacent_node = adjacency_list[closest_node][i].first;
            int edge_distance = adjacency_list[closest_node][i].second;
            int distance_via_closest_node = shortest_distances[closest_node] + edge_distance;
            
            if(distance_via_closest_node < shortest_distances[adjacent_node]){
                shortest_distances[adjacent_node] = distance_via_closest_node;
            }
        }

    }

    return shortest_distances;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int nodes, edges;
        cin>>nodes>>edges;
        // indexing from 0
        adjacency_list.resize(nodes);

        for(int i=0;i<edges;i++){
            int node_x, node_y, distance;
            cin>>node_x>>node_y>>distance;
            adjacency_list[node_x].push_back({node_y,distance});
            // for undirected graph
            adjacency_list[node_y].push_back({node_x,distance});

        }

        int source_node;
        cin>>source_node;

        vector<int> shortest_distances = findShortestDistancesFromSource(source_node);

        // for(int i=0;i<nodes;i++){
        //     for(int j=0;j<adjacency_list[i].size();j++){
        //         cout<<adjacency_list[i][j].first<<" "<<adjacency_list[i][j].second<<" ";
        //     }
        //     cout<<endl;
        // }

        for(int i=0;i<shortest_distances.size();i++){
            cout<<shortest_distances[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}