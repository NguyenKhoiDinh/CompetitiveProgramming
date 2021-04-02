#include <bits/stdc++.h>

using namespace std;
struct element {
  int a[5];
  bool operator < (const element &other) const {
    return (a[0] < other.a[0] || a[0] == other.a[0] && a[1] < other.a[1] ||
    a[0] == other.a[0] && a[1] == other.a[1] && a[2] < other.a[2] ||
    a[0] == other.a[0] && a[1] == other.a[1] && a[2] == other.a[2] && a[3] < other.a[3] ||
    a[0] == other.a[0] && a[1] == other.a[1] && a[2] == other.a[2] && a[3] == other.a[3] && a[4] < other.a[4]);
  }
  bool operator == (const element &other) const {
    return (a[0] == other.a[0] && a[1] == other.a[1] && a[2] == other.a[2] &&
    a[3] == other.a[3] && a[4] == other.a[4]);
  }
};
queue <element> q;
map <element, pair <element, int> > trace;

void traceBack(element &e, element &start) {
  element current = e;
  string res = "";
  while (true) {
    cout << "ngu" << endl;
    cout << current.a[0] << current.a[1] << current.a[2] << current.a[3] << current.a[4] << endl;
    pair <element, int> back = trace[current];
    res += (char) (back.second + '0');
    current = back.first;
    if (current == start) {
      break;
    }
  }
  reverse(res.begin(), res.end());
  cout << res;
}

int main () {
  element first;
  first.a[0] = 7;
  first.a[1] = 7;
  first.a[2] = 9;
  first.a[3] = 5;
  first.a[4] = 7;
  q.push(first);
  while (true) {
    element e = q.front();
    q.pop();
    for (int i = 0; i < 5; i++) {
      element nxt = e;
      nxt.a[i]++;
      bool flag = true;
      for (int j = 0; j < 5; j++) {
        if (nxt.a[j] == 0) {
          flag = false;
          break;
        }
        if (j != i) {
          nxt.a[j]--;
        }
      }
      for (int j = 0; j < 5; j++) {
        cout << nxt.a[j] << ' ';
      }
      cout << endl;
      if (flag == true && trace.find(nxt) == trace.end()) {
        trace[nxt] = make_pair(e, i);
        q.push(nxt);
        int sum = 0;
        for (int j = 0; j < 5; j++) {
          sum += nxt.a[j];
        }
        cout << sum << endl;
        if (sum == 1) {
          //traceBack(nxt, first);
          cout << "YES" << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}

/*
(a, b) -> (2 * a, b + 1
*/