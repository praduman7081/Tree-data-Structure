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

int maxDepth(Tree *root)
{
    int depth = 0;
    if (root == NULL)
    {
        return depth;
    }

    queue<Tree *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            Tree *temp = q.front();
            q.pop();
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
        depth++;
    }

    return depth;
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

    cout << maxDepth(root);

    return 0;
}