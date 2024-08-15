#include <bits/stdc++.h>

using namespace std;
int n; 
int a[200005]; 

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    priority_queue <long long> pqOdd;
    multiset <long long> S; 
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; 
      if (a[i] % 2 == 0) {
        S.insert(a[i]);  
      }
      else {
        pqOdd.push(a[i]); 
      }
    }
    if (pqOdd.empty() == true || S.empty() == true) {
      cout << 0 << endl; 
      continue; 
    }
    int ans = 0; 
    while (S.empty() == false) {
      long long topOdd = pqOdd.top(); 
      multiset <long long>::iterator it = S.lower_bound(topOdd); 
      if (it == S.begin()) {
        ans += 1 + (int) S.size(); 
        break; 
      }
      it--; 
      ans++; 
      long long value = *it; 
      S.erase(it);        
      topOdd += value; 
      pqOdd.push(topOdd); 
    }
    cout << ans << endl;
  }
  return 0; 
}