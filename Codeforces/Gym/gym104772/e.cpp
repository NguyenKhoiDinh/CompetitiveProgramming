#include <iostream> 
#include <math.h> 
#include <vector>
#include <utility> 
struct point {
  int x, y; 
};
point p[100005]; 
int x[100005], y[100005]; 
int n, numTest; 
bool isAttack(const point &a, const point &b) {
  return (a.x == b.x || a.y == b.y || std::abs(a.x - b.x) == std::abs(a.y - b.y)); 
}
bool isValid(const point &p) {
  return (p.x >= -1000000000 && p.x <= 1000000000 && p.y >= -1000000000 && p.y <= 1000000000); 
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> p[i].x >> p[i].y;  
      x[i] = p[i].x;
      y[i] = p[i].y;
    }
    int index = -1; 
    if (n == 1) {
      std::cout << "YES" << std::endl;       
      std::cout << p[1].x << ' ' << p[1].y << std::endl; 
      continue; 
    }
    int total = 0; 
    for (int i = 2; i <= n; i++) {
      if (isAttack(p[1], p[i]) == true) {
        total++; 
      }
      else {
        index = i;
        break; 
      }
    }
    if (total == n - 1) {
      std::cout << "YES" << std::endl;
      std::cout << p[1].x << ' ' << p[1].y << std::endl;
      continue; 
    }
    std::vector <std::pair <int, int> > v;
    v.push_back(std::make_pair(x[1], y[index])); 
    v.push_back(std::make_pair(x[index], y[1])); 
    if (isValid((point) {x[1] + y[1] - y[index], y[index]}) == true) {
      v.push_back(std::make_pair(x[1] + y[1] - y[index], y[index])); 
    } 
    if (isValid((point) {x[1] - y[1] + y[index], y[index]}) == true) {
      v.push_back(std::make_pair(x[1] - y[1] + y[index], y[index])); 
    }
    if (isValid((point) {x[index], x[1] + y[1] - x[index]}) == true) {
      v.push_back(std::make_pair(x[index], x[1] + y[1] - x[index])); 
    }
    if (isValid((point) {x[index], y[1] - x[1] + x[index]}) == true) {
      v.push_back(std::make_pair(x[index], y[1] - x[1] + x[index])); 
    } 


    if (isValid((point) {x[index] - y[index] + y[1], y[1]}) == true) {
      v.push_back(std::make_pair(x[index] - y[index] + y[1], y[1])); 
    } 
    if (isValid((point) {x[1], x[1] + y[index] - x[index]}) == true) {
      v.push_back(std::make_pair(x[1], x[1] + y[index] - x[index])); 
    }
    if (isValid((point) {x[1], -x[1] + y[index] + x[index]}) == true) {
      v.push_back(std::make_pair(x[1], -x[1] + y[index] + x[index])); 
    }
    if (isValid((point) {x[index] + y[index] - y[1], y[1]}) == true) {
      v.push_back(std::make_pair(x[index] + y[index] - y[1], y[1])); 
    }
    int tmp = y[index] + x[index] - y[1] + x[1]; 
    if (tmp % 2 == 0 && isValid((point) {tmp / 2, tmp / 2 + y[1] - x[1]}) == true) {
      v.push_back(std::make_pair(tmp / 2, tmp / 2 + y[1] - x[1]));
    }
    tmp = x[1] + y[1] - y[index] + x[index];
    if (tmp % 2 == 0 && isValid((point) {tmp / 2, tmp / 2 + y[index] - x[index]}) == true) {
      v.push_back(std::make_pair(tmp / 2, tmp / 2 + y[index] - x[index]));
    }
    std::vector <int> cnt;
    cnt.resize((int) v.size(), 0); 
    for (int j = 0; j < (int) v.size(); j++) {
      for (int i = 2; i <= n; i++) {
        if (i == index) {
          continue; 
        }
        if (isAttack((point) {v[j].first, v[j].second}, p[i]) == true) {
          cnt[j]++; 
        }
      }
    }
    bool ok = false; 
    for (int j = 0; j < (int) v.size(); j++) {
      if (cnt[j] == n - 2) {
        std::cout << "YES" << std::endl; 
        std::cout << v[j].first << ' ' << v[j].second << std::endl; 
        ok = true; 
        break;
      }
    }
    if (ok == false) {
      std::cout << "NO" << std::endl; 
    }
  }
  return 0; 
}