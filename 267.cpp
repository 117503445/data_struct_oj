#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int getStackLen(stack<int> s)
{
    int n = 0;
    while (!s.empty())
    {
        n++;
        s.pop();
    }
    return n;
}
bool validateStackSequences(int pushed[], int popped[], int n, int m)
{

    stack<int> s;
    //用于标识弹出序列的位置
    int popIndex = 0;
    for (int i = 0; i < n; i++)
    {
        s.push(pushed[i]);
        if (getStackLen(s) > m)
        {
            return false;
        }

        //如果栈不为空，且栈顶元素等于弹出序列
        while (!s.empty() && s.top() == popped[popIndex])
        {
            //出栈
            s.pop();
            //弹出序列向后一位
            popIndex++;
        }
    }

    return s.empty();
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
        int result = validateStackSequences(arrayInput, arrayOutput, n, m);
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
