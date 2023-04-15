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

int maxDepth(Tree* root){
    if(root== NULL){
        return 0;
    }
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
    
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

    cout<<maxDepth(root);
    return 0;
}