#include "XyzContractEmployee.H"


void XyzContractEmployee::setExtAgency(ExternalAgency ExtAgencyParm)
{
    mExtAgency = ExtAgencyParm;
}

ExternalAgency XyzContractEmployee::getExtAgency(void)
{
    return mExtAgency;
}
