#include <bits/stdc++.h>

using namespace std;
bool isPrime[400005];
int smallestPrime[400005];  
void erathones() {
  for (int i = 2; i <= 400000; i++) {
    isPrime[i] = true;    
  }
  for (int i = 2; i <= 400000; i++) {
    if (isPrime[i] == false) {
      continue; 
    }
    smallestPrime[i] = i; 
    for (int j = 2 * i; j <= 400000; j += i) {
      isPrime[j] = false;
      if (smallestPrime[j] == 0) {
        smallestPrime[j] = i; 
      } 
    }
  }
}
set <int> myset; 
int n; 
int a[100005]; 

int main () {
  erathones(); 
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    myset.clear();
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (isPrime[a[i]] == true) {
        myset.insert(a[i]); 
      } 
    }
    if ((int) myset.size() > 1) {
      cout << -1 << endl; 
      continue; 
    }
    if (myset.empty() == true) {
      cout << 2 << endl; 
      continue;
    }
    sort(a + 1, a + n + 1); 
    bool ok = true; 
    for (int i = 2; i <= n; i++) {
      if (a[i] % 2 == 0 && a[i] < 2 * a[1]) {
        ok = false;
        break; 
      }
      if (a[i] % 2 == 1 && a[i] - smallestPrime[a[i]] < 2 * a[1]) {
        ok = false;
        break; 
      }
    }
    cout << (ok == true ? a[1] : -1) << endl; 
  }
  return 0; 
}