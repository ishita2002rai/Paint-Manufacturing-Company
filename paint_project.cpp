//VINAYAK PAINT MANUFACTURING COMPANY

//Paint Order and Sell 

// Header Files
#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
using namespace std;

//Defined class paint
class paint
{
	private:
		string code, name;
		float quantity, price;
		int u_id;
		string u_name,u_email,u_phone;
	public:
		void panel();
		void admin();
		void customer();
		void insert();  // Function in Admin Panel
		void search();
		void update();
		void del();
		void admin_check_order();
		void remove_order();  //Can't use function name as remove as remove is predefined function in system
		void display();
		void order_booking();
		void customer_check_order();
};

//Intro Panel
void intro()
{
	system("cls");
	cout<<"\n\n\n\n\n";
	cout<<"\t\t\t=====================================\n\n\n";
	cout<<"\t\t\t\t    ISHITA PAINT";
	cout<<"\n\n\n\t\t\t\tMANUFACTURING COMPANY";
	cout<<"\n\n\n\t\t\t=====================================";
	getch();
}

// Control Panel
void paint::panel()
{
	p:
	system("cls");  //Clear Screen each time
	int choice;
	string email, pass;
	char ch;
	cout<<"\n\t\tControl Panel";
	cout<<"\n\n 1. Admin Panel";
	cout<<"\n\n 2. Customer Panel";
	cout<<"\n\n 3. Exit";
	cout<<"\n\n Enter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			system("cls");
			cout<<"\n\n\t Login Account";
			cout<<"\n\nE-Mail: ";
			cin>>email;
			cout<<"\n\nPassword: ";
			
			for(int i=1;i<=7;i++)
			{
				ch= getch();
				pass+=ch;
				cout<<"*";
			}
			if(email=="ishita28rai@gmail.com" && pass=="ishita")
			{
				cout<<"\n\nLogin Successful";
				Sleep(1500);
				admin();
			}
			else
			{
				cout<<"\n\nEither e-amil or password is wrong.";
				goto p;
			}	
			break;
		case 2:
			customer();
		case 3:
			exit(0);
		default:
			cout<<"\n\nInvalid Value... Please try again...";
			goto p;
	}
	getch();
}

// Admin Panel
void paint::admin()
{
	p:
	system("cls");  //Clear Screen each time
	int choice;
	cout<<"\n\t\tAdmin Panel";
	cout<<"\n\n 1. Add New Paint";
	cout<<"\n\n 2. Search Paint";
	cout<<"\n\n 3. Update Paint";
	cout<<"\n\n 4. Delete Paint";
	cout<<"\n\n 5. Check Orders";
	cout<<"\n\n 6. Remove Orders";
	cout<<"\n\n 7. Go Back to Control Panel";
	cout<<"\n\n Enter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			insert();
			break;
		case 2:
			search();
			break;
		case 3:
			update();
			break;
		case 4:
			del();
			break;
		case 5:
			admin_check_order();
			break;
		case 6:
			remove_order();
			break;
		case 7:
			panel();
		default:
			cout<<"\n\nInvalid Value... Please try again...";
		}
		getch();
		goto p;
}

// Customer Panel
void paint::customer()
{
	p:
	system("cls");  //Clear Screen each time
	int choice;
	cout<<"\n\t\tCustomer Panel";
	cout<<"\n\n 1. Display Paints";
	cout<<"\n\n 2. Order Booking";
	cout<<"\n\n 3. Check Orders";
	cout<<"\n\n 4. Go Back to Control Panel";
	cout<<"\n\n Enter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			display();
			break;
		case 2:
			order_booking();
			break;
		case 3:
			customer_check_order();
			break;
		case 4:
			panel();
		default:
			cout<<"\n\nInvalid Value... Please try again...";
	}
	getch();
	goto p;
}

//Insert Paint at Admin End
void paint::insert()
{
	p:
	system("cls");
	fstream file; 
	string c,n;
	float p,q;
	cout<<"\n\n\t\t Add New Paint";
	cout<<"\n\n\n Paint Code: ";
	cin>>code;
	cout<<"\n\n Paint Name: ";
	cin>>name;
	cout<<"\n\n Price: ";
	cin>>price;
	cout<<"\n\n Quantity: ";
	cin>>quantity;
	file.open("paint.txt",ios::in);
	if(!file){
		//Sending data to a txt file
		file.open("paint.txt",ios::app|ios::out);
		file<<" "<<code<<" "<<name<<" "<<price<<" "<<quantity<<"\n";
		file.close();
		cout<<"\n\nData Successfully added";
	}
	else{
		file>>c>>n>>p>>q;
		while(!file.eof()) //Check when there is end of file
		{
			if(c==code)
			{
				file.close();
				Sleep(1500);
				cout<<"\n\n Paint Code Already Exists... Enter new code...";
				getch();
				goto p;
			}
			file>>c>>n>>p>>q;
		 }
		 file.close(); 
		 file.open("paint.txt",ios::app|ios::out);
		 file<<" "<<code<<" "<<name<<" "<<price<<" "<<quantity<<"\n";
		 file.close();
		 cout<<"\n\nData Successfully added";
	}
}

//Search Paint at Admin End
void paint::search()
{
	system("cls");
	string c; 
	int found=0;
	fstream file;
	cout<<"\n\n\t Search Paint ";
	cout<<"\n\n Paint Code: ";
	cin>>c;
	file.open("paint.txt",ios::in);
	if(!file)
	{
		admin();
	}
	else
	{
		file>>code>>name>>price>>quantity;
		while(!file.eof())
		{
			if(c==code){
				system("cls");
				cout<<"\n\n\t Search Paint";
				cout<<"\n\n Paint Code: "<<code;
				cout<<"\n\n Paint Name: "<<name;
				cout<<"\n\n Paint Price: "<<price;
				cout<<"\n\n Paint Quantity: "<<quantity;
				found++;
			}
			file>>code>>name>>price>>quantity;
		}
		file.close();
		if(found==0)
		cout<<"\n\n Paint Code Not Found";
	}
}

//Update Paint at Admin End
void paint::update()
{
	system("cls");
	fstream file, file1;
	string c,n;
	float p,q;
	int found=0;
	cout<<"\n\n\t\tUpdate Paint";
	cout<<"\n\nPaint Code: ";
	cin>>c;
	file.open("paint.txt",ios::in);
	if(!file)
	{
		cout<<"No such record present.";
		admin();
	}
	else
	{
		file1.open("paint1.txt",ios::app|ios::out);
		file>>code>>name>>price>>quantity;
		while(!file.eof())
		{
			if(c==code)
			{
				cout<<"\n\n Enter new paint name: ";
				cin>>n;
				cout<<"\n\nEnter new paint price: ";
				cin>>p;
				cout<<"\n\nEnter new paint quantity: ";
				cin>>q;
				file1<<" "<<code<<" "<<n<<" "<<p<<" "<<q<<"\n";
				found++;
			}
			else
			file1<<" "<<code<<" "<<name<<" "<<price<<" "<<quantity<<"\n";
			file>>code>>name>>price>>quantity;
		}
		file.close();
		file1.close();
		remove("paint.txt");
		rename("paint1.txt","paint.txt");   //Format- (Old Name, New Name)
		if(found==0)
		{
			cout<<"Record Not Found.";
		}
		else
		{
			cout<<"Record Updated.";
		}
	}
}

//Delete Paint at Admin End
void paint::del()
{
	system("cls");
	fstream file, file1;
	string c;
	int found=0;
	cout<<"\n\n\t\tDelete Paint";
	cout<<"\n\nPaint Code: ";
	cin>>c;
	file.open("paint.txt",ios::in);
	if(!file)
	{
		cout<<"No such record present.";
		admin();
	}
	else
	{
		file1.open("paint1.txt",ios::app|ios::out);
		file>>code>>name>>price>>quantity;
		while(!file.eof())
		{
			if(c==code)
			{
				cout<<"\n\nRecord Deleted Successfully.";
				found++;
			}
			else
			file1<<" "<<code<<" "<<name<<" "<<price<<" "<<quantity<<"\n";
			file>>code>>name>>price>>quantity;
		}
		file.close();
		file1.close();
		remove("paint.txt");
		rename("paint1.txt","paint.txt");   //Format- (Old Name, New Name)
		if(found==0)
		{
			cout<<"Record Not Found.";
		}
		else
		{
			cout<<"\n\nRecord Updated.";
		}
	}
}


//Check order at admin end
void paint::admin_check_order()
{
	system("cls");
	int found=0;
	fstream file;
	cout<<"\n\t\t Admin Check Orders";
	file.open("order.txt",ios::in);
	if(!file)
	{
		cout<<"\n\n No Order in pending state.";
		Sleep(1500);
		admin();
	}
	else
	{
		file>>u_id>>u_name>>u_email>>u_phone;
		while(!file.eof())
		{
			cout<<"\n\nUser I'd: "<<u_id;
			cout<<"\n\nUser Name: "<<u_name;
			cout<<"\n\nUser E-Mail: "<<u_email;
			cout<<"\n\nUser Phone Number: "<<u_phone;
			found++;
			file>>u_id>>u_name>>u_email>>u_phone;
		}
		file.close();
		if(found==0)
		{
			cout<<"\n\n No Order in pending state.";
		}
	}
}


//Remove order at admin end
void paint::remove_order()
{
	system("cls");
	fstream file,file1;
	int found=0,id;
	cout<<"\n\n\t\tRemove Order";
	cout<<"\n\n User I'd: ";
	cin>>id;
	file.open("order.txt",ios::in);
	if(!file)
	{
		cout<<"\n\n Record Not Found";
		Sleep(1500);  //Sleep Time in miliseconds
		admin();
	}
	else
	{
		file1.open("order1.txt",ios::app|ios::out);
		file>>u_id>>u_name>>u_email>>u_phone;
		while(!file.eof())
		{
			if(id==u_id)
			{
				cout<<"\n\n Order Removed Successfully.";
				found++;
			}
			else
			{
				file1<<" "<<u_id<<" "<<u_name<<" "<<u_email<<" "<<u_phone<<"\n";
			}
			file>>u_id>>u_name>>u_email>>u_phone;
		}
		file.close();
		file1.close();
		remove("order.txt");
		rename("order1.txt","order.txt");
		if(found==0)
		{
			cout<<"\n\nRecord Not Found";
		}
	}
}

//Display paints at customer end
void paint::display()
{
	system("cls");
	fstream file;
	int found=0;
	cout<<"\n\n\t\t Display Paints";
	file.open("paint.txt",ios::in);
	if(!file)
	{
		cout<<"No Paints Available";
		Sleep(1500);
		customer();
	}
	else
	{
		file>>code>>name>>price>>quantity;  //Don't change sequence
		while(!file.eof())
		{
			cout<<"\n\n\n Paint Code: "<<code;
			cout<<"\n\nPaint Name: "<<name;
			cout<<"\n\nPaint Price: "<<price;
			cout<<"\n\nPaint Quantity: "<<quantity;
			found++;
			file>>code>>name>>price>>quantity; 
		}
		file.close();
		if(found==0)
		{
			cout<<"Record Not Found";
		}
	}
}


//Order booking at customer end
void paint::order_booking()
{
	system("cls");
	fstream file;
	int found=0,id;
	string n,e,p;
	cout<<"\n\n\t\tOrder Booking";
	cout<<"\n\nName: ";
	cin>>u_name;
	cout<<"\n\nE-Mail: ";
	cin>>u_email;
	cout<<"\n\nPhone Number: ";
	cin>>u_phone;
	file.open("order.txt",ios::in);
	//Check if file exists or not
	if(!file)
	{
		file.open("order.txt",ios::app|ios::out);
		u_id=1000;
		file<<" "<<u_id<<" "<<u_name<<" "<<u_email<<" "<<u_phone<<"\n";
		file.close();
	}
	else
	{
		file>>id>>n>>e>>p;
		while(!file.eof())
		{
			found++;
			file>>id>>n>>e>>p;
		}
		file.close();
		file.open("order.txt",ios::app|ios::out);
		//Check if there is data in the file or not
		if(found==0)
		{
			u_id=1000;
			file<<" "<<u_id<<" "<<u_name<<" "<<u_email<<" "<<u_phone<<"\n";
		}
		else
		{
			u_id=id+1;
			file<<" "<<u_id<<" "<<u_name<<" "<<u_email<<" "<<u_phone<<"\n";
		}
		file.close();
	}
	cout<<"\n\nYour User I'd is: "<<u_id;
	cout<<"\n\nContact Details Submitted Successfully.";
	cout<<"Someone from our team will contact you soon.";
}


//Check order at customer end
void paint::customer_check_order()
{
	system("cls");
	fstream file;
	int id,found=0;
	cout<<"\n\n\t\tCheck Order";
	cout<<"\n\nUser I'd: ";
	cin>>id;
	file.open("order.txt",ios::in);
	if(!file)
	{
		cout<<"\n\nNo such order";
		Sleep(1500);
		customer();
	}
	else
	{
		file>>u_id>>u_name>>u_email>>u_phone;
		while(!file.eof())
		{
			if(id==u_id)
			{
				cout<<"\n\nYour order is in pending state.";
				found++;
			}
			file>>u_id>>u_name>>u_email>>u_phone;
		}
		file.close();
		if(found==0)
		{
			cout<<"\n\nNO such order found";
		}
	}
}

//Main Function
main(){
	//Object created of class
	paint p;
	intro();  
	p.panel();
}
