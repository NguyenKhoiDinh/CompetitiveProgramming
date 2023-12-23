#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
long long cost[64][64];
std::vector <int> have, dontHave;  
bool queen[64][64], rook[64][64], knight[64][64], bishop[64][64]; 

int main () {
  //freopen("BONUS.INP", "r", stdin);
  //freopen("BONUS.OUT", "w", stdout);
  int k;
  std::cin >> k;
  for (int i = 1; i <= k; i++) {
    int x, y, value;
    std::cin >> x >> y >> value; 
    x--;
    y--; 
    cost[x][y] += value;
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (cost[i][j] > 0) {
        have.push_back(i * 8 + j); 
      }
      else {
        dontHave.push_back(i * 8 + j); 
      }
    }
  }
  for (int i = 0; i < (int) dontHave.size(); i++) {
    for (int j = 0; j < (int) have.size(); j++) {
      int valueDontHave = dontHave[i];
      int valueHave = have[j]; 
      int x1 = valueDontHave / 8;
      int y1 = valueDontHave % 8;
      int x2 = valueHave / 8;
      int y2 = valueHave % 8;
      if (x1 == x2 || y1 == y2) {
        queen[valueDontHave][valueHave] = true;
        rook[valueDontHave][valueHave] = true; 
      }
      if (x1 + y1 == x2 + y2 || x1 - y1 == x2 - y2) {
        queen[valueDontHave][valueHave] = true;
        bishop[valueDontHave][valueHave] = true; 
      }
      if ((std::abs(x2 - x1) == 2 && std::abs(y2 - y1) == 1) || (std::abs(x2 - x1) == 1 && std::abs(y2 - y1) == 2)) {
        knight[valueDontHave][valueHave] = true; 
      }
    }
  }
  long long ans = 0LL; 
  for (int iQ = 0; iQ < (int) dontHave.size(); iQ++) {
    for (int iR = 0; iR < (int) dontHave.size(); iR++) {
      if (iR == iQ) {
        continue; 
      }
      for (int iB = 0; iB < (int) dontHave.size(); iB++) {
        if (iB == iQ || iB == iR) {
          continue; 
        }
        for (int iK = 0; iK < (int) dontHave.size(); iK++) {
          if (iK == iQ || iK == iR || iK == iB) {
            continue; 
          }
          int valueQ = dontHave[iQ];
          int valueR = dontHave[iR];
          int valueB = dontHave[iB];
          int valueK = dontHave[iK];
          long long sum = 0LL; 
          for (int j = 0; j < (int) have.size(); j++) {
            int valuej = have[j]; 
            if (queen[valueQ][valuej] == true || rook[valueR][valuej] == true || bishop[valueB][valuej] == true || knight[valueK][valuej] == true) {
              int x = valuej / 8;
              int y = valuej % 8;
              sum += cost[x][y]; 
            }
          }
          ans = std::max(ans, sum); 
        }
      }
    }
  }
  std::cout << ans;
  return 0; 
}