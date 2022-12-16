#include <iostream>
#include <algorithm>
#include <vector>
std::vector <int> listPins; 
int n, numQuery; 

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin >> n >> numQuery;
  for (int i = 1; i <= n; i++) {
    int value; 
    std::cin >> value; 
    int tmp = value; 
    if (tmp == 0) {
      continue;
    }
    if (tmp % 2 == 0) {
      while (tmp % 2 == 0) {
        tmp /= 2; 
      }
    }
    else if (tmp % 3 == 0) {
      while (tmp % 3 == 0) {
        tmp /= 3; 
      }
    }
    else if (tmp % 5 == 0) {
      while (tmp % 5 == 0) {
        tmp /= 5; 
      }
    }
    if (tmp == 1) {
      listPins.push_back(value); 
    }
  }
  std::sort(listPins.begin(), listPins.end()); 
  for (int query = 1; query <= numQuery; query++) {
    int low, high;
    std::cin >> low >> high; 
    if (listPins.empty() == true) {
      std::cout << 0 << std::endl;
      continue; 
    }
    int lo = 0;
    int hi = (int) listPins.size() - 1;
    int minLeft = -1, maxRight = -1; 
    while (lo <= hi) {
      int mid = (lo + hi) / 2; 
      if (listPins[mid] >= low) {
        minLeft = mid;
        hi = mid - 1; 
      }
      else {
        lo = mid + 1; 
      }
    }
    lo = 0; 
    hi = (int) listPins.size() - 1; 
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (listPins[mid] <= high) {
        maxRight = mid;
        lo = mid + 1;
      }
      else {
        hi = mid - 1; 
      }
    }
    if (minLeft != -1 && maxRight != -1) {
      std::cout << maxRight - minLeft + 1 << std::endl; 
    }
    else {
      std::cout << 0 << std::endl;
    }
  }
  return 0; 
}