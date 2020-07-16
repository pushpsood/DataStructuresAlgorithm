#include<stdio.h>

struct Array{
int *A;
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
int main()
{
   struct Array arr;
   int n,i;
   printf("Enter the size of the array\n");
   scanf("%d",&arr.sz);
   arr.A=new int[arr.sz];
   arr.length=0;
   printf("Enter the number of numbers\n");
   scanf("%d",&n);
   for(int i=0;i<n;i++)
    scanf("%d",&arr.A[i]);
   arr.length=n;
   Display(arr);
   return 0;
}
