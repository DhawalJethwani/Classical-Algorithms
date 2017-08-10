#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

void arrmerge(float *a,int start,int mid,int last)
{
    int nl=mid-start+1;
    int nr=last-mid;
    float l[nl];
    int i;
    for(i=0;i<nl;i++)
    {
        l[i]=a[i+start];
    }
    float r[nr];
    for(i=0;i<nr;i++)
    {
        r[i]=a[mid+i+1];
    }
    i=0;
    int j=0;
    int k=start;
    while(i<nl && j<nr)
    {
        if(l[i]<=r[j])
        {
            a[k]=l[i];
            k++;
            i++;
        }
        else
        {
            a[k]=r[j];
            k++;
            j++;
        }
    }
    while(i<nl)
    {
        a[k]=l[i];
        k++;
        i++;
    }
    while(j<nr)
    {
        a[k]=r[j];
        k++;
        j++;
    }
    return;
}
void merge_sort(float a[],int n)
{
    for(int asize=1;asize<=n-1;asize=2*asize)
    {
        for(int lstart=0;lstart<n-1;lstart+=2*asize)
        {
            int mid=lstart+asize-1;
            int riend=min(lstart+asize*2-1,n-1);
            arrmerge(a,lstart,mid,riend);
        }
    }
}
int main()
{
    int i,n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    float a[n];
    printf("Enter the values :\n");
    for(i=0;i<n;i++)
    {
        scanf("%f",&a[i]);
    }
    merge_sort(a,n);
    printf("The sorted array :\n");
    for(i=0;i<n;i++)
    {
        printf("%.2f ",a[i]);
    }
    printf("\n");
    return 0;
}
