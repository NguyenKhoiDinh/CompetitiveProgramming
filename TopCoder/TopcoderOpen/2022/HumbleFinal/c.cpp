#include <bits/stdc++.h> 

using namespace std;
int stick[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}; 
int f[10][65]; 

class MatchstickNumbers {
  public:
  void init() {
    f[0][0] = 1;
    for (int i = 0; i < 9; i++) {
      for (int totalSticks = 0; totalSticks <= 63; totalSticks++) {
        if (f[i][totalSticks] == 0) {
          continue; 
        }
        for (int dig = 0; dig <= 9; dig++) {
          f[i + 1][totalSticks + stick[dig]] += f[i][totalSticks]; 
        }
      }
    }  
  }
  string index(int N) {
    init();
    N++;
    string ans = "";
    int totalSticks = -1;
    for (int j = 1; j <= 63; j++) {
      if (N > f[9][j]) {
        N -= f[9][j]; 
      }
      else {
        totalSticks = j; 
        break; 
      }
    }
    int i = 9;
    while (i >= 1) {
      for (int dig = 0; dig <= 9; dig++) {
        if (totalSticks - stick[dig] < 0) {
          continue; 
        }
        if (N > f[i - 1][totalSticks - stick[dig]]) {
          N -= f[i - 1][totalSticks - stick[dig]]; 
        }
        else {
          ans += (char) (dig + '0'); 
          totalSticks -= stick[dig]; 
          break; 
        }
      }
      i--; 
    }
    return ans;  
  }
};
MatchstickNumbers M; 

int main () {
  cout << M.index(4);
  return 0; 
}