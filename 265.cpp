#include <iostream>

//Author:117503445
//date:2020-03-17 00:34
//email:t117503445@gmail.com
#include <queue>
#include <iostream>
using namespace std;
void queryPrintFromFrontToEnd(queue<int> q)
{
    cout << endl;
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    cout << endl;
}
void queryPrintFromFrontToEndFmt(queue<int> q)
{
    int n = q.size();
    for (int i = 0; i < n; i++)
    {
        cout << q.front();
        if (i != n - 1)
        {
            cout << " ";
        }

        q.pop();
    }
}
int queryFindMinValue(queue<int> q, int lastmin)
{
    int min = -1000;
    while (!q.empty())
    {
        if (min == -1000 && q.front() > lastmin)
        {
            min = q.front();
        }
        else if (q.front() < min && q.front() > lastmin)
        {
            min = q.front();
        }
        q.pop();
    }
    return min;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    queue<int> q1;
    int t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        q1.push(t);
    }
    queue<int> q2;

    int min = -1000;
    while (q2.size() != n)
    {
        //queryPrintFromFrontToEnd(q1);
        //cout << min << endl;
        min = queryFindMinValue(q1, min);
        q2.push(min);
    }

    queryPrintFromFrontToEndFmt(q2);

    return 0;
}
