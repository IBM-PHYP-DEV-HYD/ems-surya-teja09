#include "XyzEmployeeImpl.H"

/*

XyzEmployeeImpl::XyzEmployeeImpl(string EmpNameParm, string EmpIdParm, uint8_t EmpStatusParm, uint8_t EmpTypeParm, char EmpGenderParm, string DobParm, string DojParm):
          mEmployeeName(EmpNameParm),       
{

}*/

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

void XyzEmployeeImpl::setInternSpecificDetails(InternDetails InternDetailsParm)
{

}

void XyzEmployeeImpl::setExtAgency(ExternalAgency ExtAgencyParm)
{

}

InternDetails XyzEmployeeImpl::getInternSpecificDetails(void)
{
    InternDetails sInternDetails = {COLLEGE_UNDEFINED, UNDEFINED_BRANCH};

    return sInternDetails;
}

ExternalAgency XyzEmployeeImpl::getExtAgency(void)
{
    return (ExternalAgency)AGENCY_UNDEFINED;
}

string XyzEmployeeImpl::getEmployeeId(void)
{
    return mEmployeeId;
}

char XyzEmployeeImpl::getEmployeeGender(void)
{
    return mGender;
}

uint8_t XyzEmployeeImpl::getEmployeeStatus(void)
{
    return mEmployeeStatus;
}

uint8_t XyzEmployeeImpl::getEmployeeType(void)
{
    return mEmployeeType;
}

void XyzEmployeeImpl::printEmpSpecificHeader(void)
{

}

void XyzEmployeeImpl::printEmpSpecifiDetails(void)
{

}