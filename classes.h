#include<string.h>
#include<iostream>
using namespace std;
class students{
	char password[30];
	char name[25];
	char rollno[11];
	int year;
	char branch[10];
	char mobile[11];
	public:
		void get_data(){
			cout<<"Roll Number: ";
			fflush(stdin);
			gets(rollno);
			cout<<"Name: ";
			gets(name);
			cout<<"Year: ";
			cin>>year;
			cout<<"Branch: ";
			fflush(stdin);
			gets(branch);
			cout<<"Mobile Number: ";
			gets(mobile);
		}
		void get_password(){
			fflush(stdin);
			cout<<"Set Password: ";
			gets(password);
		}
		static void put_data_layout(){
			cout<<"Roll_No."<<setw(15)<<"Name"<<setw(30)<<"Year"<<setw(15)<<"Branch"<<setw(22)<<"Mobile_No."<<endl;
			cout<<"--------------------------------------------------------------------------------------------"<<endl;
		}
		void put_data(){
			cout<<rollno<<setw(20)<<name<<setw(20)<<year<<setw(20)<<branch<<setw(20)<<mobile<<endl;
		}
		char* return_id(){
			return rollno;
		}
		char* return_password(){
			return password;
		}
};

class marks{
	int mark[5];
	char rollno[11];
	float percentage;
	public:
		marks(){
			percentage=0;
		}
		void get_marks(){
			cout<<"Roll Number: ";
			fflush(stdin);
			gets(rollno);
			cout<<"Enter Marks\n";
			for(int i=0;i<5;i++){
				cout<<"Subject "<<i+1<<" : ";
				cin>>mark[i];
				percentage+=mark[i];
			}
			percentage=(percentage/500)*100;
		}
		static void put_marks_layout(){
			cout<<"Roll_No."<<setw(20)<<"Subject 1"<<setw(15)<<"Subject 2"<<setw(15)<<"Subject 3"<<setw(15)<<"Subject 4"<<setw(15)<<"Subject 5"<<setw(15)<<"Percentage"<<endl;
			cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;
		}
		void put_marks(){
			cout<<rollno<<setw(15)<<mark[0]<<setw(15)<<mark[1]<<setw(15)<<mark[2]<<setw(15)<<mark[3]<<setw(15)<<mark[4]<<setw(15)<<percentage<<endl;
		}
		char* return_id(){
			return rollno;
		}
};

class teacher{
	char password[30];
	char name[25];
	char id[11];
	int experience;
	char branch[10];
	char mobile[11];
	public:
		void get_info(){
			cout<<"ID: ";
			fflush(stdin);
			gets(id);
			cout<<"Name: ";
			gets(name);
			cout<<"Experience: ";
			cin>>experience;
			cout<<"Branch: ";
			fflush(stdin);
			gets(branch);
			cout<<"Mobile Number: ";
			gets(mobile);
		}
		void get_password(){
			fflush(stdin);
			cout<<"Set Password: ";
			gets(password);
		}
		static void put_info_layout(){
			cout<<"Id"<<setw(20)<<"Name"<<setw(30)<<"Experience"<<setw(15)<<"Branch"<<setw(20)<<"Mobile_No."<<endl;
			cout<<"--------------------------------------------------------------------------------------------"<<endl;
		}
		void put_info(){
			cout<<id<<setw(20)<<name<<setw(20)<<experience<<setw(20)<<branch<<setw(20)<<mobile<<endl;
		}
		char* return_id(){
			return id;
		}
		char* return_password(){
			return password;
		}
};

class principal{
	char password[30];
	char id[11];
	char name[25];
	int experience;
	char mobile[11];
	public:
		void get_detail(){
			fflush(stdin);
			cout<<"ID: ";
			gets(id);
			cout<<"Name: ";
			gets(name);
			cout<<"Experience: ";
			cin>>experience;
			fflush(stdin);
			cout<<"Mobile: ";
			gets(mobile);
		}
		void get_password(){
			fflush(stdin);
			cout<<"Set Password: ";
			gets(password);
		}
		void put_detail(){
			cout<<"Id"<<setw(20)<<"Name"<<setw(30)<<"Experience"<<setw(20)<<"Mobile_No."<<endl;
			cout<<"------------------------------------------------------------------------------------"<<endl;
			cout<<id<<setw(20)<<name<<setw(20)<<experience<<setw(20)<<setw(20)<<mobile<<endl;
			cout<<"------------------------------------------------------------------------------------"<<endl;
		}
		char* return_id(){
			return this->id;
		}
		char* return_password(){
			return password;
		}
};

class books{
	char book_id[11];
	char book_name[30];
	char author[30];
	char course[10];
	public:
		void book_info(){
			cout<<"Book Name: ";
			fflush(stdin);
			gets(book_name);
			cout<<"Author: ";
			gets(author);
			cout<<"Book ID: ";
			gets(book_id);
			cout<<"Course: ";
			fflush(stdin);
			gets(course);
		}
		static void put_book_layout(){
			cout<<"Book_ID"<<setw(20)<<"Book_Name"<<setw(20)<<"Book_Author"<<setw(20)<<"Course"<<endl;
			cout<<"--------------------------------------------------------------------------------------------"<<endl;
		}
		void put_book_info(){
			cout<<book_id<<setw(20)<<book_name<<setw(30)<<author<<setw(15)<<course<<endl;
		}
		char* return_id(){		
			return book_id;
		}
};	
