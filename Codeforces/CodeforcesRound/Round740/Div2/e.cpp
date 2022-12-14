#include <bits/stdc++.h> 

using namespace std;
const int MAX_N = 2025;
int numTest;
int n;
int a[MAX_N];
vector <int> ans;

void rev(int pos) {
  ans.push_back(pos);
  int l = 1; int r = pos;
  while (l <= r) {
    swap(a[l], a[r]);
    l++;
    r--;
  }
}

int findPos(int value) {
  for (int i = 1; i <= n; i++) {
    if (value == a[i]) {
      return i;
    }
  }
  return 0;
}

int main () {
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    bool found = true; 
    for (int i = 1; i <= n; i++) {
      if (a[i] % 2 != i % 2) {
        found = false;
        break; 
      }  
    }
    if (found == false) {
      cout << -1 << endl; 
      continue;
    }                
    ans.clear();
    for (int i = n; i >= 3; i -= 2) {
      int pos = findPos(i);
      rev(pos);
      pos = findPos(i - 1);
      rev(pos - 1);
      rev(pos + 1);
      rev(3);
      rev(i);    
    } 
    cout << (int) ans.size() << endl;
    for (int i = 0; i < (int) ans.size(); i++) {
      cout << ans[i] << ' ';
    }
    cout << endl; 
  }
  return 0; 
}