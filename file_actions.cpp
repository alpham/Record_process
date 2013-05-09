#include<iostream>
#include<fstream>
#include<string.h>
//#include<conio.h>
#include<stdlib.h>
using namespace std;

/*Structure created for student record*/
struct Book
{
    int roll_no;
    char name[30];
    char author[30];
    long year;
}book;

void copy(char [],char []);

/*Function to create  the records
In write mode it creates new file and write the records*/

void create()
{
    Book book;
    FILE *fp;
    int total;
    fp=fopen("Records.txt","w");
    if(fp==NULL)
        cout<<"\nUnable to open the file";
    else
    {
        cout<<"\nHow many record(s) do you want to enter\t";
        cin>>total;
        for(int i=0;i<total;i++)
        {
            cout<<"\nEnter the roll Number of book :>" ;
            cin>>book.roll_no;
            cout<<"\nEnter The Name Of The Book :>";
            cin>>book.name;
            cout<<"\nEnter The Author of The Book :>";
            cin>>book.author;
            cout<<"\nEnter The Year Of populate This Book :>";
            cin>>book.year;
            fprintf(fp,"\n%d- \t%s \t%s \t%ld",book.roll_no,book.name,book.author,book.year);
        }
        cout<<"\nRecord(s) inserted successfully...";
        fclose(fp);
    }
}
/*This Function add record to file*/
void insert()
{
    Book book;
    FILE *fp;
    int total;
    fp=fopen("Records.txt","a");
    if(fp==NULL)
        cout<<"\nUnable to open the file";
    else
    {
        cout<<"\nHow many record(s) do you want to enter\t";
        cin>>total;
        for(int i=0;i<total;i++)
        {
            cout<<"\nEnter the roll Number of book :>" ;
            cin>>book.roll_no;
            cout<<"\nEnter The Name Of The Book :>";
            cin>>book.name;
            cout<<"\nEnter The Author of The Book :>";
            cin>>book.author;
            cout<<"\nEnter The Year Of populate This Book :>";
            cin>>book.year;
            fprintf(fp,"\n%d- \t%s \t%s \t%ld",book.roll_no,book.name,book.author,book.year);
        }
        cout<<"\nRecord(s) inserted successfully...";
        fclose(fp);
    }
}


/*This function displays the record of file */

int display(char filename[])
{
    Book book;
    FILE *fp;
    fp=fopen(filename,"r");
    while(fscanf(fp,"\n%d- \t%s \t%s \t%ld",&book.roll_no,book.name,book.author,&book.year)!=EOF)

        cout<<book.roll_no<<"\t"<<book.name<<"\t"<<book.author<<"\t"<<book.year<<"\n";


    fclose(fp);
}


/*Function to search the records of file */
int search(int roll)
{

    Book book;

    FILE *fp;
    fp=fopen("Records.txt","r");
    cout<<"Enter The Roll Number You Want Search For :> ";
    cin>>roll;

    while(fscanf(fp,"\n%d- \t%s \t%s \t%ld",&book.roll_no,book.name,book.author,&book.year)!=EOF)
    {
        if(roll == book.roll_no)
        {
            cout<<book.roll_no<<"\t"<<book.name<<"\t"<<book.author<<"\t"<<book.year<<"\n";
        }
    }
    fclose(fp);
}


/*Function to modify the record with new user-entered data*/
void update()
{
    int roll;
    Book book,book1;
    FILE *fp1,*fp2;
    fp2=fopen("Temp.txt","w");
    fclose(fp2);
    fp1=fopen("Records.txt","r");
    fp2=fopen("Temp.txt","a");
    if(fp1==NULL||fp2==NULL)
        cout<<"\nUnable to to open file";
    else
    {
        cout<<"\nEnter the roll Number to be UPdate :>\t";
        cin>>roll;
        if(search(roll) == 0)
        {
            while(fscanf(fp1,"\n\t%d- \t%s \t%s \t%ld",&book.roll_no,book.name,book.author,&book.year)!=EOF)
            {
                if(roll == book.roll_no)
                {
                    cout<<"Enter The New Roll_no :>";
                    cin>>book1.roll_no;
                    cout<<"Enter The New Name :>";
                    cin>>book1.name;
                    cout<<"Enter The New Author :> ";
                    cin>>book1.author;
                    cout<<"Enter The New Year :>";
                    cin>>book1.year;
                    fprintf(fp2,"\n\t%d- \t%s \t%s \t%ld",book1.roll_no,book1.name,book1.author,book1.year);
                }
                else{
                    fprintf(fp2,"\n\t%d- \t%s \t%s \t%ld",book.roll_no,book.name,book.author,book.year);
                }
            }
            copy("Temp.txt","Records.txt");
            if(remove("Records.txt") == 0 )
                cout<<"\n\tUpdated..\n\n";
            fclose(fp2);
            if(rename("Temp.txt","Records.txt") == 0)
                cout<<"\n\tREnamed...\n\n";
            fclose(fp1);

            cout<<"\n\nRecords updateed successfully...\n\n\n";

        }
    }

    display("Temp.txt");
}

/*Function to delete a record from the file*/
void Delete()
{
    int roll;
    Book book;
    FILE *fp1,*fp2;
    fp2=fopen("Temp.txt","w");
    fclose(fp2);
    fp1=fopen("Records.txt","r");
    fp2=fopen("Temp.txt","a");
    if(fp1==NULL || fp2==NULL)
        cout<<"\nUnable to to open file";
    else
    {
        cout<<"\nEnter the roll Number to be deleted\t";
        cin>>roll;
        if(search(roll) == 0)
        {
            while(fscanf(fp1,"\n\t%d- \t%s \t%s \t%ld",&book.roll_no,book.name,book.author,&book.year)!=EOF)
            {
                if(roll != book.roll_no)
                {
                    fprintf(fp2,"\n\t%d- \t%s \t%s \t%ld",book.roll_no,book.name,book.author,book.year);
                }
            }
            copy("Temp.txt","Records.txt");
            if(remove("Records.txt") == 0 )
                cout<<"\n\tRemoved..\n\n";
            fclose(fp2);
            if(rename("Temp.txt","Records.txt") == 0)
                cout<<"\n\tREnamed...\n\n";


            fclose(fp1);

            cout<<"\n\nRecords deleted successfully...\n\n\n";
        }
    }
    display("Temp.txt");
}

/*Function to copy all records from one file to other*/
void copy(char f1[],char f2[])
{
    Book book;
    FILE *fp1,*fp2;
    fp1=fopen(f1,"r");
    fp2=fopen(f2,"w");
    if(fp1==NULL || fp2==NULL)
        cout<<"\nUnable to to open file";
    else
    {
        while(fscanf(fp1,"\n\t%d- \t%s \t%s \t%ld",&book.roll_no,book.name,book.author,&book.year)!=EOF)
        {
            fprintf(fp2,"\n\t%d- \t%s \t%s \t%ld",book.roll_no,book.name,book.author,book.year);
        }
        fclose(fp1);
        fclose(fp2);
        cout<<"\n\nRecords copied successfully...";
    }
}

