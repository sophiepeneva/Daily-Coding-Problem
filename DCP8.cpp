/*

A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.

For example, the following tree has 5 unival subtrees:

   0
  / \
 1   0
    / \
   1   0
  / \
 1   1

*/

#include<iostream>
#include<string>

using namespace std;

int univalTrees = 0;

struct Node{
    int val;
    Node* left;
    Node* right;

    Node(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

bool hasOneLevelOfUnity(Node* curr){
    if(curr->left == nullptr){
        return curr->right->val == curr->val;
    }
    if(curr->right == nullptr){
        return curr->left->val == curr->val;
    }
    return curr->val == curr->right->val && curr->val == curr->left->val;
}

bool countUnivalTrees(Node* curr){
    if(curr == nullptr){
        return false;
    }
    if(curr->left == nullptr && curr->right == nullptr){
        univalTrees++;
        return true;
    }

    bool left = countUnivalTrees(curr->left);
    bool right = countUnivalTrees(curr->right);

    if(left && right && hasOneLevelOfUnity(curr)){
         univalTrees++;
         return true;
     }
    return false;
};
 
int main(){
    Node* root = new Node(0);
    Node* left = new Node(1);
    Node* right = new Node(0);
    root->left = left;
    root->right = right;
    Node* rightLeft = new Node(1);
    Node* rightRight = new Node(0);
    Node* rightLeftLeft = new Node(1);
    Node* rightLeftRight = new Node(1);
    right->left = rightLeft;
    rightLeft -> right = rightLeftRight;
    right->right = rightRight;
    rightLeft -> left = rightLeftLeft;
    countUnivalTrees(root);
    cout<<univalTrees<<endl;
}
