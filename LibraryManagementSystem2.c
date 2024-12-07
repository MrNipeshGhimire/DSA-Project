#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct book{
	char bookname[20];
};
struct node{
	char name[20];
	int roll;
	char faculty[15];
	int lcode;
	char address[20];
	int n;
	struct book b[5];
	struct node *next;
};
struct node *header;
struct node *getData(){
	char name[20];
	int lcode;
	int roll;
	char address[20];
	char faculty[20];
	char choice;
	char book_name[20];
	int n,i;
	//
	struct node *ptrnew;
	//struct book b[5];
	ptrnew=(struct node*)malloc(sizeof(struct node));
	if(ptrnew==NULL)
	{
		printf("Memory Allocation Failed");
	}else{
	printf("Enter name of Student: ");
    fflush(stdin);
    gets(name);
	printf("Enter Roll num: ");
	//scanf("%d",ptrnew->roll);
	scanf("%d",&roll);
	printf("Enter Faculty: ");
	//gets(ptrnew->faculty);
	fflush(stdin);
	gets(faculty);
	printf("Enter Address: ");
	fflush(stdin);
	gets(address);
	up:
	printf("Enter Library code(int num only): ");
	scanf("%d",&lcode);
	//lcode_checker(lcode);
	if(lcode==lcode_checker(lcode))
	{
		printf("\n\tDuplicate Library Code..!!");
		printf("\n\tLibrary Code Should be unique\n");
		goto up;
	}
	printf("Do you want to lend book(Y/N):");
	scanf(" %c",&choice);
	if(choice=='Y'|| choice=='y')
	{   up1:
		printf("\nEnter number of books:");
		scanf("%d",&n);
		if(n>5)
		{
			printf("\tYou can only receive maximum 5 books..!!");
			goto up1;
		}
		for(i=0; i<n; i++)
		{
			printf("Enter name of book %d: ",i+1);
			fflush(stdin);
			//gets(book_name);
		//	strcpy(ptrnew->b[i].bookname,book_name);
		     gets(ptrnew->b[i].bookname);
		}
	}
		strcpy(ptrnew->name,name);
		ptrnew->roll=roll;
		strcpy(ptrnew->faculty,faculty);
		strcpy(ptrnew->address,address);
		ptrnew->lcode=lcode;
		ptrnew->next=NULL;	
		ptrnew->n=n;
   }
}
void addStudentData()
{
	FILE *fp;
	fp=fopen("Nipesh.txt","w");
	struct node *ptrnew;
	ptrnew=getData();
	if(header==NULL)
	{
		header=ptrnew;
		fwrite(header,sizeof(struct node),1,fp);
		printf("Details added successfully");
	    printf("\nStored into file");	
	}else{
		ptrnew->next=header;
	    header=ptrnew;
	    fwrite(header,sizeof(struct node),1,fp);
	   	printf("Details added successfully");
	   	printf("\nStored into file");
	}
	fclose(fp);
	printf("\n");
	system("pause");
}
void displayData() //display
{
	struct node *ptrthis;
	struct book *b[5];
	int i;
/*	struct node s1;
	FILE *fp;
	fp= fopen("student2.doc","r");
	while(fread(&s1,sizeof(struct node),1,fp))
	{
		strcpy(ptrthis->name,s1.name);
		ptrthis->roll=s1.roll;
		strcpy(ptrthis->faculty,s1.faculty);
		strcpy(ptrthis->address,s1.address);
		ptrthis->lcode=s1.lcode;
		ptrthis->next=NULL;	
		ptrthis->n=s1.n;
	}
*/	/////////////////////////////////
	
	if(header==NULL)
	{
		printf("List is Empty");
	}else{
		printf("\n\t__________________STUDENT RECORDS__________________");
		for(ptrthis=header; ptrthis!=NULL; ptrthis=ptrthis->next)
		{
			printf("\n\n\t\tName         : %s",ptrthis->name);
			printf("\n\t\tRoll No      : %d",ptrthis->roll);
			printf("\n\t\tLibrary code : %d",ptrthis->lcode);
			printf("\n\t\tFaculty      : %s",ptrthis->faculty);
			printf("\n\t\tAddress      : %s",ptrthis->address);
			printf("\n\t\tName of Books received by student:\n");
			for(i=0; i<ptrthis->n; i++)
			{
				//printf("Total N= %d",ptrthis->n);
				printf("\t\t\t%d. %s\n",i+1,ptrthis->b[i].bookname);
			}
			printf("\t___________________________________________________");
		}
	}
	printf("\n");
	system("pause");
}
//=============For receiving Book===========================//
void receiveBook()
{
	struct node *ptrthis;
	//variable decleration
	int lcode,i,n,flag=0;
	if(header==NULL)
	{
		printf(" \nSystem is Empty....!!");
	}else{ 
	         printf("\t\tEnter Library Code: ");
	         scanf("%d",&lcode);
	        for(ptrthis=header; ptrthis!=NULL; ptrthis=ptrthis->next)
	        {
	        	
	        	if(ptrthis->lcode==lcode)
	        	{
	        		flag=1;
	        	 printf("\n\tName         : %s",ptrthis->name);
			     printf("\n\tRoll No      : %d",ptrthis->roll);
			     printf("\n\tLibrary code : %d",ptrthis->lcode);
			     printf("\n\tFaculty      : %s",ptrthis->faculty);
			     printf("\n\tAddress      : %s",ptrthis->address);
			     printf("\n\tName of Books received by student:\n");
			         for(i=0; i<ptrthis->n; i++)
			           {
						printf("\t\t%d. %s\n",i+1,ptrthis->b[i].bookname);
					   }
					   if(ptrthis->n==5)
					   {
					   	printf("\n\tYou have Already Received 5 Books..!");
					     }else{
					     	    wait:
			                    printf("\nEnter numbers of Books:");
							    scanf("%d",&n);
							    if(n==5-ptrthis->n || n<5-ptrthis->n)
							    {
								for(i=ptrthis->n; i<n+ptrthis->n; i++)
								{
							    printf("\nEnter Book %d:",i+1);
							    fflush(stdin);
								gets(ptrthis->b[i].bookname);
							    }
							     ptrthis->n= n + ptrthis->n;  
							//previous num of book + current no. of book
							printf("\nBook Received Successfully..");
						}else{
						    	printf("You can only receive %d Book.",5-ptrthis->n);
						    	goto wait;
							}
			              }
				}	
			}
			if(flag==0)
			{
				printf("\n\tIncorrect Library Code..!!");
			}
		}printf("\n");
		system("pause");
}
//=======================For Returning Book=========================//
void returnBook()
{
	struct node *ptrthis;
	int i,j,pos,lcode,flag=0;
	if(header==NULL)
	{
		printf("\nSystem is Empty..");
	}else{
		printf("Enter Library Code: ");
		scanf("%d",&lcode);
		for(ptrthis=header; ptrthis!=NULL; ptrthis=ptrthis->next)
	        {
	        	if(ptrthis->lcode==lcode)
	        	{
	        		flag=1;
	        	 printf("\n\tName         : %s",ptrthis->name);
			     printf("\n\tRoll No      : %d",ptrthis->roll);
			     printf("\n\tLibrary code : %d",ptrthis->lcode);
			     printf("\n\tFaculty      : %s",ptrthis->faculty);
			     printf("\n\tAddress      : %s",ptrthis->address);
			     if(ptrthis->n==NULL)
			     {
			     	printf("\n\n\tYou haven't received any Book..!!");
				 }else{
			     printf("\n\tName of Books received by student:\n");
			         for(i=0; i<ptrthis->n; i++)
			           {
						printf("\t\t%d. %s\n",i+1,ptrthis->b[i].bookname);
					   }
					   printf("\nEnter the position of Book which you want to returned:");
					   scanf("%d",&pos);
					   for(i=0; i<ptrthis->n; i++)
					   {
					   	if(pos==i+1)
					   	{
					   		for(j=i; j<ptrthis->n; j++)
					   		{
					   	      	ptrthis->b[j]=ptrthis->b[j+1];//paxadi ko data one step agadi aauxa
					        }
					        ptrthis->n--;
						 }
					   }
					   printf("\nBook Returned Successfully");
			   }
			   }  
		   }
		   if(flag==0)
			   {
			   	printf("\tIncorrect Library Code");
			   }
		   printf("\n");
		   system("pause");
	}
}
//===================for update====================================//
void update()
{
	struct node *ptrthis;
	int lcode,i;
	char name[20];
	if(header==NULL)
	{
		printf("System is Empty..!!");
	}else{
		printf("Enter name or Library code of Student: ");
		scanf("%d",&lcode);
		gets(name);
		for(ptrthis=header; ptrthis!=NULL; ptrthis=ptrthis->next)
		{
			if(ptrthis==NULL)
			{
				printf("\nNot Found..");
			}else if(lcode==ptrthis->lcode || strcmp(ptrthis->name,name)==0)
			{
			printf("\n\t__________________STUDENT INFO______________________");
			printf("\n\n\t\tName         : %s",ptrthis->name);
			printf("\tEnter New Name: ");
			fflush(stdin);
			gets(ptrthis->name);
			
			printf("\n\t\tRoll No      : %d",ptrthis->roll);
			printf("\tEnter new Roll No: ");
			scanf("%d",&ptrthis->roll);
			
			printf("\n\t\tLibrary code : %d",ptrthis->lcode);
			printf("\tEnter new Library code: ");
			scanf("%d",&ptrthis->lcode);
			
			printf("\n\t\tFaculty      : %s",ptrthis->faculty);
			printf("\tEnter new Faculty: ");
			fflush(stdin);
			gets(ptrthis->faculty);
			
			printf("\n\t\tAddress      : %s",ptrthis->address);
			printf("\tEnter new Address: ");
			fflush(stdin);
			gets(ptrthis->address);
			printf("\n\t\tInformation Updated Successfully..");
	    	printf("\n\t___________________________________________________");
			}
		}
		
	}
	printf("\n");
	system("pause");
}
//================for searching Data===============================//
void search()
{
	struct node *ptrthis;
	int lcode,i;
	char name[20];
	if(header==NULL)
	{
		printf("System is Empty..!!");
	}else{
		printf("Enter name or Library code of Student: ");
		scanf("%d",&lcode);
		gets(name);
		for(ptrthis=header; ptrthis!=NULL; ptrthis=ptrthis->next)
		{
			if(ptrthis==NULL)
			{
				printf("\nNot Found..");
			}else if(lcode==ptrthis->lcode || strcmp(ptrthis->name,name)==0)
			{
			printf("\n\t__________________STUDENT INFO______________________");
			printf("\n\n\t\tName         : %s",ptrthis->name);
			printf("\n\t\tRoll No      : %d",ptrthis->roll);
			printf("\n\t\tLibrary code : %d",ptrthis->lcode);
			printf("\n\t\tFaculty      : %s",ptrthis->faculty);
			printf("\n\t\tAddress      : %s",ptrthis->address);
			printf("\n\t\tName of Books received by student:\n");
			for(i=0; i<ptrthis->n; i++)
			{
				printf("\t\t\t%d. %s\n",i+1,ptrthis->b[i].bookname);
			}
			printf("\t___________________________________________________");
			}
		}
	}
	printf("\n");
	system("pause");
}
//==============delete record================================//
void deleteRecord()
{
	struct node *ptrthis,*prev;
	int lcode,i;
	char name[20];
	if(header==NULL)
	{
		printf("\n\t\tSystem is Empty..");
	}else{
		printf("Enter Library code of Student: ");
		scanf("%d",&lcode);
		//gets(name);
		ptrthis=header;
		while( ptrthis->lcode!=lcode )
		{
			prev=ptrthis;
			ptrthis=ptrthis->next;
			if(ptrthis==NULL)
			{
				printf("\nNot Found..!!");
				return;
			}
		  /*  else if(lcode==prev->lcode || strcmp(prev->name,name)==0)
			{
			printf("\n\t__________________STUDENT INFO______________________");
			printf("\n\n\t\tName         : %s",prev->name);
			printf("\n\t\tRoll No      : %d",prev->roll);
			printf("\n\t\tLibrary code : %d",ptrthis->lcode);
			printf("\n\t\tFaculty      : %s",ptrthis->faculty);
			printf("\n\t\tAddress      : %s",ptrthis->address);
			printf("\n\t\tName of Books received by student:\n");
			for(i=0; i<ptrthis->n; i++)
			{
				printf("\t\t\t%d. %s\n",i+1,ptrthis->b[i].bookname);
			}
			printf("\t___________________________________________________");
			printf("\n\t\tAre you sure want to Delete this Record?(press enter)");
			}*/
		
		}
			if(ptrthis==header)
			{
				header=header->next;
			}else{
				prev->next=ptrthis->next;
				free(ptrthis);
			}
			
			printf("\nDetail Removed Successfully..");
	   }
	    printf("\n");
	    system("pause"); 
    }
    //==============get from file==========================//
void getFromFile()
{
	struct node *ptrnew;
	struct node *ptrthis;
	struct node s1;
	FILE *fp;
	fp=fopen("Nipesh.txt","r+");
	int i;
	if(fp==NULL)
	{
		printf("\n\tFile is Empty..!!");
	}else{
		   while(feof(fp)==0)
		    {
			while(fread(&s1,sizeof(struct node),1,fp))
			{
				ptrnew=(struct node*)malloc(sizeof(struct node));
				strcpy(ptrnew->name,s1.name);
				ptrnew->roll=s1.roll;
				strcpy(ptrnew->address,s1.address);
				ptrnew->lcode=s1.lcode;
				strcpy(ptrnew->faculty,s1.faculty);
				ptrnew->n=s1.n;
				for( i=0 ;i<ptrnew->n; i++)
				{
					strcpy(ptrnew->b[i].bookname,s1.b[i].bookname);
				}
				ptrnew->next=NULL;
				if(header==NULL)
				{
					header=ptrnew;
				}else{
					ptrthis=header;
					while(ptrthis->next!=NULL)
					{
					ptrnew->next=header;
					header=ptrnew;
					ptrthis=ptrthis->next;
				}
				}
			}
	}
		printf("\n\tData accessed from File..");
	}
	fclose(fp);
	getch();
}
//================Main Function=====================================//
void main()
{
	int choice;
	do{
		system("cls");
		printf("\n\t===| STUDENT INFORMATION AND LIBRARY MANAGEMENT SYSTEM |===\n");
		printf("\t\t_________________________________________");
	    printf("\t\t\t                 \t\t");
		printf("\n\t\t|                        \t\t|");
		printf("\n\t\t|\t1. ADD STUDENT RECORD\t\t|");
		printf("\n\t\t|\t2. DISPLAY RECORD\t\t|");
		printf("\n\t\t|\t3. FOR RECEIVING BOOK\t\t|");
		printf("\n\t\t|\t4. FOR RETURNING BOOK\t\t|");
		printf("\n\t\t|\t5. UPDATE STUDENT RECORD\t|");
		printf("\n\t\t|\t6. SEARCH STUDENT RECORD\t|");
		printf("\n\t\t|\t7. DELETE STUDENT RECORD\t|");
		printf("\n\t\t|\t8. ACCESS FROM FILE\t\t|");
		printf("\n\t\t|\t9. EXIT PROGRAM\t\t\t|");
		printf("\n\t\t|\t                 \t\t|\n");
		printf("\t\t|_______________________________________|");
		printf("\n\n\t\tEnter your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				addStudentData();
				break;
				case 2:
					displayData();
					break;
					case 3:
						receiveBook();
						break;
						case 4:
							returnBook();
							break;
							case 5:
								update();
								break;
							case 6:
								search();
								break;
								case 7:
									deleteRecord();
									break;
									case 8:
										getFromFile();
										break;
									case 9:
									   exit(0);
									   break;
									default:
										printf("\nInvalid Option Given");
										printf("\n");
										system("pause");
		}
	}while(choice!=9);
}
//============Library Code Checker======================//
int  lcode_checker(int lcode)
{
	struct node *ptrthis;
	for(ptrthis=header; ptrthis!=NULL; ptrthis=ptrthis->next)
	{
		if(ptrthis->lcode==lcode)
		{
			
			return lcode;	
		}
	}
}

