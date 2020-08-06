#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

bool check_empty(vector<int> d)
{
    for(int i=0;i<d.size();i++)
    {
        if(d[i]>=0)
            return true;
    }
    return false;
}

int extract_min(vector<int> &d)
{
    int m=INT_MAX;
    int pos;
    for(int i=0;i<d.size();i++)
    {
        if(d[i]<m&&d[i]>=0)
            {
                m=d[i];
                pos=i;
            }
    }
    return pos;
}


long long distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code here
  vector<int> dist(adj.size());
  vector<int> H(adj.size());

  for(int i=0;i<adj.size();i++)
      {
          dist[i]=-1;
          H[i]=-1;
      }
  dist[s]=0;
  H[s]=0;
  while(check_empty(H))
  {
      int u=extract_min(H);
      for(int i=0;i<adj[u].size();i++)
      {
          int v=adj[u][i];
        if(dist[v]>dist[u]+cost[u][i]||(dist[v]==-1))
          {
              dist[v]=dist[u]+cost[u][i];
              H[v]=dist[v];
          }
      }
    H[u]=-100;
  }
  return dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
