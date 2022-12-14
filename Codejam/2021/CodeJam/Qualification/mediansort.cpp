#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 55;
int numTest;
int n, Q;
int p[MAX_N];

struct query {
  int v1, v2, v3;
  int result;
};
vector <query> listAsked;

int findPos(int x1, int x2, int x3) {
  for (int i = 0; i < (int) listAsked.size(); i++) {
    query q = listAsked[i];
    vector <int> a, b;
    a.push_back(q.v1);
    a.push_back(q.v2);
    a.push_back(q.v3);
    b.push_back(x1);
    b.push_back(x2);
    b.push_back(x3);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a == b) {
      return q.result;
    }
  }
  return -1;
}

int main () {
  cin >> numTest >> n >> Q;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    for (int i = 1; i <= n; i++) {
      p[i] = -1;
    }
    listAsked.clear();
    vector <int> save;
    int start = -1, end = -1;
    int l = 1, r = n;
    while (l < r) {
      save.clear();
      for (int i = 1; i <= n; i++) {
        if (p[i] == -1) {
          save.push_back(i);
        }
      }
      while ((int) save.size() > 2) {
        int v1 = save.back();
        save.pop_back();
        int v2 = save.back();
        save.pop_back();
        int v3 = save.back();
        save.pop_back();

          cout << v1 << ' ' << v2 << ' ' << v3 << endl;
          fflush(stdout);
          int pos;
          cin >> pos;
          listAsked.push_back((query) {v1, v2, v3, pos});

        if (pos == v1) {
          save.push_back(v2);
          save.push_back(v3);
        }
        else if (pos == v2) {
          save.push_back(v1);
          save.push_back(v3);
        }
        else {
          save.push_back(v1);
          save.push_back(v2);
        }
      }
      if (l == 1) {
        start = save[0];
        end = save[1];
        p[start] = l;
        p[end] = r;
      }
      else {
        int pos = findPos(start, save[0], save[1]);
        {
          cout << start << ' ' << save[0] << ' ' << save[1] << endl;
          fflush(stdout);
          int pos;
          cin >> pos;
          listAsked.push_back((query) {start, save[0], save[1], pos});
        }
        if (pos == save[0]) {
          p[save[0]] = l;
          p[save[1]] = r;
        }
        else {
          p[save[1]] = l;
          p[save[0]] = r;
        }
      }
      l++;
      r--;
    }
    if (n % 2 == 1) {
      for (int i = 1; i <= n; i++) {
        if (p[i] == -1) {
          p[i] = (n + 1) / 2;
        }
      }
    }
    vector <pair <int, int> > ans;
    for (int i = 1; i <= n; i++) {
      ans.push_back(make_pair(p[i], i));
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) {
      cout << ans[i].second << ' ';
    }
    cout << endl;
    fflush(stdout);
    int answer;
    cin >> answer;
    if (answer == -1) {
      return 0;
    }
  }
  return 0;
}

/*
48 + 46
*/