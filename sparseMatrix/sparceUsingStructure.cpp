
#include<iostream>
using namespace std;
struct Element
{
    int i,j,x;
};
struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *ele;
};
void Create(struct Sparse *s)
{
    cout<<"Enter Dimensions";
    cin>>s->m;
    cin>>s->n;
    cout<<"Non Zero Elements";
    cin>>s->num;
    s->ele=new struct Element[s->num];
    cout<<"Enter Elements";
    for(int i=0;i<s->num;i++)
        cin>>s->ele[i].i>>s->ele[i].j>>s->ele[i].x;
}
void Display(struct Sparse s)
{
    int k=0;
    for(int i=0;i<s.m;i++)
    {
        for(int j=0;j<s.n;j++)
        {
            if(i==s.ele[k].i&&j==s.ele[k].j)
                cout<<s.ele[k++].x<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}
int main()
{
    struct Sparse s;
    Create(&s);
    Display(s);


}
