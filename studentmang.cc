#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
void add();
void view();
void menu();
void exit();

struct quiz
{char a,b,c,d;
   char query[200];
   char op1[20];
   char op2[20];
   char op3[20];
   char op4[20];
   char choice[20];
   char choose[30];
   char right[20];
   char marks[20];
   char wrong[20];
   char correct={a|| b|| c|| d};
   int count, money;
   char quit[20];



};
int main()
{ printf("\nEnter your choice : ");
menu();
   return 0;
}
void menu()
{
    int choice;
printf("\nEnter your choice : ");
    scanf("%d",&choice);
switch(choice)
    {
    case 1:
        add();
        break;
case 2:
view();
break;



    default:
        printf("Invalid Choice.");
    }

}
void exit()
{

    exit(0);
}


void add()
{char a,b,c,d;
char correct={a|| b|| c|| d};
char choice;
    FILE *fp;
    struct quiz std;
    char another ='a';
    fp = fopen("record.txt","ab+");
    if(fp == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'a')
    {
        printf("\t\tQ");
        gets(std.query);
        printf("\n\n");
        printf("\n ENTER OPTIONS");
        gets(std.op1);
         printf("\n\n");
        gets(std.op2);
        printf("\n\n");
        gets(std.op3);
         printf("\n\n");
        gets(std.op4);
        printf("\n\n Enter your choice____");
        scanf("%c",choice);
        printf("\n\n Correct ___");
        scanf("%c",correct);




    		if(choice == correct)
			{
			    printf("YOUR ANSWER IS CORRECT!!!!!");
			    printf("YOU WIN__");
			    gets(std.marks);

			    std.count++;
			    printf("money+");
			    scanf("%d",&std.money); _getch();break;}



                else{
		           printf("YOUR ANSWER IS WRONG!!!!");
		           _getch();


		       }




        fwrite(&std,sizeof(std),1,fp);
        printf("\nWant to add of another record? Then press 'a' else 'n'.");
        fflush(stdin);
        another = _getch();
        fflush(stdin);
    }
    fclose(fp);
    menu();

}
void view()
{
    FILE *fp;
    int i=1,j=8;
    struct student std;
    printf("<\n\n\t\t*** VIEW RECORD ***\n\n");
   
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        printf("\nError opening file.");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1)
    {printf("%-7s%-22s%-12s%-9s%-12s%-12s\n",i,std.query,std.op1, std.op2, std.op3, std.op4,std.choice,std.choose,);
        
        i++;
        j++;
    }
    fclose(fp);
    menu();
}