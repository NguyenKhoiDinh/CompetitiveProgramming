#include <iostream> 
#include <set>
#include <math.h> 
#include <vector>
#include <algorithm> 
struct rectangle {
  int x1, y1, x2, y2; 
};
std::set <int> myset[1000005]; 
int n, m, k;
std::vector <int> save;
std::vector <rectangle> listRectangle;  

int main () {
  std::cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    int x1, y1, x2, y2; 
    std::cin >> x1 >> y1 >> x2 >> y2; 
    x2 += x1;
    y2 += y1;     
    listRectangle.push_back((rectangle) {x1, y1, x2, y2}); 
    save.push_back(x1 - 1);
    save.push_back(x2);
  }
  std::sort(save.begin(), save.end()); 
  long long number = 0LL; 
  long long maxValue = -1;
  long long minValue = 10000000000007LL; 
  for (int i = 0; i < (int) save.size() - 1; i++) {
    if (save[i] == save[i + 1]) {
      continue; 
    }
    int l = save[i] + 1; 
    int r = save[i + 1];
    std::set <int> S; 
    for (int j = 0; j < (int) listRectangle.size(); j++) {
      if (listRectangle[j].x1 <= l && r <= listRectangle[j].x2) {
        std::set <int>::iterator it = S.find(listRectangle[j].y1);
        if (it != S.end()) {
          S.erase(it); 
        }  
        else {
          S.insert(listRectangle[j].y1); 
        }
        it = S.find(listRectangle[j].y2 + 1);
        if (it != S.end()) {
          S.erase(it); 
        }  
        else {
          S.insert(listRectangle[j].y2 + 1); 
        }
      }
    }
    bool isOdd = false; 
    int lastValue = -1; 
    for (std::set <int>::iterator it = S.begin(); it != S.end(); it++) {
      int value = *it;
      isOdd = !isOdd;
      if (isOdd == false) {
        number += 1LL * (value - lastValue) * (r - l + 1);
        minValue = std::min(minValue, 1LL * lastValue * (n + 1) + l);
        maxValue = std::max(maxValue, 1LL * (value - 1) * (n + 1) + r);    
      }  
      else {
        lastValue = value;
      }
    }
  }
  if (number == 0) {
    std::cout << "0 -1 -1"; 
  } 
  else {
    std::cout << number << ' ' << minValue << ' ' << maxValue; 
  }
  return 0; 
}