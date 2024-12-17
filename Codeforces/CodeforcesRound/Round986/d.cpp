#include <bits/stdc++.h>

using namespace std;
int n;
int p[3][200005];
int it[3][4 * 200010];
pair <int, int> f[200005];   
void update(int index, int L, int R, int position, int value, int type) {
  if (L > position || R < position) {
    return; 
  }
  if (L == R) {
    it[type][index] = value; 
    return; 
  }
  int mid = (L + R) / 2;
  update(2 * index, L, mid, position, value, type);
  update(2 * index + 1, mid + 1, R, position, value, type); 
  it[type][index] = max(it[type][2 * index], it[type][2 * index + 1]); 
}
int get(int index, int L, int R, int l, int r, int type) {
  if (l > R || L > r) {
    return -1; 
  }
  if (l <= L && R <= r) {
    return it[type][index]; 
  }
  int mid = (L + R) / 2; 
  int maxLeft = get(2 * index, L, mid, l, r, type);
  int maxRight = get(2 * index + 1, mid + 1, R, l, r, type); 
  return max(maxLeft, maxRight); 
}

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    for (int j = 0; j < 3; j++) {
      for (int i = 1; i <= n; i++) {
        cin >> p[j][i]; 
      }
    }
    for (int i = 1; i <= n; i++) {
      f[i] = make_pair(-1, -1); 
    }
    for (int j = 0; j < 3; j++) {
      for (int i = 1; i <= 4 * n; i++) {
        it[j][i] = -1; 
      }
    }                                     
    for (int j = 0; j < 3; j++) {
      update(1, 1, n, p[j][1], 1, j); 
    }
    for (int i = 2; i <= n; i++) {
      for (int j = 0; j < 3; j++) {
        int maxValue = get(1, 1, n, p[j][i], n, j);
        if (maxValue > 0) {
          f[i] = make_pair(maxValue, j);   
        }
      }
      if (f[i].first != -1) {
        for (int j = 0; j < 3; j++) {
          update(1, 1, n, p[j][i], i, j); 
        }
      }
    }
    if (f[n].first == -1) {
      cout << "NO" << endl;
      continue; 
    }
    cout << "YES" << endl; 
    vector <pair <int, int> > ans;
    int i = n;
    while (i > 1) {
      int type = f[i].second;
      ans.push_back(make_pair(i, type));
      i = f[i].first;    
    }   
    reverse(ans.begin(), ans.end()); 
    cout << (int) ans.size() << endl; 
    for (int i = 0; i < (int) ans.size(); i++) {
      if (ans[i].second == 0) {
        cout << 'q'; 
      }
      else if (ans[i].second == 1) {
        cout << 'k';
      }
      else {
        cout << 'j';
      }
      cout << ' ' << ans[i].first;
      cout << endl; 
    }
  }       
  return 0; 
}