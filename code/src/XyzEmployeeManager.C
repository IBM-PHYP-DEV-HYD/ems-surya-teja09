#include "XyzEmployeeManager.H"
   
XyzEmployeeManager::XyzEmployeeManager()
{
    mEmpCount = 0;
}

void XyzEmployeeManager::pAddFullTimeEmp(EmpDetails empDetailsParm)
{
    XyzEmployeeIF* sXyzEmp = new XyzFullTimeEmployee(empDetailsParm.mEmpName, 
                                                     empDetailsParm.mEmpId, 
                                                     empDetailsParm.mEmpStatus, 
                                                     empDetailsParm.mEmpType, 
                                                     empDetailsParm.mGender, 
                                                     empDetailsParm.mDob, 
                                                     empDetailsParm.mDoj);
    mActiveEmpQueue.pushFront(sXyzEmp);
    ++mEmpCount;
}

void XyzEmployeeManager::pAddContractEmp(EmpDetails empDetailsParm)
{
    XyzEmployeeIF* sXyzEmp = new XyzContractEmployee(empDetailsParm.mEmpName, 
                                                     empDetailsParm.mEmpId, 
                                                     empDetailsParm.mEmpStatus, 
                                                     empDetailsParm.mEmpType, 
                                                     empDetailsParm.mGender, 
                                                     empDetailsParm.mDob, 
                                                     empDetailsParm.mDoj);
    mActiveEmpQueue.pushFront(sXyzEmp);
    ++mEmpCount;
}

void XyzEmployeeManager::pAddInternEmp(EmpDetails empDetailsParm)
{
    XyzEmployeeIF* sXyzEmp = new XyzInternEmployee(empDetailsParm.mEmpName, 
                                                   empDetailsParm.mEmpId, 
                                                   empDetailsParm.mEmpStatus, 
                                                   empDetailsParm.mEmpType, 
                                                   empDetailsParm.mGender, 
                                                   empDetailsParm.mDob, 
                                                   empDetailsParm.mDoj);
    mActiveEmpQueue.pushFront(sXyzEmp);
    ++mEmpCount; 
}

void XyzEmployeeManager::addEmployee(EmpDetails empDetailsParm)
{
    switch(empDetailsParm.mEmpType)
    {
        case FULL_TIME:
        {
            pAddFullTimeEmp(empDetailsParm);
            break;
        }
        case CONTRACT:
        {     
            pAddContractEmp(empDetailsParm);      
            break;
        }
        case INTERN:
        {        
            pAddInternEmp(empDetailsParm);  
            break;
        }
    }
}

void XyzEmployeeManager::addEmptoResignedQueue(Node<XyzEmployeeIF*>* resignedEmpParm)
{
    resignedEmpParm->mdata->setEmployeeStatus(RESIGNED);
    mResignedEmpQueue.pushFront(resignedEmpParm->mdata);
}

void XyzEmployeeManager::removeEmployee(string empIdParm)
{
    int sNodePos = 1;
    Node<XyzEmployeeIF*>* sCurrNode = nullptr;
    sCurrNode = mActiveEmpQueue.mHead;

    while(sCurrNode != NULL)
    {
        if(sCurrNode->mdata->getEmployeeId() == empIdParm)
        {
            addEmptoResignedQueue(sCurrNode);
            mActiveEmpQueue.removeNodeAtParticularPosition(sNodePos);
        }  
        else
        {
            ++sNodePos;
        } 
        sCurrNode = sCurrNode->mNext;
    } 
}

void XyzEmployeeManager::printEmployeesByType(int empTypeParm)
{
    bool sFlag = 0;
    Node<XyzEmployeeIF*>* sCurrNode = nullptr;
    sCurrNode = mActiveEmpQueue.mHead;

    while((sCurrNode != NULL))
    {
        if((sCurrNode->mdata->getEmployeeType() == empTypeParm))
        {
            if(sFlag == 0)
            {
                sCurrNode->mdata->printEmpSpecificHeader();
                sCurrNode->mdata->printEmpSpecificDetails();
                sFlag = 1;
            }
            else
            {
                sCurrNode->mdata->printEmpSpecificDetails();
            }
        }
        sCurrNode = sCurrNode->mNext;
    }    
}

void XyzEmployeeManager::printEmployeesByStatus(int empStatusParm)
{
    bool sFlag = 0;
    Node<XyzEmployeeIF*>* sCurrNode = nullptr;
    sCurrNode = mActiveEmpQueue.mHead;

    while((sCurrNode != NULL) )
    {
        if((sCurrNode->mdata->getEmployeeStatus() == empStatusParm))
        {
            if(sFlag == 0)
            {
                sCurrNode->mdata->printEmployeeSummaryHeader();
                sCurrNode->mdata->printEmployeeSummary();
                sFlag = 1;
            }
            else
            {
                sCurrNode->mdata->printEmployeeSummary();
            }
        }
        sCurrNode = sCurrNode->mNext;
    }    
}

void XyzEmployeeManager::printEmployeesByGender(int empGenderParm)
{
    bool sFlag = 0;
    Node<XyzEmployeeIF*>* sCurrNode = nullptr;
    sCurrNode = mActiveEmpQueue.mHead;

    while((sCurrNode != NULL) )
    {
        if((sCurrNode->mdata->getEmployeeGender() == empGenderParm))
        {
            if(sFlag == 0)
            {
                sCurrNode->mdata->printEmployeeSummaryHeader();
                sCurrNode->mdata->printEmployeeSummary();
                sFlag = 1;
            }
            else
            {
                sCurrNode->mdata->printEmployeeSummary();
            }
        }
        sCurrNode = sCurrNode->mNext;
    }    
} 

void XyzEmployeeManager::printResignedEmployees(void)
{
    Node<XyzEmployeeIF*>* sCurrNode = mResignedEmpQueue.mHead;

    sCurrNode->mdata->printResignedEmployeeSummaryHeader();

    while(sCurrNode != NULL)
    {
        sCurrNode->mdata->prinResignedEmployeeSummary();
        sCurrNode = sCurrNode->mNext;
    }    
}

void XyzEmployeeManager::printEmployeeSummary(void)
{
    Node<XyzEmployeeIF*>* sCurrNode = mActiveEmpQueue.mHead;

    sCurrNode->mdata->printEmployeeSummaryHeader();

    while(sCurrNode != NULL)
    {
        sCurrNode->mdata->printEmployeeSummary();
        sCurrNode = sCurrNode->mNext;
    }    
}

void XyzEmployeeManager::makeInternOrContractAsFullTimeEmployees(void)
{
    //Needs to be implemented
}

void XyzEmployeeManager::addLeaves(int leavesParm)
{
    Node<XyzEmployeeIF*>* sCurrNode = nullptr;
    sCurrNode = mActiveEmpQueue.mHead;

    while(sCurrNode != NULL)
    {
        if((sCurrNode->mdata->getEmployeeType() == FULL_TIME))
        {
            sCurrNode->mdata->addLeavestoFullTimeEmp(leavesParm);
        }  
        sCurrNode = sCurrNode->mNext;
    } 
}

void XyzEmployeeManager::searchEmployeeByName(string empNameParm)
{
    Node<XyzEmployeeIF*>* sCurrNode = nullptr;
    sCurrNode = mActiveEmpQueue.mHead;

    while(sCurrNode != NULL)
    {
        if(sCurrNode->mdata->getEmployeeName() == empNameParm)
        {
            sCurrNode->mdata->printParticularEmployeeSummary();
        }   
        sCurrNode = sCurrNode->mNext;
    } 
}

void XyzEmployeeManager::searchEmployeeById(string empIdParm)
{
    Node<XyzEmployeeIF*>* sCurrNode = nullptr;
    sCurrNode = mActiveEmpQueue.mHead;

    while(sCurrNode != NULL)
    {
        if(sCurrNode->mdata->getEmployeeId() == empIdParm)
        {
            sCurrNode->mdata->printParticularEmployeeSummary();
        }   
        sCurrNode = sCurrNode->mNext;
    } 
}

void XyzEmployeeManager::printEmployeeDetails(int empFilterTypeParm, int empFilterValueParm)
{
    switch(empFilterTypeParm)
    {
        case TYPE: 
        {
            printEmployeesByType(empFilterValueParm);
            break;
        }
        case GENDER: 
        {
            printEmployeesByGender(empFilterValueParm);
            break;
        }
        case STATUS: 
        {
            printEmployeesByStatus(empFilterValueParm);
            break;
        }
        case SUMMARY: 
        {
            printEmployeeSummary();           
            break;
        }  
        case RESIGNED_EMP:
        {
            printResignedEmployees();
            break;
        }      
        default:
        {
            break;
        }
    }
}
