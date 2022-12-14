#include <bits/stdc++.h>

using namespace std;

class OptimalGolf {
  public: 
  int minStrokes(int D, vector <int> lo, vector <int> hi) {
    int n = (int) lo.size();
    int res = 0;
    bool found = false;
    while (true) {
      for (int i = 0; i < n; i++) {
        if (lo[i] <= D && D <= hi[i]) {
          res++;
          found = true; 
          break;
        }
      }
      if (found == true) {
        break;
      }
      else {
        int maxi = -1;
        for (int i = 0; i < n; i++) {
          maxi = max(maxi, hi[i]);
        }
        if (maxi > D) {
          if (res == 0) {
            res = 2;
          }
          else {
            res++;
          }
          break;
        }
        else {
          D -= maxi;
          res++;
        }
      }
    }
    return res;
  }
};

OptimalGolf O;

int main () {
  return 0;
}