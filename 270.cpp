#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    bool local_test = 0;

    string s;
    if (local_test)
    {
        s = "abc@@de#";
    }
    else
    {

        cin >> s;
    }
    if (s.length() == 0)
    {
        cout << endl
             << 0;
    }
    s = '0' + s;
    int n = s.length();
    vector<char> leave_nodes;
    for (int i = 1; i < n - 1; i++)
    {
        //i < n-1 remove '#'
        char c = s[i];
        if (c == '@')
        {
            continue;
        }
        if (2 * i > n - 1)
        {
            leave_nodes.push_back(c);
            //leave_node++;
            continue;
        }
        bool left_exist = false;

        if (2 * i <= n - 1)
        {
            if (s[i * 2] != '@' && s[2 * i] != '#')
            {
                left_exist = true;
            }
        }
        bool right_exist = false;

        if (2 * i + 1 <= n - 1)
        {
            if (s[i * 2 + 1] != '@' && s[2 * i + 1] != '#')
            {
                right_exist = true;
            }
        }
        if (!left_exist && !right_exist)
        {
            leave_nodes.push_back(c);
        }
    }
    for (int i = 0; i < leave_nodes.size(); i++)
    {
        cout << leave_nodes[i];
        if (i != leave_nodes.size() - 1)
        {
            cout << ' ';
        }
    }

    cout << endl
         << leave_nodes.size();
    return 0;
}
