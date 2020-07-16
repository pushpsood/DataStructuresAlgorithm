
#include<stdio.h>

struct Array{
int A[20];
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

struct Array MG(struct Array *arr1,struct Array *arr2)
{
    int i,j,k=0;;
    struct Array arr;
    arr.sz=20;
    for(i=0,j=0;i<arr1->length,j<arr2->length;)
    {
        if(arr1->A[i]>=arr2->A[j])
            arr.A[k++]=arr2->A[j++];
        else
            arr.A[k++]=arr1->A[i++];
    }
    while(i<arr1->length)
        arr.A[k++]=arr1->A[i++];
    while(i<arr2->length)
        arr.A[k++]=arr1->A[j++];
    arr.length=arr1->length+arr2->length;
    return arr;

}
int main()
{
   struct Array arr1={{1,5,7,55,100},20,5};
   struct Array arr2={{8,9,11,45,99},20,5};
   struct Array arr=MG(&arr1,&arr2);
   Display(arr);
   return 0;
}
