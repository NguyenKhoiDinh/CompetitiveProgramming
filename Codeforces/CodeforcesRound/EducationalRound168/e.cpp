#include <bits/stdc++.h>

using namespace std;
int n, numQueries;
int a[200005];
int para[200005];
int fw[200005];    
void update(int index, int value) {
  for (; index <= n; index += index & -index) {
    fw[index] += value; 
  }
}
int get(int index) {
  int ret = 0;
  for (; index > 0; index -= index & -index) {
    ret += fw[index]; 
  }
  return ret; 
}

int main () {      
  int numTest = 1;   
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n >> numQueries; 
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    para[1] = 1; 
    update(1, 1); 
    for (int i = 2; i <= n; i++) {
      int lo = 1;
      int hi = n;
      while (lo <= hi) {
        int mid = (lo + hi) / 2; 
        int numbDefeats = get(mid); 
        if (numbDefeats / mid < a[i]) {
          para[i] = mid; 
          hi = mid - 1; 
        }
        else {
          lo = mid + 1; 
        }
      }
      update(para[i], 1);    
    }                     
    for (int query = 1; query <= numQueries; query++) {
      int pos, x; 
      cin >> pos >> x; 
      if (para[pos] <= x) {
        cout << "YES"; 
      }
      else {
        cout << "NO";
      }
      cout << endl;
    }
  }
  return 0; 
}