#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int judgeIsHuiwen(vector<char> input)
{
    int length = input.size();
    int end = length;

    if(length == 0)
        return -1;   //too short
    else
    {
        for(int i = 0; i < length; i++)
        {
            end--;
            if(input.at(i) != input.at(end))
            {
                return 0;
            }
            else
                continue;
        }
    }
    return 1;
}

int main()
{
    cout<<"Type the string"<<endl;
    cout<<"Press 'Enter' to get the result"<<endl;
    cout<<"Press 'Space' to exit: "<<endl;
    vector<char> input;
    char ch;

    while(1)
    {

        do
        {
            scanf("%c", &ch);
            input.push_back(ch);
        }while( ch != '\n');

        input.pop_back(); //last is '\n'

        if(input.size() >= 1 && input.at(input.size()-1) == ' ')
            break;

        if(judgeIsHuiwen(input) == 1)
        {
            cout<<"is Huiwen"<<endl;
        }
        else if(judgeIsHuiwen(input) == 0)
        {
            cout<<"is NOT Huiwen"<<endl;
        }
        else
        {
            cout<<"input ZERO"<<endl;
        }

        input.clear();

    }
}


