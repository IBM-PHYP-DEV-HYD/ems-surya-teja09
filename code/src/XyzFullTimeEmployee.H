#ifndef XYZFULLTIMEEMPLOYEE_H
#define XYZFULLTIMEEMPLOYEE_H

#include "iostream"
#include "XyzEmployeeImpl.H"

using namespace std;

class XyzFullTimeEmployee : public XyzEmployeeImpl
{
public:
    uint8_t mLeavesAvailed;
    uint8_t mLeavesLeft;

public:
    void setLeaveDetails(void);
    void getLeaveDetails(void);
};

#endif