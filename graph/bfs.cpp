#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::cout;

void bfs(vector<vector<int> > &adj, int s, int t,vector<int> &d)
{
    queue<int> q;
    q.push(s);
    d[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];
            if(d[v]==-1)
            {
                q.push(v);
                d[v]=d[u]+1;
            }
        }
    }
}

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here
  vector<int> distance(adj.size());
  for(int i=0;i<adj.size();i++)
    distance[i]=-1;
  bfs(adj,s,t,distance);
  return distance[t];
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
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
