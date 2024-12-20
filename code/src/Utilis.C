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

uint8_t ContractEmpExternalAgency[3] = {AVENGERS, JUSTICE_LEAUGE, X_MEN};

HiringFromBranches HiringBranch[3] = {CSE, CSIT, ECE};

HiringFromColleges HiringCollege[7] = {IIT_DELHI, IIT_MUMBAI, IIT_HYDERABAD, IIT_KANPUR, NIT_WARANGAL, NIT_TIRUCHI, IIIT_HYDERABAD};

int getRandomNumber(int startNumParm, int endNumParm)
{
    random_device sRandomDevice;
    mt19937 sRandomNumberGenerator(sRandomDevice());
    uniform_int_distribution<int> sGenerate(startNumParm, endNumParm);
    int sRandomNumber = sGenerate(sRandomNumberGenerator);
    return sRandomNumber;
}

void getRandomizedEmpBasicDetails(EmpDetails* EmpDetailsParm, uint32_t mEmpIdSeriesNumParm)
{
    EmpDetailsParm->mEmpName = EmpNames[getRandomNumber(0, 50)];

    EmpDetailsParm->mDob = to_string(getRandomNumber(1, 30)) + " " + Months[getRandomNumber(0,11)] + " " + to_string(getRandomNumber(1960, 2000));

    //uint16_t sYear;
    //sYear = getRandomNumber(2001, 2024);

    EmpDetailsParm->mDoj = to_string(getRandomNumber(1, 30)) + " " + Months[getRandomNumber(0,11)] + " " + to_string(getRandomNumber(2001, 2024));

    EmpDetailsParm->mEmpStatus = getRandomNumber(1, 2);

    if(EmpDetailsParm->mEmpType == FULL_TIME)
    {
        EmpDetailsParm->mEmpId = "XYZ" + to_string(mEmpIdSeriesNumParm * 0.000001).substr(4) + "F";
    }
    else if(EmpDetailsParm->mEmpType == CONTRACT)
    {
        EmpDetailsParm->mEmpId = "XYZ" + to_string(mEmpIdSeriesNumParm * 0.000001).substr(4) + "C";
    } 
    else if(EmpDetailsParm->mEmpType == INTERN)
    {
        EmpDetailsParm->mEmpId = "XYZ" + to_string(mEmpIdSeriesNumParm * 0.000001).substr(4) + "I";
    }
    else
    {
        //No operation required
    }
    
    EmpDetailsParm->mGender = getRandomNumber(0,1);
}

ExternalAgency getRandomizedEmployeeAgency(void)
{
    return (ExternalAgency)getRandomNumber(0,2);
}


void getRandomizedInternDetails(InternDetails *InternDetailsParm)
{
    InternDetailsParm->mHiringBranch = HiringBranch[getRandomNumber(0,2)];

    InternDetailsParm->mHiringCollege = HiringCollege[getRandomNumber(0,6)];
}





