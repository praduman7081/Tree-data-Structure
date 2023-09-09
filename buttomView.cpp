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

vector<int> topView(Tree* root){
    vector<int> res;
    if(root == NULL) return res;
    map<int,int> mpp;
    queue<pair<Tree*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Tree* node = it.first;
        int line = it.second;
        mpp[line] = node->val;
       if(node->left != NULL) q.push({node->left,line-1});
       if(node->right != NULL) q.push({node->right, line+1});
    
    }

    for(auto it: mpp){
        res.push_back(it.second);
    }
    return res;
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

    vector<int> ans =  topView(root);
    for(auto it : ans){
        cout<<it<<"\t";
    }

    return 0;
}