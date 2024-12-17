#include <bits/stdc++.h>

using namespace std;
int cnt[1005]; 
int n; 
int a[1005]; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    memset(cnt, 0, sizeof(cnt)); 
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
      cnt[a[i]]++; 
    }
    int numb1 = 0, numb2 = 0;
    for (int i = 1; i <= n; i++) {
      if (cnt[i] == 1) {
        numb1++;
      }
      else if (cnt[i] > 1) {
        numb2++; 
      }
    }
    int ans = 2 * ((numb1 + 1) / 2) + numb2;
    cout << ans << endl; 
  }
  return 0; 
}