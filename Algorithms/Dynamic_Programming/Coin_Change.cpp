/*
Problem Statement:
-----------------
iven a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? 
The order of coins doesn’t matter.
For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. 
For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.
*/

#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(n*w), n is number of coins and w is sum to be paid
//Space Complexity : O(n*sum)
int findChanges(int changes[] , int sum , int n)
{
    int dp[n+1][sum+1] = {0};

    for(int i=0 ; i<= n ; i++)
    {
        for(int j=0 ; j<=sum ; j++)
        {
            //amount to be paid is 0
            if(j == 0)
                dp[i][j] = 0;
            //if number of coins is 0
            else if(i == 0)
                dp[i][j] = INT_MAX;
            //if the current coin is larger than amount
            //Exclude the denomination case
            else if(changes[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = min(dp[i-1][j] , 1 + dp[i][j - changes[i-1]]);
        }
    }
    return dp[n][sum];
}

int main()
{
    int n;
    cout<<"Enter total number of different coins : ";
    cin>>n;

    int sum;
    cout<<"Enter the sum : ";
    cin>>sum;

    int changes[n];
    cout<<"Enter the coins : "<<endl;
    for(int i=0 ; i<n ; i++)
        cin>>changes[i];

    cout<<"Minimum number of coins to pay "<<sum<<" is : "<<findChanges(changes , sum , n);

    return 0;
}

