#include <iostream>
#include <fstream>

using namespace std;
int numTest;

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    long long n;
    cin >> n;
    if (n == 1) {
      cout << "NO" << endl;
      continue;
    }
    bool check = true;
    while (n % 2 == 0) {
      n /= 2;
    }
    if (n == 1) {
      cout << "NO";
    }
    else {
      cout << "YES";
    }
    cout << endl;
  }
  return 0;
}