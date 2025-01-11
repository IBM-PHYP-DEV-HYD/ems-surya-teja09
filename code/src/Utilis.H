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
    AVENGERS                   = 0,
    JUSTICE_LEAUGE             = 1,
    X_MEN                      = 2,
    AGENCY_UNDEFINED           = 3,
};

enum HiringFromColleges
{
    IIT_DELHI                  = 0,
    IIT_MUMBAI                 = 1,
    IIT_HYDERABAD              = 2,
    IIT_KANPUR                 = 3,
    NIT_WARANGAL               = 4,
    NIT_TIRUCHI                = 5,
    IIIT_HYDERABAD             = 6,
    COLLEGE_UNDEFINED          = 7
};

enum HiringFromBranches
{
    CSE               = 0,
    CSIT              = 1,
    ECE               = 2,
    UNDEFINED_BRANCH  = 3
};

enum EmployeeGender
{
    MALE              = 1,
    FEMALE            = 2,
    NA                = 3
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
    int mGender;
    uint8_t mEmpStatus;
    string mEmpId;
    uint8_t mEmpType;
};

enum MAIN_MENU
{
    ADD_EMPLOYEE       = 1,
    REMOVE_EMPLOYEE    = 2,
    PRINT_EMPLOYEE     = 3,
    OTHERS             = 4,
    EXIT               = -1

};

int getRandomNumber(int startNumParm, int endNumParm);
void getRandomizedEmpBasicDetails(EmpDetails* EmpDetailsParm, uint32_t mEmpIdSeriesNumParm);
int getRandomizedEmployeeAgency(void);
void getRandomizedInternDetails(InternDetails *InternDetailsParm);
void printmainmenu(void);
void printEmployeeOption(void);
void printemployeetypemenu(void);
void printEmployeedetailsMenu(void);
void printEmployeeOtherdetailsMenu(void);
void printDeletemenu(void);

#endif