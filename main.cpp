#include <bits/stdc++.h>
using namespace std;


char phone_number[15];
int counter=0;

class general_data
{
protected:
    char name[30];
    char address[30];
    char phone[15];

public:
   virtual void showData()=0;

    char* get_phonenumber()
    {
        return phone;
    }


};

class client:public general_data
{
protected:
    char admin_name[30],admin_pass[30];
    char package[10];
    char bill_satuts[10];
public:
    void getData(void)
    {
        cout<<"ENTER YOUR NAME: "<<endl;
        cin>>name;
        cout<<"ENTER ADDRESS: "<<endl;
        cin>>address;
        cout<<"ENTER PHONE NUMBER: "<<endl;
        cin>>phone;
        cout<<"ENTER ADMIN NAME: "<<endl;
        cin>>admin_name;
        cout<<"ENTER ADMIN PASSWORD: "<<endl;
        cin>>admin_pass;
        cout<<"ENTER PACKAGE NUMBER:"<<endl;
        cin>>package;
        cout<<"ENTER BILL STATUS(PAID/NOTPAID) :"<<endl;
        cin>>bill_satuts;
    }

    void delete_data();

    void update_data();

    void add_data();

    void show_Billstatus();

    void showData();

    void search_client();

};
 client s;

void client::add_data()
{
    ofstream file;
    file.open("client.txt",ios::app);
    if(!file)
    {
        cout<<"Error in creating file.."<<endl;

    }
    cout<<"\nFile created successfully."<<endl;
    getData();
    file.write((char*)this,sizeof(*this));

    file.close();
}

void client::delete_data()
{
    cout <<"Enter the Phone Number of the Client to Delete: ";
    cin >> phone_number;

    ifstream file1;
    ofstream fout;

    file1.open("client.txt",ios::in|ios::binary);
    fout.open("tempfile.txt",ios::out|ios::binary);
    file1.read((char*)this,sizeof(*this));

    while (!file1.eof())
    {
        if (strcmp(phone,phone_number) )
        {
            fout.write((char*)this,sizeof(*this));

        }
        file1.read((char*)this,sizeof(*this));

    }
    file1.close();
    fout.close();
    remove("client.txt");
    rename("tempfile.txt","client.txt");

}

void client::update_data()
{
    cout <<"Enter the Phone Number of the Client to Update: ";
    cin >> phone_number;

    counter=0;

    ifstream file1;
    ofstream fout;

    file1.open("client.txt",ios::in|ios::binary);
    fout.open("tempfile.txt",ios::out|ios::binary);
    file1.read((char*)this,sizeof(*this));

    while (!file1.eof())
    {
        if (!strcmp(phone,phone_number) )
        {
            getData();
            fout.write((char*)this,sizeof(*this));
            file1.read((char*)this,sizeof(*this));
            counter++;
            continue;

        }
        fout.write((char*)this,sizeof(*this));
        file1.read((char*)this,sizeof(*this));

    }
    if(counter==0)
        {
            cout<<"RECORD NOT FOUND!"<<endl;

        }
    file1.close();
    fout.close();
    remove("client.txt");
    rename("tempfile.txt","client.txt");
}
  void client::show_Billstatus()
  {
      cout<<"NAME :"<<name<<"\t\t\t"<<"BILLING STATUS:"<<bill_satuts<<endl;
  }

  void client::showData()
  {
     cout<<"Name:"<<name<<endl;
     cout<<"Address:"<<address<<endl;
     cout<<"PHONE NUMBER:"<<phone<<endl;
     cout<<"ADMIN NAME: "<<admin_name<<endl;
     cout<<"ADMIN PASSWORD: "<<admin_pass<<endl;
     cout<<"PACKAGE NUMBER:"<<package<<endl;
     cout<<"BILL STATUS(PAID/NOTPAID) :"<<bill_satuts<<endl;

  }

void client::search_client()
{
    cout <<"\n Enter the Phone Number of the Client: ";
    cin >> phone_number;

    ifstream file1;
    counter=0;

    file1.open("client.txt",ios::in|ios::binary);

    file1.read((char*)&s,sizeof(s));
    while (!file1.eof())
    {
        if (!strcmp(s.get_phonenumber(),phone_number) )
        {
            s.showData();
            file1.close();
            counter++;
            break;
        }
        else
        {
            file1.read((char*)&s,sizeof(s));
        }

    }
    if(counter==0)
    {
        cout<<"RECORD NOT FOUND!"<<endl;
    }
    file1.close();
}


class employee:public general_data
{
protected:
    char birth_date[15];
    char salary[10] ;
    char salary_status[10];
    char designation[20];
public:
    void getData(void)
    {
        cout<<"ENTER EMPLOYEE NAME: "<<endl;
        cin>>name;
        cout<<"ENTER ADDRESS: "<<endl;
        cin>>address;
        cout<<"ENTER PHONE NUMBER: "<<endl;
        cin>>phone;
        cout<<"ENTER BIRTHDATE:"<<endl;
        cin>>birth_date;
        cout<<"ENTER DESIGNATION:"<<endl;
        cin>>designation;
        cout<<"ENTER SALARY:"<<endl;
        cin>>salary;
        cout<<"ENTER SALARY STATUS(PAID/UNPAID):"<<endl;
        cin>>salary_status;

    }

    void add_data();
    void delete_data();

    void update_data();
    void showsalary_status()
    {
        cout<<"NAME: "<<name<<"\t\t\t"<<"SALARY STATUS: "<<salary_status<<endl;
    }

    void showData();

    void search_employee();


};

employee e;

void employee::add_data()
{
    ofstream file;
    file.open("employee.txt",ios::app);
    if(!file)
    {
        cout<<"Error in creating file.."<<endl;

    }
    cout<<"\nFile created successfully."<<endl;
    getData();
    file.write((char*)this,sizeof(*this));

    file.close();
}


void employee::delete_data()
{
    cout <<"Enter the Phone Number of the Employee to Delete: ";
    cin >> phone_number;

    ifstream file1;
    ofstream fout;

    file1.open("employee.txt",ios::in|ios::binary);
    fout.open("tempfile.txt",ios::out|ios::binary);
    file1.read((char*)this,sizeof(*this));

    while (!file1.eof())
    {
        if (strcmp(phone,phone_number) )
        {
            fout.write((char*)this,sizeof(*this));

        }
        file1.read((char*)this,sizeof(*this));

    }
    file1.close();
    fout.close();
    remove("employee.txt");
    rename("tempfile.txt","employee.txt");

}

void employee::update_data()
{
    cout <<"Enter the Phone Number of the Employee to Update: ";
    cin >> phone_number;

    counter=0;

    ifstream file1;
    ofstream fout;

    file1.open("employee.txt",ios::in|ios::binary);
    fout.open("tempfile.txt",ios::out|ios::binary);
    file1.read((char*)this,sizeof(*this));

    while (!file1.eof())
    {
        if (!strcmp(phone,phone_number) )
        {
            getData();
            fout.write((char*)this,sizeof(*this));
            file1.read((char*)this,sizeof(*this));
            counter++;
            continue;

        }
        fout.write((char*)this,sizeof(*this));
        file1.read((char*)this,sizeof(*this));
    }
    if(counter==0)
        {
            cout<<"RECORD NOT FOUND!"<<endl;

        }
    file1.close();
    fout.close();
    remove("employee.txt");
    rename("tempfile.txt","employee.txt");
}

void employee::showData()
{
     cout<<"Name:"<<name<<endl;
     cout<<"Address:"<<address<<endl;
     cout<<"PHONE NUMBER:"<<phone<<endl;
     cout<<"BIRTH DATE: "<<birth_date<<endl;
     cout<<"DESIGNATION: "<<designation<<endl;
     cout<<"SALARY: "<<salary<<endl;
     cout<<"SALARY STATUS:"<<salary_status<<endl;

}

void employee::search_employee()
{
    cout <<"\n Enter the Phone Number of the Employee: ";
    cin >> phone_number;

    ifstream file1;

    file1.open("employee.txt",ios::in|ios::binary);

    file1.read((char*)&e,sizeof(e));
    while (!file1.eof())
    {
        if (!strcmp(e.get_phonenumber(),phone_number) )
        {
            showData();
            file1.close();
            counter++;
            break;
        }
        else
        {
            file1.read((char*)&e,sizeof(e));
        }

    }
    if(counter==0)
    {
        cout<<"RECORD NOT FOUND!"<<endl;
    }
}



bool Islogging()
{
    string username,password,un,pw;

    cout << "\t\t\t-----------------------------------------------------------"<<"\n";
    cout<<"\t\t\t\tADMIN LOGIN PANNEL"<<"\n";
    cout<<"\t\t\t-----------------------------------------------------------";
    cout<<"\n\n\t\t\t\tENTER YOUR LOGIN USERNAME: ";
    cin>>username;
    cout<<"\n\t\t\t\tENTER YOUR PASSWORD: ";
    cin>>password;

    ifstream read;
    read.open("password.txt");

    getline(read,un);
    getline(read,pw);

    if(username==un && password==pw)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template<class T>
class password
{
private:
    T user_name[2];
public:
    password(T a,T b)
    {


    }
    password()
    {

    }
    set_password()
    {

        cout<<"\n\n\n\n\t\t\t\t\tENTER NEW USER NAME:";
        cin>>user_name[0];
        cout<<"\n\t\t\t\t\tENTER NEW PASSWORD:";
        cin>>user_name[1];

        ofstream write;
        write.open("password.txt");

        write<<user_name[0]<<endl;
        write<<user_name[1];

        write.close();


    }

    get_password()
    {
        ifstream read;
        read.open("password.txt");

        getline(read,user_name[0]);

        getline(read,user_name[1]);

        read.close();
    }
    enter_password_forcheck()
    {

        cout<<"\n\n\n\n\t\t\t\t\tENTER OLD USER NAME:";
        cin>>user_name[0];
        cout<<"\n\t\t\t\t\tENTER OLD PASSWORD:";
        cin>>user_name[1];

    }

    int operator==(password temp)
    {
        if((user_name[0]==temp.user_name[0]) && (user_name[1]==temp.user_name[1]))
        {
            return 1;
        }
        else
            return 0;
    }


};





password <string>p1("TREX","TREX");





int main()
{

    char another;
    int choice,status;
    int quit=1;



    while(1)
    {

        system("cls");

        cout << "\t\t\t-----------------------------------------------------------"<<"\n";
        cout<<"\t\t\t\tSELECT ANY OPTION FROM THE BELOW"<<"\n";
        cout<<"\t\t\t-----------------------------------------------------------";
        cout<<"\n\n\n\t\t\t 1.ADMIN PANNEL";
        cout<<"\n\t\t\t 2.EMPLOYEE PANNEL";
        cout<<"\n\t\t\t 3.Customer PANNEL";
        cout<<"\n\t\t\t 4.QUIT";
        cout << "\n\n";
        cout << "\t\t\t Select Your Option :=> ";



        cin>>choice;
        switch(choice)
        {

        case 1:
        {
            system("cls");
            status=Islogging();
            if(status==1)
            {

                while(quit)
                {
                    system("cls");

                    cout << "\t\t\t-----------------------------------------------------------"<<"\n";
                    cout<<"\t\t\t\tWELCOME INTERNET SERVICE PROVIDER MANAGEMENT SYSTEM "<<"\n";
                    cout<<"\t\t\t-----------------------------------------------------------";
                    cout <<"\n\n";
                    cout << "\n\n";
                    cout << "\n \t\t\t 1.  Add    Records Clients";
                    cout << "\n \t\t\t 2.  Add    Records Employees";
                    cout << "\n \t\t\t 3.  List   Records Clients";
                    cout << "\n \t\t\t 4.  List   Records Employee";
                    cout << "\n \t\t\t 5.  Modify Records Client";
                    cout << "\n \t\t\t 6.  Modify Records Employee";
                    cout << "\n \t\t\t 7.  Search Records Client";
                    cout << "\n \t\t\t 8.  Search Records Employee";
                    cout << "\n \t\t\t 9.  Delete Records Client";
                    cout << "\n \t\t\t 10. Delete Records Employee";
                    cout << "\n \t\t\t 11. Change Admin password";
                    cout << "\n \t\t\t 12. Exit To main ";
                    cout << "\n\n";
                    cout << "\t\t\t Select Your Choice :=> ";


                    cin>>choice;
                    switch(choice)
                    {
                    case 1 :
                    {
                        another ='Y';
                        while(another == 'Y' || another == 'y')
                        {
                            system("cls");

                            s.add_data();


                            cout<<"\nFile saved and closed succesfully."<<endl;
                            cout << "\n Add Another Record (Y/N) ";
                            fflush(stdin);
                            cin>>another;

                        }


                        break;
                    }

                    case 2 :
                    {

                        another ='Y';
                        while(another == 'Y' || another == 'y')
                        {
                            system("cls");

                            e.add_data();
                            cout<<"\nFile saved and closed succesfully."<<endl;
                            cout << "\n Add Another Record (Y/N) ";
                            cin>>another;

                        }
                        break;
                    }


                    case 3:
                    {

                        system("cls");
                        cout<<"--------------------------------------------------------\n";
                        cout << "\t|View All the Employees Records in the Database|";
                        cout<<"\n--------------------------------------------------------\n";
                        cout << "\n";

                        ifstream file1;
                        file1.open("client.txt",ios::in);
                        try
                            {
                               if(!file1)  throw 1;
                            }
                            catch(int a)
                            {
                                cout<<"NO DATA IN THE FILE!"<<endl;
                                break;
                            }
                        file1.read((char*)&s,sizeof(s));

                        while(!file1.eof())
                        {

                            s.showData();
                            cout<<"\n"<<"------------------------------------------\n";
                            file1.read((char*)&s,sizeof(s));
                        }

                        file1.close();

                        cout << "\n\n";
                        system("pause");
                    }
                    break;


                    case 4:
                    {

                        system("cls");
                        cout<<"--------------------------------------------------------\n";
                        cout << "\t|View All the Employees Records in the Database|";
                        cout<<"\n--------------------------------------------------------\n";
                        cout << "\n";

                        ifstream file1;
                        file1.open("employee.txt",ios::in);
                        try
                            {
                               if(!file1)  throw 1;
                            }
                            catch(int a)
                            {
                                cout<<"NO DATA IN THE FILE!"<<endl;
                                break;
                            }
                        file1.read((char*)&e,sizeof(e));

                        while(!file1.eof())
                        {

                            e.showData();
                            cout<<"\n"<<"------------------------------------------\n";
                            file1.read((char*)&e,sizeof(e));
                        }

                        file1.close();

                        cout << "\n\n";
                        system("pause");
                    }
                    break;

                    case 5 :
                    {
                        system("cls");
                        another = 'Y';
                        while (another == 'Y'|| another == 'y')
                        {

                            s.update_data();
                            cout << "\n Modify Another Record (Y/N) ";
                            fflush(stdin);
                            another = getchar();
                        }

                        system("pause");

                    }
                    break;


                    case 6 :
                    {

                        system("cls");
                        another = 'Y';
                        while (another == 'Y'|| another == 'y')
                        {

                            e.update_data();
                            cout << "\n Modify Another Record (Y/N) ";
                            fflush(stdin);
                            another = getchar();
                        }
                        system("pause");

                    }
                    break;


                    case 7 :
                    {
                        system("cls");
                        another = 'Y';
                        while (another == 'Y'|| another == 'y')
                        {
                            s.search_client();
                            cout << "\n Search Another Record (Y/N) ";
                            fflush(stdin);
                            another = getchar();
                        }
                        break;
                    }

                    case 8 :
                    {
                        system("cls");
                        another = 'Y';
                        while (another == 'Y'|| another == 'y')
                        {
                            e.search_employee();

                            cout << "\n Search Another Record (Y/N) ";
                            fflush(stdin);
                            another = getchar();
                        }
                        break;
                    }
                    case 9:
                    {
                        system("cls");
                        another = 'Y';
                        while (another == 'Y'|| another == 'y')
                        {
                            s.delete_data();
                            cout<<"DONE!"<<endl;
                            cout << "\n Delete Another Record (Y/N) ";
                            fflush(stdin);
                            another = getchar();
                        }
                        break;
                    }

                    case 10:
                    {
                        system("cls");
                        another = 'Y';
                        while (another == 'Y'|| another == 'y')
                        {
                            e.delete_data();
                            cout<<"DONE!"<<endl;
                            cout << "\n Delete Another Record (Y/N) ";
                            fflush(stdin);
                            another = getchar();
                        }
                        break;
                    }

                    case 11:
                        {
                            system("cls");

                            password <string>p2,p3;
                            int check;
                            p2.enter_password_forcheck();
                            p3.get_password();
                            check=p2==p3;



                            if(check==1)
                            {
                                p1.set_password();
                            }
                            else cout<<"\n\t\t\tPASSWORD NOT MATCHED WITH THE OLD ONE!"<<endl;

                            system("pause");

                        }
                        break;

                    case 12:

                    {
                        cout << "\n\n";
                        cout << "\t\t     COPYRIGHT ISP 2019";
                        cout << "\n\n";
                        quit=0;
                        break;

                    }
                    /*go:
                        {
                          break;
                        }*/
                        break;


                    }




                }
            }
            else
                cout<<"YOU HAVE ENTERDED WRONG PASSWORD!"<<endl;

            system("pause");

        }
        quit=1;
        break;
        case 2:
        {
            system("cls");

            while(quit)
            {
                system("cls");

                cout << "\t\t\t-----------------------------------------------------------"<<"\n";
                cout<<"\t\t\t\tWELCOME ISP EMPLOYEE PANNEL "<<"\n";
                cout<<"\t\t\t-----------------------------------------------------------";
                cout <<"\n\n";
                cout << "\n\n";
                cout << "\n \t\t\t 1.  List   Records Employee";
                cout << "\n \t\t\t 2.  Search Records Employee";
                cout << "\n \t\t\t 3.  View Salary Status";
                cout << "\n \t\t\t 4.  Exit To main ";
                cout << "\n\n";
                cout << "\t\t\t Select Your Choice :=> ";


                cin>>choice;
                switch(choice)
                {

                 case 1:
                   {

                            system("cls");
                            cout<<"--------------------------------------------------------\n";
                            cout << "\t|View All the Records in the Database|";
                            cout<<"\n--------------------------------------------------------\n";
                            cout << "\n";

                            ifstream file1;
                            file1.open("employee.txt",ios::in);

                            try
                            {
                               if(!file1)  throw 1;
                            }
                            catch(int a)
                            {
                                cout<<"NO DATA IN THE FILE!"<<endl;
                                break;
                            }

                            file1.read((char*)&e,sizeof(e));

                            while(!file1.eof())
                            {

                                e.showData();
                                cout<<"\n"<<"---------------------------------------------"<<endl;
                                file1.read((char*)&e,sizeof(e));
                            }

                            file1.close();

                            cout << "\n\n";
                            break;
                  }


                case 2:

                  {
                        system("cls");
                        another = 'Y';
                        while (another == 'Y'|| another == 'y')
                        {
                            cout <<"\n Enter the Phone Number of the Client: ";
                            cin >> phone_number;

                            ifstream file1;

                            file1.open("employee.txt",ios::in|ios::binary);

                            file1.read((char*)&e,sizeof(e));
                            while (!file1.eof())
                            {
                                if (!strcmp(e.get_phonenumber(),phone_number) )
                                {
                                    e.showData();
                                    file1.close();
                                    counter++;
                                    break;
                                }
                                else
                                {
                                    file1.read((char*)&e,sizeof(e));
                                }

                            }
                            if(counter==0)
                            {
                                cout<<"RECORD NOT FOUND!"<<endl;
                            }
                            cout << "\n Search Another Record (Y/N) ";
                            fflush(stdin);
                            another = getchar();
                        }
                        break;
                    }


                case 3:
                {
                    system("cls");
                    another = 'Y';
                    while (another == 'Y'|| another == 'y')
                    {
                        cout <<"\n Enter the Phone Number of the Employee: ";
                        cin >> phone_number;

                        ifstream file1;

                        file1.open("employee.txt",ios::in);

                        file1.read((char*)&e,sizeof(e));
                        while (!file1.eof())
                        {
                            //file1.read((char*)&e,sizeof(e));
                            if (!strcmp(e.get_phonenumber(),phone_number) )
                            {
                                e.showsalary_status();
                                file1.close();
                                counter++;
                                break;
                            }
                            else
                                file1.read((char*)&e,sizeof(e));

                        }
                        if(counter==0)
                        {
                            cout<<"RECORD NOT FOUND!"<<endl;
                        }
                        file1.close();
                        cout << "\n Search Another Record (Y/N) ";
                         fflush(stdin);
                         another = getchar();
                    }
                  }

                break;

                case 4:

                    {
                        cout << "\n\n";
                        cout << "\t\t    COPYRIGHT ISP 2019";
                        cout << "\n\n";
                        quit=0;
                        break;

                    }


                }
              system("pause");
            }
        }
        quit=1;
        break;


   case 3:
      {
            system("cls");

            while(quit)
            {
                system("cls");

                cout << "\t\t\t-----------------------------------------------------------"<<"\n";
                cout<<"\t\t\t\tWELCOME ISP CLIENT PANNEL "<<"\n";
                cout<<"\t\t\t-----------------------------------------------------------";
                cout <<"\n\n";
                cout << "\n\n";
                cout << "\n \t\t\t 1.  List   Records Client";
                cout << "\n \t\t\t 2.  Search Records Client";
                cout << "\n \t\t\t 3.  View Billing Status";
                cout << "\n \t\t\t 4.  Exit To main ";
                cout << "\n\n";
                cout << "\t\t\t Select Your Choice :=> ";
                fflush(stdin);

                cin>>choice;
                switch(choice)
                {

                 case 1:
                   {

                            system("cls");
                            cout<<"--------------------------------------------------------\n";
                            cout << "\t|View All the Clients Records in the Database|";
                            cout<<"\n--------------------------------------------------------\n";
                            cout << "\n";

                            ifstream file1;
                            file1.open("client.txt",ios::in);
                            try
                            {
                               if(!file1)  throw 1;
                            }
                            catch(int a)
                            {
                                cout<<"NO DATA IN THE FILE!"<<endl;
                                break;
                            }

                            file1.read((char*)&s,sizeof(s));

                            while(!file1.eof())
                            {

                                s.showData();
                                cout<<"\n"<<"---------------------------------------------"<<endl;
                                file1.read((char*)&s,sizeof(s));
                            }

                            file1.close();

                            cout << "\n\n";
                            break;
                  }


                case 2:

                  {
                        system("cls");
                        another = 'Y';
                        while (another == 'Y'|| another == 'y')
                        {
                            cout <<"\n Enter the Phone Number of the Client: ";
                            cin >> phone_number;

                            ifstream file1;

                            file1.open("client.txt",ios::in|ios::binary);

                            file1.read((char*)&s,sizeof(s));
                            while (!file1.eof())
                            {
                                if (!strcmp(s.get_phonenumber(),phone_number) )
                                {
                                    s.showData();
                                    file1.close();
                                    counter++;
                                    break;
                                }
                                else
                                {
                                    file1.read((char*)&s,sizeof(s));
                                }

                            }
                            if(counter==0)
                            {
                                cout<<"RECORD NOT FOUND!"<<endl;
                            }
                            cout << "\n Search Another Record (Y/N) ";
                            fflush(stdin);
                            another = getchar();
                        }
                        break;
                    }


                case 3:
                {
                    system("cls");
                    another = 'Y';
                    while (another == 'Y'|| another == 'y')
                    {
                        cout <<"\n Enter the Phone Number of the Client: ";
                        cin >> phone_number;

                        ifstream file1;

                        file1.open("client.txt",ios::in);

                        file1.read((char*)&s,sizeof(s));
                        while (!file1.eof())
                        {
                            //file1.read((char*)&s,sizeof(s));
                            if (!strcmp(s.get_phonenumber(),phone_number) )
                            {
                                s.show_Billstatus();
                                file1.close();
                                counter++;
                                break;
                            }
                            else
                                file1.read((char*)&s,sizeof(s));

                        }
                        if(counter==0)
                        {
                            cout<<"RECORD NOT FOUND!"<<endl;
                        }
                        file1.close();
                        cout << "\n Search Another Record (Y/N) ";
                        fflush(stdin);
                        another = getchar();
                    }
                  }

                break;

                case 4:

                    {
                        cout << "\n\n";
                        cout << "\t\t     Copyright ISP 2019";
                        cout << "\n\n";
                        quit=0;
                        break;

                    }


                }
                 system("pause");

            }
        }
        quit=1;
        break;

    case 4:
    {

    cout << "\n\n";
    cout << "\t\t     Copyright ISP 2019";
    cout << "\n\n";
    exit(0);
    }

       }
    }

}



