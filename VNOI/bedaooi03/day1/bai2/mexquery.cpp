#include <iostream>
#include <algorithm>
#include <utility>
#include <vector> 
std::vector <int> a;
std::vector <std::vector <std::pair <int, bool> > > it;
int n, numQueries;  

void lazyUpdate(const int &x, int index, int L, int R) {
  if (it[x][index].second == true && L < R) {
    int mid = (L + R) / 2;   
    it[x][2 * index].first = (it[x][index].first == 0 ? 0 : mid - L + 1);
    it[x][2 * index].second = true;
    it[x][2 * index + 1].first = (it[x][index].first == 0 ? 0 : R - mid);
    it[x][2 * index + 1].second = true;  
  }  
  it[x][index].second = false; 
}

void update(const int &x, int index, int L, int R, int l, int r, const int &value) {
  lazyUpdate(x, index, L, R); 
  if (L > r || l > R) {
    return; 
  }
  if (l <= L && R <= r) {
    it[x][index].first = (value == 1 ? R - L + 1 : 0); 
    it[x][index].second = true;
    lazyUpdate(x, index, L, R);
    return;  
  }
  int mid = (L + R) / 2; 
  update(x, 2 * index, L, mid, l, r, value);
  update(x, 2 * index + 1, mid + 1, R, l, r, value);
  it[x][index].first = it[x][2 * index].first + it[x][2 * index + 1].first; 
}

int get(const int &x, int index, int L, int R, int l, int r) {
  lazyUpdate(x, index, L, R); 
  if (L > r || l > R) {
    return 0; 
  }
  if (l <= L && R <= r) {
    return it[x][index].first; 
  }
  int mid = (L + R) / 2; 
  int get1 = get(x, 2 * index, L, mid, l, r);
  int get2 = get(x, 2 * index + 1, mid + 1, R, l, r);
  return get1 + get2; 
}

int main () {
  freopen("mexquery.inp", "r", stdin);
  freopen("mexquery.out", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i]; 
  } 
  it.resize(31);
  for (int i = 0; i <= 30; i++) {
    it[i].resize(4 * n + 5); 
  }
  for (int i = 0; i < n; i++) {
    update(a[i], 1, 0, n - 1, i, i, 1); 
  }
  std::cin >> numQueries;
  for (int query = 1; query <= numQueries; query++) {
    int type;
    std::cin >> type;
    if (type == 1) {
      int l, r, increasing; 
      std::cin >> l >> r >> increasing;
      l--;
      r--;
      std::vector <int> save;
      for (int i = 0; i <= 30; i++) {
        int numb = get(i, 1, 0, n - 1, l, r); 
        save.push_back(numb); 
      }
      if (increasing == 1) {
        int pos = l; 
        for (int i = 0; i < (int) save.size(); i++) {
          if (save[i] == 0) {
            continue; 
          }  
          update(i, 1, 0, n - 1, pos, pos + save[i] - 1, 1);
          update(i, 1, 0, n - 1, pos + save[i], r, 0);   
          update(i, 1, 0, n - 1, l, pos - 1, 0);
          pos += save[i]; 
        }
      }
      else {
        int pos = l; 
        for (int i = (int) save.size() - 1; i >= 0; i--) {
          if (save[i] == 0) {
            continue; 
          }  
          update(i, 1, 0, n - 1, pos, pos + save[i] - 1, 1);
          update(i, 1, 0, n - 1, pos + save[i], r, 0);
          update(i, 1, 0, n - 1, l, pos - 1, 0); 
          pos += save[i]; 
        }
      } 
    }
    else {
      int l, r;
      std::cin >> l >> r;
      l--;
      r--;
      int ans = 31; 
      for (int i = 0; i <= 30; i++) {
        int numb = get(i, 1, 0, n - 1, l, r);          
        if (numb == 0) {                         
          ans = i;
          break; 
        }
      }
      std::cout << ans << std::endl;
    }  
  }
  return 0; 
}   