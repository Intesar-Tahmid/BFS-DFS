/* 
6 9 - 6 is the number of vertices and 9 is the number of edges
1 3
1 5
3 5
3 4
3 6
3 2
2 6
4 6
5 6
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10
vector<int>g[N];
bool vis[N];
//In DFS we need only one information, the vertex from whick
//we'll be start traversing
void dfs(int vertex){
    //we have to go to depth whenever we find a vertex
    //Take action on vertex after entering the vertex
    //if(vis[vertex]) return;
    vis[vertex] = true;
    for(int child : g[vertex]){
        cout << "Parent " << vertex << ", Child " << child << endl;
        if(vis[child]) continue;
        //Take action on child before entering the child node
        dfs(child);
        //Take action on child after exiting the child node
    }
    //Take action on vertex before exiting the vertex
}

int main()
{
    int n,m;
    for(int i = 0; i<9; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

}