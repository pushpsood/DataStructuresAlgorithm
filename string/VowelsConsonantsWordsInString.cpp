
#include<iostream>
using namespace std;
int main()
{
    int v=0,c=0,w=0;
    char A[]="How Are You";
    int i;
    for(i=0;A[i]!='\0';i++)
        {
            if(A[i]=='a'||A[i]=='e'||A[i]=='i'||A[i]=='o'||A[i]=='u'||
               A[i]=='A'||A[i]=='E'||A[i]=='I'||A[i]=='O'||A[i]=='O')
                v++;
            else if((A[i]>=65&&A[i]<=90)||(A[i]>=97&&A[i]<=122))
                c++;
            if(A[i]==' '&&A[i-1]!=' ')
                w++;

        }
        if(A[i-1]!=' ')
            w++;
        cout<<"\nVowles: "<<v;
        cout<<"\nConsonants: "<<c;
        cout<<"\nWords: "<<w;

    return 0;
}

