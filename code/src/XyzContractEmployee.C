#include "XyzContractEmployee.H"

XyzContractEmployee::XyzContractEmployee(string EmpNameParm, string EmpIdParm, int EmpStatusParm, int EmpTypeParm, int EmpGenderParm, string DobParm, string DojParm):
                     XyzEmployeeImpl(EmpNameParm, EmpIdParm, EmpStatusParm, EmpTypeParm, EmpGenderParm, DobParm, DojParm) 
{
    mExtAgency = getRandomizedEmployeeAgency();   
}

ExternalAgency XyzContractEmployee::getExtAgency(void)
{
    return (ExternalAgency)mExtAgency;
}

InternDetails XyzContractEmployee::getInternSpecificDetails(void)
{
    InternDetails sInternDetailsParm;
    sInternDetailsParm.mHiringCollege = COLLEGE_UNDEFINED;
    sInternDetailsParm.mHiringBranch = UNDEFINED_BRANCH;   

    return sInternDetailsParm;
}

string XyzContractEmployee::getEmployeeLeavesAvaialed(void)
{
    return "NA";
}

string XyzContractEmployee::getEmployeeLeavesLeft(void)
{
    return "NA";
}

void XyzContractEmployee::printParticularEmployeeSummary(void)
{
    cout << "Employee Details :" << endl;
    string sEmpStatus;
    switch(mEmployeeStatus)
    {
        case ACTIVE:
        {
            sEmpStatus = "ACTIVE";
            break;
        }
        case INACTIVE:
        {
            sEmpStatus = "INACTIVE";
            break;
        }
        case RESIGNED:
        {
            sEmpStatus = "RESIGNED";
            break;
        }
    }

    string sGender;
    if(mGender == 1)
    {
        sGender = "MALE";
    }
    else
    {
        sGender = "FEMALE";
    }

    string sAgency;
    switch(mExtAgency)
    {
        case AVENGERS:
        {
            sAgency = "AVENGERS";
            break;
        }
        case JUSTICE_LEAUGE:
        {
            sAgency = "JUSTICE_LEAUGE";
            break;
        }
        case X_MEN:
        {
            sAgency = "X_MEN";
            break;
        }
        default:
        {
            break;
        }
    }

    cout <<  " Employee Name   : " << mEmployeeName << endl;
    cout <<  " Employee Id     : " << mEmployeeId << endl;
    cout <<  " Employee Type   : " << "CONTRACT" << endl;
    cout <<  " Employee Status : " << sEmpStatus << endl;
    cout <<  " Employee Gender : " << sGender << endl;
    cout <<  " Date of Birth   : " << mDateOfBirth << endl;
    cout <<  " Date of Joining : " << mDateOfBirth << endl;
    cout <<  " External Agency : " << sAgency << endl;
}

void XyzContractEmployee::printEmpSpecificHeader(void)
{
    cout << setfill('-') << setw(165) << "-" << endl;
    cout << left
         << "| Employee Name     "
         << "| ID        "
         << "| Type             "
         << "| Status         "
         << "| Gender      "
         << "| Date of Birth       "
         << "| Date of Joining    "
         << "| Date of Leaving    "
         << "| Agency          |" << endl;
    cout << setfill('-') << setw(165) << "-" << endl;
    cout << setfill(' ') << setw(165) << " " << endl;
}


void XyzContractEmployee::printEmpSpecifiDetails(void)
{
    string sEmpStatus;
    switch(mEmployeeStatus)
    {
        case ACTIVE:
        {
            sEmpStatus = "ACTIVE";
            break;
        }
        case INACTIVE:
        {
            sEmpStatus = "INACTIVE";
            break;
        }
        case RESIGNED:
        {
            sEmpStatus = "RESIGNED";
            break;
        }
        default:
        {
            break;
        }
    }

    string sGender;
    if(mGender == 1)
    {
        sGender = "MALE";
    }
    else
    {
        sGender = "FEMALE";
    }

    string sAgency;
    switch(mExtAgency)
    {
        case AVENGERS:
        {
            sAgency = "AVENGERS";
            break;
        }
        case JUSTICE_LEAUGE:
        {
            sAgency = "JUSTICE_LEAUGE";
            break;
        }
        case X_MEN:
        {
            sAgency = "X_MEN";
            break;
        }
        default:
        {
            break;
        }
    }    

    cout << left
         << "| " << setw(18) << mEmployeeName
         << "| " << setw(10) << mEmployeeId
         << "| " << setw(17) << "CONTRACT"
         << "| " << setw(16) << sEmpStatus
         << "| " << setw(13) << sGender
         << "| " << setw(20) << mDateOfBirth
         << "| " << setw(19) << mDateOfBirth
         << "| " << setw(19) << mDateOfBirth
         << "| " << setw(15) << sAgency
         << "|" << endl;

    cout << setfill(' ') << setw(160) << " " << endl;
}