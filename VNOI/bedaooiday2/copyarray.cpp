#include <iostream>
#include <vector> 
struct node {
  node *child[2]; 
};
int n, numQueries; 
std::vector <node *> version; 
int xorValue[100005]; 
node *createNode() {
  node *ret = new node();
  ret->child[0] = NULL;
  ret->child[1] = NULL; 
  return ret; 
}

void addValue(node *&root, const int &value) {
  node *p = root; 
  for (int i = 30; i >= 0; i--) {
    int bit = ((value & (1 << i)) > 0);
    if (p->child[bit] == NULL) {
      p->child[bit] = createNode(); 
    } 
    else {
      node *newChild = createNode(); 
      *newChild = *p->child[bit]; 
      p->child[bit] = newChild; 
    }
    p = p->child[bit]; 
  }
}

int get(node *root, int value) {
  int ret = 0; 
  node *p = root; 
  for (int i = 30; i >= 0; i--) {
    int bit = ((value & (1 << i)) > 0); 
    if (p->child[bit] == NULL) {
      p = p->child[!bit];
      ret += (1 << i); 
    }
    else {
      p = p->child[bit];
    }
  }
  return ret; 
}

int main () {
  freopen("copyarray.inp", "r", stdin);
  freopen("copyarray.out", "w", stdout);
  std::cin >> n >> numQueries; 
  node *root = createNode();
  version.push_back(root);  
  for (int i = 1; i <= n; i++) {
    int value; 
    std::cin >> value; 
    addValue(version[0], value); 
  }
  xorValue[0] = 0; 
  for (int query = 1; query <= numQueries; query++) {
    int type, id, value;
    std::cin >> type >> id >> value;
    if (type == 1) {
      root = createNode(); 
      *root = *version[id]; 
      addValue(root, value ^ xorValue[id]); 
      version.push_back(root); 
      xorValue[query] = xorValue[id]; 
    }    
    else {
      xorValue[query] = xorValue[id]; 
      xorValue[query] ^= value; 
      root = createNode();
      *root = *version[id]; 
      version.push_back(root); 
    }
  }
  for (int i = 0; i <= numQueries; i++) {
    std::cout << get(version[i], xorValue[i]) << ' '; 
  }
  return 0; 
}