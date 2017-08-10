#include <time.h>
#include <stdio.h>
#include <math.h>
#include <iostream>


using namespace std;

void algo_log(long long n)
{
    clock_t tStart = clock();
    for(int i=0;i<log2(n);i++);
    printf("This algorithm(O(log(n)) took %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}

void algo_n(long long n)
{
    clock_t tStart = clock();
    for(int i=0;i<n;i++);
    printf("This algorithm(O(n)) took %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}

void algo_nlog(long long n)
{
    clock_t tStart = clock();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<log2(n);j++);
    }
    printf("This algorithm(O(n*log(n))) took %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}

void algo_nsq(long long int n)
{
    clock_t tStart = clock();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++);
    }
    printf("This algorithm(O(n^2)) took %.10fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}

int main()
{
    long long int n;
    int k;
    while(1)
    {
        cout << "Enter the value of N" << endl;
        cin >> n;
        cout << "Enter the number corresponding to the algorithm to be executed" << endl;
        cin >> k;
        if(k==1)
        {
            algo_log(n);
        }
        else if(k==2)
        {
            algo_n(n);
        }
        else if(k==3)
        {
            algo_nlog(n);
        }
        else if(k==4)
        {
            algo_nsq(n);
        }
        else if(k==5)
        {
            break;
        }
        else
        {
            cout << "Invalid";
        }
    }
    return 0;
}
