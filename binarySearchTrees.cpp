#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// definition of Binary Search Trees
struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Implementation of Binary Search Trees
Node* insertBST(Node* root, int val){
    if(root == NULL){
        return new Node(val);
    }

    if(val < root->data){
        root->left = insertBST(root->left, val);
    } else{
        root->right = insertBST(root->right, val);
    }

    return root;
}

// Traversal in Binary Search Trees
void inorder(Node* root){
    if(root == NULL){
        return; 
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// main() function
int main(){
    Node *root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);

    inorder(root);
    cout << endl;
    return 0;
}