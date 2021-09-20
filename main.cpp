#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

class check_in_out{
private:
    static int g_floor[9],f_floor[9],s_floor[9];
    int floor_choice,room_choice;
public:
    check_in_out(){};
    void displayrooms();
    void check_in_choices();
    void check_out_choices();
    void store_status();
    void read_status();
    void check_in();
    void check_out();
    void room_availabilty();
};

int check_in_out::g_floor[9]={0};
int check_in_out::f_floor[9]={0};
int check_in_out::s_floor[9]={0};

class customer
{
    string name, ic, c_contact;

    public:
        customer(string name, string ic,string c_contact):name(name),ic(ic),c_contact(c_contact){
                ofstream custinfo;
                custinfo.open("customer.txt",ios::app);
                if(custinfo.fail())
                {
                cout << "Fail";
                exit(1);
                }
                custinfo<<name<<" "<<ic <<" "<<c_contact<<endl;
                cout << "\n";
                system ("PAUSE");
                }
};

class functions{
private:
    string ic, name, c_contact;
public:
    functions(){};
    void getcustinfo();
    void search_cust_rc();
    void edit_cust_rc();
    void del_cust_rc();
    void view_cust_rc();
};


void check_in_out::displayrooms(){
    cout << "\n";
    cout<<"S floor ";
    for(int i=0;i<10;i++){
        if(s_floor[i]==0){
        cout<<i<<"(A)"<<"\t";
        }else{
        cout<<i<<"(F)"<<"\t";
        }

    }
    cout<<endl;
    cout<<"F floor ";
    for(int i=0;i<10;i++){
        if(f_floor[i]==0){
        cout<<i<<"(A)"<<"\t";
        }else{
        cout<<i<<"(F)"<<"\t";
        }
    }
    cout<<endl;
    cout<<"G floor ";
    for(int i=0;i<10;i++){
        if(g_floor[i]==0){
        cout<<i<<"(A)"<<"\t";
        }else{
        cout<<i<<"(F)"<<"\t";
        }
    }
    cout<<endl;
}

void check_in_out::check_in_choices(){
    cout << "\n";
    cout << "Please enter floor that you want to check in for customer:" << endl;
    cout << "Ground floor[0], 1 st floor[1], 2 nd floor [2]."<<endl;
    cin>> floor_choice;
    if (floor_choice==0){

        cout<<"\nPlease enter the room that you want to check in for customer:"<<endl;
        cout<<"The room range is between 0 to 9."<<endl;
        cin>>room_choice;
            if(g_floor[room_choice]==0){
                cout<<"\nThe room is successfully checked in."<<endl;
                g_floor[room_choice]=1;
            }else{
                cout<<"\nThe room is not available. Please select another."<<endl;
            }

    }else if (floor_choice==1){

        cout<<"\nPlease enter the room that you want to check in for customer:"<<endl;
        cout<<"The room range is between 0 to 9."<<endl;
        cin>>room_choice;
            if(f_floor[room_choice]==0){
                cout<<"\nThe room is successfully checked in"<<endl;
                f_floor[room_choice]=1;
            }else{
                cout<<"\nThe room is not available. Please select another."<<endl;
            }
    }else if (floor_choice==2){

        cout<<"\nPlease enter the room that you want to check in for customer:"<<endl;
        cout<<"The room range is between 0 to 9."<<endl;
        cin>>room_choice;
            if(s_floor[room_choice]==0){
                cout<<"\nThe room is successfully checked in."<<endl;
                s_floor[room_choice]=1;
            }else{
                cout<<"\nThe room is not available. Please select another."<<endl;
            }
    }else{
        cout<<"\nPlease enter a valid input."<<endl;
    }
}

void check_in_out::check_out_choices(){
    cout << "\n";
    cout << "Please enter floor that you want to check out for customer:" << endl;
    cout << "Ground floor[0], 1 st floor[1], 2 nd floor [2]."<<endl;
    cin>> floor_choice;
    if (floor_choice==0){

        cout<<"\nPlease enter the room that you want to check out for customer:"<<endl;
        cout<<"The room range is between 0 to 9."<<endl;
        cin>>room_choice;
            if(g_floor[room_choice]==1){
                cout<<"\nThe room has been checked out."<<endl;
                g_floor[room_choice]=0;
            }else{
                cout<<"\nThe room is not available to do check out."<<endl;
            }

    }else if (floor_choice==1){

        cout<<"\nPlease enter the room that you want to check out for customer:"<<endl;
        cout<<"The room range is between 0 to 9."<<endl;
        cin>>room_choice;
            if(f_floor[room_choice]==1){
                cout<<"\nThe room has been checked out."<<endl;
                f_floor[room_choice]=0;
            }else{
                cout<<"\nThe room is not available to check out."<<endl;
            }
    }else if (floor_choice==2){

        cout<<"\nPlease enter the room that you want to check out for customer:"<<endl;
        cout<<"The room range is between 0 to 9."<<endl;
        cin>>room_choice;
            if(s_floor[room_choice]==1){
                cout<<"\nThe room has been checked out."<<endl;
                s_floor[room_choice]=0;
            }else{
                cout<<"\nThe room is not available to check out."<<endl;
            }
    }else{
        cout<<"\nPlease enter a valid input."<<endl;
    }
}

void check_in_out::store_status(){
    ofstream file;
    file.open("status.txt");
    for(int i=0;i<10;i++){
            file<<s_floor[i]<<"\t";

        }

    file<<endl;
    for(int i=0;i<10;i++){

            file<<f_floor[i]<<"\t";

        }

    file<<endl;
    for(int i=0;i<10;i++){

            file<<g_floor[i]<<"\t";

    }
    file<<endl;
}

void check_in_out::read_status(){

    ifstream file;
    file.open("status.txt");
    for(int i=0;i<=9;i++){
        file>>s_floor[i];
    }
    for(int i=0;i<=9;i++){
        file>>f_floor[i];
    }
    for(int i=0;i<=9;i++){
        file>>g_floor[i];
    }
}

void check_in_out::check_in(){
    read_status();
    displayrooms();
    check_in_choices();
    store_status();
    cout << "\n";
    system ("PAUSE");
}

void check_in_out::check_out(){
    read_status();
    displayrooms();
    check_out_choices();
    store_status();
    cout << "\n";
    system ("PAUSE");
}

void check_in_out::room_availabilty(){
    cout << "The rooms' status currently: " <<endl;
    read_status();
    displayrooms();
    cout << "\n";
    system ("PAUSE");
}

void functions::getcustinfo(){
    cout << "\n";
    cout<<"Enter customer's name,ic and contact number accordingly:"<<endl;
    cin>>name>>ic>>c_contact;
    customer one(name,ic,c_contact);
}

void functions::search_cust_rc(){
    int signal=0;
    ifstream customer;
    customer.open("customer.txt");
    cout << "\n";
    cout<<"Enter the name of customer that you want to search: "<<endl;
    cin >> name;
    if (customer.is_open())
        {
            while (!customer.eof())
                {
                    string temp;
                    customer >> temp;
                    if (temp == name)
                    {
                    customer >> ic >> c_contact;
                    cout << "Customer " << name << " found. IC and Contact number of " << name << " is " << ic << " and " << c_contact << "." << endl;
                    signal++;
                    }
                }
                if (signal==0){
                    cout<<"There is no relevant record."<<endl;
                }
            customer.close();
        }
    cout << "\n";
    system ("PAUSE");
}

void functions::edit_cust_rc(){
    string line;
    cout << "\n";
    cout << "Please enter the name of customer that you want to edit his or her record: ";
    cin >> name;
    ifstream custinfo;
    custinfo.open("customer.txt");
    ofstream temp;
    temp.open("temp.txt");
    while(getline(custinfo,line))
    {
        if (line.substr(0, name.size()) != name)
            temp << line << endl;
    }
    custinfo.close();
    temp.close();
    remove("customer.txt");
    rename("temp.txt", "customer.txt");
    cout << "Re-enter customer's name,ic and contact number accordingly:" << endl;
    cin >> name >> ic >> c_contact;
    ofstream customer;
                customer.open("customer.txt",ios::app);
                if(customer.fail())
                {
                cout << "Fail";
                exit(1);
                }
                customer<<name<<" "<<ic <<" "<<c_contact<<endl;
    cout << "\n";
    system ("PAUSE");
}

void functions::del_cust_rc(){
    string line;
    int signal = 0;
    bool found = false;
    ifstream customer;
    customer.open("customer.txt");
    cout << "\n";
    cout << "Please enter a customer name record that you want to delete: ";
    cin >> name;
    if (customer.is_open())
        {
            while (!customer.eof())
                {
                    string temp;
                    customer >> temp;
                    if (temp == name)
                    {
                    found = true;
                    cout << "Customer " << name << " found." << endl;
                    signal++;
                    }
                }
                if (signal == 0){
                    cout << "There is no relevant record." << endl;
                }
            customer.close();
        }
        if (found == true)
        {
            ifstream custinfo;
            custinfo.open("customer.txt");
            ofstream temp;
            temp.open("temp.txt");
            while(getline(custinfo,line))
            {
                if (line.substr(0, name.size()) != name)
                    temp << line << endl;
            }
            cout << "The record with the name " << name << " has been deleted." << endl;
            custinfo.close();
            temp.close();
            remove("customer.txt");
            rename("temp.txt", "customer.txt");
            cout << "\n";
        }else
            {
              cout << "The record with the name " << name << " does not exist." << endl;
            }
    system ("PAUSE");
}

void functions::view_cust_rc(){
    int signal=0;
    ifstream custinfo;
    custinfo.open("customer.txt");
    if(custinfo.is_open())
    {
        cout << "\n";
        cout << "The current customer records are: " <<endl;
        while(custinfo >> name >> ic >> c_contact)
        {
            cout << "Name\t\t:" << name << "\n" << "IC\t\t:" << ic << "\n" << "Contact number  :" << c_contact << "\n";
            cout << "--------------------------------------\n" ;
            signal ++;
        }
           if (signal==0)
                    {
                    cout << "None customer record exist." << "\n";
                    cout << "\n";
                    }
        custinfo.close();
    }
    system ("PAUSE");
}

int main();
int main_menu(int choice_new)
{
    functions nine;
    check_in_out two;
    switch(choice_new)
    {
        case 1: {nine.getcustinfo();main();break;}
        case 2: {nine.edit_cust_rc();main();break;}
        case 3: {nine.del_cust_rc();main();break;}
        case 4: {nine.view_cust_rc();main();break;}
        case 5: {nine.search_cust_rc();main();break;}
        case 6: {two.check_in();main();break;}
        case 7: {two.check_out();main();break;}
        case 8: {two.room_availabilty();main();break;}
        case 9: {break;}
        default:{
                cout<<"Please enter a valid choice.It is either (1/2/3/4/5/6/7/8/9)"<<endl;
                system ("PAUSE");
                main();
                }
    }
}

int main()
{
    int choice_new;
    system ("CLS");
    cout << "****************************************************"<<endl;
    cout << "****************************************************"<<endl;
    cout << "~~~~~_____~~~~~______~~~~~___~~~~__~~~~~_______~~~~~"<<endl;
    cout << "~~~___~~~~~~~~~~~__~~~~~~~____~~~__~~~~~_______~~~~~"<<endl;
    cout << "~~___~~~~~~~~~~~~__~~~~~~~__~__~~__~~~~~~~___~~~~~~~"<<endl;
    cout << "~~~___~~~~~~~~~~~__~~~~~~~__~~__~__~~~~~~~___~~~~~~~"<<endl;
    cout << "~~~~~_____~~~~~______~~~~~__~~~~___~~~~~~~___~~~~~~~"<<endl;
    cout << "****************************************************"<<endl;
    cout << "****************************************************"<<endl;
    cout << "CINT Hotel Management Program is ready to serve." << endl;
    cout << "\nHow can I help you?" << endl;
    cout << "1.Add a customer record." << endl;   //add();
    cout << "2.Edit a customer record." << endl;
    cout << "3.Delete a customer record." << endl;
    cout << "4.View customer record" << endl;
    cout << "5.Search a customer record" << endl;
    cout << "6.Check in"<<endl;
    cout << "7.Check out."<<endl;
    cout << "8.Check rooms availability."<<endl;
    cout << "9.Exit this program.\n"<<endl;
    cout << "Please enter your choice: ";
    cin >> choice_new;

    if(choice_new<10&&choice_new>0){
            main_menu(choice_new);

    }else{
        cout<<"Invalid input. Please enter either (1/2/3/4/5/6/7/8/9):"<<endl;
        cin.clear();
        cin.ignore();
        system("PAUSE");
        main();
    }
    return 0;
}



