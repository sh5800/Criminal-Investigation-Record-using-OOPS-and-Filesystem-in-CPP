#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
  
                             class crim_rec
							 {
								 char name[30],sex,fname[30],addrs[25],
								       crime[50],bldgrp[5],dob[9];
								 int crim_code,reward;
                                 void disp();
								 
                                   public:
								 void get();
                                 void wtf();
                                 void rtf();
                                 void search();								 
                                 void del();
								 void mod();
							 } c;
							 
							 
							 
							 
							  void crim_rec::get()
							  {
								  cout<<"\nEnter the Name of the criminal:";
								  gets(name);
								  cout<<"\nGender:";
								  cin>>sex;
								  cout<<"\nEnter Date of Birth:";
								  gets(dob);
								  cout<<"Enter blodd group \n A+,A-,B+,B-,AB+,AB-,O+,O-:";
								  gets (bldgrp);
								  cout<<"\nEnter father's name:";
								  gets(fname);
								  cout<<"\nEnter Address:";
								  gets(addrs);
								  cout<<"\nEnter the crime commited:";
								  gets(crime);
								  cout<<"\nEnter reward on criminal:";
								  cin>>reward;
							  }
								   void crim_rec::disp()
								   {
									   cout<<"The record of criminal:\n";
									   cout<<"\nName of criminal:"<name;
									   cout<<"\nGender:"<<sex;
									   cout<<"\nDOB:"<<dob;
									   cout<<"\nBlood Group:"<<bldgrp;
									   cout<<"\nFather's name:"<<fname;
									   cout<<"\nAddress:"<<addrs;
									   cout<<"\nCrime:"<<crime;
									   cout<<"\nReward:"<<reward;
								   }								   
								     void crim_rec::wtf()
									 {
										 ofstream ofile;
										 ofile.open("CBI.dat",ios::app|ios::binary);
										 get();
										 ofile.write((char*)&c,sizeof(c));
										 ofile.close();
									 }
									 void crim_rec::rtf()
									 {
										 ifstream ifile;
										 ifile.open("CBI.dat",ios::binary|ios::in);
										 ifile.seekg(0,ios::beg);
										 while(ifile)
										 {
											 ifile.read((char*)&c,sizeof(c));
											 if(ifile.eof())
												 break;
											 c.disp();
										 }
										 ifile.close();
									 }
									 void crim_rec::search()
									 {
										 char m[20];
										 ifstream ifile("CBI.dat",ios::in|ios::in);
										 cout<<"Enter the name of criminal to be searched:";
										 gets(m);
										 ifile.seekg(0,ios::beg);
										 ifile.read((char*)&c,sizeof(c));
										 while(ifile)
										 {
											 if(strcmpi(m,c.name)==0)
												 c.disp();
											 ifile.read((char*)&c,sizeof(c));
											 
										 }
										 ifile.close();
									 }
									      void crim_rec::del()
										  {
											  char b[20];
											  ifstream ifile;
											  ifile.open("CBI.dat",ios::in|ios::binary);
											  ofstream ofile;
											  ofile.open("new.dat",ios::app|ios::binary);
											  cout<<"Enter the name of the criminal whose record you want to delete:";
											  gets(b);
											  ifile.seekg(0,ios::beg);
											  ifile.read((char*)&c,sizeof(c));
											  while(ifile)
											  {
												  if(strcmpi(b,c.name)!=0)
													  ofile.write((char*)&c,sizeof(c));
												  ifile.read((char*)&c,sizeof(c));
												  
											  }
											  ifile.close();
											  ofile.close();
											  remove("CBI.dat");
											  rename("new.dat","CBI.dat");
											  cout<<"\nRecord Deleted Successfully:";
											  
										  }
										  void crim_rec::mod()
										  {
											  char d[20];
											  int p,a;
											  cout<<"\nEnter the name of the criminal whose record you want to modify\n";
											  gets(d);
											  fstream f;
											  crim_rec newrec;
											  f.open("CBI.dat",ios::in|ios::out|ios::binary);
											  f.seekg(0,ios::beg);
											  
											  while(!f.eof())
											  {
												  f.read((char*)&c,sizeof(c));
												  if(!strcmpi(d,c.name))
												  {
													  cout<<"\nPress 1 to change name:";
													  cout<<"\nPress 2 to change gender:";
													  cout<<"\nPress 3 to change date of birth:";
													  cout<<"\nPress 4 to change blood group:";
													  cout<<"\nPress 5 to change father's name:";
													  cout<<"\nPress 6 to change address:";
													  cout<<"\nPress 7 to change crime commited:";
													  cout<<"\nPress 8 to change reward on criminal:\n";
													     cin>>p;
														 switch(p)
														 {
															 case 1:
															 gets(c.name);
															 break;
															 
															 case 2:
															 cin>>c.sex;
															 break;
															 
															 case 3:
															 gets(c.dob);
															 break;
															 
															 case 4:
															 gets(c.bldgrp);
															 break;
															 
															 case 5:
															 gets(c.fname);
															 break;
															 
															 case 6:
															 gets(c.addrs);
															 break;
															 
															 case 7:
															 gets(c.crime);
															 break;
															 
															 case 8:
															 cin>>c.reward;
															 break;
															 
														 }
												          	 f.seekp(f.tellg()-sizeof(c)); 
												  }
											  }
										    cout<<"\nRecord Modified Successfully:";
											f.close();
											
										  }
										  
										   void passwd(char*ar,int max)
										   {             	   
	                                       	char v;
		                                    int x=0;
		                                    while(1)
		                               {
			                               v=getch();
			                               if(v==13)
			                           {
				                           ar[x]='\0';
				                              break;
			                           }
			                             if(v==8 && x!=0)
			                           {
				                         cout<<"\b \b";
				                       if(x<=max && x>0)
					                        x--;
			                           }
			                             else
				                         if(x<max && v!=8)
				                      {
					                     cout<<"*";
					                     ar[x]=v;
					                     x++;
				                      }
		                            }
	                                 }
	
										  
										  
										  
										  
										  
    void main()
	{
		int ch;
		char choice;
		char u[15],ps[11];
		cout<<"*****************************************************:";
		cout<<"\n\n\t\t*********PROJECT ON CRIMINAL INVESTIGATION:**********:";
		cout<<"\n\n*********************************************************:";
		cout<<"\n\n\t\t\t\t\tCompiled and Presented by:";
		cout<<"\n\n\t\t\t\t\tShreyash Kashyap-XII-C:";
		cout<<"\n\nPress any key to continue......";
		getch();
		do
		{
			clrscr();
			cout<<"\t Central Bureau of Investigation:";
			cout<<"\n*******************************:";
			cout<<"\n\n* 1.View criminal details     *";
            cout<<"\n\n* 2.Add new criminal details     *";
            cout<<"\n\n* 3.Search a criminal record        *";
			cout<<"\n\n* 4.Delete a criminal record          *";
			cout<<"\n\n* 5.Modify a criminal record:         *";
			cout<<"\n\n Enter your choice:";
			cin>>ch;
			
			
			switch(ch)
			{
				case 1:
				cout<<"Enter the Username:";
					  gets(u);
					  cout<<"Enter the password :";
					  
					  passwd(ps,10);
					  
					 
					  if(strcmpi(u,"Shreyas")==0)
					  {
					  if(strcmpi(ps,"shreyas")==0)
						  cout<<"\n Access Granted:\n";
					  }
					  else if(strcmpi(u,"Jamie")==0)
					  { if(strcmpi(ps,"jamie")==0)
						  cout<<"\n Access Granted:\n";
					  }
					  else 
					  {  cout<<"\n Access Denied:\n";
				         getch();
					      exit(0);
					  }
					  getch();
				c.rtf();
				break;
				
				case 2:
				cout<<"Enter the Username:";
					  gets(u);
					  cout<<"Enter the password :";
					  
					  passwd(ps,10);
					  
					 
					  if(strcmpi(u,"Shreyas")==0)
					  {
					  if(strcmpi(ps,"shreyas")==0)
						  cout<<"\n Access Granted:\n";
					  }
					  else if(strcmpi(u,"Jamie")==0)
					  { if(strcmpi(ps,"jamie")==0)
						  cout<<"\n Access Granted:\n";
					  }
					  else 
					  { cout<<"\n Access Denied:\n";
				         getch();
				         exit(0);
					  }
					  getch();
				c.wtf();
				break;
				
				case 3:
				c.search();
				break;
				
				case 4:
				c.del();
				break;
				
				case 5:
				cout<<"Enter the Username:";
					  gets(u);
					  cout<<"Enter the password :";
					  
					  passwd(ps,10);
					  
					 
					  if(strcmpi(u,"Shreyas")==0)
					  {
					  if(strcmpi(ps,"shreyas")==0)
						  cout<<"\n Access Granted:\n";
					  }
					  else if(strcmpi(u,"Jamie")==0)
					  { if(strcmpi(ps,"jamie")==0)
						  cout<<"\n Access Granted:\n";
					  }
					  else 
					  {  cout<<"\n Access Denied:\n";
				         getch();
					       exit(0);
					  }
					  getch();
				c.mod();
				break;
				
				default:
				{
					cout<<"\nerror!";
					
				}
				break;
			}
			
			cout<<"\nContinue? (y/n)\n";
			cin>>choice;
		}while(choice=='y'||choice=='Y');
		cout<<"\nGood bye";
		     
	}	