#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

int count(Node* root){
    if(root == NULL){
        return 0;
    }
    return count(root->left) + count(root->right) + 1;
}

int AllNodesSum(Node* root){
    if(root == NULL){
        return 0;
    }
    return AllNodesSum(root->left)+ AllNodesSum(root->right)+root->data;
}

int calHeight(Node* root){
    if(root==NULL){
        return 0;
    }
    int lHeight = calHeight(root->left);
    int rHeight = calHeight(root->right);
    return max(rHeight, lHeight)+1;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<count(root)<<endl;
    cout<<AllNodesSum(root)<<endl;
    cout<<calHeight(root)<<endl;
    return 0;
}