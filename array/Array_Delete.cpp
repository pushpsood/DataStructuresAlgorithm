
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

int Delete(struct Array *arr,int index)
{
    int x=0;
    if(index>=0&&index<=arr->length-1)
    {
        x=arr->A[index];
        for(int i=index;i<arr->length-1;i++)
            arr->A[i]=arr->A[i+1];
        arr->length--;
        return x;
    }
    return -1;
}

int main()
{
   struct Array arr={{1,5,2,4,6},10,5};

   printf("%d\n",Delete(&arr,1));
   Display(arr);
   return 0;
}
