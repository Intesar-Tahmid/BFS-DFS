#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> v[10]; // Vector for maintaining adjacency list explained above
int level[10];     // To determine the level of each node
bool vis[10];      // Mark the node if visited


createAndAddEdge(vector <int> v[], int x, int y){
    v[x].push_back(y);
    v[y].push_back(x);
}
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    level[s] = 0; 
    vis[s] = true;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        cout << p << " eije lo" << endl;
        for (int i = 0; i < v[p].size(); i++)
        {
            if (vis[v[p][i]] == false)
            {
                
                level[v[p][i]] = level[p] + 1;
                q.push(v[p][i]);
                vis[v[p][i]] = true;
            }
        }
    }
}

int main(){
    
    int source = 0;

  createAndAddEdge(v, 0, 1);
  createAndAddEdge(v, 0, 2);
  createAndAddEdge(v, 1, 5);
  createAndAddEdge(v, 2, 3);
  createAndAddEdge(v, 2, 4);
  createAndAddEdge(v, 3, 3);
  createAndAddEdge(v, 4, 4);
  createAndAddEdge(v, 5, 5);

  bfs(0);

  return 0;

    


}