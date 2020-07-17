//Validating A String. Only numbers and Characters

#include<iostream>
using namespace std;
bool validate(char *A)
{
    int i;
    for(int i=0;A[i]!='\0';i++)
    {
        if(!(A[i]>=65&&A[i]<=90)&&!(A[i]>=97&&A[i]<=122)&&!(A[i]>=48&&A[i]<=57))
           return false;
    }
        return true;

}
int main()
{
    char *P="WeLComE124=5Goa";
    int i;
    bool val=validate(P);
    if(val==true)
        cout<<"Valid";
    else
        cout<<"Invalid";
    return 0;
}

