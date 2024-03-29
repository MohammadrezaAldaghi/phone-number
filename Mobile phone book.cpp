#include<iostream>
#include<string>
#include<map>
#include<iterator>
#include<windows.h>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;


template<typename T> 
class Buffer
{
    protected:
        int Size;
        T* Array;
        int Capacity;
        int write_index;
        int read_index;
    public:
    Buffer(int s):Capacity(s),write_index(0),read_index(0) ,Size(s)
    {
        Array = new T[s];
    }
    void SetBuffer(T value)
    {
        Array[write_index]=value;
        write_index = (write_index+1)%Capacity;
        if(write_index==read_index)
        {
            read_index=(read_index+1)%Size;
        }
    }
    void DISPLAY()
    {
        for(int i=0;i<Capacity;i++)
        {
            cout<<Array[i]<<" ";
        }
        cout<<endl;
    }
        
};
/****************************new class***************/
class PhoneNumber
{
protected:
    int Key;
    map<int, string> Phonenumber;
    map<int, string> TypeNumber;
public:
    PhoneNumber() :Key(0) {};
    void SetPhoneNumber()
    {
        while (true)
        {
            // cin.ignore();
            cout << "Enter Phone number (-1 to exit) : ";
            string input;
            cin >> input;
            if (input == "-1")
            {
                break;
            }
            string type;
            cout << endl << "Enter Type (for example :mobile,home,Workplace,other) : ";
            bool check = false;
            cin >> type;
            try
            {
                if (check == false)
                {
                    try
                    {
                        if (input.length() < 13 && input.length() > 7)
                        {
                            Phonenumber.insert(make_pair(Key, input));
                        }
                        else
                        {
                            throw invalid_argument("Smaller/larger than allowed❌");
                            check = true;
                        }
                    }
                    catch (const std::exception& e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                }
                else
                {
                    throw invalid_argument("invalid argument❌");
                }
            }
            catch (const std::exception& e)
            {
                std::cerr << e.what() << endl;
            }
            try
            {
                if (type.length() != 0 && check == false)
                {
                    TypeNumber.insert(make_pair(Key, type));
                    Key++;
                }
                else
                {
                    throw invalid_argument("invalid argument❌");
                }
            }
            catch (const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            cout<<endl<<"Add ✅ "<<endl;
            Sleep(700);
            system("cls");
        }
    }
    void DeletePhoneNumber()
    {
        system("cls");
        Display();
        cout << "Enter number to delete : ";
        int input = 0;
        cin >> input;
        Phonenumber.erase(input - 1);
        TypeNumber.erase(input - 1);
        cout<<endl<<"Delete ✅"<<endl;
        Sleep(800);
        system("cls");
    }
    void EditPhoneNumber_ADD()
    {
        Display();
        SetPhoneNumber();
    }
    void DeletePhoneNumber_DELETE()
    {
        DeletePhoneNumber();
    }
    virtual void Display()
    {
        int arr[15];
        string str[15];
        int index = 0;
        for (const auto& a : Phonenumber)
        {
            arr[index] = a.first;
            str[index] = a.second;
            index++;
            // output : cout<<a.first+1<<" : "<<a.second<<endl;
        }
        index = 0;
        for (const auto& a : TypeNumber)
        {
            str[index] += "  type : " + a.second;
            index++;
            // cout<<a.first+1<<" : "<<a.second<<endl;
        }
        for (int i = 0; i < index; i++)
        {
            // if(stoi(str[i])>1)
            // {
            cout << arr[i] + 1 << " : " << str[i] << " 📱📱📱"<<endl;
            // }
        }
    }

};
/***********************************New Class*****************************/
class Person : public PhoneNumber
{
protected:
    string Name;
    bool Delete;
public:
    Person() {};
    void SetPerson()
    {
        cin.get();
        Delete = false;
        cout << "Enter fullname : ";
        string input;
        getline(cin, input);
        Name = input;
        PhoneNumber::SetPhoneNumber();
    }
    string Get() { return Name; }
    void Display()
    {
        if (!GetSoftDelete())
        {
            cout << "Name (📞)= " << Name << endl;
            PhoneNumber::Display();
        }
        // else
        // {
        //     cout<<"There is no such audience"<<endl;
        // }
    }
    string GetName()
    {
        return Name;
    }
    void SoftDelete()
    {
        Delete = true;
        cout<<"Delete ✅"<<endl;
    }
    bool GetSoftDelete()
    {
        return Delete;
    }
    ~Person()
    {
        // cout<<"default destructor "<<endl;
    }
    Person GetPErson()
    {
        return *this;
    }
    void GetSearch(string search)
    {
        if (Name.find(search) != -1)
        {
            cout << Name << endl;
        }
    }


};
/***********************************New Class*****************************/

/***********************************New Class*****************************/
class Favorite : public Person
{
protected:
    bool DeleteFavorite;
    map<string, Person> Favorites;
public:
    void SetFavorite(Person& p)
    {
        Favorites.insert(make_pair(p.GetName(), p));
        DeleteFavorite = false;
        cout << "Added the object has type qualifiers that are not compatible with the member function" << endl;
    }
    void Display()
    {
        for (auto& p : Favorites)
        {
            if(DeleteFavorite==false)
            {
                cout << p.first << " , " << p.second.GetName() << endl;
            }
        }
    }

};
/***********************************New Class*****************************/

void SORT(string *str,vector<Person>& P)
{
    int k = 0;
    int size = str->length();
    k = str->length() - 1;
    sort(str,str+str->length()-1);
    cout <<endl<< "------------------------------------------" << endl;
    while (k>=0)
    {
        for (auto& a : P)
        {
            if (a.GetName() == str[k])
            {
                cout << "☏ ";
                a.Display();
                break;
            }
        }
        k--;
    }

    cout << endl<<"------------------------------------------" << endl;
}
void Test(vector<Person>& P)
{
    P[0].Display();
}



void Manu()
{
    vector<Person>persons;
    vector<Person>favorites;
    while (true)
    {
        string input;
        cout << "1.Add contact " << endl << "2.Delete a number from the contact " << endl << "3.Add a number to a contact" << endl;
        cout << "4.Delete contact " << endl << "5.Add Favorite" <<endl<<"6.Display all contact "<<endl<<"7.Display all favorites" <<endl<< "8.search contact " <<endl;
        cout << "9.Delete favorite" << endl << "10.Dipslay (sort by name)" << endl << "11.Display a specific audience " << endl<<"12.Exit"<<endl<<"Enter Number >> ";
        cin >> input;
        if (input == "1")
        {
            Person P;
            P.SetPerson();
            persons.push_back(P);
        }
        if (input == "2")
        {
            cin.ignore();
            cout << endl << "Enter Name : ";
            getline(cin,input);
            cout << endl;
            for (auto& a : persons)
            {
                if (a.GetName() == input)
                {
                    a.DeletePhoneNumber_DELETE();
                    break;
                }
            }
            cin.clear();
            system("pause");
            system("cls");
        }
        if (input == "3")
        {
            cout << endl << "Enter Name : ";
            cin.ignore();

            getline(cin,input);
            cout << endl;
            for (auto& a : persons)
            {
                if (a.GetName() == input)
                {
                    a.EditPhoneNumber_ADD();
                    break;
                }
            }
            cin.clear();
        }
        if (input == "4")
        {
            cout << endl << "Enter Name : ";
            cin.ignore();
            getline(cin,input);
            cout << endl;
            for (auto& a : persons)
            {
                if (a.GetName() == input)
                {
                    a.SoftDelete();
                    break;
                }
            }
            cin.clear();
        }
        if (input == "5")
        {
            cout << endl << "Enter Name : ";
            cin.ignore();

            getline(cin,input);
            cout << endl;

            for (auto& a : persons)
            {
                if (input == a.GetName())
                {
                    favorites.push_back(a.GetPErson());
                }
            }
            cin.clear();

        }
        if (input == "6")
        {
            for (auto& f : persons)
            {
                f.Display();
            }
        }
        if (input == "7")
        {
            for (auto& a : favorites)
            {
                a.Display();
            }
        }
        if (input == "8")
        {
            string res;
            vector<Person>vec1 = persons;
            cout << endl << "Enter Name : ";
            cin.ignore();

            getline(cin,res);
            cout << endl;
            for (auto& l : vec1)
            {
                l.GetSearch(res);
            }
            system("pause");
            cin.clear();
            system("cls");

        }
        if (input == "9")
        {
            cout << endl << "Enter Name : ";
            cin.ignore();

            getline(cin,input);
            cout << endl;
            Person k;
            for (auto& a : favorites)
            {
                if (a.GetName() == input)
                {
                    a.SoftDelete();///////////////////////////////////////////
                    break;
                }
            }
            cin.clear();


        }
        if (input == "10")
        {
            string str[20];
            int k = 0;
            for (auto& a : persons)
            {
                str[k] = a.GetName();
                k++;
            }
            SORT(str,persons);
        }
        if (input == "11")
        {
            cout << "Enter name : ";
            cin.ignore();

            getline(cin,input);
            for (auto& a : persons)
            {
                if (a.GetName() == input)
                {
                    a.Display();
                    break;
                }
            }
        }
        if (input == "12")
        {
            cout << endl << "See you latter" << endl;
            exit(1);
        }



    }



}


int main()
{
    Manu();
    // Buffer<int> B(3);
    // for(int i=0;i<15;i++)
    // {
    //     B.SetBuffer(i);
    // }
    // B.DISPLAY();


    // map<string, int> info;
    // info["Ali"] = 1;
    // info["Mohammadreza"] = 2;
    // info["Amir"] = 3;
    // if (info.count("Amir"))
    // {
    //     cout << "Yes" << endl;
    // }
    // else
    // {
    //     cout << "No" << endl;
    // }
    // Person p;

    // map<string, int> maps;
    // maps.insert(make_pair("ali", 1));
    // maps.insert(make_pair("amir", 2));
    // maps.insert(make_pair("sina", 3));
    // maps.insert(make_pair("ahmad", 4));
    // for (auto it = maps.begin(); it != maps.end(); it++)
    // {
    //     cout << it->first << "," << it->second << endl;
    // }
    // cout << endl << "------------------------------" << endl;
    // vector<Person>persons;
    // for (int i = 0; i < 2; i++)
    // {
    //     Person PP;
    //     PP.SetPerson();
    //     persons.push_back(PP);
    // }
    // for (auto& a : persons)
    // {

    //     if (a.GetName() == "ali")
    //     {
    //         a.DeletePhoneNumber();
    //         break;
    //     }
    // }
    // for (auto& a : persons)
    // {
    //     a.Display();
    // }



    return 0;
}



