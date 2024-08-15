#include <iostream>
#include <string> 
#include <math.h>
#include <vector>
const int inf = 1000000007;  
char vowels[6] = {'A', 'E', 'I', 'O', 'U', 'Y'};
int n;  
std::string s[1000005];  
int f[1000005][3];
bool isVowel(char c) {
  for (int i = 0; i < 6; i++) {
    if (c == vowels[i]) {
      return true; 
    }
  }
  return false; 
} 

int main () {
  std::cin >> n; 
  for (int i = 1; i <= n; i++) {
    std::cin >> s[i]; 
  }
  for (int i = 0; i <= n; i++) {
    for (int c = 0; c <= 2; c++) {
      f[i][c] = inf; 
    }  
  }
  f[0][0] = 0; 
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 2; j++) {
      if (f[i][j] == inf) {
        continue; 
      }
      int sz = (int) s[i + 1].size(); 
      if (sz >= 1) {
        if (isVowel(s[i + 1][0]) == true) {
          f[i + 1][0] = std::min(f[i + 1][0], f[i][j] + 1); 
        } 
        else if (j + 1 <= 2) {
          f[i + 1][j + 1] = std::min(f[i + 1][j + 1], f[i][j] + 1);  
        }
      }
      if (sz >= 2) {
        if (isVowel(s[i + 1][0]) == false && isVowel(s[i + 1][1]) == true && j + 1 <= 2) {
          f[i + 1][0] = std::min(f[i + 1][0], f[i][j] + 2); 
        }
        else if (isVowel(s[i + 1][0]) == false && isVowel(s[i + 1][1]) == false && j + 2 <= 2) {
          f[i + 1][j + 2] = std::min(f[i + 1][j + 2], f[i][j] + 2); 
        }
      }
      if (sz >= 3) {
        if (isVowel(s[i + 1][0]) == false && isVowel(s[i + 1][1]) == false && isVowel(s[i + 1][2]) == true && j + 2 <= 2) {
          f[i + 1][0] = std::min(f[i + 1][0], f[i][j] + 3); 
        }
      }
    }
  }
  int ans = inf;
  for (int j = 0; j <= 2; j++) {
    ans = std::min(ans, f[n][j]); 
  } 
  if (ans == inf) {
    std::cout << "*";
  }
  else {
    std::cout << ans; 
  } 
  return 0; 
}