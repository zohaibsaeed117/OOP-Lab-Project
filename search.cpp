#include <iostream>
using namespace std;
int search(string str, string substr)
{
    int length = str.size();
    int otherLength = substr.size();
    int i = 0;
    int j = 0;
    bool found = false;
    int foundIndex;
    while (str[i] != '\0')
    {
        if (str[i] == substr[j])
        {
            found = true;
            j++;
            if (j == otherLength)
            {
                break;
            }
        }
        else
        {
            found = false;
            j = 0;
        }
        i++;
    }
    if (found)
    {
        foundIndex = i - j + 1;
    }
    else
    {
        foundIndex = -1;
    }
    return foundIndex;
}