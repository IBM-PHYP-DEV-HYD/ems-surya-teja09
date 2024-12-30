#include "XyzFullTimeEmployee.H"

void XyzFullTimeEmployee::setLeaveDetails(int LeavesAvailedParm)
{
    mLeavesAvailed = LeavesAvailedParm;
    mLevesLeft = 22 - mLeavesAvailed;
}

string XyzFullTimeEmployee::getEmployeeLeavesAvaialed(void)
{
    return to_string(mLeavesAvailed);
}

string XyzFullTimeEmployee::getEmployeeLeavesLeft(void)
{
    return to_string(mLevesLeft);
}

ExternalAgency XyzFullTimeEmployee::getExtAgency(void)
{
    return (ExternalAgency)AGENCY_UNDEFINED;
}

InternDetails XyzFullTimeEmployee::getInternSpecificDetails(void)
{
    InternDetails sInternDetailsParm;
    sInternDetailsParm.mHiringCollege = COLLEGE_UNDEFINED;
    sInternDetailsParm.mHiringBranch = UNDEFINED_BRANCH;   

    return sInternDetailsParm;
}

void XyzFullTimeEmployee::printEmpSpecificHeader(void)
{
    cout << setfill('-') << setw(187) << "-" << endl;
    cout << left
         << "| Employee Name     "
         << "| ID        "
         << "| Type             "
         << "| Status         "
         << "| Gender      "
         << "| Date of Birth       "
         << "| Date of Joining    "
         << "| Date of Leaving    "
         << "| Leaves Availed      "
         << "| Leaves Left     |" << endl;
    cout << setfill('-') << setw(187) << "-" << endl;
    cout << setfill(' ') << setw(187) << " " << endl;
}


void XyzFullTimeEmployee::printEmpSpecifiDetails(void)
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


    cout << left
         << "| " << setw(18) << mEmployeeName
         << "| " << setw(10) << mEmployeeId
         << "| " << setw(17) << "FULL-TIME"
         << "| " << setw(15) << sEmpStatus
         << "| " << setw(12) << sGender
         << "| " << setw(20) << mDateOfBirth
         << "| " << setw(19) << mDateOfBirth
         << "| " << setw(19) << mDateOfBirth
         << "| " << setw(20) << mLeavesAvailed
         << "| " << setw(16) << mLevesLeft
         << "|" << endl;
    
    cout << setfill(' ') << setw(187) << " " << endl;
}