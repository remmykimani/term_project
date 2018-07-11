//PROGRAMMER: Mungai Remmy Kimani
//TITLE: Student Shuffler Program
//Lecturer: Kevin Omondi


#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include <algorithm>
#include "Windows.h"
#include <shellapi.h>
#include <tchar.h>

using namespace std;
bool errormessage = true;
int main();
//class is a user defined object hence we are defining an object STUDENT who has the below attributes
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


//this is the function that reads the files and stores the in vectors
void filetovectorall(vector < STUDENTS >& student_info,string filename)
{
		ifstream file(filename);

		if (!file.is_open())
		{
			errormessage = false;
			cout << "\n\n\t\tError opening file\n\nReturning to homepage...\n" << endl;
			Sleep(2000);
			system("cls");
			main();	
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
			}
			file.close();
		}
	
}

//this function prints out the storage array on the screen
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

//this function reads the main store vector and separates males and female to sepaate vectors
void filetovectorgender(vector <STUDENTS>&male_students,vector < STUDENTS >&student_info, vector<STUDENTS>&female_students)
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

//this funnction prints the male students 
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

//this function prints female students
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

//this function writes the split vectors to a csv file
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

//this function writes the split vectors to a csv file
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

//this function writes the split vectors to a csv file
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

//randomises the male studentts
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
	system("cls");
	cout << "-----------------------------------\n\n";
	cout << "Number of students in List A:" << group_a.size()<<"\n" << endl;
	for (unsigned int x = 0; x < group_a.size(); x++)
	{
		cout << group_a.at(x).admission;
		cout << group_a.at(x).firstname;
		cout << group_a.at(x).surname;
		cout << group_a.at(x).sex << "\n";
	}
	
}

void print_group_b(vector<STUDENTS>&group_b)
{
	cout << "\n\n-----------------------------------\n\n";
	cout << "Number of students in List B:" << group_b.size() <<"\n"<< endl;
	for (unsigned int x = 0; x < group_b.size(); x++)
	{
		cout << group_b.at(x).admission;
		cout << group_b.at(x).firstname;
		cout << group_b.at(x).surname;
		cout << group_b.at(x).sex << "\n";
	}
	
}

//randomises female students
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

//writes the shuffled list to csv file
void fileappendgroup_a(vector < STUDENTS >& group_a)
{
	//this is where the file is output to a file
	ofstream group_aoutput;
	group_aoutput.open("group_a.csv");

	group_aoutput << "ADMISSION NO,NAME,GENDER\n";
	for (unsigned int x = 0; x < group_a.size(); x++)
	{
		group_aoutput << group_a.at(x).admission << ",";
		group_aoutput << group_a.at(x).firstname;
		group_aoutput << group_a.at(x).surname << ",";
		group_aoutput << group_a.at(x).sex << "\n";
	}
	group_aoutput.close();

}

//writes the shuffled list to csv file
void fileappendgroup_b(vector < STUDENTS >& group_b)
{
	//this is where the file is output to a file
	ofstream group_boutput;
	group_boutput.open("group_b.csv");
	group_boutput << "ADMISSION NO,NAME,GENDER\n";
	for (unsigned int x = 0; x < group_b.size(); x++)
	{
		group_boutput << group_b.at(x).admission<<",";
		group_boutput << group_b.at(x).firstname;
		group_boutput << group_b.at(x).surname << ",";
		group_boutput << group_b.at(x).sex << "\n";
	}
	group_boutput.close();

}void choicedisplay (int choice_listtype, vector<STUDENTS>&group_a, vector<STUDENTS>&group_b)
{
		switch (choice_listtype)
		{
		case 1:
			print_group_a(group_a);
			break;
		case 2:
			print_group_b(group_b);
			break;
		case 3:
			cout << "\n\n\t------LIST A------\n";
			print_group_a(group_a);
			cout << "\n\n\t------LIST B------\n";
			print_group_b(group_b);
			break;

		default:
			cout << "WRONG SELECTION...TRY AGAIN\n";
			//put a goto
			
			break;
		}
}

void open_a()
{
	//system("group_a.csv");
	 string s = "start excel group_a.csv";
	 system(s.c_str());
}

void open_b()
{
	//system("group_b.csv");
	string s = " start excel group_b.csv";
	system(s.c_str());
}

void openfiles()
{
	int choice_openfile;
	cout << "OPEN SAVED FILES?\n"
		<<"\t1.YES\n\t2.NO\nCHOICE: \n";
	cin >> choice_openfile;

	switch (choice_openfile)
	{
	case 1:
	{
		open_a();
		open_b();
		break;
	}
	
	case 2:
		exit(0);
	}
}


int main()
{
	SetConsoleTitle(L"Student Shuffler");
	vector<STUDENTS>student_info;
	vector<STUDENTS>male_students;
	vector<STUDENTS>female_students;
	vector<STUDENTS>group_a;
	vector<STUDENTS>group_b;

	int num_file;
	string filename;
	int choice_firstpage;
	int choice_display;
	int choice_listtype;
	
	do {
	a:
		cout << "------------WELCOME TO THE STUDENT SHUFFLER PROGRAM--------\n\n";
		cout << "Loading.";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".\n\n\n";
		system("pause");
		system("cls");
		cout << "\tPLEASE MAKE YOUR CHOICE\n"
			<< "\t\t1.ENTER FILES\n"
			<< "\t\t2.EXIT THE PROGRAM\n";

		cin >> choice_firstpage;
		system("cls");
		switch (choice_firstpage)
		{
		case 1:
			cout << "ENTER THE NUMBER OF FILES YOU HAVE\n";
			cin >> num_file;

			for (int x = 0; x < num_file; x++)
			{
				cout << "PLEASE ENTER FILENAME\n";
				cin >> filename;
				filetovectorall(student_info, filename);
			}		

			system("cls");
			cout << "\tReading Files....\n";
			Sleep(2000);
			filetovectorgender(male_students, student_info, female_students);
			cout << "\tRandomising Students...\n";
			randomise_female(female_students, male_students, group_a, group_b);
			randomise_male(female_students, male_students, group_a, group_b);
			Sleep(3000);
			cout << "-----files stored and shuffled sucessfully!-----\n\n";
			break;
		case 2:
			system("cls");
			cout << "\t-----PROGRAM EXITING-----\n";
			Sleep(3000);
			exit(0);
			break;
		default:
			cout << "WRONG SELECTION...TRY AGAIN\n";
			goto a;
			break;
		}

	b:
		//system("cls");
		cout << "CHOOSE DISPLAY OPTION\n"
			<< "\t1..DISPLAY LISTS ON SCREEN\n"
			<< "\t2..SAVE THE LISTS\n"
			<< "Choice: ";
		cin >> choice_display;
	c:
		switch (choice_display)
		{
		case 1:
			system("cls");
			cout << "WHICH LIST WOULD YOU LIKE TO DISPLAY?\n"
				<< "\t1..LIST A\n"
				<< "\t2..LIST B\n"
				<< "\t3..BOTH LIST A AND LIST B\n"
				<< "Choice: ";
			cin >> choice_listtype;
			//choicedisplay(choice_listtype, group_a, group_b);
			switch (choice_listtype)
			{
			case 1:
				print_group_a(group_a);
				break;
			case 2:
				print_group_b(group_b);
				break;
			case 3:
				cout << "\t------LIST A------\n";
				print_group_a(group_a);
				cout << "\t------LIST B------\n";
				print_group_b(group_b);
				break;

			default:
				cout << "WRONG SELECTION...TRY AGAIN\n";
				goto c;
				break;
			}
			break;

		case 2:
			system("cls");
			
			cout << "\t----SAVING LIST A...\n\n";
			fileappendgroup_a(group_a);
			Sleep(3000);
			cout << "\t----SAVING LIST B...\n\n";
			fileappendgroup_b(group_b);
			Sleep(3000);
			cout << "----------LISTS SAVED----------\n";
			openfiles();
			break;
		default:
			cout << "WRONG SELECTION...TRY AGAIN\n";
			goto b;
			break;
		}
	} while (true);

	system("pause");
	return 0;

}