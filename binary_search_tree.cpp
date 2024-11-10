#include <iostream>
using namespace std;

struct n1 {
    int key;
    n1* left;
    n1* right;

    n1(int k) {
        key = k;
        left = right = nullptr;
    }
};

n1* insert(n1* node, int key) {
    if (node == nullptr) {
        return new n1(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }

    return node;
}

n1* search(n1* node, int key) {
    if (node == nullptr || node->key == key) {
        return node;
    }

    if (key < node->key) {
        return search(node->left, key);
    }

    return search(node->right, key);
}

void inorder(n1* node) {
    if (node != nullptr) {
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }
}
void preorder(n1* node){
    if(node!=nullptr){
        cout<<node->key<<" ";
        preorder(node->left);
        preorder(node->right);

    }
}
void postorder(n1* node){
    if(node!=nullptr){
        postorder(node->left);
        postorder(node->right);
        cout<<node->key<<" ";
    }
}

int main() {
    n1* root = nullptr;
    int arr[8];
    cout << "Enter the elements to insert in the tree:" << endl;

    for (int i = 0; i < 8; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 8; i++) {
        root = insert(root, arr[i]);
    }

    cout << "In-order traversal of the BST: ";
    inorder(root);
    cout << endl;
        cout << "Pre-order traversal of the BST: ";
    preorder(root);
    cout << endl;
    
    cout<<"Post-order traversal of the BST: ";
    postorder(root);
    cout<<endl;
    return 0;
}