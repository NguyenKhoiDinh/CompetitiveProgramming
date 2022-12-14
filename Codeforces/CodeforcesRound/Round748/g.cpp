#include <bits/stdc++.h> 

using namespace std;
int numTest;
int sum[1000005];
string s;
int n;
int query; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> s;
    n = (int) s.size();
    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1];
      if (s[i - 1] == '[' || s[i - 1] == ']') {
        if (i % 2 == 0) {
          sum[i]++;
        }
        else {
          sum[i]--;
        }
      }
    }
    cin >> query;
    for (int i = 1; i <= query; i++) {
      int l, r;
      cin >> l >> r;
      cout << abs(sum[r] - sum[l - 1]) << endl;
    }
  }
  return 0; 
}