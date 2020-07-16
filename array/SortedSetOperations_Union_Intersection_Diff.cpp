

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

struct Array Union(struct Array *arr1,struct Array *arr2)
{
    int i,j,k=0;;
    struct Array arr;
    arr.sz=20;
    for(i=0,j=0;i<arr1->length,j<arr2->length;)
    {
        if(arr1->A[i]>arr2->A[j])
            arr.A[k++]=arr2->A[j++];
        else if(arr1->A[i]==arr2->A[j])
        {
            arr.A[k++]=arr1->A[i++];
            j++;
        }
        else
            arr.A[k++]=arr1->A[i++];
    }
    while(i<arr1->length)
        arr.A[k++]=arr1->A[i++];
    while(i<arr2->length)
        arr.A[k++]=arr1->A[j++];
    arr.length=k;
    return arr;

}

struct Array Intersection(struct Array *arr1,struct Array *arr2)
{
    int i,j,k=0;;
    struct Array arr;
    arr.sz=20;
    for(i=0,j=0;i<arr1->length,j<arr2->length;)
    {
        if(arr1->A[i]>arr2->A[j])
            j++;
        else if(arr1->A[i]==arr2->A[j])
        {
            arr.A[k++]=arr1->A[i++];
            j++;
        }
        else
            i++;
    }
    arr.length=k;
    return arr;

}

struct Array Difference(struct Array *arr1,struct Array *arr2)
{
    int i,j,k=0;;
    struct Array arr;
    arr.sz=20;
    for(i=0,j=0;i<arr1->length,j<arr2->length;)
    {
        if(arr1->A[i]>arr2->A[j])
            j++;
        else if(arr1->A[i]==arr2->A[j])
        {
            i++;
            j++;
        }
        else
            arr.A[k++]=arr1->A[i++];
    }
    while(i<arr1->length)
        arr.A[k++]=arr1->A[i++];
    arr.length=k;
    return arr;

}
int main()
{
   struct Array arr1={{1,5,7,55,99},20,5};
   struct Array arr2={{7,8,11,45,99},20,5};
   struct Array arr=Union(&arr1,&arr2);
   printf("Union");
   Display(arr);
   printf("\n");

   arr=Intersection(&arr1,&arr2);
   printf("InterSection");
   Display(arr);
   printf("\n");

   //arr1-arr2
   arr=Difference(&arr1,&arr2);
   printf("Union");
   Display(arr);
   printf("\n");
   return 0;
}
