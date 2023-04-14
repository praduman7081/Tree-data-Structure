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

void bfs(Tree *root, vector<vector<int>> &vec)
{   if(root == NULL){
      return;
   }
    queue<Tree *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
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

            level.push_back(temp->val);
        }
        vec.push_back(level);
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
    vector<vector<int>> vec;
    bfs(root, vec);

    for (int i = 0; i < vec.size(); i++)
    {
        {
            for (auto it : vec[i])
            {
                cout << it << "\t";
            }
            cout << "\n";
        }
    }
    return 0;
}