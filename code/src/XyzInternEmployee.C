#include "XyzInternEmployee.H"

void XyzInternEmployee::setInternSpecificDetails(InternDetails InternDetailsParm)
{
    mHiringCollege = InternDetailsParm.mHiringCollege;
    mHiringBranch = InternDetailsParm.mHiringBranch;
}

InternDetails XyzInternEmployee::getInternSpecificDetails(void)
{
    InternDetails sInternDetailsParm;
    sInternDetailsParm.mHiringCollege = mHiringCollege;
    sInternDetailsParm.mHiringBranch = mHiringBranch;   

    return sInternDetailsParm;
}


void XyzInternEmployee::printEmpSpecificHeader(void)
{
    cout << setfill('-') << setw(195) << "-" << endl;
    cout << left
         << "| Employee Name     "
         << "| ID        "
         << "| Type             "
         << "| Status         "
         << "| Gender      "
         << "| Date of Birth       "
         << "| Date of Joining    "
         << "| Date of Leaving    "
         << "| Hiring Branch      "
         << "| Hiring College     |" << endl;
    cout << setfill('-') << setw(195) << "-" << endl;
    cout << setfill(' ') << setw(195) << " " << endl;
}


void XyzInternEmployee::printEmpSpecifiDetails(void)
{
    cout << left
         << "| " << setw(18) << mEmployeeName
         << "| " << setw(10) << mEmployeeId
         << "| " << setw(18) << mEmployeeType
         << "| " << setw(16) << mEmployeeStatus
         << "| " << setw(13) << mGender
         << "| " << setw(20) << mDateOfBirth
         << "| " << setw(19) << mDateOfBirth
         << "| " << setw(19) << mDateOfBirth
         << "| " << setw(19) << mHiringBranch
         << "| " << setw(19) << mHiringCollege
         << "|" << endl;
         
    cout << setfill(' ') << setw(195) << " " << endl;
}

