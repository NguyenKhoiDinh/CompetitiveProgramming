#include <iostream>
#include <vector>
#include <math.h>
const int inf = 1000000007;
const int MAXB = 30; 
int numTest; 
int n, V, numQueries;
int a[200005], b[200005]; 
int f[200005][19]; 
int range(int l, int r) {
  int j = (int) std::log2(r - l + 1); 
  return std::max(f[r][j], f[l + (1 << j) - 1][j]); 
}
struct itnode {
  std::vector <int> maxId;
  std::vector <int> minId;
  int l, r;  
  int ans; 
  itnode() {
    ans = inf; 
    maxId.resize(MAXB, 0);
    minId.resize(MAXB, 0);
    l = 0;
    r = 0;   
  }
  friend itnode operator +(const itnode &a, const itnode &b) {
    itnode ret; 
    ret.l = a.l;
    ret.r = b.r; 
    ret.ans = std::min(a.ans, b.ans); 
    int value = 0; 
    for (int i = MAXB - 1; i >= 0; i--) {
      int bit = ((V & (1 << i)) > 0);
      ret.maxId[i] = (b.maxId[i] == 0 ? a.maxId[i] : b.maxId[i]); 
      ret.minId[i] = (a.minId[i] == 0 ? b.minId[i] : a.minId[i]); 
      int leftValue = (a.maxId[i] == 0 ? inf : range(a.maxId[i], a.r));
      int rightValue = (b.minId[i] == 0 ? inf : range(b.l, b.minId[i]));
      int minValue = std::min(leftValue, rightValue); 
      if (bit == 0) {
        ret.ans = std::min(ret.ans, std::max(value, minValue));   
      }  
      else {
        value = std::max(value, minValue);
      }
    }
    ret.ans = std::min(ret.ans, value); 
    return ret; 
  }
};
std::vector <itnode> it; 
void update(const int &index, const int &L, const int &R, const int &p, const int &value) {
  it[index].l = L;
  it[index].r = R; 
  if (R < p || L > p) {
    return; 
  }
  if (L == R) {
    it[index].ans = (value >= V ? a[p] : inf);
    for (int i = MAXB - 1; i >= 0; i--) {
      int bit = ((value & (1 << i)) > 0); 
      if (bit == 1) {
        it[index].maxId[i] = p;
        it[index].minId[i] = p; 
      }
      else {
        it[index].maxId[i] = 0;
        it[index].minId[i] = 0; 
      }
    }               
    return;     
  }
  int mid = (L + R) / 2; 
  update(2 * index, L, mid, p, value); 
  update(2 * index + 1, mid + 1, R, p, value); 
  it[index] = it[2 * index] + it[2 * index + 1]; 
}

itnode get(const int &index, const int &L, const int &R, const int &l, const int &r) {
  if (l <= L && R <= r) {
    return it[index]; 
  }
  if (l > R || L > r) {
    itnode ret; 
    ret.l = L; 
    ret.r = R; 
    return ret; 
  }
  int mid = (L + R) / 2; 
  itnode getLeft = get(2 * index, L, mid, l, r);
  itnode getRight = get(2 * index + 1, mid + 1, R, l, r); 
  itnode ret = getLeft + getRight;
  return ret; 
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> V; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      std::cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 19; j++) {
        f[i][j] = -1; 
      }
    }
    for (int i = 1; i <= n; i++) {
      f[i][0] = a[i]; 
    }
    for (int j = 1; j < 19; j++) {
      for (int i = 1; i <= n; i++) {
        if (i - (1 << j) > 0 && f[i - (1 << j)][j - 1] != -1) {
          f[i][j] = std::max(f[i][j - 1], f[i - (1 << j)][j - 1]); 
        }
      }  
    }
    it.clear();
    it.resize(4 * n + 5); 
    for (int i = 1; i <= n; i++) {
      update(1, 1, n, i, b[i]); 
    }
    std::cin >> numQueries; 
    for (int query = 1; query <= numQueries; query++) {
      int type;
      std::cin >> type;
      if (type == 1) {
        int p, x;
        std::cin >> p >> x; 
        update(1, 1, n, p, x); 
      }
      else {
        int l, r;
        std::cin >> l >> r; 
        itnode ret = get(1, 1, n, l, r); 
        std::cout << (ret.ans == inf ? -1 : ret.ans) << ' '; 
      }
    }
    std::cout << std::endl;
  }
  return 0; 
}