#include <bits/stdc++.h>

using namespace std;

class JudgedScoring {
  public:
  int overallScore(vector <int> scores) {
    sort(scores.begin(), scores.end());
    int sum = 0;
    for (int i = 1; i < (int) scores.size() - 1; i++) {
      sum += scores[i];
    }
    return sum;
  }
};

int main () {
  return 0;
}