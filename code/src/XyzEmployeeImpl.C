#include "XyzEmployeeImpl.H"


void XyzEmployeeImpl::setEmployeeBasicDetails(EmpDetails* EmpDetailsPar)
{

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

void XyzEmployeeImpl::getEmployeeBasicDetails(void)
{
    
}
