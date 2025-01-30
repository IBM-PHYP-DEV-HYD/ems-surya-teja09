#include "XyzEmployeeManager.H"
   
XyzEmployeeManager::XyzEmployeeManager()
{

}

void XyzEmployeeManager::pAddFullTimeEmp(EmpDetails empDetailsParm)
{
    XyzEmployeeIF* sXyzEmp = new XyzFullTimeEmployee(empDetailsParm.mEmpName, 
                                                     empDetailsParm.mEmpId, 
                                                     empDetailsParm.mEmpStatus, 
                                                     empDetailsParm.mEmpType, 
                                                     empDetailsParm.mGender, 
                                                     empDetailsParm.mDob, 
                                                     empDetailsParm.mDoj,
                                                     empDetailsParm.mDol,
                                                     empDetailsParm.mLeavesAvailed,
                                                     empDetailsParm.mLeavesLeft);
    mActiveEmpQueue.pushFront(sXyzEmp);
}

void XyzEmployeeManager::pAddContractEmp(EmpDetails empDetailsParm)
{
    XyzEmployeeIF* sXyzEmp = new XyzContractEmployee(empDetailsParm.mEmpName, 
                                                     empDetailsParm.mEmpId, 
                                                     empDetailsParm.mEmpStatus, 
                                                     empDetailsParm.mEmpType, 
                                                     empDetailsParm.mGender, 
                                                     empDetailsParm.mDob, 
                                                     empDetailsParm.mDoj,
                                                     empDetailsParm.mDol,
                                                     empDetailsParm.mExtAgency);
    mActiveEmpQueue.pushFront(sXyzEmp);
}

void XyzEmployeeManager::pAddInternEmp(EmpDetails empDetailsParm)
{
    XyzEmployeeIF* sXyzEmp = new XyzInternEmployee(empDetailsParm.mEmpName, 
                                                   empDetailsParm.mEmpId, 
                                                   empDetailsParm.mEmpStatus, 
                                                   empDetailsParm.mEmpType, 
                                                   empDetailsParm.mGender, 
                                                   empDetailsParm.mDob, 
                                                   empDetailsParm.mDoj,
                                                   empDetailsParm.mDol,
                                                   empDetailsParm.mHiringCollege,
                                                   empDetailsParm.mHiringBranch);
    mActiveEmpQueue.pushFront(sXyzEmp);
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
            if(sCurrNode->mdata->getEmployeeType() == Ems::EmployeeType::FULL_TIME)
            {
                string sDateOfLeaving;
                sDateOfLeaving = getRandomizedDol();
                sCurrNode->mdata->setDateOfLeaving(sDateOfLeaving);
            }
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
    EmsPrintRecord sEmsPrint;
    while((sCurrNode != NULL))
    {
        if((sCurrNode->mdata->getEmployeeType() == empTypeParm))
        {
            if(sFlag == 0)
            {
                sCurrNode->mdata->printEmpSpecificHeader();
                sCurrNode->mdata->fillEmpSpecificDetails(sEmsPrint);
                sEmsPrint.printAll();
                sFlag = 1;
            }
            else
            {
                sCurrNode->mdata->fillEmpSpecificDetails(sEmsPrint);
                sEmsPrint.printAll();
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
    EmsPrintRecord sEmsPrint;
    while((sCurrNode != NULL) )
    {
        if((sCurrNode->mdata->getEmployeeStatus() == empStatusParm))
        {
            if(sFlag == 0)
            {
                sCurrNode->mdata->printEmployeeSummaryHeader();
                sCurrNode->mdata->fillEmployeeSummary(sEmsPrint);
                sEmsPrint.mPrintAllVar = true;
                sEmsPrint.printAll();
                sFlag = 1;
            }
            else
            {
                sCurrNode->mdata->fillEmployeeSummary(sEmsPrint);
                sEmsPrint.mPrintAllVar = true;
                sEmsPrint.printAll();
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
    EmsPrintRecord sEmsPrint;
    while((sCurrNode != NULL) )
    {
        if((sCurrNode->mdata->getEmployeeGender() == empGenderParm))
        {
            if(sFlag == 0)
            {
                sCurrNode->mdata->printEmployeeSummaryHeader();
                sCurrNode->mdata->fillEmployeeSummary(sEmsPrint);
                sEmsPrint.mPrintAllVar = true;
                sEmsPrint.printAll();
                sFlag = 1;
            }
            else
            {
                sCurrNode->mdata->fillEmployeeSummary(sEmsPrint);
                sEmsPrint.mPrintAllVar = true;
                sEmsPrint.printAll();
            }
        }
        sCurrNode = sCurrNode->mNext;
    }    
} 

void XyzEmployeeManager::printResignedEmployees(void)
{
    Node<XyzEmployeeIF*>* sCurrNode = mResignedEmpQueue.mHead;
    EmsPrintRecord sEmsPrint;
    sCurrNode->mdata->printResignedEmployeeSummaryHeader();

    while(sCurrNode != NULL)
    {
        sCurrNode->mdata->prinResignedEmployeeSummary(sEmsPrint);
        sEmsPrint.printAll();
        sCurrNode = sCurrNode->mNext;
    }    
}

void XyzEmployeeManager::printEmployeeSummary(void)
{
    Node<XyzEmployeeIF*>* sCurrNode = mActiveEmpQueue.mHead;
    EmsPrintRecord sEmsPrint;
    sCurrNode->mdata->printEmployeeSummaryHeader();

    while(sCurrNode != NULL)
    {
        sCurrNode->mdata->fillEmployeeSummary(sEmsPrint);
        sEmsPrint.mPrintAllVar = true;
        sEmsPrint.printAll();
        sCurrNode = sCurrNode->mNext;
    }    
}

void XyzEmployeeManager::convertEmptoFullTime(string empIdParm)
{
    Node<XyzEmployeeIF*>* sCurrNode = nullptr;
    sCurrNode = mActiveEmpQueue.mHead;

    while(sCurrNode != NULL)
    {
        if (sCurrNode->mdata->getEmployeeId() == empIdParm) 
        {
            if (sCurrNode->mdata->getEmployeeType() == Ems::EmployeeType::CONTRACT || sCurrNode->mdata->getEmployeeType() == Ems::EmployeeType::INTERN) 
            {
                EmpDetails sEmpDetails;
                sEmpDetails.mEmpName        = sCurrNode->mdata->getEmployeeName();
                sEmpDetails.mEmpId          = getFullTimeEmpId();
                sEmpDetails.mGender         = sCurrNode->mdata->getGender();
                sEmpDetails.mDob            = sCurrNode->mdata->getDateOfBirth();
                sEmpDetails.mDoj            = sCurrNode->mdata->getDateOfJoining();
                sEmpDetails.mEmpStatus      = sCurrNode->mdata->getEmployeeStatus();
                sEmpDetails.mEmpType        = Ems::EmployeeType::FULL_TIME;
                sEmpDetails.mDol            = "NA";
                sEmpDetails.mLeavesAvailed  = 0;
                sEmpDetails.mLeavesLeft      = 22;

                XyzFullTimeEmployee* sFullTimeEmp = new XyzFullTimeEmployee(sEmpDetails.mEmpName, 
                                                                            sEmpDetails.mEmpId, 
                                                                            sEmpDetails.mEmpStatus, 
                                                                            sEmpDetails.mEmpType, 
                                                                            sEmpDetails.mGender, 
                                                                            sEmpDetails.mDob, 
                                                                            sEmpDetails.mDoj,
                                                                            sEmpDetails.mDol,
                                                                            sEmpDetails.mLeavesAvailed,
                                                                            sEmpDetails.mLeavesLeft);

                sCurrNode->mdata = sFullTimeEmp;
            }
        }
        sCurrNode = sCurrNode->mNext;
    }
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
