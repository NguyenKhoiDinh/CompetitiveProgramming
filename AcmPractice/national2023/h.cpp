#include <iostream>
#include <algorithm>
#include <vector>
int n, numQueries; 
int a[200005]; 
std::vector <long long> listPosition[200005]; 
std::vector <long long> fw[200005]; 
int p[200005]; 
long long last = 0LL; 

void update(const int &x, int index, const long long &value) {
  int sz = (int) fw[x].size();
  sz--; 
  for (; index <= sz; index += index & -index) {
    fw[x][index] += value; 
  }
}

long long get(const int &x, int index) {
  long long ret = 0LL; 
  for (; index > 0; index -= index & -index) {
    ret += fw[x][index]; 
  }
  return ret; 
}

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin >> n >> numQueries; 
  for (int i = 1; i <= n; i++) {
    listPosition[i].push_back(0LL); 
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];   
    p[i] = (int) listPosition[a[i]].size(); 
    listPosition[a[i]].push_back(i); 
  }
  for (int i = 1; i <= n; i++) {
    int sz = (int) listPosition[i].size();
    fw[i].resize(sz + 5, 0LL);  
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < (int) listPosition[i].size(); j++) {
      update(i, j, 1LL * listPosition[i][j] * listPosition[i][j]); 
    }  
  }
  for (int query = 1; query <= numQueries; query++) {
    int type;
    std::cin >> type; 
    if (type == 1) {
      long long pos;
      std::cin >> pos;
      pos = (1LL * pos + last - 1 + n - 1) % (n - 1) + 1;  
      if (a[pos] != a[pos + 1]) {
        update(a[pos], p[pos], -1LL * listPosition[a[pos]][p[pos]] * listPosition[a[pos]][p[pos]]);
        listPosition[a[pos]][p[pos]]++;
        update(a[pos], p[pos], 1LL * listPosition[a[pos]][p[pos]] * listPosition[a[pos]][p[pos]]);
        update(a[pos + 1], p[pos + 1], -1LL * listPosition[a[pos + 1]][p[pos + 1]] * listPosition[a[pos + 1]][p[pos + 1]]);
        listPosition[a[pos + 1]][p[pos + 1]]--;
        update(a[pos + 1], p[pos + 1], 1LL * listPosition[a[pos + 1]][p[pos + 1]] * listPosition[a[pos + 1]][p[pos + 1]]);
        std::swap(p[pos], p[pos + 1]);
        std::swap(a[pos], a[pos + 1]);  
      }
    }
    else if (type == 2) {
      long long boundLeft, boundRight, x; 
      std::cin >> boundLeft >> boundRight >> x; 
      boundLeft = (1LL * boundLeft + last - 1 + n) % n + 1;
      boundRight = (1LL * boundRight + last - 1 + n) % n + 1;
      x = (1LL * x + last - 1 + n) % n + 1;
      if (boundLeft > boundRight) {
        std::swap(boundLeft, boundRight);
      }
      std::vector <long long>::iterator low = std::lower_bound(listPosition[x].begin(), listPosition[x].end(), boundLeft);
      if (low == listPosition[x].end()) {
        std::cout << 0 << std::endl;
        last = 0; 
        continue; 
      }
      std::vector <long long>::iterator up = std::upper_bound(listPosition[x].begin(), listPosition[x].end(), boundRight);
      if (up == listPosition[x].begin()) {
        std::cout << 0 << std::endl;
        last = 0;
        continue; 
      }
      up--;
      int l = low - listPosition[x].begin(); 
      int r = up - listPosition[x].begin();
      long long ans = get(x, r) - get(x, l - 1); 
      std::cout << ans << std::endl;  
      last = ans; 
    }
    else {
      long long l, r, x; 
      std::cin >> l >> r >> x;
      l = (1LL * l + last - 1 + n) % n + 1;
      r = (1LL * r + last - 1 + n) % n + 1;
      x = (1LL * x + last - 1 + n) % n + 1;
      if (l > r) {
        std::swap(l, r);
      }
      long long ans = get(x, r) - get(x, l - 1); 
      std::cout << ans << std::endl; 
      last = ans; 
    }
  }  
  return 0; 
}
