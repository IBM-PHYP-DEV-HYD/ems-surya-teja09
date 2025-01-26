#include "XyzEmployeeImpl.H"


XyzEmployeeImpl::XyzEmployeeImpl(string EmpNameParm, string EmpIdParm, int EmpStatusParm, int EmpTypeParm, int EmpGenderParm, string DobParm, string DojParm): 
    mEmployeeName(EmpNameParm), mEmployeeId(EmpIdParm), mEmployeeStatus(EmpStatusParm), mEmployeeType(EmpTypeParm), mGender(EmpGenderParm), mDateOfBirth(DobParm), mDateOfJoining(DojParm)         
{

}

void XyzEmployeeImpl::setEmployeeBasicDetails(EmpDetails* EmpDetailsParm)
{
    mEmployeeName       = EmpDetailsParm->mEmpName;
    mDateOfBirth        = EmpDetailsParm->mDob;
    mDateOfJoining      = EmpDetailsParm->mDoj;
    mGender             = EmpDetailsParm->mGender;
    mEmployeeStatus     = EmpDetailsParm->mEmpStatus;
    mEmployeeType       = EmpDetailsParm->mEmpType; 
    mEmployeeId         = EmpDetailsParm->mEmpId;
}

void XyzEmployeeImpl::setLeaveDetails(int LeavesAvailedParm)
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

void XyzEmployeeImpl::setEmployeeStatus(int EmployeeStatusParm)
{
    mEmployeeStatus = EmployeeStatusParm;
}

uint8_t XyzEmployeeImpl::getEmployeeStatus(void)
{
    return mEmployeeStatus;
}

string XyzEmployeeImpl::getEmployeeName(void)
{
    return mEmployeeName;
}

uint8_t XyzEmployeeImpl::getEmployeeType(void)
{
    return mEmployeeType;
}

void XyzEmployeeImpl::printEmpSpecificHeader(void)
{

}

void XyzEmployeeImpl::printEmpSpecificDetails(void)
{
    mEmsPrint.mEmpName       = mEmployeeName;
    mEmsPrint.mEmpDob        = mDateOfBirth;
    mEmsPrint.mEmpDoj        = mDateOfJoining;
    mEmsPrint.mEmpGender     = getGenderFromEnum(mGender);
    mEmsPrint.mEmpid         = mEmployeeId;
    mEmsPrint.mEmpStatus     = getEmpStatusFromEnum(mEmployeeStatus);
    mEmsPrint.mEmpType       = getTypeFromEnum(mEmployeeType);
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
         << "| Employee Name     "
         << "| ID        "
         << "| Type             "
         << "| Status         "
         << "| Gender      "
         << "| Date of Birth       "
         << "| Date of Joining    "
         << "| Date of Leaving    |" << endl;
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
         << "| Employee Name     "
         << "| ID        "
         << "| Type             "
         << "| Status         "
         << "| Gender      "
         << "| Date of Birth       "
         << "| Date of Joining    "
         << "| Date of Leaving    "
         << "| Leaves Availed      "
         << "| Leaves Left     " 
         << "| Agency          " 
         << "| Hiring College  "
         << "| Hiring Branch    |"<< endl;
    cout << setfill('-') << setw(242) << "-" << endl;
    cout << setfill(' ') << setw(242) << " " << endl;   
}


void XyzEmployeeImpl::printEmployeeSummary(void)
{
    mEmsPrint.mEmpName       = mEmployeeName;
    mEmsPrint.mEmpDob        = mDateOfBirth;
    mEmsPrint.mEmpDoj        = mDateOfJoining;
    mEmsPrint.mEmpGender     = getGenderFromEnum(mGender);
    mEmsPrint.mEmpid         = mEmployeeId;
    mEmsPrint.mEmpStatus     = getEmpStatusFromEnum(mEmployeeStatus);
    mEmsPrint.mEmpType       = getTypeFromEnum(mEmployeeType);

    Ems::ExternalAgency mExtAgency = getExtAgency();
    InternDetails sInternDetails  = getInternSpecificDetails();

    string sLeavesAvailed = getEmployeeLeavesAvailed();
    string sLeavesLeft = getEmployeeLeavesLeft();

    mEmsPrint.mEmpAgency = getAgencyFromEnum(mExtAgency);
    mEmsPrint.mEmpBranch = getHiringBranchFromEnum(sInternDetails.mHiringBranch);
    mEmsPrint.mEmpCollege = getHiringCollegeFromEnum(sInternDetails.mHiringCollege);
    mEmsPrint.mEmpNol =  sLeavesLeft;

    mEmsPrint.mPrintAllVar = true;
    mEmsPrint.printAll();
    mEmsPrint.mPrintAllVar = false;
}