#include <bits/stdc++.h> 

using namespace std;

class GameShowTotal {
  public:
  string verify(int n, vector <int> a, int W) {
    int sum = 0; 
    if (W == 0) {
      return "possible"; 
    }
    for (int i = n - 1; i >= 0; i--) {
      sum += a[i]; 
      if (sum == W) {
        return "possible"; 
      }
    }
    return "impossible"; 
  }
};
GameShowTotal G; 

int main () {
  return 0; 
}