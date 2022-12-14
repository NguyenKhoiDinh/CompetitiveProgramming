#include <bits/stdc++.h>
using namespace std;
 
long long a, b, c, d;
#define MOD 111539786
 
// Function calculate the N-th fibanacci
// number using fast doubling method
void FastDoubling(int n, long long res[])
{
    // Base Condition
    if (n == 0) {
        res[0] = 0;
        res[1] = 1;
        return;
    }
    FastDoubling((n / 2), res);
 
    // Here a = F(n)
    a = res[0];
 
    // Here b = F(n+1)
    b = res[1];
 
    c = 2 * b - a;
 
    if (c < 0)
        c += MOD;
 
    // As F(2n) = F(n)[2F(n+1) – F(n)]
    // Here c  = F(2n)
    c = (a * c) % MOD;
 
    // As F(2n + 1) = F(n)^2 + F(n+1)^2
    // Here d = F(2n + 1)
    d = (a * a + b * b) % MOD;
 
    // Check if N is odd
    // or even
    if (n % 2 == 0) {
        res[0] = c;
        res[1] = d;
    }
    else {
        res[0] = d;
        res[1] = c + d;
    }
}
 
// Driver code
int main()
{
    int numTest;
    cin >> numTest;
    while (numTest--) {
long long res[2] = { 0 };
    int N;
    cin >> N;
    FastDoubling(N + 1, res);
 
    cout << res[0] << "\n";
    
    }
    return 0;
}