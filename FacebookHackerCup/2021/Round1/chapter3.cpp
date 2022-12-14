#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 800005; 
const long long MOD = 1000000007;
int numTest;
string s;
int n;             

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    cin >> n;
    cin >> s;
    long long ans = 0LL;
    long long lastPos0 = 0, lastPos1 = 0, count0 = 0, count1 = 0;
    long long sum0 = 0, sum1 = 0;
    long long len = 0; 
    int side = -1; 
    int type = -1; 
    long long countFirst = 0LL; 
    for (int i = 1; i <= n; i++) {
      if (s[i - 1] == 'F') {
        len++;
        if (side == 0) {
          count0++;
          count0 %= MOD; 
          if (lastPos1 != 0) {
            sum0 = (sum1 + lastPos1) % MOD; 
            (ans += sum0) %= MOD; 
          }  
        }
        else if (side == 1) {
          count1++;
          count1 %= MOD;
          if (lastPos0 != 0) {
            sum1 = (sum0 + lastPos0) % MOD; 
            (ans += sum1) %= MOD;
          }
        }
      }
      else if (s[i - 1] == 'X') {
        if (type == -1) {
          if (lastPos0 != 0) {
            type = 0; 
            countFirst = i - 1;
          } 
        }
        count1++;
        count1 %= MOD;
        len++; 
        lastPos1 = len;
        side = 1; 
        if (lastPos0 != 0) {
          sum1 = (sum0 + lastPos0) % MOD;
          (ans += sum1) %= MOD;
        }
      }
      else if (s[i - 1] == 'O') {
        if (type == -1) {
          if (lastPos1 != 0) {
            type = 1;
            countFirst = i - 1;
          }
        }
        count0++;
        count0 %= MOD;
        len++;
        lastPos0 = len;
        side = 0;   
        if (lastPos1 != 0) {
          sum0 = (sum1 + lastPos1) % MOD;
          (ans += sum0) %= MOD; 
        }
      }
      else {
        if (lastPos0 != 0 && lastPos1 != 0) {
          (sum0 *= 2LL) %= MOD;
          (sum1 *= 2LL) %= MOD;
          if (type == 0) {
            (sum0 += (countFirst * lastPos1) % MOD) %= MOD;
            (sum0 += ((count0 - countFirst + MOD) % MOD * len) % MOD) %= MOD;   
          }
          else {
            (sum1 += (countFirst * lastPos0) % MOD) %= MOD;
            (sum1 += ((count1 - countFirst + MOD) % MOD * len) % MOD) %= MOD;
          }
          (ans += sum0) %= MOD;
          (ans += sum1) %= MOD;
        }  
        if (lastPos0 != 0) {
          (lastPos0 += len) %= MOD;
        }
        if (lastPos1 != 0) {
          (lastPos1 += len) %= MOD;
        }
        (len *= 2LL) %= MOD;
      }
    }
    cout << ans << endl;
  }
  return 0; 
}