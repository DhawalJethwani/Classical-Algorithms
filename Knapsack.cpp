#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <stdio.h>
using namespace std;
int knapSack(int W, vector<int>& wt, vector<int>& cost, int n)
{
   vector< vector<int> > dp(n+1,vector<int>(W+1,0)),selection(n+1,vector<int>(W+1,-1));
   for (int i = 1; i <= n; i++)
   {
       for (int w = 1; w <= W; w++)
       {
            if (wt[i-1] <= w)
			{
                if( dp[i-1][w] < cost[i-1] + dp[i-1][w-wt[i-1]] )
					selection[i][w]=i-1;
                else
					selection[i][w]=-1;
				dp[i][w] = max( cost[i-1] + dp[i-1][w-wt[i-1]] , dp[i-1][w] );
			}
            else
			{
				dp[i][w] = dp[i-1][w];
				selection[i][w]=-1;
		    }
       }
   }
   int E=W;
   vector<int> path;
   for(int i=n;i>0;i--)
   {
	   if(selection[i][E]!=-1)
	   {
		   path.push_back(i-1);
		   E-=wt[i-1];
	   }
   }
   cout <<"Selections : " << path.size() << ", described below "<<endl;
   printf("%3s%9s%9s\n","ID","Size","Cost");
   for(int i=0;i<path.size();i++)
   {
	   printf("%3d%9d%9d\n",path[i]+1,wt[path[i]], cost[path[i]]) ;
   }
   cout <<"Knapsack free after optimal allocation : " << E << endl ;
   return dp[n][W];
}

int main()
{
	cout << "Enter the knapsack size and number of elements:\n";
	int N,C;
	scanf("%d%d",&C,&N);
	vector<int> cost(N),wt(N);
	for(int i =0;i< N ;i++)
	{
		cout << "Enter size and cost of item number " << i + 1 << ":" << endl ;
		scanf("%d%d",&wt[i],&cost[i]);
	}
	cout << "-------- Recognised Input ------------------"<<endl;
	cout << "Knapsack Capacity = " << C << endl;
	cout << "Number of items = " << N << endl;
	printf("%3s%9s%9s\n","ID","Size","Cost");
    for(int i=0;i<N;i++)
    {
        printf("%3d%9d%9d\n",i+1,wt[i], cost[i]) ;
    }
    cout <<"--------------- Processing... -----------------" << endl;
    time_t T=clock();
    printf("Solution Cost =%5d units\n",knapSack(C,wt,cost,N));
	cout <<"Effective time = " << (clock()-T) <<" ms"<<endl;
    return 0;
}
