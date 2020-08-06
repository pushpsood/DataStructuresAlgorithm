#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;


int bfs(vector<vector<int> > &adj, int s,vector<int> &color)
{
    queue<int> q;
    q.push(s);

    color[s]=1;
    int ct=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            if(color[v]==-1)
            {
                color[v]=1-color[u];
                q.push(v);
            }
            else if(color[v]==color[u])
                return 0;
        }
    }
    return 1;
}


int bipartite(vector<vector<int> > &adj) {
  //write your code here
   vector<int> color(adj.size());
    for(int i=0;i<adj.size();i++)
    color[i]=-1;
  for(int i=0;i<adj.size();i++)
  {
      if(color[i]==-1){
      if(bfs(adj,i,color)) continue;
      else
        return 0;
      }
  }
  return 1;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
