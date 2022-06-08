#include<iostream>
#include<vector>
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

vector<Node*> constructTrees(int start, int end){
    vector<Node*> trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }

    for(int i=start; i<=end; i++){
        vector<Node*> leftSubtrees = constructTrees(start, i-1);
        vector<Node*> rightSubtrees = constructTrees(i+1, end);

        for(int j=0; j<leftSubtrees.size(); j++){
            Node* leftS = leftSubtrees[j];
            for(int k=0; k<rightSubtrees.size(); k++){
                Node* rightS = rightSubtrees[k];
                Node* node = new Node(i);
                node->left = leftS;
                node->right = rightS;
                trees.push_back(node);
            }
        }
    }
    return trees;
}

void display(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    display(root->left);
    display(root->right);
}

int main(){
    vector<Node*> totalTrees = constructTrees(1, 4);
    for(int i=0; i<totalTrees.size(); i++){
        cout<<(i+1)<<": ";
        display(totalTrees[i]);
        cout<<endl;
    }
    return 0;
}