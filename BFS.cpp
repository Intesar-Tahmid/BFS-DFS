#include <bits/stdc++.h>

using namespace std;

struct Edge{
    int src;
    int dest;
};

class Graph{
    public:
        //a vector of vector to represent adjacent list of the graph
        vector<vector<int>>adjList;
        //Graph constructor
        Graph(vector<Edge>const &edges, int n)
        {
            adjList.resize(n);
            //add edges to the undirected graph
            for(auto &edge: edges)
            {
                adjList[edge.src].push_back(edge.dest);
                adjList[edge.dest].push_back(edge.src);
            }
        }
};

//perform BFS on the graph starting from vertex 'v' 
void BFS(Graph const &graph, int v, vector<bool>&discovered)
{
    //create a new queue for doing BFS
    queue<int>q;
    //mark the source vertex as discovered
    discovered[v] = true;

    //enqueue source vertex
    q.push(v);

    //loop till queue is empty
    while(!q.empty())
    {
        //dequeue front node and print it
        v = q.front();
        q.pop();
        cout << v << " ";
        //do for every edge(v, u)
        for(int u: graph.adjList[v])
        {
            if(!discovered[u])
            {
                //mark it as discovered and enqueue it
                discovered[u] = true;
                q.push(u);
            }
        }
    }
}

int main()
{
    vector<Edge>edges = {
       {1, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}, {5, 9},
        {5, 10}, {4, 7}, {4, 8}, {7, 11}, {7, 12}
        // vertex 0, 13, and 14 are single nodes
    };

    //total number of nodes in the graph labeled from 0 to 14
    int n = 15;

    //build a graph from given edges. It's function call
    Graph graph(edges, n);

    //to keep track of whether a vertex is discovered or not
    vector<bool>discovered(n, false);

    //perform BFS traversal from all undiscovered nodes to cover all connected components of a graph
    for(int i = 0; i<n; i++)
    {
        if(discovered[i] == false)
        {
            //start BFS from vertex i
            BFS(graph, i, discovered);
        }
    }

    return 0;
}