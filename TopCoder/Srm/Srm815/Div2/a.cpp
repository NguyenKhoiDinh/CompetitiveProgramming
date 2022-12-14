#include <bits/stdc++.h>

using namespace std;

class SunShroom {
  public:
  long long produceSun(vector<long long> a, long long t) {
    int n = (int) a.size();   
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      long long v = a[i];
      if (v <= t) {
        long long grow = (t - v) / 24;
        if (grow > 4) {
          grow -= 4;
          ans += 60; 
        }  
        else {
          ans += 15LL * grow; 
          grow = 0; 
        }
        ans += 25LL * grow; 
      }
    }
    return ans;
  }
};

SunShroom S; 

int main () {
  return 0;
}