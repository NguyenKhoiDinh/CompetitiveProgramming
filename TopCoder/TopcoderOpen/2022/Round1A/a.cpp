#include <bits/stdc++.h> 

using namespace std; 

class SkyscraperReconstruction {
  public: 
  vector <int> reconstruct(string s) {
    int n = (int) s.size();
    vector <int> ret(n, 0);
    int p = n; 
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == 'O') {
        ret[i] = p; 
        p--; 
      }
    }  
    for (int i = 0; i < n; i++) {
      if (ret[i] == 0) {
        ret[i] = p; 
        p--; 
      }
    }
    return ret; 
  }
};
SkyscraperReconstruction S; 

int main () {
  return 0; 
}