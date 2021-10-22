//
//  main.cpp
//  task2
//
//  Created by Егор on 22.10.2021.
//


int WhereIsPoint(float x, float y, float rad, float center_x, float center_y);
#include <math.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

int WhereIsPoint();
using namespace std;
int main(int argc, const char* argv[]) 
{
	if (argc > 3)
	{
		cout << "Error: more than 2 arguments" << endl;
		exit(1);
	}

	ifstream in;
	ifstream in2;

	try {
		in.open(argv[1]);
		in2.open(argv[2]);
	}
	catch (int e)
	{
		cout << "Caught exception number:  " << e << endl;
		return 0;
	}

	if (!in or !in2) {
		cerr << "Error: cannot open the file!";
		exit(1);
	}

	float center_x, center_y, x, y, radius;

	in >> center_x >> center_y;
	in >> radius;
	in.close();

	while (!in2.eof())
	{
		in2 >> x >> y;
		cout << WhereIsPoint(x, y, radius, center_x, center_y) << endl;
	}

}

int WhereIsPoint(float x, float y, float rad, float center_x, float center_y)
{
	if (pow((x - center_x), 2) + pow((y - center_y), 2) < pow(rad, 2))
		return 0; //внутри
	if (pow((x - center_x), 2) + pow((y - center_y), 2) == pow(rad, 2))
		return 1; //на окружности
	else
		return 2; //за окружностью

}

