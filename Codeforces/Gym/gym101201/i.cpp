#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct house {
  int x, m;
  bool operator < (const house &hs) const {
    return x < hs.x;
  }
};
vector <house> neg, pos;
int n, k;

long long calc(vector <house> &listHouse) {
  sort(listHouse.begin(), listHouse.end());
  long long res = 0;
  int curPos = (int) listHouse.size() - 1;
  while (curPos >= 0) {
    int numTrips = (listHouse[curPos].m + k - 1) / k;
    res += 2LL * numTrips * listHouse[curPos].x;
    int numLetters = k * numTrips - listHouse[curPos].m;
    curPos--;
    while (true) {
      if (curPos < 0 || numLetters == 0) {
        break;
      }
      if (numLetters >= listHouse[curPos].m) {
        numLetters -= listHouse[curPos].m;
        curPos--;
      }
      else {
        listHouse[curPos].m -= numLetters;
        numLetters = 0;
      }
    }
  }
  return res;
}

int main () {
  freopen("input.txt", "r", stdin);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int x, m;
    cin >> x >> m;
    if (x < 0) {
      neg.push_back((house) {abs(x), m});
    }
    else {
      pos.push_back((house) {x, m});
    }
  }
  long long res = calc(neg) + calc(pos);
  cout << res;
  return 0;
}