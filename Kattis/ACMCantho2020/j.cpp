#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <algorithm>

using namespace std;

struct element {
  long long numb, total, l1, r1, l2, r2;
};

long long number = 0LL;
long long n, m;
int numTest;
vector <element> save;
vector <pair <long long, long long> > listSegment, listCutSegment;
vector <long long> listPoints;
vector <long long> numSegment;

long long calc(long long &val) {
  long long count = 0LL;
  for (int i = 0; i < (int) listCutSegment.size(); i++) {
    if (listCutSegment[i].second <= val) {
      count += numSegment[i] * (listCutSegment[i].second - listCutSegment[i].first + 1);
    }
    else if (listCutSegment[i].first <= val && val <= listCutSegment[i].second) {
      count += numSegment[i] * (val - listCutSegment[i].first + 1);
    }
  }
  return count;
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  save.push_back((element) {3, 6, 1, 2, 4, 4});
  number += 3;
  while (true) {
    long long fi = 1;
    long long se = save.back().total - 1;
    long long th = 2LL * se;
    save.push_back((element) {2LL * se - 1, se + th, 1, se, th, th + se - 2});
    number += 2LL * se - 1;
    if (number >= 1e18) {
      break;
    }
  }
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    listSegment.clear();
    listCutSegment.clear();
    numSegment.clear();
    cin >> n >> m;
    number = 0LL;
    int pos = -1;
    for (int i = 0; i < (int) save.size(); i++) {
      if (number + save[i].numb >= n) {
        pos = i;
        break;
      }
      else {
        number += save[i].numb;
      }
    }
    for (int i = 0; i < pos; i++) {
      listSegment.push_back(make_pair(save[i].l1, save[i].r1));
      listSegment.push_back(make_pair(save[i].l2, save[i].r2));
    }
    element e = save[pos];
    long long curPosition = n - number;
    listSegment.push_back(make_pair(1, 1));
    if (curPosition > 0) {
      curPosition--;
      long long numAdd1 = curPosition / 2;
      if (curPosition % 2 == 1) {
        numAdd1++;
      }
      long long numAdd2 = curPosition / 2;
      listSegment.push_back(make_pair(save[pos].r1 - numAdd1 + 1, save[pos].r1));
      if (numAdd2 > 0) {
        listSegment.push_back(make_pair(save[pos].l2, save[pos].l2 + numAdd2 - 1));
      }
    }
    listPoints.clear();
    for (int i = 0; i < (int) listSegment.size(); i++) {
      listPoints.push_back(listSegment[i].first - 1);
      listPoints.push_back(listSegment[i].second);
    }
    sort(listPoints.begin(), listPoints.end());
    for (int i = 0; i < (int) listPoints.size() - 1; i++) {
      if (listPoints[i] < listPoints[i + 1]) {
        listCutSegment.push_back(make_pair(listPoints[i] + 1, listPoints[i + 1]));
      }
    }
    for (int i = 0; i < (int) listCutSegment.size(); i++) {
      int count = 0;
      long long l = listCutSegment[i].first;
      long long r = listCutSegment[i].second;
      for (int j = 0; j < (int) listSegment.size(); j++) {
        if (listSegment[j].first <= l && r <= listSegment[j].second) {
          count++;
        }
      }
      numSegment.push_back(count);
    }
    long long ans = -1;
    long long left = 1;
    long long right = listCutSegment.back().second;
    while (left <= right) {
      long long mid = (left + right) >> 1;
      if (calc(mid) >= m) {
        ans = mid;
        right = mid - 1;
      }
      else {
        left = mid + 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}