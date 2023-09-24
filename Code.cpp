#include<iostream>
#include<string>
#include<ctype.h>
#include<fstream>
#include<queue>
#include<vector>
#include<stack>
#include<ctime>
#include<unistd.h>
#include<conio.h>
using namespace std;
#define admin "Sai Hospital"
#define pass "chandigarh university"
queue<string> appoint;
vector<string> line;
stack<int> pos;
string in_admin, in_pass;
#define space ""
string name, opd_no, bed_no, attendant, address, doc_name, wid, test, disease, blood_grp, medicine, injection, payment, adhaar;

int age;

time_t now=time(0);



void clear_stack(){
	while(!pos.empty())
		pos.pop();
}

void read_file(){
	fstream obj("data.txt" );
	string a,b;
	line.clear();
	while(!obj.eof()){
		getline(obj,b);
		if(b==appoint.front()){
			while(!obj.eof()){
				getline(obj,b);
				if(b==space)
					break;
			}
			while(!obj.eof()){
				line.push_back(b);
				getline(obj,b);
				
				
			}
		}
	}
	
	obj.close();
}

void write_file(){
	fstream obj("data.txt" );
	string b;
	int c;
	string dt=ctime(&now);
	while(!obj.eof()){
		getline(obj,b);
		if(b==appoint.front()){
			while(!obj.eof()){
				pos.push(obj.tellg());
				getline(obj,b);
				if(b==space){
					pos.pop();
					obj.clear();
					obj.seekp(pos.top());
					obj<<dt<<"Disease: "<<disease<<endl<<"Tests: "<<test<<endl<<"Medicine: "<<medicine<<endl<<"Injection: "<<injection<<endl<<payment<<endl;
					for(int i=0;i<line.size();++i){
						obj<<line[i]<<endl;
					}
					obj.close();
					clear_stack();
					return;
				}
			}
		}
	}
	
	obj.close();
}

void write_file2(){
	fstream obj("data.txt" );
	string b;
	int c;
	string dt=ctime(&now);
	while(!obj.eof()){
		getline(obj,b);
		if(b==appoint.front()){
			while(!obj.eof()){
				pos.push(obj.tellg());
				getline(obj,b);
				if(b==space){
					pos.pop();
					obj.clear();
					obj.seekp(pos.top());
					obj<<dt<<"Disease: "<<disease<<endl<<"Tests: "<<test<<endl<<"Medicine: "<<medicine<<endl<<"Injection: "<<injection<<endl;
					obj<<"Doctor Name: "<<doc_name<<endl<<"Attendant Name: "<<attendant<<endl<<"OPD No.: "<<opd_no<<endl<<"Bed No.: "<<bed_no<<endl<<payment<<endl;
					for(int i=0;i<line.size();++i){
						obj<<line[i]<<endl;
					}
					obj.close();
					clear_stack();
					return;
				}
			}
		}
	}
	
	obj.close();
}

void add_more(){
	//fstream obj("data.txt" );
	char ch;
	string a,b;
	a=appoint.front();
	cout<<"(use comma[,] to seperate multiple inputs.)\n\n";
	cout<<"Enter Disease: ";
	getline(cin, disease);
	cout<<"Enter Tests: ";
	getline(cin, test);
	cout<<"Enter Medicine: ";
	getline(cin, medicine);
	cout<<"Enter Injection: ";
	getline(cin, injection);
	/*while(!obj.eof()){
		getline(obj,b);
		if(a==b){
			getline(obj,b);
			getline(obj,b);
			getline(obj,b);
			break;
		}
	}
	obj<<"Disease: "<<disease<<endl<<"Tests: "<<test<<endl<<"Medicine: "<<medicine<<endl<<"Injection: "<<injection<<endl;*/
	cout<<"Do you want to Admit the Patient(y/n): ";
	cin>>ch;
	cin.ignore();
	if(ch=='y' || ch=='Y'){
	cout<<"Enter Doctor Name: ";
	getline(cin, doc_name);
	cout<<"Enter Attendant Name: ";
	getline(cin, attendant);
	cout<<"Enter OPD number: ";
	getline(cin, opd_no);
	cout<<"Enter Bed number: ";
	getline(cin, bed_no);
	//obj<<"Doctor Name: "<<doc_name<<endl<<"Attendant Name: "<<attendant<<endl<<"OPD No.: "<<opd_no<<endl<<"Bed No.: "<<bed_no<<endl;
	}
	cout<<"Enter Mode of Payment (Cash / Card): ";
	getline(cin,payment);
	if(ch=='y' || ch=='Y'){
		read_file();
		write_file2();
	}
	else{
		read_file();
		write_file();
	}
	//obj.close();
}



void search_patient(){
	fstream obj("data.txt", ios::in);
	if(!obj)
     cout<<"can not open the file";
	string a,b;
	cout<<"Enter Patient Adhaar Number: ";
	getline(cin,a);
	while(!obj.eof()){
		getline(obj,b);
		if(a==b){
			getline(obj,b);
			cout<<"\nFound.\n";
			cout<<"Name: "<<b<<endl;
			getline(obj,b);
			cout<<"Age: "<<b<<endl;
			getline(obj,b);
			cout<<"Blood Group: "<<b<<endl;
			getline(obj,b);
			cout<<"Address: "<<b<<endl;
			getline(obj,b);
			while(b!=space){
				cout<<b<<endl;
				getline(obj,b);
			}
			getch();
			cin.ignore();
			cout<<"Returning";
			sleep(1);
			cout<<".";
			sleep(1);
			cout<<".";
			sleep(1);
			cout<<".";
			return;
		} 
	}
	cout<<"Patient Not Found.\n\n";
	obj.close();
	getch();
	cin.ignore();
	cout<<"Returning";
	sleep(1);
	cout<<".";
	sleep(1);
	cout<<".";
	sleep(1);
	cout<<".";
}
void display_all(){
	fstream obj("data.txt", ios::in);
	if(!obj)
    cout<<"can not open the file";
	string ca;
	while(!obj.eof()){
		getline(obj,ca);
		if(ca.empty())
		continue;
		cout<<ca<<endl;
	}
	obj.close();
}
void display(){
	fstream obj("data.txt", ios::in);
	if(!obj)
     cout<<"can not open the file";
	string na,g;
	na=appoint.front();
	cout<<"Name: ";
	while(!obj.eof()){
		getline(obj,g);
		if(g==na){
			cout<<g<<endl;
			getline(obj,g);
			cout<<"Age: ";
			cout<<g<<endl;
			getline(obj,g);
			cout<<"Blood Group: "<<g<<endl;
			getline(obj,g);
			cout<<"Address: "<<g<<endl;
			while(1){
				getline(obj,g);
				if(g==space){
					obj.close();
					return;
				}
				cout<<g<<endl;
			}
		}
	}
	obj.close();
}
void showq(queue<string> gq)
{
	int i=1;
    queue<string> g = gq;
    while (!g.empty()) {
        cout <<i<<". "<< g.front();
        i++;
        g.pop();
    }
    getch();
    cin.ignore();
    system("cls");
}
void add_patient(){
	fstream obj("data.txt", ios::out | ios::app);
	if(!obj)
     cout<<"can not open the file";
	cout<<"Enter Patient Adhaar number: ";
	getline(cin, adhaar);
	cout<<"Enter Patient Name: ";
	getline(cin, name);
	cout<<"Enter Age: ";
	cin>>age;
	cin.ignore();
	cout<<"Enter Blood Group: ";
	getline(cin,blood_grp);
	cout<<"Enter Address: ";
	getline(cin,address);
	obj<<adhaar<<endl<<name<<endl<<age<<endl<<blood_grp<<endl<<address<<endl<<space<<endl;
	system("cls");
	cout<<"Patient Added Successfully."<<endl;
	obj.close();
	cout<<"Returning";
	sleep(1);
	cout<<".";
	sleep(1);
	cout<<".";
	sleep(1);
	cout<<".";
}


void appointment(){
	fstream obj("data.txt", ios::in );
	if(!obj)
     cout<<"can not open the file";
	string apname,gname;
	cout<<"Enter Patient Adhaar Number: ";
	getline(cin,apname);
	while(!obj.eof()){
		getline(obj,gname);
		if(gname==apname){
			cout<<"Appointment Taken.\n";
			getline(obj,apname);
			appoint.push(apname);
			cout<<"Returning";
			sleep(1);
			cout<<".";
			sleep(1);
			cout<<".";
			sleep(1);
			cout<<".";
			return;
			obj.close();
		}
		
	}
	
			cout<<"No Such Patient.\n";
	obj.close();
	cout<<"Returning";
	sleep(1);
	cout<<".";
	sleep(1);
	cout<<".";
	sleep(1);
	cout<<".";
}


int main(){
	int b;
	char ch;
	int a;
	while(1){
cout<<"Enter Admin UserName: ";
getline(cin,in_admin);
cout<<"Enter Admin Password: ";
getline(cin, in_pass);

if(in_admin!=admin || in_pass!=pass){
	system("cls");
	cout<<"Invalid Credentials.\nPlease Try Again.\n";
	sleep(3);
	system("cls");
}
else{
system("cls");
cout<<"Welcome to Clinic management system.";
cout<<"\nCredentials are correct, Granting Access.";
sleep(1);
cout<<".";
sleep(1);
cout<<".";
sleep(1);
cout<<".";
sleep(1);
cout<<".";
sleep(1);
cout<<".";
system("cls");
break;
}
}
	while(1){
	cout<<"\nMain Menu\n\n";
	cout<<"\n P : Patient Branch \n";
	cout<<"\n D : Doctor Branch \n";
	cout<<"\n Q : Exit System \n";
	cout<<"\nPlease Enter the Aplhabet acoording to your choice: ";
	cin>>ch;
	if(ch>=97 && ch<=122){
		ch-=32;
	}
	system("cls");
	switch(ch){
		case 'P':
			do{
			cout<<"Patient Branch Menu\n\n";	
			 cout<<"\n[1] To Add a New Patient\n";
			 cout<<"\n[2] To Search for a Old patient\n";
			 cout<<"\n[3] To Take Appointment\n"; 
			 cout<<"\n[4] To go Back to Main Menu\n";
			 cout<<"\n\nEnter your choice: ";
			cin>>a;
			cin.ignore();
			system("cls");
			switch(a){
				case 1:
					add_patient();
					system("cls");
					break;
				case 2:
					search_patient();
					system("cls");
					break;
				case 3:
					appointment();
					system("cls");
					break;
				case 4:
					break;
				default:
					cout<<"Invalid Input.";
					sleep(3);
					cout<<"Returning.";
					sleep(1);
					cout<<".";
					sleep(1);
					cout<<".";
					sleep(1);
					cout<<".";
					system("cls");
			}
			}while(a!=4);
			break;
		case 'D':
			do{
			cout<<"\nPlease select for the given menu:\n\n";
			cout<<"\n[1] To check Appointments\n";
			cout<<"\n[2] To call-in Patient\n";
			cout<<"\n[3] To view Patient Details\n";
			cout<<"\n[4] To go Back to Previous Menu\n";
			cout<<"\n\nEnter your choice: ";
			cin>>a;
			cin.ignore();
			system("cls");
			switch(a){
				case 1:
					if(appoint.empty()){
								cout<<"No Appointments.\n";
								sleep(5);
								break;
							}
						system("cls");
					showq(appoint);
					break;
				case 2:
					while(1){
						if(appoint.empty()){
								cout<<"\n\nNo more Appointments.\n";
								getch();
								cin.ignore();
								system("cls");
								break;
							}
						cout<<"\nPlease select for the given menu:\n\n"; 
						cout<<"\n[1] to call-in "<<appoint.front(); 
						cout<<"\n[2] to go back to Previous Menu\n";
						cout<<"\n\nEnter your choice: ";
						cin>>b;
						cin.ignore();
						if(b==1){
							display();
							add_more();
							system("cls");
							appoint.pop();
							}
						else if(b==2)
							break;
						else{
							cout<<"Invalid Input.";
							sleep(2);
							system("cls");
							}
						}
						break;
				case 3:
					search_patient();
					system("cls");
					break;
				case 4:
					break;
				default:
					cout<<"Invalid Input.";
					sleep(3);
					cout<<"Returning.";
					sleep(1);
					cout<<".";
					sleep(1);
					cout<<".";
					sleep(1);
					cout<<".";
					system("cls");
				}
			}while(a!=4);
			break;
			
		case 'Q':
			break;
		default:
					cout<<"Invalid Input.\n";
					sleep(1);
					cout<<"Returning.";
					sleep(1);
					cout<<".";
					sleep(1);
					cout<<".";
					sleep(1);
					cout<<".";
					system("cls");
	}
	
}

}
