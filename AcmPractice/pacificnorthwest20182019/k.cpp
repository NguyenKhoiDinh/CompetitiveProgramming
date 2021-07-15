#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 9;
const double PROB = 1.0000 / 36.000000;
double prob[13];
double dpMin[(1 << MAX_N) + 5], dpMax[(1 << MAX_N) + 5];
vector <int> listMask[13];
int sum[(1 << MAX_N) + 5];
string s;
int value1, value2;
int maskDigit = 0;
double expectedMax = -1000.00000000, expectedMin = 1000000.00000000000;
string ansMax = "-1", ansMin = "-1";

string changeToString(int mask) {
  string ans = "";
  for (int i = 0; i < MAX_N; i++) {
    if ((mask & (1 << i)) > 0) {
      ans += (char) (i + 1 + '0');
    }
  }
  if (mask == 0) {
    ans = "0";
  }
  return ans;
}

int changeToInt(int mask) {
  int sum = 0;
  for (int i = 0; i < MAX_N; i++) {
    if ((mask & (1 << i)) > 0) {
      sum = sum * 10 + (i + 1);
    }
  }
  return sum;
}

void init() {
  for (int mask = 1; mask < (1 << MAX_N); mask++) {
    for (int i = 0; i < MAX_N; i++) {
      if ((mask & (1 << i)) > 0) {
        sum[mask] += i + 1;
      }
    }
    if (sum[mask] <= 12) {
      listMask[sum[mask]].push_back(mask);
    }
  }
}

void solveMin() {
  for (int mask = 1; mask < (1 << MAX_N); mask++) {
    for (int sumDice = 2; sumDice <= 12; sumDice++) {
      bool found = false;
      double minValue = expectedMin;
      for (int i = 0; i < (int) listMask[sumDice].size(); i++) {
        int nextMask = listMask[sumDice][i];
        if ((mask & nextMask) == nextMask) {
          found = true;
          minValue = min(minValue, dpMin[mask - nextMask]);
        }
      }
      dpMin[mask] += prob[sumDice] * (found == true ? minValue : changeToInt(mask));
    }
  }
}

void solveMax() {
  for (int mask = 1; mask < (1 << MAX_N); mask++) {
    for (int sumDice = 2; sumDice <= 12; sumDice++) {
      bool found = false;
      double maxValue = expectedMax;
      for (int i = 0; i < (int) listMask[sumDice].size(); i++) {
        int nextMask = listMask[sumDice][i];
        if ((mask & nextMask) == nextMask) {
          found = true;
          maxValue = max(maxValue, dpMax[mask - nextMask]);
        }
      }
      dpMax[mask] += prob[sumDice] * (found == true ? maxValue : changeToInt(mask));
    }
  }
}

int main () {
  init();
  cin >> s >> value1 >> value2;
  int total = value1 + value2;
  int n = (int) s.size();
  for (int i = 0; i < n; i++) {
    maskDigit |= (1 << (s[i] - '0' - 1));
  }
  for (int x = 1; x <= 6; x++) {
    for (int y = 1; y <= 6; y++) {
      prob[x + y] += PROB;
    }
  }
  solveMin();
  solveMax();
  for (int i = 0; i < (int) listMask[total].size(); i++) {
    int mask = listMask[total][i];
    if ((maskDigit & mask) == mask) {
      if (expectedMax < dpMax[maskDigit - mask]) {
        ansMax = changeToString(mask);
        expectedMax = dpMax[maskDigit - mask];
      }
      if (expectedMin > dpMin[maskDigit - mask]) {
        ansMin = changeToString(mask);
        expectedMin = dpMin[maskDigit - mask];
      }
    }
  }
  if (ansMax == "-1" || ansMin == "-1") {
    cout << ansMin << ' ' << s << ".00000" << endl;
    cout << ansMax << ' ' << s << ".00000" << endl;
  }
  else {
    cout << ansMin << ' ';
    cout << fixed << setprecision(5) << expectedMin << endl;
    cout << ansMax << ' ';
    cout << fixed << setprecision(5) << expectedMax << endl;
  }
  return 0;
}