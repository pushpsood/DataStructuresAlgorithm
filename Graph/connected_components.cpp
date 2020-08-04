#include <iostream>
#include <vector>
//undirected
using std::vector;
using std::pair;
int ct=0;

void explore(vector<vector<int> > &adj,int x,vector<int> &visit)
{
    visit[x]=1;
    for(int i=0;i<adj[x].size();i++)
    {
        if(visit[adj[x][i]]==0)
        {
            explore(adj,adj[x][i],visit);
        }
    }

}

int number_of_components(vector<vector<int> > &adj) {
  //write your code here
  vector<int> visit(adj.size());
  ct=0;
  for(int i=0;i<adj.size();i++)
  {
      if(visit[i]==0)
      {
         explore(adj,i,visit);
         ct++;
      }
  }
  return ct;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << number_of_components(adj);
}
