#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 200005;
vector <int> neg, pos;
int n, limitTime;
int a[MAX_N];
long long sumPos[MAX_N], sumNeg[MAX_N];

int main () {
  scanf("%d %d", &n, &limitTime);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] < 0) {
      neg.push_back(-a[i]);
    }
    else {
      pos.push_back(a[i]);
    }
  }
  reverse(neg.begin(), neg.end());
  for (int i = 0; i < (int) neg.size(); i++) {
    sumNeg[i + 1] = neg[i];
  }
  for (int i = 0; i < (int) pos.size(); i++) {
    sumPos[i + 1] = pos[i];
  }
  int ans = 0;
  for (int i = 0; i <= (int) neg.size(); i++) {
    long long timeNeg = 2LL * sumNeg[i];
    long long timePos = limitTime - timeNeg;
    int position = -1;
    int l = 0;
    int r = (int) pos.size();
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (timePos >= sumPos[mid]) {
        position = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    if (position != -1) {
      ans = max(ans, i + position);
    }
  }
  for (int i = 0; i <= (int) pos.size(); i++) {
    long long timePos = 2LL * sumPos[i];
    long long timeNeg = limitTime - timePos;
    int position = -1;
    int l = 0;
    int r = (int) neg.size();
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (timeNeg >= sumNeg[mid]) {
        position = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    if (position != -1) {
      ans = max(ans, i + position);
    }
  }
  printf("%d", ans);
  return 0;
}