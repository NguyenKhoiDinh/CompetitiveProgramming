#include <iostream> 
#include <vector>
#include <map>
#include <math.h> 
#include <utility> 
int numTest; 
int a, b, c, d; 
std::map <int, int> cnt; 
std::vector <std::pair <int, int> > save; 
int x = -1, y = -1; 

void process(int x) {
  for (int i = 2; i <= (int) std::sqrt(x); i++) {
    while (x % i == 0) {
      cnt[i]++;
      x /= i;  
    }
  }
  if (x > 1) {
    cnt[x]++;
  }  
}

long long modify(long long x, long long limit) {
  if (x > limit) {
    return -1; 
  }
  long long mul = limit / x; 
  return x * mul; 
}

void backTracking(int position, long long mul) {
  if (x != -1 && y != -1) {
    return; 
  }
  long long tmpx = modify(mul, c);
  long long rest = 1LL * a * b / mul;  
  long long tmpy = modify(rest, d);          
  if (tmpx != -1 && tmpy != -1 && tmpx > a && tmpy > b) {
    x = tmpx;
    y = tmpy; 
    return; 
  }
  if (position == (int) save.size()) {
    return;
  }
  backTracking(position + 1, mul); 
  if (save[position].second > 0 && mul * save[position].first <= c) {
    save[position].second--;
    backTracking(position, mul * save[position].first); 
    save[position].second++; 
  }
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    cnt.clear(); 
    save.clear();
    x = -1;
    y = -1;  
    std::cin >> a >> b >> c >> d; 
    process(a);
    process(b);               
    for (std::map <int, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
      save.push_back(std::make_pair(it->first, it->second)); 
    }
    backTracking(0, 1);
    std::cout << x << ' ' << y << std::endl;  
  }
  return 0; 
}