
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

void Append(struct Array *arr,int x)
{
    if(arr->length<arr->sz)
        arr->A[arr->length++]=x;
}

void Insert(struct Array *arr,int index,int x)
{
    if(index>=0&& index<=arr->length)
    {
        for(int i=arr->length;i>index;i--)
            arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->length++;
    }

}

int main()
{
   struct Array arr={{1,5,2,4,6},10,5};

   Append(&arr,15);

   Insert(&arr,5,10);

   Display(arr);
   return 0;
}
