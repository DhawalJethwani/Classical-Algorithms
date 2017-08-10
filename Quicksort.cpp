#include <stdio.h>
#include <stdlib.h>

void iswap(float *a,float *b)
{
    float t=*a;
    *a=*b;
    *b=t;
}

int partionIndex(float *arr,int start,int last)
{
    int pivot;
    printf("\nEnter the pivot index (in the range %d to %d): ",start+1,last+1);
    float p;
    fflush(stdout);
    scanf("%f",&p);
    pivot=(int)p;
    while(p!=pivot || pivot<start+1 || pivot>last+1)
    {
        printf("Invalid Input!\nPivot should be a non negative integer, greater than %d and less than %d\n",start+1,last+1);
        fflush(stdout);
        scanf("%f",&p);
        pivot=(int)p;
    }
    pivot=pivot-1;
    printf("Chosen Pivot : %f\n",arr[pivot]);
    int pIndex=start;
    int i;
    for(i=start;i<=last;i++)
    {
        if(arr[i]<arr[pivot])
        {
            if(pIndex==pivot && pIndex<last)
            {
                pIndex++;
            }
            iswap(arr+pIndex,arr+i);
            pIndex++;
        }
    }
    if(pIndex>pivot)
    {
        iswap(arr+pivot,arr+pIndex-1);
        pIndex--;
    }
    else
    {
        iswap(arr+pIndex,arr+pivot);
    }
    return pIndex;
}

float *quickSort(float *arr,int start,int last,int n)
{
    printf("\n");
    int stk[last-start+1];
    int top=-1;
    stk[++top]=start;
    stk[++top]=last;
    while(top>=0)
    {
        last=stk[top--];
        start=stk[top--];
        int pIndex=partionIndex(arr,start,last);
        printf("\nArray after rearrangement about the chosen pivot :\n");
        int j;
        for(j=0;j<n;j++)
        {
            if(j==pIndex)
            {
                printf(" -> {%.2f} <-  ",*(arr+j));
            }
            else
            {
                printf("%.2f ",*(arr+j));
            }
        }
        if(pIndex-1>start)
        {
            stk[++top]=start;
            stk[++top]=pIndex-1;
        }
        if(pIndex+1<last)
        {
            stk[++top]=pIndex+1;
            stk[++top]=last;
        }
    }
    return arr;
}

int main()
{
    float p;
    int n;
    printf("Enter the size of the array : ");
    fflush(stdout);
    scanf("%f",&p);
    n=(int)p;
    while(p!=n || n<0)
    {
        printf("Invalid Input! Size should be a non negative integer.\n");
        fflush(stdout);
        scanf("%f",&p);
        n=(int)p;
    }
    printf("Enter %d floating point numbers in the array :\n",n);
    float *arr=(float *)malloc(n*sizeof(float));
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%f",arr+i);
    }
    quickSort(arr,0,n-1,n);
    printf("\nSorted Array :\n");
    for(i=0;i<n;i++)
    {
        printf("%.2f ",*(arr+i));
    }
    printf("\n");
    return 0;
}
