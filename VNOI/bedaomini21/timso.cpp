#include <iostream>
#include <vector>
std::vector <long long> a; 

std::vector <int> splitNumber(long long x) {
  std::vector <int> ret;
  ret.resize(10, 0); 
  while (x > 0) {
    int r = x % 10;
    x /= 10;
    ret[r]++; 
  }
  return ret; 
}

void process() {
  long long x = 1; 
  while (true) {
    std::vector <int> cnt1 = splitNumber(x);
    std::vector <int> cnt2 = splitNumber(x * x);
    bool check = true;
    for (int i = 0; i <= 9; i++) {
      if (cnt1[i] + cnt2[i] > 2) {
        check = false;
        break;
      }
    }  
    if (check == true) {
      a.push_back(x); 
    }
    if (x > 4000000) {
      break;
    }
    x++; 
  }
}

int main () {
  process(); 
  int numTest;
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    int n;
    std::cin >> n;
    std::vector <long long>::iterator it = std::lower_bound(a.begin(), a.end(), n);
    if (it == a.end()) {
      std::cout << "-1" << std::endl;
      continue; 
    } 
    std::cout << *it << std::endl;
  }
  return 0; 
}