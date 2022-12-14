#include <iostream>
#include <set>
#include <string> 
#include <iomanip>

std::multiset <int> smaller, larger; 
int numQuery; 

void modify() {
  while ((int) larger.size() > (int) smaller.size()) {
    std::multiset <int>::iterator it = larger.begin(); 
    int value = *it;
    larger.erase(it);
    smaller.insert(value); 
  }
  while ((int) smaller.size() - 1 > (int) larger.size()) {
    std::multiset <int>::iterator it = smaller.end(); 
    it--; 
    int value = *it;
    smaller.erase(it);
    larger.insert(value); 
  } 
}

int main () {
  std::cin >> numQuery; 
  for (int query = 1; query <= numQuery; query++) {
    std::string type; 
    std::cin >> type; 
    if (type == "MEDIAN") {
      if (smaller.empty() == true) {
        std::cout << 0 << std::endl; 
        continue; 
      }
      if ((int) smaller.size() > (int) larger.size()) {
        std::multiset <int>::iterator it = smaller.end();
        it--;
        std::cout << *it << std::endl; 
      }
      else {
        std::multiset <int>::iterator it1, it2; 
        it1 = smaller.end(); 
        it1--;
        it2 = larger.begin();
        int value1 = *it1; 
        int value2 = *it2; 
        std::cout << std::fixed << std::setprecision(1) << 1.0 * (value1 + value2) / 2.0 << std::endl; 
      }
    }
    else if (type == "IN") {
      int x;
      std::cin >> x;
      std::multiset <int>::iterator it = smaller.end(); 
      if (it == smaller.begin()) {
        smaller.insert(x);
        continue;   
      }
      it--;
      int value = *it;  
      if (x > value) {
        larger.insert(x); 
      }
      else {
        smaller.insert(x);
      }
      modify();   
    }
    else {
      int x;
      std::cin >> x; 
      std::multiset <int>::iterator it = smaller.find(x); 
      if (it != smaller.end()) {
        smaller.erase(it); 
      }
      else {
        it = larger.find(x); 
        larger.erase(it); 
      }
      modify(); 
    }
  }
  return 0; 
}