#include <bits/stdc++.h> 

using namespace std;
int numTest;
long long n; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    long long x = n << 30LL;
    long long y = x + n;
    cout << x << ' ' << y << endl;    
  }
  return 0; 
}