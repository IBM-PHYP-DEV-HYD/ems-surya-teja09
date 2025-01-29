#include "XyzContractEmployee.H"

XyzContractEmployee::XyzContractEmployee(string empNameParm, 
                                         string empIdParm, 
                                         int empStatusParm, 
                                         int empTypeParm, 
                                         int empGenderParm, 
                                         string dobParm, 
                                         string dojParm,
                                         string dolParm,
                                         int extAgencyParm):
XyzEmployeeImpl(empNameParm, 
                empIdParm, 
                empStatusParm, 
                empTypeParm, 
                empGenderParm, 
                dobParm, 
                dojParm,
                dolParm),
                mExtAgency(extAgencyParm)
{
    //mExtAgency = getRandomizedEmployeeAgency();   
}

Ems::ExternalAgency XyzContractEmployee::getExtAgency(void)
{
    return (Ems::ExternalAgency)mExtAgency;
}

InternDetails XyzContractEmployee::getInternSpecificDetails(void)
{
    InternDetails sInternDetailsParm;
    sInternDetailsParm.mHiringCollege = Ems::HiringFromColleges::COLLEGE_UNDEFINED;
    sInternDetailsParm.mHiringBranch = Ems::HiringFromBranches::UNDEFINED_BRANCH;   

    return sInternDetailsParm;
}

string XyzContractEmployee::getEmployeeLeavesAvailed(void)
{
    return "NA";
}

string XyzContractEmployee::getEmployeeLeavesLeft(void)
{
    return "NA";
}

void XyzContractEmployee::printParticularEmployeeSummary(void)
{
    XyzEmployeeImpl::printParticularEmployeeSummary();
    cout <<  " External Agency : " << getAgencyFromEnum(mExtAgency) << endl;
}

void XyzContractEmployee::printEmpSpecificHeader(void)
{
    cout << setfill('-') << setw(165) << "-" << endl;
    cout << left
         << "| Employee Name      "
         << "| ID       "
         << "| Type             "
         << "| Status           "
         << "| Gender           "
         << "| Date of Birth    "
         << "| Date of Joining  "
         << "| Date of Leaving  "
         << "| Agency          |" << endl;
    cout << setfill('-') << setw(165) << "-" << endl;
    cout << setfill(' ') << setw(165) << " " << endl;
}


void XyzContractEmployee::printEmpSpecificDetails(EmsPrintRecord &emsPrintParm)
{ 
    XyzEmployeeImpl::printEmpSpecificDetails(emsPrintParm);
    emsPrintParm.mEmpAgency = getAgencyFromEnum(mExtAgency);

    //mEmsPrint.printAll();
}