#include <iostream>
#include <stack>
using namespace std;
int judge(int arrayInput[], int arrayOutput[], int n, int m)
{
    stack<int> sk;

    int indexInput = 0;
    int indexOutput = 0;

    while (indexInput < n)
    {
        if (indexOutput >= n)
        {
            return 0;
        }

        int input = arrayInput[indexInput];
        int output = arrayOutput[indexOutput];
        // cout << "indexInput = " << indexInput << endl
        //      << "input = " << input << endl
        //      << "indexOutput = " << indexOutput << endl
        //      << "output = " << output << endl;
        if (input < output)
        {
            //cout << "push " << input << endl;

            sk.push(input);

            if (sk.size() > m)
            {
                return 0;
            }

            indexInput++;
        }
        else if (input == output)
        {
            //int top = sk.top();

            sk.push(input);
            if (sk.size() > m)
            {
                return 0;
            }
            sk.pop();

            //cout << "push pop " << input << endl;
            indexInput++;
            indexOutput++;
        }
        else if (input > output)
        {
            //int top = sk.top();

            if (sk.empty())
            {
                return 0;
            }

            sk.pop();
            //cout << "pop " << top << endl;
            indexOutput++;
        }
        //cout << endl;
    }

    while (indexOutput < n)
    {
        if (sk.empty())
        {
            return 0;
        }
        int top = sk.top();

        int output = arrayOutput[indexOutput];
        //cout << output << "---" << top << endl;

        if (top != output)
        {
            return 0;
        }
        sk.pop();
        indexOutput++;
    }

    return 1;
}
int main(int argc, char const *argv[])
{
    int m, n, k;
    cin >> m >> n >> k;
    int arrayInput[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arrayInput[i];
    }
    for (int i = 0; i < k; i++)
    {
        int arrayOutput[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arrayOutput[j];
        }
        int result = judge(arrayInput, arrayOutput, n, m);
        if (result == 0)
        {
            cout << "NO" << endl;
        }
        else if (result == 1)
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}
