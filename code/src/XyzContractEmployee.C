#include "XyzContractEmployee.H"

XyzContractEmployee::XyzContractEmployee(string empNameParm, 
                                         string empIdParm, 
                                         int empStatusParm, 
                                         int empTypeParm, 
                                         int empGenderParm, 
                                         string dobParm, 
                                         string dojParm,
                                         string dolParm,
                                         int extAgencyParm)
:XyzEmployeeImpl(empNameParm 
                ,empIdParm 
                ,empStatusParm 
                ,empTypeParm 
                ,empGenderParm 
                ,dobParm
                ,dojParm
                ,dolParm)
,mExtAgency(extAgencyParm)
{
 
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
    cout << setfill('-') << setw(172) << "-" << endl;
    cout << "| "<< left << setw(20) << setfill(' ') <<"Employee Name";
    cout << "| "<< left << setw(10) << setfill(' ') <<"ID";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Type";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Status";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Gender";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Date of Birth";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Date of Joining";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Date of Leaving";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Agency";
    cout << endl;
    cout << setfill('-') << setw(172) << "-" << endl;
    cout << setfill(' ') << setw(172) << " " << endl;
}

void XyzContractEmployee::fillEmpSpecificDetails(EmsPrintRecord &emsPrintParm)
{ 
    XyzEmployeeImpl::fillEmpSpecificDetails(emsPrintParm);
    emsPrintParm.mEmpAgency = getAgencyFromEnum(mExtAgency);
}

void XyzContractEmployee::setDateOfLeaving(string dolParm)
{

}