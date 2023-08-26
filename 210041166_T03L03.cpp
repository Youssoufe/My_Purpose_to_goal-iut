#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
    string arr, number;
    int n, temp, random = 1;

    getline(cin, arr);
    arr[arr.size()] = ' ';
    arr[arr.size()+1] = '\0';
    cin >> n;

    for (int I = 0, J = 0; I <= arr.size(); I++, J++)
    {
        if (arr[I] != ' ')
        {
            number[J] = arr[I];
        }
        else
        {
            temp = stoi(number);

            while(temp>random)
            {
                temp == random ? cout << "Push " : cout << "Push Pop ";
            random++;
            }

            if(temp == random)
                cout << "Push ";
            random++;
            J = -1;
        }
    }
    return 0;
}
class Solution {
public:
    vector<string> buildArray(vector<int>& arr, int n) {
        string number;
        vector <string> fucku;
        int temp, random = 1;

        arr[arr.size()] = ' ';
        arr[arr.size() + 1] = '\0';


        for (int I = 0, J = 0; I <= arr.size(); I++, J++)
    {
        if (arr[I] != ' ')
        {
            number[J] = arr[I];
        }
        else
        {
            temp = stoi(number);

            while(temp>random)
            {
                if(temp == random)
                {
                    fuck.push_back("Push");
                }
                else
                {
                    fucku.push_back("Push");
                    fucku.push_back("Pop");
                }
            random++;
            }

            if(temp == random)
                fucku.push_back("Push");
            random++;
            J = -1;
        }
        }
        return fucku;
    }
};
