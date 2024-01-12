#include <iostream>
long long it[800005][10]; 
int a[200005]; 
int n, numQueries; 

bool isValid(int x, int digit) {
  if (x % digit == 0) {
    return true; 
  }
  while (x > 0) {
    int r = x % 10;
    if (r == digit) {
      return true; 
    }
    x /= 10;
  }
  return false; 
}

void build(int index, int L, int R, int digit) {
  if (L == R) {
    if (isValid(L, digit) == true) {
      it[index][digit] = 2LL * a[L]; 
    }
    else {
      it[index][digit] = a[L]; 
    }
    return; 
  }
  int mid = (L + R) / 2; 
  build(2 * index, L, mid, digit);
  build(2 * index + 1, mid + 1, R, digit);
  it[index][digit] = it[2 * index][digit] + it[2 * index + 1][digit]; 
}

void update(int index, int L, int R, const int &position, const int &value, int digit) { 
  if (L > position || R < position) {
    return; 
  }
  if (L == R) {
    if (isValid(position, digit) == true) {
      it[index][digit] = 2LL * value;
    }
    else {
      it[index][digit] = value; 
    }
    return; 
  }
  int mid = (L + R) / 2; 
  update(2 * index, L, mid, position, value, digit);
  update(2 * index + 1, mid + 1, R, position, value, digit);
  it[index][digit] = it[2 * index][digit] + it[2 * index + 1][digit]; 
}

long long get(int index, int L, int R, int l, int r, int digit) {
  if (l > R || L > r) {
    return 0LL; 
  }
  if (l <= L && R <= r) {
    return it[index][digit]; 
  }
  int mid = (L + R) / 2; 
  long long valueLeft = get(2 * index, L, mid, l, r, digit);
  long long valueRight = get(2 * index + 1, mid + 1, R, l, r, digit);
  return valueLeft + valueRight; 
}

int main () {
  std::cin >> n >> numQueries;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i]; 
  } 
  for (int k = 1; k <= 9; k++) {
    build(1, 1, n, k); 
  }
  for (int query = 1; query <= numQueries; query++) {
    int type; 
    std::cin >> type; 
    if (type == 1) {
      int position, value; 
      std::cin >> position >> value; 
      for (int k = 1; k <= 9; k++) {
        update(1, 1, n, position, value, k); 
      }
    }
    else {
      int l, r, digit;
      std::cin >> l >> r >> digit; 
      std::cout << get(1, 1, n, l, r, digit) << std::endl; 
    }
  }
  return 0; 
}