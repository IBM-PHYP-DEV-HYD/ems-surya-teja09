#include "XyzInternEmployee.H"

XyzInternEmployee::XyzInternEmployee(string empNameParm, 
                                     string empIdParm, 
                                     int empStatusParm, 
                                     int empTypeParm, 
                                     int empGenderParm, 
                                     string dobParm, 
                                     string dojParm,
                                     string dolParm,
                                     Ems::HiringFromColleges hiringCollegeParm,
                                     Ems::HiringFromBranches hiringBranchParm):
XyzEmployeeImpl(empNameParm, 
                empIdParm, 
                empStatusParm, 
                empTypeParm, 
                empGenderParm, 
                dobParm, 
                dojParm,
                dolParm),
                mHiringCollege(hiringCollegeParm),
                mHiringBranch(hiringBranchParm)
{
 
}

InternDetails XyzInternEmployee::getInternSpecificDetails(void)
{
    InternDetails sInternDetailsParm;
    sInternDetailsParm.mHiringCollege = mHiringCollege;
    sInternDetailsParm.mHiringBranch = mHiringBranch;   

    return sInternDetailsParm;
}

Ems::ExternalAgency XyzInternEmployee::getExtAgency(void)
{
    return (Ems::ExternalAgency)Ems::ExternalAgency::AGENCY_UNDEFINED;
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
         << "| Employee Name      "
         << "| ID       "
         << "| Type             "
         << "| Status           "
         << "| Gender           "
         << "| Date of Birth    "
         << "| Date of Joining  "
         << "| Date of Leaving  "
         << "| Hiring Branch    "
         << "| Hiring College  |" << endl;
    cout << setfill('-') << setw(189) << "-" << endl;
    cout << setfill(' ') << setw(189) << " " << endl;
}


void XyzInternEmployee::printEmpSpecificDetails(EmsPrintRecord &emsPrintParm)
{
    XyzEmployeeImpl::printEmpSpecificDetails(emsPrintParm);
    emsPrintParm.mEmpCollege = getHiringCollegeFromEnum(mHiringCollege) ;  
    emsPrintParm.mEmpBranch  = getHiringBranchFromEnum(mHiringBranch); 
    //mEmsPrint.printAll();
}

