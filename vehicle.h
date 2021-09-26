#include<bits/stdc++.h>
using namespace std;

map<string,vector<int>> slotAgeWise;
map<string,vector<string>> agewithRegNo;
map<string,int> regNoWithSlot;
map<string,string> userDetailMap;
vector<string> notReserved;
int notReservedIndex = 0;
int slot = 0;

//vehicle class for age and reg no
//mapping to various fileds done here
class Vehicle
{
    private:
    string vehicle_reg_no;
    string driver_age;
    // vector<int> v;

    public:
    Vehicle(){}
    Vehicle(string reg_no, string age)//,int slot)
    {
        vehicle_reg_no = reg_no;
        driver_age = age;
        userDetailMap.insert(pair<string,string>(vehicle_reg_no,driver_age));
        if(notReserved.size() != 0)
        {
            slot = stoi(notReserved[notReservedIndex]);
            notReservedIndex++;
        }
        else
        {
            slot++;
        }
        regNoWithSlot[vehicle_reg_no] = slot;
        slotAgeWise[driver_age].push_back(slot);
        agewithRegNo[driver_age].push_back(vehicle_reg_no);
    }

    string get_reg_no();
    string get_age(string regNo);
    void getDetail();
    string displayParkSlot(string regNo);
    vector<int> displaySlotAgeWise(string age);
    int slotWithCarNo(string no);
    string Leave(string slotNo);
    void vacate(string slott);
    vector<string> ageWiseRegNo(string age);
    
};

//get vehicle reg no
string Vehicle :: get_reg_no()
{
    return vehicle_reg_no;
}

//get age mapped to particular regNO
string Vehicle :: get_age(string regNo)
{
    map<string, string>::iterator itr;
    for (itr = userDetailMap.begin(); itr != userDetailMap.end(); ++itr) 
    {
        if(itr->first == regNo)
        return itr->second;
    }
    return " ";
}

// void Vehicle :: getDetail()
// {
//     map<string, string>::iterator itr;
//     for (itr = userDetailMap.begin(); itr != userDetailMap.end(); ++itr) {
//         cout << "\t HERE" << itr->first << '\t' << itr->second << '\n';
//     }
// }


//allocating and dispalying slots to vehicle reg no
string Vehicle :: displayParkSlot(string regNo)
{
    map<string, string>::iterator itr;
    string s;
    for (itr = userDetailMap.begin(); itr != userDetailMap.end(); ++itr) 
    {
        if(itr->first == regNo)
        s = "Car with vehicle registration number \"" + itr->first + "\" has been parked at slot number " + to_string(regNoWithSlot[vehicle_reg_no]) + "\n";
    }
    return s;
    
}

//giving all values of slots corresponding to particular age
vector<int> Vehicle :: displaySlotAgeWise(string age)
{
    map<string, vector<int>>::iterator itr;
    for (itr = slotAgeWise.begin(); itr != slotAgeWise.end(); ++itr) 
    {
        if(itr->first == age)
        return itr->second;
    }
    return {};
}

//given slot corresponding to particular reg no
int Vehicle :: slotWithCarNo(string no)
{
    map<string, int>::iterator itr;
    for (itr = regNoWithSlot.begin(); itr != regNoWithSlot.end(); ++itr) 
    {
        if(itr->first == no)
        return itr->second;
    }
    return 0;
}

// leaving the slot
string Vehicle :: Leave(string slotNo)
{
    map<string, int>::iterator itr;
    for (itr = regNoWithSlot.begin(); itr != regNoWithSlot.end(); ++itr) 
    {
        if(itr->second == stoi(slotNo))
        return itr->first;
    }
    return "Slot already vacant";

}

// vacating the slot and making it unreserved
void Vehicle :: vacate(string slott)
{
    map<string, int>::iterator itr;
    string corresRegNo;
    string corresAge;
    for (itr = regNoWithSlot.begin(); itr != regNoWithSlot.end(); ++itr) 
    {
        if(itr->second == stoi(slott))
        corresRegNo = itr->first, notReserved.push_back(slott), regNoWithSlot.erase(itr);
    }

    map<string, string>::iterator itr1;
    string s;
    for (itr1 = userDetailMap.begin(); itr1 != userDetailMap.end(); ++itr1) 
    {
        if(itr1->first == corresRegNo)
        corresAge = itr1->second, userDetailMap.erase(itr1);
    }

    map<string, vector<int>>::iterator itr2;
    for (itr2 = slotAgeWise.begin(); itr2 != slotAgeWise.end(); ++itr2) 
    {
        if(itr2->first == corresAge)
        slotAgeWise.erase(itr2);
    }

    map<string, vector<string>>::iterator itr3;
    for (itr3 = agewithRegNo.begin(); itr3 != agewithRegNo.end(); ++itr3) 
    {
        if(itr->first == corresAge)
        agewithRegNo.erase(itr3);
    }


    // for(itr = regNoWithSlot.begin(); itr != regNoWithSlot.end(); ++itr) 
    // {
    //     cout<<"\nHere we go "<<itr->first << '\t' << itr->second ;
    //     cout<<"\n";
        
    // }
}

//mapping and giving back vehicle reg no corresponding to particular driver age
vector<string> Vehicle :: ageWiseRegNo(string age)
{
    map<string, vector<string>>::iterator itr;
    for (itr = agewithRegNo.begin(); itr != agewithRegNo.end(); ++itr) 
    {
        if(itr->first == age)
        return itr->second;
    }
    return {};
}
