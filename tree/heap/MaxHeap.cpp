#include<vector>
#include<iostream>
using namespace std;
void Insert(vector<int> &a,int pos)
{
    int temp=a[pos],i=pos;
    while(i>1&&temp>a[i/2])
    {
        a[i]=a[i/2];
        i=i/2;
    }
    a[i]=temp;
}

int main()
{
    vector<int> a;
    a.push_back(-1);
    a.push_back(40);
    a.push_back(35);
    a.push_back(15);
    a.push_back(30);
    a.push_back(10);
    a.push_back(12);

    int pos=7;
    a.push_back(50);

    Insert(a,pos);
    for(int i=1;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }
}
