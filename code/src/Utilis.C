#include "Utilis.H"

// Array of 50 random names
string EmpNames[50] = {
    "Aiden", "Olivia", "Noah", "Emma", "Liam","Sophia", "Jackson", "Ava", "Mason", "Isabella","Lucas", "Mia", 
    "Ethan", "Amelia", "James","Harper", "Benjamin", "Evelyn", "Alexander", "Lily","Henry", "Ella", "Sebastian", 
    "Grace", "Jack","Chloe", "William", "Charlotte", "Daniel", "Zoe","Matthew", "Hannah", "Samuel", "Emily", "David",
    "Abigail", "Gabriel", "Scarlett", "Owen", "Victoria","Isaac", "Lillian", "Elijah", "Lila", "Oliver","Aria", "Mila", 
    "Jameson", "Penelope", "Wyatt"};

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
    
    int sResult = getRandomNumber(1,20);

    if(sResult < 10)
    {
        EmpDetailsParm->mGender = 1;            // Male employee
    }
    else
    {
        EmpDetailsParm->mGender = 2;            // Female employee
    }
        
}

int getRandomizedEmployeeAgency(void)
{
    return getRandomNumber(0,2);
}

void getRandomizedInternDetails(InternDetails *InternDetailsParm)
{
    InternDetailsParm->mHiringBranch = HiringBranch[getRandomNumber(0,2)];

    InternDetailsParm->mHiringCollege = HiringCollege[getRandomNumber(0,6)];
}

void printmainmenu(void)
{
    cout<<endl<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"| Choose any Option below          |"<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"| 1. Add an Employee.              |"<<endl;
    cout<<"| 2. Remove an employee.           |"<<endl;
    cout<<"| 3. Employee Details              |"<<endl;
    cout<<"| 4. Others.                       |"<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"|      Press -1 to exit            |"<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<endl<<endl;
}

void printEmployeeOption(void)
{
    cout<<endl<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"| Choose any option below.         |"<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"| 1. Add Employee at Random        |"<<endl;
    cout<<"| 2. Add an Employee (F/C/I)       |"<<endl;
    cout<<"-----------------------------------|"<<endl;
    cout<<"|   Press -1 to Exit.              |"<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<endl<<endl;
                
}

void printemployeetypemenu(void)
{
    cout<<endl<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"| Choose Employee Type.            |"<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"| 1. Full-time Employee            |"<<endl;
    cout<<"| 2. Contractor Employee           |"<<endl;
    cout<<"| 3. Intern Employee               |"<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<"|      Press -1 to exit            |"<<endl;
    cout<<"|----------------------------------|"<<endl;
    cout<<endl<<endl;
}

void printEmployeedetailsMenu(void)
{
    cout<<endl<<endl;
    cout<<"|--------------------------------------|"<<endl;
    cout<<"| Choose Employee Details.             |"<<endl;
    cout<<"|--------------------------------------|"<<endl;
    cout<<"| 1. Active Employee Summary           |"<<endl;
    cout<<"| 2. Employee Summary based on type.   |"<<endl;
    cout<<"| 3. Employee Summary based on Gender  |"<<endl;
    cout<<"| 4. Employee Summary based on Status  |"<<endl;
    cout<<"| 5. Employee Summary based on ID.     |"<<endl;
    cout<<"| 6. Resigned Employee Summary.        |"<<endl;
    cout<<"|--------------------------------------|"<<endl;
    cout<<"|      Press -1 to exit                |"<<endl;
    cout<<"|--------------------------------------|"<<endl;
    cout<<endl<<endl;
}

void printEmployeeOtherdetailsMenu(void)
{
    cout<<endl<<endl;
    cout<<"|-----------------------------------------------------------|"<<endl;
    cout<<"| Others Details                                            |"<<endl;
    cout<<"|-----------------------------------------------------------|"<<endl;
    cout<<"| 1. Add n number of leaves to all the Full-Time employees  |"<<endl;
    cout<<"| 2. Convert an Employee to Full-Time employee              |"<<endl;
    cout<<"| 3. Search an Employee by ID                               |"<<endl;
    cout<<"| 4. Search an Employee by Name                             |"<<endl;
    cout<<"| 5. Get Active and Resigned Employee Count                 |"<<endl;
    cout<<"|-----------------------------------------------------------|"<<endl;
    cout<<"|      Press -1 to exit                                     |"<<endl;
    cout<<"|-----------------------------------------------------------|"<<endl;
    cout<<endl<<endl;
}

void printDeletemenu(void)
{
    cout<<endl<<endl;
    cout<<"|--------------------------------------|"<<endl;
    cout<<"| Choose option to remove              |"<<endl;
    cout<<"|--------------------------------------|"<<endl;
    cout<<"| 1. Remove All employees              |"<<endl;
    cout<<"| 2. Remove based on type.             |"<<endl;
    cout<<"| 3. Remove based on Gender            |"<<endl;
    cout<<"| 4. Remove based on Status            |"<<endl;
    cout<<"| 5. Remove based on ID.               |"<<endl;
    cout<<"|--------------------------------------|"<<endl;
    cout<<"|      Press -1 to exit                |"<<endl;
    cout<<"|--------------------------------------|"<<endl;
    cout<<endl<<endl;
}