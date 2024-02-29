#include<iostream>
using namespace std;
class hotel
{
	protected:
	char name[30];
	char ph_num[13];
	string email;
	char n;char date[9];
		
	public:
	    hotel()
		{
		cout<<"===================================="<<endl;
		cout<<"     WELCOME TO HOTEL DE LUNA       "<<endl;
		cout<<"===================================="<<endl;
		cout<<"FACLITIES"<<endl;
		cout<<"free wifi"<<endl<<"parking"<<endl<<"non-smoking rooms"<<endl;
		} 	
};
class booking:public hotel
{   
	public:
    	booking()
    	{
    	cout<<"enter N for booking"<<endl;
    	cin>>n;
    	cout<<"share your information"<<endl;
    	cout<<"enter name"<<endl;
    	cin>>name;
    	cout<<"enter date of the day you want booking for";
    	cin>>date;
    	cout<<"phone.no"<<endl;
		cin>>ph_num;
    	cout<<"email"<<endl;
		cin>>email;
		}
		void menu()
		{
			cout<<"charge for 1 day = 3000"<<endl;
			cout<<"Options for Rooms"<<endl;
			cout<<"___________________________"<<endl;
			cout<<"|Room              Charges|"<<endl;
			cout<<"|Standard Room     10,000 |"<<endl;
			cout<<"|Triple Room       15,000 |"<<endl;
			cout<<"|VIP Room          30,000 |"<<endl;
			cout<<endl;
			cout<<"Food services"<<endl;
			cout<<"____________________________"<<endl;
			cout<<"All Three Meals 10,000"<<endl;
			cout<<"Only Breakfast  5,000"<<endl;
		}
	
};
class days
{   protected:
	    int day,choice,more,dayss,r,meal_m;
    public:
    	virtual void select()
    	{
    	cout<<"for how many days you want to book a room ";
		cin>>day;
		dayss= 3000*day;
		}
	    virtual void disp()
		{
			cout<<"charge for" <<day<<"day is"<<dayss<<endl;
		}
	
};
class rooms:public days
{

	public:
   	    void select()
        {
      	
   	    cout<<"press 1 for standrad room"<<endl<<"press 2 for triple room"<<endl<<"press 3 for VIP room"<<endl;
   	    cin>>choice;
   	    switch(choice)
	    {
		    case 1:
			cout<<"standrad room"<<endl;
			cout<<"how many room you want";cin>>more;
			r=10000*more;
			break;
		    case 2:
			cout<<"triple room"<<endl;
			cout<<"how many room you want";cin>>more;
			r=15000*more;
			break;
		    case 3:
			cout<<"VIP room"<<endl;
			cout<<"how many room you want";
			cin>>more;
			r=30000*more; 
			break;
		    default :
		    cout<<"invalid";
	    }
        }
        void disp()
		{
			cout<<"charge for room/rooms is "<<r<<endl;
		}

};
class meals:public rooms
{
	public:
	void select()
	{   
		cout<<"press 1 for all three meals "<<endl<<"press 2 for only breakfast"<<endl<<"press 3 for none"<<endl;
   	    cin>>choice;
   	    switch(choice)
	    {
		    case 1:
			cout<<"all three meals for"<<day<<"days"<<endl;
			meal_m=(10000*day);
			break;
		    case 2:
			cout<<"only breakfast"<<endl;
			meal_m=(5000*day);
			break;
		    case 3:
			cout<<"thank you!"<<endl;
			meal_m=(0*day);
			break;
		    default :
		    cout<<"invalid";
	    }
    } 
    void disp()
    {
    	cout<<"charge for your meal choice is "<<meal_m<<endl;
	}
};
 
class expenses : public meals
{
public:
    void calculateExpenses()
   { 

    days *ptr = new days;
	ptr->disp();
	rooms obj1;meals obj2;
    ptr=&obj1;ptr->disp();
    ptr=&obj2;ptr->disp(); 
	int totalExpenses =120 ;
    cout << "Total expenses: " << totalExpenses << endl;
	}
};

	
int main()
{
	booking bk;
	bk.menu();
    days *ptr= new days;
    ptr->select();
    rooms obj1;meals obj2;
    ptr=&obj1;ptr->select();
    ptr=&obj1;ptr->disp();
    ptr=&obj2;ptr->select();
    ptr=&obj2;ptr->disp();
    expenses total;
    total.calculateExpenses();
 
}
