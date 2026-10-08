#include<iostream>
#include<string.h>
#include <iomanip>
#include <ctime>
using namespace std;

			//Class Customer
class Customer
{
	string name;	   			 //CUSTOMER FULL NAME
	string address;				//CUSTOMER ADDRESS
	string phone;				//CONTACT NUMBER
	int days=0;	    			//DURATION OF STAY
	float payment_advance;		//ADVANCE PAYMENT
	double bill=0;				//BILL AMT
	int booking_id;				//BOOKING ID
	int room;					//ROOM NO
	int status;
public:
	Customer()
{
		days=0;
		payment_advance=0;
		bill=0;
		booking_id=0;
		status=0;
		room=0;
}
	void accept();				//ACCEPT CUSTOMER DETAILS
	void display();				//DISPLAY CUSTOMER DETAILS
	friend class room;
	friend class Hotel;
};
void Customer::accept()		//ACCEPTING CUSTOMER DETAILS
{
	cout<<"Enter customer name: ";
	getline(cin, name);
	getline(cin, name);
	cout<<"Enter Customer address: ";
	getline(cin,address);
	flag:
	cout<<"Enter mobile number: ";
	cin>>phone;
	for(int i=0;i<(phone.length());i++)	//PHONE NUMBER VALIDATIONS
  	{									//PHONE NUMBER NEEDS TO BE ALL DIGITS AND 10 IN LENGTH
		if(!isdigit(phone[i]))
		{
			cout<<"Phone number has to be in digits.\n";
			goto flag;
		}
  	}
  	if(phone.length()!=10)		//PHONE LENGTH VALIDATIONS
  	{
  	  cout<<"Phone number should be 10 digits.\n";
  	  goto flag;
 	 }
}
//

void Customer::display()		//DISPLAYING CUSTOMER DETAILS
{
	cout<<booking_id<<"\t\t";
	cout<<"| "<<left<<setfill(' ')<<setw(30)<<name;
	cout<<"| "<<phone<<"\t\t\t";
	cout<<"| "<<left<<setfill(' ')<<setw(30)<<address;
	cout<<"| "<<room<<"\t\t\t";
	if(status==1){cout<<"|\t\t-\t\t|"<<endl;}
	else{cout<<"|\tCHECKED OUT.\t\t|"<<endl;}
}
    //CLASS ROOM
	//TO STORE DATA OF ALL ROOMS IN THE HOTEL
class Room
{
	char type;				//COMFORT SUITE OR NORMAL ROOM
	char stype;				//BIG SIZE OR SMALL SIZED ROOM
	char ac;				//AC OR NON AC
	int roomNumber;			//ROOM NUMBER
	double rent;			//DAILY RENT OF ROOM
	int status=0;			//ROOM IS BOOKED OR NOT
public:
	friend class Hotel;
	void acceptroom(int rno);		//ADD ROOMS TO HOTEL DATABASE
	void displayroom();		//DISPLAY ROOMS
	Room()					//DEFAULT CONSTRUCTOR
	{
		type='\0';
		stype='\0';
		ac='\0';
		roomNumber=0;
		rent=0;
		status=0;
	}
};
void Room::acceptroom(int rno)		//ACCEPTING ALL ROOM DETAILS
{
	roomNumber=rno;	//ROOM NUMBER
	cout<<"Type AC/Non-AC (A/N) : ";
	cin>>ac;
	while(ac!='A'&& ac!='N')		//VALIDATIONS
	{
		cout<<"Please Re-Enter Type: AC/Non-AC (A/N) : ";
		cin>>ac;
	}
	cout<<"Type Comfort Suite or Normal (S/N) : ";
	cin>>type;
	while(type!='S' && type!='N')
	{
		cout<<"Please Re-enter Type Comfort Suite or Normal (S/N) : ";
		cin>>type;
	}
	cout<<"Type Size (B/S) : ";
	cin>>stype;
	while(stype!='B'&& stype!='S')
	{
		cout<<"Please Re-enter Type Size (B/S) : ";
		cin>>stype;
	}
	cout<<"Daily Rent : ";
	cin>>rent;
	while(rent<0 || rent>20000)
	{
		cout<<"Please enter valid rent.";
		cin>>rent;
	}
	status=0;	//BOOKING STATUS OF THE ROOM
	cout<<"\nRoom Added Successfully!"<<endl;
}
void Room::displayroom()
{
	cout<<"| "<<roomNumber<<".\t\t|\t"<<ac<<"\t\t|\t"<<type<<"\t\t|\t"<<stype<<"\t\t|\t"<<rent<<"\t\t|\t";
	if(status==0){cout<<"Available.\t|";}
	else{cout<<"Booked.\t\t|";}
	cout<<endl;
}
//class Hotel
class Hotel
{
	Room a[100];			//ARRAY OF ROOMS
	Customer c[100];			//ARRAY OF CUSTOMERS
	int nroom=0, ncust=0;	//NO OF ROOMS AND CUSTOMERS
public:
	void addRooms();		//ADD ROOMS TO DATABASE
	void searchroom();		//SEARCH FOR A PARTICULAR ROOM
	void CheckIn();			//FOR CUSTOMER CHECKIN
	void searchcust();		//SEARCH WHETHER A PARTICULAR CUSTOMER IS STAYING AT THE HOTEL
	void availability();	//CHECK AVAILABILITY OF ROOMS
	void CheckOut();		//CHECKOUT AND BILLING PROCEDURE
	void Summary();			//GUEST SUMMARY
};
void Hotel::addRooms()
{
	int rno;
	cout<<"Enter number of rooms: ";
	cin>>nroom;		//ACCEPTING NUMBER OF ROOMS
	while(nroom<=0)
	{
		cout<<"Invalid. Enter valid number of rooms.";
		cin>>nroom;
	}
	for(int i=0;i<nroom;i++)
	{
		cout<<"ROOM "<<(i+1)<<endl;
		flag:
		cout<<endl<<"Enter room number : ";
		cin>>rno;
		if(rno<=0)		//VALIDATIONS
		{
			cout<<endl<<"This room number is invalid! Please Re-enter the room number : ";
			goto flag;
		}
		for(int i=0; i<nroom;i++)	//VALIDATIONS FOR REPETITIVE ROOM NUMBERS
		{
			if(a[i].roomNumber==rno)
			{
				cout<<"Invalid. Repetitive room numbers."<<endl;
				goto flag;
			}
		}
		a[i].acceptroom(rno);		//CALLING FUNCTION ACCEPT ROOM FROM CLASS ROOM
	}
}
void Hotel::availability()		//CHECKING AVAILABILITY OF THE ROOMS
{
	if(nroom==0)
	{
		cout<<"Please add rooms."<<endl;
		return;
	}
	cout<<"The list of all available rooms:"<<endl;
	cout<<"| Room No.\t|\tAC/Non-AC\t|\tType\t\t|\tStype\t\t|\tRent\t\t|\tAvailability  \t|"<<endl;
	for(int i=0;i<nroom;i++)
	{
		a[i].displayroom();	//DISPLAYING ROOM DETAILS
	}
}
void Hotel::searchroom()	//SEARCH FOR A PARTICULAR TYPE OF A ROOM
{
	if(nroom==0)
	{
		cout<<"Please add rooms."<<endl;
		return;
	}
	int flag=0;
	char ac1, type1, stype1;
	cout<<"Do you want AC or Non-AC? (A/N): "<<endl;
	cin>>ac1;
	cout<<"Do you want suite or normal room?"<<endl;
	cin>>type1;
	cout<<"Size? (B/S)"<<endl;
	cin>>stype1;
	for(int i=0;i<nroom;i++)
	{
		if(a[i].ac==ac1 && a[i].type==type1 && a[i].stype==stype1)		//MAKING SURE ALL CONDITIONS ARE SATISFIED
		{
			flag=1;
			cout<<"Room found"<<endl;
			a[i].displayroom();
		}
	}
	if(flag==0)
	{
		cout<<"No such room is available."<<endl;
	}
}
void Hotel::CheckIn()		//CHECK IN OF A CUSTOMER
{
	if(nroom==0)
	{
		cout<<"Please add rooms."<<endl;
		return;
	}
	int i, rno;
	if(ncust<=nroom){	//CHECKING CONDITION IF HOTEL HAS EMPTY ROOMS
		c[ncust].booking_id=ncust+1;	//ALLOTING CUSTOMER ID TO THE CUSTOMER
		flag:
		int flag1=0;
		cout<<"Enter room number=";		//ASKING WHAT ROOM NUMBER CUSTOMER WANTS TO STAY IN
		cin>>rno;
		for(i=0;i<nroom; i++){
			if(rno==a[i].roomNumber)
			{
				flag1=1;
				break;
			}
		}
		if(flag1==0){
			cout<<"Invalid room number. Please Enter again.\n";
			goto flag;
		}
		if(a[i].status==0)		//CHECKING IF ROOM IS UNOCCUPIED
		{
			char ch2;
			cout<<"Room available."<<endl;
			a[i].displayroom();
			cout<<"Do you wish to continue? Press(Y/y)";		//CONFIRMATION
			cin>>ch2;
			if(ch2=='Y'||ch2=='y')
			{
				c[ncust].accept();		//ACCEPTING CUSTOMER DETAILS
				cout<<"Enter number of days of stay: ";
				cin>>c[ncust].days;
				c[ncust].bill = c[ncust].days*a[i].rent;		//generating bill. bill= No. of days * rent per day.
				cout<<"Your total bill will approx be Rs."<<(c[ncust].bill)<<"."<<endl<<". Min adv payment="<<c[ncust].bill/4<<"What will you be paying?";
				cin>>c[ncust].payment_advance;
				while(c[ncust].payment_advance<c[ncust].bill/4||c[ncust].payment_advance>c[ncust].bill)
				{
					cout<<"Enter valid amount.";
					cin>>c[ncust].payment_advance;
				}
				cout<<"Thank you. Booking confirmed."<<endl;		//confirmed booking
				cout<<"--------------------------------------------------------------"<<endl;		//printing booking details
				cout<<"Booking Id: "<<c[ncust].booking_id<<"\nName: "<<c[ncust].name<<"\nRoom no.: "<<rno<<"\nDate: ";
				time_t my_time = time(NULL);
						// ctime() used to give the present time
				printf("%s", ctime(&my_time));
				a[i].status=1;		//changing room status to booked
				c[ncust].room=rno;		//alloting room to customer
				c[ncust].status=1;
				ncust++;
			}
			else		//if needs to change room number
			{
				goto flag;
			}
		}
		else		//if room is occupied
		{
			cout<<"Room Occupied. Please choose another room."<<endl;
		}
	}
	else		//CONDITION ALL ROOMS ARE BOOKED
	{
		cout<<"Sorry! Hotel is Full."<<endl;
	}
}
void Hotel::searchcust()
{
	int id, flag=0;
	cout<<"Enter booking id of customer.";
	cin>>id;
	for(int i=0;i<=ncust;i++)		//SEARCHING FOR CUSTOMER
	{
		if(c[i].booking_id==id)
		{
			cout<<"\t\t\t Name"<<setw(20);
			cout<<"\t\t\t Phone"<<setw(20);
			cout<<"\t\t\t Address"<<setw(20);
			cout<<"\t\t\tRoom no: "<<setw(20)<<endl;
			c[i].display();
			flag=1;
		}
	}
	if(flag==0)		//case not found
	{
		cout<<"No customer found."<<endl;
	}
}
void Hotel::CheckOut()		//CHECKING OUT
{
	int rno, i, j;
	cout<<"Enter room number= ";
	cin>>rno;
	for(j=0;j<nroom; j++){
		if(rno==a[j].roomNumber)
		{
			break;
		}
	}
	if(a[j].status==0)		//IF ROOM NOT FOUND OCCUPIED
	{
		cout<<"Invalid."<<endl;
	}
	for(i=0;i<ncust;i++)	//CHECKING CUSTOMER DETAILS
	{
		if(c[i].room==rno)
		{
			cout<<"CHECKING OUT."<<endl;
			c[i].display();		//CUSTOMER DETAILS
			cout<<"Your total bill is "<<c[i].bill<<endl;
			cout<<"Adv payment: "<<c[i].payment_advance;
			cout<<endl<<"Hence, pending payment= Rs."<<c[i].bill-c[i].payment_advance;		//PENDING PAYMENTS
			cout<<endl<<"Thank you! Visit Again :)"<<endl;
			a[j].status=0;	//CHANGING STATUS OF ROOM TO UNOCCUPIED
			c[i].status=0;	//CHECKED OUT
			break;
		}
	}
}
void Hotel::Summary()		//PRINTING LIST OF ALL CUSTOMERS
{
	if(nroom==0)
	{
		cout<<"No customers as yet."<<endl;
		return;
	}
	cout<<"Guest Summary:"<<endl;
	cout<<"Id.\t\t";
	cout<<"|	Name	\t\t";
	cout<<"|	Phone	\t\t";
	cout<<"|	Address	\t\t";
	cout<<"|	Room no	: \t";
	cout<<"|	Status	\t\t|"<<endl;
	for(int i=0;i<ncust;i++)
	{
		c[i].display();
	}
}

int main()
{
	Hotel Taj;		//CREATING OBJECT OF CLASS HOTEL
	char ch;
	cout<<endl<<"======================================================================================WELCOME TO TAJ GROUP OF HOTELS========================================================================================";
	do
	{		//MENU TO USE AS EITHER ADMIN OR WHEN A CUSTOMER ENTERS
		cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout<<endl<<"\t\t\t\t\t\t\t\t\t\t\t"
				"MENU:\n\t\t\t\t\t\t\t\t\t\t\t"
				"1.OPERATE AS ADMIN\n\t\t\t\t\t\t\t\t\t\t\t"
				"2.OPERATE AS CUSTOMER\n\t\t\t\t\t\t\t\t\t\t\t"
				"3.EXIT\n\t\t\t\t\t\t\t\t\t\t\t"
				"Enter your choice:";
		cin>>ch;
		switch(ch)
		{
		case '1':
			cout<<"Add database of rooms in the hotel:"<<endl;
			Taj.addRooms();
			cout<<"Database updated. Going back to main menu."<<endl;
			break;
		case '2':
			char ch1;
			do
			{
				//MENU 2 TO USE WHEN A CUSTOMER WANTS TO CHECK IN
				cout<<endl<<"*************************************************************************************************************************************************************************************************"<<endl;
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~WELCOME TO TAJ GROUP OF HOTELS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
				cout<<"\n\t\t\t\t\t\t\t\t\t\t\t"
						"Menu:\n\t\t\t\t\t\t\t\t\t\t\t"
						"1.Check Availability of rooms.\n\t\t\t\t\t\t\t\t\t\t\t"
						"2.Search Room\n\t\t\t\t\t\t\t\t\t\t\t"
						"3.Check In\n\t\t\t\t\t\t\t\t\t\t\t"
						"4.Search Customer\n\t\t\t\t\t\t\t\t\t\t\t"
						"5.Guest Summary\n\t\t\t\t\t\t\t\t\t\t\t"
						"6.Checkout.\n\t\t\t\t\t\t\t\t\t\t\t"
						"7.Go back to Main Menu.\n\t\t\t\t\t\t\t\t\t\t\t"
						"Enter your choice:";
				cin>>ch1;
				switch(ch1)
				{
				case '1':
					Taj.availability();
					break;
				case '2':
					Taj.searchroom();
					break;
				case '3':
					Taj.CheckIn();
					break;
				case '4':
					Taj.searchcust();
					break;
				case '5':
					Taj.Summary();
					break;
				case '6':
					Taj.CheckOut();
					break;
				case '7':
					break;
				default:
					cout<<"Invalid Choice."<<endl;
					break;
				}
			}while(ch1!='7');
			break;
		case '3':
			cout<<"Thank you!";
			exit(0);
		default:
			cout<<"Invalid Choice."<<endl;
			break;
		}
	}while(ch!='3');
	return 0;
}
