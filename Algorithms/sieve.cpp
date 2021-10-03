#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int lli;

lli i, j, k, lim = 20000000;

vector<bool> isprime(20000000, true);
vector<bool> v;

void primes() {
  for (i = 2; i < lim; i++)
    if (isprime[i])
      for (j = i*i; j < lim; j += i)
        isprime[j] = false;
}

int main() {
  primes();

  int n;

  cout << "Type a number to check if it is a prime number" << endl;
  cin >> n;

  if (isprime[n])
    cout << n << " is a prime number" << endl;
  else
    cout << n << " is not a prime number" << endl;
}
