#include <bits/stdc++.h>

using namespace std;

int dp[55][55];

class SimilarDNA {
  public: 
  string areSimilar(string A, string B) {
    int lenA = (int) A.size();
    int lenB = (int) B.size();
    for (int i = 0; i <= lenA; i++) {
      dp[i][0] = i;
    }
    for (int i = 0; i <= lenB; i++) {
      dp[0][i] = i;
    }
    for (int i = 1; i <= lenA; i++) {
      for (int j = 1; j <= lenB; j++) {
        if (A[i - 1] == B[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        }
        else {
          dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
        }
      }
    }
    return (dp[lenA][lenB] <= 2 ? "similar" : "disticnt");
  }
};

SimilarDNA S;

int main () {
  return 0;
}