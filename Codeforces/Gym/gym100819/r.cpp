#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct fullName {
  string lastName, firstName;
  bool operator < (const fullName &other) const {
    if (lastName < other.lastName || (lastName == other.lastName && firstName < other.firstName)) {
      return true;
    }
    return false;
  }
};

int n;
vector <fullName> listStudent;

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n;
  listStudent.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> listStudent[i].firstName >> listStudent[i].lastName;
  }
  sort(listStudent.begin(), listStudent.end());
  for (int i = 0; i < n; i++) {
    cout << listStudent[i].firstName << ' ' << listStudent[i].lastName << endl;
  }
  return 0;
}