#include <iostream>
#include <vector>
#include <algorithm>
struct rectangle {
  int x1, x2, y, value; 
  bool operator < (const rectangle &other) {
    return y < other.y; 
  }
};
struct element {
  int area; 
  int cnt; 
  element () {
    area = 0;
    cnt = 0;
  } 
};
element it[4 * 30005]; 
std::vector <rectangle> listRectangles;
int n;  

void update(int index, int L, int R) {
  if (it[index].cnt > 0) {
    it[index].area = R - L + 1;                                            
  }
  else {
    if (L < R) {
      it[index].area = it[2 * index].area + it[2 * index + 1].area; 
    }
    else {
      it[index].area = 0; 
    }
  }  
}

void updateArea(int index, int L, int R, int l, int r, int value) {
  if (l > R || L > r) {
    return; 
  }  
  if (l <= L && R <= r) {
    it[index].cnt += value; 
    update(index, L, R); 
    return; 
  }                        
  int mid = (L + R) / 2; 
  updateArea(2 * index, L, mid, l, r, value);
  updateArea(2 * index + 1, mid + 1, R, l, r, value);
  update(index, L, R);  
}

int main () {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2; 
    listRectangles.push_back((rectangle) {x1, x2, y1, 1}); 
    listRectangles.push_back((rectangle) {x1, x2, y2, -1}); 
  }
  std::sort(listRectangles.begin(), listRectangles.end()); 
  int ans = 0;
  for (int i = 0; i < (int) listRectangles.size() - 1; i++) {
    updateArea(1, 0, 30000, listRectangles[i].x1, listRectangles[i].x2 - 1, listRectangles[i].value); 
    ans += (listRectangles[i + 1].y - listRectangles[i].y) * it[1].area;
  } 
  std::cout << ans;
  return 0; 
}