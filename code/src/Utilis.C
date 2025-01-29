#include "Utilis.H"

// Array of 50 random names
string EmpNames[50] = {
    "Aiden", "Olivia", "Noah", "Emma", "Liam","Sophia", "Jackson", "Ava", "Mason", "Isabella","Lucas", "Mia", 
    "Ethan", "Amelia", "James","Harper", "Benjamin", "Evelyn", "Alexander", "Lily","Henry", "Ella", "Sebastian", 
    "Grace", "Jack","Chloe", "William", "Charlotte", "Daniel", "Zoe","Matthew", "Hannah", "Samuel", "Emily", "David",
    "Abigail", "Gabriel", "Scarlett", "Owen", "Victoria","Isaac", "Lillian", "Elijah", "Lila", "Oliver","Aria", "Mila", 
    "Jameson", "Penelope", "Wyatt"};

string Months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

uint8_t ContractEmpExternalAgency[3] = {Ems::ExternalAgency::AVENGERS, Ems::ExternalAgency::JUSTICE_LEAUGE, Ems::ExternalAgency::X_MEN};

Ems::HiringFromBranches HiringBranch[3] = {Ems::HiringFromBranches::CSE, Ems::HiringFromBranches::CSIT, Ems::HiringFromBranches::ECE};

Ems::HiringFromColleges HiringCollege[7] = {Ems::HiringFromColleges::IIT_DELHI, Ems::HiringFromColleges::IIT_MUMBAI, 
                                            Ems::HiringFromColleges::IIT_HYDERABAD, Ems::HiringFromColleges::IIT_KANPUR, 
                                            Ems::HiringFromColleges::NIT_WARANGAL, Ems::HiringFromColleges::NIT_TIRUCHI, 
                                            Ems::HiringFromColleges::IIIT_HYDERABAD};


uint32_t fullTimeEmpCount = 0;
uint32_t contractEmpCount = 0;
uint32_t internEmpCount = 0;

int getRandomNumber(int startNumParm, int endNumParm)
{
    random_device sRandomDevice;
    mt19937 sRandomNumberGenerator(sRandomDevice());
    uniform_int_distribution<int> sGenerate(startNumParm, endNumParm);
    int sRandomNumber = sGenerate(sRandomNumberGenerator);
    return sRandomNumber;
}

#if 0
void getRandomizedEmpBasicDetails(EmpDetails* empDetailsParm)
{
    empDetailsParm->mEmpName = EmpNames[getRandomNumber(0, 50)];

    empDetailsParm->mDob = to_string(getRandomNumber(1, 30)) + " " + Months[getRandomNumber(0,11)] + " " + to_string(getRandomNumber(1960, 2000));

    empDetailsParm->mDoj = to_string(getRandomNumber(1, 30)) + " " + Months[getRandomNumber(0,11)] + " " + to_string(getRandomNumber(2001, 2024));

    empDetailsParm->mEmpStatus = getRandomNumber(1, 2);

    if(empDetailsParm->mEmpType == Ems::EmployeeType::FULL_TIME)
    {
        empDetailsParm->mEmpId = "XYZ" + to_string(fullTimeEmpCount * 0.000001).substr(4) + "F";
        fullTimeEmpCount++;
    }
    else if(empDetailsParm->mEmpType == Ems::EmployeeType::CONTRACT)
    {
        empDetailsParm->mEmpId = "XYZ" + to_string(contractEmpCount * 0.000001).substr(4) + "C";
        contractEmpCount++;
    } 
    else if(empDetailsParm->mEmpType == Ems::EmployeeType::INTERN)
    {
        empDetailsParm->mEmpId = "XYZ" + to_string(internEmpCount * 0.000001).substr(4) + "I";
        internEmpCount++;
    }
    else
    {
        //No operation required
    }
    
    int sResult = getRandomNumber(1,20);

    if(sResult < 10)
    {
        empDetailsParm->mGender = 1;            // Male employee
    }
    else
    {
        empDetailsParm->mGender = 2;            // Female employee
    }    
}
#endif

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void getRandomizedEmpBasicDetails(EmpDetails* empDetailsParm)
{
    empDetailsParm->mEmpName = EmpNames[getRandomNumber(0, 50)];

    empDetailsParm->mDob = to_string(getRandomNumber(1, 30)) + " " + Months[getRandomNumber(0,11)] + " " + to_string(getRandomNumber(1960, 2000));

    int joiningDay = getRandomNumber(1, 30);
    int joiningMonthIndex = getRandomNumber(0,11);
    int joiningYear = getRandomNumber(2001, 2024);

    empDetailsParm->mDoj = to_string(joiningDay) + " " + Months[joiningMonthIndex] + " " + to_string(joiningYear);

    empDetailsParm->mDol = empDetailsParm->mDoj;

    empDetailsParm->mEmpStatus = getRandomNumber(1, 2);

    if(empDetailsParm->mEmpType == Ems::EmployeeType::FULL_TIME)
    {
        empDetailsParm->mEmpId = "XYZ" + to_string(fullTimeEmpCount * 0.000001).substr(4) + "F";
        fullTimeEmpCount++;

        empDetailsParm->mDol = "NA";
        empDetailsParm->mLevesLeft = 22;
        empDetailsParm->mLeavesAvailed = 0;
    }
    else if(empDetailsParm->mEmpType == Ems::EmployeeType::CONTRACT)
    {
        empDetailsParm->mEmpId = "XYZ" + to_string(contractEmpCount * 0.000001).substr(4) + "C";
        contractEmpCount++;

        int leavingYear = joiningYear + 1; 
        empDetailsParm->mDol = to_string(joiningDay) + " " + Months[joiningMonthIndex] + " " + to_string(leavingYear);
        empDetailsParm->mExtAgency = getRandomizedEmployeeAgency();
    } 
    else if(empDetailsParm->mEmpType == Ems::EmployeeType::INTERN)
    {
        empDetailsParm->mEmpId = "XYZ" + to_string(internEmpCount * 0.000001).substr(4) + "I";
        internEmpCount++;

        int leavingMonthIndex = joiningMonthIndex + 6; 

        if (leavingMonthIndex >= 12) {
            leavingMonthIndex -= 12;
            joiningYear += 1;
        }

        empDetailsParm->mDol = to_string(joiningDay) + " " + Months[leavingMonthIndex] + " " + to_string(joiningYear);

        empDetailsParm->mHiringBranch  = HiringBranch[getRandomNumber(0,2)];
        empDetailsParm->mHiringCollege = HiringCollege[getRandomNumber(0,6)];
    }

    int sResult = getRandomNumber(1, 20);
    empDetailsParm->mGender = (sResult < 10) ? 1 : 2;
}


string getFullTimeEmpId(void)
{
    string sEmpId;
    sEmpId = "XYZ" + to_string(fullTimeEmpCount * 0.000001).substr(4) + "F";
    fullTimeEmpCount++;
    return sEmpId;
}


int getRandomizedEmployeeAgency(void)
{
    return getRandomNumber(0,2);
}

void getRandomizedInternDetails(InternDetails *internDetailsParm)
{
    internDetailsParm->mHiringBranch = HiringBranch[getRandomNumber(0,2)];

    internDetailsParm->mHiringCollege = HiringCollege[getRandomNumber(0,6)];
}

string getAgencyFromEnum(int extAgencyParm)
{
    string sAgency = "NA";
    switch(extAgencyParm)
    {
        case Ems::ExternalAgency::AVENGERS:
        {
            sAgency = "AVENGERS";
            break;
        }
        case Ems::ExternalAgency::JUSTICE_LEAUGE:
        {
            sAgency = "JUSTICE_LEAUGE";
            break;
        }
        case Ems::ExternalAgency::X_MEN:
        {
            sAgency = "X_MEN";
            break;
        }
        default:
        {
            break;
        }
    }
    return sAgency;
}

string getHiringCollegeFromEnum(int hiringCollegeParm)
{
    string sHiringCollege = "NA";
    switch(hiringCollegeParm)
    {
        case Ems::HiringFromColleges::IIT_DELHI:
        {
            sHiringCollege = "IIT_DELHI";
            break;
        }
        case Ems::HiringFromColleges::IIT_MUMBAI:
        {
            sHiringCollege = "IIT_MUMBAI";
            break;
        }
        case Ems::HiringFromColleges::IIT_HYDERABAD:
        {
            sHiringCollege = "IIT_HYDERABAD";
            break;
        }
        case Ems::HiringFromColleges::IIT_KANPUR:
        {
            sHiringCollege = "IIT_KANPUR";
            break;
        }
        case Ems::HiringFromColleges::NIT_WARANGAL:
        {
            sHiringCollege = "NIT_WARANGAL";
            break;
        }
        case Ems::HiringFromColleges::NIT_TIRUCHI:
        {
            sHiringCollege = "NIT_TIRUCHI";
            break;
        }
       case Ems::HiringFromColleges::IIIT_HYDERABAD:
        {
            sHiringCollege = "IIIT_HYDERABAD";
            break;
        }     
        default:
        {
            break;
        }
    }
    return sHiringCollege;
}

string getHiringBranchFromEnum(int hiringBranchParm)
{
    string sHiringBranch = "NA";
    switch(hiringBranchParm)
    {
        case Ems::HiringFromBranches::CSE:
        {
            sHiringBranch = "CSE";
            break;
        }
        case Ems::HiringFromBranches::CSIT:
        {
            sHiringBranch = "CSIT";
            break;
        }
        case Ems::HiringFromBranches::ECE:
        {
            sHiringBranch = "ECE";
            break;
        }
        default:
        {
            break;
        }
    }
    return sHiringBranch;
}

string getEmpStatusFromEnum(int empStatusParm)
{
    string sEmpStatus = "NA";
    switch(empStatusParm)
    {
        case Ems::EmployeeStatus::ACTIVE:
        {
            sEmpStatus = "ACTIVE";
            break;
        }
        case Ems::EmployeeStatus::INACTIVE:
        {
            sEmpStatus = "INACTIVE";
            break;
        }
        case Ems::EmployeeStatus::RESIGNED:
        {
            sEmpStatus = "RESIGNED";
            break;
        }
        default:
        {
            break;
        }
    }
    return sEmpStatus;
}

string getGenderFromEnum(int genderParm)
{
    string sGender = "NA";
    if(genderParm == 1)
    {
        sGender = "MALE";
    }
    else
    {
        sGender = "FEMALE";
    }  
    return sGender;
}
  
string getTypeFromEnum(int employeeTypeParm)
{
    string sEmpType = "NA";
    switch(employeeTypeParm)
    {
        case Ems::EmployeeType::FULL_TIME:
        {
            sEmpType = "FULL_TIME";
            break;
        }
        case Ems::EmployeeType::CONTRACT:
        {
            sEmpType = "CONTRACT";
            break;
        }
        case Ems::EmployeeType::INTERN:
        {
            sEmpType = "INTERN";
            break;
        }
    }
    return sEmpType;
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
    cout<<"| 1. Employee Summary based on type.   |"<<endl;
    cout<<"| 2. Employee Summary based on Gender  |"<<endl;
    cout<<"| 3. Employee Summary based on Status  |"<<endl;
    cout<<"| 4. Employee Summary Summary.         |"<<endl;
    cout<<"| 5. Resigned Employee Summary.        |"<<endl;
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