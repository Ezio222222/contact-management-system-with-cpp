#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
#include <sstream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

struct Contact {
    string name;
    string phone;
    string email;
};
void ClearScreen()
{
    system("cls");
}

string toLowerStr(string s) {
    for (char &c : s) c = tolower(c);
    return s;
}
void Greet()
{
    cout<<"==========Contact Management System by Ezio=========="<<endl;
    cout<<"1. Add contact"<<endl;
    cout<<"2. View all contact"<<endl;
    cout<<"3. Search contact"<<endl;
    cout<<"4. Edit contact"<<endl;
    cout<<"5. Save contact to file"<<endl;
    cout<<"6. Load contact from file"<<endl;
    cout<<"7. Delete contact"<<endl;
    cout<<"8. Exit"<<endl;
    cout<<"===================================================="<<endl;
    cout<<"Enter function number: ";
}

void Loopask()
{
    cout<<"How many contacts do you want to add: ";
}

void PressEnter()
{
    cout<<"==========Press Enter to Go Main Manu==========";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string temp;
    getline(cin, temp); //Waits until user press enter
}
void AddContact(vector<Contact> &contacts,int num)
{   cout<<"=====Adding Contact Function====="<<endl<<endl;
    Contact c;
    for(int i=0;i<num;i++)
    {cout<<"Adding Contact ("<<i+1<<")"<<endl;
     cin.ignore(numeric_limits<streamsize>::max(), '\n');   
    cout<<"Enter name : ";
    getline(cin, c.name);
    bool valid;
    do
    {
        cout<<"Enter phone: ";
        cin>>c.phone;
        valid = true;

        for (char ch : c.phone)
        {
            if (!isdigit(ch))
            {
                valid = false;
                cout << "Invalid phone number! Only digits allowed.\n";
                break;
            }
        }
    } while (!valid);

    cout<<"Enter email: ";
    cin>>c.email;

    contacts.push_back(c);

    cout << "Contact added successfully!\n";
    cout<<"------------------------------------------------"<<endl<<endl;
}
}


void ViewContact(vector<Contact> &contacts)
{   cout<<"=====View all contacts function====="<<endl<<endl;
    for (int i =0; i<contacts.size();i++)
    {   cout<<"Contact ("<<i+1<<")"<<endl;
        cout<<"Name: "<<contacts[i].name<<endl;
        cout<<"Phone: "<<contacts[i].phone<<endl;
        cout<<"Email: "<<contacts[i].email<<endl;
        cout<<"-------------"<<endl;
    }

    if(contacts.size() == 0)
    {
        cout<<"No contacts to display!"<<endl;
    }
}

void SearchContact(vector<Contact> &contacts)
{   bool found = false;
    cout<<"=====Search contact function====="<<endl<<endl;
    int num;
    cout<<"What you want to search?"<<endl;
    cout<<"1. With name"<<endl;
    cout<<"2. With phone"<<endl;
    cout<<"3. With email"<<endl;
    cout<<"=============================="<<endl;
    cout<<"Enter number(1,2,3) : ";
    cin>>num;
    if (num < 1 || num > 3) {
    cout << "Invalid option! Please enter 1, 2, or 3.\n";
    return;
   }
   else{

    string key;
    if(num==1)
    { 
      cout<<"Enter name : ";
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      getline(cin, key);
      key = toLowerStr(key);
      for(int i=0;i<contacts.size();i++)
      { 
        if(toLowerStr(contacts[i].name) == key)
        {
            cout<<"Contact Found Sucessfully!"<<endl;
            cout<<"Name :"<<contacts[i].name<<endl;
            cout<<"Phone :"<<contacts[i].phone<<endl;
            cout<<"Email :"<<contacts[i].email<<endl;
            found = true;
        }  
      }   
    }
    else if(num==2)
    {
        
        cout<<"Enter phone : ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, key);
        
        for(int i=0;i<contacts.size();i++)
      { 
        if(contacts[i].phone == key)
        {
            cout<<"Contact Found Sucessfully!"<<endl;
            cout<<"Name :"<<contacts[i].name<<endl;
            cout<<"Phone :"<<contacts[i].phone<<endl;
            cout<<"Email :"<<contacts[i].email<<endl;
            found = true;
        }  
      }   

    }
    else if(num == 3)
    {  cout<<"Enter Email : ";
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, key);
        key=toLowerStr(key);
       for(int i=0;i<contacts.size();i++)
       {
        if(toLowerStr(contacts[i].email) == key)
        {
            cout<<"Contact Found Sucessfully!"<<endl;
            cout<<"Name :"<<contacts[i].name<<endl;
            cout<<"Phone :"<<contacts[i].phone<<endl;
            cout<<"Email :"<<contacts[i].email<<endl;
            found = true;
        }
       }
    }

    }
    if(!found)
    {
        cout<<"Contact Not Found!"<<endl;
    }
}

void EditContact(vector<Contact> &contacts)
{
    cout<<"=====Edit contact function====="<<endl<<endl;
    int num;
    cout<<"Enter the contact number you want to edit :";
    cin>>num;

    if(num < 1 || num>contacts.size())
    {
        cout<<"Invalid contact number!"<<endl;
        cout<<"Contact number should be between 1 and "<<contacts.size()<<endl;
    }
    else
    {  num=num-1;
       cout<<"Editing Contact ("<<num+1<<")"<<endl;
       cout<<"==============================="<<endl;\
       cout<<"Enter new name : ";
       cin.ignore();
       getline(cin, contacts[num].name);

       bool valid;
       do
       {
         cout<<"Enter new phone : ";
         cin>>contacts[num].phone;
         valid = true;

         for (char ch : contacts[num].phone)
         {
             if (!isdigit(ch))
             {
                 valid = false;
                 cout << "Invalid phone number! Only digits allowed.\n";
                 break;
             }
         }
       } while (!valid);

       cout<<"Enter new Email :";
       cin>>contacts[num].email;
       
       cout<<"Contact updated sucessfully!"<<endl;}
}
void SaveToFile(const vector<Contact> &contacts, const string& filename)
{
    ofstream out(filename);

    if(!out)
    {
        cout<<"Error!!!"<<endl;

    }
    for (const Contact& c : contacts) {
        out << c.name << endl;
        out << c.phone << endl;
        out << c.email << endl;
        out << "-------------" << endl; // separator
    }

    out.close();
    cout << "Contacts saved to file successfully!\n";
}

void ShowFilesInCurrentFolder() {
    cout << "Files in current directory:\n\n";
    
    for (const auto &entry : fs::directory_iterator(".")) {
        if(entry.is_regular_file() && entry.path().extension() == ".txt")
        {cout << entry.path().filename().string() << endl;}
    }
}
 
void LoadFromFile(vector<Contact>& contacts, const string& filename) {
    ifstream in(filename);

    if (!in) {
        cout << "Error opening file!\n";
        return;
    }

    string line;
    while (true)
    {
        Contact c;

        // Read name
        if (!getline(in, c.name)) break;

        // Read phone
        if (!getline(in, c.phone)) break;

        // Read email
        if (!getline(in, c.email)) break;

        // Read separator line (---)
        getline(in, line); 

        contacts.push_back(c);
    }

    cout << "Contacts loaded successfully!\n";
}

void DeleteContact(vector<Contact> &contacts)
{
    cout<<"=====Delete contact function====="<<endl<<endl;
    int num;
    cout<<"Enter the contact number you want to delete :";
    cin>>num;

    if(num < 1 || num>contacts.size())
    {
        cout<<"Invalid contact number!"<<endl;
        cout<<"Contact number should be between 1 and "<<contacts.size()<<endl;
    }
    else{
        contacts.erase(contacts.begin() + num - 1);
        cout<<"Contact deleted sucessfully!"<<endl;
    
    }
}
int main()
{
    vector<Contact> contacts;
    int choice;

    while (true)
    {   ClearScreen();
        Greet();
        cin >> choice;
        
        ClearScreen();     

        switch (choice)    //To check condition of user choice
        {
            case 1:{
                Loopask();
                int num;cin>>num;  
                AddContact(contacts,num);
                ClearScreen();
                break;
            }
            case 2:{  
                ViewContact(contacts);
                PressEnter();
                break;
            }
            case 3:{
                SearchContact(contacts);
                PressEnter();           
                break;
            }
            case 4:{
                EditContact(contacts);
                PressEnter();            
                break;}

            case 5:{
                string filename;
                cout<<"Enter file name :";
                cin>>filename;
                filename = filename.append(".txt");
                SaveToFile(contacts,filename);
                PressEnter();
                break;
            }
            case 6:{
                ShowFilesInCurrentFolder();
                string filename;
                cout<<"Enter file name to Load: ";
                cin>>filename;
                filename = filename.append(".txt");
                cout<<"=========================="<<endl;
                LoadFromFile(contacts,filename);
                PressEnter();
                break;
            }
            case 7:
            {   DeleteContact(contacts);
                PressEnter();
                break;
            }        
                     
            case 8:
                cout << "Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}