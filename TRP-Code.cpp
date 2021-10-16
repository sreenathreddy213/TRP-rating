#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

FILE *fp,*ft;
char choice='y';
char NAME[40];

void home();

struct show
{
char sh[40];
float t;
}s;

void rating_program()
{
fp=fopen("rating.txt","a+");
    
    if(fp==NULL)
    {
    system("cls");
printf("\n\n\n\t\t\t\t\tFile Creation failed");
    getch();
    home();
}

choice='y';

while(choice=='y' || choice=='Y')
{
system("cls");

printf("\n\n Enter name of the program : ");
    scanf("%s",s.sh);
    fflush(stdin);
    printf("\n\n Enter trp : ");
    scanf("%f",&s.t);
    
    
    fwrite(&s,sizeof(s),1,fp);
    printf("\n\n Do you want to Add another program : Enter 'y'/'Y'");     
    fflush(stdin);
    choice=getche();
}

fclose(fp);
}

void view_details()
{
fp=fopen("rating.txt","a+");

system("cls");
printf("\n Enter the Name of the Program : ");
fflush(stdin);
    scanf("%s",NAME);
    
    while(fread(&s,sizeof(s),1,fp)==1)
    {
    if(strcmp(s.sh,NAME)==0)
    {
    system("cls");
    printf("\n\n Name of the Program : %s",s.sh);
    printf("\n\n TRP Rating : %0.1f%%",s.t);    
    getch();
}
}

fclose(fp);
}


void update_rating()
{
fp=fopen("rating.txt","a+");
ft=fopen("Temp.txt","a+");

system("cls");
printf("\n Enter the Name of the Program : ");
    scanf("%s",NAME);
    
    while(fread(&s,sizeof(s),1,fp)==1)
    {
    if(strcmp(s.sh,NAME)==0)
    {
    system("cls");
    printf("\n Enter the New TRP Rating : ");
    
    scanf("%f",&s.t);
    fflush(stdin);
    
    
    fwrite(&s,sizeof(s),1,ft);
}
else
{
fwrite(&s,sizeof(s),1,ft);
}
}

fclose(fp);
fclose(ft);
printf("\n\n Details Successfully Updated");
getch();
remove("rating.txt");
rename("Temp.txt","rating.txt");
}

void program_deletion()
{
fp=fopen("rating.txt","a+");
ft=fopen("Temp.txt","a+");

system("cls");
printf("\n Enter the Name of the Program : ");
scanf("%s",NAME);

while(fread(&s,sizeof(s),1,fp)==1)
{
if(strcmp(s.sh,NAME))
{
fwrite(&s,sizeof(s),1,ft);
}
}

fclose(fp);
fclose(ft);
printf("\n\n Details Removed Successfully"); 
getch();
remove("rating.txt");
rename("Temp.txt","rating.txt");
}



void all_programs()
{
system("cls");
fp=fopen("rating.txt","a+");

printf("\n\n Name\t:\tTRP Rating   ");
while(fread(&s,sizeof(s),1,fp)==1)
{
printf("\n\n %s\t:\t%0.1f%% ",s.sh,s.t); 
}
getch();
fclose(fp);
}

void home()
{
int ch;

while(1)
{

system("cls"); 
printf("\n\n\t\t*********************************************\n");
    printf("\t\t******** WELCOME TO ENQUIRY COUNTER *********\n");
    printf("\t\t*********************************************\n");
printf("\n\t\tPress 1 to Rate the program.");
printf("\n\t\tPress 2 to Know the details of the program.");
printf("\n\t\tPress 3 to Update the rating of program.");
printf("\n\t\tPress 4 to Delete the program data.");
printf("\n\t\tPress 5 to View all Telecasting programs.");
    printf("\n\t\tPress 6 to Exit.\n");

printf("\n\n\n Choose from the above options : ");
scanf("%d",&ch);

switch(ch)
{
case 1: rating_program();      break;
case 2: view_details();        break;
case 3: update_rating();       break;
case 4: program_deletion();    break;
case 5: all_programs();        break;
case 6: exit(0);
default: printf("\n\n Invalid Option Chosen "); getch();
}

} 
}

int main()
{
home();
}
