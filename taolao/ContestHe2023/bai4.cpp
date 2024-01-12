#include <iostream>
#include <math.h> 
const long long inf = -1000000000007LL; 
long long dp[300005][3][3]; 
long long a[300005]; 
int n;
long long k;  

void update(long long &a, long long b) {
  a = std::max(a, b); 
}

int main () {
  std::cin >> n >> k; 
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  }
  for (int i = 0; i <= n; i++) {
    for (int state = 0; state <= 2; state++) {
      for (int stateSum = 0; stateSum <= 2; stateSum++) {
        dp[i][state][stateSum] = inf; 
      } 
    }
  }
  dp[0][0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int state = 0; state <= 2; state++) {
      for (int stateSum = 0; stateSum <= 2; stateSum++) {
        if (dp[i][state][stateSum] == inf) {
          continue; 
        }
        if (state == 0) {
          if (stateSum == 0) {
            update(dp[i + 1][0][0], dp[i][state][stateSum]);
            update(dp[i + 1][1][0], dp[i][state][stateSum]);
            update(dp[i + 1][0][1], dp[i][state][stateSum] + a[i + 1]);
            update(dp[i + 1][1][1], dp[i][state][stateSum] + k * a[i + 1]);
          }
          else if (stateSum == 1) {
            update(dp[i + 1][0][1], dp[i][state][stateSum] + a[i + 1]); 
            update(dp[i + 1][1][1], dp[i][state][stateSum] + k * a[i + 1]); 
            update(dp[i + 1][0][2], dp[i][state][stateSum]); 
            update(dp[i + 1][1][2], dp[i][state][stateSum]); 
          }   
          else {
            update(dp[i + 1][0][2], dp[i][state][stateSum]); 
            update(dp[i + 1][1][2], dp[i][state][stateSum]); 
          }
        }
        else if (state == 1) {
          if (stateSum == 0) {
            update(dp[i + 1][1][0], dp[i][state][stateSum]);
            update(dp[i + 1][2][0], dp[i][state][stateSum]);
            update(dp[i + 1][1][1], dp[i][state][stateSum] + k * a[i + 1]);
            update(dp[i + 1][2][1], dp[i][state][stateSum] + a[i + 1]);
          }
          else if (stateSum == 1) {
            update(dp[i + 1][1][1], dp[i][state][stateSum] + k * a[i + 1]); 
            update(dp[i + 1][2][1], dp[i][state][stateSum] + a[i + 1]); 
            update(dp[i + 1][1][2], dp[i][state][stateSum]); 
            update(dp[i + 1][2][2], dp[i][state][stateSum]); 
          }   
          else {
            update(dp[i + 1][1][2], dp[i][state][stateSum]); 
            update(dp[i + 1][2][2], dp[i][state][stateSum]); 
          }                          
        }
        else {
          if (stateSum == 0) {
            update(dp[i + 1][2][0], dp[i][state][stateSum]);
            update(dp[i + 1][2][1], dp[i][state][stateSum] + a[i + 1]);
          }
          else if (stateSum == 1) {
            update(dp[i + 1][2][1], dp[i][state][stateSum] + a[i + 1]); 
            update(dp[i + 1][2][2], dp[i][state][stateSum]); 
          }   
          else {
            update(dp[i + 1][1][2], dp[i][state][stateSum]); 
          }  
        }
      }
    }
  }
  long long ans = inf; 
  for (int state = 0; state <= 2; state++) {
    for (int stateSum = 0; stateSum <= 2; stateSum++) {
      update(ans, dp[n][state][stateSum]);
    } 
  }
  std::cout << ans; 
  return 0; 
}