#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void menu();
void add();
void view();
void search();
void modify();
void deleterec();
struct student
{
    char name[20];
    char mobile[10];
    int rollno;
    char course[20];
    char branch[20];
};
int main()
{
    
    printf("\n\n\n\t\t*** Student Record Management System ***\n\n");
    menu();
    return 0;
}
void menu()
{
    int choice;
    printf("Enter appropriate number to perform following task.\n");
    printf("\n1 : Add Record.");
    printf("\n2 : View Record.");
    printf("\n3 : Search Record.");
    printf("\n4 : Modify Record.");
    printf("\n5 : Delete.");
    printf("\n6 : Exit.");
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

    case 3:
        search();
        break;

    case 4:
        modify();
        break;

    case 5:
        deleterec();
        break;

    case 6:
        exit(1);
        break;

    default:
        printf("Invalid Choice.");
    }
}
void add()
{
    FILE *fp;
    struct student std;
    char another ='y';
    fp = fopen("record.txt","ab+");
    if(fp == NULL)
    {
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        printf("\t\t*** ADD RECORD ***\n");
        printf("Enter details of student\n");
        printf("\nEnter Name : ");
        gets(std.name);
        printf("\nEnter Mobile Number : ");
        gets(std.mobile);
        printf("\nEnter Roll No : ");
        scanf("%d",&std.rollno);
        fflush(stdin);
        printf("\nEnter Course : ");
        gets(std.course);
        printf("\nEnter Branch : ");
        gets(std.branch);
        fwrite(&std,sizeof(std),1,fp);
        printf("\nWant to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
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
    printf("S.No   Name of Student       Mobile No   Roll No  Course      Branch\n");
    printf("--------------------------------------------------------------------\n");
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        printf("\nError opening file.");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        printf("%-7d%-22s%-12s%-9d%-12s%-12s\n",i,std.name,std.mobile,std.rollno,std.course,std.branch);
        i++;
        j++;
    }
    fclose(fp);
    menu();
}
void search()
{
    FILE *fp;
    struct student std;
    char stname[20];
    printf("\t\t*** SEARCH RECORD ***\n\n");
    printf("Enter name of student : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        printf("\nError opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(stname,std.name) == 0)
        {
            printf("\nName : %s",std.name);
            printf("\nMobile Number : %s",std.mobile);
            printf("\nRoll No : %d",std.rollno);
            printf("\nCourse : %s",std.course);
            printf("\nBranch : %s",std.branch);
        }
    }
    fclose(fp);
    menu();
}
void modify()
{
    char stname[20];
    FILE *fp;
    struct student std;
    printf("\t\t*** MODIFY RECORD ***\n\n");
    printf("Enter name of student to modify: ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        printf("\nError opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stname,std.name) == 0)
        {
            printf("\nEnter name: ");
            gets(std.name);
            printf("\nEnter mobile number : ");
            gets(std.mobile);
            printf("\nEnter roll no : ");
            scanf("%d",&std.rollno);
            printf("\nEnter Course : ");
            fflush(stdin);
            gets(std.course);
            printf("\nEnter Branch : ");
            fflush(stdin);
            gets(std.branch);
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    fclose(fp);
    menu();
}
void deleterec()
{
    char stname[20];
    FILE *fp,*ft;
    struct student std;
    printf("\t\t*** DELETE RECORD ***\n\n");
    printf("Enter name of student to delete record : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        printf("\nError opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL)
    {
        printf("\nError opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(stname,std.name)!=0)
            fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");
    menu();
}