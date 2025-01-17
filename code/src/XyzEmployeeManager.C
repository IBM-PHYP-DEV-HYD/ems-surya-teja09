#include "XyzEmployeeManager.H"
   
XyzEmployeeManager::XyzEmployeeManager()
{
    mEmpCount = 0;
}

void XyzEmployeeManager::addEmployee(int UserInputParm)
{
    int sEmpType = 0;
  
    switch(UserInputParm)
    {
        case RANDOM:
        {
            sEmpType = getRandomNumber(1,3);
            switch(sEmpType)
            {
                case FULL_TIME:
                {
                    EmpDetails sEmpDetails;

                    sEmpDetails.mEmpType = (uint8_t)FULL_TIME;
                    getRandomizedEmpBasicDetails(&sEmpDetails, mEmpCount);

                    XyzEmployeeIF* sXyzEmp = new XyzFullTimeEmployee(sEmpDetails.mEmpName, sEmpDetails.mEmpId, sEmpDetails.mEmpStatus, sEmpDetails.mEmpType, sEmpDetails.mGender, sEmpDetails.mDob, sEmpDetails.mDoj);
        
                    mActiveEmpQueue.pushFront(sXyzEmp);

                    ++mEmpCount;
                    break;
                }
                case CONTRACT:
                {
                    
                    EmpDetails sEmpDetails;
                    sEmpDetails.mEmpType = (uint8_t)CONTRACT;
                    getRandomizedEmpBasicDetails(&sEmpDetails, mEmpCount);

                    XyzEmployeeIF* sXyzEmp = new XyzContractEmployee(sEmpDetails.mEmpName, sEmpDetails.mEmpId, sEmpDetails.mEmpStatus, sEmpDetails.mEmpType, sEmpDetails.mGender, sEmpDetails.mDob, sEmpDetails.mDoj);

                    mActiveEmpQueue.pushFront(sXyzEmp);

                    ++mEmpCount;           
                    break;
                }
                case INTERN:
                {
                    EmpDetails sEmpDetails;

                    sEmpDetails.mEmpType = (uint8_t)INTERN;
                    getRandomizedEmpBasicDetails(&sEmpDetails, mEmpCount);

                    XyzEmployeeIF* sXyzEmp = new XyzInternEmployee(sEmpDetails.mEmpName, sEmpDetails.mEmpId, sEmpDetails.mEmpStatus, sEmpDetails.mEmpType, sEmpDetails.mGender, sEmpDetails.mDob, sEmpDetails.mDoj);

                    mActiveEmpQueue.pushFront(sXyzEmp);

                    ++mEmpCount;           
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
                    XyzEmployeeIF* sXyzEmp = new XyzFullTimeEmployee(sEmpDetails.mEmpName, sEmpDetails.mEmpId, sEmpDetails.mEmpStatus, sEmpDetails.mEmpType, sEmpDetails.mGender, sEmpDetails.mDob, sEmpDetails.mDoj);
                    mActiveEmpQueue.pushFront(sXyzEmp);
                    ++mEmpCount;  
                    break;              
                }
                case CONTRACT:
                {
                    XyzEmployeeIF* sXyzEmp = new XyzContractEmployee(sEmpDetails.mEmpName, sEmpDetails.mEmpId, sEmpDetails.mEmpStatus, sEmpDetails.mEmpType, sEmpDetails.mGender, sEmpDetails.mDob, sEmpDetails.mDoj);
                    mActiveEmpQueue.pushFront(sXyzEmp);
                    ++mEmpCount;
                    break;
                }
                case INTERN:
                {
                    XyzEmployeeIF* sXyzEmp = new XyzInternEmployee(sEmpDetails.mEmpName, sEmpDetails.mEmpId, sEmpDetails.mEmpStatus, sEmpDetails.mEmpType, sEmpDetails.mGender, sEmpDetails.mDob, sEmpDetails.mDoj);
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

void XyzEmployeeManager::removeEmployee(string EmpIdParm)
{
    int sNodePos = 1;
    Node<XyzEmployeeIF*>* sCurrNode = nullptr;
    sCurrNode = mActiveEmpQueue.mHead;

    while(sCurrNode != NULL)
    {
        if(sCurrNode->mdata->getEmployeeId() == EmpIdParm)
        {
            mActiveEmpQueue.removeNodeAtParticularPosition(sNodePos);
        }  
        else
        {
            ++sNodePos;
        } 
        sCurrNode = sCurrNode->mNext;
    } 
}

void XyzEmployeeManager::printEmployeesByType(int EmpTypeParm)
{
    bool sFlag = 0;
    Node<XyzEmployeeIF*>* sCurrNode = nullptr;
    sCurrNode = mActiveEmpQueue.mHead;

    while((sCurrNode != NULL))
    {
        if((sCurrNode->mdata->getEmployeeType() == EmpTypeParm))
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

void XyzEmployeeManager::printEmployeesByStatus(int EmpStatusParm)
{
    bool sFlag = 0;
    Node<XyzEmployeeIF*>* sCurrNode = nullptr;
    sCurrNode = mActiveEmpQueue.mHead;

    while((sCurrNode != NULL) )
    {
        if((sCurrNode->mdata->getEmployeeStatus() == EmpStatusParm))
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

void XyzEmployeeManager::printEmployeesByGender(int EmpGenderParm)
{
    bool sFlag = 0;
    Node<XyzEmployeeIF*>* sCurrNode = nullptr;
    sCurrNode = mActiveEmpQueue.mHead;

    while((sCurrNode != NULL) )
    {
        if((sCurrNode->mdata->getEmployeeGender() == EmpGenderParm))
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

}

void XyzEmployeeManager::addLeaves(void)
{
    int sNoLeaves = 0;
    Node<XyzEmployeeIF*>* sCurrNode = nullptr;
    sCurrNode = mActiveEmpQueue.mHead;
    cout << "Enter Number of leaves to be added :" << endl;
    cin >> sNoLeaves;

    while(sCurrNode != NULL)
    {
        if((sCurrNode->mdata->getEmployeeType() == FULL_TIME))
        {
            sCurrNode->mdata->addLeavestoFullTimeEmp(sNoLeaves);
        }  
        sCurrNode = sCurrNode->mNext;
    } 
}

void XyzEmployeeManager::searchEmployeeByName(void)
{
    std::string sEmpName;
    cout << "Enter empid : " << endl;
    std::cin >> sEmpName;
    Node<XyzEmployeeIF*>* sCurrNode = nullptr;
    sCurrNode = mActiveEmpQueue.mHead;

    while(sCurrNode != NULL)
    {
        if(sCurrNode->mdata->getEmployeeId() == sEmpName)
        {
            printParticularEmployeeSummary();
        }   
        sCurrNode = sCurrNode->mNext;
    } 
}

void XyzEmployeeManager::printParticularEmployeeSummary(void)
{
    //Do Nothing
}

void XyzEmployeeManager::searchEmployeeById(void)
{
    std::string sEmpId;
    cout << "Enter empid : " << endl;
    std::cin >> sEmpId;
    Node<XyzEmployeeIF*>* sCurrNode = nullptr;
    sCurrNode = mActiveEmpQueue.mHead;

    while(sCurrNode != NULL)
    {
        if(sCurrNode->mdata->getEmployeeId() == sEmpId)
        {
            printParticularEmployeeSummary();
        }   
        sCurrNode = sCurrNode->mNext;
    } 
}

void XyzEmployeeManager::printEmployeeDetails(int UserInputParm)
{
    switch(UserInputParm)
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
        default:
        {
            break;
        }
    }
}