#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 105;
int numTest;
int n, sum;
int a[MAX_N];
vector <pair <int, int> > save;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n >> sum;
    save.clear();
    sum++;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
      int rem = sum - (n - i);
      int pos = -1;
      for (int j = i; j <= n; j++) {
        if (j - i + 1 <= rem) {
          pos = j;
        }
      }
      if (pos == -1) {
        flag = false;
        break;
      }
      sum -= pos - i + 1;
      a[pos] = i;
      reverse(a + i, a + pos + 1);
      save.push_back(make_pair(i, pos));
    }
    if (sum > 0) {
      flag = false;
    }
    if (flag == false) {
      cout << "IMPOSSIBLE";
    }
    else {
      reverse(save.begin(), save.end());
      for (int i = 0; i < (int) save.size(); i++) {
        int l = save[i].first;
        int r = save[i].second;
        reverse(a + l, a + r + 1);
      }
      for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
      }
    }
    cout << endl;
  }
  return 0;
}

/*
4 3 2 1

4 2 1 3

? ? ? 1

1 ? ? ?
*/