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

vector<int> postorder(Tree* root){
    vector<int> postorder;
    stack<Tree*> st,st2;
    if(root == NULL){
        return postorder;
    }
    st.push(root);
    while(!st.empty()){
     root = st.top();
     st.pop();
     st2.push(root);
      if(root->left != NULL) {
       st.push(root->left);
     } 

     if(root->right != NULL) {
       st.push(root->right);
     }
    }
    while(!st2.empty()){
        postorder.push_back(st2.top()->val);
        st2.pop();
    }
    return postorder;
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
    vec = postorder(root);

    for(auto it:vec){
        cout<<it<<"\n";
    }
    return 0;
}