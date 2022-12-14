#include <bits/stdc++.h> 

using namespace std;
const int LIM = 2000000;

int pos[25][2]; 
double dp[LIM + 5][25][2]; 
double prob[LIM + 5][25][2]; 
int numTest; 

void createLastPos(const string &s) {
  memset(pos, 0, sizeof(pos)); 
  if (s[0] == '0') {
    pos[0][0] = 1;
    pos[0][1] = 0; 
  }
  else {
    pos[0][1] = 1; 
    pos[0][0] = 0; 
  }
  int n = (int) s.size();
  string st = "";
  for (int i = 1; i < n; i++) {
    st += s[i - 1]; 
    for (int c = 0; c <= 1; c++) {
      string tmp = st;
      tmp += (char) (c + '0');
      for (int j = i + 1; j >= 1; j--) {
        if (c == s[j - 1] - '0') {
          int p = i + 1;
          int q = j; 
          while (q > 0) {
            if (s[q - 1] != tmp[p - 1]) {
              break;
            }
            p--;
            q--;
          }
          if (q == 0) {
            pos[i][c] = j;
            break;
          }
        }
      }
    }
  }
}

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    string s; 
    cin >> s; 
    createLastPos(s);  
    int len = (int) s.size(); 
    memset(dp, 0.0, sizeof(dp));
    memset(prob, 0.0, sizeof(prob)); 
    prob[0][0][0] = 1.0; 
    for (int i = 0; i < LIM; i++) {
      for (int lastPos = 0; lastPos <= len - 1; lastPos++) {
        for (int bit = 0; bit <= 1; bit++) {
          int nextPos = pos[lastPos][bit]; 
          int found = 0;
          if (nextPos == len) {
            found = 1; 
          }                                                                               
          prob[i + 1][nextPos][found] += prob[i][lastPos][0] * 0.5; 
          dp[i + 1][nextPos][found] += (dp[i][lastPos][0] + prob[i][lastPos][0]) / 2;
        }
      }   
    }
    double ans = 0.0; 
    for (int i = 1; i <= LIM; i++) {
      ans += prob[i][len][1] * i; 
    } 
    cout << fixed << setprecision(12) << ans << endl;
  }
  return 0;
}