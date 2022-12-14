#include <bits/stdc++.h>

using namespace std;

map <int, int> M;

class PlanningTrips {
  public:
  int find(int a, vector <int> num) {
    int n = (int) num.size();
    for (int i = 0; i < n; i++) {
      M[num[i]]++;
    }
    vector <pair <int, int> > save;
    while ((int) M.size() > 0) {
      map <int, int> :: iterator it = M.begin();
      int key = it->first;
      int val = it->second;
      int cnt = val % a;
      if (val >= a) {
        M[key + 1] += val / a;
      }
      M.erase(it);
      if (cnt > 0) {
        save.push_back(make_pair(key, cnt));
      }
    }
    if ((int) save.size() == 1 && save.back().first == 1) {
      return save.back().first;
    }
    else {
      return save.back().first + 1;
    }
  }
};

PlanningTrips P;

int main () {
  cout << P.find(10,
{5, 6, 3});
  return 0;
}