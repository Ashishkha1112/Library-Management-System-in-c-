#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<string.h>
#define ENTER 13 //ascii value of keys
#define TAB 9
#define BCKSPC 8
int choice,choose;

char findbook,findmember;
struct user{
	char fullname[50];
	char pass[50];
	char uname[50];
	char phone[50];
};
struct book{
	char name[30];
	int id,qt,rack;
	char auth[30];
	char pub[30];
	char cat[30];
	int upper;
	long int i;
	int lower;
	int count;
	int idd,imm,iyy;
	int ddd,dmm,dyy;
}b;
struct member{
	long int i;
	char name[30];
	char address[30];
	int id,age;
	double ph;
	char gender[10];
	char mail[40];
	int upper;
	int lower;
	int count;
}m;
void login();
void getpass(char pwd[50]);
void member_list();
int checkid1(int);
int checkid(int);
void registration();
void book_list();
void edit_book();
void search_book();
void add();
void delete1();
void issue_book();
void returnfunc();
void mainmenu();
void main()

{
	int choice;
  	printf("\n\n\t\t\t\t\tLIBRARY MANAGEMENT SYSTEM");
    printf("\n\n\t\t\t\t\t    Authentication Page");
    printf("\n\t\t  ----------------------------------------------------------------------------");
	printf("\n\t\t  1. Register");
	printf("\n\t\t  2. login");
	printf("\n\t\t  3. Exit");
	
	printf("\n\n\n\t\t  Enter your Choice : \t");
	scanf("%d", &choice);
	
	switch(choice)
	{
		case 1:
			registration();
			break;
		case 2:
			login();
			break;
		case 3: 
		default:
		exit(1);
	}
}

void mainmenu()
{
	system("cls");
 	printf("\n\n\t\t\t\t\tLIBRARY MANAGEMENT SYSTEM");
    printf("\n\n\t\t\t\t\t\t  MENU");
    printf("\n\t\t  ----------------------------------------------------------------------------\n");
	printf("\n\n\t\t\t 1. Add");
	printf("\n\t\t\t 2. delete");
	printf("\n\t\t\t 3. Search");
	printf("\n\t\t\t 4. Edit Book Details:");
	printf("\n\t\t\t 5. Book List");
	printf("\n\t\t\t 6. Member List");
	printf("\n\t\t\t 7. Issue book");
	printf("\n\t\t\t 8. Exit");
	printf("\n\n\n\t\t\t Enter your Choice  :");
	scanf("%d",&choice);
	system("cls");
	switch(choice)
	{
	case 1:
		add();
		break;
	case 2:
		delete1();
		break;
	case 3:
		search_book();
		break;		
	case 4:
		edit_book();
		break;	
	case 5:
		book_list();
		break;
	case 6:
		member_list();
		break;
	case 7:
		issue_book();
		break;
	case 8:
		default:
		exit(1);
	}
}
		
		
void add()
{

	system("cls");
	printf(" Add Menu");
	printf("\n\t\t\t 1. Add Book  ");
	printf("\n\t\t\t 2. Add Member ");
	printf("\n\t\t\t 3. Main menu");
	printf("\n\n\t\t\tChoice 1 or 2 or 3 :");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			{

		system("cls");
		FILE *fp;
		struct book b;
		char another='y';
		fp=fopen("book.txt","ab");
		if(fp == NULL){
        system("cls");
    	printf("\n\n\t\t\t\t\t   LIBRARY MANAGEMENT SYSTEM");
    	printf("\n\t\t  ----------------------------------------------------------------------------");
        printf("\n\t\t  Error opening file");
        exit(1);
    }
		
		while(another=='y')
		{
	 	printf("\n\n\t\t\t\t\tLIBRARY MANAGEMENT SYSTEM");
    	printf("\n\n\t\t\t\t\t\tADD BOOKS");
        printf("\n\n\n\t\t\t\t\t   Enter details of Book");
        printf("\n\t\t  ----------------------------------------------------------------------------\n");
        b.lower = 0, b.upper = 100000, b.count = 1;
		for (b.i = 0; b.i < b.count; b.i++)
		{
    	srand(time(0));
        b.id = (rand()%(b.upper - b.lower + 1)) + b.lower;
        printf("\n\t\t\tBook id. : %ld",b.id);
        scanf("%ld",&b.id);
   		}
   		
   		fflush(stdin);
		printf("\n\t\t\tName of Book:");
		gets(b.name);
		printf("\n\t\t\tAuther:");
		gets(b.auth);
		printf("\n\t\t\tPublication:");
		gets(b.pub);	
		fflush(stdin);
		printf("\n\t\t\tCatagory:");
		gets(b.cat);
		printf("\n\t\t\tQuantity:");
		scanf("%d",&b.qt);
		printf("\n\t\t\tRack number :");
		scanf("%d",&b.rack);
		fwrite(&b,sizeof(b),1,fp);
		printf("\n\t\t\tThe  book Record is succesfully saved ");
		printf("\n\n\n\n\t\t\t Save any more?(Y/N)");
		another=getch();
		system("cls");
		}
		fclose(fp);
		
		mainmenu();
	}
		break;
		
		
		case 2:
			{
	system("cls");
		FILE *fm;
		struct member m;
		fm=fopen("member.txt","ab");
		char another='y';
		while(another=='y')
		{
			printf("Enter The Information");
			printf("\n Member ID:");
			scanf("%d",&m.id);
			fflush(stdin);
			printf("Name Of Member:");
			gets(m.name);
			fflush(stdin);
			printf("Address:");
			gets(m.address);
			printf("Phone Number:");
			scanf("%lf",&m.ph);
			fflush(stdin);
			
			printf("Email ID:");
			gets(m.mail);
			fflush(stdin);
			printf("Gender:");
			gets(m.gender);
			printf("Age:");
			scanf("%d",&m.age);
		fwrite(&m,sizeof(m),1,fm);
		printf("The  Member Record is succesfully saved ");
		printf("\n Save any more?(Y/N)");
		another=getch();
		system("cls");
		}
		fclose(fm);
		mainmenu();;
			break;
		}
		case 3:
			default:
			mainmenu();
			break;	
	}
}
			
		

		
		
void delete1()
{
	system("cls");
	printf(" Delete Menu");
	printf("\n 1. Delete Book  ");
	printf("\n 2. Delete Member ");
	printf("\n 3. Main menu");
	printf("\nChoice 1 or 2 or 3 :");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			{
				system("cls");
	int id;
	FILE *fp,*fd;
	struct book b;
	
	printf("\n Enter the book id to delete:");
	scanf("%d",&id);
	fp=fopen("book.txt","rb+");
	fd=fopen("temp.txt","ab+");
	
	if(fp==NULL||fd==NULL)
	{
		printf("\n error opening file");
		returnfunc();
	}
	while(fread(&b,sizeof(b),1,fp) == 1)
	{
	 if(id!=b.id)
	 {
		fwrite(&b, sizeof(b),1,fd);
		getch();
	
	 	
	 }
	 
	}
	fclose(fp);	
	fclose(fd);
	remove("book.txt");
	rename("temp.txt","book.txt");
	printf("\n The record is successfully deleted.");
	printf("\nDelete another record?(Y/N):");
	if(getch()=='y'|| getch()=='Y')
	delete1();
	else 
	returnfunc();
								  
}

		break;
	case 2:
		{
		
			system("cls");
			int id;
			FILE *fm,*fr;
		struct member m;
	
		printf("\n Enter the member id to delete:");
		scanf("%d",&id);
		fm=fopen("member.txt","rb+");
		fr=fopen("temp.txt","ab+");
	
		if(fm==NULL||fr==NULL)
	{
		printf("\n error opening file");
		returnfunc();
	}
	while(fread(&m,sizeof(m),1,fm) == 1)
	{
	 if(id!=m.id)
	 {
		fwrite(&m, sizeof(m),1,fr);
		getch();
	
	 	
	 }
	 
	}
	fclose(fm);	
	fclose(fr);
	remove("member.txt");
	rename("temp.txt","member.txt");
	printf("\n The record is successfully deleted.");
	printf("\nDelete another record?(Y/N):");
	if(getch()=='y'|| getch()=='Y')
	delete1();
	else 
	returnfunc();
}
			break;
		case 3:
			default:
			mainmenu();
			break;
	}

		
}
				
	void book_list()
				{
				
				system("cls");
				FILE *fp;
			struct book b;
				fp=fopen("book.txt","rb");
				fflush(stdin);
				printf("\nID\t\tBook Name\t\tAuthor\t\tPublication\t\tCatagory\t\tQuantity\t\tRack no.\n");
				
			
				rewind(fp);
				while(fread(&b,sizeof(b),1,fp)==1)
					
					{
			
				printf("\n%d		%17s	%22s	%12s%18s	%10d%19d",b.id,b.name,b.auth,b.pub,b.cat,b.qt,b.rack);
					}
				
						
					fclose(fp);
					returnfunc();
				}
			void member_list()
			{
					system("cls");
					FILE *fm;
				struct member m;
				fm=fopen("member.txt","rb+");
				if(fm==NULL)
				{
					printf("\n Error Opening file");
					getch();
					returnfunc();
				}
				printf("\nID\tName\t\t      Address\t\t\tEmail\t\tContact no.\t\tAge\t\tGender\n");
				rewind(fm);
				while(fread(&m,sizeof(m),1,fm) == 1 ){
				printf("\n%-7d %-22s%-15s		%-9s	%-12.0lf		%-12d    %-12s",m.id,m.name,m.address,m.mail,m.ph,m.age,m.gender);
					}
				
						
					fclose(fm);
					returnfunc();
				}	

	void search_book()
	{
		int id;
		char name[50];
	system("cls");
	
	search_menu:
	printf(" Search Book By");
	FILE *fp;
	struct book b;
	printf("\n 1. Book ID ");
	printf("\n 2. Book Name ");
	printf("\n 3. Main menu");
	
	printf("\nSelect any option :");
	scanf("%d",&choice);
	fp=fopen("book.txt","rb+");
	rewind(fp);
	if(choice==3)
	mainmenu();
	if(choice==1 ||choice==2  )
	{
		switch(choice)
	{
		case 1:
		{
		system("cls");
		printf("\n Search by book id");
		printf("\n Enter the book id:");
		scanf("%d",&id);
		while(fread(&b,sizeof(b),1,fp)==1)	
		{
			if(checkid(id)==0);
			{
				system("cls");
				
				  
				printf("\n The book is available. ");
				printf("\nID	Book Name							Author		Publication		Catagory	Quantity	Rack no.\n");
				printf("\n%d	%s					%s			%s				%s			%d		%d		",b.id,b.name,b.auth,b.pub,b.cat,b.qt,b.rack);
				getch();
				system("cls");
			
				findbook='t';
			}
		}
			if(findbook!='t')
{
	system("cls");
	printf("\n No record found.");
}


printf("\n Try another search?(Y/N). ");
if(getch()=='y'|| getch()=='Y')

	search_book();
	else
returnfunc();
		break;
		}
			
		case 2:
			{
		system("cls");
		printf("\n Search by book name");
		fflush(stdin);
		printf("\n Enter the book name:");
		gets(name);
		while(fread(&b,sizeof(b),1,fp)==1)	
		{
			if(b.name==name);
			{
				system("cls");
				
				printf("\n The book is available. ");
				
				system("cls");	
				printf("\nID	Book Name					Author			Publication			Catagory		Quantity		Rack no.\n");
				printf("\n%d	%s					%s			%s				%s			%d		%d		",b.id,b.name,b.auth,b.pub,b.cat,b.qt,b.rack);
				getch();
				findbook='t';
			}
		}
			if(findbook!='t')
{
	system("cls");
	printf("\n No record found.");
}


printf("\n Try another search?(Y/N). ");
if(getch()=='y'|| getch()=='Y')

	search_book();
	else
returnfunc();	
		break;
		}
		
			case 3:
				mainmenu();
				break;
			

	}
	
	}
	
			printf(" Sorry the option does not exists");
	printf(" \nEnter any key to go to main menu .........");
	getch();
	system("cls");
	goto search_menu;	
	
					}
					
	void edit_book()
	{
		system("cls");
		FILE *fp;
		struct book b;
		int c=0;
		int id,e;
		printf("\n Edit book Details");
		char another='y';
		while(another='y')
		
		{
			system("cls");
			printf("Enter Book id to be edited:");
			scanf("%d",&id);
			
			rewind(fp);
			
			fp=fopen("book.txt","rb+");
			while(fread(&b,sizeof(b),1,fp)==1)
			{
				if(checkid(id)==0)
				{
					printf("\n The Book is available");
					printf("\n The book id is: %d",b.id);
					fflush(stdin);
					printf("\n Enter new name:");
					gets(b.name);
						fflush(stdin);
					printf("\n Enter new Author:");
					gets(b.auth);
						fflush(stdin);
					printf("\n Enter new Publication:");
					gets(b.pub);
					printf("\n Enter new Catagory:");
					gets(b.cat);
					printf("\n Enter New quantity:");
					scanf("%d",&b.qt);
					printf("\n Enter new rack number:");
					scanf("%d",&b.rack);
					printf("\n The record is modified!");
					fseek(fp,ftell(fp)-sizeof(b),0);
					fwrite(&b,sizeof(b),1,fp);
					c=1;
					fclose(fp);
				}
				if(c==0)
				
				{
					printf("\n No record Found !");
					
					
				}
			}
			printf("\n Modify another book record?(Y/N).");
			fflush(stdin);
			if(getch()=='y'|| getch()=='Y')
			another=getch();
			mainmenu();
		}
		
		
		
	returnfunc();
		}	
	
	void issue_book()
	{
		struct member member;
		struct book book ;
		 int id,t,quantity;
		 int returntime;

    system("cls");
    printf("********************************ISSUE SECTION**************************");
    
    printf("\n 1. Issue a Book");
    printf("\n 2. View Issued Book");
    printf("\n 3. Remove Issued Book");

    
    printf("\nEnter a Choice:");
    scanf("%d",&choice);
    
    switch(choice)
    {
    	case 1:
    			{
					int id,t,returntime;
					FILE *fp,*fm,*fi;
    				system("cls");
   			
    		
    				char another='y';
    				while(another='y')
    				{
    					system("cls");
    					printf("\n Issuse Book ");
    					printf("\n Enter Book id to be issue:");
    					scanf("%d",&id);
    					fflush(stdin);
    				
    					fm=fopen("member.txt","rb");
    					fp=fopen("book.txt","rb+");
    					fi=fopen("issue.txt","ab+");
    					fflush(stdin);
    					while(fread(&b,sizeof(b),1,fp)==1)
    					{
					
    						if(id==b.id)
    						{
    							b.id=book.id;
    							rewind(fp);
    						
    							
    							printf("\n The Book is available");
    							printf("\n There are %d unissued book in library",b.qt);
    							printf("\n book ID:%d",b.id);
    							printf("\n Book name:%s",b.name);
    							printf("\n Auther:%s",b.auth);
    							printf("\n Publication:%s",b.pub);
    							printf("\n Enter member id:");
    							scanf("%d",&t);
    							fflush(stdin);
    							rewind(fm);
    						 while(fread(&m,sizeof(m),1,fm)==1)
    							{
									if(t==m.id);
    				    			{
    				    				m.id=member.id;
    				    				printf("\n Member is available");
    									printf("\n  member id:%d ",member.id);
    									printf("\n Name of member: %s",m.name);
    									printf("\n  member address: %s",m.address);
    									fflush(stdin);
    									printf("\n Enter issue date:");
   										printf("\n day:");
   										scanf("%d",&b.idd);
										printf("\n month:");
   										scanf("%d",&b.imm);
					   					printf("\n year:");
   										scanf("%d",&b.iyy) ;
   										printf("\n Issued date:%d-%d-%d",b.idd,b.imm,b.iyy);
   										printf("\n Enter the issuing day:");
    									scanf("%d",&returntime);
   										b.qt=b.qt-1;
   										b.ddd=b.idd+returntime;
   										b.dmm=b.imm;
   										b.dyy=b.iyy;
   								if(b.ddd>30)
   								{
   									b.dmm +=b.ddd/30;
   									b.ddd-=30;
						  		 }
								if(b.dmm >12)
						  		 {
						   			b.dyy+=b.dmm/12;
						   			b.dmm-=12;
						 		  }
						   printf("\n Due date:%d-%d-%d",b.ddd,b.dmm,b.dyy);
						   printf("\n The book  %d is sucessfully issued to :",b.id);
						   printf("\n Name:%s",b.name);
						   printf("\n Member id: %d",b.id);
						   printf("\n %d book are remaining of id %d",b.qt,b.id);
						   fseek(fi,sizeof(b),SEEK_END);
						   fseek(fi,sizeof(m),SEEK_END);
							 fwrite(&m,sizeof(m),1,fi);
						   fwrite(&b,sizeof(b),1,fi);
						   fseek(fp,ftell(fp)-sizeof(b),0);
						   fwrite(&b,sizeof(b),1,fp);
						   fclose(fi);
							fclose(fp);
  							fclose(fm);
						   
						   
						}
					}
					
					
					
						
					}
				
				}
					
					
					if(id!=b.id)
					{
						printf("\n  No book record found!");
					
						issue_book();
						
					}
				
					
					 fflush(stdin);
					printf("\nIssue any more(Y/N):");
					
					 another=getche();
   				if(another!=getche())
   				{
   					returnfunc();
				   }
   
 
				}
				returnfunc();
	}
    
    		
			break;
			
		case 2:
			{
					system("cls");
				FILE *fi;
			struct book b;
			struct member m;
				fi=fopen("issue.txt","rb");
				fflush(stdin);
				printf("\nBook ID\t\t\tMember ID\t\tIssue date.\t\t Due date \n");
				
			
				rewind(fi);
				while(fread(&b,sizeof(b),1,fi)==1)
				{
				while(fread(&m,sizeof(m),1,fi)==1)
					
					{
						printf("\n%d	%22d	%d - %d -%d	 %d - %d - %d",b.id,m.id,b.idd,b.imm,b.iyy,b.ddd,b.dmm,b.dyy);
					}
				}
						
					fclose(fi);
					returnfunc();
			}
			break;
		case 3:
		{
						system("cls");
	int id;
	FILE *fi,*fm,*fp,*fd;
	struct book b;
	
	printf("\n Enter the book id to unissue:");
	scanf("%d",&id);
	fi=fopen("issue.txt","rb+");
	fp=fopen("book.txt","rb+");
	fd=fopen("temp.txt","ab+");
	
	if(fp==NULL||fd==NULL||fi==NULL||fm==NULL)
	{
		printf("\n error opening file");
		returnfunc();
	}
	while(fread(&b,sizeof(b),1,fi) == 1)
	{
	 if(id!=b.id)
	 {
		fwrite(&b, sizeof(b),1,fd);
		getch();
	
	 	
	 }
	 
	}
	b.id=b.id+1;
	 fseek(fp,ftell(fp)-sizeof(b),0);
	fwrite(&b,sizeof(b),1,fp);
	fclose(fp);	
	fclose(fd);
	fclose(fi);
	remove("book.txt");
	rename("temp.txt","book.txt");
	printf("\n The record is successfully unissued.");
	printf("\nUnissue another record?(Y/N):");
	if(getch()=='y'|| getch()=='Y')
	issue_book();
	else 
	returnfunc();		
		}	
			
			}
			
	}
	
	void returnfunc()
	{
		{
		{
			printf("\n Press Enter to return to main menu ...");
		}
			a:
			if(getch()==13)
		
			mainmenu();
			else
			goto a;
			
		}
	}


	int checkid(int t) 
{
	FILE *fp;
	struct book b;

    while(fread(&b,sizeof(b),1,fp)==1)
    if(b.id==t)
    return 0;
    return 1;

}  
int checkid1(int i)
{
FILE *fm;
	struct member m;
	while(fread(&m,sizeof(m),1,fm)==1)
	if(m.id==i)
	return 0;
	return 1;
}
void registration()
{
	FILE *rp;
	int choice;
	char pass2[50];
	struct user u;
	rp= fopen("uname.txt","ab+");
	if(rp==NULL)
	{
		system("cls");
		printf("\n\n\t\t\t\t\tLIBRARY MANAGEMENT SYSTEM");
    	printf("\n\n\t\t\t\t\t      Registration Page");
    	printf("\n\t\t  ----------------------------------------------------------------------------");
		printf("\n\t\t  Error Opening file\n");
		exit(1);
	}
	system("cls");
	printf("\n\n\t\t\t\t\tLIBRARY MANAGEMENT SYSTEM");
    printf("\n\n\t\t\t\t\t      Registration Page");
    printf("\n\t\t  ----------------------------------------------------------------------------");
	printf("\n\t\t  Enter Full Name : ");
    fflush(stdin);
    gets(u.fullname);
    printf("\n\t\t  Enter your Phone No. : ");
    gets(u.phone);
    printf("\n\t\t  Enter Username : ");
    gets(u.uname);
    printf("\n\t\t  Enter Password : ");
    getpass(u.pass);
    printf("\n\t\t  Confirm Password : ");
    getpass(pass2);
    if(!strcmp(u.pass,pass2))
    {
    	fwrite(&u,sizeof(u),1,rp);
    	if(fwrite!=0){
    	fclose(rp);
    	printf("\n\n\n\t\t  user registration Sucess.");
    	printf("\n\n\t\t  Press any key to continue");
		getch();
		system("cls");
		main();	
		}
    	else
    	fclose(rp);
    	printf("\n\n\t\t  Sorry ! Something Went wrong");
    	printf("\n\n\t\t  Press any key to continue");
		getch();
		system("cls");
		main();
	}
	else{
		printf("\n\n\t\t  Password do not matched");
		getch();
		system("cls");
		main();
	}
}
void login()
{
	char name[50],passs[50];
	int usrfound=0;
	FILE *rp;
	struct user u;
	rp= fopen("uname.txt","r");
	if(rp==NULL)
	{
		system("cls");
		printf("\n\n\t\t\t\t\tLIBRARY MANAGEMENT SYSTEM");
    	printf("\n\n\t\t\t\t\t        Login Page");
    	printf("\n\t\t  ----------------------------------------------------------------------------");
		printf("\n\t\t  Error Opening file\n");
		exit(1);
	}
	system("cls");
	printf("\n\n\t\t\t\t\tLIBRARY MANAGEMENT SYSTEM");
    printf("\n\n\t\t\t\t\t        Login Page");
    printf("\n\t\t  ----------------------------------------------------------------------------");
	printf("\n\t\t  Enter Username : ");
	fflush(stdin);
	gets(name);
    printf("\n\t\t  Enter Password : ");
    getpass(passs);
    while(fread(&u, sizeof(struct user), 1, rp)==1)
    {
    	  if(!strcmp(u.uname,name)){
			if(!strcmp(passs,u.pass)){
            printf("\n\n\n\t\t\t\t\t  Credential Matched !!");
            printf("\n\n\t\t  Welcome %s To LIBRARY MANAGEMENT SYSTEM", u.fullname);
            printf("\n\n\n\n\t\t  Press any key to continue");
            getch();
            system("cls");
            mainmenu();
        }
        else
        {
            printf("\n\t\t  Password is Incorrect.");
            printf("\n\n\n\t\t  Press any key to continue : ");
            getch();
            login();
        }
        usrfound = 1;
	}
}
if(!usrfound){
	printf("\n\n\t\t  User is not registered");
	getch();
	system("cls");
	main();
}
fclose(rp); 
}
void getpass(char pwd[50])
{
	int i;
	char ch;
	while(1){
		ch = getch();
		if(ch == ENTER || ch == TAB){
			pwd[i] = '\0';
			break;
		}else if(ch == BCKSPC){
			if(i>0){
				i--;
				printf("\b \b");
			}
		}else{
			pwd[i++] = ch;
			printf("* \b");
		}
}
}
