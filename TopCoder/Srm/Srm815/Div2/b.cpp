#include <bits/stdc++.h>

using namespace std;
int cnt[1005];

class DevuAndRabbitNumbering {
  public:
  string canRenumber(vector <int> a) {
    int n = (int) a.size();
    sort(a.begin(), a.end());
    a[0]--;
    for (int i = 1; i < n; i++) {
      if (a[i] - 1 > a[i - 1]) {
        a[i]--;
      }
      else if (a[i] > a[i - 1]) {
      }
      else if (a[i] + 1 > a[i - 1]) {
        a[i]++;
      }
      else {
        return "cannot";
      }
    }
    return "can";
  }
};
DevuAndRabbitNumbering D; 

int main () {
  return 0;
}


[1, 1, 1]