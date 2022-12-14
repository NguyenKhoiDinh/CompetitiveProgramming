#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 82; 
int dp[MAX_N][MAX_N][22][22];
int numTest;  

int changeToInt(const string &s) {
  int ret = 0; 
  for (int i = 0; i < (int) s.size(); i++) {
    ret = ret * 10 + s[i] - '0';
  }
  return ret; 
}

void dynamicProgramming() {
  dp[0][0][0][0] = 1; 
  for (int score1 = 0; score1 <= 80; score1++) {
    for (int score2 = 0; score2 <= 80; score2++) {
      for (int win1 = 0; win1 <= 20; win1++) {
        for (int win2 = 0; win2 <= 20; win2++) {
          if (dp[score1][score2][win1][win2] == 0) {
            continue; 
          }
          if (win1 < 20) {
            if (score1 + 4 <= 80) {
              dp[score1 + 4][score2][win1 + 1][win2] = 1; 
              if (score2 + 1 <= 80) {
                dp[score1 + 4][score2 + 1][win1 + 1][win2] = 1; 
              }
            }
            for (int newScore = 4; score1 + newScore <= 80 && score2 + newScore - 2 <= 80; newScore++) {
              dp[score1 + newScore][score2 + newScore - 2][win1 + 1][win2] = 1; 
            }
          }
          if (win2 < 20) {
            if (score2 + 4 <= 80) {
              dp[score1][score2 + 4][win1][win2 + 1] = 1; 
              if (score1 + 1 <= 80) {
                dp[score1 + 1][score2 + 4][win1][win2 + 1] = 1; 
              }
            }
            for (int newScore = 4; score2 + newScore <= 80 && score1 + newScore - 2 <= 80; newScore++) {
              dp[score1 + newScore - 2][score2 + newScore][win1][win2 + 1] = 1; 
            }
          }
        }
      }
    }
  }
}

int main () {
  dynamicProgramming();
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    string s;
    cin >> s; 
    s += '-'; 
    string ss = ""; 
    int L = -1, R = -1; 
    for (int i = 0; i < (int) s.size(); i++) {
      if (s[i] == '-') {
        if (L == -1) {
          L = changeToInt(ss); 
        }  
        else {
          R = changeToInt(ss); 
        }
        ss = ""; 
      }
      else {
        ss += s[i]; 
      }
    }
    bool valid = false; 
    for (int win2 = 0; win2 <= 4; win2++) {
      if (dp[L][R][6][win2] == 1) {
        valid = true;
        break; 
      }
    }
    for (int win1 = 7; win1 <= 20; win1++) {
      if (dp[L][R][win1][win1 - 2] == 1) {
        valid = true;
        break; 
      }
    }
    cout << (valid == true ? "YES" : "NO") << endl;
  }
  return 0;
}