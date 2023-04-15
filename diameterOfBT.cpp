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

int height(Tree* root,int &maxi){
    if(root== NULL){
        return 0;
    }
        int lh = height(root->left,maxi);
        int rh = height(root->right,maxi);
        maxi  = max(maxi,lh+rh);
        return 1 + max(lh, rh);
    
}

int diameter(Tree* root){
   int diameter = 0;
   height(root,diameter);
   return diameter;
   
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

    cout<<diameter(root);
    return 0;
}