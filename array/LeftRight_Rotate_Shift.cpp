
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
void Move(int *x,int *y)
{
    *x=*y;
}

void LShift(struct Array *arr)
{
    for(int i=0;i<arr->length-1;i++)
        Move(&arr->A[i],&arr->A[i+1]);
    arr->A[arr->length-1]=0;
}
void RShift(struct Array *arr)
{
    for(int i=arr->length-2;i>=0;i--)
        Move(&arr->A[i+1],&arr->A[i]);
    arr->A[0]=0;
}
void LRotate(struct Array *arr)
{
    int temp;
    temp=arr->A[0];
    for(int i=0;i<arr->length-1;i++)
        Move(&arr->A[i],&arr->A[i+1]);
    arr->A[arr->length-1]=temp;
}
void RRotate(struct Array *arr)
{
    int temp;
    temp=arr->A[arr->length-1];
    for(int i=arr->length-2;i>=0;i--)
        Move(&arr->A[i+1],&arr->A[i]);
    arr->A[0]=temp;
}
int main()
{
   struct Array arr={{1,5,2,4,6},10,5};
   LShift(&arr);
   printf("Left Shift");
   Display(arr);
   printf("\n");

   RShift(&arr);
   printf("Right Shift");
   Display(arr);
   printf("\n");

   arr.A[0]=100;

   LRotate(&arr);
   printf("Left Rotate");
   Display(arr);
   printf("\n");

   RRotate(&arr);
   printf("Left Rotate");
   Display(arr);
   printf("\n");
   return 0;
}
