#include <bits/stdc++.h>
using namespace std;

/*
    TC -> O(N)
    SC -> O(N)

*/
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

vector<int> inorder(Tree *root)
{
    vector<int> inorder;
    stack<Tree *> st;
    Tree *node = root;

    while (true)
    {
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty())
            {
                break;
            }
            node = st.top();
            st.pop();
            inorder.push_back(node->val);
            node = node->right;
        }
    }

    return inorder;
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
    vector<int> vec;
    vec = inorder(root);

    for (auto it : vec)
    {
        cout << it << "\n";
    }
    return 0;
}