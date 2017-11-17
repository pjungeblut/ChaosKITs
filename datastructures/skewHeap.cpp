// Skew Heap, verschmelzbare Priority Queue.
// Laufzeit: Merging, Inserting, DeleteMin: O(log(n)) amortisiert
struct node{
  int key;
  node *lc, *rc;
  node(int k) : key(k), lc(0), rc(0) {}
} *root = 0; 
int size = 0;

node* merge(node *x, node *y) {
  if (!x) return y;
  if (!y) return x;
  if (x->key > y->key) swap(x,y);
  x->rc = merge(x->rc, y);
  swap(x->lc, x->rc);
  return x;
}

void insert(int x) { root = merge(root, new node(x)); size++; }

int delmin() {
  if (!root) return -1;
  int ret = root->key;
  node *troot = merge(root->lc, root->rc);
  delete root;
  root = troot;
  size--;
  return ret;
}
