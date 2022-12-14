#include <bits/stdc++.h> 

using namespace std;
const long long BASE = 123456789LL;
const int MAX_N = 100005; 
string A, B; 
int cnt; 
long long pw[MAX_N]; 
long long hashA[MAX_N], hashB[MAX_N];
int n, m;

bool check(int len, long long value) {
  int numb = 0; 
  for (int i = len; i <= n; i++) {
    long long hash = (hashA[i] - hashA[i - len]) * pw[n - i];
    if (value == hash) {
      numb++;
    }
  }
  return (numb >= cnt);
}

int main () {
  pw[0] = 1LL;
  for (int i = 1; i < MAX_N; i++) {
    pw[i] = pw[i - 1] * BASE;
  }
  getline(cin, A);
  getline(cin, B);
  cin >> cnt;
  n = (int) A.size();
  m = (int) B.size();
  hashA[0] = 0LL;
  for (int i = 1; i <= n; i++) {
    hashA[i] = hashA[i - 1] + A[i - 1] * pw[i - 1]; 
  }
  hashB[0] = 0LL;
  for (int i = 1; i <= m; i++) {
    hashB[i] = hashB[i - 1] + B[i - 1] * pw[i - 1];
  }
  int ans = -1; 
  int l = 1; 
  int r = m;
  while (l <= r) {
    int mid = (l + r) >> 1;
    long long value = hashB[mid] * pw[n - mid];
    int len = mid;
    bool found = check(len, value);
    if (found == true) {
      ans = len; 
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  if (ans == -1) {
    cout << "IMPOSSIBLE";
  }
  else {
    for (int i = 0; i < ans; i++) {
      cout << B[i]; 
    }
  }
  return 0; 
}