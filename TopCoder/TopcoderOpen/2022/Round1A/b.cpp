#include <bits/stdc++.h> 

using namespace std; 
const int lim = 20000;
double dp[lim + 5][105]; 
double prob[15][105]; 

class SingleOrDouble {
  public: 
  double probAlice(int N, int D, int A, int B) {
    prob[0][0] = 1.0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j <= N * D; j++) {
        if (prob[i][j] == 0.0) {
          continue; 
        }
        for (int x = 1; x <= D; x++) {
          prob[i + 1][j + x] += (1.0 / D) * prob[i][j]; 
        }
      }
    }
    // p = pA + pB * pA + (1 - pA - pB * pA - pB * pB) * p <=>
    double pA = prob[N][A];
    double pB = prob[N][B];
    double ans = (pA + pB * pA) / (pA + pB * pB + pB * pB);  
    return ans; 
  }
};
SingleOrDouble S;

int main () {
  cout << fixed << setprecision(12) << S.probAlice(10     ,
10                                                        ,
29                                                         ,
16);
  return 0; 
}