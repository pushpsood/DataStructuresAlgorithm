
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
struct Sparse *Add(struct Sparse *s1,struct Sparse *s2)
{
    int i=0,j=0,k=0;
    struct Sparse *sum=new struct Sparse();
    sum->ele=new struct Element[s1->num+s2->num];
    while(i<s1->num&&j<s2->num)
    {
        if(s1->ele[i].i<s2->ele[j].i)
            sum->ele[k++]=s1->ele[i++];
        else if(s1->ele[i].i>s2->ele[j].i)
            sum->ele[k++]=s2->ele[j++];
        else
        {
            if(s1->ele[i].j<s2->ele[j].j)
            sum->ele[k++]=s1->ele[i++];
            else if(s1->ele[i].j>s2->ele[j].j)
            sum->ele[k++]=s2->ele[j++];
            else{
            sum->ele[k]=s1->ele[i];
            sum->ele[k++].x=s1->ele[i++].x+s2->ele[j++].x;}
        }
    }
    for(;i<s1->num;i++)
        sum->ele[k++]=s1->ele[i];
    for(;j<s2->num;j++)
        sum->ele[k++]=s2->ele[j];
        sum->m=s1->m;
        sum->n=s1->n;
        sum->num=k;
    return sum;
}
int main()
{
    struct Sparse s1,s2;
    Create(&s1);
    Create(&s2);

    struct Sparse *sum=Add(&s1,&s2);
    cout<<"First\n";
    Display(s1);
    cout<<"\nSecond\n";
    Display(s2);
    cout<<"\nSum\n";
    Display(*sum);


}
