//Author:117503445
//date:2020-03-17 00:21
//email:t117503445@gmail.com

#include <iostream>
#include <list>
#include <string>

using namespace std;

struct data
{
    string name;
    int id;
    char sex;
};
int id;
int main(int argc, char const *argv[])
{
    list<struct data> stus;

    while (true)
    {
        struct data d;
        cin >> d.name;
        if (d.name.compare("#") == 0)
        {
            break;
        }
        cin >> d.id >> d.sex;
        stus.push_back(d);
    }

    cin >> id;

    int lastSize = stus.size();

    //not available before C++11
    //fuck xdoj use C++98

    //stus.remove_if([](struct data d) { return d.id == id; });

    list<struct data>::iterator iter;
    for (iter = stus.begin(); iter != stus.end(); iter++)
    {
        if (iter->id == id)
        {
            iter = stus.erase(iter);
        }
    }

    if (stus.size() == lastSize)
    {
        cout << "No";
    }
    else
    {

        for (iter = stus.begin(); iter != stus.end(); iter++)
        {
            cout << iter->name << ' ' << iter->id << ' ' << iter->sex << endl;
        }
    }

    return 0;
}
