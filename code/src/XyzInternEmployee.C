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
                                     Ems::HiringFromBranches hiringBranchParm)
:XyzEmployeeImpl(empNameParm 
                ,empIdParm 
                ,empStatusParm
                ,empTypeParm 
                ,empGenderParm 
                ,dobParm 
                ,dojParm
                ,dolParm)
,mHiringCollege(hiringCollegeParm)
,mHiringBranch(hiringBranchParm)
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
    cout << setfill('-') << setw(190) << "-" << endl;
    cout << "| "<< left << setw(20) << setfill(' ') <<"Employee Name";
    cout << "| "<< left << setw(10) << setfill(' ') <<"ID";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Type";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Status";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Gender";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Date of Birth";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Date of Joining";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Date of Leaving";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Hiring Branch";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Hiring College";
    cout << endl;
    cout << setfill('-') << setw(190) << "-" << endl;
    cout << setfill(' ') << setw(190) << " " << endl;
}


void XyzInternEmployee::fillEmpSpecificDetails(EmsPrintRecord &emsPrintParm)
{
    XyzEmployeeImpl::fillEmpSpecificDetails(emsPrintParm);
    emsPrintParm.mEmpCollege = getHiringCollegeFromEnum(mHiringCollege) ;  
    emsPrintParm.mEmpBranch  = getHiringBranchFromEnum(mHiringBranch); 
}

void XyzInternEmployee::setDateOfLeaving(string dolParm)
{

}

