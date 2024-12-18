#include "Utilis.H"

// Array of 50 random names
string EmpNames[50] = {
    "Aiden", "Olivia", "Noah", "Emma", "Liam","Sophia", "Jackson", "Ava", "Mason", "Isabella","Lucas", "Mia", 
    "Ethan", "Amelia", "James","Harper", "Benjamin", "Evelyn", "Alexander", "Lily","Henry", "Ella", "Sebastian", 
    "Grace", "Jack","Chloe", "William", "Charlotte", "Daniel", "Zoe","Matthew", "Hannah", "Samuel", "Emily", "David",
    "Abigail", "Gabriel", "Scarlett", "Owen", "Victoria","Isaac", "Lillian", "Elijah", "Lila", "Oliver","Aria", "Mila", 
    "Jameson", "Penelope", "Wyatt"};

char EmpGender[2] = {'M', 'F'};

string Months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

int getRandomNumber(int startNumParm, int endNumParm)
{
    random_device sRandomDevice;
    mt19937 sRandomNumberGenerator(sRandomDevice());
    uniform_int_distribution<int> sGenerate(startNumParm, endNumParm);
    int sRandomNumber = sGenerate(sRandomNumberGenerator);
    return sRandomNumber;
}

void getEmpBasicDetails(EmpDetails* EmpDetailsParm, uint32_t mEmpIdSeriesNumParm)
{

    EmpDetailsParm->mEmpName = EmpNames[getRandomNumber(0, 50)];

    EmpDetailsParm->mDob = to_string(getRandomNumber(1, 30)) + " " + Months[getRandomNumber(0,11)] + " " + to_string(getRandomNumber(1960, 2000));

    //uint16_t sYear;
    //sYear = getRandomNumber(2001, 2024);

    EmpDetailsParm->mDoj = to_string(getRandomNumber(1, 30)) + " " + Months[getRandomNumber(0,11)] + " " + to_string(getRandomNumber(2001, 2024));

    EmpDetailsParm->mEmpStatus = getRandomNumber(1, 2);

    EmpDetailsParm->mEmpId = "XYZ" + to_string(mEmpIdSeriesNumParm * 0.000001).substr(4) + "F";

}


