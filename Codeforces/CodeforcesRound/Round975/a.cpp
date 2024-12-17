#include <bits/stdc++.h>

using namespace std;
int n;
int a[1005]; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    int ans = 0; 
    int maxValue = -1; 
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }    
    int numb = 0; 
    for (int i = 1; i <= n; i += 2) {
      maxValue = max(maxValue, a[i]); 
      numb++; 
    }
    ans = maxValue + numb;
    maxValue = -1; 
    numb = 0; 
    for (int i = 2; i <= n; i += 2) {
      maxValue = max(maxValue, a[i]); 
      numb++; 
    }
    ans = max(ans, maxValue + numb); 
    cout << ans << endl;
  }
  return 0; 
}