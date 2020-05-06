//Author:117503445
//date:2020-03-17 00:27
//email:t117503445@gmail.com

#include <iostream>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    list<int> l;
    int len;
    int insertNum;
    cin >> len >> insertNum;

    for (int i = 0; i < len; i++)
    {
        int t;
        cin >> t;
        l.push_front(t);
    }

    l.push_back(insertNum);

    l.sort();

    list<int>::iterator iter;
    int i = 0;
    for (iter = l.begin(); iter != l.end(); iter++)
    {
        cout << *iter;
        if (i < len)
        {
            cout << ' ';
        }
        i++;
    }
    return 0;
}
