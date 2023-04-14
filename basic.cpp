#include<bits/stdc++.h>
using namespace std;

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

void preorder(Tree* root,vector<int> &vec){
    if(root == NULL){
        return;
    }
    vec.push_back(root->val);
    preorder(root->left,vec);
    preorder(root->right,vec);
}

void inorder(Tree* root,vector<int> &vec){
    if(root == NULL){
        return;
    }

    
    inorder(root->left,vec);
    vec.push_back(root->val);
    inorder(root->right,vec);
}

void postorder(Tree* root,vector<int> &vec){
     if(root == NULL){
        return;
     }
    postorder(root->left,vec);
    postorder(root->right,vec);
    vec.push_back(root->val);
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
    vector<int> vec;
    preorder(root,vec);

    for(auto it:vec){
        cout<<it<<"\n";
    }
    return 0;
}