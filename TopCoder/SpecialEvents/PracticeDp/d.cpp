#include <bits/stdc++.h> 

using namespace std; 
class MonstersAndBunnies {
  public: 
  double survivalProbability(int M, int B) {
    if (M == 0) {
      return 1.0; 
    }       
    else if (M % 2 == 0) {
      return 1.0 / (M + 1); 
    }
    else {
      return 0.0; 
    }
  }
};

int main () {
  return 0; 
}