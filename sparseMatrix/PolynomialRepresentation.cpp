#include<iostream>
using namespace std;
struct Term
{
    int coeff;
    int exp;
};
struct Poly
{
    int n;
    struct Term *t;
};
void Create(struct Poly *p)
{
    cout<<"No of terms";
    int num;
    cin>>num;
    p->n=num;
    p->t=new struct Term[num];
    cout<<"Enter terms\n";
    for(int i=0;i<num;i++)
    {
        cin>>p->t[i].coeff>>p->t[i].exp;
    }
}
void Display(struct Poly p)
{
    for(int i=0;i<p.n;i++)
        printf("(%dx^%d)+",p.t[i].coeff,p.t[i].exp);
    cout<<endl;
}
struct Poly *Add(struct Poly p1,struct Poly p2)
{
    int i=0,j=0,k=0;
    struct Poly *sum=new struct Poly();
    sum->t= new struct Term[p1.n+p2.n];
    while(i<p1.n&&j<p2.n)
    {
        if(p1.t[i].exp>p2.t[j].exp)
            sum->t[k++]=p1.t[i++];
        else if(p1.t[i].exp<p2.t[j].exp)
            sum->t[k++]=p2.t[j++];
        else{
            sum->t[k]=p1.t[i++];
            sum->t[k++].coeff+=p2.t[j++].coeff;
        }
    }
    for(;i<p1.n;i++)
    sum->t[k++]=p1.t[i];
    for(;j<p2.n;j++)
    sum->t[k++]=p2.t[j];
    sum->n=k;
    return sum;
};
int main()
{
    struct Poly p1,p2;
    Create(&p1);
    Create(&p2);
    struct Poly *p=Add(p1,p2);
    Display(p1);
    Display(p2);
    Display(*p);
}
