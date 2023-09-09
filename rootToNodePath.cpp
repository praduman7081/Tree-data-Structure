#include <bits/stdc++.h>
using namespace std;

// O(N)
// S(N)

class Tree
{
public:
    int val;
    Tree *left;
    Tree *right;
    Tree(int v)
    {
        val = v;
        left = NULL, right = NULL;
    }
};

bool getPath(Tree* root, vector<int> &ds, int x){
    if(!root){
        return false;
    }
    
    ds.push_back(root->val);
    if(root->val == x){
        return true;
    }

    if(getPath(root->left,ds,x) || getPath(root->right, ds, x)){
        return true;
    }

    ds.pop_back();
    return false;
}

int main()
{
    Tree *root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);
    root->right->right->left = new Tree(8);
    root->left->left->left = new Tree(9);
      vector<int> res;
    getPath(root,res,8);
    for(auto it : res){
        cout<<it<<"\t";
    }

    return 0;
}