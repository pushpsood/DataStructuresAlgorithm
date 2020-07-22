//Row major
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
        A=new int[n*(n+1)/2];
    }
    void Set(int,int,int);
    int Get(int,int);
    void Display();
    ~Matrix(){delete []A;}
};
void Matrix::Set(int i,int j,int x)
{
    if(i>=j)
        A[(i*(i-1)/2)+j-1]=x;
}
int Matrix::Get(int i,int j)
{
    if(i>= j)
        return A[i*(i-1)/2+j-1];
    else
        return 0;
}
void Matrix::Display()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>=j)
                cout<<A[i*(i-1)/2+j-1]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

int main()
{
    Matrix m(4);
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            int x;
            cin>>x;
            m.Set(i,j,x);
        }
    }
    m.Display();

}
