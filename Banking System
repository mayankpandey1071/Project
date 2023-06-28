#include<bits/stdc++.h>
using namespace std;
long long account_generator=22113344;
int pos;
struct bank
{
	string customer_name[2];
	int pin;
	long long  account_number;
	long long ammount;
}customer[10];       // here i have declared array of bank stucture with size 10
                    // you can increase array size as much you want
  
void menu()
{   cout<<"Enter 0 for create bank account \n";
	cout<<"1. Enter 1 for check your balance \n2. Enter 2 for Deposite ammount\n";
	cout<<"3. Enter 3 for Withdraw ammount \n4. Enter 4 for Transfer Ammount (to other account)\n";
	cout<<"5. Enter 5 to Exit\n";
}   
void createAccount()   // create account   
                          // I have not using any king of validation 
                          // like whether entered customer is already have a acount or pos have reached its max limit etc.
{
	cout<<"Enter your first name\n";    
	cin>>customer[pos].customer_name[0];
	cout<<"Enter your last name\n"; 
	cin>>customer[pos].customer_name[1];
	cout<<"Your account number is : ";
	customer[pos].account_number=account_generator+6;
	cout<<customer[pos].account_number<<endl;
	cout<<"Enter you pin number:\n";
	cin>>customer[pos].pin;
	customer[pos].ammount=0;     // ammount is integer value
	cout<<"Detail: \n";
	cout<<"Name : "<<customer[pos].customer_name[0]<<" "<<customer[pos].customer_name[1]<<endl;
	cout<<"Account Number: "<<customer[pos].account_number<<"\t\t Ammount: "<<customer[pos].ammount<<"\n\n";
	pos++;  // increase number of customer 
	account_generator+=6;  // so that next time also make a unique account number
}
void BalanceCheck()
{    long long ant;
    cout<<"Enter your account number : ";
    cin>>ant;
	int pin,tpos;
	cout<<"Please enter your pin\n";
	for(int j=0;j<3;j++)   // it wiil give you 3 chance to enter the pin 
	{
	cin>>pin;
	bool flag=false;
	for(int i=0;i<10;i++)
	{
		if(customer[i].pin==pin and customer[i].account_number==ant)
		{
		  tpos=i;
		 flag=true;
		 break;
		}
	}
	if(flag)
    {
    cout<<"Account Number: "<<customer[tpos].account_number<<endl;
	cout<<"Your Current balance : "<<customer[tpos].ammount<<"\n\n";
	break;
     }    
	else
	cout<<" You have entered wrong pin. plase re enter: ";
    } 
}

void Deposite()
{   
long long an; 
cout<<"Please enter your account number:\n";
cin>>an;
bool flag=false;
	for(int i=0;i<10;i++)
	{
		if(customer[i].account_number==an)
		{
		 int pn;
	      cout<<"Enter your pin: ";
	      cin>>pn;	
	         if(pn!=customer[i].pin) break;
	         int money;
	         cout<<"Enter ammount to want deposite : ";  // use validate that user should enter only positive value;
	         cin>>money;
	         customer[i].ammount+=money;
		 flag=true;
		 break;
		}
	}
	if(flag)
	{ 
	cout<<"Deposite Succefully \n\n";
	}
	else
	cout<<"Invalid Entery\n\n";
}

void Withdraw()

{
	long long an; 
cout<<"Please enter your account number:\n";
cin>>an;
bool flag=false;
	for(int i=0;i<10;i++)
	{
		if(customer[i].account_number==an)
		{
		 int pn;
	      cout<<"Enter your pin: ";
	      cin>>pn;	
	         if(pn!=customer[i].pin) break;
	         int money;
	         cout<<"Enter ammount to want Withdraw : ";
	         cin>>money;
	         if(money<=customer[i].ammount)   // ammout should be in account
	         customer[i].ammount-=money;
	         else
	         {
	         cout<<"Cann't Withdraw\n";
	         break;
	         }
		 flag=true;
		 break;
		}
	}
	if(flag)
	{ 
	cout<<"Deposite Succefully \n\n";
	}
	else
	cout<<"Invalid Entery\n\n";
	
}

void Transfer()
{
	long long S_ant, D_ant;
	cout<<"Enter your Account Number : ";
	cin>>S_ant;
	for(int i=0;i<10;i++)
	{
		if(customer[i].account_number=S_ant)
		{
			cout<<"Enter Reciever Account number : ";
			cin>>D_ant;
			for(int j=0;j<10;j++)
			{
				if(D_ant==customer[j].account_number)
				{
					int pin;
					cout<<"Enter your pin number : ";
					cin>>pin;
					if(pin==customer[i].pin)
					{
						int amount;
						cout<<"Enter ammount for tranfer:  ";
						cin>>amount;
						if(amount<=customer[i].ammount)
						{
							customer[i].ammount-=amount;              // transfer amount
							customer[j].ammount+=amount;
							cout<<"Transfer Succesfull!\n\n";
							break;
						}
						cout<<"Insufficient balance \n\n";
					}
					cout<<"Invalid pin\n\n";
				}
				cout<<"Wring reciever number\n\n";
			}
			break;
		}
	}
}

int main()
{
	while(true)  // infinite loop
	{
		menu();
		int choice;
		cin>>choice;
		if(choice<0 and choice >5)
		cout<<"please Enter valid number\n";
		else if(choice==0)
		createAccount();
		else if (choice ==5)
		{
			cout<<"Thankyou for visiting us!\n";
			break;
		}
		else if(choice==1)
		BalanceCheck();
		else if(choice==2)
		Deposite();
		else if(choice==3)
		Withdraw();
		else
		Transfer();
	}
}
