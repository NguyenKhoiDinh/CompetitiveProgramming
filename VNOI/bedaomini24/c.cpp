#include <bits/stdc++.h> 

using namespace std; 
struct itnode {
  long long lazy = 0LL;
  long long value = 0LL;  
  itnode *left, *right; 
};
int numQueries;
int sz = 0;
vector <itnode *> version; 
int range[100005]; 
itnode *createNode() {
  itnode *ret = new itnode(); 
  ret->lazy = 0LL;
  ret->value = 0LL; 
  ret->left = NULL;
  ret->right = NULL;
  return ret; 
}
void build(itnode *&root, int L, int R) {
  root = createNode(); 
  if (L == R) {
    return;   
  }
  int mid = (L + R) / 2; 
  build(root->left, L, mid);
  build(root->right, mid + 1, R); 
}
void lazyUpdate(itnode *&root, int L, int R) {
  if (root->lazy > 0 && L < R) {
    itnode *newLeft, *newRight; 
    newLeft = createNode();
    *newLeft = *root->left;
    newLeft->lazy += root->lazy;
    newLeft->value += root->lazy;   
    newRight = createNode();
    *newRight = *root->right;
    newRight->lazy += root->lazy;
    newRight->value += root->lazy;
    root->left = newLeft;
    root->right = newRight;   
  }
  root->lazy = 0LL; 
}
void update(itnode *&root, int L, int R, int position, const int &value) {
  lazyUpdate(root, L, R); 
  itnode *ret = createNode();
  *ret = *root;  
  if (L == R) {
    ret->value = value;
    root = ret;  
    return; 
  }
  int mid = (L + R) / 2; 
  if (position <= mid) {
    update(ret->left, L, mid, position, value); 
  }
  else {
    update(ret->right, mid + 1, R, position, value); 
  }
  root = ret; 
}
bool checkIntersect(int l1, int r1, int l2, int r2) {
  return max(l1, l2) <= min(r1, r2); 
}  
void updateValue(itnode *&root, int L, int R, int l, int r, const int value) {
  lazyUpdate(root, L, R);
  itnode *ret = createNode();
  *ret = *root;
  if (l <= L && R <= r) {
    ret->lazy += value; 
    ret->value += value; 
    root = ret;
    lazyUpdate(root, L, R);
    return;  
  }
  int mid = (L + R) / 2;
  if (checkIntersect(l, r, L, mid) == true) {
    updateValue(ret->left, L, mid, l, r, value); 
  }  
  if (checkIntersect(l, r, mid + 1, R) == true) {
    updateValue(ret->right, mid + 1, R, l, r, value); 
  }
  root = ret; 
}
int get(itnode *&root, int L, int R, int position) {
  lazyUpdate(root, L, R);
  if (L == R) {
    return root->value; 
  }
  int mid = (L + R) / 2;
  if (position <= mid) {
    return get(root->left, L, mid, position); 
  }   
  else {
    return get(root->right, mid + 1, R, position); 
  }
}

int main () {
  cin >> numQueries; 
  itnode *root;
  build(root, 1, numQueries); 
  version.push_back(root); 
  int last = 0; 
  for (int query = 1; query <= numQueries; query++) {
    int type, value; 
    cin >> type >> value;
    if (type == 1) {
      itnode *newRoot = createNode();
      *newRoot = *version.back(); 
      update(newRoot, 1, numQueries, query, value);
      version.push_back(newRoot);   
      last++; 
    }
    else if (type == 2) {
      updateValue(version.back(), 1, numQueries, 1, last, value);             
    }
    else {
      range[value] = query;   
    }
  }
  vector <long long> ans; 
  for (int i = 1; i <= last; i++) {
    int value = get(version[i], 1, numQueries, i);
    if (range[value] >= i) {
      continue; 
    } 
    ans.push_back(value); 
  }
  cout << (int) ans.size() << endl;
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i] << ' '; 
  }
  return 0; 
}