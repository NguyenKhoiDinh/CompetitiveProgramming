#include <iostream> 
#include <vector>
#include <math.h>
#include <utility> 
#include <map>
#include <algorithm>
#include <tuple> 
const long long inf = -1000000000000000007LL; 
int numTest; 
struct element {
  std::vector <long long> value; 
  element() {
    value.resize(2);
    value[0] = value[1] = inf; 
  }
};
std::vector <element> it; 

void update(int index, int L, int R, int position, const long long &v, int direction) {
  if (position < L || position > R) {
    return; 
  }
  if (position <= L && R <= position) {
    it[index].value[direction] = std::max(it[index].value[direction], v);
    return; 
  }
  int mid = (L + R) / 2; 
  update(2 * index + 1, L, mid, position, v, direction); 
  update(2 * index + 2, mid + 1, R, position, v, direction); 
  it[index].value[direction] = std::max(it[2 * index + 1].value[direction], it[2 * index + 2].value[direction]); 
} 

long long get(int index, int L, int R, int l, int r, int direction) {
  if (l > R || L > r) {
    return inf; 
  }
  if (l <= L && R <= r) {
    return it[index].value[direction]; 
  }
  int mid = (L + R) / 2; 
  long long value1 = get(2 * index + 1, L, mid, l, r, direction);
  long long value2 = get(2 * index + 2, mid + 1, R, l, r, direction);
  return std::max(value1, value2); 
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": "; 
    std::vector <std::tuple <int, int, int> > save; 
    int n, E; 
    std::cin >> n >> E;
    save.push_back(std::make_tuple(-1, -1, -1)); 
    for (int i = 1; i <= n; i++) {
      int x, y, cost;
      std::cin >> x >> y >> cost; 
      save.push_back(std::make_tuple(y, x, cost));   
    }
    std::sort(save.begin(), save.end());
    std::vector <std::vector <std::pair <int, int> > > a;
    std::vector <std::pair <int, int> > v; 
    for (int i = 1; i < (int) save.size(); i++) {
      if (std::get <0> (save[i]) != std::get <0> (save[i - 1])) {
        if (v.empty() == false) {
          a.push_back(v); 
        }
        v.clear(); 
      }
      v.push_back(std::make_pair(std::get <1> (save[i]), std::get <2> (save[i]))); 
    }
    if (v.empty() == false) {
      a.push_back(v); 
    }
    it.clear();
    it.resize(4 * 100005 + 100);
    update(0, 0, 100001, 0, 0LL, 1);
    for (int j = (int) a.size() - 1; j >= 0; j--) {
      std::vector <std::pair <int, int> > &v = a[j];
      std::vector <std::vector <long long> > tmp;
      tmp.resize(2);
      int sz = (int) v.size();
      tmp[0].resize(sz, inf); 
      tmp[1].resize(sz, inf);
      for (int i = 0; i < sz; i++) {
        int position = v[i].first;
        int cost = v[i].second;            
        tmp[0][i] = std::max(tmp[0][i], it[0].value[1] - E + cost); 
        tmp[0][i] = std::max(tmp[0][i], get(0, 0, 100001, position, 100001, 0) + cost); 
        tmp[0][i] = std::max(tmp[0][i], get(0, 0, 100001, 0, position, 1) - 2LL * E + cost); 
        tmp[1][i] = std::max(tmp[1][i], it[0].value[0] - E + cost);
        tmp[1][i] = std::max(tmp[1][i], get(0, 0, 100001, 0, position, 1) + cost);
        tmp[1][i] = std::max(tmp[1][i], get(0, 0, 100001, position, 100001, 0) - 2LL * E + cost);   
      }                                       
      long long sum = tmp[1][0]; 
      for (int i = 1; i < sz; i++) {
        int position = v[i].first;
        int cost = v[i].second; 
        sum = std::max(sum + cost, tmp[1][i]); 
        tmp[1][i] = std::max(tmp[1][i], sum); 
      }
      sum = tmp[0][sz - 1]; 
      for (int i = sz - 2; i >= 0; i--) {
        int position = v[i].first;
        int cost = v[i].second; 
        sum = std::max(sum + cost, tmp[0][i]); 
        tmp[0][i] = std::max(tmp[0][i], sum); 
      }
      for (int i = 0; i < sz; i++) {
        int position = v[i].first;
        update(0, 0, 100001, position, tmp[1][i], 1);
        update(0, 0, 100001, position, tmp[0][i], 0);
      }
    }
    std::cout << std::max(it[0].value[0], it[0].value[1]) << std::endl;     
  }
  return 0; 
}