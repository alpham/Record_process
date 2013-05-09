#include "mainwindow.h"
#include <QApplication>
#include<iostream>
#include<fstream>
#include<string.h>
//#include<conio.h>
#include<stdlib.h>
using namespace std;

FILE *fp;
/*Main function starts*/
main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    MainWindow w;
    w.show();
    return app.exec();



//    int ch,i,roll;
//    do
//    {
//        //clrscr();
//        /*Menu for the function*/
//        cout<<"\n\t\t*** Welcome To Our Library Project ***";
//        cout<<"\n\n1-To Create A New File  :>";
//        cout<<"\n\n2-To Insert A New Record In The File :>";
//        cout<<"\n\n3-To Update A Record In The File :>";
//        cout<<"\n\n4-To Search For A Specific Record In The File :>";
//        cout<<"\n\n5-To Display The Data :>";
//        cout<<"\n\n7-To Delete A Record Form The File :>";
//        cout<<"\n\n8-To Exit From The File :>";
//        cout<<"\n\n Enter your choice :> \t";
//        cin>>ch;
//        switch(ch)
//        {
//        case 1:create();break;
//        case 2:insert();break;
//        case 3:update();break;
//        case 4:search(roll);break;
//        case 5:display("Records.txt");break;
//        case 7:Delete();break;
//        case 8: exit(1); break;
//        default:cout<<"\nPlease,Enter Proper Choice   :> ";
//        }
//        system("PAUSE");
//    }while(ch!=8); /*Program terminates on choice 8*/
}

