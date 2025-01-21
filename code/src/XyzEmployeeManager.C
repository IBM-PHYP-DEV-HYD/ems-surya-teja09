#include "XyzEmployeeManager.H"
   
XyzEmployeeManager::XyzEmployeeManager()
{
    mEmpCount = 0;
}

void XyzEmployeeManager::pAddFullTimeEmp(void)
{
    EmpDetails sEmpDetails;
    sEmpDetails.mEmpType = (uint8_t)FULL_TIME;
    getRandomizedEmpBasicDetails(&sEmpDetails, mEmpCount);
    XyzEmployeeIF* sXyzEmp = new XyzFullTimeEmployee(sEmpDetails.mEmpName, 
                                                     sEmpDetails.mEmpId, 
                                                     sEmpDetails.mEmpStatus, 
                                                     sEmpDetails.mEmpType, 
                                                     sEmpDetails.mGender, 
                                                     sEmpDetails.mDob, 
                                                     sEmpDetails.mDoj);
    mActiveEmpQueue.pushFront(sXyzEmp);
    ++mEmpCount;
}

void XyzEmployeeManager::pAddContractEmp(void)
{
    EmpDetails sEmpDetails;
    sEmpDetails.mEmpType = (uint8_t)CONTRACT;
    getRandomizedEmpBasicDetails(&sEmpDetails, mEmpCount);
    XyzEmployeeIF* sXyzEmp = new XyzContractEmployee(sEmpDetails.mEmpName, 
                                                     sEmpDetails.mEmpId, 
                                                     sEmpDetails.mEmpStatus, 
                                                     sEmpDetails.mEmpType, 
                                                     sEmpDetails.mGender, 
                                                     sEmpDetails.mDob, 
                                                     sEmpDetails.mDoj);
    mActiveEmpQueue.pushFront(sXyzEmp);
    ++mEmpCount;
}

void XyzEmployeeManager::pAddInternEmp(void)
{
    EmpDetails sEmpDetails;
    sEmpDetails.mEmpType = (uint8_t)INTERN;
    getRandomizedEmpBasicDetails(&sEmpDetails, mEmpCount);
    XyzEmployeeIF* sXyzEmp = new XyzInternEmployee(sEmpDetails.mEmpName, 
                                                   sEmpDetails.mEmpId, 
                                                   sEmpDetails.mEmpStatus, 
                                                   sEmpDetails.mEmpType, 
                                                   sEmpDetails.mGender, 
                                                   sEmpDetails.mDob, 
                                                   sEmpDetails.mDoj);
    mActiveEmpQueue.pushFront(sXyzEmp);
    ++mEmpCount; 
}

void XyzEmployeeManager::addEmployee(int userInputParm)
{
    int sEmpType = 0;
    EmpDetails sEmpDetails;
    switch(userInputParm)
    {
        case RANDOM:
        {
            sEmpType = getRandomNumber(1,3);
            switch(sEmpType)
            {
                case FULL_TIME:
                {
                    pAddFullTimeEmp();
                    break;
                }
                case CONTRACT:
                {     
                    pAddContractEmp();      
                    break;
                }
                case INTERN:
                {        
                    pAddInternEmp();  
                    break;
                }
            }
            break;
        }
        case USER_DEFINED:
        {
            EmpDetails sEmpDetails;
            cout << "Enter Employee Type : 1. Full Time  2. Contract  3. Intern" << endl;
            cin >> sEmpDetails.mEmpType;
            cout << "choosed Emp Type " << sEmpDetails.mEmpType << endl;

            getRandomizedEmpBasicDetails(&sEmpDetails, mEmpCount);

            cout << "Enter Emp Name: " << endl;
            cin >> sEmpDetails.mEmpName;

            cout << "Enter Emp Gender: 1. Male 2. Female " << endl;
            cin >> sEmpDetails.mGender;
            switch(sEmpDetails.mEmpType)
            {
                case FULL_TIME:
                {
                    XyzEmployeeIF* sXyzEmp = new XyzFullTimeEmployee(sEmpDetails.mEmpName, 
                                                                     sEmpDetails.mEmpId, 
                                                                     sEmpDetails.mEmpStatus, 
                                                                     sEmpDetails.mEmpType, 
                                                                     sEmpDetails.mGender, 
                                                                     sEmpDetails.mDob, 
                                                                     sEmpDetails.mDoj);
                    mActiveEmpQueue.pushFront(sXyzEmp);
                    ++mEmpCount;  
                    break;              
                }
                case CONTRACT:
                {
                    XyzEmployeeIF* sXyzEmp = new XyzContractEmployee(sEmpDetails.mEmpName, 
                                                                     sEmpDetails.mEmpId, 
                                                                     sEmpDetails.mEmpStatus, 
                                                                     sEmpDetails.mEmpType, 
                                                                     sEmpDetails.mGender, 
                                                                     sEmpDetails.mDob, 
                                                                     sEmpDetails.mDoj);
                    mActiveEmpQueue.pushFront(sXyzEmp);
                    ++mEmpCount;
                    break;
                }
                case INTERN:
                {
                    XyzEmployeeIF* sXyzEmp = new XyzInternEmployee(sEmpDetails.mEmpName, 
                                                                   sEmpDetails.mEmpId, 
                                                                   sEmpDetails.mEmpStatus, 
                                                                   sEmpDetails.mEmpType, 
                                                                   sEmpDetails.mGender, 
                                                                   sEmpDetails.mDob, 
                                                                   sEmpDetails.mDoj);
                    mActiveEmpQueue.pushFront(sXyzEmp);
                    ++mEmpCount;
                    break;
                }
                default:
                {
                    //Do Nothing
                    break;
                }
            }
            break;
        }
        default:
        {
            cout << "choose correct option" << endl;
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

void XyzEmployeeManager::printEmployeeDetails(int userInputParm)
{
    switch(userInputParm)
    {
        case TYPE: 
        {
            int sInput = 0;
            cout << "Enter Employee type : " << endl << "1. FullTime \n" << "2. Contract \n" "3. Intern \n" << endl;
            cin >> sInput;
            printEmployeesByType(sInput);
            break;
        }
        case GENDER: 
        {
            int sInput = 0;
            cout << "Enter Employee type : " << endl << "1. Male \n" << "2. Female \n"<< endl;
            cin >> sInput;
            printEmployeesByGender(sInput);
            break;
        }
        case STATUS: 
        {
            int sInput = 0;
            cout << "Enter Employee type : " << endl << "1. Active \n" << "2. Inactive \n"<< endl;
            cin >> sInput;
            printEmployeesByStatus(sInput);
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

void XyzEmployeeManager::otherDetails(int inputParm)
{
    switch(inputParm)
    {
        case ADD_LEAVES:
        {
            int sNoLeaves = 0;
            cout << "Enter Number of leaves to be added :" << endl;
            cin >> sNoLeaves;
            if(sNoLeaves <= 22)
            {
                addLeaves(sNoLeaves);
            }
            else
            {
                cout << "Add leaves less than or equal to 22" << endl;
            }
            break;
        }
        case CONVERT_EMP:
        {
            makeInternOrContractAsFullTimeEmployees();
            break;
        }
        case EMP_ID_SEARCH:
        {
            std::string sEmpId;
            cout << "Enter empid : " << endl;
            std::cin >> sEmpId;
            searchEmployeeById(sEmpId);
            break;
        }
        case EMP_NAME_SEARCH:
        {
            std::string sEmpName;
            cout << "Enter Name : " << endl;
            std::cin >> sEmpName;
            searchEmployeeByName(sEmpName);
            break;
        }
        default:
        {
            //Do Nothing
            break;
        }
    }
}