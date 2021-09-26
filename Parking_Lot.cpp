#include<bits/stdc++.h>
#include "vehicle.h"

using namespace std;

int main()
{
    fstream infile, outFile;
    string word, inFileName;
    inFileName = "input.txt";
    infile.open(inFileName.c_str());
    outFile.open("output.txt",ios::trunc | ios::out | ios::in);
    
    int flag = 1;
    int slot = 0;
    Vehicle vv;
    while(getline(infile, word))
    {
        switch (flag)
        {
        case 1:
        {
            outFile << "Created parking of " <<  word[19] << " slots";
            outFile << "\n";
            flag++;
            break;
        }
        case 2:
        case 3:
        case 5:
        case 8:
        {
            vv = Vehicle( word.substr(5,13), word.substr(word.length()-2,word.length() - 1));//,++slot);
            outFile << vv.displayParkSlot(word.substr(5,13));
            flag++;
            break;
        }
        case 4:
        {
            int i;
            vector<int> vec = vv.displaySlotAgeWise(word.substr(word.length()-2,word.length() - 1));
            for(i = 0; i < vec.size()-1; i++)
            outFile << to_string(vec[i]) + ",";
            outFile << to_string(vec[i]);
            outFile << "\n";
            flag++;
            break;
        }
        case 6:
        {
            outFile << to_string(vv.slotWithCarNo(word.substr(word.length()-13,word.length()-1)));
            outFile << "\n";
            flag++;
            break;
        }
        case 7:
        {
            string reg_no = vv.Leave(word.substr(word.length()-1));
            vv.vacate(word.substr(word.length()-1));
            outFile << "Slot number " << word.substr(word.length()-1) << " vacated, the car with vehicle registration number \"" 
                    << reg_no << "\" left the space, the driver of the car was of age " << vv.get_age(reg_no);
            outFile << "\n";
            flag++;
            break;
        }
        case 9:
        {
            int i;
            vector<string> vecAge = vv.ageWiseRegNo(word.substr(word.length()-2,word.length()-1));
            for(i = 0; i < vecAge.size(); i++)
            outFile << "\"" << vecAge[i] + "\", ";
            flag++;
            break;
        }
        default:
            break;
        }
    }


    return 0;
}