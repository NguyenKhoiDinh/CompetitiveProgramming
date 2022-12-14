#include <iostream>
#include <fstream>
#include <string>

using namespace std;
string s;
int n;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> s;
  n = (int) s.size();
  bool res = true;
  for (int l = 0; l < n; l++) {
    for (int r = l; r < n; r++) {
      int head = l;
      int tail = r;
      bool flag = true;
      while (head <= tail) {
        if (s[head] != s[tail]) {
          flag = false;
          break;
        }
        head++;
        tail--;
      }
      if (flag == true) {
        if ((r - l + 1) % 2 == 0) {
          res = false;
        }
      }
    }
  }
  if (res == true) {
    cout << "Odd.";
  }
  else {
    cout << "Or not.";
  }
  return 0;
}