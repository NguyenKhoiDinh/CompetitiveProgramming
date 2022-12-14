#include <iostream>
#include <utility> 
#include <algorithm>
#include <math.h> 
#include <vector>
int n, numQuery; 
int a[100005];
std::pair <int, int> save[100005]; 
std::vector <int> it[4 * 100005]; 

void build(int index, int L, int R) {
  std::vector <int> v; 
  if (L == R) {
    v.push_back(save[L].second);
    it[index] = v; 
    return; 
  }
  int mid = (L + R) / 2; 
  build(2 * index, L, mid);
  build(2 * index + 1, mid + 1, R);
  std::vector <int> &v1 = it[2 * index]; 
  std::vector <int> &v2 = it[2 * index + 1]; 
  int i = 0;
  int j = 0; 
  while (i < (int) v1.size() && j < (int) v2.size()) {
    if (v1[i] < v2[j]) {
      v.push_back(v1[i]);
      i++; 
    }
    else {
      v.push_back(v2[j]);
      j++; 
    }
  }
  while (i < (int) v1.size()) {
    v.push_back(v1[i]);
    i++;
  }
  while (j < (int) v2.size()) {
    v.push_back(v2[j]); 
    j++; 
  }
  it[index] = v; 
}

int countNumber(int &lo, int &hi, const std::vector <int> &v) {
  int minLeft = -1;
  int maxRight = -1; 
  int l = 0;
  int r = (int) v.size() - 1; 
  while (l <= r) {
    int mid = (l + r) / 2; 
    if (v[mid] >= lo) {
      minLeft = mid; 
      r = mid - 1;
    }
    else {
      l = mid + 1; 
    }
  }
  l = 0;
  r = (int) v.size() - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (v[mid] <= hi) {
      maxRight = mid;
      l = mid + 1; 
    }
    else {
      r = mid - 1; 
    }
  }
  if (minLeft == -1 || maxRight == -1) {
    return 0; 
  }
  return maxRight - minLeft + 1; 
}

int get(int index, int L, int R, int lo, int hi, int lim) {
  if (L == R) {
    return it[index].back(); 
  }  
  int numbValids = countNumber(lo, hi, it[2 * index]);
  int mid = (L + R) / 2; 
  if (numbValids < lim) {
    return get(2 * index + 1, mid + 1, R, lo, hi, lim - numbValids);    
  }
  else {
    return get(2 * index, L, mid, lo, hi, lim); 
  }
}

int main () {
  std::cin >> n >> numQuery;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
    save[i].first = a[i];
    save[i].second = i; 
  }
  std::sort(save + 1, save + n + 1); 
  build(1, 1, n); 
  for (int query = 1; query <= numQuery; query++) {
    int lo, hi;
    std::cin >> lo >> hi;
    int position = get(1, 1, n, lo, hi, (hi - lo + 1) / 2 + (hi - lo + 1) % 2);
    std::cout << a[position] << std::endl;   
  }
  return 0; 
}