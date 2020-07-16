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


int Get(struct Array arr,int index)
{
    if(index>=0 && index<arr.length-1)
        return arr.A[index];
    return -1;
}
int Set(struct Array *arr,int a,int index)
{
    if(index>=0&&index<arr->length-1)
        arr->A[index]=a;
    return 0;
}
int Max(struct Array arr)
{
    int m=-1;
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]>m)
            m=arr.A[i];
    }
    return m;
}
int Min(struct Array arr)
{
    int m=100000;
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]<m)
            m=arr.A[i];
    }
    return m;
}
int Sum(struct Array arr)
{
    int sum=0;
    for(int i=0;i<arr.length;i++)
        sum+=arr.A[i];
    return sum;
}

int main()
{
   struct Array arr={{1,5,2,4,6},10,5};
   printf("Get: %d\n",Get(arr,3));
   Set(&arr,100,3);
   printf("Set Done\n");

   printf("Max: %d\n",Max(arr));
   int sum=Sum(arr);
   printf("Sum: %d\n",sum);
   printf("Avg: %d\n",sum/arr.length);

   Display(arr);
   return 0;
}
