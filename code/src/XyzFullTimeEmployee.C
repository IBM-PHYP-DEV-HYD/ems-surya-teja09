#include "XyzFullTimeEmployee.H"

XyzFullTimeEmployee::XyzFullTimeEmployee(string EmpNameParm, string EmpIdParm, int EmpStatusParm, int EmpTypeParm, int EmpGenderParm, string DobParm, string DojParm):
                     XyzEmployeeImpl(EmpNameParm, EmpIdParm, EmpStatusParm, EmpTypeParm, EmpGenderParm, DobParm, DojParm)   
{
    mLeavesAvailed = getRandomNumber(1, 22);   
    mLevesLeft = 22 - mLeavesAvailed;
}

void XyzFullTimeEmployee::setLeaveDetails(int LeavesAvailedParm)
{
    mLeavesAvailed = LeavesAvailedParm;
    mLevesLeft = 22 - mLeavesAvailed;
}

string XyzFullTimeEmployee::getEmployeeLeavesAvailed(void)
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

void XyzFullTimeEmployee::printParticularEmployeeSummary(void)
{
    XyzEmployeeImpl::printParticularEmployeeSummary();
    cout <<  " Leaves Availed  : " << mLeavesAvailed << endl;  
    cout <<  " Leaves Left     : " << mLevesLeft << endl;  
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


void XyzFullTimeEmployee::printEmpSpecificDetails(void)
{
    XyzEmployeeImpl::printEmpSpecificDetails();     
    cout << "| " << setw(20) << mLeavesAvailed
         << "| " << setw(16) << mLevesLeft
         << "|" << endl;
    
    cout << setfill(' ') << setw(187) << " " << endl;
}

void XyzFullTimeEmployee::addLeavestoFullTimeEmp(int LeavesLeftParm)
{
    mLevesLeft = LeavesLeftParm;
}