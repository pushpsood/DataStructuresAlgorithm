#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int dfs(vector<vector<int> > &adj, int x, vector<int> &visited, vector<int> &st)
{
    visited[x]=1;
    st[x]=1;
    for(int i=0;i<adj[x].size();i++)
    {
        if(!visited[adj[x][i]]&& dfs(adj, adj[x][i], visited, st))
            return 1;
        else if(st[adj[x][i]])
            return 1;
    }
    st[x]=0;
    return 0;
}


int acyclic(vector<vector<int> > &adj) {
  //write your code here
  vector<int> visited(adj.size());
  vector<int> st(adj.size());
  for(int i=0;i<adj.size();i++)
  {
      if(!visited[i])
      {
          if(dfs(adj,i,visited,st))
            return 1;
      }
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
