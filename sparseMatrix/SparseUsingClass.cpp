#include<iostream>
using namespace std;
class Element
{
public:
    int i;
    int j;
    int x;
};
class Sparse
{
    int m;
    int n;
    int num;
    Element *ele;
public:
    Sparse(int m,int n,int num)
    {
        this->m=m;
        this->n=n;
        this->num=num;
        ele=new Element[this->num];
    }
    ~Sparse()
    {
        delete []ele;
    }
    void Read();
    void Display();
};
void Sparse::Read()
{
    cout<<"Enter non zero element\n";
    for(int i=0;i<n;i++)
        cin>>ele[i].i>>ele[i].j>>ele[i].x;
}
void Sparse::Display()
{
    int k=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(ele[k].i==i&&ele[k].j==j)
                cout<<ele[k++].x<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}
int main()
{
    Sparse s(5,5,5);
    s.Read();
    s.Display();
}
