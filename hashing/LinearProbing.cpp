#include<iostream>
#define SIZE 10
using namespace std;
int h(int key)
{
    return key%SIZE;
}

int probe(int H[],int key)
{
    int index=h(key);
    int i=1;
    while(H[(index+i)%SIZE]!=0)
        i++;
    return (index+i)%SIZE;
}
void Insert(int H[],int key)
{
    int index=h(key);
    if(H[index]!=0)
        index=probe(H,key);
    H[index]=key;
}

bool Search(int H[],int key)
{
    int index=h(key);
    while(H[index]!=0)
    {
        if(H[(index++)%SIZE]==key)
            return true;
    }
    return false;
}

int main()
{
    int HT[10]={0};
    Insert(HT,10);
    Insert(HT,12);
    Insert(HT,14);
    Insert(HT,19);
    Insert(HT,24);
    Insert(HT,74);
    Insert(HT,774);
    Insert(HT,144);

    Insert(HT,784);
    for(int i=0;i<SIZE;i++)
    {
        cout<<HT[i]<<" ";
    }

    if(Search(HT,784))
        cout<<"Found";
}
