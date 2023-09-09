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

void leftView(Tree* root,vector<int> &res,int level){
    
   
    if(root == NULL) return ;
    if(res.size() == level){
        res.push_back(root->val);
    }
    if(root->left != NULL){
        leftView(root->left,res,level+1);
    }
    if(root->right != NULL){
        leftView(root->right,res, level+1);
    }
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
     leftView(root,res,0);
    for(auto it : res){
        cout<<it<<"\t";
    }

    return 0;
}