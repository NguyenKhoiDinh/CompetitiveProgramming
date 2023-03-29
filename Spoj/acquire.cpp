#include <iostream> 
#include <algorithm> 
#include <vector> 
#include <math.h> 
#include <deque> 
const long long inf = 100000000000000007LL; 

struct rectangle {
  int width, height; 
  bool operator < (const rectangle &other) {
    return (width > other.width || (width == other.width && height < other.height)); 
  }
};
struct line {                               
  long long a, b; 
};
std::vector <rectangle> listRectangles; 
int n; 
std::vector <long long> dp; 

int main () {
  std::cin >> n; 
  for (int i = 0; i < n; i++) {
    rectangle current; 
    std::cin >> current.width >> current.height; 
    listRectangles.push_back(current); 
  }
  std::sort(listRectangles.begin(), listRectangles.end()); 
  std::vector <rectangle> tmp; 
  int maxHeight = listRectangles[0].height; 
  tmp.push_back(listRectangles[0]); 
  for (int i = 1; i < n; i++) {
    if (listRectangles[i].height > maxHeight) {
      tmp.push_back(listRectangles[i]); 
      maxHeight = listRectangles[i].height; 
    }
  }
  listRectangles = tmp; 
  n = (int) tmp.size(); 
  dp.resize(n + 2, inf); 
  dp[0] = 0; 
  return 0; 
}