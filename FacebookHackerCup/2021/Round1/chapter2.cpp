#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 800005; 
const long long MOD = 1000000007;
int numTest;
string s;
int n;             

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    cin >> n;
    cin >> s;
    int ans = 0;
    int side = -1; 
    int pos = 0; 
    int lastPos0 = -1, lastPos1 = -1;
    int sum0 = 0, sum1 = 0; 
    if (s[0] == 'O') {
      side = 0;
      lastPos0 = 0;  
    }
    else if (s[0] == 'X') {
      side = 1; 
      lastPos1 = 0; 
    }
    else {
      for (int i = 0; i < n; i++) {
        if (s[i] != 'F') {
          side = (s[i] == 'X');
          pos = i; 
          if (s[i] == 'X') {
            lastPos1 = i;
          }
          else {
            lastPos0 = i; 
          }
          break; 
        }
      }
    }
    if (side == -1) {
      cout << 0 << endl;
      continue; 
    }                    
    for (int i = max(lastPos0, lastPos1) + 1; i < n; i++) {
      if (s[i] == 'X') {
        side = 1; 
        lastPos1 = i; 
      }
      else if (s[i] == 'O') {
        side = 0;
        lastPos0 = i;  
      }
      if (side == 1) {
        sum1 = (sum0 + lastPos0 + 1) % MOD;
        (ans += sum1) %= MOD;
      }
      else {
        sum0 = (sum1 + lastPos1 + 1) % MOD;
        (ans += sum0) %= MOD;
      }
    } 
    cout << ans << endl;
  }
  return 0; 
}