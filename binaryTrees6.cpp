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

int calHeight(Node* root){
    if(root == NULL){
        return 0;
    }
    return max(calHeight(root->left), calHeight(root->right)) + 1;
}

int calDiameter(Node* root){
    if(root == NULL){
        return 0;
    }

    int lHeight = calHeight(root->left);
    int rHeight = calHeight(root->right);
    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = calDiameter(root->left);
    int rDiamater = calDiameter(root->right);

    return max(currDiameter, max(lDiameter, rDiamater));
}

int Diameter(Node* root, int* height){
    if(root == NULL){
        *height = 0;
        return 0;
    }
    int lh = 0;
    int rh = 0;
    int lDia = Diameter(root->left, &lh);
    int rDia = Diameter(root->right, &rh);

    int currDia = lh + rh + 1;
    *height = max(lh, rh) + 1;
    return max(currDia, max(lDia, rDia));
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<calDiameter(root)<<endl;
    int height = 0;
    cout<<Diameter(root, &height)<<endl;
    return 0;
}