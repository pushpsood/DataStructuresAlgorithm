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
void Swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void Reverse(struct Array *arr)
{
    for(int i=0,j=arr->length-1;i<j;i++,j--)
        Swap(&arr->A[i],&arr->A[j]);
}
int main()
{
   struct Array arr={{1,5,2,4,6},10,5};
   Reverse(&arr);
   Display(arr);
   return 0;
}
