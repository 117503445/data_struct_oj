//Author:117503445
//date:2020-03-17 00:34
//email:t117503445@gmail.com

#include <iostream>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        list<int> l;
        int size;
        cin >> size;
        for (int j = 0; j < size; j++)
        {
            int t;
            cin >> t;
            l.push_back(t);
        }

        l.reverse();

        list<int>::iterator iter;
        int k = 0;
        for (iter = l.begin(); iter != l.end(); iter++)
        {
            cout << *iter;
            if (k < size)
            {
                cout << ' ';
            }
            k++;
        }
        cout << '\n';
    }
    return 0;
}
