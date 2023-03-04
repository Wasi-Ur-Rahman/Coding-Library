#include <bits/stdc++.h>
#define int int64_t
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
using namespace std;

const int N = 1e6 + 10;

struct Node {
  int val;
  Node *left,*right;
  Node(int x) {
    val = x;
    left = NULL;
    right = NULL;
  }
};

Node* insertBST(Node *r,int x) {
  if (r == NULL) {
    return new Node(x);
  }
  if (r->val > x) {
    r->left = insertBST(r->left,x);
  }else {
    r->right = insertBST(r->right,x);
  }
  return r;
}


Node* searchBST(Node* r,int key) {
  if (r == NULL) {
    return NULL;
  }
  if (r->val == key) {
    return r;
  }
  if (r->val > key) {
    return searchBST(r->left,key);
  }
  return searchBST(r->right,key);
}


Node* inorderSucc(Node *r) {
  Node* cur = r;
  while (cur && cur->left != NULL) {
    cur = cur->left;
  }
  return cur;
}

Node* Delete(Node* r,int key) {
  if (r->val == key) {
    if (r->left == NULL) {
      Node* temp = r->right;
      free(r);
      return temp;
    }else if (r->right == NULL) {
      Node* temp = r->left;
      free(r);
      return temp;
    }else {
      Node* temp = inorderSucc(r->left);
      r->val = temp->val;
      r->left = Delete(r->left,temp->val);
      return r;
    }
  }
  if (key < r->val) {
    r->left = Delete(r->left,key);
  }
  if (key > r->val) {
    r->right = Delete(r->right,key);
  }
  return r;
}

void inorder(Node* r) {
  if (r == NULL) return;

  inorder(r->left);
  cout << r->val << " ";
  inorder(r->right);
}

void solve() {
  Node *r = NULL;
  r = insertBST(r,5);
  insertBST(r,1);
  insertBST(r,3);
  insertBST(r,4);
  insertBST(r,2);
  insertBST(r,7);

  inorder(r);
  cout << '\n';
  Delete(r,3);
  Delete(r,1);
  inorder(r);
}

int32_t main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);

  // int t,test = 1;
  // cin >> t;

  // while (t--)
    //cout << "Case " << test++ << ": ";
    solve();
    
  return 0;
}
