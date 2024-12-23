#ifndef XYZFULLTIMEEMPLOYEE_H
#define XYZFULLTIMEEMPLOYEE_H

#include "iostream"
#include "XyzEmployeeImpl.H"

using namespace std;

class XyzFullTimeEmployee : public XyzEmployeeImpl
{
public:
    uint8_t mLeavesAvailed;

public:
    
    void setLeaveDetails(uint8_t LeavesAvailedParm);
    void getLeaveDetails(void);
    //void printDetails(void);
};

#endif