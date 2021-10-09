/*
Problem Statement:
-----------------
Sort a large set of floating point numbers which are in range from 0.0 to 1.0 and are uniformly distributed across the range.
*/

#include <bits/stdc++.h>
using namespace std;

void bin_sort(float a[], int n)
{
    int i, j;
    //creating buckets
    vector<float> b[n];

    //putting array elements into their respective buckets.
    for (i = 0; i < n; i++)
    {
        int bi = n * a[i]; //index in bucket (important step)
        b[bi].push_back(a[i]);
    }

    //sorting the individual buckets
    for (i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

    //concatenating all the buckets into the array
    int index = 0;
    for (i = 0; i < n; i++)               //traversing buckets
        for (j = 0; j < b[i].size(); j++) //traversing individual bucket
            a[index++] = b[i][j];
}

int main()
{
    int n, i;

    cout << "Enter number of elements of array : ";
    cin >> n;

    float a[n];

    cout << "Enter elements of array : " << endl;
    for (i = 0; i < n; i++)
        cin >> a[i];

    bin_sort(a, n);

    cout << "\n\nSorted array is : " << endl;
    for (i = 0; i < n; i++)
        cout << a[i] << "  ";

    return 0;
}

/*
Sample Input-Output:
-------------------
Enter number of elements of array : 5
Enter elements of array : 
0.897
0.565
0.656
0.1234
0.665


Sorted array is :
0.1234  0.565  0.656  0.665  0.897
*/
