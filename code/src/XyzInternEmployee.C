#include "XyzInternEmployee.H"

XyzInternEmployee::XyzInternEmployee(string EmpNameParm, string EmpIdParm, int EmpStatusParm, int EmpTypeParm, int EmpGenderParm, string DobParm, string DojParm):
                     XyzEmployeeImpl(EmpNameParm, EmpIdParm, EmpStatusParm, EmpTypeParm, EmpGenderParm, DobParm, DojParm) 
{
    InternDetails sInternDetails;
    getRandomizedInternDetails(&sInternDetails);
    mHiringCollege = sInternDetails.mHiringCollege;
    mHiringBranch = sInternDetails.mHiringBranch;   
}

InternDetails XyzInternEmployee::getInternSpecificDetails(void)
{
    InternDetails sInternDetailsParm;
    sInternDetailsParm.mHiringCollege = mHiringCollege;
    sInternDetailsParm.mHiringBranch = mHiringBranch;   

    return sInternDetailsParm;
}

ExternalAgency XyzInternEmployee::getExtAgency(void)
{
    return (ExternalAgency)AGENCY_UNDEFINED;
}

string XyzInternEmployee::getEmployeeLeavesAvailed(void)
{
    return "NA";
}

string XyzInternEmployee::getEmployeeLeavesLeft(void)
{
    return "NA";
}

void XyzInternEmployee::printParticularEmployeeSummary(void)
{
    XyzEmployeeImpl::printParticularEmployeeSummary();
    cout <<  " Hiring College  : " << getHiringCollegeFromEnum(mHiringCollege) << endl;  
    cout <<  " Hiring Branch   : " << getHiringBranchFromEnum(mHiringBranch) << endl;     
}

void XyzInternEmployee::printEmpSpecificHeader(void)
{
    cout << setfill('-') << setw(189) << "-" << endl;
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
    cout << setfill('-') << setw(189) << "-" << endl;
    cout << setfill(' ') << setw(189) << " " << endl;
}


void XyzInternEmployee::printEmpSpecificDetails(void)
{
    XyzEmployeeImpl::printEmpSpecificDetails();
    mEmsPrint.mEmpCollege = getHiringCollegeFromEnum(mHiringCollege) ;  
    mEmsPrint.mEmpBranch  = getHiringBranchFromEnum(mHiringBranch); 
    mEmsPrint.printAll();
}

