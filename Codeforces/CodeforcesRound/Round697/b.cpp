#include <iostream>
#include <fstream>

using namespace std;
int numTest;
int n;
bool check[1000005];

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int x = 0; x <= 1000; x++) {
    for (int y = 0; y <= 1000; y++) {
      if (2020 * x + 2021 * y > 1000000) {
        continue;
      }
      check[2020 * x + 2021 * y] = true;
    }
  }
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    cout << (check[n] == true ? "YES" : "NO") << endl;
  }
  return 0;
}