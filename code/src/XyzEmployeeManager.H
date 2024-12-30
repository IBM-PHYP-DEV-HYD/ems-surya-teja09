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
public:
    Edll<XyzEmployeeIF*> ActiveAndInactiveEmpl;
    uint32_t mEmpIdSeriesNum;

public:
    void addEmployee(void);
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
    XyzEmployeeManager();
};

#endif