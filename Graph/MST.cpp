#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int x;
    int y;
    int d;
    Edge();
    Edge(int x, int y, int d);
    // for comparing Edges by distance
    bool operator<(const Edge &edge) const;
};

Edge::Edge()
{
    this->x = -1;
    this->y = -1;
    this->d = -1;
}

Edge::Edge(int x, int y, int d)
{
    this->x = x;
    this->y = y;
    this->d = d;
}

bool Edge::operator<(const Edge &edge) const{
    return this->d < edge.d;
}

// (id, distance)
vector< vector<int> > adjacency_list;
vector<Edge> edge_list;
vector<Edge> mst_edge_list;
set<int> finalized_node_set;

// TestCase
// 1
// 4 5
// 0 1 1
// 0 2 4
// 0 3 3
// 2 3 5
// 1 3 2
// 0 1 1
// 0 2 4
// 0 3 3
// 2 3 5
// 1 3 2

// Output
// 0 1 1
// 1 3 2
// 0 2 4
// Minimum Cost: 7

void KruskalMST(){
    
    // ? What if we sort the edge_list according to distance
    
    // reset
    mst_edge_list.clear();
    finalized_node_set.clear();

    int node_count = adjacency_list.size();

    // loop until n-1 edges are selected as mst_edges
    while(mst_edge_list.size() < node_count - 1){
        // find min_cost_edge
        Edge min_cost_edge;
        min_cost_edge.d = INT_MAX;

        for(int i=0;i<edge_list.size();i++){
            int x = edge_list[i].x;
            int y = edge_list[i].y;
            int d = edge_list[i].d;

            // check for cycle
            if(x == y){
                continue;
            }

            if(finalized_node_set.count(x) > 0 && finalized_node_set.count(y) > 0){
                // TODO: use a set for edge_list and remove the current node from set to avoid re-calculation

                // edge will form a cycle, skip the edge
                continue;
            }

            if(d < min_cost_edge.d){
                min_cost_edge.x = x;
                min_cost_edge.y = y;
                min_cost_edge.d = d;
            }
        }

        // finalize the nodes of edge
        finalized_node_set.insert(min_cost_edge.x);
        finalized_node_set.insert(min_cost_edge.y);
        
        // add edge to mst
        mst_edge_list.push_back(min_cost_edge);
    }
}

void KruskalMST_v2(){
    // reset
    mst_edge_list.clear();
    finalized_node_set.clear();

    int node_count = adjacency_list.size();

    set<Edge> edge_set;

    for(int i=0;i<edge_list.size();i++){
        edge_set.insert(edge_list[i]);
    }
    // set<Edge> edge_set(edge_list.begin(), edge_list.end());

    for(auto iter = edge_set.begin(); iter != edge_set.end(); iter++){
        
        if(mst_edge_list.size() >= node_count -1 ){
            // n nodes have n-1 edges in mst
            break;
        }

        int x = (*iter).x;
        int y = (*iter).y;
        int d = (*iter).d;

        // check for cycle
        if(x == y){
            continue;
        }

        if(finalized_node_set.count(x) > 0 && finalized_node_set.count(y) > 0){
            // edge will form a cycle, skip the edge
            continue;
        }

        // finalize the nodes of edge
        finalized_node_set.insert(x);
        finalized_node_set.insert(y);
        
        // add edge to mst
        mst_edge_list.push_back(*iter);

    }
}

void showMST(){
    int min_cost = 0;

    for(int i=0;i<mst_edge_list.size();i++){
        int x = mst_edge_list[i].x;
        int y = mst_edge_list[i].y;
        int d = mst_edge_list[i].d;
        min_cost += d;
        cout<<x<<" "<<y<<" "<<d<<endl;
    }
    
    cout<<"Minimum Cost: "<<min_cost<<endl;
}

int main(){
    
    // read input from ip.txt file
    freopen("ip.txt","r",stdin);

    int test_case_count;
    cin>>test_case_count;
    while(test_case_count--){
        int node_count, edge_count;
        cin>>node_count>>edge_count;
        // indexing from 0
        adjacency_list.resize(node_count);

        for(int i=0;i<edge_count;i++){
            int node_x, node_y, distance;
            cin>>node_x>>node_y>>distance;
            Edge edge = Edge(node_x, node_y, distance);
            edge_list.push_back(edge);
            adjacency_list[node_x].push_back(node_y);
            // for undirected graph
            adjacency_list[node_y].push_back(node_x);

        }

        for(int i=0;i<edge_list.size();i++){
            cout<<edge_list[i].x<<" "<<edge_list[i].y<<" "<<edge_list[i].d<<endl;
        }

        cout<<endl;

        KruskalMST();

        showMST();

        KruskalMST_v2();

        showMST();     

        cout<<endl;
    }
    return 0;
}