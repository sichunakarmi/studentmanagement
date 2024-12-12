#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>

using namespace std;
class login
{
	public:
		  string username="admin";
		  int password =123 ;
		  
		  string user;
		   int pass;
	
		  	login(){
		  		int ch;
		  		 this->username;
		  		 this->password;
		  		 cout<<endl;
		  		cout<<" ________________________________________"<<endl;
		  		cout<<"|  Hello,Welcome to the system login!!   |"<<endl;
		  		cout<<"|________________________________________|"<<endl;
		  	cout<<"       Enter Your Username :";
		  	cin>>user;
		  	if(user==username)
		  	{
		  	cout<<"        Enter  Password:";
		  		cin>>pass;
		  		
		  		if(pass==password)
		  		{
		  			cout<<"*********Successful login!!*********"<<endl;
		  			system("pause");
				  }
				  else{
				  	cout<<"                    Incorrect password!!  Try Again"<<endl;
				  	system("pause");
					  system("cls");
				  	login();
			}
			  }
			  else{
			  	cout<<"                        Incorrect username!!  try Again"<<endl;
			  	system("pause");
			  	system("cls");
			  	login();
			  }
			  }
		  	
};
		  

class Student
{
 int admno;
 char name[20];
 char gender;
 int std;
 float marks;
 float percentage;
 
 public:
  void getData();
  void showData();
  int getAdmno(){return admno;}
}s;



void Student::getData()
{
 cout<<"     ____________________________"<<endl;
 cout<<"    | Enter Student Details......|"<<endl;
 cout<<"    |____________________________|"<<endl;
 cout<<"      Enter Admission No.     : "; cin>>admno;
 cout<<"      Enter Full Name         : "; cin.ignore(); cin.getline(name,20);
 cout<<"      Enter Gender (M/F)      : "; cin>>gender;
 cout<<"      Enter Standard          : "; cin>>std;
 cout<<"      Enter Marks (out of 500): "; cin>>marks;
 cout<<endl;
 percentage=marks*100.0/500.00;
}

void Student::showData()
{
 cout<<"     ____________________________"<<endl;
 cout<<"    |.......Student Details......|"<<endl;
 cout<<"    |____________________________|"<<endl;
 cout<<"       Admission No.     : "<<admno<<endl;
 cout<<"       Full Name         : "<<name<<endl;
 cout<<"       Gender            : "<<gender<<endl;
 cout<<"       Standard          : "<<std<<endl;
 cout<<"       Marks (out of 500): "<<marks<<endl;
 cout<<"       Percentage        : "<<percentage<<endl;
 cout<<endl;
}

void addData()
{
 ofstream fout;
 fout.open("Students.txt",ios::binary|ios::out|ios::app);
 s.getData();
 fout.write((char*)&s,sizeof(s));
 fout.close();
 cout<<"\n       Data Successfully Saved to File....\n";
}

void displayData()
{
  cout<<"     ____________________________"<<endl;
 cout<<"    |.......Read Details......|"<<endl;
 cout<<"    |____________________________|"<<endl;
 ifstream fin;
 fin.open("Students.txt",ios::in|ios::binary);
 while(fin.read((char*)&s,sizeof(s)))
 {
  s.showData();
 }
 fin.close();
 cout<<"\n      Data Reading from File Successfully Done....\n";
}

void searchData()
{
 cout<<"     ____________________________"<<endl;
 cout<<"    |.......Student Details......|"<<endl;
 cout<<"    |____________________________|"<<endl;
 int n, flag=0;
 ifstream fin;
 fin.open("Students.txt",ios::in|ios::binary);
   cout<<"       Enter Admission Number you want to search : ";
 cin>>n;
 
 while(fin.read((char*)&s,sizeof(s)))
 {
  if(n==s.getAdmno())
  {
   cout<<"       The Details of Admission No. "<<n<<" shown herewith:\n";
   s.showData();
   flag++;
  }
 }
 fin.close();
 if(flag==0)
  cout<<"    The Admission No. "<<n<<endl<<".....Data not found.....\n\n";
 //cout<<"\n\n Data Reading from File Successfully Done....\n";
}

void deleteData()
{
 cout<<"     ____________________________"<<endl;
 cout<<"    |.......Delete Details...... |"<<endl;
 cout<<"    |____________________________|"<<endl;
 int n, flag=0;
 ifstream fin;
 ofstream fout,tout;

 fin.open("Students.txt",ios::in|ios::binary);
 fout.open("TempStud.txt",ios::out|ios::app|ios::binary);
 cout<<"        Enter Admission Number you want to delete: ";
 cin>>n;
 
 while(fin.read((char*)&s,sizeof(s)))
 {
  if(n==s.getAdmno())
  {
   cout<<"      The Following Admission No. "<<n<<" has been DELETED:\n";
   s.showData();
   tout.write((char*)&s,sizeof(s));
   flag++;
  }
  else
  {
   fout.write((char*)&s,sizeof(s));
  }
 }
 fout.close();
 tout.close();
 fin.close();
 if(flag==0)
  cout<<"The Admission No. "<<n<<" not found....\n\n";
 remove("Students.txt");
 rename("tempStud.txt","Students.txt");
}


void modifyData()
{ 
 cout<<"     ____________________________"<<endl;
 cout<<"    |.......Modify Details.. ....|"<<endl;
 cout<<"    |____________________________|"<<endl;
 int n, flag=0, pos;
 fstream fio;

 fio.open("Students.txt",ios::in|ios::out|ios::binary);
 
 cout<<"        Enter Admission Number you want to Modify : ";
 cin>>n;
 
 system("cls");
 
 while(fio.read((char*)&s,sizeof(s)))
 {
  pos=fio.tellg();
  if(n==s.getAdmno())
  {
   cout<<"     The Following Admission No. "<<n<<" will be modified with new data:\n";
   s.showData();
   cout<<"\n\nNow Enter the New Details....\n";
   s.getData();
   fio.seekg(pos-sizeof(s));
   fio.write((char*)&s,sizeof(s));
   flag++;
  }
 }
 fio.close();
 
 if(flag==0)
  cout<<"The Admission No. "<<n<<" not found....\n\n";
}

void project()
{
 int ch;
 do
 {
  system("cls");
  cout<<"...............STUDENT MANAGEMENT SYSTEM..............\n";
  cout<<"======================================================\n";
  cout<<"       0. Exit from Program......\n";
  cout<<"       1. Write Data to File.....\n";
  cout<<"       2. Read Data From File....\n";
  cout<<"       3. Search Data From File..\n";
  cout<<"       4. Delete Data From File..\n";
  cout<<"       5. Modify Data in File....\n";
  cout<<"Enter your choice  : ";
  cin>>ch;
  system("cls");
  switch(ch)
  {
   case 1: addData(); break;
   case 2: displayData(); break;
   case 3: searchData(); break;
   case 4: deleteData(); break;
   case 5: modifyData(); break;
  }
  system("pause");
 }while(ch);
}

int main()
{
login();
 project();
}

