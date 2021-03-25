#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
vector <int> triangle1(3), triangle2(3);

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> triangle1[0] >> triangle1[1] >> triangle1[2];
  cin >> triangle2[0] >> triangle2[1] >> triangle2[2];
  sort(triangle1.begin(), triangle1.end());
  sort(triangle2.begin(), triangle2.end());
  if (triangle1 != triangle2) {
    cout << "NO";
    return 0;
  }
  if (triangle1[0] * triangle1[0] + triangle1[1] * triangle1[1] == triangle1[2] * triangle1[2]) {
    cout << "YES";
  }
  else {
    cout << "NO";
  }
  return 0;
}