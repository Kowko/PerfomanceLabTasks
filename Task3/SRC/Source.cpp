//
//  main.cpp
//  task3
//
//  Created by ���� on 22.10.2021.
//  �� ����� ���� � json ����� ���� �� �� java.
//  

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;
int main(int argc, const char* argv[])
{
	if (argc > 3)
	{
		cout << "Error: more than 2 arguments" << endl;
		exit(1);
	}

	ifstream in; //������ ��� in2 (values)
	ifstream in2; //��������� values �� in

	try {
		in.open(argv[1]);
		in2.open(argv[2]);
		//in.open("values.json");
		//in2.open("tests.json");
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
	int value, start, end;
	int id = 0;
	string idVal, idTest, substringVal, StartTestsString, TestsString, StringToSearch;
	bool startB = true;
	
	string str((istreambuf_iterator<char>(in2)), istreambuf_iterator<char>());
	string strVal((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
	try
	{
		str.find("id");
	}
	catch (int e)
	{
		cout << "Error: cannot find ID, probably values.json is an empty file" << endl;
		return 0;
	}
	while (id != -1) //���� ���� ���� ID
	{
		id = str.find("id"); //������� ID
		start = str.find("id");
		end = str.find(",");
		if (end < start)
		{
			str = str.substr(start);
			start = 0;
		}
		end = str.find(",");
		end = end - 5;
		idVal = str.substr((start + 5), (end - start));
	
		if (startB)
		{
			startB = false;
			str = str.substr(id); //�������� ������
		}

		value = str.find("value");
		str = str.substr(value);
		start = 4;
		end = str.find(",") - 10;
		if (end < 0)
		{
			end = 10;
		}
		substringVal = str.substr((start + 5), (end - start));
		id = str.find("id");

		// ��� ���������� ������ �� ������ ������

		StringToSearch = "\"id\": " + idVal + ","; //����� ������� id
		start = strVal.find(StringToSearch);

		if (start >= 0) //���� ������� � ������ �������
		{

			StartTestsString = StartTestsString + strVal.substr(0, start); //�������� �������
			strVal = strVal.substr(start);
			start = 0;

			end = strVal.find("value");
			end = end +9;

			StartTestsString = StartTestsString + strVal.substr(0, end) + substringVal;
			strVal = strVal.substr(end);

		}
		else
		{
			start = StartTestsString.find(StringToSearch);
			if (start >= 0) //���� ��������� � �����
			{
				
				TestsString = StartTestsString.substr(0, start); //�������� �������
				StartTestsString = StartTestsString.substr(start);
				start = 0;

				end = StartTestsString.find("value");
				end = end + 9;

				TestsString = TestsString + StartTestsString.substr(0, end) + substringVal;
				StartTestsString = StartTestsString.substr(end);

				StartTestsString = TestsString + StartTestsString;

			}

		}
		
	}
	in.close();
	in2.close();

	StartTestsString = StartTestsString + strVal;

	ofstream outputfile("report.json");
	outputfile << StartTestsString;
	outputfile.close();

	
}
