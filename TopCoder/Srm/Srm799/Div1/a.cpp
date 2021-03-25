#include <bits/stdc++.h>

using namespace std;
int must[30];

class CapriciousSorting {
  public:
  int count(vector <int> num) {
    int n = (int) num.size();
    for (int i = 0; i < 30; i++) {
      must[i] = -1;
    }
    for (int i = 1; i < 30; i++) {
    }
    for (int i = 0; i < n - 1; i++) {
      if (num[i] == num[i + 1]) {
        return 0;
      }
    }
    for (int i = 0; i < n - 1; i++) {
      int maxValue = max(num[i], num[i + 1]);
      int maxBit = 0;
      for (int bit = 0; bit < 30; bit++) {
        if ((num[i] & (1 << bit)) != (num[i + 1] & (1 << bit))) {
          maxBit = bit;
        }
      }
      int flag = (num[i] > num[i + 1]);
      if (must[maxBit] != -1 && must[maxBit] != flag) {
        return 0;
      }
      must[maxBit] = flag;
    }
    int ans = 1;
    for (int bit = 0; bit < 30; bit++) {
      if (must[bit] == -1) {
        ans *= 2;
      }
    }
    return ans;
  }
};
