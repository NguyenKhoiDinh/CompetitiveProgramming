#include <bits/stdc++.h> 

using namespace std;
int numTest;
struct element {
  int l, r;
  bool operator < (const element &other) {
    return l < other.l;
  }
};

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    cin >> n;
    vector <vector <int> > a;
    for (int i = 1; i <= n; i++) {
      int cnt;
      cin >> cnt;
      vector <int> b;
      for (int j = 1; j <= cnt; j++) {
        int x;
        cin >> x;
        b.push_back(x);
      } 
      a.push_back(b);
    }
    vector <element> save;
    for (int i = 0; i < n; i++) {
      int lo = 1; 
      int hi = 1000000007;
      int l = -1, r = -1;
      while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        int value = mid; 
        bool check = true;
        for (int j = 0; j < (int) a[i].size(); j++) {
          if (value > a[i][j]) {
            value++;
          }
          else {
            check = false;
            break;
          }
        }
        if (check == true) {
          l = mid;
          hi = mid - 1;  
        }
        else {
          lo = mid + 1;
        }
      }
      save.push_back((element) {l, l + (int) a[i].size()});
    }                              
    sort(save.begin(), save.end());
    for (int i = 1; i < (int) save.size(); i++) {
      if (save[i].l < save[i - 1].r) {
        int diff = save[i - 1].r - save[i].l;
        save[i].l = save[i - 1].r;
        save[i].r += diff;  
      }
    }
    int ans = save[0].l;
    for (int i = 1; i < (int) save.size(); i++) {
      if (save[i].l > save[i - 1].r) {
        ans += save[i].l - save[i - 1].r;
      }
    }
    cout << ans << endl;
  }
  return 0; 
}