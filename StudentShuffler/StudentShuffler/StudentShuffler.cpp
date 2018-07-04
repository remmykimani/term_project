#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;

class STUDENTS
{
	public:
		string admission;
		string firstname;
		string surname;
		string sex;

		void insert(string adm="null", string fname="null", string gender="null",string sname ="null")
		{
			 admission=adm;
			firstname= fname;
			sex = gender;
			surname = sname ;
		}

};



void filetovectorall(vector < STUDENTS >& student_info)
{
	
	ifstream file("inputICSALL.csv");


	if (!file.is_open())
	{
		cout << "Error opening file" << endl;
	}
	else
	{
		while (!file.eof())
		{
			STUDENTS obj_student;
			string adm;
			string fname;
			string gender;
			string sname;

			getline(file, adm, ',');
			getline(file, sname, ',');
			getline(file, fname, ',');
			getline(file, gender, '\n');


			obj_student.insert(adm, sname, gender, fname);
			student_info.push_back(obj_student);

			//file.close();
			
		}
		
	}

}
void print_all(vector<STUDENTS>&student_info)
{
	for (unsigned int x = 0; x < student_info.size(); x++)
	{
		cout << student_info.at(x).admission;
		cout << student_info.at(x).firstname;
		cout << student_info.at(x).surname;
		cout << student_info.at(x).sex << "\n";

	}
}

void filetovectormale(vector <STUDENTS>&male_students,vector < STUDENTS >&student_info, vector<STUDENTS>&female_students)
{
			for (unsigned int x = 0; x < student_info.size(); x++)
			{
				if (student_info.at(x).sex == "M")
				{
			
					male_students.push_back(student_info.at(x));

				}
				else
				{
					female_students .push_back(student_info.at(x));
				}
			}
		
	}

void print_vectormale(vector < STUDENTS >&male_students)
{
	{

		cout << "-----------------------------------";
		for (unsigned int x = 0; x < male_students.size(); x++)
		{
			cout << male_students.at(x).admission;
			cout << male_students.at(x).firstname;
			cout << male_students.at(x).surname;
			cout << male_students.at(x).sex << "\n";
		}
	}

}
void print_vectorfemale(vector < STUDENTS >&female_students)
{
	{

		cout << "-----------------------------------";
		for (unsigned int x = 0; x < female_students.size(); x++)
		{
			cout << female_students.at(x).admission;
			cout << female_students.at(x).firstname;
			cout << female_students.at(x).surname;
			cout << female_students.at(x).sex << "\n";
		}
	}

}

void fileappendall(vector < STUDENTS >& student_info)
{
	//this is where the file is output to a file
	ofstream studentsoutput;
	studentsoutput.open("students.csv");
	for (unsigned int x = 0; x < student_info.size(); x++)
	{
		studentsoutput << student_info.at(x).admission;
		studentsoutput << student_info.at(x).firstname;
		studentsoutput << student_info.at(x).surname;
		studentsoutput << student_info.at(x).sex << "\n";
	}
	//studentsoutput.close();

}

void fileappendallfemale(vector < STUDENTS >& female_students)
{
	//this is where the file is output to a file
	ofstream studentsoutput;
	studentsoutput.open("female_students.csv");
	for (unsigned int x = 0; x < female_students.size(); x++)
	{
		studentsoutput << female_students.at(x).admission;
		studentsoutput << female_students.at(x).firstname;
		studentsoutput << female_students.at(x).surname;
		studentsoutput << female_students.at(x).sex << "\n";
	}
	//studentsoutput.close();

}
void fileappendallmale(vector < STUDENTS >& male_students)
{
	//this is where the file is output to a file
	ofstream studentsoutput;
	studentsoutput.open("male_students.csv");
	for (unsigned int x = 0; x < male_students.size(); x++)
	{
		studentsoutput << male_students.at(x).admission;
		studentsoutput << male_students.at(x).firstname;
		studentsoutput << male_students.at(x).surname;
		studentsoutput << male_students.at(x).sex << "\n";
	}
	//studentsoutput.close();

}

void randomise_male(vector<STUDENTS>&female_students, vector<STUDENTS>&male_students, vector<STUDENTS>&group_a, vector<STUDENTS>&group_b)
{
	for (unsigned int x = 0; x < male_students.size() - 1; x += 2)//note use of x=+2(x=x+2)
	{
		group_a.push_back(male_students.at(x));
		group_b.push_back(male_students.at(x + 1));

		int divident = male_students.size() % 2;

		if (divident > 0 && x == male_students.size() - 3)
		{
			group_a.push_back(male_students.at(x + 2));
		}

	}
}
void print_group_a(vector<STUDENTS>&group_a)
{
	cout << "-----------------------------------";
	for (unsigned int x = 0; x < group_a.size(); x++)
	{
		cout << group_a.at(x).admission;
		cout << group_a.at(x).firstname;
		cout << group_a.at(x).surname;
		cout << group_a.at(x).sex << "\n";
	}
	cout << "number:" << group_a.size() << endl;
}

void print_group_b(vector<STUDENTS>&group_b)
{
	cout << "-----------------------------------";
	for (unsigned int x = 0; x < group_b.size(); x++)
	{
		cout << group_b.at(x).admission;
		cout << group_b.at(x).firstname;
		cout << group_b.at(x).surname;
		cout << group_b.at(x).sex << "\n";
	}
	cout << "number:" << group_b.size() << endl;
}


void randomise_female(vector<STUDENTS>&female_students, vector<STUDENTS>&male_students, vector<STUDENTS>&group_a, vector<STUDENTS>&group_b)
{
	for (unsigned int x = 0; x < female_students.size() - 1; x += 2)//note use of x=+2(x=x+2)
	{
		group_a.push_back(female_students.at(x));
		group_b.push_back(female_students.at(x + 1));

		int divident = female_students.size() % 2;

		if (divident > 0 && x == female_students.size() - 3)
		{
			group_a.push_back(female_students.at(x + 2));
		}

	}
}

void fileappendgroup_a(vector < STUDENTS >& group_a)
{
	//this is where the file is output to a file
	ofstream group_aoutput;
	group_aoutput.open("male_students.csv");
	for (unsigned int x = 0; x < group_a.size(); x++)
	{
		group_aoutput << group_a.at(x).admission;
		group_aoutput << group_a.at(x).firstname;
		group_aoutput << group_a.at(x).surname;
		group_aoutput << group_a.at(x).sex << "\n";
	}
	group_aoutput.close();

}

void fileappendgroup_b(vector < STUDENTS >& group_b)
{
	//this is where the file is output to a file
	ofstream group_boutput;
	group_boutput.open("male_students.csv");
	for (unsigned int x = 0; x < group_b.size(); x++)
	{
		group_boutput << group_b.at(x).admission;
		group_boutput << group_b.at(x).firstname;
		group_boutput << group_b.at(x).surname;
		group_boutput << group_b.at(x).sex << "\n";
	}
	group_boutput.close();

}






int main()
{
	vector<STUDENTS>student_info;
	vector<STUDENTS>male_students;
	vector<STUDENTS>female_students;
	vector<STUDENTS>group_a;
	vector<STUDENTS>group_b;


	
	filetovectorall(student_info);
	print_all(student_info);

	//filetovectormale(male_students, student_info,female_students);
	

	//randomise_male(female_students, male_students, group_a, group_b);




	system("pause");
	return 0;

}

