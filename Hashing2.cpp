#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;

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

void getVerticalOrder(Node* root, int horD, map<int, vector<int>> &m){
    if(root == NULL){
        return;
    }
    m[horD].push_back(root->data);
    getVerticalOrder(root->left, horD-1, m);
    getVerticalOrder(root->right, horD+1, m);
}

int main(){
    Node* root = new Node(10);
    root->left = new Node(7);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(11);
    root->right->left = new Node(14);
    root->right->right = new Node(6);

    map<int, vector<int>> m;
    int horD = 0;

    getVerticalOrder(root, horD, m);

    map<int, vector<int>> :: iterator it;
    for(it=m.begin(); it!=m.end(); it++){
        for(int i=0; i<(it->second).size(); i++){
            cout << (it->second)[i] << " ";
        } cout << endl;
    }

    return 0;
}