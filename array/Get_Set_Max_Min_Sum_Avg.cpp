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


int Get

int main()
{
   struct Array arr={{1,5,2,4,6},10,5};
   printf("%d",LinearSearch(&arr,5));
   Display(arr);
   return 0;
}
