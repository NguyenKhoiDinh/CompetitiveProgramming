#include <bits/stdc++.h>

using namespace std;
int Count[1005];

class DivideLoot {
  public:
  string verify(int N, vector <int> loot) {
    int sum = 0;
    for (int i = 0; i < (int) loot.size(); i++) {
      sum += loot[i];
    }
    if (sum % N != 0) {
      return "impossible";
    }
    sum /= N;
    vector <int> newLoot;
    for (int i = 0; i < (int) loot.size(); i++) {
      if (loot[i] == sum) {
        N--;
      }
      else {
        newLoot.push_back(loot[i]);
      }
    }
    if (2 * N != (int) newLoot.size()) {
      return "impossible";
    }
    for (int i = 0; i < (int) newLoot.size(); i++) {
      Count[newLoot[i]]++;
    }
    for (int i = 1; i <= 1000; i++) {
      while (Count[i] > 0) {
        Count[i]--;
        if (Count[sum - i] > 0) {
          Count[sum - i]--;
        }
        else {
          return "impossible";
        }
      }
    }
    return "possible";
  }
};

DivideLoot D;

int main () {
  cout << D.verify(5,
{1, 1, 1, 2, 2, 1});
  return 0;
}