#include<iostream>
#include<queue>
using namespace std;

BFS(int A[][7],int start,int n=7)
{
    int i=start;
    queue<int> q;
    int visited[n]={0};
    cout<<i<<" ";
    q.push(i);
    visited[i]=1;
    while(!q.empty())
    {
        i=q.front();
        q.pop();
        for(int j=1;j<n;j++)
        {
            if(A[i][j]==1&&visited[j]==0)
            {
                cout<<j<<" ";
                visited[j]=1;
                q.push(j);
            }
        }
    }

}
DFS(int A[][7],int start,int n=7)
{
    static int visited[7]={0};
    if(visited[start]==0)
    {
        cout<<start<<" ";
        visited[start]=1;
        for(int j=1;j<n;j++)
        {
            if(A[start][j]==1&&visited[j]==0)
                DFS(A,j);
        }
    }
}
int main()
{
    int A[7][7]={{0,0,0,0,0,0,0},
    {0,0,1,1,0,0,0},
    {0,1,0,0,1,0,0},
    {0,1,0,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}
    };
    DFS(A,1);
    cout<<endl;
    BFS(A,4);
}
