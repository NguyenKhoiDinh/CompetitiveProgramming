#include <bits/stdc++.h>
using namespace std;
int pos0[2], pos1[2];
string s;
int numTest;

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> s;
    int n = (int) s.size();
    for (int c = 0; c <= 1; c++) {
      pos0[c] = -1;
      pos1[c] = -1;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        int maxPos = max(pos0[1 - i % 2], pos1[i % 2]);
        ans += i - maxPos;
      }
      else if (s[i] == '1') {
        int maxPos = max(pos0[i % 2], pos1[1 - i % 2]);
        ans += i - maxPos;
      }
      else {
        int maxPos1 = max(pos0[1 - i % 2], pos1[i % 2]);
        int maxPos2 = max(pos0[i % 2], pos1[1 - i % 2]);
        ans += i - min(maxPos1, maxPos2);
      }
      if (s[i] == '0') {
        pos0[i % 2] = i;
      }
      else if (s[i] == '1') {
        pos1[i % 2] = i;
      }
    }
    cout << ans << endl;
  }
  return 0;
}