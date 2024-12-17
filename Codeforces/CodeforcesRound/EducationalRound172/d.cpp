#include <bits/stdc++.h>

using namespace std;
struct element {
  int l, r;
  bool operator < (const element &other) {
    if (l < other.l || (l == other.l && r > other.r)) {
      return true; 
    }
    return false; 
  } 
};
int n; 
map <pair <int, int>, vector <int> > save;
map <int, int> compressNumber;
vector <int> saver;  
vector <element> a;
set <int> myset; 
int ans[200005];                       
int it[4 * 200005]; 
int value[200005]; 
void update(int index, int L, int R, int position, const int &value) {
  if (L > position || position > R) {
    return; 
  }
  if (L == R) {
    it[index] = value;
    return;  
  }
  int mid = (L + R) / 2; 
  update(2 * index, L, mid, position, value); 
  update(2 * index + 1, mid + 1, R, position, value);
  it[index] = max(it[2 * index], it[2 * index + 1]);  
}   
int get(int index, int L, int R, int l, int r) {
  if (l > R || L > r) {
    return -1; 
  }
  if (l <= L && R <= r) {
    return it[index]; 
  }
  int mid = (L + R) / 2; 
  int valueLeft = get(2 * index, L, mid, l, r); 
  int valueRight = get(2 * index + 1, mid + 1, R, l, r); 
  return max(valueLeft, valueRight); 
}

int main () {
  int numTest;
  cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cin >> n;
    a.clear();
    save.clear();
    saver.clear(); 
    compressNumber.clear();
    myset.clear();  
    for (int i = 0; i < n; i++) {
      ans[i] = 0;
      int l, r;
      cin >> l >> r;
      saver.push_back(r); 
      save[make_pair(l, r)].push_back(i); 
    }
    for (int i = 1; i <= 4 * n; i++) {
      it[i] = -1;   
    }
    sort(saver.begin(), saver.end());
    int id = 1;
    compressNumber[saver[0]] = id;
    value[id] = saver[0];        
    for (int i = 1; i < (int) saver.size(); i++) {
      if (saver[i] != saver[i - 1]) {
        id++;
        compressNumber[saver[i]] = id;
        value[id] = saver[i];    
      }
    }
    for (map <pair <int, int>, vector <int> >::iterator it = save.begin(); it != save.end(); it++) {
      a.push_back((element) {it->first.first, it->first.second}); 
    } 
    sort(a.begin(), a.end());
    for (int i = 0; i < (int) a.size(); i++) {
      vector <int> &v = save[make_pair(a[i].l, a[i].r)];
      if ((int) v.size() == 1 && i > 0) {
        int currentId = compressNumber[a[i].r]; 
        set <int>::iterator it = myset.lower_bound(currentId);
        if (it != myset.end()) {
          int foundId = *it;
          int minR = value[foundId];
          int maxL = get(1, 1, n, foundId, n);
          if (maxL != -1) {
            int numb = a[i].l - maxL;
            numb += minR - a[i].r;
            ans[v[0]] = numb;  
          }   
        }                             
      }
      myset.insert(compressNumber[a[i].r]); 
      update(1, 1, n, compressNumber[a[i].r], a[i].l);       
    }                  
    for (int i = 0; i < n; i++) {
      cout << ans[i] << endl; 
    } 
  }                             
  return 0; 
}