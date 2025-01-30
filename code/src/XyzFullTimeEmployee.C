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
                                         int leavesLeftParm)
:XyzEmployeeImpl(empNameParm 
                ,empIdParm 
                ,empStatusParm 
                ,empTypeParm 
                ,empGenderParm 
                ,dobParm 
                ,dojParm
                ,dolParm) 
,mLeavesAvailed(leavesAvailedParm)
,mLeavesLeft(leavesLeftParm) 
{

}

void XyzFullTimeEmployee::setLeaveDetails(int leavesAvailedParm)
{
    mLeavesAvailed = leavesAvailedParm;
    mLeavesLeft = 22 - mLeavesAvailed;
}

string XyzFullTimeEmployee::getEmployeeLeavesAvailed(void)
{
    return to_string(mLeavesAvailed);
}

string XyzFullTimeEmployee::getEmployeeLeavesLeft(void)
{
    return to_string(mLeavesLeft);
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
    cout <<  " Leaves Left     : " << mLeavesLeft << endl;  
}

void XyzFullTimeEmployee::printEmpSpecificHeader(void)
{
    cout << setfill('-') << setw(188) << "-" << endl;
    cout << "| "<< left << setw(20) << setfill(' ') <<"Employee Name";
    cout << "| "<< left << setw(10) << setfill(' ') <<"ID";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Type";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Status";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Gender";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Date of Birth";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Date of Joining";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Date of Leaving";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Leaves Availed";
    cout << "| "<< left << setw(18) << setfill(' ') <<"Leaves Left";
    cout << endl;
    cout << setfill('-') << setw(188) << "-" << endl;
    cout << setfill(' ') << setw(188) << " " << endl;
}


void XyzFullTimeEmployee::fillEmpSpecificDetails(EmsPrintRecord &emsPrintParm)
{
    XyzEmployeeImpl::fillEmpSpecificDetails(emsPrintParm);   
    emsPrintParm.mEmpNol = to_string(mLeavesLeft);
    emsPrintParm.mEmpNola = to_string(mLeavesAvailed);
}

void XyzFullTimeEmployee::addLeavestoFullTimeEmp(int leavesLeftParm)
{
    mLeavesLeft = leavesLeftParm;
}

void XyzFullTimeEmployee::setDateOfLeaving(string dolParm)
{
    mDateOfLeaving = dolParm;
}