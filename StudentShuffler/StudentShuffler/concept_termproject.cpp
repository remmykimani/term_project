#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include <array>
using namespace std;
int main()
{
	const int cols = 3;
	const int rows = 200;
	string allstudents[rows][cols];

	ifstream allstudentsfile("inputICSALL.csv");

	if (!allstudentsfile.is_open())
		{
			cout << "Error opening file" << endl;
		}
	else
	{

		while (!allstudentsfile.eof())
		{
			string adm;
			string name;
			string gender;
			getline(allstudentsfile, adm, '"');
			getline(allstudentsfile, name, '"');
			getline(allstudentsfile, gender, '\n');



			for (unsigned int i = 0; i < rows; i++)
			{
				for (unsigned int j = 0; j < cols; j++)
				{
					allstudentsfile >> allstudents[i][j];

				}
			}
		}






	}
	system("pause");
	return 0;
}

