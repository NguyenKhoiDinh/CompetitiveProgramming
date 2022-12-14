#include <bits/stdc++.h>

using namespace std;

class MinMaxGame {
  public:
  int lastNumber(vector <int> A) {
    int n = (int) A.size();
    int mini = min(A[0], A[n - 1]);
    int maxi = max(A[0], A[n - 1]);
    if (n % 2 == 0) {
      return mini;
    }
    else {
      return maxi;
    }
  }
};

MinMaxGame M;

int main () {
  cout << M.lastNumber({4, 5, 1, 6, 5});
  return 0;
}