#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int key;
    Node *left;
    Node *right;
    int link;
    int height;
    Node(int key) {
        this->key = key;
        this->left = NULL;
        this->right = NULL;
        this->link = 1;
        this->height = 1;
    }
};
// int height(Node *n) {
//     if (n == NULL)
//         return 0; 
//     return n->height;
// }
int link(Node *n) {
    if (n == NULL)
        return 0; 
    return n->link;
}
  
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    // y->height = max(height(y->left), height(y->right)) + 1;
    // x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    // y->height = max(height(y->left), height(y->right)) + 1;
    // x->height = max(height(x->left), height(x->right)) + 1;
    y->link += 1; 
    return y;
}
// int getBalance(Node *N) {
//     if (N == NULL)
//         return 0;
//     return height(N->left) - height(N->right);
// }
Node* insert(Node* root, int key) {
    if(root == NULL) return new Node(key);
    else if(key < root->key) root->left = insert(root->left, key);
    else if(key > root->key) root->right = insert(root->right, key);
    else return root;
    // root->height = 1 + max(height(root->left), height(root->right));
    // int balance = getBalance(root);
    // if(balance > 1 && key < root->left->key) return rightRotate(root);
    // if(balance < -1 && key > root->right->key) return leftRotate(root);
    // if(balance > 1 && key > root->left->key) {
    //     root->left = leftRotate(root->left);
    //     return rightRotate(root);
    // }
    // if(balance < -1 && key < root->right->key) {
    //     root->right = rightRotate(root->right);
    //     return leftRotate(root);
    // }
    if(root->link == link(root->left)) return rightRotate(root);
    if(root->link <= link(root->right->right)) return leftRotate(root);
    return root;
}
void preOrder(Node *root) {
    if(root == NULL) return;
    // cout << root->key << '(' << root->height << ')' << " ";
    cout << root->key << '(' << root->link << ')' << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(Node* root) {
    if(root == NULL) return;
    inOrder(root->left);
    // cout << root->key << '(' << root->height << ')' << " ";
    cout << root->key << '(' << root->link << ')' << " ";
    inOrder(root->right); 
} 
void postOrder(Node* root) {
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    // cout << root->key << '(' << root->height << ')' << " ";
    cout << root->key << '(' << root->link << ')' << " ";
}
int main() {
    Node *root = NULL;
    int n, key; cin >> n;
    while(n--) {
        cin >> key;
        root = insert(root, key);
    }
    preOrder(root); cout << endl;
    inOrder(root); cout << endl;
    postOrder(root); cout << endl;
    return 0;
}