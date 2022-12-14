#include <bits/stdc++.h> 

using namespace std;
long long dp[16][140][140][3];
string N; 
bool isPrime[140]; 

void erathones() {
  for (int i = 2; i < 140; i++) {
    isPrime[i] = true; 
  }  
  for (int i = 2; i < 140; i++) {
    if (isPrime[i] == true) {
      for (int j = i + i; j < 140; j += i) {
        isPrime[j] = false; 
      }
    }
  }
}

int main () {
  erathones();
  cin >> N;
  int len = (int) N.size();
  dp[0][0][0][0] = 1; 
  for (int i = 0; i < len; i++) {
    for (int sumx = 0; sumx <= 9 * 15; sumx++) {
      for (int sumy = 0; sumy <= 9 * 15; sumy++) {
        for (int rem = 0; rem <= 2; rem++) {
          if (dp[i][sumx][sumy][rem] == 0) {
            continue; 
          }
          for (int nextRem = 0; nextRem <= 2; nextRem++) {
            for (int y = 0; y <= 9; y++) {
              int x = N[i] - '0' + rem * 10 - 2 * y - nextRem;
              if (0 <= x && x <= 9) {
                dp[i + 1][sumx + x][sumy + y][nextRem] += dp[i][sumx][sumy][rem];   
              }  
            }
          }
        }
      }
    }
  }
  long long ans = 0LL;
  for (int sumx = 2; sumx < 140; sumx++) {
    for (int sumy = 2; sumy < 140; sumy++) {
      if (isPrime[sumx] == true && isPrime[sumy] == true) {
        ans += dp[len][sumx][sumy][0];  
      }
    }
  }
  cout << ans;
  return 0;
}


//x + 2 * y + nextRem - 20 = N[i] - '0'