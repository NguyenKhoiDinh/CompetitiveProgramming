#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int n, numFloor;
int lowest, highest;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n >> numFloor;
  lowest = 2;
  highest = numFloor - 1;
  for (int i = 1; i <= n; i++) {
    int floor;
    string status;
    cin >> floor >> status;
    if (status == "SAFE") {
      lowest = max(lowest, floor + 1);
    }
    else {
      highest = min(highest, floor - 1);
    }
  }
  cout << lowest << ' ' << highest;
  return 0;
}