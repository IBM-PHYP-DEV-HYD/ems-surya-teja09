#include "XyzFullTimeEmployee.H"

XyzFullTimeEmployee::XyzFullTimeEmployee(string empNameParm, 
                                         string empIdParm, 
                                         int empStatusParm, 
                                         int empTypeParm, 
                                         int empGenderParm, 
                                         string dobParm, 
                                         string dojParm,
                                         string dolParm,
                                         int leavesAvailedParm,
                                         int leavesLeftParm):
XyzEmployeeImpl(empNameParm, 
                empIdParm, 
                empStatusParm, 
                empTypeParm, 
                empGenderParm, 
                dobParm, 
                dojParm,
                dolParm), 
                mLeavesAvailed(leavesAvailedParm),
                mLevesLeft(leavesLeftParm) 
{
    //mLeavesAvailed = getRandomNumber(1, 22);   
    //mLevesLeft = 22 - mLeavesAvailed;
}

void XyzFullTimeEmployee::setLeaveDetails(int leavesAvailedParm)
{
    mLeavesAvailed = leavesAvailedParm;
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

Ems::ExternalAgency XyzFullTimeEmployee::getExtAgency(void)
{
    return (Ems::ExternalAgency)Ems::ExternalAgency::AGENCY_UNDEFINED;
}

InternDetails XyzFullTimeEmployee::getInternSpecificDetails(void)
{
    InternDetails sInternDetailsParm;
    sInternDetailsParm.mHiringCollege = Ems::HiringFromColleges::COLLEGE_UNDEFINED;
    sInternDetailsParm.mHiringBranch = Ems::HiringFromBranches::UNDEFINED_BRANCH;   

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
         << "| Employee Name      "
         << "| ID       "
         << "| Type             "
         << "| Status           "
         << "| Gender           "
         << "| Date of Birth    "
         << "| Date of Joining  "
         << "| Date of Leaving  "
         << "| Leaves Availed   "
         << "| Leaves Left     |" << endl;
    cout << setfill('-') << setw(187) << "-" << endl;
    cout << setfill(' ') << setw(187) << " " << endl;
}


void XyzFullTimeEmployee::printEmpSpecificDetails(EmsPrintRecord &emsPrintParm)
{
    XyzEmployeeImpl::printEmpSpecificDetails(emsPrintParm);   
    emsPrintParm.mEmpNol = to_string(mLevesLeft);
    //mEmsPrint.printAll();
}

void XyzFullTimeEmployee::addLeavestoFullTimeEmp(int leavesLeftParm)
{
    mLevesLeft = leavesLeftParm;
}