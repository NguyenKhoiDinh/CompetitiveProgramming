#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 17005; 
int numTest; 
int n, k; 
int a[MAX_N];

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    deque <int> dq;
    for (int i = 1; i <= k; i++) {
      while (!dq.empty() && a[i] < dq.back()) {
        dq.pop_back();
      }
      dq.push_back(a[i]);
    }
    cout << dq.front() << ' '; 
    for (int i = k + 1; i <= n; i++) {
      if (dq.front() == a[i - k]) {
        dq.pop_front(); 
      }
      while (!dq.empty() && a[i] < dq.back()) {
        dq.pop_back();
      }
      dq.push_back(a[i]); 
      cout << dq.front() << ' ';
    }
    cout << endl; 
  }
  return 0; 
}