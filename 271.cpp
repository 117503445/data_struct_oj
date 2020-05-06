#include <iostream>
#include <vector>
using namespace std;

typedef struct node
{
    int data;
    node *left, *right;
} tree;
void tree_print_in_order(node *p)
{
    if (p != NULL)
    {
        tree_print_in_order(p->left);
        cout << p->data << ' ';
        tree_print_in_order(p->right);
    }
}
node *insert(node *t, node *s)
{
    node *f, *p;
    if (t == NULL)
    {
        return s;
    }
    p = t;
    while (p != NULL)
    {
        f = p;
        if (s->data == p->data)
        {
            return t;
        }
        if (s->data < p->data)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    if (s->data < f->data)
    {
        f->left = s;
    }
    else
    {
        f->right = s;
    }
    return t;
}
node *create(vector<int> nums)
{
    node *t = NULL, *s = NULL;
    for (int i = 0; i < nums.size(); i++)
    {
        s = new node();
        s->left = s->right = NULL;
        s->data = nums[i];
        t = insert(t, s);
    }

    return t;
}
int main(int argc, char const *argv[])
{
    bool is_local_test = false;
    int n;
    vector<int> nums;
    if (is_local_test)
    {
        n = 5;
        nums.push_back(1);
        nums.push_back(6);
        nums.push_back(5);
        nums.push_back(9);
        nums.push_back(8);
    }
    else
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int t;
            cin >> t;
            nums.push_back(t);
        }
    }
    tree *t = create(nums);
    tree_print_in_order(t);
    return 0;
}
