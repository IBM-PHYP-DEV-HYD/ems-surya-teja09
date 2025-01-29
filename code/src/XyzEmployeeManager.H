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
    void pAddFullTimeEmp(EmpDetails empDetailsParm);
    void pAddContractEmp(EmpDetails empDetailsParm);
    void pAddInternEmp(EmpDetails empDetailsParm);


public:
    void addEmployee(EmpDetails empDetailsParm);
    void removeEmployee(string EmpIdParm);
    void printResignedEmployees(void);
    void printEmployeesByType(int EmpTypeParm);
    void printEmployeesByStatus(int EmpStatusParm);
    void printEmployeesByGender(int EmpGenderParm);
    void printEmployeeSummary(void);
    void convertEmptoFullTime(string empIdParm);
    void addLeaves(int leavesParm);
    void searchEmployeeByName(string EmpNameParm);
    void searchEmployeeById(string EmpIdParm);
    void printEmployeeDetails(int empFilterTypeParm, int empFilterValueParm);
    //void printParticularEmployeeSummary(void);
    void addEmptoResignedQueue(Node<XyzEmployeeIF*>* ResignedEmpParm);
    XyzEmployeeManager();
};

#endif