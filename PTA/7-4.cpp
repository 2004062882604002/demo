#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string input;
    getline(cin, input);
    stack<int> s;
    stringstream ss(input);
    string token;

    while (ss >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (s.size() < 2)
            {
                cout << "Expression Error: " << s.top() << endl;
                return 0;
            }

            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();

            int result;

            if (token == "+")
            {
                result = a + b;
            }
            else if (token == "-")
            {
                result = a - b;
            }
            else if (token == "*")
            {
                result = a * b;
            }
            else
            {
                if (b == 0)
                {
                    cout << "Error: " << a << "/0" << endl;
                    return 0;
                }
                result = a / b;
            }

            s.push(result);
        }
        else if(token=="#")
        {
            break;
        }
        else
        {
            int num = stoi(token);
            s.push(num);
        }
    }

    if (s.size() == 1)
    {
        cout << s.top() << endl;
    }
    else
    {
        cout << "Expression Error: " << s.top() << endl;
    }
    system("pause");
    return 0;
}