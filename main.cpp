#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<iostream>
#include"classes.h"
#include"functions.h"
using namespace std;
int main(){
	system("color A");
	int n;
	main_menu:
	system("CLS");
	cout<<"COLLAGE PORTAL\n";
	cout<<"--------------\n";
	cout<<"1.Login\n2.Sign Up\n3.Change Password\n4.Exit\n";
	while(1){
		cout<<"\nChoise: ";
		cin>>n;
		switch(n){
			case 1:
				char id[11],password[30];
				system("CLS");
				cout<<"LOGIN\n";
				cout<<"-----\n";
				cout<<"\nID: ";
				fflush(stdin);
				gets(id);
				cout<<"\nPassword: ";
				gets(password);
				if(login(id,password)=="principal"){
					information:
					system("CLS");
					cout<<"LogIn As Principal\n";
					cout<<"------------------\n\n";
					cout<<"1.Information\n2.Update\n3.Insert\n4.Search\n5.Deleat\n6.LogOut\n";   
					while(1){
						cout<<"\nChoise: ";
						cin>>n;
						switch(n){
							case 1:
								principla_informaton:
								system("CLS");
								cout<<"INFORMATION\n";
								cout<<"-----------\n\n";
								cout<<"1.Personal\n2.Teacher\n3.Students\n4.Students Marks\n5.Book\n6.Back\n";  
								while(1){
									cout<<"\nChoise: ";
									cin>>n;
									switch(n){
										case 1:
											system("cls");
											cout<<"Personal Information\n";
											cout<<"--------------------\n\n";
											display_principal();	
											getch();
											goto principla_informaton;								
										break;
										case 2:
											system("CLS");
											cout<<"Teachers Information\n";
											cout<<"--------------------\n\n";
											display_teacher();
											getch();
											goto principla_informaton;
										break;
										case 3:
											system("CLS");
											cout<<"Students Information\n";
											cout<<"--------------------\n\n";
											display_student();
											getch();
											goto principla_informaton;
										break;
										case 4:
											system("CLS");
											cout<<"Marks Information\n";
											cout<<"-----------------\n\n";
											display_marks();
											getch();
											goto principla_informaton;
										break;
										case 5:
											system("CLS");
											cout<<"Book Information\n";
											cout<<"----------------\n\n";
											display_book();
											getch();
											goto principla_informaton;
										break;
										case 6:goto information;
										default:cout<<"\nOops!Choise Out Of The Scope.\n";
									}
								}
							break;
							case 2:												
								principal_update:
								system("CLS");
								cout<<"UPDATE\n";
								cout<<"------\n\n";
								cout<<"1.Personal\n2.Teacher\n3.Student\n4.Student Marks\n5.Back\n";
								while(1){
									cout<<"\nChoise: ";
									cin>>n;
									switch(n){
										case 1:
											system("cls");
											cout<<"Update Principal\n";
											cout<<"----------------\n\n";
											update_principal();
											getch();
											goto principal_update;
										break;
										case 2:
											system("CLS");
											cout<<"Update Teacher\n";
											cout<<"--------------\n\n";
											char id1[11];
											cout<<"ID: ";
											fflush(stdin);
											gets(id1);
											update_teacher(id1);
											getch();
											goto principal_update;
										break;
										case 3:
											system("CLS");
											cout<<"Update Student\n";
											cout<<"--------------\n\n";
											char id2[11];
											cout<<"ID: ";
											fflush(stdin);
											gets(id2);
											update_student(id2);
											getch();
											goto principal_update;
										break;
										case 4:
											system("CLS");
											cout<<"Update Marks\n";
											cout<<"------------\n\n";
											char id3[11];
											cout<<"ID: ";
											fflush(stdin);
											gets(id3);
											update_marks(id3);
											getch();
											goto principal_update;
										break;
										case 5:goto information;
										default:cout<<"\nOops!Choise Out Of The Scope.\n";
									}
								}
							break;
							case 3:
								principal_insert:
								system("CLS");															
								cout<<"INSERT INFO\n";
								cout<<"-----------\n\n";
								cout<<"1.Teacher\n2.Student\n3.Student Marks\n4.Back\n";
								while(1){
									cout<<"\nChoise: ";
									cin>>n;
									switch(n){
										case 1:
											system("CLS");
											cout<<"Insert Teacher\n";			
											cout<<"--------------\n\n";
											insert_teacher();
											getch();
											goto principal_insert;
										break;
										case 2:
											system("CLS");
											cout<<"Insert Student\n";
											cout<<"--------------\n\n";			
											insert_student();
											getch();
											goto principal_insert;
										break;
										case 3:
											system("CLS");
											cout<<"Insert Marks\n";
											cout<<"------------\n\n";
											insert_marks();
											getch();
											goto principal_insert;
										break;
										case 4:goto information;
										default:cout<<"\nOops!Choise Out Of The Scope.\n";
									}
								}
							break;
							case 4:
								search_lable1:
								system("cls");															
								cout<<"Search\n";
								cout<<"------\n\n";
								cout<<"1.Teacher\n2.Student\n3.Student Marks\n4.Book\n5.Back\n";
								while(1){
									int n;
									cout<<"\nChoise: ";
									cin>>n;
									switch(n){
										case 1:
											system("cls");
											cout<<"Teacher Search\n";
											cout<<"--------------\n\n";
											char id1[11];
											cout<<"ID: ";
											fflush(stdin);
											gets(id1);
											teacher_search(id1);
											getch();
											goto search_lable1;
										break;
										case 2:
											system("cls");
											cout<<"Student Search\n";
											cout<<"--------------\n\n";
											char id2[11];
											cout<<"ID: ";
											fflush(stdin);
											gets(id2);
											student_search(id2);
											getch();
											goto search_lable1;
										break;
										case 3:
											system("cls");
											cout<<"Student_Marks Search\n";
											cout<<"--------------------\n\n";
											char id3[11];
											cout<<"ID: ";
											fflush(stdin);
											gets(id3);
											marks_search(id3);
											getch();
											goto search_lable1;
										break;
										case 4:
											system("cls");
											cout<<"Book Search\n";
											cout<<"-----------\n\n";
											char id4[11];
											cout<<"ID: ";
											fflush(stdin);
											gets(id4);
											book_search(id4);
											getch();
											goto search_lable1;
										break;	
										case 5:goto information;
										default:cout<<"\nOops!Choise Out Of The Scope.\n";
									}
								}
								getch();
								goto information;
							break;
							case 5:
								delete_lable:
								system("cls");
								cout<<"Delete Record\n";
								cout<<"-------------\n\n";
								cout<<"1.Teacher\n2.Student\n3.Marks\n4.Back\n";
								while(1){
									cout<<"\nChoise: ";
									cin>>n;
									switch(n){
										case 1:
											system("cls");
											cout<<"Delete Teacher\n";
											cout<<"--------------\n\n";
											char id1[11];
											cout<<"ID: ";
											fflush(stdin);
											gets(id1);
											delete_teacher(id1);
											getch();
											goto delete_lable;
										break;
										case 2:
											system("cls");
											cout<<"Delete Student\n";
											cout<<"--------------\n\n";
											char id2[11];
											cout<<"ID: ";
											fflush(stdin);
											gets(id2);
											delete_student(id2);
											getch();
											goto delete_lable;
										break;
										case 3:
											system("cls");
											cout<<"Delete Marks\n";
											cout<<"------------\n\n";
											char id3[11];
											cout<<"ID: ";
											fflush(stdin);
											gets(id3);
											delete_marks(id3);
											getch();
											goto delete_lable;
										break;
										case 4:goto information;										
										default:cout<<"\nOops!Choise Out Of The Scope.\n";
									}
								}	
							break;
							case 6:
							system("cls");
							cout<<"\n\nSuccessfully Logout!\n";
							cout<<"--------------------\n\n";
							getch();
							goto main_menu;
							default:cout<<"\nOops!Choise Out Of The Scope.\n";
						}
					}
				}
				else if(login(id,password)=="teacher"){
					information_teacher:
					system("CLS");
					cout<<"LogIn As Teacher\n";
					cout<<"----------------\n\n";
					cout<<"1.Information\n2.Update\n3.Insert\n4.Search\n5.Delete\n6.LogOut\n";  
					while(1){												
						cout<<"\nChoise: ";
						cin>>n;
						switch(n){
							case 1:
								teacher_lable1:
								system("CLS");
								cout<<"Information\n";
								cout<<"-----------\n\n";
								cout<<"1.Personal\n2.Students\n3.Students Marks\n4.Book\n5.Back\n";  
								while(1){
								cout<<"\nChoise: ";
								cin>>n;
								switch(n){
									case 1:
										system("cls");
										cout<<"Personal Information\n";
										cout<<"--------------------\n\n";
										teacher_search(id);
										getch();
										goto teacher_lable1;
									break;
									case 2:
										system("CLS");
										cout<<"Student Information\n";
										cout<<"-------------------\n\n";
										display_student();
										getch();
										goto teacher_lable1;
									break;
									case 3:
										system("CLS");
										cout<<"Student Marks Information\n";
										cout<<"-------------------------\n\n";
										display_marks();
										getch();
										goto teacher_lable1;
									break;
									case 4:
										system("CLS");
										cout<<"Book Information\n";
										cout<<"----------------\n\n";
										display_book();
										getch();
										goto teacher_lable1;
									break;
									case 5:goto information_teacher;
										default:cout<<"\nOops!Choise Out Of The Scope.\n";
									}
								}
							break;
							case 2:
								teacher_lable2:
								system("CLS");
								cout<<"UPDATE\n";
								cout<<"------\n\n";
								cout<<"1.Personal\n2.Student\n3.Student Marks\n4.Back\n";
								while(1){
									cout<<"\nChoise: ";
									cin>>n;
									switch(n){
										case 1:
											system("CLS");
											cout<<"Update Personal\n";
											cout<<"---------------\n\n";
											update_teacher(id);
											getch();
											goto teacher_lable2;
										break;
										case 2:
											system("CLS");
											cout<<"Update Student\n";
											cout<<"--------------\n\n";
											char id1[11];
											cout<<"Id: ";
											fflush(stdin);
											gets(id1);
											cout<<endl;
											update_student(id1);
											getch();
											goto teacher_lable2;
										break;
										case 3:
											system("CLS");
											cout<<"Update Marks\n";
											cout<<"------------\n\n";
											char id2[11];
											cout<<"ID: ";
											fflush(stdin);
											gets(id2);
											cout<<endl;
											update_marks(id2);
											getch();
											goto teacher_lable2;
										break;
										case 4:goto information_teacher;
										default:cout<<"\nOops!Choise Out Of The Scope\n";
									}
								}
							break;																
							case 3:
								teacher_lable3:
								system("CLS");
								cout<<"INSERT INFO\n";
								cout<<"-----------\n\n";
								cout<<"1.Student\n2.Student Marks\n3.Back\n";
								while(1){
									cout<<"\nChoise: ";
									cin>>n;
									switch(n){
										case 1:
											system("cls");
											cout<<"Insert Student\n";
											cout<<"--------------\n\n";
											insert_student();
											getch();
											goto teacher_lable3;
										break;
										case 2:
											system("cls");
											cout<<"Insert Marks\n";
											cout<<"------------\n\n";
											insert_marks();
											getch();
											goto teacher_lable3;
										break;
										case 3:goto information_teacher;
										default:cout<<"\nOops!Choise Out Of The Scope.\n";
									}
								}
							break;
							case 4:
								search_lable2:
								system("cls");														
								cout<<"Search\n";
								cout<<"------\n\n";
								cout<<"1.Student\n2.Student Marks\n3.Book\n4.Back\n";
								while(1){
									int n;
									cout<<"\nChoise: ";
									cin>>n;
									switch(n){
										case 1:
											system("cls");
											cout<<"Student Search\n";
											cout<<"--------------\n\n";
											char id1[11];
											cout<<"ID: ";
											fflush(stdin);
											gets(id1);
											cout<<endl;
											student_search(id1);
											getch();
											goto search_lable2;
											break;
										case 2:
											system("cls");
											cout<<"Student_Marks Search\n";
											cout<<"--------------------\n\n";
											char id2[11];
											cout<<"ID: ";
											fflush(stdin);
											gets(id2);
											cout<<endl;
											marks_search(id2);
											getch();
											goto search_lable2;
										break;
										case 3:
											system("cls");
											cout<<"Search\n";
											cout<<"------\n\n";
											char id3[11];
											cout<<"ID: ";
											fflush(stdin);
											gets(id3);
											cout<<endl;
											book_search(id3);
											getch();
											goto search_lable2;
										break;
										case 4:goto information_teacher;
										default:cout<<"\nOops!Choise Out Of The Scope.\n";
									}
								}
							break;
							case 5:
								delete_lable1:
								system("cls");
								cout<<"Delete Record\n";
								cout<<"-------------\n\n";
								cout<<"1.Student\n2.Marks\n3.Back\n";
								while(1){
									cout<<"\nChoise: ";
									cin>>n;
									switch(n){
										case 1:
											system("cls");
											cout<<"Delete Student\n";
											cout<<"--------------\n\n";
											char id2[11];
											cout<<"ID: ";
											fflush(stdin);
											gets(id2);
											delete_student(id2);
											getch();
											goto delete_lable1;
										break;
										case 2:
											system("cls");
											cout<<"Delete Marks\n";
											cout<<"------------\n\n";
											char id3[11];
											cout<<"ID: ";
											fflush(stdin);
											gets(id3);
											delete_marks(id3);
											getch();
											goto delete_lable1;
										break;
										case 3:goto information_teacher;										
										default:cout<<"\nOops!Choise Out Of The Scope.\n";
									}
								}	
							break;
							case 6:
								system("cls");
								cout<<"\n\nSuccessfully Logout!\n";
								cout<<"--------------------\n\n";
								getch();
								goto main_menu;
							default:cout<<"\nOops!Choise Out Of The Scope.\n";
						}
					}
				}
				else if(login(id,password)=="student"){
					information_student:
					system("CLS");
					cout<<"LogIn As Student\n";
					cout<<"----------------\n\n";
					cout<<"1.Information\n2.Update\n3.Search_Book\n4.LogOut\n";   
					while(1){
						cout<<"\nChoise: ";
						cin>>n;
						switch(n){
							case 1:
								student_lable1:
								system("CLS");
								cout<<"Information\n";
								cout<<"-----------\n\n";
								cout<<"1.Personal\n2.Marks\n3.Books\n4.Back\n";  			
								while(1){
								cout<<"\nChoise: ";
								cin>>n;
								switch(n){
									case 1:
										system("cls");					
										cout<<"Personal Information\n";
										cout<<"--------------------\n\n";
										student_search(id);
										getch();
										goto student_lable1;
									break;
									case 2:
										system("cls");
										cout<<"Information Marks\n";
										cout<<"-----------------\n\n";
										marks_search(id);
										getch();
										goto student_lable1;
									break;
									case 3:
										system("cls");
										cout<<"Information Books\n";
										cout<<"-----------------\n\n";
										display_book();
										getch();
										goto student_lable1;
									break;
									case 4:goto information_student;
										default:cout<<"\nOops!Choise Out Of The Scope.\n";
									}
								}
							break;
							case 2:
								system("CLS");
								cout<<"UPDATE\n";
								cout<<"------\n\n";
								update_student(id);
								getch();
								goto information_student;
							break;
							case 3:
								system("cls");
								cout<<"Book Search\n";
								cout<<"-----------\n\n";
								char id_book[11];
								cout<<"ID: ";
								fflush(stdin);
								gets(id_book);
								cout<<endl;
								book_search(id_book);
								getch();
								goto information_student;
							break;
							case 4:
								system("cls");
								cout<<"\n\nSuccessfully Logout!\n";
								cout<<"--------------------\n\n";
								getch();
								goto main_menu;
							default:cout<<"\nOops!Choise Out Of The Scope.\n";
						}
					}					
				}
				else if(login(id,password)=="Invalid Password"){
					system("cls");
					cout<<"\n\nInvalid Password!\n";
					cout<<"-----------------\n\n";
					getch();
					goto main_menu;
				}
				else if(login(id,password)=="Invalid ID"){
					system("cls");
					cout<<"\n\nInvalid ID!\n";
					cout<<"-----------\n\n";
					getch();
					goto main_menu;
				}
			break;
			case 2:
				signup_page:
				system("CLS");
				cout<<"SignUp\n";
				cout<<"------\n\n";
				cout<<"1.Principal\n2.Teacher\n3.Student\n4.Book\n5.Back\n";
				while(1){
					cout<<"\nChoise: ";
					cin>>n;
					switch(n){
						case 1:
							system("cls");
							cout<<"Insert Principal\n";
							cout<<"----------------\n\n";
							insert_principal();
							getch();
							goto signup_page;
						break;
						case 2:
							system("cls");
							cout<<"Insert Teacher\n";
							cout<<"--------------\n\n";
							insert_teacher();
							getch();
							goto signup_page;
 						break;
						case 3:
							system("cls");
							cout<<"Insert Student\n";
							cout<<"--------------\n\n";
							insert_student();
							getch();
							goto signup_page;
						break;
						case 4:
							system("cls");
							cout<<"Insert Book\n";
							cout<<"-----------\n\n";
							insert_book();
							getch();
							goto signup_page;
						break;
						case 5:goto main_menu;
						default:cout<<"\nOops!Choise Out Of The Scope.\n";	
					}
				}
			break;
			case 3:
				char id_pass[11],pass[30];
				system("cls");
				cout<<"Change Password\n";
				cout<<"---------------\n\n";
				cout<<"ID: ";
				fflush(stdin);
				gets(id_pass);
				cout<<"\nPassword: ";
				gets(pass);
				cout<<endl;
				if(login(id_pass,pass)=="principal"){
					fstream principal_data;
					principal obj;
					principal_data.open("principal_data.txt",ios::in|ios::out|ios::binary|ios::ate);
					principal_data.seekg(0);
					principal_data.read((char*)&obj,sizeof(obj));
					obj.get_password();
					principal_data.seekg(0);
					principal_data.write((char*)&obj,sizeof(obj));
					cout<<"\nSuccessfully Changed!\n";
				}
				else if(login(id_pass,pass)=="teacher"){
					fstream teacher_data;
					teacher obj;
					teacher_data.open("teacher_data.txt",ios::in|ios::out|ios::binary|ios::ate);
					teacher_data.seekg(0);
					while(teacher_data.read((char*)&obj,sizeof(obj))){
						if(strcmp(obj.return_id(),id_pass)==0){
							obj.get_password();
							teacher_data.seekg(teacher_data.tellg()-sizeof(obj));
							teacher_data.write((char*)&obj,sizeof(obj));
							cout<<"\nSuccessfully Changed!\n";
							break;
						}
					}
				}
				else if(login(id_pass,pass)=="student"){
					fstream student_data;
					students obj;
					student_data.open("student_data.txt",ios::in|ios::out|ios::binary|ios::ate);
					student_data.seekg(0);
					while(student_data.read((char*)&obj,sizeof(obj))){
						if(strcmp(obj.return_id(),id_pass)==0){
							obj.get_password();
							student_data.seekg(student_data.tellg()-sizeof(obj));
							student_data.write((char*)&obj,sizeof(obj));
							cout<<"\nSuccessfully Changed!\n";
							break;
						}
					}
				}
				else if(login(id_pass,pass)=="Invalid Password")
					cout<<"\nInvalid Password";
				else
					cout<<"\nInvalid ID\n";
				getch();
				goto main_menu;
			break;
			case 4:
				system("cls");
				cout<<"\n\nDo you want to close the Portal(y/n): ";
				char a;
				cin>>a;
				if(a=='y'||a=='Y'){
					system("cls");
					cout<<"\n\n\n\n\t\t\t\tTHANK YOU"<<endl;
					cout<<"\t\t\t\t---------\n\n";
					exit(0);
				}
				else
					goto main_menu;
			default:cout<<"Choise Out Of The Scope!\n";	
		}
	}
}
