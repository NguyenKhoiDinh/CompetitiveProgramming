#include <bits/stdc++.h> 

using namespace std;

class BearSlowlySorts {
  public: 
  int minMoves(vector <int> w) {
    vector <int> a = w; 
    int n = (int) a.size();
    sort(a.begin(), a.end());
    if (a == w) {
      return 0;
    }
    if (a[0] == w[0] || a[n - 1] == w[n - 1]) {
      return 1; 
    }
    if (a[0] == w[n - 1] && a[n - 1] == w[0]) {
      return 3;
    }
    return 2;
  }
};

int main () {
  return 0;
}