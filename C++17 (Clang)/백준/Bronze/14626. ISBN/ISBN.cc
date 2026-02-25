#include <iostream>
#include <string>

using namespace std;



int main(){
    
    string str;
    cin >> str;
    
    int idx = -1, sum = 0;
    
    for (int i = 0 ; i < 13 ; ++i)
    {
        if (str[i] == '*')
        {
            idx = i;
        }

        else
        {
            if (i % 2 == 0) sum += (str[i] - '0');
            else sum += (str[i] - '0') * 3;
        }
    }

    for (int i = 0 ; i <= 9 ; ++i)
    {
        int tmp = 0;

        if (idx % 2 == 0)
        {
            tmp = i;
        }
        else
        {
            tmp = i * 3;
        }

        if ((sum + tmp) % 10 == 0)
        {
            cout << i << endl;
            break;
        }
        
    }
    
    return 0;
}