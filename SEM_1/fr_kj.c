#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char key[50];
char key1[50];
char dat[8000];
char pass[]="passwordoftheworldishereinprogrambutyoucantguessit";
FILE *fil, *file, *file2;
int homescan(int);
int initial();
int homeprt();
int birthadd();
int birthsrch();
int birthsrchn();
int birthsrchd();
int birthsrchm();
int keyinit();
int keyverify();
int encrypt();
int decrypt();
int printdat(int *, int);
int rite(char *);
int move(int );
int initial()
{
	printf("WELCOME TO BIRTHDAY REMINDER.\nThis screen will appear only once.\nPlease read this carefully and proceed.");
	printf("\nThe Data stored by Birthday reminder is stored in encrypted form. It is inaccessible without key");
	printf("\nPlease exit the program properly else data might be inaccessible.\nPress Enter to Proceed"); // First Time Run Initialisation
	char enter;
	scanf("%c", &enter);
	fil = fopen("4help.dat", "w+");
	if (fil == NULL)
	{
         printf("There is some error with the permissions I have.\n");
		 exit(-1);
	}
	else
	{
		fclose(fil);
		keyinit();
	}
}
int homeprt()
{
	printf("\n Please Enter the keywords to proceed.\nEnter:");
	printf("\n1 -> Add a New Birthday");
	printf("\n2 -> Search For Person");
	//printf("\n3 -> View All Friends Names");
	printf("\n4 -> Exit\n"); // Printing Home Input
	int homein;
	scanf("%d", &homein);
	homescan(homein); 
}
int homescan(int homein)
{
	if (homein==1)// home input and proceed
	birthadd();
	if (homein==2)// home input and proceed
	birthsrch();
	/*if (homein==3)// home input and proceed
	{
		file2=fopen("4help1.dat","r");
	if (file2==NULL)
	{
		printf("\n No Birthdays Stored");
		exit(-1);
	}
	int details[100],mm;
	fscanf(file2, "%d", &mm);
	fclose(file2);
	printf("%d", mm);
	for (int kk=0;kk<mm;kk++)
		details[100]=kk;
		printdat(&details[0], mm);
	}*/
	if (homein==4)// home input and proceed
	{
	exit(-1);
	}
	if (homein>4)
	{
		printf("\nInvalid Input");
		exit(-1);
	}
	//if (homein==2)
}
int birthadd()
{
	char temp[50];
	int counter=0;
	printf("\nPlease enter First Name: ");
	scanf("%s", &temp);
	rite(temp);
	printf("\nPlease enter Middle Name: ");
	scanf("%s", &temp);
	rite(temp);
	printf("\nPlease enter Last Name: ");
	scanf("%s", &temp);
	rite(temp);
	printf("\nPlease enter Date of Birth(dd.mm.yyyy): ");
	scanf("%s", &temp);
	rite(temp);
	printf("\nPlease enter Mobile Number(must be 10digit long): ");
	scanf("%s", &temp);
	if (strlen(temp)!=10)
	{
		printf("\nPlease enter Mobile Number(must be 10digit long): ");
		scanf("%s", &temp);
		rite(temp);
	}
	else
	{
	rite(temp);
	}
	printf("\nPlease enter Email Address: ");
	scanf("%s", &temp);
	rite(temp);
	file= fopen("4help1.dat","r");
	if (file==NULL)
		counter==0;
	else
	{
		fscanf(file, "%d", &counter);
		fclose(file);
	}
	counter++;
	file= fopen("4help1.dat","w+");// Birtdhay Add
	fprintf(file, "%d", counter);
	fclose(file);
	homeprt();
}
int birthsrch()
{
	printf("\nPlease enter how you want to search for birthday\n1)By Name\n2)By Date of Birth\n3) By Mobile no.\n");
	int where;
	scanf("%d", &where);
	if (where==1)
	birthsrchn();
	if (where==2)
	birthsrchd();
	if (where==3)
	birthsrchm();
	if (where>=4)
	{
		printf("\nInvalid Input");
		exit(-1);
	}
	
}
int birthsrchn()
{
	printf("Please Enter the name of person");
	char name[50], name2[50];
	scanf("%s", &name);
	file2=fopen("4help1.dat","r");
	if (file2==NULL)
	{
		printf("\n No Birthdays Stored");
		exit(-1);
	}
	int total;
	fscanf(file2,"%d", &total);
	fclose(file2);
	int coun=0,q=0;
	int detail[50],mmm=0;
	for (int i=0;i<total;i++)
	{
		coun=0;
		q=0;
		for (int j=1;j<4;j++)
		{
			fclose(file);
			move(((6*i)+j));
			q=0;
			fscanf(file,"%s", &name2);
			coun=0;
			//printf("\n%s", &name2);
			for(int k=0;k<strlen(name2);k++)
			{
				if (name[q]==name2[k])
				{
					coun++;
					q++;
				}
				if(coun==strlen(name))
				{
					//printf("%d", i);
					detail[mmm]=i;
					mmm++;
					j=4;
					k=strlen(name);
					coun=0;
					fclose(file);
				}
			}
		}
	}
	printdat(&detail[0], mmm);
	homeprt();
	
}
int birthsrchm()
{
	printf("Please Enter Mobile No. Of Person");
	char name[50], name2[50];
	scanf("%s", &name);
	file2=fopen("4help1.dat","r");
	if (file2==NULL)
	{
		printf("\n No Data Stored");
		exit(-1);
	}
	int total;
	fscanf(file2,"%d", &total);
	fclose(file2);
	int coun=0,q=0;
	int detail[50],mmm=0;
	for (int i=0;i<total;i++)
	{
		coun=0;
		q=0;
		for (int j=5;j<6;j++)
		{
			fclose(file);
			move(((6*i)+j));
			q=0;
			fscanf(file,"%s", &name2);
			coun=0;
			//printf("\n%s", &name2);
			for(int k=0;k<strlen(name2);k++)
			{
				if (name[q]==name2[k])
				{
					coun++;
					q++;
				}
				if(coun==strlen(name))
				{
					//printf("%d", i);
					detail[mmm]=i;
					mmm++;
					j=6;
					k=strlen(name);
					coun=0;
					fclose(file);
				}
			}
		}
	}
	printdat(&detail[0], mmm);
	homeprt();
	
}
int birthsrchd()
{
	printf("Please Enter Birthdate Of Person(date or month or dd.mm.yyyy) :");
	char name[50], name2[50];
	scanf("%s", &name);
	file2=fopen("4help1.dat","r");
	if (file2==NULL)
	{
		printf("\n No Data Stored");
		exit(-1);
	}
	int total;
	fscanf(file2,"%d", &total);
	fclose(file2);
	int coun=0,q=0;
	int detail[50],mmm=0;
	for (int i=0;i<total;i++)
	{
		coun=0;
		q=0;
		for (int j=4;j<5;j++)
		{
			fclose(file);
			move(((6*i)+j));
			q=0;
			fscanf(file,"%s", &name2);
			coun=0;
			//printf("\n%s", &name2);
			for(int k=0;k<strlen(name2);k++)
			{
				if (name[q]==name2[k])
				{
					coun++;
					q++;
				}
				if(coun==strlen(name))
				{
					//printf("%d", i);
					detail[mmm]=i;
					mmm++;
					j=5;
					k=strlen(name);
					coun=0;
					fclose(file);
				}
			}
		}
	}
	printdat(&detail[0], mmm);
	homeprt();
}
int printdat(int * detail, int mmm)
{
	char name2[50];
	//printf("%d", &mmm);
	if (mmm==0)
	{
	printf("\n No Match Found");
	}
	else
	{
		printf("\nData Of Following Persons is/are matched\n\n");
		for (int i=0;i<mmm;i++)
		{
			printf("%d)", i+1);
			int x;
			x=detail[i];
			for (int j=1;j<7;j++)
			{
				if (j==1)
					printf("Name:");
				if (j==4)
					printf("\n  Date Of Birth:");
				if (j==5)
					printf("\n  Mobile number:");
				if (j==6)
					printf("\n  Email: ");
				fclose(file);
				move(((6*x)+j));
				fscanf(file,"%s", &name2);
				printf(" %s", name2);
			}
					printf("\n\n");
		}
	}
}
int move(int moved)
{
	file=fopen("4help_1.dat","r");
	for (int i=0;i<moved-1;i++)
		fscanf(file, "%*[^\n]\n");
}
int keyinit()
{
	printf("\nPlease enter the new password(ASCII characters only except spaces. :"); //New Password Set
	fil = fopen("4help.dat", "a");
	if (fil == NULL)
	{
		printf("There is some error with the permissions I have.\n");
		exit(-1);
	}
	while (strlen(key)<8)
	{
		printf("\nThe password should be min of 8 characters: ");
		scanf(" %s", &key);
	}
	for (int i=0;i<strlen(key);i++)
		key[i]=key[i]+pass[i];
	fprintf(fil, "%s\n", key);
	fclose(fil);
}
int keyverify()
{
	printf("Please Enter the password: ");
	scanf("%s", &key);
	fil = fopen("4help.dat", "r");
	for (int i=0;i<=strlen(key);i++)
	{
		key[i]=key[i]+pass[i];
	}
	int count=0;
	fscanf(fil, "%s",&key1);
	count=0;
	for (int i=0;i<strlen(key1);i++)
	{
		if (key1[i]==key[i])
		count++;
	}
	if (count==strlen(key1))
	{
		printf("Key Verified\n");
		homeprt();
		
	}
	else
	{
		printf("Not Verified");
		exit(-1);
	}
	fclose(fil);
	
	
}
/*int encrypt()
{
fil = fopen("4help_1.dat","r");
fscanf(fil, "%[]*c", dat);
fclose(fil);
int j=0;
for (int i=0;i<strlen(dat);i++)
	{
	dat[i]=dat[i]+key[j];
	j++;
	if (j>=strlen(key1))
		j=0;
	}
fil = fopen("4help_2.dat", "w+");
fprintf(fil, "%s", dat);
fclose(fil);
}
int decrypt()
{
fil = fopen("4help_2.dat","r");
fscanf(fil, "%[]*c", dat);
fclose(fil);
int j=0;
for (int i=0;i<120;i++)
	{
	dat[i]=dat[i]-key[j];
	j++;
	if (j>=strlen(key1))
		j=0;
	}
fil = fopen("4help_3.dat", "w+");
for (int kk=0;kk<120;kk++)
fprintf(fil, "%c", dat[kk]);
fclose(fil);
}*/
int rite(char * me)
{
	file = fopen("4help_1.dat","a");
	fprintf(file, "%s\n", me);
	fclose(file);
}
int main()
{
	if ((fil = fopen("4help.dat","r"))!=NULL)
		keyverify();
	else
	{
		initial();
		keyverify();
	}
	file = fopen("4help_1.dat", "r");
	if(file==NULL)
		file = fopen("4help_1.dat", "w+");
		fclose(file);
}