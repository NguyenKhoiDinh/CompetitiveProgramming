#include <iostream> 
#include <string> 
unsigned long long power2[100005]; 
unsigned long long sum[100005]; 
std::string s; 
int numQueries, n;   
struct itnode {
  unsigned long long sum = 0LL; 
  bool isReverse;
  itnode() {
    sum = 0LL;
    isReverse = false;     
  } 
}; 
itnode it[4 * 100005]; 

void init() {
  power2[0] = 1LL; 
  sum[0] = 1LL; 
  for (int i = 1; i <= n; i++) {
    power2[i] = power2[i - 1] * 10LL;
    sum[i] = sum[i - 1] + power2[i];  
  }
}

void build(int index, int L, int R) {
  if (L == R) {
    it[index].sum = power2[L] * (s[L - 1] - '0');
    return;  
  }
  int mid = (L + R) / 2; 
  build(2 * index, L, mid);
  build(2 * index + 1, mid + 1, R);
  it[index].sum = it[2 * index].sum + it[2 * index + 1].sum;  
}

void lazyUpdate(int index, int L, int R) {
  if (it[index].isReverse == true && L < R) {
    int mid = (L + R) / 2;
    if (it[2 *index].isReverse == false) {
      it[2 * index].isReverse = true;
    }
    else {
      it[2 * index].isReverse = false; 
    }
    it[2 * index].sum = sum[mid] - sum[L - 1] - it[2 * index].sum;
    if (it[2 *index + 1].isReverse == false) {
      it[2 * index + 1].isReverse = true;
    }
    else {
      it[2 * index + 1].isReverse = false; 
    }
    it[2 * index + 1].sum = sum[R] - sum[mid] - it[2 * index + 1].sum;   
  }
  it[index].isReverse = false; 
}                           

void update(int index, int L, int R, int l, int r) {
  if (l <= L && R <= r) {
    if (it[index].isReverse == false) {
      it[index].isReverse = true;
    }
    else {
      it[index].isReverse = false;
    }
    it[index].sum = sum[R] - sum[L - 1] - it[index].sum;  
    lazyUpdate(index, L, R); 
    return; 
  }
  lazyUpdate(index, L, R); 
  if (l > R || L > r) {
    return; 
  }
  int mid = (L + R) / 2; 
  update(2 * index, L, mid, l, r);
  update(2 * index + 1, mid + 1, R, l, r);
  it[index].sum = it[2 * index].sum + it[2 * index + 1].sum;  
}

unsigned long long get(int index, int L, int R, int l, int r) {
  lazyUpdate(index, L, R); 
  if (l > R || L > r) {
    return 0LL; 
  }
  if (l <= L && R <= r) {
    return it[index].sum;
  }
  int mid = (L + R) / 2; 
  unsigned long long valueLeft = get(2 * index, L, mid, l, r);
  unsigned long long valueRight = get(2 * index + 1, mid + 1, R, l, r); 
  return valueLeft + valueRight; 
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  std::cin >> s; 
  n = (int) s.size();
  init(); 
  build(1, 1, n); 
  std::cin >> numQueries; 
  for (int query = 1; query <= numQueries; query++) {
    int type;
    std::cin >> type; 
    if (type == 1) {
      int l, r;
      std::cin >> l >> r; 
      update(1, 1, n, l, r); 
    }                                          
    else {
      int l1, r1, l2, r2;
      std::cin >> l1 >> r1 >> l2 >> r2; 
      if ((r1 - l1 + 1) != (r2 - l2 + 1)) {
        std::cout << "NO" << std::endl; 
        continue; 
      }
      unsigned long long value1 = get(1, 1, n, l1, r1); 
      unsigned long long value2 = get(1, 1, n, l2, r2); 
      value1 *= power2[l2]; 
      value2 *= power2[l1]; 
      std::cout << (value1 == value2 ? "YES" : "NO") << std::endl;
    }
  }
  return 0; 
}