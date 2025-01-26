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

void XyzEmployeeManager::makeInternOrContractAsFullTimeEmployees(void)
{
    #if 0
    string employeeId;
    // Iterate through the queue to find the matching employee
    for (int i = 0; i < mActiveEmpQueue.getSize(); ++i) {
        auto emp = mActiveEmpQueue.getNodeAtPosition(i + 1); // Get node at position

        // Check if the ID matches
        if (emp->mdata->getEmployeeId() == employeeId) {
            // Determine employee type
            if (emp->mdata->getEmployeeType() == CONTRACT || emp->mdata->getEmployeeType() == INTERN) {
                // Extract common details
                string name = emp->mdata->getEmployeeName();
                string id = emp->mdata->getEmployeeId();
                int gender = emp->mdata->getGender();
                string dob = emp->mdata->getDateOfBirth();
                string doj = emp->mdata->getDateOfJoining();
                string dol = emp->mdata->getDateOfLeaving();
                int status = emp->mdata->getEmployeeStatus();

                // Create a new FullTimeEmployee object
                int defaultLeavesAvailed = 0; // Default value for new full-time employees
                int defaultLeavesLeft = 22;   // Assume maximum leaves for full-time employees
                auto fullTimeEmp = new XyzFullTimeEmployee(name, id, gender, dob, status, doj, dol, defaultLeavesAvailed, defaultLeavesLeft);

                // Replace the existing pointer in the queue
                delete emp->mdata; // Clean up the old object
                emp->mdata = fullTimeEmp;

                //cout << "Employee with ID " << employeeId << " converted to Full-Time successfully.\n";
                return;
            } else {
                //cout << "Employee with ID " << employeeId << " is already a Full-Time Employee.\n";
            }
        }
    }
#endif
    //Needs to be implemented
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
