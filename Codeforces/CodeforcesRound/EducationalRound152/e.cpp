#include <iostream>
#include <vector> 
#include <math.h> 
#include <utility> 
int a[1000005]; 
int position[1000005]; 
int n; 
long long solve(int l, int r) {
  if (l == r) {
    return 0LL; 
  }                           
  long long ret = 0LL; 
  int mid = (l + r) / 2; 
  ret += solve(l, mid);
  ret += solve(mid + 1, r); 
  std::vector <int> aLeft, aRight; 
  for (int i = l; i <= mid; i++) {
    aLeft.push_back(a[i]); 
  }
  for (int i = mid + 1; i <= r; i++) {
    aRight.push_back(a[i]); 
  }
  int sizeLeft = (int) aLeft.size(), sizeRight = (int) aRight.size();
  std::vector <std::pair <int, int> > mLeft, mRight;
  mLeft.resize(sizeLeft);
  mRight.resize(sizeRight);
  int p = sizeLeft;
  int maxi = -1; 
  int maxElement = -1; 
  for (int i = 0; i < sizeRight; i++) {
    maxElement = std::max(maxElement, aRight[i]); 
    while (p > 0 && std::max(maxi, aLeft[p - 1]) < maxElement) {
      maxi = std::max(maxi, aLeft[p - 1]); 
      p--; 
    }
    mRight[i].first = (p == sizeLeft ? -1 : p); 
  }
  p = -1;
  maxi = -1; 
  maxElement = -1; 
  for (int i = sizeLeft - 1; i >= 0; i--) {
    maxElement = std::max(maxElement, aLeft[i]); 
    while (p + 1 < sizeRight && std::max(maxi, aRight[p + 1]) < maxElement) {
      maxi = std::max(maxi, aRight[p + 1]); 
      p++; 
    }                          
    mLeft[i].first = p; 
  }
  p = sizeLeft;
  int mini = n + 5;
  int minElement = n + 5;
  for (int i = 0; i < sizeRight; i++) {
    minElement = std::min(minElement, aRight[i]); 
    while (p > 0 && std::min(mini, aLeft[p - 1]) > minElement) {
      mini = std::min(mini, aLeft[p - 1]); 
      p--; 
    }
    mRight[i].second = (p == sizeLeft ? -1 : p); 
  }  
  p = -1;
  mini = n + 5;
  minElement = n + 5;           
  for (int i = sizeLeft - 1; i >= 0; i--) {
    minElement = std::min(minElement, aLeft[i]); 
    while (p + 1 < sizeRight && std::min(mini, aRight[p + 1]) > minElement) {
      mini = std::min(mini, aRight[p + 1]); 
      p++; 
    }
    mLeft[i].second = p; 
  }
  // Max and Min to the left
  maxi = -1; 
  mini = n + 5;
  for (int i = sizeLeft - 1; i >= 0; i--) {
    maxi = std::max(maxi, aLeft[i]); 
    mini = std::min(mini, aLeft[i]);
    if (position[mini] < position[maxi]) {
      if (mLeft[i].first != -1 && mLeft[i].second != -1) {
        int pos = std::min(mLeft[i].first, mLeft[i].second);
        ret += pos + 1;          
      }
    } 
  }
  // Max and Min to the right 
  maxi = -1;
  mini = n + 5; 
  for (int i = 0; i < sizeRight; i++) {
    maxi = std::max(maxi, aRight[i]); 
    mini = std::min(mini, aRight[i]);
    if (position[mini] < position[maxi]) {
      if (mRight[i].first != -1 && mRight[i].second != -1) {
        int pos = std::max(mRight[i].first, mRight[i].second);
        ret += sizeLeft - pos;  
      }
    } 
  }
  // Min to the left and Max to the right 
  for (int i = 0; i < sizeRight; i++) {
    int posMax = mRight[i].first; 
    int posMin = mRight[i].second;
    if (posMax == -1 || posMin == 0) {
      continue; 
    } 
    int l1 = posMax, r1 = sizeLeft - 1;
    int l2, r2;  
    if (posMin == -1) {
      l2 = 0;
      r2 = sizeLeft - 1; 
    }
    else {
      l2 = 0; 
      r2 = posMin - 1; 
    }
    if (l2 > r1 || l1 > r2) {
      continue; 
    }
    int lo = std::max(l1, l2);
    int hi = std::min(r1, r2);
    ret += hi - lo + 1;
  }
  return ret;  
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    position[a[i]] = i; 
  }
  std::cout << solve(1, n); 
  return 0; 
}