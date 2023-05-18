#include<iostream>
#include<string>
#include<map>
#include<iterator>
#include<windows.h>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;

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
                // for(int i=0;i<input.length();i++)
                // {
                //     if(input[i]==32)
                //     {
                //         check=true;
                //     }
                //     else
                //     {
                //         check=false;
                //     }
                // }
                if (check == false)
                {
                    try
                    {
                        if (input.length() < 12 && input.length() > 7)
                        {
                            Phonenumber.insert(make_pair(Key, input));
                        }
                        else
                        {
                            throw invalid_argument("Smaller/larger than allowed");
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
                    throw invalid_argument("invalid argument");
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
                    throw invalid_argument("invalid argument");
                }
            }
            catch (const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }

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
        Sleep(800);
        system("cls");
    }
    void EditPhoneNumber()
    {
        Display();
        SetPhoneNumber();
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
            cout << arr[i] + 1 << " : " << str[i] << endl;
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
            cout << "Name = " << Name << endl;
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
/***********************************New Class*****************************/
/***********************************New Class*****************************/




void Manu()
{
    vector<Person>persons;
    vector<Person>favorites;
    while (true)
    {
        string input;
        cout << "1.Add contact " << endl << "2.Delete a number from the contact " << endl << "3.Add a number to a contact" << endl;
        cout << "4.Delete contact " << endl << "5.Add Favorite" <<endl<<"6.Display all contact "<<endl<<"7.Display all favorites" <<endl<< "8.search contact " <<endl;
        cout << "9.Delete favorite" << endl;
        cin >> input;
        if (input == "1")
        {
            Person P;
            P.SetPerson();
            persons.push_back(P);
        }
        if (input == "3")
        {
            cout << endl << "Enter Name : ";
            cin >> input;
            cout << endl;
            for (auto& a : persons)
            {
                if (a.GetName() == input)
                {
                    a.EditPhoneNumber();
                    break;
                }
            }
        }
        if (input == "4")
        {
            cout << endl << "Enter Name : ";
            cin >> input;
            cout << endl;
            for (auto& a : persons)
            {
                if (a.GetName() == input)
                {
                    a.SoftDelete();
                    break;
                }
            }
        }
        if (input == "5")
        {
            cout << endl << "Enter Name : ";
            cin >> input;
            cout << endl;

            for (auto& a : persons)
            {
                if (input == a.GetName())
                {
                    favorites.push_back(a.GetPErson());
                }
            }
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
            cin >> res;
            cout << endl;
            for (auto& l : vec1)
            {
                l.GetSearch(res);
            }
            system("pause");
            system("cls");
        }
        if (input == "9")
        {
            cout << endl << "Enter Name : ";
            cin >> input;
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

        }



    }



}


int main()
{
    Manu();
    map<string, int> info;
    info["Ali"] = 1;
    info["Mohammadreza"] = 2;
    info["Amir"] = 3;
    if (info.count("Amir"))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    Person p;

    map<string, int> maps;
    maps.insert(make_pair("ali", 1));
    maps.insert(make_pair("amir", 2));
    maps.insert(make_pair("sina", 3));
    maps.insert(make_pair("ahmad", 4));
    for (auto it = maps.begin(); it != maps.end(); it++)
    {
        cout << it->first << "," << it->second << endl;
    }
    cout << endl << "------------------------------" << endl;
    vector<Person>persons;
    for (int i = 0; i < 2; i++)
    {
        Person PP;
        PP.SetPerson();
        persons.push_back(PP);
    }
    for (auto& a : persons)
    {

        if (a.GetName() == "ali")
        {
            a.DeletePhoneNumber();
            break;
        }
    }
    for (auto& a : persons)
    {
        a.Display();
    }



    return 0;
}






























//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//
//
//
//
//class Unit
//{
//protected:
//	vector<long> endtime;
//	vector<long> starttime;
//	vector<long> PublicMission;
//	vector<long >reward;
//	vector <long> missionid;
//public:
//	void SEtUnit(long id, long start, long end, long r)
//	{
//		endtime.push_back(end);
//		starttime.push_back(start);
//		reward.push_back(r);
//		missionid.push_back(id);
//	}
//	bool ISBigerthan(long b, long a)
//	{
//		//return true;
//		 if (a < b)
//		 {
//		 	return true;
//		 }
//		 else
//		 {
//		 	return false;
//		 }
//	}
//	void Display(long time,long idd)
//	{
//		long end[10];
//		long star[10];
//		long rew[10];
//		long missio[10];
//		int k = 0;
//		for (auto& p : endtime)
//		{
//			if (ISBigerthan(time, p) == true)
//			{
//				end[k] = p;
//			}
//			else
//			{
//				end[k] = -1;
//			}
//			k++;
//		}
//		k = 0;
//		for (auto& p : starttime)
//		{
//			star[k] = p;
//			k++;
//		}
//		k = 0;
//		for (auto& p : reward)
//		{
//			rew[k] = p;
//			k++;
//		}
//		k = 0;
//		for (auto& p : missionid)
//		{
//			missio[k] = p;
//			k++;
//		}
//		cout << "completed missions for driver " << idd << ":" << endl;
//		for (int i = 0; i < k; i++)
//		{
//			cout << "mission : " << missio[i] << endl;
//			cout << "start timestamp : " << star[i] << endl;
//			cout << "end timestamp : " << end[i] << endl;
//			cout << "reward : " << rew[i] << endl << endl;
//		}
//
//	}
//	void DisplayStart()
//	{
//		for (auto& p : starttime)
//		{
//			cout <<" p = " << p << endl;
//		}
//		cout << endl << endl;
//	}
//
//};
//
//class Driver :public Unit
//{
//protected:
//	long ID;
//	long time;
//
//public:
//	void SetID(long id)
//	{
//		ID = id;
//	}
//	long GetID()
//	{
//		return ID;
//	}
//	void SETMission(long id, long start, long end, long reward)
//	{
//		Unit::SEtUnit(id, start, end, reward);
//	}
//	void SetBegin(long t)
//	{
//		time = t;
//	}
//	long GetBegin()
//	{
//		return time;
//	}
//	void Display()
//	{
//		//cout << "Driver ID = " << ID << endl;
//		Unit::Display(GetBegin(), ID);
//
//	}
//};
//
//
//class Trip : public Driver
//{
//protected:
//	long StarTrip;
//	long EndTrip;
//	long Reward;
//	long MissionID;
//	long Delete;
//public:
//	Trip() {};
//	void SetTrip(long id, long start, long end, long reward)
//	{
//		SetID(id);
//		StarTrip = start;
//		EndTrip = end;
//		Reward = reward;
//	}
//	void SetDelete()
//	{
//		Delete = false;
//	}
//	void SetMissionID(long missionid)
//	{
//		MissionID = missionid;
//	}
//
//
//};
//
//class Mission : public Unit
//{
//protected:
//	long StartMission;
//	long EndMission;
//	long MissionID;
//	bool Delete;
//	long Reward;
//public:
//	void SetMission(long id, long start, long end, long reward)
//	{
//		if (start > end)
//		{
//			cout << "ARGUMENTS_INVALID" << end;
//			return;
//		}
//		else
//		{
//			Delete = false;
//			MissionID = id;
//			StartMission = start;
//			EndMission = end;
//			Reward = reward;
//		}
//	}
//	long GetStarTrip() { return StartMission; }
//	long GetEndMission() { return EndMission; }
//	long GetMissionID() { return MissionID; }
//	long GetReward() { return Reward; }
//	bool GetDelete() { return Delete; }
//	void SetDelete()
//	{
//		Delete = true;
//	}
//
//
//};
//
//class TimeMission : public Mission
//{
//private:
//	long Time;
//public:
//	void SetTimeMission(long id, long start, long end, long time, long reward)
//	{
//		SetMission(id, start, end, reward);
//		Time = time;
//		Delete = false;
//	}
//
//
//};
//
//class DistanceMission : public Mission
//{
//protected:
//	long Reward;
//
//public:
//	void SetDistanceMission(long id, long start, long end, long distance, long reward)
//	{
//		SetMission(id, start, end, reward);
//		Reward = distance;
//		Delete = false;
//	}
//};
//
//class CountMission :public Mission
//{
//protected:
//	long counter;
//public:
//	void SetCountMission(long id, long start, long end, long count, long reward)
//	{
//		SetMission(id, start, end, reward);
//		counter = count;
//		Delete = false;
//	}
//
//};
//
//
//int main()
//{
//	vector<Mission> M;
//	vector<TimeMission> TimeMissions;
//	vector<DistanceMission> DistanceMissions;
//	vector <CountMission> CountMissions;
//	vector <Driver> Drivers;
//	vector<Trip> Trips;
//	vector<Driver>Driver_Recodes;
//	vector<long>checkMissionid;
//
//
//	string input;
//	string Temp[10];
//	int counter = 0;
//	cout << endl << endl;
//	for (int i = 0; i < 500; i++)
//	{
//		string str = "add_distance_mission 3 1076347116 1580349516 250000 200000";
//		string delimiter = " ";
//		getline(cin, str);
//		size_t pos = 0;
//		string token;
//		/******************************************/
//		while ((pos = str.find(delimiter)) != std::string::npos)
//		{
//			token = str.substr(0, pos);
//			str.erase(0, pos + delimiter.length());
//			Temp[counter] = token;
//			counter++;
//		}
//		Temp[counter] = str;
//		counter = 0;
//		if (Temp[0] == "add_time_mission")
//		{
//			TimeMission T;
//			if (stoi(Temp[2]) < stoi(Temp[3]) && stoi(Temp[5]) > 0 && stoi(Temp[4]) > 0)
//			{
//				bool check = true;
//				for (auto& p : checkMissionid)
//				{
//					if (p == stoi(Temp[1]))
//					{
//						check = false;
//					}
//				}
//				if (check == true)
//				{
//					checkMissionid.push_back(stoi(Temp[1]));
//					T.SetTimeMission(stoi(Temp[1]), stoi(Temp[2]), stoi(Temp[3]), stoi(Temp[4]), stoi(Temp[5]));
//					TimeMissions.push_back(T);
//					cout << "Ok" << endl;
//				}
//				else
//				{
//					cout << "DUPLICATE_MISSION_ID" << endl;
//				}
//			}
//			else
//			{
//				cout << "INVALID_ARGUMENTS" << endl;
//			}
//		}
//		if (Temp[0] == "add_distance_mission")
//		{
//			DistanceMission D;
//			if (stoi(Temp[2]) < stoi(Temp[3]) && stoi(Temp[5]) > 0 && stoi(Temp[4]) > 0)
//			{
//				bool check = true;
//				for (auto& p : checkMissionid)
//				{
//					if (p == stoi(Temp[1]))
//					{
//						check = false;
//					}
//				}
//				if (check == true)
//				{
//					checkMissionid.push_back(stoi(Temp[1]));
//					D.SetDistanceMission(stoi(Temp[1]), stoi(Temp[2]), stoi(Temp[3]), stoi(Temp[4]), stoi(Temp[5]));
//					DistanceMissions.push_back(D);
//					cout << "Ok" << endl;
//				}
//				else
//				{
//					cout << "DUPLICATE_MISSION_ID" << endl;
//				}
//			}
//			else
//			{
//				cout << "INVALID_ARGUMENTS" << endl;
//			}
//
//		}
//		if (Temp[0] == "add_count_mission")
//		{
//			CountMission C;
//			if (stoi(Temp[2]) < stoi(Temp[3]) && stoi(Temp[5]) > 0 && stoi(Temp[4]) > 0)
//			{
//				bool check = true;
//				for (auto& p : checkMissionid)
//				{
//					if (p == stoi(Temp[1]))
//					{
//						check = false;
//					}
//				}
//				if (check == true)
//				{
//					checkMissionid.push_back(stoi(Temp[1]));
//					C.SetCountMission(stoi(Temp[1]), stoi(Temp[2]), stoi(Temp[3]), stoi(Temp[4]), stoi(Temp[5]));
//					CountMissions.push_back(C);
//					cout << "Ok" << endl;
//				}
//				else
//				{
//					cout << "DUPLICATE_MISSION_ID" << endl;
//				}
//			}
//			else
//			{
//				cout << "INVALID_ARGUMENTS" << endl;
//			}
//
//		}
//		if (Temp[0] == "assign_mission")
//		{
//			bool check = false;
//			Driver D;
//			/*cout << endl<<"Temp [2] = "<<Temp[2] << endl;*/
//			int x = stoi(Temp[2]);
//			D.SetID(x);
//			for (auto& i : TimeMissions)
//			{
//				if (stoi(Temp[1]) == i.GetMissionID())
//				{
//					bool check1 = false;
//					for (auto& p : TimeMissions)
//					{
//						if (p.GetDelete() == true)
//						{
//							check1 = true;
//						}
//					}
//					if (check1 == false)
//					{
//						i.SetMission(i.GetMissionID(), i.GetStarTrip(), i.GetEndMission(), i.GetReward());
//						D.SETMission(i.GetMissionID(), i.GetStarTrip(), i.GetEndMission(), i.GetReward());
//						Drivers.push_back(D);
//						cout << "Ok" << endl;
//						check = true;
//						i.SetDelete();
//						break;
//					}
//					else
//					{
//						cout << "DUPLICATE_DRIVER_MISSION" << endl;
//					}
//				}
//			}
//			/************************/
//			for (auto& i : CountMissions)
//			{
//				if (stoi(Temp[1]) == i.GetMissionID())
//				{
//					i.SetMission(i.GetMissionID(), i.GetStarTrip(), i.GetEndMission(), i.GetReward());
//					D.SETMission(i.GetMissionID(), i.GetStarTrip(), i.GetEndMission(), i.GetReward());
//					Drivers.push_back(D);
//					check = true;
//					cout << "Ok" << endl;
//
//					break;
//				}
//			}
//			/***********************/
//			for (auto& i : DistanceMissions)
//			{
//				if (stoi(Temp[1]) == i.GetMissionID())
//				{
//					i.SetMission(i.GetMissionID(), i.GetStarTrip(), i.GetEndMission(), i.GetReward());
//					D.SETMission(i.GetMissionID(), i.GetStarTrip(), i.GetEndMission(), i.GetReward());
//					check = true;
//					Drivers.push_back(D);
//					cout << "Ok" << endl;
//
//					break;
//				}
//			}
//			/***********************/
//			if (check == false)
//			{
//				cout << "MISSION_NOT_FOUND" << endl;
//			}
//		}
//		if (Temp[0] == "record_ride")
//		{
//			Trip T;
//			if (stoi(Temp[2]) > stoi(Temp[1]))
//			{
//				//T.SETMission(stoi(Temp[1]), stoi(Temp[2]), stoi(Temp[3]), stoi(Temp[4]));
//				T.SetBegin(stoi(Temp[2]));
//				for (auto& p : Drivers)
//				{
//					p.Display();
//				}
//			}
//			else
//			{
//				cout << "INVALID_ARGUMENTS" << endl;
//			}
//		}
//		if (Temp[0] == "show_missions_status")
//		{
//			for (auto& p : Drivers)
//			{
//				if (p.GetID() == stoi(Temp[1]))
//				{
//					p.Display();
//				}
//			}
//		}
//		if (Temp[0] == "DisplayStart")
//		{
//			for (auto& p : Drivers)
//			{
//				p.DisplayStart();
//			}
//		}
//		if (Temp[0] == "Exit")
//		{
//			return 0;
//		}
//
//	}
//
//
//
//
//
//
//	return -1;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////#include<iostream>
////#include<string>
////#include<map>
////#include<iterator>
////using namespace std;
////
/////***********************************New Class*****************************/
////class Person
////{
////protected:
////    string Name;
////public:
////    Person() {};
////    void SetPerson()
////    {
////        cout << "Enter fullname : ";
////        string input;
////        getline(cin, input);
////        Name = input;
////    }
////    string Get() { return Name; }
////    void Display()
////    {
////        cout << "Name = " << Name << endl;
////    }
////
////};
/////***********************************New Class*****************************/
////class PhoneNumber
////{
////protected:
////
////public:
////
////};
/////***********************************New Class*****************************/
////class Favorite
////{
////protected:
////
////public:
////
////};
/////***********************************New Class*****************************/
/////***********************************New Class*****************************/
/////***********************************New Class*****************************/
////
////int main()
////{
////    map<string, int> info;
////    info["Ali"] = 1;
////    info["Mohammadreza"] = 2;
////    info["Amir"] = 3;
////    if (info.count("Amir"))
////    {
////        cout << "Yes" << endl;
////    }
////    else
////    {
////        cout << "No" << endl;
////    }
////    Person p;
////
////    map<string, int> maps;
////    maps.insert(make_pair("ali", 1));
////    maps.insert(make_pair("amir", 2));
////    maps.insert(make_pair("sina", 3));
////    maps.insert(make_pair("ahmad", 4));
////    for (auto it = maps.begin(); it != maps.end(); it++)
////    {
////        cout << it->first << "," << it->second << endl;
////    }
////    map<int, Person> Persons;
////    p.SetPerson();
////    Persons.insert(make_pair(1, p));
////    p.SetPerson();
////    Persons.insert(make_pair(2, p));
////    // p.SetPerson();
////    // Persons.insert(make_pair(3,p));
////    // p.SetPerson();
////    // Persons.insert(make_pair(4,p));
////    // p.SetPerson();
////    for (auto it = Persons.begin(); it != Persons.end(); it++)
////    {
////        cout << "Key value = " << it->first << ",";
////        it->second.Display();
////    }
////    cout << endl << "------------------------------" << endl;
////    // Persons.erase(p,2);
////    // int value;
////    // string key;
////    
////
////
////
////
////    return 0;
////}