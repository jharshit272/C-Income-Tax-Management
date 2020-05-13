//C++ PROJECT
//INCOME TAX MANAGEMENT OF EMPLOYEES OF AN OFFICE

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
class employee
	      {

		int emp_num;
		char name[50];
		int age;
		char gen;
		char department[25];
		double basic_pay;
		double rebate;//on annual income
		double net_pay;//annual
		double anual_it;
		char status[15];//status of previous year tax


		public:


		void getdata();
		void it();//to calculate income tax on annual income
		void putdata();
		void modify();
		int empnum()
			  { return emp_num;}
	       }s;

void employee::getdata()
			 {cout<<"\nEnter employee number-->";
			  cin>>emp_num;
			  cout<<"\nEnter name-->";
			  gets(name);
			  cout<<"\nEnter age-->";
			  cin>>age;
			  cout<<"\nEnter sex(m/f)-->";
			  cin>>gen;
			  cout<<"\nEnter department of work-->";
			  gets(department);
			  cout<<"\nEnter basic pay(monthly)-->";
			  cin>>basic_pay;

			  cout<<"Enter rebateable income(investment in insurance premium,PF,contributions and other such schemes)-->";cin>>rebate;

			  if(rebate>100000)rebate=100000;//rebate exemption max upto 1 lakh is available
			  net_pay=(12*basic_pay)-rebate;
			  it();
			  cout<<"\nEnter status of previous year income tax (paid/due)-->";
			  gets(status);
			  }
void employee::putdata()
			{ cout<<"\n****PERSONAL DETAILS****\n";
			  cout<<emp_num<<"\t"<<name<<"\t"<<age<<"\t"<<gen
			  <<"\n"<<department<<"\t"<<basic_pay<<"\t"<<"\nAnnual taxable income : "<<net_pay
			  <<"\nInvestments subjected to rebate : "<<rebate<<"\nAnnual income tax to be paid : "<<anual_it<<"\nIncome tax status of previous year : "<<status<<"\n\n";
			}
void employee::modify()
			{ cout<<"\n***Record to be modified is-->\n";
			  s.putdata();
			  cout<<"\nEnter new name-->";
			  gets(name);
			  cout<<"\nEnter new age-->";
			  cin>>age;
			  cout<<"\nEnter new sex(m/f)-->";
			  cin>>gen;
			  cout<<"\nEnter new department of work-->";
			  gets(department);
			  cout<<"\nEnter new basic pay-->";
			  cin>>basic_pay;
			  cout<<"Enter rebateable income(investment in insurance premium,PF,contributions and other such schemes)-->";cin>>rebate;
			  if(rebate>100000)rebate=100000;
			  net_pay=(12*basic_pay)-rebate;
			  it();
			  cout<<"\nEnter new status of previous year income tax (paid/due)-->";
			  gets(status);

			  }
void employee::it()
{	     if(gen=='m'||gen=='M'&&age<65) //for male less than 65 years of age
	     { if(net_pay<=100000)
		     { anual_it = 0;
		     }
	       else if(net_pay>100000&&net_pay<=150000)
		     { anual_it =.1*net_pay ;
		     }
	       else if(net_pay>150000&&net_pay<=250000)
		     { anual_it =(.2*net_pay) ;
		     }
	       else if(net_pay>250000)
		     { anual_it = (.3*net_pay) ;
		     }
	       else if(net_pay>1000000) //surcharge on income exceeding 10 lakh per annum
		     {anual_it =((anual_it)+(.1*(net_pay-1000000)));
		     }
	     }
	       if(gen=='f'||gen=='F'&&age<65)//for female
	     { if(net_pay<=135000)
		  { anual_it = 0;
		  }
	       else if(net_pay>135000&&net_pay<=150000)
		  { anual_it =(.1*net_pay) ;
		  }
	       else if(net_pay>150000&&net_pay<=250000)
		  { anual_it =(.2*net_pay) ;
		  }
	       else if(net_pay>250000)
		  { anual_it = (.3*net_pay) ;
		  }
	       else if(net_pay>1000000)//surcharge
		  {anual_it =((anual_it)+(.1*((net_pay)-1000000)));
		  }
	       }
	       if( age>65)//senior citizen
	     { if(net_pay<=185000)
		 { anual_it = 0;
		  }
		else if(net_pay>185000&&net_pay<=250000)
		     { anual_it =(.2*net_pay) ;
		     }
		else if(net_pay>250000)
		     { anual_it = (.3*net_pay) ;
		     }
		else if(net_pay>1000000)//surcharge on income exceeding 10 lakh
			{anual_it =((anual_it)+(.1*((net_pay)-1000000)));
			}
	       }
	       anual_it=((anual_it)+(.02*anual_it));//education cess at 2% on tax

}
void main()
	 { clrscr(); int ch;char c;
	   void adddata();
	   void deldata();
	   void modify();
	   void displayrec();
	   void dispfile();
	   void showtax();
	  do{
	     clrscr();
	     cout<<"\n\n*********************************MAIN MENU**************************************";
	     cout<<" \n\n\n\n\n\n\t\t\t\t1).Add Employee\n"
		 <<"\t\t\t\t2).Delete data\n \t\t\t\t3).Modify Employee data\n"
		 <<"\t\t\t\t4).Display Employee data\n "
		 <<"\t\t\t\t5).Display complete office record\n \t\t\t\t6).View tax rates and details"
		 <<"\n\t\t\t\t7).Exit"
		 <<"\nENTER CHOICE-->";
	      cin>>ch;
		    switch(ch)
			      { case 1 :clrscr();adddata();break;
				case 2 :clrscr();deldata();break;
				case 3 :clrscr();modify();break;
				case 4 :clrscr();displayrec();break;
				case 5 :clrscr();dispfile();break;
				case 6 :clrscr();showtax();break;
				case 7 :exit(0);
			      }
	    } while((ch>=1)&&(ch<=6));
	  }

void adddata()
	      { char ans='y';ofstream fout;
		fout.open("office.dat",ios::out|ios::binary|ios::app);
		if(fout==0)
		  { cout<<"\nCan not open file";
		  }
		while(ans=='y'||ans=='Y')
		     {  employee s;
			s.getdata();
		       fout.write((char*)&s,sizeof(s));
		       cout<<"\nEnter more(y/n)?";
		       cin>>ans;
		     }
	       fout.close();
	       }
void deldata()
	      { int eno,flag=0;char confirm;
		cout<<"\nEnter employee number of to be deleted record-->";
		cin>>eno;
		ifstream fin;
		fin.open("office.dat",ios::in|ios::binary);
		if(fin==0)
		   { cout<<"\nCan not open file" ;
		   }
		ofstream fout("temp.dat",ios::out|ios::binary);
		while(!fin.eof())
		     { fin.read((char*)&s,sizeof(s));
		       int sh=s.empnum();
		       if(sh==eno)
			  { flag=1;
			    s.putdata();
			    cout<<"\nAre you sure you want to delete this record(y/n) ?\n";
			    cin>>confirm;
			    if(confirm=='n')
			    fout.write((char*)&s,sizeof(s));
			  }
			  else
			    fout.write((char*)&s,sizeof(s));
		      }
		 if(flag==0)
		    cout<<"\nRecord not found";
		    remove("office.dat");
		    rename("temp.dat","office.dat");
		    fin.close();
		    fout.close();
		    fin.open("office.dat");
		    cout<<"\nNew file contents are\n";
		    while(!fin.eof())
			 { fin.read((char*)&s,sizeof(s));
			   s.putdata();
			  }
		    getch();
		    fin.close();
		    }
void modify()
	  { fstream fio("office.dat",ios::in|ios::out|ios::binary);
	    int eno;long position; int flag=0;
	    cout<<"\nEnter employee number of to be modified record-->" ;
	    cin>>eno;
	    int sh;
	    while(!fio.eof())
		 { position=fio.tellg();
		   fio.read((char*)&s,sizeof(s));
		   sh=s.empnum();
		    if(sh==eno)
		      {  s.modify();
			 fio.seekg(position);
			 fio.write((char*)&s,sizeof(s));
			 flag=1;
			 break;
		      }
		 }
		    if(flag==0)
		       { cout<<"\nRecord not found";
		       }
		    fio.seekg(0);
		    cout<<"\nNow file contains";
		    while(!fio.eof())
			 { fio.read((char*)&s,sizeof(s));
			   if(fio.eof())break;
			   s.putdata();
			 }
			 fio.close();
	    }


void displayrec()
     {int enumb;int flag=0;
      cout<<"Enter employee number of to be displayed record";
      cin>>enumb;


      ifstream fin;
      fin.open("office.dat",ios::in|ios::binary);
      while(!fin.eof())
	   {fin.read((char*)&s,sizeof(s));
	    if(s.empnum()==enumb)
	      {flag=1;
	      s.putdata();
	      break;
	      }
	    }
	      if(flag==0)
	      {cout<<"Record not found";
	      }
	      getch();
	      fin.close();

      }

void dispfile()
     {ifstream fin;
      fin.open("office.dat",ios::in|ios::binary);
      while(!fin.eof())
	   { fin.read((char*)&s,sizeof(s));
	      if(fin.eof())break;
	      s.putdata();
	    }
       getch();
	    fin.close();

      }
void showtax()
     { ifstream fin("tax.txt");
       if(fin==0)
	  cout<<"Cannot open file";
	  char ch;
	  while(!fin.eof())
	       {fin.get(ch);
		cout.put(ch);
		}
		fin.close();
      }