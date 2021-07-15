#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 200005;
vector <int> save[MAX_N];
int n;

int main () {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a, c;
    cin >> a >> c;
    save[c].push_back(a);
  }
  for (int c = 1; c < MAX_N; c++) {
    for (int i = 1; i < (int) save[c].size(); i++) {
      if (save[c][i] < save[c][i - 1]) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
  return 0;
}