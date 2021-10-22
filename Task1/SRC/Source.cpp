//
//  main.cpp
//  task1
//
//  Created by Егор on 22.10.2021.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(int agrc, const char* argv[]) {
    if (agrc == 1)
    {
        cout << "Error" << endl;
        exit(1);
    }
    stringstream strValue, strValue2;
    strValue << argv[1];
    int n, m;
    strValue >> n;
    strValue2 << argv[2];
    strValue2 >> m;
    if (m < 1)
    {
        cout << "Error: canno choose path when m < 0" << endl;
        exit(1);
    }
    string total = "1";
    int i = -1;
    while (i != 0)
    {
        if (i == -1)
        {
            i = 0;
        }

        i = i + m;

        while (i >= n)
        {
            i = i - n;
        }

        total = total + to_string(i + 1);

    }
    cout << total;

    return 0;
}
