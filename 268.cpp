#include <iostream>
#include <stack>
using namespace std;
bool isValid(string s)
{
    stack<char> sk;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        char c = s[i];
        switch (c)
        {
        case '(':
        case '[':
        case '{':
            sk.push(c);
            break;
        case ')':
        case ']':
        case '}':
            if (sk.empty())
            {
                return false;
            }
            char last = sk.top();
            if ((c == ')' && last != '(') || c == ']' && last != '[' || c == '}' && last != '{')
            {
                return false;
            }
            sk.pop();
            break;
        }
    }
    return sk.empty() == true;
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int r[n];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        r[i] = isValid(s);
    }
    for (int i = 0; i < n; i++)
    {
        if (r[i])
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}
