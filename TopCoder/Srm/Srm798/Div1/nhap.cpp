#include <bits/stdc++.h>

using namespace std;

vector <int> a;
bool visited[10];
const int MAX_N = 5;

int calc(vector <int> &a) {
  int n = (int) a.size();
  for (int i = 1; i <= n; i++) {
    visited[i] = false;
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (visited[a[i]] == false) {
      int len = 0;
      int u = a[i];
      while (true) {
        if (visited[u] == true) {
          break;
        }
        visited[u] = true;
        len++;
        u = a[u - 1];
      }
      sum += len - 1;
    }
  }
  return sum;
}

int main () {
  freopen("output.txt", "w", stdout);
  for (int i = 1; i <= MAX_N; i++) {
    a.push_back(i);
  }
  int sum = 0;
  do {
    bool flag = true;
    for (int i = 0; i < MAX_N; i++) {
      if (a[i] == i + 1) {
        flag = false;
        break;
      }
    }
    if (flag == true) {
      int val = calc(a);
      sum += val;
      if (val > 0) {
        for (int i = 0; i < MAX_N; i++) {
          cout << a[i] << "   ";
        }
        cout << ":     " << val;
        cout << endl;
      }
    }
  }
  while (next_permutation(a.begin(), a.end()));
  cout << sum;
  return 0;
}