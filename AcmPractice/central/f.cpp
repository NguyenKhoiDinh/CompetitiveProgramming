#include <bits/stdc++.h> 

using namespace std;
int numTest; 
string s; 

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> s;
    long long ans = 0LL;
    int n = (int) s.size(); 
    for (int c = 0; c < 26; c++) {
      string st = "";
      st += (char) (c + 'a'); 
      st += s; 
      st += (char) (c + 'a');
      int prevPos = 0;
      int prevLen = 0;  
      for (int i = 1; i <= n + 1; i++) {
        if (st[i] == (char) (c + 'a')) {
          int pos = i; 
          int len = pos - prevPos; 
          ans += 1LL * len * prevLen; 
          prevLen = len;
          prevPos = pos;  
        }
      }                                     
    }    
    cout << ans << endl; 
  }
  return 0; 
}