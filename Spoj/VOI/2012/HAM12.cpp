#include <iostream>
#include <string>

using namespace std;
int lenOrigin, numGen, lenGen;
string origin, gen;

int main () {
  cin >> lenOrigin >> lenGen >> numGen;
  cin >> origin;
  origin += origin;
  lenOrigin *= 2;
  int ans = 1007;
  for (int i = 1; i <= numGen; i++) {
    cin >> gen;
    int l = 0;
    int r = lenGen - 1;
    while (r < lenOrigin) {
      int cnt = 0;
      for (int j = 0; j < lenGen; j++) {
        if (gen[j] != origin[j + l]) {
          cnt++;
        }
      }
      l++;
      r++;
      if (ans > cnt) {
        ans = cnt;
      }
    }
  }
  cout << ans;
  return 0;
}