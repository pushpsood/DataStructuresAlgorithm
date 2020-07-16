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


int BinarySearch(struct Array arr,int l,int h,int mid,int key)
{
    if(l>=h)
        return -1;
    if(arr.A[mid]==key)
        return mid;
    else if(arr.A[mid]>key)
        return BinarySearch(arr,l,mid-1,(l+mid-1)/2,key);
    else if(arr.A[mid]<key)
        return BinarySearch(arr,mid+1,h,(l+mid+1)/2,key);
}

int main()
{
   struct Array arr={{1,2,3,4,5,6,7},10,7};
   printf("%d",BinarySearch(arr,0,arr.length-1,(0+arr.length-1)/2,100));
   Display(arr);
   return 0;
}
