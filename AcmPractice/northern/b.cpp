#include <bits/stdc++.h> 

using namespace std;
int n; 
int a[100005]; 
map <int, int> cntPos, cntNeg; 

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > 0) {
      cntPos[a[i]]++;
    }
    else {
      cntNeg[a[i]]++; 
    }
  }
  for (int i = 1; i <= n; i++) {
    int v = abs(a[i]);
    int revv = -v; 
    if ((cntPos[v] + cntNeg[revv]) % 2 == 1) {
      if (cntPos[v] < cntNeg[revv]) {
        cout << v; 
      }
      else {
        cout << revv;
      }
      return 0; 
    }
  }
  return 0;
}