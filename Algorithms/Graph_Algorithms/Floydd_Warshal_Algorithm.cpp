/*
Problem Statement:
The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph. 
*/

#include <bits/stdc++.h>
using namespace std;

#define Z 99999
#define N 4

/*
Time Complexity  : O(n^3)
Space Complexity : O(n*n)
*/

void printMatrix(int dp[][N])
{
    for(int i=0 ; i<N ; i++)
    {
        for(int j=0 ; j<N ; j++)
        {
            if(dp[i][j] == Z)
                cout<<"INF  ";
            else
                cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void floydWarshallDP(int graph[][N])
{
    int dp[N][N];

    //initializing the dp table or
    //matrix with the given graph values.
    for(int i=0 ; i<N ; i++)
        for(int j=0 ; j<N ; j++)
            dp[i][j] = graph[i][j];

    //for creating k-graphs
    for(int k=0 ; k<N ; k++)
        //generating the matrix with two 2 loops
        for(int i=0 ; i<N ; i++)
            for(int j=0 ; j<N ; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

    cout<<"The shortest distance matrix formed is : "<<endl;
    printMatrix(dp);
}


int main()
{
    int graph[N][N] =
    {
        { 0, 3, Z, 7 },
        { 8, 0, 2, Z },
        { 5, Z, 0, 1 },
        { 2, Z, Z, 0 }
    };

    floydWarshallDP(graph);

    return 0;
}
