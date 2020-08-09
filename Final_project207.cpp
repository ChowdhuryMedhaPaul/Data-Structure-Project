#include<bits/stdc++.h>
using namespace std;
struct node_voter
{
    int national;
    string name,f_name,m_name,birth_date;
    struct node_voter *next;
}*head;
int serial=1000,pass=123000,pass_che=0,de=0;
int cnt=0,cnt1=0,cnt2=0,cnt3=0,cnt4=0,id_che=0;
void main_menu();
void insert_another();
void voting();
void admin();
void admin_win();
void winner();
void display();
void search_info(int id);
void delete_voter(int ID);
void main_menu();

/// **********Insert New Voter***********
void insert_voter()
{
    node_voter* temp,*tail;
    int national;
     string name,f_name,m_name,birth_date;
    cout<<"\t enter your name\t: ";
  cin.ignore();
  getline(cin,name);
    cout<<"\t enter your  father's name\t: ";
  cin.ignore();
  getline(cin,f_name);
    cout<<"\t enter your mother's name\t: ";
  cin.ignore();
  getline(cin,m_name);
    cout<<"\t enter your national \t: ";
    cin>>national;
    cout<<"\t enter your Birthday's Date\t: ";
  cin.ignore();
  getline(cin,birth_date);
    temp=(struct node_voter*)malloc(sizeof(struct node_voter));
      temp->name=name;
    temp->f_name=f_name;
    temp->m_name=m_name;
    temp->birth_date=birth_date;
    temp->national=national;
    temp->next=NULL;
    tail=head;
    while(tail->next != NULL)
        tail = tail->next;
    tail->next=temp;
}


///***********Inserted Voter List**********
void insert_voter_info(string name, string f_name,string m_name,string birth_date,int national)
{
    struct node_voter *temp,*tail;
    temp=(struct node_voter*)malloc(sizeof(struct node_voter));
     temp->name=name;
    temp->f_name=f_name;
    temp->m_name=m_name;
    temp->birth_date=birth_date;
    temp->national=national;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }

}

///********Display all voter info**********
void display()
{
    struct node_voter *temp;
    temp=head;
    while(temp!=NULL)
    {
        cout<<"MY Name\t:"<<temp->name<<"\nMY Father's Name\t:"<<temp->f_name<<"\nMY Mother's Name:"<<temp->m_name<<"\nBrithDate\t:"<<temp->birth_date<<"\nMY National ID Card\t:"<<temp->national<<"\n"<<endl;
        temp=temp->next;
    }
    cout<<"\n\t\tDo you want to search data by NID number\n\n";
    cout<<"\t\tpress 1 for Yes or press 2 for see winner\n\n";
    int pr;
    cin>>pr;
    if(pr==1)
    {
        int id;
        cout<<"\t\tEnter your NID Card number\t:";
        cin>>id;
        search_info(id);
    }
    else winner();

}

///*********Search voter*********
void search_info(int id)
{
    struct node_voter *temp;
    temp=head;
    int  che=0,i;
    while(temp!=NULL)
    {
        if(temp->national==id)
        {
            cout<<"\n\n\t\tFound Voter information\n"<<endl;
            cout<<"MY Name\t:"<<temp->name<<"\nMY Father's Name\t:"<<temp->f_name<<"\nMY Mother's Name\t:"<<temp->m_name<<"\nBrithDate\t:"<<temp->birth_date<<"\nMY National ID Card\t:"<<temp->national<<"\n"<<endl;
            che++;
            pass_che++;
            temp->national=0;

            break;
        }
        temp=temp->next;
    }
    if(che==0)
    {
        cout<<"\n\n\t\tNot Found\n\n\tPress 1 for Again enter your NID\n\n";
        cout<<"\t\tpress 2 to see winner\n\n";
        int pres;
        cin>>pres;
        if(pres==1)
        {
            cout<<"\n\n\t\tEnter your NID again:\t";
            cin>>i;
            search_info(i);
        }
   else if(pres==2)

           winner();

    }

    cout<<"\t\tVoter Serial Number is: "<<serial+1<<endl;
    if(pass_che%2==0)
        cout<<"\t\tVoter Password is: "<<pass+155<<endl;
    else
        cout<<"\t\tVoter Password is: "<<pass-99<<endl;
    cout<<"\n\n\t\tTime for vote.......\n\n"<<endl;
    admin();

}
///********Deleted Voter********
void delete_voter(int n)
{
   int i;
    struct node_voter *temp1,*temp2;
temp1=head;
if(n==10000010)
{
    head=temp1->next;
    free(temp1);
    de++;
}
else{
   for(int i=10000010;i<n-2;i++)
        temp1=temp1->next;

        temp2=temp1->next;
        temp1->next=temp2->next;
        free(temp2);
       de++;
}
        cout<<"\t\tCurrent voter information deleted............\n\n";
             cout<<"\t\tpress 1 for search data \n\n";
       cout<<"\t\tpress 2 winner ............\n\n";
int pr;
cin>>pr;
if(pr==1){
   cout<<"\t\tEnter your ID for new voter info:\t";
   int id;
   cin>>id;
   search_info(id);
}
else if(pr==2) winner();
}
///*****Serial & Password*******
void admin()
{
    int p;
    cout<<"\t\t Enter voter password\t:";
    cin>>p;
    if(p==pass+155)
    {
        cout<<"\n\t\tTime for Vote\n\n";
        serial++;
        pass+=155;
        voting();
    }
    else if(p==pass-99)
    {
        cout<<"\n\t\tTime for Vote\n\n";
        serial++;
        pass-=99;
        voting();
    }
    else
    {
        cout<<"\t\tWrong password.......\n\n";
        admin();
    }
}
///********Count Vote********
void voting()
{
    system("color 4F");

    int press;
    cout<<"\t\tList of Candidate...........\n";
    cout<<"\tname\t\t\t\tTeam Name\t\t\t\symbol\n\n";
    cout<<"\tpress 1. Sheikh Hasina\t\tAwami League\t\tNouka\n";
    cout<<"\tpress 2. Khalada Zia\t\tBNP\t\tDhan\n";
    cout<<"\tpress 3. Hussain Muhammad Ershad\t\t\tJatiya Party\t\tLangol\n";
    cout<<"\tpress 4. Other Team\t\t****\t\tXXXX\n";
    cin>>press;
    if(press==1)
        cnt1++;
    if(press==2)
        cnt2++;
    if(press==3)
        cnt3++;
        if(press==4)
        cnt4++;

    if(press!=1&&press!=2&&press!=3&&press!=4)
    {
        cout<<".....In valid vote.....\n";
        main_menu();
    }
    cout<<"\t\tpress 1 for Another voter information from the list\n\n";
    cout<<"\t\tpress 2 to new voter enter\n\n";
    cout<<"\t\tpress 3 for see display list\n\n";
    cout<<"\t\tpress 4 for deleted voter information\n\n";
    cout<<"\t\tpress 5 for winner\n\n";
    cin>>press;
    if(press==1)
    {
        int id;
        cout<<"\t\tEnter your NID Card number\t:";
        cin>>id;
        search_info(id);

    }
    else if(press==2)
    {
        cout<<"\n\t\t new voter inserted: \n\n";
        insert_voter();
        cout<<"\n\n\t\tEnter your NID Card number\t:";
        int id;
        cin>>id;
        search_info(id);
    }
    else if(press==3)
        display();
         else if(press==4){
           cout<<"\n\tEnter NID to deleted:\t";
           int i;
           cin>>i;
        delete_voter(i);
         }
    else
        admin_win();

}
///********Admin password********
void admin_win()
{
    system("color 9F");
    cout<<"\t\t Enter the admin password to see winner\n\n";
    int pass,che=0;
    cin>>pass;
    if(pass==12345)
        winner();
    else
    {
        che++;
        if(che==3)
        {
            cout<<"\t Wrong password 3 times program exit\n\n";
            exit(0);
        }
        else
        {
            cout<<"\t\tWrong Password........\n\tRe-Enter\n";
            admin_win();
        }

    }
}
///********TO see Winner*******
void winner()
{
    system("color 6F");
    if(cnt1>cnt2&&cnt1>cnt3&&cnt1>cnt4)
    {
        cout<<"The  Sheikh Hasina total vote is: "<<cnt1<<endl;
        cout<<"The Khaleda Zia total vote is : "<<cnt2<<endl;
        cout<<"The  Hussain Muhammad Ershad total vote is: "<<cnt3<<endl;
        cout<<"The  Others total vote is: "<<cnt4<<endl;
        cout<<"\nThe president Sheikh Hasina  is win by: "<<cnt1<<"\tvote"<<endl;
    }
    else if(cnt2>cnt1&&cnt2>cnt3&&cnt2>cnt4)
    {
         cout<<"The  Sheikh Hasina total vote is: "<<cnt1<<endl;
        cout<<"The Khaleda Zia total vote is : "<<cnt2<<endl;
        cout<<"The  Hussain Muhammad Ershad total vote is: "<<cnt3<<endl;
        cout<<"The  Others total vote is: "<<cnt4<<endl;
        cout<<"\nThe president Khaleda Zia  is win by: "<<cnt2<<"\tvote"<<endl;
    }
    else if(cnt3>cnt1&&cnt3>cnt2&&cnt3>cnt4)
    {
       cout<<"The  Sheikh Hasina total vote is: "<<cnt1<<endl;
        cout<<"The Khaleda Zia total vote is : "<<cnt2<<endl;
        cout<<"The  Hussain Muhammad Ershad total vote is: "<<cnt3<<endl;
        cout<<"The  Others total vote is: "<<cnt4<<endl;
        cout<<"\nThe president Hussain Muhammad Ershad is win by: "<<cnt3<<"\tvote"<<endl;
    }
       else if(cnt3>cnt1&&cnt3>cnt2)
    {
       cout<<"The  Sheikh Hasina total vote is: "<<cnt1<<endl;
        cout<<"The Khaleda Zia total vote is : "<<cnt2<<endl;
        cout<<"The  Hussain Muhammad Ershad total vote is: "<<cnt3<<endl;
        cout<<"The  Others total vote is: "<<cnt4<<endl;
        cout<<"\nThe president Others is win by: "<<cnt4<<"\tvote"<<endl;
    }
    else if(cnt2==cnt1||cnt2==cnt3||cnt2==cnt4)
    {
       cout<<"The  Sheikh Hasina total vote is: "<<cnt1<<endl;
        cout<<"The Khaleda Zia total vote is : "<<cnt2<<endl;
        cout<<"The  Hussain Muhammad Ershad total vote is: "<<cnt3<<endl;
        cout<<"The  Others total vote is: "<<cnt4<<endl;
        cout<<"\n Everyone gets the same vote\n\n"<<endl;

    }
    cout<<"\n\n\t\tDo you want to see list and vote again\n\n";
    cout<<"\t\t YES to press 1 or press 2 for exit\n\n";
    int p;
    cin>>p;
    if(p==1)
        display();
    else
        exit(0);

}
///**********Main Menu***********
void main_menu()

{
    system("color 3F");
    cout<<"\t\t press 1 for voter information\t\t\n\n";
   cout<<"\t\t press 2 exit for \t\t\n\n";
    int press;
    cin>>press;
    if(press==1)
    {
        struct node_voter *head=NULL;
        insert_voter_info("Medha Paul","Madhusudan Paul","Mukti Paul","02-09-1997",10000010);
        insert_voter_info("Avia Anwar","Mr. Anwar","Mrs. Anwar","01-01-1997",10000011);
        insert_voter_info("Rajvir Paul","Sumon Paul","Brinda Paul","10-11-1995",10000012);
        insert_voter_info("Sayonto Paul","Sudip Paul","Shormi Paul","24-11-1993",10000013);
        insert_voter_info("Abu Bakar Shiddique","Mr. Bakar Shiddique","Mrs. Bakar Shiddique","21-11-1993",10000014);
        display();
    }
    else
        exit(0);
}
///********Main Function***********
int main()
{

    cout<<"\t**** WELCOME TO OUR PROJECT****\n\n"<<endl;

    cout<<"\tpress 1 for main menu\t\n\n"<<endl;
    int press;
    cin>>press;
    if(press==1)
        main_menu();
    else
    {
        cout<<"\texit the program\n"<<endl;
        return 0;
    }
    return 0;
}

