#include<iostream>
#include<stack>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int main()
{
    int N, M, K;
    //N是推送器上松针片的数量
    //M为小盒子存放松针片最大数量
    //K为一根松杆上能插松针片的最大数量
    cin >> N >> M >> K;
    string str, token;
    cin.ignore();
    getline(cin, str);
    stringstream ss(str);
    vector<int> vec;  //推送器上松针

    while (ss >> token)
    {
        vec.push_back(stoi(token));
    }
    int i = 0;
    //输入功能正常

    stack<int> box;
    stack<int> pine;
    //插松针
    while (!box.empty()||!vec.empty())
    {
        if (box.empty())
        {
            if (pine.empty() || vec[0] < pine.top())
            {
                pine.push(vec[0]);
                i++;
                vec.erase(vec.begin());
            }
            else
            {
                box.push(vec[0]);
                vec.erase(vec.begin());
            }
        }
        else
        {
            if (pine.empty() || box.top() < pine.top())
            {
                pine.push(box.top());
                i++;
                box.pop();
            }
            else
            {
                if (box.top() < pine.top() ||box.top( )== pine.top())
                {
                    pine.push(box.top());
                    i++;
                    box.pop();

                }
                else if (vec[0] < pine.top()|| vec[0] == pine.top())
                {
                    pine.push(vec[0]);
                    i++;
                    vec.erase(vec.begin());
                }
                else
                {
                    box.push(vec[0]);
                    vec.erase(vec.begin());
                }
            }
            if (i == K)
            {
                vector<int>temp;
                while (!pine.empty())
                {
                    temp.push_back(pine.top());
                    pine.pop();
                }
                for (int k = temp.size() - 1; k > -1; k--)
                {
                    if (k == 0)
                    {
                        cout << temp[k] << endl;
                    }
                    else
                    {
                        cout << temp[k] << " ";
                    }
                }
                i = 0;
            }
            if (box.size() == M && vec[0]>pine.top())
            {
                vector<int>temp;
                while (!pine.empty())
                {
                    temp.push_back(pine.top());
                    pine.pop();
                }
                for (int k = temp.size() - 1; k > -1; k--)
                {
                    if (k == 0)
                    {
                        cout << temp[k] << endl;
                    }
                    else
                    {
                        cout << temp[k] << " ";
                    }

                }
                i = 0;
            }
            
            
        }
    }

    vector<int>temp1;
    while (!pine.empty())
    {
        temp1.push_back(pine.top());
        pine.pop();
    }
    for (int k = temp1.size() - 1; k > -1; k--)
    {
        if (k == 0)
        {
            cout << temp1[k] << " " << endl;
        }
        else
        {
            cout << temp1[k] << " ";
        }
    }

    system("pause");
    return 0;
}

//输出后有些变量要清零
//box里面的不用
//pine松枝清零
//vec推进器里面不清零
//标识符i要清零