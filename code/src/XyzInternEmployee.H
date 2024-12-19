#ifndef XYZINTERNEMPLOYEE_H
#define XYZINTERNEMPLOYEE_H

#include "Utilis.H"
#include "XyzEmployeeImpl.H"

class XyzInternEmployee : public XyzEmployeeImpl
{
private:
    HiringFromColleges mHiringCollege;
    HiringFromBranches mHiringBranch; 

public:
    void setInternSpecificDetails(InternDetails InternDetailsParm);
    InternDetails getInternSpecificDetails(void);
    
};

#endif