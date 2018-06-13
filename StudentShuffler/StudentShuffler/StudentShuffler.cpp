#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include <vector>

using namespace std;

int main()
{
	vector<string>all_students;
	ifstream ics_a("inputICSA.csv");

	if (!ics_a.is_open())
	{
		cout << "Not open";
	}
	else
	{
		string adm;
		string name;
		string gender;

		while (ics_a.good())
		{
			/*getline(ics_a, adm, '"');
			getline(ics_a, name, '"');*/

			getline(ics_a, name, '\n');

			all_students.push_back(name);


			/*cout << "Your Admission Number:" << adm << endl;
			cout <<"Your Name is :"<< name<<endl;
			cout <<"Your Gender is :"<< gender<<endl;
			cout << "______________________________\n";*/
			cout << all_students.at(all_students.size) << endl;
		}
	}
	system("pause");
	return 0;
}

