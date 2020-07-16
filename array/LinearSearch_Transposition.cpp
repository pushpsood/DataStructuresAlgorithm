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

int LinearSearch(struct Array *arr,int key)
{
    int i=0;
    for(i=0;i<arr->length;i++)
    {
        if(arr->A[i]==key)
        {
            if(i!=0)
            Swap(&arr->A[i],&arr->A[i-1]);//Transposition
            //Swap(&arr->A[i],&arr->A[0])//Move to head
            return i;
        }
    }
    return -1;

}

int main()
{
   struct Array arr={{1,5,2,4,6},10,5};
   printf("%d",LinearSearch(&arr,5));
   Display(arr);
   return 0;
}
