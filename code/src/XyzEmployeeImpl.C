#include "XyzEmployeeImpl.H"


XyzEmployeeImpl::XyzEmployeeImpl(string empNameParm, 
                                 string empIdParm, 
                                 int empStatusParm, 
                                 int empTypeParm, 
                                 int empGenderParm, 
                                 string dobParm, 
                                 string dojParm,
                                 string dolParm): 
mEmployeeName(empNameParm), 
mEmployeeId(empIdParm), 
mEmployeeStatus(empStatusParm), 
mEmployeeType(empTypeParm), 
mGender(empGenderParm), 
mDateOfBirth(dobParm), 
mDateOfJoining(dojParm),  
mDateOfLeaving(dolParm)      
{

}

void XyzEmployeeImpl::setEmployeeBasicDetails(EmpDetails* empDetailsParm)
{
    mEmployeeName       = empDetailsParm->mEmpName;
    mDateOfBirth        = empDetailsParm->mDob;
    mDateOfJoining      = empDetailsParm->mDoj;
    mGender             = empDetailsParm->mGender;
    mEmployeeStatus     = empDetailsParm->mEmpStatus;
    mEmployeeType       = empDetailsParm->mEmpType; 
    mEmployeeId         = empDetailsParm->mEmpId;
}

void XyzEmployeeImpl::setLeaveDetails(int leavesAvailedParm)
{
    
}

InternDetails XyzEmployeeImpl::getInternSpecificDetails(void)
{
    InternDetails sDetails;
    return sDetails;
}

Ems::ExternalAgency XyzEmployeeImpl::getExtAgency(void)
{
    Ems::ExternalAgency sAgency = Ems::ExternalAgency::AGENCY_UNDEFINED;
    return sAgency;
}

string XyzEmployeeImpl::getEmployeeId(void)
{
    return mEmployeeId;
}

char XyzEmployeeImpl::getEmployeeGender(void)
{
    return mGender;
}

void XyzEmployeeImpl::setEmployeeStatus(int employeeStatusParm)
{
    mEmployeeStatus = employeeStatusParm;
}

int XyzEmployeeImpl::getEmployeeStatus(void)
{
    return mEmployeeStatus;
}

string XyzEmployeeImpl::getEmployeeName(void)
{
    return mEmployeeName;
}

int XyzEmployeeImpl::getEmployeeType(void)
{
    return mEmployeeType;
}

int XyzEmployeeImpl::getGender()
{
    return mGender;
}

string XyzEmployeeImpl::getDateOfBirth()
{
    return mDateOfBirth;
}

string XyzEmployeeImpl::getDateOfJoining()
{
    return mDateOfJoining;
}

string XyzEmployeeImpl::getDateOfLeaving()
{
    return mDateOfLeaving;
}

void XyzEmployeeImpl::printEmpSpecificHeader(void)
{

}

void XyzEmployeeImpl::printEmpSpecificDetails(EmsPrintRecord &emsPrintParm)
{
    emsPrintParm.mEmpName       = mEmployeeName;
    emsPrintParm.mEmpDob        = mDateOfBirth;
    emsPrintParm.mEmpDoj        = mDateOfJoining;
    emsPrintParm.mEmpDol        = mDateOfLeaving;
    emsPrintParm.mEmpGender     = getGenderFromEnum(mGender);
    emsPrintParm.mEmpid         = mEmployeeId;
    emsPrintParm.mEmpStatus     = getEmpStatusFromEnum(mEmployeeStatus);
    emsPrintParm.mEmpType       = getTypeFromEnum(mEmployeeType);
}

string XyzEmployeeImpl::getEmployeeLeavesAvailed(void)
{
    return "NA";
}

string XyzEmployeeImpl::getEmployeeLeavesLeft(void)
{
    return "NA";
}

void XyzEmployeeImpl::printParticularEmployeeSummary(void)
{
    cout <<  " Employee Name   : " << mEmployeeName << endl;
    cout <<  " Employee Id     : " << mEmployeeId << endl;
    cout <<  " Employee Type   : " << getTypeFromEnum(mEmployeeType) << endl;
    cout <<  " Employee Status : " << getEmpStatusFromEnum(mEmployeeStatus) << endl;
    cout <<  " Employee Gender : " << getGenderFromEnum(mGender) << endl;
    cout <<  " Date of Birth   : " << mDateOfBirth << endl;
    cout <<  " Date of Joining : " << mDateOfJoining << endl;   

}

void XyzEmployeeImpl::addLeavestoFullTimeEmp(int LeavesLeftParm)
{

}

void XyzEmployeeImpl::printResignedEmployeeSummaryHeader(void)
{
    cout << setfill('-') << setw(242) << "-" << endl;
    cout << left
         << "| Employee Name      "
         << "| ID       "
         << "| Type             "
         << "| Status           "
         << "| Gender           "
         << "| Date of Birth    "
         << "| Date of Joining  "
         << "| Date of Leaving |" << endl;
    cout << setfill('-') << setw(242) << "-" << endl;
    cout << setfill(' ') << setw(242) << " " << endl;          
}

void XyzEmployeeImpl::prinResignedEmployeeSummary(void)
{
    cout << left
         << "| " << setw(18) << mEmployeeName
         << "| " << setw(10) << mEmployeeId
         << "| " << setw(15) << "RESIGNED"
         << "| " << setw(12) << getGenderFromEnum(mGender)
         << "| " << setw(20) << mDateOfBirth 
         << "| " << setw(19) << mDateOfBirth
         << "| " << setw(19) << mDateOfBirth
         << "|" << endl;

    cout << setfill(' ') << setw(187) << " " << endl;
}

void XyzEmployeeImpl::printEmployeeSummaryHeader(void)
{
    cout << setfill('-') << setw(242) << "-" << endl;
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
         << "| Leaves Left      " 
         << "| Agency           " 
         << "| Hiring College   "
         << "| Hiring Branch   |"<< endl;
    cout << setfill('-') << setw(242) << "-" << endl;
    cout << setfill(' ') << setw(242) << " " << endl;   
}


void XyzEmployeeImpl::printEmployeeSummary(EmsPrintRecord &emsPrintParm)
{
    emsPrintParm.mEmpName       = mEmployeeName;
    emsPrintParm.mEmpDob        = mDateOfBirth;
    emsPrintParm.mEmpDoj        = mDateOfJoining;
    emsPrintParm.mEmpDol        = mDateOfLeaving;
    emsPrintParm.mEmpGender     = getGenderFromEnum(mGender);
    emsPrintParm.mEmpid         = mEmployeeId;
    emsPrintParm.mEmpStatus     = getEmpStatusFromEnum(mEmployeeStatus);
    emsPrintParm.mEmpType       = getTypeFromEnum(mEmployeeType);

    Ems::ExternalAgency mExtAgency = getExtAgency();
    InternDetails sInternDetails  = getInternSpecificDetails();

    string sLeavesAvailed = getEmployeeLeavesAvailed();
    string sLeavesLeft = getEmployeeLeavesLeft();

    emsPrintParm.mEmpAgency = getAgencyFromEnum(mExtAgency);
    emsPrintParm.mEmpBranch = getHiringBranchFromEnum(sInternDetails.mHiringBranch);
    emsPrintParm.mEmpCollege = getHiringCollegeFromEnum(sInternDetails.mHiringCollege);
    emsPrintParm.mEmpNol =  sLeavesLeft;
    emsPrintParm.mEmpNola = sLeavesAvailed;
}