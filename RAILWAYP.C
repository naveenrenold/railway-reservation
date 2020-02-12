#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
void Homepage();     //6functions
void Files(int);
void Booking(int);
void Cancelling();
void Availability();
void Chart();
struct Details       //struct
{                   //1.use files to get the data and
int no,totalno;             //2.do operations with struct in program
struct seats
{
char name[10];
int age;
char gender[10];
}Tickets[50];
}Trains[3];
FILE *folder,*temp;           //file declared commonly
int main()
{
int i;
//struct Details Trains[3];
/**for(i=0;i<=2;i++)
{
Trains[i].no=0;
}  **/
clrscr();
Homepage();       //calling only homepage at main
return 0;
}
void Homepage()   //1.homepage
{
int m,i;
char a[10];
printf("\t\t\tWELCOME TO THE HOMEPAGE");
printf("\n\n\nWhat do you want to do?\n1.Book Tickets\n2.Cancel a Ticket\n3.See Train Chart\n4.Log Out\n5.IRCTC personnel login");
printf("\n\tEnter option here:");
scanf("%d",&m);
switch(m)
{
case 1:
{
clrscr();
Availability();
break;
}
case 2:
{
clrscr();
Cancelling();
break;
}
case 3:
{
clrscr();
Chart();
break;
}
case 4:                 //exit program
{
clrscr();
printf("\n\n\n\t\tThank you for using IRTCC");
getch();
break;
}
case 5:                 //for deleting file details
{
 clrscr();
 printf("Enter top secret password:");
 {
 scanf("%s",&a);
 }
 if(!(strcmp(a,"trainz")))
 {
 folder=fopen("Data1.txt","w");
 fclose(folder);
 folder=fopen("Data2.txt","w");
 fclose(folder);
 folder=fopen("Data3.txt","w");
 fclose(folder);
 }
 else
{
 printf("Imposter!!!");
}
clrscr();
 getch();
 Homepage();
 break;
}
default:                   //return to homepage
{
clrscr();
printf("OOPS INVALID OPTION\nPress any key to continue");
getch();
clrscr();
Homepage();
}
}
}
void Availability()       //2.checks availability and calls booking
{
int n,x;
printf("\t\t\tTRAINS\n1.Ananthapuri Exprees\n2.Kanyakumari SuperFast Exprees\n3.Guruvayur Exprees");
printf("\n\n\n\tChoose a Train:");
scanf("%d",&n);
Files(n);
/**switch(n)
{
case 1:
{**/
if(Trains[n-1].no<50)
{
printf("%d Tickets Are Available",50-Trains[n-1].no);
printf("\n\t\t\t\tBOOK NOW");
printf("\n\t\t1.YES\t\t\t\t2.NO\n");
scanf("%d",&x);
if(x==1)
{
Booking(n);
}
else{
clrscr();
Homepage();
}
}
else                 //if no go to homepage
{
printf("Selected train is fully booked:(\nPlease choose another train");
getch();
clrscr();
Homepage();
}
/**break;
}
case 2:
{
if(Trains[1].no<50)
{
printf("%d Tickets Are Available",50-Trains[2].no);
printf("\n\t\t\t\tBOOK NOW");
printf("\n\t\t1.YES\t\t\t\t2.NO\n");
scanf("%d",&x);
if(x==1)
{
Booking(2);
}
else{
clrscr();
Homepage();
}

}
else
{
printf("Selected train is fully booked:(\nPlease choose another train");
getch();
Homepage();
}
break;
}
case 3:
{
if(Trains[2].no<50)
{
printf("%d Tickets Are Available",50-Trains[2].no);
printf("\n\t\t\t\tBOOK NOW");
printf("\n\t\t1.YES\t\t\t\t2.NO\n");
scanf("%d",&x);
if(x==1)
{
Booking(3);
}
else{
clrscr();
Homepage();
}
}
else
{
printf("Selected train is fully booked:(\nPlease choose another train");
getch();
Homepage();
}
break;
}**/
}
void Booking(int a)           //3.called after checking availability
{
int b,i=1;
printf("\nEnter the no of Tickets:");
scanf("%d",&b);
if(b+Trains[a-1].no>=50)
{
printf("Only %d tickets are available\n Please try another train",50-Trains[b-1].no);
getch();
clrscr();
Homepage();
}
else
{
clrscr();
if(a==1)
{
folder=fopen("Data1.txt","a");
}
if(a==2)
{
folder=fopen("Data2.txt","a");
}
if(a==3)
{
folder=fopen("Data3.txt","a");
}
//folder=fopen("Data.txt","a");         //open file in append mode to add details
//printf("PNR No\tName\t\tAge\tGender");  //just printed
do                //loop to print to file in proper format
{
printf("\n\tPNR No:%d\t",Trains[a-1].totalno+1);
printf("\nName:");
scanf("%s",Trains[a-1].Tickets[Trains[a-1].no].name);
printf("\nAge:");
scanf("%d",&(Trains[a-1].Tickets[Trains[a-1].no].age));
printf("\nGender:");
scanf("%s",Trains[a-1].Tickets[Trains[a-1].no].gender);
//scanf("%s%d%s",Trains[a-1].Tickets[Trains[a-1].no].name,&(Trains[a-1].Tickets[Trains[a-1].no].age),Trains[a-1].Tickets[Trains[a-1].no].gender);

fprintf(folder,"\n%d\t%s\t\t%d\t%s",Trains[a-1].totalno+1,Trains[a-1].Tickets[Trains[a-1].no].name,(Trains[a-1].Tickets[Trains[a-1].no].age),Trains[a-1].Tickets[Trains[a-1].no].gender);
//scanf("%s\t%d\t%s",Trains[a-1].Tickets[Trains[a-1].no].name,&(Trains[a-1].Tickets[Trains[a-1].no].age),Trains[a-1].Tickets[Trains[a-1].no].gender);
/**printf("%s",Trains[a-1].Tickets[Trains[a-1].no].name);
printf("\t");
scanf("%d",&(Trains[a-1].Tickets[Trains[a-1].no].age));
printf("\t");
scanf(" %s", Trains[a-1].Tickets[Trains[a-1].no].gender);**/
(Trains[a-1].no)++;
(Trains[a-1].totalno)++;
i++;
}while((Trains[a-1].no<50)&&i<=b);
fclose(folder);
clrscr();
Homepage();
}
}
void Chart()         //4.chart
{
char c;
int a,x=0;
printf("\t\t\tTRAINS\n1.Ananthapuri Exprees\n2.Kanyakumari SuperFast Exprees\n3.Guruvayur Exprees");
printf("\n\n\n\tChoose a Train:");
scanf("%d",&a);
if(a==1)
{
folder=fopen("Data1.txt","r");
}
if(a==2)
{
folder=fopen("Data2.txt","r");
}
if(a==3)
{
folder=fopen("Data3.txt","r");
}
printf("PNR No\tName\t\tAge\tGender\n");//just printed
while((c=getc(folder))!=EOF)     //loop to print the entire file till end
{
if(c=='\n')
{
if(x==0)
{
printf("%c",c);
x=1;
}
}
else
{
x=0;
printf("%c",c);
}
}
fclose(folder);                  //close
getch();
clrscr();
Homepage();
}
void Files(int a)                //5.files
{
int i=0,x=0;
char c;
if(a==1)
{
folder=fopen("Data1.txt","r");
}
if(a==2)
{
folder=fopen("Data2.txt","r");
}
if(a==3)
{
folder=fopen("Data3.txt","r");
}
rewind(folder);
while((c=getc(folder))!=EOF)
{
if(c=='\n')
{
if(x==0)
{
i++;
x=1;
}
}
else
x=0;
}
if(x==1)
i=i-1;
//printf("%d",i);
Trains[a-1].no=i;
rewind(folder);
i=0;
while((c=getc(folder))!=EOF)
{
if(c=='\n')
{
i++;
}
}
Trains[a-1].totalno=i;
//getch();
fclose(folder);
}
void Cancelling()
{
char c;
char name[500];
int age;
char gender[250];
int a,t,i,pnrno;
printf("\t\t\tTRAINS\n1.Ananthapuri Exprees\n2.Kanyakumari SuperFast Exprees\n3.Guruvayur Exprees");
printf("\n\n\n\tChoose a Train:");
scanf("%d",&a);
/**if(a==1)
{
folder=fopen("Data1.txt","r");
}
if(a==2)
{
folder=fopen("Data2.txt","r");
}
if(a==3)
{
folder=fopen("Data3.txt","r");
}**/
clrscr();
printf("\t\t\tTicket Canceling Centre");
//printf("\nEnter the number of tickets:");
//scanf("%d",&n);
printf("\n\tEnter PNR number:\n");
temp=fopen("temp.txt","w+");
//printf("S.no\tPNR No\tName\t\tAge\tGender\n");
//for(i=0;i<n;i++)
//{
i=0;
if(a==1)
{
folder=fopen("Data1.txt","r");
}
if(a==2)
{
folder=fopen("Data2.txt","r");
}
if(a==3)
{
folder=fopen("Data3.txt","r");
}
rewind(folder);
printf("\n%d.",i+1);
scanf("%d",&t);
while((fscanf(folder,"%d%s%d%s",&pnrno,name,&age,gender))!=EOF)
{
//fscanf(folder,"%d%s%d%s",&pnrno,name,&age,gender);
if(pnrno!=t)
fprintf(temp,"\n%d\t%s\t\t%d\t%s",pnrno,name,age,gender);
else
fprintf(temp,"\n");
}
fclose(folder);
fclose(temp);
if(a==1)
{
remove("Data1.txt");
rename("temp.txt","Data1.txt");
}
if(a==2)
{
remove("Data2.txt");
rename("temp.txt","Data2.txt");
}
if(a==3)
{
remove("Data3.txt");
rename("temp.txt","Data3.txt");
}
printf("\t\tCancelled");
getch();
clrscr();
Homepage();
}
//}