#include <iostream> 
#include <set>
#include <utility>  
const int inf = 1000000007;
int numTest; 
int n, numQueries; 
int a[200005];
int it[4 * 2000005];
void update(int index, int L, int R, int position, int value) {
  if (L > position || R < position) {
    return; 
  }
  if (L == R) {
    it[index] = value;
    return;  
  }  
  int mid = (L + R) / 2; 
  update(2 * index, L, mid, position, value);
  update(2 * index + 1, mid + 1, R, position, value);
  it[index] = std::min(it[2 * index], it[2 * index + 1]);   
}
int get(int index, int L, int R, int l, int r) {
  if (l > R || L > r) {
    return inf; 
  }
  if (l <= L && R <= r) {
    return it[index]; 
  }
  int mid = (L + R) / 2; 
  int vLeft = get(2 * index, L, mid, l, r); 
  int vRight = get(2 * index + 1, mid + 1, R, l, r);
  return std::min(vLeft, vRight);  
}  
void removeElement(const std::pair <int, int> &pr, std::set <std::pair <int, int> > &Sd) {
  Sd.erase(Sd.find(pr)); 
  std::set <std::pair <int, int> >::iterator it = Sd.upper_bound(std::make_pair(pr.first, -1)); 
  if (it == Sd.end()) {
    update(1, 1, 2000000, pr.first, inf); 
  }
  else {                              
    std::pair <int, int> tmp = *it; 
    if (tmp.first != pr.first) {
      update(1, 1, 2000000, pr.first, inf); 
    }
    else {
      update(1, 1, 2000000, pr.first, tmp.second); 
    }
  }
}
void addElement(const std::pair <int, int> &pr, std::set <std::pair <int, int> > &Sd) {
  Sd.insert(pr); 
  std::set <std::pair <int, int> >::iterator it = Sd.upper_bound(std::make_pair(pr.first, -1));
  std::pair <int, int> tmp = *it;  
  update(1, 1, 2000000, pr.first, tmp.second); 
}

int main () {
  for (int i = 1; i <= 4 * 2000000; i++) {
    it[i] = inf; 
  }             
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n; 
    std::set <int> S;
    std::set <std::pair <int, int> > Sd; 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
      S.insert(a[i]); 
    }
    S.insert(0);
    for (int i = 0; i < n; i++) {
      addElement(std::make_pair(a[i + 1] - a[i] - 1, a[i] + 1), Sd);  
    }
    std::cin >> numQueries;
    for (int query = 1; query <= numQueries; query++) {
      char type;
      std::cin >> type;
      if (type == '+') {
        int x; 
        std::cin >> x; 
        std::set <int>::iterator it = S.upper_bound(x); 
        if (it == S.end()) {
          it--; 
          int v = *it; 
          int d = x - v - 1;
          addElement(std::make_pair(d, v + 1), Sd);                   
          S.insert(x);                     
        }
        else {
          int vBig = *it; 
          it--;
          int vSmall = *it; 
          int d = vBig - vSmall - 1; 
          std::pair <int, int> pr = std::make_pair(d, vSmall + 1); 
          removeElement(pr, Sd); 
          int dBig = vBig - x - 1;
          std::pair <int, int> prBig = std::make_pair(dBig, x + 1);
          addElement(prBig, Sd); 
          int dSmall = x - vSmall - 1;
          std::pair <int, int> prSmall = std::make_pair(dSmall, vSmall + 1);
          addElement(prSmall, Sd); 
          S.insert(x);     
        }
      }
      else if (type == '-') {
        int x;
        std::cin >> x;                                        
        std::set <int>::iterator it = S.end();
        it--;
        int largest = *it; 
        if (x == largest) {
          it--; 
          int vSmall = *it;
          std::pair <int, int> pr = std::make_pair(x - vSmall - 1, vSmall + 1);
          removeElement(pr, Sd); 
          S.erase(S.find(x));     
        }
        else {
          it = S.upper_bound(x); 
          int vBig = *it; 
          it--; 
          it--;
          int vSmall = *it;                                                     
          std::pair <int, int> prBig = std::make_pair(vBig - x - 1, x + 1);
          std::pair <int, int> prSmall = std::make_pair(x - vSmall - 1, vSmall + 1);
          removeElement(prBig, Sd);
          removeElement(prSmall, Sd); 
          addElement(std::make_pair(vBig - vSmall - 1, vSmall + 1), Sd); 
          S.erase(S.find(x));   
        } 
      }
      else {
        int k;
        std::cin >> k;
        std::pair <int, int> pr = std::make_pair(k, -1);
        std::set <std::pair <int, int> >::iterator it = Sd.upper_bound(pr);
        if (it == Sd.end()) {
          std::set <int>::iterator it1 = S.end();
          it1--;
          int largest = *it1;
          std::cout << largest + 1 << ' ';  
        }  
        else {
          std::cout << get(1, 1, 2000000, k, 2000000) << ' ';   
        }
      }  
    }
    for (std::set <std::pair <int, int> >::iterator it = Sd.begin(); it != Sd.end(); it++) {
      std::pair <int, int> pr = *it; 
      int len = pr.first; 
      update(1, 1, 2000000, len, inf); 
    }
    std::cout << std::endl;
  }
  return 0; 
}