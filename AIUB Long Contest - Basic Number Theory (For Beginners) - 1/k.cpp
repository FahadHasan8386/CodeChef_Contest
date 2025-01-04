#include<bits/stdc++.h>
using namespace std;

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mx = 1e8;
bitset<mx> isPrime;
vector<int> primes;

void primeGen ( int n )
{
    isPrime[2] = 1;
    for ( int i = 3; i <= n; i += 2 ) isPrime[i] = 1;

    int sq = sqrt(n);
    for ( int i = 3; i <= sq; i += 2 ) {
        if(isPrime[i]) {
            for ( int j = i*i; j <= n; j += i ) {
                isPrime[j] = 0;
            }
        }
    }

    primes.push_back(2);

    for ( int i = 3; i <= n; i += 2 ) {
        if(isPrime[i] == 1) {
            primes.push_back(i);
        }
    }
}

int main()
{

    optimize();
    int lim = 1e8;

    primeGen(lim);

    for(int i = 0; i < primes.size(); i = i + 100)
    {
        cout << primes[i] << "\n";
    }
}
