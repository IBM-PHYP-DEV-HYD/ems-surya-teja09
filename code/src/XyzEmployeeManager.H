#ifndef XYZEMPLOYEEMANAGER_H
#define XYZEMPLOYEEMANAGER_H

#include "Utilis.H"
#include "Edll.H"
#include "XyzEmployeeIF.H"
#include "XyzFullTimeEmployee.H"
#include "XyzContractEmployee.H"
#include "XyzInternEmployee.H"
#include "string.h"

using namespace std;

class XyzEmployeeManager
{  
protected:
    Edll<XyzEmployeeIF*> mActiveEmpQueue;
    Edll<XyzEmployeeIF*> mResignedEmpQueue;
    uint32_t mEmpCount;

public:
    
    void addEmployee(int UserInputParm);
    void removeEmployee(string EmpIdParm);
    void printResignedEmployees(void);
    void printEmployeesByType(int EmpTypeParm);
    void printEmployeesByStatus(int EmpStatusParm);
    void printEmployeesByGender(int EmpGenderParm);
    void printEmployeeSummary(void);
    void makeInternOrContractAsFullTimeEmployees(void);
    void addLeaves(void);
    void searchEmployeeByName(void);
    void searchEmployeeById(void);
    void printEmployeeDetails(int UserInputParm);
    void printParticularEmployeeSummary(void);
    XyzEmployeeManager();
};

#endif