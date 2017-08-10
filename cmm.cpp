#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
void PrintCombination(vector<vector<int> >arr,int i,int j){
    if (i==j){
        printf("A%d",i);
    }
    else{
        printf("(");
        PrintCombination(arr,i,i+arr[i][j]);
        PrintCombination(arr,i+arr[i][j]+1,j);
        printf(")");
    }
}

int main()
{
    int p[]={30,35,15,5,10,20,25};
    int n=(sizeof(p)/sizeof(4))-1;
    int minimum=0;
    int i,j,k,x,y;
    int A[n][n];
    vector<vector<int> >Valueofk(n,vector<int>(n));
    for (i=0;i<=n-1;i++){
        for (j=0;j<=n-1;j++){
            if (i>=j){
                A[i][j]=0;
            }
        }
    }

    for (i=0;i<=n-1;i++){
        for (j=0;j<=n-1;j++){
            if (i>=j){
                Valueofk[i][j]=0;
            }
        }
    }

    for(i=1;i<=n-1;i++){
        for (j=1;j<=n-i;j++){
                minimum=99999999;
            for(k=0;k<=i-1;k++){
                x=A[j-1][j+k-1]+A[j+k][j+i-1]+(p[j-1]*p[j+k]*p[j+i]);
                if(x<minimum){
                    minimum=x;
                    y=k;
                }
            }
            A[j-1][j+i-1]=minimum;
            Valueofk[j-1][j+i-1]=y;
        }
    }

    for (i=0;i<=n-1;i++){
        for (j=0;j<=n-1;j++){
            cout<< A[i][j]<< "\t";
        }
        cout<< "\n";
    }
    cout << "\n\n\n";

    for (i=0;i<=n-1;i++){
        for (j=0;j<=n-1;j++){
            cout<< Valueofk[i][j]<< "\t";
        }
        cout<< "\n";
    }

    cout << "\n\nThe optimal number of calculations required to obtain the result matrix is " << A[0][n-1] << "\n\n";
    PrintCombination(Valueofk,0,n-1);
    return 0;
}
