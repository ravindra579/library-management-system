#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<cstring>
#include<cmath>

using namespace std;
void intro(void);
void write_b();
class book{
    char bno[6];
    char bname[10];
    char aname[10];
public:
    void create_book()
    {
    cout<<"enter bno"<<endl;
    cin>>bno;
      cout<<"enter bname"<<endl;
    cin>>bname;
      cout<<"enter aname"<<endl;
    cin>>aname;
    }
    void show_book(){
    cout<<bno<<endl;
    cout<<bname<<endl;
    cout<<aname<<endl;
    }
    void modify_book(){
    cout<<" book no"<<bno<<endl;
    cout<<"enter new book name"<<endl;
    cin>>bname;
     cout<<"enter new auther name"<<endl;
    cin>>aname;
    }
    char*retbno(){
    return bno;
    }
    void report(){
    cout<<bno<<endl;
    cout<<bname<<endl;
    cout<<aname<<endl;
    }}bk;
class student{
    char sno[10];
    char sname[10];
    char stbno[10];
    int token;
public:
    void create_stduent()
    {
    cout<<"enter sno"<<endl;
    cin>>sno;
      cout<<"enter sname"<<endl;
    cin>>sname;
      token =0;
      //stbno[0]="/0";
    }
    void show_student(){
    cout<<sno<<endl;
    cout<<sname<<endl;
    cout<<"no. of books issued"<<token<<endl;
    cout<<"book no"<<stbno<<endl;
    }
    void modify_student(){
    cout<<" student no"<<sno<<endl;
    cout<<"enter new student name"<<endl;
    cin>>sname;
    }
    char* retsno(){
    return sno;
    }
    char* retstbno(){
    return stbno;
    }
    int rettoken(){
    return token;
    }
    void addtoken(){
    token=1;
    }
    void resettoken(){
    token=0;
    }
     //getstbno(char n[]){
     //strcpy(stbno,n);
    //}
    void report(){
    cout<<sno<<endl;
    cout<<sname<<endl;
    cout<<stbno<<endl;
    cout<<token<<endl;
    }}st;

class admin1{
    char adminname[10];
    char adminpassword[10];

public:
    char* retadminname(){
    return adminname;
    }
    char* retadminpassword(){
    return adminpassword;
    }
    }ad;
     fstream fp,fp1;
    void intro(){
    cout<< "welcome to library"<<endl;
    }
    /*void admin(){
    char* ch;
    char* n;
    int flag=0;
    int found=0;
    cout<<"enter name and password";
    cin>>ch>>n;
    int a=0;
    fp.open("admin.txt",ios::in);
    while(fp.read((char*)&ad,sizeof(admin1))){
        if(strcmpi(ad.retadminname(),ch)==0){
            flag=1;
            break;
        }
        if(strcmpi(ad.retadminpassword(),n)==0){
            found==1;
            break;
        }}
        if(flag==0){
            cout<<"incorrect user name"<<endl;
        }
        if(found==0){
            cout<<"password incorrect"<<endl;
    }
    do{
    if(flag==1 && found==1){
        system("cls");
        cout<<"ADMIN MENU"<<endl;
        cout<<"1.create student record"<<endl;
        cout<<"2.display all students records"<<endl;
        cout<<"3.modify student records"<<endl;
        cout<<"4.delete"<<endl;
        cout<<"5.create book"<<endl;
        cout<<"6.display all books"<<endl;
        cout<<"7.display specific book"<<endl;
        cout<<"8.display specific student record"<<endl;
        cout<<"9.modify book"<<endl;
        cout<<"10.delete book"<<endl;
        cout<<"11.back to main menu"<<endl;
        cin>>a;

    }
    switch(a){
        system("cls");
        case 1:void write_s();
               break;
        case 2:void display_alls();
               break;
        case 3:void modify_s();
               break;
        case 4:void delete_s();
               break;
        case 5:void write_b();
               break;
        case 6:void display_allb();
               break;
        case 7:{char num[10];
                system("cls");;
                cout<<"enter book no"<<endl;
                cin>>num;
                char* display_b(num);
                break;
        }
        case 8:{char num[10];
                system("cls");;
                cout<<"enter student no"<<endl;
                cin>>num;
                char* display_s(num);
                break;
        }
        case 9:void modify_b();
               break;
        case 10:void delete_b();
               break;
        //case 11: exit();
          //    break;
    }
    }while(a!=11);
    }*/
void write_b(){
    char ch;
    fp.open("book.txt",ios::out|ios::in);
    ofstream p;
    do{
        system("cls");
        bk.create_book();

        fp.write((char*)&bk,sizeof(book));
        cout<<"do you want to add more books (y/n)?"<<endl;
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}
void write_s(){
     char ch;
    fp.open("book",ios::out|ios::app);
    do{
        system("cls");
        bk.create_book();
        fp.write((char*)&st,sizeof(student));
        cout<<"do you want to add more  (y/n)?"<<endl;
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}
void display_b(char n[]){
    cout<<"book details";
    int flag=0;
    fp.open("book",ios::in);
    while(fp.read((char*)&bk,sizeof(book))){
        if(strcmpi(bk.retbno(),n)==0){
            bk.show_book();
            flag=1;
        }
    }
    fp.close();
    if(flag==0){
        cout<<"not found"<<endl;
    }
}
void display_s(char n[]){
    cout<<"student details";
    int flag=0;
    fp.open("student",ios::out);
    while(fp.read((char*)&st,sizeof(student))){
        if(strcmpi(st.retsno(),n)==0){
            bk.show_book();
            flag=1;
        }
    }
    fp.close();
    if(flag==0){
        cout<<"not found"<<endl;
    }
}
void display_allb(){
    system("cls");
    cout<<"book details"<<endl;
    fp.open("book",ios::in);
    while(fp.read((char*)&bk,sizeof(book))){
            bk.show_book();
        }
    fp.close();
}
void display_alls(){
    system("cls");
    cout<<"student details"<<endl;
    fp.open("book",ios::in);
    while(fp.read((char*)&bk,sizeof(book))){
            bk.show_book();
        }
    fp.close();
}
void modify_b(){
    char n[6];
    int found=0;
    cout<<"modify book record"<<endl;
    cin>>n;
    fp.open("book.txt",ios::in|ios::out);
    while(fp.read((char*)&bk,sizeof(book))&&found==0){
        if(strcmpi(bk.retbno(),n)==0){
            bk.show_book();
            cout<<"enter new details"<<endl;
            bk.modify_book();
            fp.write((char*)&bk,sizeof(book));
            found=1;
        }
    }
    fp.close();
    if(found==0){
        cout<<"record not found"<<endl;
    }
}
void modify_s(){
    char n[6];
    int found=0;
    cout<<"modify student record"<<endl;
    cin>>n;
    fp.open("student",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student))&&found==0){
        if(strcmpi(st.retsno(),n)==0){
            st.show_student();
            cout<<"enter new details"<<endl;
            st.modify_student();
            fp.write((char*)&bk,sizeof(student));
            found=1;
        }
    }
    fp.close();
    if(found==0){
        cout<<"record not found"<<endl;
    }
}
void delete_b(char n[]){
    fstream fp2;
    fp2.open("a.txt",ios::in|ios::out);
    fp.open("book.txt",ios::in|ios::out);
    int flag=0;
    while(((char*)&bk,sizeof(book))&&flag==0){
        if(strcmpi(bk.retbno(),n)!=0){
            fp2.write((char*)&bk,sizeof(book));
        }
        if("book.txt"=="a.txt"){
            flag=1;
        }
        fp2.close();
        fp.close();
        remove("book");
        rename("a","book");
        if(flag==1){
            cout<<"record not found"<<endl;
        }
    }
}
void delete_s(char n[]){
    fstream fp2;
    fp2.open("b",ios::in|ios::out);
    fp.open("student",ios::in|ios::out);
    int flag=0;
    while(((char*)&st,sizeof(student))&&flag==0){
        if(strcmpi(st.retsno(),n)!=0){
            fp2.write((char*)&st,sizeof(student));
        }
        if("student.txt"=="b.txt"){
            flag=1;
        }
        fp2.close();
        fp.close();
        remove("student");
        rename("b","student");
        if(flag==1){
            cout<<"record not found"<<endl;
        }
    }
}
void book_issue(){
    char sn[6],bn[6];
    int flag=0,found=0;
    cout<<"IN ORDER TO ISSUE BOOK"<<endl;
    cout<<"enter sno"<<endl;
    cin>>sn;
    fp.open("student",ios::in|ios::out);
    fp1.open("book",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student))&&found==0){
      if(strcmpi(st.retsno(),sn)==0){
        found=1;
        if(st.rettoken()==0){
            cout<<"enter book no"<<endl;
            cin>>bn;
            while(fp1.read((char*)&bk,sizeof(book))&&flag==0){
                if(strcmpi(bk.retbno(),bn)==0){
                    flag=1;
                    bk.show_book();
                    st.resettoken();
                    //st.getstbno(bk.retbno());
                    fp.write((char*)&st,sizeof(student));
                    cout<<"book issued"<<endl;
                }
            }
            if(flag==0){
                cout<<"book does not exist"<<endl;
            }
        }
      }
      if(found==0){
        cout<<"student does not exist"<<endl;
      }
      fp.close();
      fp1.close();
    }}
void deposit_b(){
    char sn[6],bn[6];
    int flag=0,found=0;
    cout<<"IN ORDER TO ISSUE BOOK"<<endl;
    cout<<"enter sno"<<endl;
    cin>>sn;
    fp.open("student",ios::in|ios::out);
    fp1.open("book",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student))&&found==0){
      if(strcmpi(st.retsno(),sn)==0){
        found=1;
        if(st.rettoken()==0){
            cout<<"enter book no"<<endl;
            cin>>bn;
            while(fp1.read((char*)&bk,sizeof(book))&&flag==0){
                if(strcmpi(bk.retbno(),bn)==0){
                    flag=1;
                    bk.show_book();
                    st.resettoken();
                    //st.getstbno(bk.retbno());
                    fp.write((char*)&st,sizeof(student));
                    cout<<"book issued"<<endl;
                }
            }
            if(flag==0){
                cout<<"book does not exist"<<endl;
            }
        }
      }
      if(found==0){
        cout<<"student does not exist"<<endl;
      }
      fp.close();
      fp1.close();
    }
}
 void admin(){
    char cha;
    char* ch;
    char na;
    char* n;
    int flag=0;
    int found=0;
    cout<<"enter name and password";
    cin>>cha;
    cin>>na;
    int a=0;
    ch =&cha;
    n=&na;
    fp.open("c:/documents/admin.txt",ios::in);
    while(fp.read((char*)&ad,sizeof(admin1))){
        if(strcmpi(ad.retadminname(),ch)==0){
            flag=1;
            break;
        }
        if(strcmpi(ad.retadminpassword(),n)==0){
            found==1;
            break;
        }}
        if(flag==0){
            cout<<"incorrect user name"<<endl;
        }
        if(found==0){
            cout<<"password incorrect"<<endl;
    }
    do{
    if(flag==1 && found==1){
        system("cls");
        cout<<"ADMIN MENU"<<endl;
        cout<<"1.create student record"<<endl;
        cout<<"2.display all students records"<<endl;
        cout<<"3.modify student records"<<endl;
        cout<<"4.delete"<<endl;
        cout<<"5.create book"<<endl;
        cout<<"6.display all books"<<endl;
        cout<<"7.display specific book"<<endl;
        cout<<"8.display specific student record"<<endl;
        cout<<"9.modify book"<<endl;
        cout<<"10.delete book"<<endl;
        cout<<"11.back to main menu"<<endl;
        cin>>a;

    }
    switch(a){

        case 1:void write_s();
               break;
        case 2:void display_alls();
               break;
        case 3:void modify_s();
               break;
        case 4:void delete_s();
               break;
        case 5:void write_b();
               break;
        case 6:void display_allb();
               break;
        case 7:{char num[10];
                system("cls");;
                cout<<"enter book no"<<endl;
                cin>>num;
                char* display_b(num);
                break;
        }
        case 8:{char num[10];
                system("cls");;
                cout<<"enter student no"<<endl;
                cin>>num;
                char* display_s(num);
                break;
        }
        case 9:void modify_b();
               break;
        case 10:void delete_b();
               break;
        //case 11: exit();
          //     break;
    }
    }while(a!=11);
 }
int main(){
    int a;
void intro();
 //void admin();
cout<<"WELOCOME TO LIBRARY"<<endl;
    do{
        cout<<"1.issue"<<endl;
        cout<<"2.deposit"<<endl;
        cout<<"3.admin"<<endl;
        cout<<"4.exit"<<endl;
         void admin();
        cin>>a;
        switch(a){
       case 1:system("cls");
             void book_issue();
              break;
        case 2:system("cls");
              void deposit_b();
              break;
        case 3:system("cls");
              void admin();
              break;
        case 4:system("cls");
              exit(0);
              break;
        default:
            cout<<"enter numbers between 1 to 4"<<endl;
        }
    }while(a!='4');
}





