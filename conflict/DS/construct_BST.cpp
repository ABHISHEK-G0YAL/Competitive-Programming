#include <bits/stdc++.h> 
using namespace std;
class Node  {  
    public: 
    int data;  
    Node *left, *right;  
} node;
Node* newNode( int data ) {  
    Node* temp = new Node();  
    temp->data = data;  
    temp->left = temp->right = NULL;  
    return temp;  
}
Node* constructTree (int pre[], int size ) {
    int i;
    if(size==0) return NULL;
    Node* root = newNode(pre[0]);
    for(i=1;i<size;i++)
        if(pre[i]>pre[0])
            break;
    root->left = constructTree(pre+1,i-1);
    root->right = constructTree(pre+i,size-i);
    return root;
}
void printInorder (Node* node) {  
    if (node == NULL)  
        return;  
    printInorder(node->left);  
    cout<<node->data<<" ";  
    printInorder(node->right);  
}
int main () {  
    int pre[] = {10, 5, 1, 7, 40, 50};  
    int size = sizeof( pre ) / sizeof( pre[0] );
    Node *root = constructTree(pre, size);  
    cout<<"Inorder traversal of the constructed tree: \n";  
    printInorder(root);  
    return 0;  
}
