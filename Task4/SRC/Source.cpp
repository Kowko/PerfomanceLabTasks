//
//  main.cpp
//  task4
//
//  Created by Егор on 21.10.2021.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, const char* argv[]) {
    // insert code here...
    if (argc > 2)
    {
        cout << "Error: more than 1 arguments" << endl;
        exit(1);
    }
    ifstream in;
    //in.open ("/Users/Bazzinga/Desktop/u-net-brain-tumor-master/task4/task4/nums");
    try{
    in.open(argv[1]);
    }
    catch (int e)
    {
        cout << "Caught exception number:  " << e << endl;
        return 0;
    }
    if (!in) {
        cerr << "Error: cannot open the file!";
        exit(1);
    }
    vector<int> vec;
    int num;
    while (!in.eof()) {
        in >> num;
        if (num <0)
        {
        vec.push_back(num);
        }
    }
    in.close();
    //sort (vec.begin(), vec.end(), myobject);
    sort(vec.begin(), vec.end());
    size_t size = vec.size();
    int median = 0;
    if ((size % 2) == 1)
    {
        median = vec[((size - 1) / 2)];
    }
    else
    {
        median = vec[size / 2];
    }
    num = 0;
    for (int i = 0; (size_t)i < size; i++)
    {
        if (vec[i] < median)
        {
            while (vec[i] != median)
            {
                vec[i]++;
                num++;
            }
        }
        else
        {
            while (vec[i] != median)
            {
                vec[i]--;
                num++;
            }
        }
    }
    cout << num;



    return 0;
}