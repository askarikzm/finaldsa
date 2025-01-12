#include <iostream>
#include <queue>
using namespace std;
void bfs(int graph[][5],int start,int numberVertics){
    bool visited[5]={false};
    queue<int> q;
    //start bfs from given source 
    visited[start]=true;
    q.push(start);

    cout<<"Bfs Travesel"<<endl;
    while(!q.empty()){
        int current=q.front(); // get front element
       // visit all the neighbours of start node
       for(int i=0;i<numberVertics;i++){
        if(graph[current][i]==1 && !visited[i]){
            visited[i]=true;
            q.push(i);
        }
       } 
    }
}

int main() {
    // Adjacency matrix representation of the graph
    int graph[5][5] = {
        {0, 1, 1, 0, 0},  // Connections for vertex 0
        {1, 0, 0, 1, 1},  // Connections for vertex 1
        {1, 0, 0, 0, 1},  // Connections for vertex 2
        {0, 1, 0, 0, 0},  // Connections for vertex 3
        {0, 1, 1, 0, 0}   // Connections for vertex 4
    };

    int startVertex = 0; // Starting vertex
    bfs(graph, startVertex, 5);

    return 0;
}