#include<iostream>
using namespace std;

void insert_principal(){
	fstream principal_data;
	principal_data.open("principal_data.txt",ios::app|ios::binary);
	principal obj;
	obj.get_detail();
	obj.get_password();
	principal_data.write((char*)&obj,sizeof(obj));
	principal_data.close();
	cout<<"\nSuccessfully Inserted!\n";
}
void insert_student(){
	fstream student_data;
	student_data.open("student_data.txt",ios::app|ios::binary);
	students obj;
	obj.get_data();
	obj.get_password();
	student_data.write((char*)&obj,sizeof(obj));
	student_data.close();
	cout<<"\nSuccessfully Inserted!\n";
}

void insert_teacher(){
	fstream teacher_data;
	teacher_data.open("teacher_data.txt",ios::app|ios::binary);
	teacher obj;
	obj.get_info();
	obj.get_password();
	teacher_data.write((char*)&obj,sizeof(obj));
	teacher_data.close();		
	cout<<"\nSuccessfully Inserted!\n";
}

void insert_book(){
	fstream book_data;
	book_data.open("book_data.txt",ios::app|ios::binary);
	books obj;
	obj.book_info();
	book_data.write((char*)&obj,sizeof(obj));
	book_data.close();
	cout<<"\nSuccessfully Inserted!\n";
}

void insert_marks(){
	fstream marks_data;
	marks_data.open("marks_data.txt",ios::app|ios::binary);
	marks obj;
	obj.get_marks();
	marks_data.write((char*)&obj,sizeof(obj));
	marks_data.close();
	cout<<"\nSuccessfully Inserted!\n";
}

void display_principal(){
	principal obj;
	fstream principal_data;
	principal_data.open("principal_data.txt",ios::in);
	principal_data.read((char*)&obj,sizeof(obj));
	obj.put_detail();
}

void display_student(){
	students obj;
	int count=0;
	fstream student_data;
	student_data.open("student_data.txt",ios::in);
	obj.put_data_layout();
	while(student_data.read((char*)&obj,sizeof(obj))){
		obj.put_data();
		count++;	
	}
	cout<<"--------------------------------------------------------------------------------------------"<<endl;
	if(count==0)
		cout<<"\nNo Information Yet!";
	else
		cout<<"\nTotal_Students: "<<count<<endl;
}

void display_teacher(){
	teacher obj;
	int count=0;
	fstream teacher_data;
	teacher_data.open("teacher_data.txt",ios::in);
	obj.put_info_layout();
	while(teacher_data.read((char*)&obj,sizeof(obj))){
		obj.put_info();	
		count++;
	}	
	cout<<"--------------------------------------------------------------------------------------------"<<endl;
	if(count==0)
		cout<<"\nNo Information Yet\n";
	else
		cout<<"\nTotal_Teachers: "<<count<<endl;	
}

void display_marks(){
	marks obj;
	int count=0;
	fstream marks_data;
	obj.put_marks_layout();
	marks_data.open("marks_data.txt",ios::in);
	while(marks_data.read((char*)&obj,sizeof(obj))){
		obj.put_marks();
		count++;	
	}	
	cout<<"-----------------------------------------------------------------------------------------------------------"<<endl;
	if(count==0)
		cout<<"\nNo Information Yet\n";
	else
		cout<<"\nTotal_Students_Marks_Inserted: "<<count<<endl;
}

void display_book(){
	books obj;
	int count=0;
	fstream book_data;
	book_data.open("book_data.txt",ios::in);
	obj.put_book_layout();
	while(book_data.read((char*)&obj,sizeof(obj))){
		obj.put_book_info();	
		count++;
	}	
	cout<<"--------------------------------------------------------------------------------------------"<<endl;
	if(count==0)
		cout<<"\nNo Information Yet\n";
	else
		cout<<"\nTotal_Books: "<<count<<endl;
}

void update_principal(){
	principal obj;
	fstream principal_data;
	principal_data.open("principal_data.txt",ios::in|ios::out|ios::ate|ios::binary);
	principal_data.seekg(0);
	principal_data.read((char*)&obj,sizeof(obj));
	principal_data.seekg(0);
	obj.get_detail();
	principal_data.write((char*)&obj,sizeof(obj));
	cout<<"\nSuccessfully Updated!\n";
}

void update_teacher(char id[]){
	int count=0;
	fstream teacher_data;
	teacher_data.open("teacher_data.txt",ios::in|ios::out|ios::ate|ios::binary);
	teacher obj;
	teacher_data.seekg(ios::beg);
	while(teacher_data.read((char*)&obj,sizeof(obj))){
		if(strcmp(obj.return_id(),id)==0){
			obj.get_info();
			teacher_data.seekg(teacher_data.tellg()-sizeof(obj));
			teacher_data.write((char*)&obj,sizeof(obj));
			count++;
		}
	}
	if(count==0)
		cout<<"\nNot Found!\n";
	else
		cout<<"\nSuccessfully Updated!\n";
}

void update_student(char id[]){
	int count=0;
	fstream student_data;
	student_data.open("student_data.txt",ios::in|ios::out|ios::ate|ios::binary);
	students obj;
	student_data.seekg(ios::beg);
	while(student_data.read((char*)&obj,sizeof(obj))){
		if(strcmp(obj.return_id(),id)==0){
			obj.get_data();
			student_data.seekg(student_data.tellg()-sizeof(obj));
			student_data.write((char*)&obj,sizeof(obj));
			count++;
		}
	}
	if(count==0)
		cout<<"\nNot Found!\n";
	else
		cout<<"\nSuccessfully Updated!\n";
}

void update_marks(char id[]){
	int count=0;
	fstream marks_data;
	marks_data.open("marks_data.txt",ios::in|ios::out|ios::ate|ios::binary);
	marks obj;
	marks_data.seekg(ios::beg);
	while(marks_data.read((char*)&obj,sizeof(obj))){
		if(strcmp(obj.return_id(),id)==0){
			obj.get_marks();
			marks_data.seekg(marks_data.tellg()-sizeof(obj));
			marks_data.write((char*)&obj,sizeof(obj));
			count++;
		}
	}
	if(count==0)
		cout<<"\nNot Found!\n";
	else
		cout<<"\nSuccessfully Updated!\n";
}

string login(char id[],char password[]){
	fstream student_data,teacher_data,principal_data;
	principal obj;
	students obj1;
	teacher obj2;
	principal_data.open("principal_data.txt",ios::in);
	student_data.open("student_data.txt",ios::in);
	teacher_data.open("teacher_data.txt",ios::in);
	principal_data.read((char*)&obj,sizeof(obj));
	if(strcmp(id,obj.return_id())==0){
		if(strcmp(password,obj.return_password())==0)
			return "principal";
		else
			return "Invalid Password";
	}
	while(teacher_data.read((char*)&obj2,sizeof(obj2))){
		if(strcmp(obj2.return_id(),id)==0){
			if(strcmp(obj2.return_password(),password)==0)
				return "teacher";
			else
				return "Invalid Password";
		}
	}
	while(student_data.read((char*)&obj1,sizeof(obj1))){
		if(strcmp(obj1.return_id(),id)==0){
			if(strcmp(obj1.return_password(),password)==0)
				return "student";
			else
				return "Invalid Password";
		}
	}
	return "Invalid ID";
}

void student_search(char id[]){
	int count=0;
	fstream student_data;
	students obj;																			
	student_data.open("student_data.txt",ios::in);
	while(student_data.read((char*)&obj,sizeof(obj))){
		if(strcmp(obj.return_id(),id)==0){
			obj.put_data_layout();
			obj.put_data();
			cout<<"--------------------------------------------------------------------------------------------"<<endl;
			count++;
			break;						
		}
	}
	if(count==0)
		cout<<"\nNot Found!\n";
	else
		cout<<"\nFound Successfully!\n";
}	

void teacher_search(char id[]){
	int count=0;
	fstream teacher_data;
	teacher obj;
	teacher_data.open("teacher_data.txt",ios::in);
	while(teacher_data.read((char*)&obj,sizeof(obj))){
		if(strcmp(obj.return_id(),id)==0){
			obj.put_info_layout();
			obj.put_info();
			cout<<"--------------------------------------------------------------------------------------------"<<endl;
			count++;	
			break;					
		}
	}
	if(count==0)
		cout<<"\nNot Found!\n";
	else
	 	cout<<"\nFound Successfully!\n";
}

void marks_search(char id[]){
	int count=0;
	fstream marks_data;
	marks obj;
	marks_data.open("marks_data.txt",ios::in);
	while(marks_data.read((char*)&obj,sizeof(obj))){
		if(strcmp(obj.return_id(),id)==0){
			obj.put_marks_layout();
			obj.put_marks();
			cout<<"--------------------------------------------------------------------------------------------"<<endl;
			count++;	
			break;					
		}
	}
	if(count==0)
		cout<<"\nNot Found!\n";
	else
	 	cout<<"\nFound Successfully!\n";
}

void book_search(char id[]){
	int count=0;
	fstream book_data;
	books obj;
	book_data.open("book_data.txt",ios::in);
	while(book_data.read((char*)&obj,sizeof(obj))){
		if(strcmp(obj.return_id(),id)==0){
			obj.put_book_layout();
			obj.put_book_info();
			cout<<"--------------------------------------------------------------------------------------------"<<endl;
			count++;	
			break;					
		}
	}
	if(count==0)
		cout<<"\nNot Found!\n";
	else
	 	cout<<"\nFound Successfully!\n";
}

void delete_teacher(char id[]){
	int count=0;
	fstream teacher_data,temp;
	teacher obj;
	teacher_data.open("teacher_data.txt",ios::in|ios::binary);
	temp.open("temp.txt",ios::out|ios::app|ios::binary);
	while(teacher_data.read((char*)&obj,sizeof(obj))){
		if(strcmp(id,obj.return_id())!=0)
			temp.write((char*)&obj,sizeof(obj));
		else
			count++;
	}	
	teacher_data.close();
	temp.close();
	remove("teacher_data.txt");
	rename("temp.txt","teacher_data.txt");
	if(count==1)
		cout<<"\nSuccessfully Deleted!\n";
	else 
		cout<<"\nData Not Found!\n";
}

void delete_student(char id[]){
	int count=0;
	fstream student_data,temp;
	students obj;
	student_data.open("student_data.txt",ios::in|ios::binary);
	temp.open("temp.txt",ios::out|ios::app|ios::binary);
	while(student_data.read((char*)&obj,sizeof(obj))){
		if(strcmp(id,obj.return_id())!=0)
			temp.write((char*)&obj,sizeof(obj));
		else
			count++;
	}	
	student_data.close();
	temp.close();
	remove("student_data.txt");
	rename("temp.txt","student_data.txt");
	if(count==1)
		cout<<"\nSuccessfully Deleted!\n";
	else 
		cout<<"\nData Not Found!\n";
}

void delete_marks(char id[]){
	int count=0;
	fstream marks_data,temp;
	marks obj;
	marks_data.open("marks_data.txt",ios::in|ios::binary);
	temp.open("temp.txt",ios::out|ios::app|ios::binary);
	while(marks_data.read((char*)&obj,sizeof(obj))){
		if(strcmp(id,obj.return_id())!=0)
			temp.write((char*)&obj,sizeof(obj));
		else
			count++;
	}	
	marks_data.close();
	temp.close();
	remove("marks_data.txt");
	rename("temp.txt","marks_data.txt");
	if(count==1)
		cout<<"\nSuccessfully Deleted!\n";
	else 
		cout<<"\nData Not Found!\n";
}
