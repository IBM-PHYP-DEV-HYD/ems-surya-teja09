#include "XyzEmployeeImpl.H"


void XyzEmployeeImpl::setEmployeeBasicDetails(EmpDetails* EmpDetailsParm)
{
    mEmployeeName       = EmpDetailsParm->mEmpName;
    mDateOfBirth        = EmpDetailsParm->mDob;
    mDateOfJoining      = EmpDetailsParm->mDoj;
    mGender             = EmpDetailsParm->mGender;
    mEmployeeStatus     = EmpDetailsParm->mEmpStatus;
    mEmployeeType       = EmpDetailsParm->mEmpType; 
}

void XyzEmployeeImpl::setLeaveDetails(uint8_t LeavesAvailedParm)
{
    
}

void XyzEmployeeImpl::setInternSpecificDetails(InternDetails InternDetailsParm)
{

}

void XyzEmployeeImpl::setExtAgency(ExternalAgency ExtAgencyParm)
{

}

void XyzEmployeeImpl::getLeaveDetails(void)
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

