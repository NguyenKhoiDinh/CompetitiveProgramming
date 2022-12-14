#include <bits/stdc++.h> 

using namespace std;
const long long MOD = 1000000007; 

class BearCavalry {
  public: 
  int countAssignments(vector <int> a, vector <int> b) {
    int n = (int) a.size(); 
    long long ans = 0LL; 
    for (int i = 0; i < n; i++) {
      vector <int> war;
      vector <int> hor; 
      for (int k = 0; k < n; k++) {
        if (k != 0) {
          war.push_back(a[k]); 
        }
        if (k != i) {
          hor.push_back(b[k]); 
        }
      }
      sort(war.begin(), war.end());
      long long mul = 1LL;
      int subtract = 0;  
      for (int k = (int) war.size() - 1; k >= 0; k--) {
        int cnt = 0; 
        for (int p = 0; p < (int) hor.size(); p++) {
          if (war[k] * hor[p] < a[0] * b[i]) {
            cnt++; 
          }  
        }
        (mul *= (cnt - subtract)) %= MOD; 
        subtract++; 
      }
      (ans += mul) %= MOD; 
    }
    return ((int) ans); 
  }
};

int main () {
  return 0;
}