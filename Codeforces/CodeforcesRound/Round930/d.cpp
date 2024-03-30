#include <iostream>
#include <vector>
#include <string>
int numTest; 
int n; 
std::string s; 
std::vector <int> left, right; 
std::vector <long long> sumLeft, sumRight; 
int findSmaller(const std::vector <int> &a, int position) {
  int ret = -1; 
  int lo = 0;
  int hi = (int) a.size() - 1; 
  while (lo <= hi) {
    int mid = (lo + hi) / 2; 
    if (a[mid] < position) {
      ret = mid; 
      lo = mid + 1; 
    }
    else {
      hi = mid - 1; 
    }
  }
  return ret; 
}   

int findLarger(const std::vector <int> &a, int position) {
  int ret = (int) a.size();
  int lo = 0;
  int hi = (int) a.size() - 1; 
  while (lo <= hi) {
    int mid = (lo + hi) / 2; 
    if (a[mid] > position) {
      ret = mid; 
      hi = mid - 1; 
    }
    else {
      lo = mid + 1; 
    }
  }
  return ret; 
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    std::cin >> s;
    left.clear();
    right.clear();
    left.push_back(0);
    right.push_back(0);
    sumLeft.clear();
    sumRight.clear(); 
    sumLeft.push_back(0LL);
    sumRight.push_back(0LL);
    for (int i = 0; i < n; i++) {
      if (s[i] == '>') {
        left.push_back(i + 1);
        sumLeft.push_back(sumLeft.back() + i + 1);  
      }
      else {
        right.push_back(i + 1); 
        sumRight.push_back(sumRight.back() + i + 1); 
      }
    }
    for (int i = 0; i < n; i++) {
      int posLeft = findSmaller(left, i + 1);
      int posRight = findLarger(right, i + 1);
      int numbLeft = posLeft;
      int numbRight = (int) right.size() - posRight;
      long long ans; 
      if (s[i] == '<') {
        if (numbLeft == 0) {
          std::cout << i + 1 << ' ';
          continue;  
        }
        else if (numbRight == 0) {
          std::cout << n + 2 + i - 2 * left[posLeft] << ' '; 
          continue; 
        }
        if (numbLeft <= numbRight) {
          ans = i + 1;
          ans -= 2LL * sumLeft[posLeft];
          ans += 2LL * (sumRight[posRight + numbLeft - 1] - sumRight[posRight - 1]);   
        }
        else {
          ans = i + n + 2; 
          ans += 2LL * (sumRight.back() - sumRight[posRight - 1]);
          ans -= 2LL * (sumLeft[posLeft] - sumLeft[posLeft - numbRight - 1]); 
        }
      }
      else {
        if (numbRight == 0) {
          std::cout << n - i << ' ';
          continue; 
        }
        else if (numbLeft == 0) {
          std::cout << 2 * right[posRight] - i - 1 << ' ';
          continue; 
        }
        if (numbLeft >= numbRight) {
          ans = n - i;
          ans += 2LL * (sumRight.back() - sumRight[posRight - 1]);
          ans -= 2LL * (sumLeft[posLeft] - sumLeft[posLeft - numbRight]);   
        }
        else {
          ans = -i - 1; 
          ans -= 2LL * sumLeft[posLeft]; 
          ans += 2LL * (sumRight[posRight + numbLeft] - sumRight[posRight - 1]); 
        }
      }
      std::cout << ans << ' ';      
    }               
    std::cout << std::endl; 
  }
  return 0; 
}