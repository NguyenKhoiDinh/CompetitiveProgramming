#include <bits/stdc++.h> 

using namespace std;
long long x = -1; 
int n;
int numTest;
long long a[100005];

int main () {                        
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    x = -1;
    for (int i = 1; i <= n; i++) {
      long long value;
      cin >> value;
      a[i] = value;     
    }                     
    for (int i = 1; i < n; i++) {
      x = max(x, a[i] * a[i + 1]);
    }
    cout << x << endl;
  }
  return 0;
}