#include<iostream>
#include<string>
#include<map>
#include<iterator>
#include<windows.h>
#include<cstdlib>
using namespace std;

class PhoneNumber
{
    protected:
    int Key;
    map<int,string> Phonenumber;
    map<int,string> TypeNumber;
    public:
    PhoneNumber():Key(0){};
    void SetPhoneNumber()
    {
        while (true)
        {
            // cin.ignore();
            cout<<"Enter Phone number (-1 to exit) : ";
            string input;
            getline(cin,input);
            if(input=="-1")
            {
                break;
            }
            string type;
            cout<<endl<<"Enter Type (for example :mobile,home,Workplace,other) : ";
            getline(cin,type);
            try
            {
                if(input!=""||input!=" ",input!="  "||input!="   "||input!="    "||input!="     ")
                {
                    try
                    {                            
                        if(input.length()==11)
                        {
                            Phonenumber.insert(make_pair(Key,input));
                        }
                        else
                        {
                            throw invalid_argument("Smaller/larger than allowed");
                        }
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                }
                else
                {
                    throw invalid_argument("invalid argument");
                }
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() <<endl;
            }
            try
            {
                if(type!=""||type!=" "||type!="  "||type!="   ")
                {
                    TypeNumber.insert(make_pair(Key,type));
                    Key++;
                }
                else
                {
                    throw invalid_argument("invalid argument");
                }
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
            Sleep(700);
            system("cls");
        }
    }
    virtual void Display() 
    {
        int arr[15];
        string str[15];
        int index=0;
        for(const auto& a :Phonenumber)
        {
            arr[index]=a.first;
            str[index]=a.second;
            index++;
            // output : cout<<a.first+1<<" : "<<a.second<<endl;
        }
        index=0;
        for(const auto& a :TypeNumber)
        {
            str[index]+= "  type : " + a.second;
            index++;
            // cout<<a.first+1<<" : "<<a.second<<endl;
        }
        for(int i=0;i<index;i++)
        {
            cout<<arr[i]<<" : "<<str[i]<<endl;
        }
    }

};
/***********************************New Class*****************************/
class Person : public PhoneNumber
{
    protected:
    string Name;
    public:
    Person(){};
    void SetPerson()
    {
        cout<<"Enter fullname : ";
        string input;
        getline(cin,input);
        Name = input;
        PhoneNumber::SetPhoneNumber();
    }
    string Get(){return Name;}
    void Display()
    {
        cout<<"Name = "<<Name<<endl;
        PhoneNumber::Display();
    }

};
/***********************************New Class*****************************/

/***********************************New Class*****************************/
class Favorite
{
    protected:

    public:

};
/***********************************New Class*****************************/
/***********************************New Class*****************************/
/***********************************New Class*****************************/

int main()
{
    map<string,int> info;
    info["Ali"]=1;
    info["Mohammadreza"]=2;
    info["Amir"]=3;
    if(info.count("Amir"))
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    Person p;

    map<string,int> maps;
    maps.insert(make_pair("ali",1));
    maps.insert(make_pair("amir",2));
    maps.insert(make_pair("sina",3));
    maps.insert(make_pair("ahmad",4));
    for(auto it=maps.begin();it!=maps.end();it++)
    {
        cout<<it->first<<","<<it->second<<endl;
    }
    // map<int,Person> Persons;
    // p.SetPerson();
    // Persons.insert(make_pair(1,p));
    // p.SetPerson();
    // Persons.insert(make_pair(2,p));
    // for(auto it=Persons.begin();it!=Persons.end();it++)
    // {
    //     cout<<"Key value = "<<it->first<<" , ";
    //     it->second.Display();
    // }
    // cout<<endl<<"------------------------------"<<endl;
    // Persons.erase(4);
    // for(auto it=Persons.begin();it!=Persons.end();it++)
    // {
    //     cout<<"Key value = "<<it->first<<" , ";
    //     it->second.Display();
    // }
    cout<<endl<<"------------------------------"<<endl;
    // PhoneNumber PH;
    // PH.SetPhoneNumber();
    // PH.Display();
    Person PP;
    PP.SetPerson();
    PP.Display();
    




    return 0;
}