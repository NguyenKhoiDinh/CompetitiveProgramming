#include <bits/stdc++.h>

using namespace std;
string convert(int v) {
  string res = ""; 
  while (v > 0) {
    int r = v % 10; 
    res += (char) (r + '0');
    v /= 10; 
  }
  reverse(res.begin(), res.end());
  return res;
}

int main () {
  int n;
  cin >> n;
  string s = ""; 
  for (int i = 1; i <= n; i++) {
    s += convert(i);
  }
  string nn = convert(n);
  for (int i = 0; i < (int) s.size(); i++) {
    bool flag = true; 
    for (int j = 0; j < (int) nn.size(); j++) {
      if (nn[j] != s[i + j]) {
        flag = false; 
      }
    }
    if (flag == true) {
      cout << i + 1;
      return 0; 
    }
  }
  return 0; 
}