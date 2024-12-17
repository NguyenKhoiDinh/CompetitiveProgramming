#include <bits/stdc++.h> 

using namespace std; 
int b[805][805];
int r, c;
vector <pair <int, int> > save[1000005];  
int fw[805][805]; 
void update(int indexx, int indexy, int value) {
  for (int i = indexx; i <= 800; i += i & -i) {
    for (int j = indexy; j <= 800; j += j & -j) {
      fw[i][j] += value; 
    }
  }
}
int get(int indexx, int indexy) {
  int ret = 0;
  for (int i = indexx; i > 0; i -= i & -i) {
    for (int j = indexy; j > 0; j -= j & -j) {
      ret += fw[i][j]; 
    }
  }
  return ret; 
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int numTest;
  cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cout << "Case #" << testCase << ": "; 
    long long k;
    cin >> r >> c >> k;
    for (int i = 1; i <= r * c; i++) {
      save[i].clear(); 
    } 
    for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
        cin >> b[i][j];
        save[b[i][j]].push_back(make_pair(i, j));   
      }
    }
    for (int i = 1; i <= r * c; i++) {
      sort(save[i].begin(), save[i].end()); 
    }
    int lo = 1; 
    int hi = max(r, c);
    int ans = -1;  
    while (lo <= hi) {
      memset(fw, 0, sizeof(fw));
      int mid = (lo + hi) / 2; 
      long long numb = 0LL; 
      for (int i = 1; i <= r * c; i++) {
        for (int j = 0; j < (int) save[i].size(); j++) {
          pair <int, int> pr = save[i][j]; 
          int x = pr.first;
          int y = pr.second;
          int lx = max(1, x - mid);
          int rx = min(r, x + mid);
          int ly = max(1, y - mid);
          int ry = min(c, y + mid);
          numb += get(rx, ry) - get(rx, ly - 1) - get(lx - 1, ry) + get(lx - 1, ly - 1);    
        }
        for (int j = 0; j < (int) save[i].size(); j++) {
          pair <int, int> pr = save[i][j];
          int x = pr.first;
          int y = pr.second; 
          update(x, y, 1); 
        }
      } 
      numb *= 2LL;                           
      if (numb >= k) {
        ans = mid; 
        hi = mid - 1; 
      }
      else {
        lo = mid + 1; 
      }
    }
    cout << ans << endl; 
    cerr << "Test Case " << testCase << " Success!!" << endl; 
  }
  return 0; 
}