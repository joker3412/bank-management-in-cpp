#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include<conio.h>

using namespace std;
class  bank{
	
		int accoount_number;
		string name;
		string account_type;		
		double balance;
		public:
			void openaccount();
			void Deposite();
			void list();
			void Widraw();
			void Balance_inquiry();
			void close_account();
			void Modify_account();
			
};

 int main()
{ 	string username; 
    string password;
	int x;
	system("Color 4"); 
	for(x=0;x<3;x++){
		
	cout<<"\t\t\t\tEnter the username\n\t\t\t==============================================\n\t\t\t\t"; 
	
    cin>>username; 
    cout<<"\n\t\t\t+++++++++++++++++++++++++++++++++++++++++++++\n";
 
    cout<<"\t\t\t\tEnter the password\n\t\t\t==============================================\n\t\t\t\t"; 
     cin>>password; 
	
if(username=="BLACKWIDOW26" && password=="joker@123"){ 
        
 
	
  system("CLS");
  
  
     char c;
do{  
system("CLS");
bank b;
  //for menu bar
  
  
  system("Color 1"); 
  cout<<"\t\t\t=================================================\n";
  cout<<"\t\t\t\t\tMAIN MENU\n";
   cout<<"\t\t\t=================================================\n\n";
   cout<<" \t\t\t\t[1].New Account \n \t\t\t\t[2].Deposite Amont \n\t\t\t\t[3].Widraw Amount \n";
   cout<<" \t\t\t\t[4].Balance Enquiry \n \t\t\t\t[5].All Account Holder List \n \t\t\t\t[6].Close An Accont \n";
   cout<<" \t\t\t\t[7].Modify An Accont \n \t\t\t\t[0].enter zero for exit \n";
   cout<<"\t\t\t=================================================\n\n";
   cout<<"enter what you want to do (must be a number):";
   int a;
   cin>>a;
   if(a>=0 && a<=7){
   
   switch(a)
   {
   	case 1: b.openaccount();
   	
	       break;
   	       	case 2: b.Deposite();
   	       break;
   	      	case 3: b.Widraw();
   	       break;
   	       	case 4: b.Balance_inquiry();
   	           break;
   	       	case 5: b.list();
   	       break;
   	      	case 6: b.close_account();
   	       break;
   	       	case 7: b.Modify_account();
   	       break;
   	       case 0: exit(0);
   	       break;
   	       
   }
   }
   else{
   	cout<<"\t!!!!!!!!!!!!!!!!!!!!PLEASE ENTER VALID CHOISE!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";

   //cout<<"do you want to do again y/n";
   //cin>>c;
   
    }
     cout<<"do you want to do again y/n";
   cin>>c;
 }while(c=='y'||c=='Y');
 
 
}
 else if(x==2)
    {
       printf("!!!!!!!!DANGER YOU ARE SUSSPENDED!!!!!!!\n");
       return 0;
	   	}
	
	else
	{
			 printf("\n\n\t\t\t\t*****************************************\n");
		 printf("\t\t\t\t\tWrong USERNAME OR password \n");
		 printf("\t\t\t\t**************************************\n");
		 getch();
		 	 
		 system("CLS");
		  
		  }
	
   }

	}
 void bank::openaccount()
 {
 	ofstream file;
 	file.open("bank.dat", ios::app);
     fstream f;
	 int acc;
	 int b;
   f.open("random_number.dat");
	f>>acc;
	 f.close();
	 accoount_number=acc;
	    cout<<"Accont_Number:"<<accoount_number<<endl;
        cout<<"Enter Name:";
        cin>>name;
        cout<<"enter account type s=saving and c=current";
        cin>>account_type;
        while(account_type=="s" ||  account_type=="S")
        {
        	cout<<"you choose saving account enter minimum 500rs:";
        	cin>>balance;
        	if(balance>=500){
        		cout<<"!!!!!!!!congratulation your accont created successfull!!!!!"<<endl;
        		break;
        		}
			else{
				cout<<"???????ammount must be 500 or greater than 500 enter again";
				
			   }
		} while(account_type=="c" ||  account_type=="C")
        {
        	cout<<"you choose current account enter minimum 5000rs:";
        	cin>>balance;
        	if(balance>=5000){
        		cout<<"!!!!!!!!congratulation your accont created successfull!!!!!"<<endl;
        		break;
        		}
			else{
				cout<<"???????ammount must be 5000 or greater than 5000 enter again??????\n";
				
		}
		}    
		b=acc+1;
        f.open("random_number.dat");
	     f<<b;
          f.close();
	
		file<<accoount_number<<"\t"<<name<<"\t"<<account_type<<"\t"<<balance<<"\t"<<endl;
		file.close();
	}

void bank::list()
{
	
	ifstream old;
	
	
		old.open("bank.dat",ios::out|ios::in);
		old.seekg(0);
		cout<<"===========================================\n";
		 cout<<"acc_no\tname\ttype\tbalance\n";
		 cout<<"==========================================\n";
		 while((old>>accoount_number>>name>>account_type>>balance)!=0)
		 {
		 	cout<<accoount_number<<"\t"<<name<<"\t"<<account_type<<"\t"<<balance<<"\t"<<endl;
		 	}
		 	 old.close();
	
}

void bank::Deposite()
 {
 double deposite;
 	int acc_no;
 	ifstream old;
    ofstream new1;
 	old.open("bank.dat",ios::in);
     new1.open("new.dat",ios::in| ios::out| ios::app);
 	old.seekg(0);
 	
 	cout<<"enter account number";
 	cin>>acc_no;
 	
 	 while((old>>accoount_number>>name>>account_type>>balance)!=0){
 	 		
	if (accoount_number==acc_no ){
	  	
	  	cout<<"enter deposite ammount"<<endl;
	  	cin>>deposite;
	  	balance+=deposite;
	    new1<<accoount_number<<"\t"<<name<<"\t"<<account_type<<"\t"<<balance<<"\t"<<endl;
	  	 
 	    }
 	    else
 	    {
	new1<<accoount_number<<"\t"<<name<<"\t"<<account_type<<"\t"<<balance<<"\t"<<endl;

 	    }
		 }
 	    old.close();
 	    new1.close();
 	    remove("bank.dat");
       rename("new.dat","bank.dat");
}
void bank::Widraw()
 {
 double deposite;
 	int acc_no;
 	ifstream old;
    ofstream new1;
 	old.open("bank.dat",ios::in);
     new1.open("new.dat",ios::in| ios::out| ios::app);
 	old.seekg(0);
 	
 	cout<<"enter account number";
 	cin>>acc_no;
 	
 	 while((old>>accoount_number>>name>>account_type>>balance)!=0){
 	 		
	if (accoount_number==acc_no ){
	  	
	  	cout<<"enter Widraw ammount ammount"<<endl;
	  	cin>>deposite;
	  	balance-=deposite;
	    new1<<accoount_number<<"\t"<<name<<"\t"<<account_type<<"\t"<<balance<<"\t"<<endl;
	  	 
 	    }
 	    else
 	    {
	new1<<accoount_number<<"\t"<<name<<"\t"<<account_type<<"\t"<<balance<<"\t"<<endl;

 	    }
		 }
 	    old.close();
 	    new1.close();
 	    remove("bank.dat");
       rename("new.dat","bank.dat");
}
void bank::Balance_inquiry()
{     int acc_no;
	fstream f;
	f.open("bank.dat",ios::in);
	cout<<"enter account numer:";
	cin>>acc_no;
	//int c=1;
//do{	system("CLS");
//cin>>acc_no;
    while((f>>accoount_number>>name>>account_type>>balance)!=0){
	
	if(accoount_number==acc_no)
	{
		cout<<"your balance amount is:"<<balance<<"inr\n";
		break;
	}else{
	
	cout<<"\n===============================\nEITHER ACCOUNT NUMBER IS WRONG OR ACCOUNT IS CLOSED\n============================================\n\nEnter again:";
		
	//	c++;
	}
}
//}while(c<=3);
//cout<<"!!!you reached maximum limit try again later!!";

}
void bank::close_account()

{
	int acc_no,c;
	fstream f;
	fstream n;
	f.open("bank.dat",ios::in);
	n.open("new.dat",ios::app);
	cout<<"enter account number:";
	cin>>acc_no;
//	c=1;
	char d;
//	do{
		while((f>>accoount_number>>name>>account_type>>balance)!=0){
			if(accoount_number==acc_no)
			{
				cout<<"\n\n\n\t\t++++++++cunfirm again y/n+++++++++++\n";
				cin>>d;
				if(d=='y'||d=='Y'){
					               cout<<"\n\n\t\t\t!!!!!YOUR ACCOUNT CLOSED SUCCESSFULLY!!!";
								   }
								   else{
								   	cout<<"!!!YOU CHOOSE TO STAY WITH US THANK YOU!!!!";
								   	n<<accoount_number<<"\t"<<name<<"\t"<<account_type<<"\t"<<balance<<endl;
								   }
			}
			else
			{
			  n<<accoount_number<<"\t"<<name<<"\t"<<account_type<<"\t"<<balance<<endl;
			}
			}
			f.close();
			n.close();
			remove("bank.dat");
			rename("new.dat","bank.dat");
			
		/*	cout<<"\n===============================\nEITHER ACCOUNT NUMBER IS WRONG OR ACCOUNT IS CLOSED BEFORE\n============================================\n\nEnter again:";
		cin>>acc_no;
		c++;

	}while(c<3);
	cout<<"!!!you reached maximum limit try again later!!";*/
	
}
void bank::Modify_account()
{ int acc_no;
	fstream old;
	fstream new1;
	old.open("bank.dat",ios::in|ios::out);
	new1.open("new.dat",ios::in|ios::out|ios::app);
	cout<<"enter account number to modify:";
	cin>>acc_no;
	while((old>>accoount_number>>name>>account_type>>balance)!=0)
	{
		if(accoount_number==acc_no)
		{ string key="1234";
		string pass;
			cout<<"account numer matched enter pass key to proceed:\n";
			cin>>pass;
			if(key==pass){
					cout<<"===========================================\n";
		 cout<<"acc_no\ttype\tbalance\n";
		 cout<<"==========================================\n";
				cout<<accoount_number<<"\t"<<account_type<<"\t"<<balance<<endl;
				cout<<"YOU JUST ABLE TO MODIFY THE NAME:\n";
				cout<<"your previous name is= "<<name<<endl;
				cout<<"==============\nenter new name:-";
				cin>>name;
				cout<<"!!!!!!ACCOUNT MODIFIED SUCCESSFULLY!!!!";
				
				
				 new1<<accoount_number<<"\t"<<name<<"\t"<<account_type<<"\t"<<balance<<endl;
				
			    }
			    else{
				new1<<accoount_number<<"\t"<<name<<"\t"<<account_type<<"\t"<<balance<<endl;
			    	cout<<" ++++ CONTACT TO HEAD OF DEPARTMENT ++++";
				}
		} 
		else{
		      new1<<accoount_number<<"\t"<<name<<"\t"<<account_type<<"\t"<<balance<<endl;
			
		}
	}   
	old.close();
	new1.close();
	remove("bank.dat");
	rename("new.dat","bank.dat");
	
	
}
