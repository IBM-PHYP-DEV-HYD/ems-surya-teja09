#include "XyzInternEmployee.H"

void XyzInternEmployee::setInternSpecificDetails(InternDetails InternDetailsParm)
{
    mHiringCollege = InternDetailsParm.mHiringCollege;
    mHiringBranch = InternDetailsParm.mHiringBranch;
}

InternDetails XyzInternEmployee::getInternSpecificDetails(void)
{
    InternDetails sInternDetailsParm;
    sInternDetailsParm.mHiringCollege = mHiringCollege;
    sInternDetailsParm.mHiringBranch = mHiringBranch;   

    return sInternDetailsParm;
}
