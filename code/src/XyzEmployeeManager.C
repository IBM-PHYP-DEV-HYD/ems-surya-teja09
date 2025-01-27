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
        case Ems::EmployeeType::FULL_TIME:
        {
            pAddFullTimeEmp(empDetailsParm);
            break;
        }
        case Ems::EmployeeType::CONTRACT:
        {     
            pAddContractEmp(empDetailsParm);      
            break;
        }
        case Ems::EmployeeType::INTERN:
        {        
            pAddInternEmp(empDetailsParm);  
            break;
        }
    }
}

void XyzEmployeeManager::addEmptoResignedQueue(Node<XyzEmployeeIF*>* resignedEmpParm)
{
    resignedEmpParm->mdata->setEmployeeStatus(Ems::EmployeeStatus::RESIGNED);
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

void XyzEmployeeManager::convertEmptoFullTime(string empIdParm)
{
    #if 0
    Node<XyzEmployeeIF*>* sCurrNode = nullptr;
    sCurrNode = mActiveEmpQueue.mHead;

    while(sCurrNode != NULL)
    {
        if (sCurrNode->mdata->getEmployeeId() == empIdParm) 
        {
            if (sCurrNode->mdata->getEmployeeType() == Ems::EmployeeType::CONTRACT || sCurrNode->mdata->getEmployeeType() == Ems::EmployeeType::INTERN) 
            {
                cout << "Found Employee" << endl;
                EmpDetails sEmpDetails = {0};
                sEmpDetails.mEmpName        = sCurrNode->mdata->getEmployeeName();
                sEmpDetails.mEmpId          = sCurrNode->mdata->getEmployeeId();
                sEmpDetails.mGender         = sCurrNode->mdata->getGender();
                sEmpDetails.mDob            = sCurrNode->mdata->getDateOfBirth();
                sEmpDetails.mDoj            = sCurrNode->mdata->getDateOfJoining();
                sEmpDetails.mDol            = sCurrNode->mdata->getDateOfLeaving();
                sEmpDetails.mEmpStatus      = sCurrNode->mdata->getEmployeeStatus();
                sEmpDetails.mEmpType        = Ems::EmployeeType::FULL_TIME;

                XyzEmployeeIF* sFullTimeEmp = new XyzFullTimeEmployee(sEmpDetails.mEmpName, 
                                                            sEmpDetails.mEmpId, 
                                                            sEmpDetails.mEmpStatus, 
                                                            sEmpDetails.mEmpType, 
                                                            sEmpDetails.mGender, 
                                                            sEmpDetails.mDob, 
                                                            sEmpDetails.mDoj);
                cout << "Created Fulltime emp" << endl;
                
                if (sCurrNode->mdata) 
                {
                    cout << "Deleting data" << endl;
                    delete sCurrNode->mdata;
                }
                cout << "Adding fulltime Employee" << endl;
                sCurrNode->mdata = sFullTimeEmp;
            }
        }
        sCurrNode = sCurrNode->mNext;
    }
    #endif
}

void XyzEmployeeManager::addLeaves(int leavesParm)
{
    Node<XyzEmployeeIF*>* sCurrNode = nullptr;
    sCurrNode = mActiveEmpQueue.mHead;

    while(sCurrNode != NULL)
    {
        if((sCurrNode->mdata->getEmployeeType() == Ems::EmployeeType::FULL_TIME))
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
        case Ems::PrintMenu::TYPE: 
        {
            printEmployeesByType(empFilterValueParm);
            break;
        }
        case Ems::PrintMenu::GENDER: 
        {
            printEmployeesByGender(empFilterValueParm);
            break;
        }
        case Ems::PrintMenu::STATUS: 
        {
            printEmployeesByStatus(empFilterValueParm);
            break;
        }
        case Ems::PrintMenu::SUMMARY: 
        {
            printEmployeeSummary();           
            break;
        }  
        case Ems::PrintMenu::RESIGNED_EMP:
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
