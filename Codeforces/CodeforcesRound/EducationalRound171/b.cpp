#include <bits/stdc++.h>

using namespace std;
int n;
long long a[2005]; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }
    a[0] = -1;
    a[n + 1] = 1000000000000000001LL;
    if (n % 2 == 0) {
      long long ans = 0;
      for (int i = 1; i <= n; i += 2) {
        ans = max(ans, a[i + 1] - a[i]); 
      }
      cout << ans << endl; 
    }
    else {
      long long ans = 1000000000000000007LL; 
      for (int i = 1; i <= n; i += 2) {
        long long maxDiff = 0;
        for (int j = i - 1; j >= 2; j -= 2) {
          maxDiff = max(maxDiff, a[j] - a[j - 1]); 
        }  
        for (int j = i + 1; j <= n; j += 2) {
          maxDiff = max(maxDiff, a[j + 1] - a[j]); 
        }
        int j = i - 1; 
        while (j >= 1 && a[j] + 1 == a[j + 1]) {
          j--; 
        }
        j++;
        long long minDiff = a[i] - (a[j] - 1);     
        j = i + 1;
        while (j <= n && a[j] - 1 == a[j - 1]) {
          j++; 
        }
        j--;
        minDiff = min(minDiff, (a[j] + 1) - a[i]); 
        maxDiff = max(maxDiff, minDiff);
        ans = min(ans, maxDiff); 
      }                                 
      cout << ans << endl; 
    }
  }
  return 0; 
}