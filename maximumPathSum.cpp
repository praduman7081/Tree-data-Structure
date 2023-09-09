#include<bits/stdc++.h>
using namespace std;

/*
    TC -> O(N)
    SC -> O(N)

*/

class Tree {
   public:
   int val;
   Tree* left;
   Tree* right;
   Tree(int v){
    val  = v;
    left = NULL, right = NULL;
   }
};

int height(Tree* root, int & maxSum){
    if(root == NULL){
        return 0;
    }

    int lh = max(0,height(root->left,maxSum));
    int rh = max(0,height(root->right, maxSum));

    maxSum = max(maxSum ,(lh+rh+ root->val)); // It's update maximumSum of path

    return root->val + max(lh,rh);  // it's decided to that which path is follow
}
int maxPathSum(Tree* root){
    int maxSum = 0;
    height(root,maxSum);
    return maxSum;
}
int main()
{
    Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);
    root->right->right->left = new Tree(8);
    root->left->left->left = new Tree(9);

    cout<<maxPathSum(root);

    return 0;
}