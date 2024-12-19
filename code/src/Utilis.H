#ifndef UTILIS_H
#define UTILIS_H

#include <iostream>
#include <random>
using namespace std;

enum EmployeeStatus
{
    STATUS_UNDEFINED   = 0,
    ACTIVE             = 1,
    INACTIVE           = 2,
    RESIGNED           = 3
};

enum EmployeeType
{
    TYPE_UNDEFINED     = 0,
    FULL_TIME          = 1,
    CONTRACT           = 2,
    INTERN             = 3
};

enum ExternalAgency
{
    AGENCY_UNDEFINED           = 0,
    AVENGERS                   = 1,
    JUSTICE_LEAUGE             = 2,
    X_MEN                      = 3
};

enum HiringFromColleges
{
    COLLEGE_UNDEFINED          = 0,
    IIT_DELHI                  = 1,
    IIT_MUMBAI                 = 2,
    IIT_HYDERABAD              = 3,
    IIT_KANPUR                 = 4,
    NIT_WARANGAL               = 5,
    NIT_TIRUCHI                = 6,
    IIIT_HYDERABAD             = 7
};

enum HiringFromBranches
{
    UNDEFINED_BRANCH  = 0,
    CSE               = 1,
    CSIT              = 2,
    ECE               = 3
};

#pragma once
struct InternDetails
{
    HiringFromColleges mHiringCollege;
    HiringFromBranches mHiringBranch; 
};

#pragma once
struct EmpDetails
{
    string mEmpName;
    string mDob;
    string mDoj;
    char mGender;
    uint8_t mEmpStatus;
    string mEmpId;
    uint8_t mEmpType;
};

int getRandomNumber(int startNumParm, int endNumParm);
void getRandomizedEmpBasicDetails(EmpDetails* EmpDetailsParm, uint32_t mEmpIdSeriesNumParm);
ExternalAgency getRandomizedEmployeeAgency(void);
void getRandomizedInternDetails(InternDetails *InternDetailsParm);

#endif