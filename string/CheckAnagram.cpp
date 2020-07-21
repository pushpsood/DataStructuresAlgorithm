#include<iostream>
using namespace std;
int main()
{
    char s[]="iwrotethis";
    char c[]="iwrotesth";
    int i,j;
    int arr[26];
    for(int k=0;k<26;k++)
        arr[k]=0;
    for(i=0;s[i]!='\0';i++);
    for(j=0;c[j]!='\0';j++);
    if(i!=j)
    {
        cout<<"Not Anagram";
        return 0;
    }

    for(int k=0;c[k]!='\0';k++)
    {
        arr[s[k]-97]+=1;
        arr[c[k]-97]-=1;
    }

    for(int k=0;k<26;k++)
    {
        if(arr[k]!=0)
            {
                cout<<"Not Anagram";
                return 0;
            }
    }
    cout<<"Anagram";
}
