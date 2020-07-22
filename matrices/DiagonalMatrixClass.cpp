
#include<iostream>
using namespace std;
class Matrix
{
    int *A;
    int n;
public:
    Matrix(int x)
    {
        this->n=x;
        A=new int[x];
    }
    void Set(int,int,int);
    int Get(int,int);
    void Display();
    ~Matrix(){delete []A;}
};
void Matrix::Set(int i,int j,int x)
{
    if(i==j)
        A[i-1]=x;
}
int Matrix::Get(int i,int j)
{
    if(i==j)
        return A[i-1];
    else
        return 0;
}
void Matrix::Display()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                cout<<A[i]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

int main()
{
    Matrix m(4);
    m.Set(1,1,20);
    m.Set(2,2,10);
    m.Set(3,3,-20);
    m.Set(4,4,100);
    m.Display();
}
