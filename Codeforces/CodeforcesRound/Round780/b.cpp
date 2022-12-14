#include <bits/stdc++.h> 

using namespace std;
int n, numTest, a[200005];  

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }
    sort(a + 1, a + n + 1); 
    if (n == 1) {
      cout << (a[1] == 1 ? "YES" : "NO") << endl; 
      continue; 
    }
    if (a[n] - a[n - 1] > 1) {
      cout << "NO" << endl; 
    }
    else {
      cout << "YES" << endl;
    }
  }
  return 0; 
}