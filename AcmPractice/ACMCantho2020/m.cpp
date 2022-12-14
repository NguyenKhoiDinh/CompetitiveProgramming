#include <iostream>
#include <vector>
#include <iomanip>
#include <set>

using namespace std;
int n, k;
double x;
vector <int> listCup;

int main () {
  cin >> n >> k >> x;
  for (int i = 1; i <= n; i += k) {
    listCup.push_back(i);
  }
  n = (int) listCup.size();
  cout << fixed << setprecision(12);
  cout << "POUR ";
  cout << n << ' ';
  for (int i = 0; i < n; i++) {
    cout << listCup[i] << ' ' << x / n << ' ';
  }
  cout << flush;
  int emptyCup = -1;
  int drinkCup = -1;
  double water = x / n;
  cin >> drinkCup;
  for (int i = 0; i < n; i++) {
    if (drinkCup <= listCup[i] && listCup[i] <= drinkCup + k - 1) {
      emptyCup = listCup[i];
      break;
    }
  }
  for (int step = 1; step <= 1900; step++) {
    cout << "POUR ";
    cout << n << ' ';
    double addMore = (x - water) / n;
    for (int i = 0; i < n; i++) {
      cout << listCup[i] << ' ';
      if (listCup[i] == emptyCup) {
        cout << water + addMore << ' ';
      }
      else {
        cout << addMore << ' ';
      }
    }
    cout << flush;
    water += addMore;
    cin >> drinkCup;
    emptyCup = -1;
    for (int i = 0; i < n; i++) {
      if (drinkCup <= listCup[i] && listCup[i] <= drinkCup + k - 1) {
        emptyCup = listCup[i];
        break;
      }
    }
  }
  set <int> finalCups;
  for (int i = 0; i < n; i++) {
    if (listCup[i] != emptyCup) {
      finalCups.insert(listCup[i]);
    }
  }
  int step = 1900;
  while (true) {
    if (step == 1990) {
      break;
    }
    int sz = (int) finalCups.size();
    if (sz == 1) {
      cout << "FINAL 1 ";
      set <int> :: iterator it = finalCups.begin();
      cout << *it << ' ' << x;
      cout << flush;
      return 0;
    }
    double addMore = x / sz;
    cout << "POUR " << sz << ' ';
    for (set <int> :: iterator it = finalCups.begin(); it != finalCups.end(); it++) {
      cout << *it << ' ';
      cout << addMore << ' ';
    }
    cout << flush;
    cin >> drinkCup;
    set <int> :: iterator pos;
    emptyCup = -1;
    for (set <int> :: iterator it = finalCups.begin(); it != finalCups.end(); it++) {
      int cup = *it;
      if (drinkCup <= cup && cup <= drinkCup + k - 1) {
        emptyCup = cup;
        pos = it;
        break;
      }
    }
    if (emptyCup != -1) {
      finalCups.erase(pos);
    }
    step++;
  }
  cout << "FINAL 1 ";
  if (!finalCups.empty()) {
    set <int> :: iterator it = finalCups.begin();
    cout << *it << ' ' << x;
  }
  else {
    cout << 1 << ' ' << x;
  }
  cout << flush;
  return 0;
}