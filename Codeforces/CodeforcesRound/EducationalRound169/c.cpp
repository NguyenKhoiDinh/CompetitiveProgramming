#include <bits/stdc++.h>

using namespace std;
int n, k;
int a[200005]; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
    }    
    sort(a + 1, a + n + 1); 
    bool alice = true; 
    long long sumA = 0, sumB = 0; 
    int last = a[n]; 
    for (int i = n; i >= 1; i--) {
      if (alice == true) {
        last = a[i]; 
        sumA += a[i]; 
        alice = !alice; 
        continue; 
      }
      int add = min(k, last - a[i]);
      a[i] += add;
      last = a[i];
      k -= add;
      sumB += a[i];
      alice = !alice;    
    }
    cout << sumA - sumB << endl; 
  }
  return 0; 
}