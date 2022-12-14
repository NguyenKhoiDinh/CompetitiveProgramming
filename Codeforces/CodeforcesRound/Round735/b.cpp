#include <bits/stdc++.h> 

using namespace std;
int a[300005]; 
int n;
int k; 
int numTest;

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int lim = max(1, n - 1000);
    long long res = -10000000000000007LL; 
    for (int i = lim; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        res = max(res, 1LL * i * j - 1LL * k * (a[i] | a[j]));  
      }
    } 
    cout << res << endl;
  }
  return 0;
}