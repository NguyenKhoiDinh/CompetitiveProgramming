#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 100005; 
int numTest;
struct toy {
  int E, R; 
};
toy a[MAX_N];
int n; 

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": ";
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i].E >> a[i].R; 
    }
    vector <pair <int, int> > save; 
    for (int i = 0; i < n; i++) {
      save.push_back(make_pair(a[i].E + a[i].R, a[i].E));
    }
    sort(save.begin(), save.end());
    long long sumTime = 0LL; 
    for (int i = 0; i < n; i++) {
      sumTime += a[i].E; 
    }
    bool flag = false;
    for (int i = n - 1; i >= 0; i--) {
      if (save[i].first <= sumTime) {
        cout << n - i - 1 << ' ' << "INDEFINITELY" << endl; 
        flag = true; 
        break; 
      }
      sumTime -= save[i].second; 
    }
    if (flag == true) {
      continue; 
    }
    for (int i = 0; i < n; i++) {
      sumTime += a[i].E; 
    }
    long long sum = 0LL; 
    long long ans = sumTime; 
    int cntDelete = 0; 
    priority_queue <pair <long long, int> > pq; 
    int numDel = 0; 
    for (int i = 0; i < n; i++) {
      pq.push(make_pair(a[i].E + a[i].R, a[i].E));
      sum += a[i].E; 
      while (!pq.empty()) {
        pair <long long, int> pqTop = pq.top(); 
        if (pqTop.first > sumTime) {
          sumTime -= pqTop.second; 
          pq.pop(); 
          numDel++; 
          sum -= pqTop.second; 
        }
        else {
          break; 
        }
      }
      if (ans < sumTime + sum) {
        ans = sumTime + sum;
        cntDelete = numDel; 
      }
    }
    cout << cntDelete << ' ' << ans << endl; 
  }
  return 0;
}