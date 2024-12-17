#include <bits/stdc++.h>

using namespace std;

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    string s, r;
    cin >> n >> s >> r;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        cnt0++; 
      }
      else {
        cnt1++; 
      }
    }   
    bool ans = true; 
    for (int i = 0; i < (int) r.size(); i++) {
      if (cnt0 > 0 && cnt1 > 0) {
        cnt0--;
        cnt1--;
        if (r[i] == '0') {
          cnt0++; 
        }  
        else {
          cnt1++;
        }
      }
      else {
        ans = false;
        break; 
      }
    }
    cout << (ans == true ? "YES" : "NO") << endl;
  }
  return 0; 
}