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

vector<int> preorder(Tree* root){
    vector<int> preorder;
    stack<Tree*> st;
    if(root == NULL){
        return preorder;
    }
    st.push(root);
    while(!st.empty()){
     root = st.top();
     st.pop();
     preorder.push_back(root->val);
     if(root->right != NULL) {
       st.push(root->right);
     }
     
     if(root->left != NULL) {
       st.push(root->left);
     } 

    }

    return preorder;
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
    vec = preorder(root);

    for(auto it:vec){
        cout<<it<<"\n";
    }
    return 0;
}