#include <bits/stdc++.h>

using namespace std;
map <int, int> dist[55];

class Halving {
  public:
  int minSteps(vector <int> a) {
    int n = (int) a.size();
    for (int i = 0; i < n; i++) {
      int L = a[i];
      queue <int> myqueue;
      myqueue.push(L);
      dist[i][L] = 0;
      while (!myqueue.empty()) {
        int frontVal = myqueue.front();
        myqueue.pop();
        if (frontVal == 1) {
          break;
        }
        int firstPart = frontVal / 2;
        int secondPart = frontVal - firstPart;
        if (firstPart > 0 && dist[i].find(firstPart) == dist[i].end()) {
          dist[i][firstPart] = dist[i][frontVal] + 1;
          myqueue.push(firstPart);
        }
        if (secondPart != firstPart && dist[i].find(secondPart) == dist[i].end()) {
          dist[i][secondPart] = dist[i][frontVal] + 1;
          myqueue.push(secondPart);
        }
      }
    }
    int ans = 1000000007;
    for (map <int, int> :: iterator it = dist[0].begin(); it != dist[0].end(); it++) {
      int key = it->first;
      int cnt = 0;
      int total = 0;
      for (int i = 0; i < n; i++) {
        if (dist[i].find(key) != dist[i].end()) {
          cnt++;
          total += dist[i][key];
        }
      }
      if (cnt == n) {
        ans = min(ans, total);
      }
    }
    return ans;
  }
};

Halving H;

int main () {
  cout << H.minSteps({11, 4});
  return 0;
}