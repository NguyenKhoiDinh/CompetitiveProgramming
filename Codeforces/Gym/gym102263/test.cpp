#include <iostream>
#include <set> 
#include <utility>

int main () {
  std::set <int> S;
  std::set <int> Sstep;  
  int n, m, r, c; 
  std::cin >> n >> m >> r >> c; 
  for (int sx = 0; sx < n; sx++) {
    for (int sy = 0; sy < m; sy++) {
      int x = sx, y = sy;
      int sum = 0;
      int step = 0; 
      std::set <std::pair <int, int> > check;
      while (true) {
        if (check.find(std::make_pair(x, y)) != check.end()) {
          break; 
        }
        check.insert(std::make_pair(x, y));
        sum += (x + 1) * m + y + 1;  
        step++; 
        x += r;
        x %= n; 
        y += c; 
        y %= m; 
      }
      S.insert(sum);
      Sstep.insert(step);    
    }
  }
  if ((int) S.size() == 1) {
    std::cout << "CORRECT" << std::endl; 
  }
  else {
    std::cout << (int) S.size() << std::endl;
    std::cout << "INCORRECT" << std::endl;
  }
  if ((int) Sstep.size() == 1) {
    std::cout << "OK    " << *Sstep.begin() << std::endl; 
  }
  else {
    std::cout << "NO OK" << std::endl;
  }
  return 0; 
}