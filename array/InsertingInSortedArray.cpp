
#include<stdio.h>

struct Array{
int A[10];
int sz;
int length;
};
void Display(struct Array arr)
{
    int i;
    printf("\nElements are\n");
    for(int i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
}

int InsertS(struct Array *arr,int x)
{
    if(arr->length==arr->sz)
        return -1;
    int i;
    for(i=arr->length-1;arr->A[i]>x;i--)
    {
        arr->A[i+1]=arr->A[i];
    }
    arr->length++;
    arr->A[i+1]=x;
    return 0;
}
int main()
{
   struct Array arr={{1,5,7,55,100},10,5};
   InsertS(&arr,3);
   Display(arr);
   return 0;
}
