#include <bits/stdc++.h> 

using namespace std;
int numTest;
string s; 
int n, A, B; 
struct element {
  int numbRed, rA, rB; 
};
int dp[42][42][42][42];
element trace[42][42][42][42];

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> A >> B;
    cin >> s;          
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n; i++) {
      for (int numbRed = 0; numbRed <= n; numbRed++) {
        for (int rA = 0; rA < A; rA++) {
          for (int rB = 0; rB < B; rB++) {
            trace[i][numbRed][rA][rB] = (element) {-1, -1, -1}; 
          }
        }
      }
    }
    dp[0][0][0][0] = 1; 
    for (int i = 0; i < n; i++) {
      for (int numbRed = 0; numbRed <= i; numbRed++) {
        for (int rA = 0; rA < A; rA++) {
          for (int rB = 0; rB < B; rB++) {
            if (dp[i][numbRed][rA][rB] == 0) {
              continue; 
            }
            dp[i + 1][numbRed + 1][(rA * 10 + s[i] - '0') % A][rB] = 1;
            trace[i + 1][numbRed + 1][(rA * 10 + s[i] - '0') % A][rB] = (element) {numbRed, rA, rB}; 
            dp[i + 1][numbRed][rA][(rB * 10 + s[i] - '0') % B] = 1;
            trace[i + 1][numbRed][rA][(rB * 10 + s[i] - '0') % B] = (element) {numbRed, rA, rB}; 
          }
        }
      }
    }
    int ansRed = -1, ansBlack = -1; 
    int ans = 10000; 
    for (int r = 1; r < n; r++) {
      int b = n - r; 
      if (dp[n][r][0][0] == 1) {
        if (ans > abs(r - b)) {
          ansRed = r;
          ansBlack = b;
          ans = abs(r - b); 
        }
      }
    }
    if (ansRed == -1 && ansBlack == -1) {
      cout << -1 << endl; 
    }
    else {
      string ret = "";
      int i = n;
      int numbRed = ansRed;
      int rA = 0;
      int rB = 0; 
      while (i > 0) {
        element e = trace[i][numbRed][rA][rB];
        if (e.numbRed == numbRed) {
          ret += 'B';
        }
        else {
          ret += 'R'; 
        }
        i--;
        numbRed = e.numbRed;
        rA = e.rA;
        rB = e.rB; 
      }
      reverse(ret.begin(), ret.end());
      cout << ret << endl; 
    }
  }   
  return 0; 
}