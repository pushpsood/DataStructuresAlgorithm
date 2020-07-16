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

int IsSorted(struct Array *arr)
{
    for(int i=0;i<arr->length-1;i++)
    {
        if(arr->A[i]>arr->A[i+1])
            return -1;
    }
    return 1;

}
int main()
{
   struct Array arr={{1,5,7,55,100},10,5};
   printf("IsSorted? %d\n",IsSorted(&arr));
   Display(arr);
   return 0;
}
