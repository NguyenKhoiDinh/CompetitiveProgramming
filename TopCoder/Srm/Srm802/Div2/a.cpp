#include <bits/stdc++.h>

using namespace std;

class BallotCounting {
  public:
  int count(string votes) {
    int n = (int) votes.size();
    int maxVote = n / 2 + 1;
    int voteA = 0, voteB = 0;
    for (int i = 0; i < n; i++) {
      if (votes[i] == 'A') {
        voteA++;
      }
      else {
        voteB++;
      }
      if (voteA == maxVote || voteB == maxVote) {
        return i + 1;
      }
    }
    return n;
  }
};

int main () {
  return 0;
}