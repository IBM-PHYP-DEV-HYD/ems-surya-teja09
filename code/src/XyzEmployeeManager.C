#include "XyzEmployeeManager.H"
   
XyzEmployeeManager::XyzEmployeeManager()
{
    mEmpIdSeriesNum = 0;
}

void XyzEmployeeManager::pAddEmployeeByType(int EmpTypeParm)
{
    switch(EmpTypeParm)
    {
        case FULL_TIME:
        {
            EmpDetails sEmpDetails;

            sEmpDetails.mEmpType = (uint8_t)FULL_TIME;
            getRandomizedEmpBasicDetails(&sEmpDetails, mEmpIdSeriesNum);

            XyzEmployeeIF* sXyzEmp = new XyzFullTimeEmployee(sEmpDetails.mEmpName, sEmpDetails.mEmpId, sEmpDetails.mEmpStatus, sEmpDetails.mEmpType, sEmpDetails.mGender, sEmpDetails.mDob, sEmpDetails.mDoj);
 
            ActiveAndInactiveEmplObj.pushFront(sXyzEmp);

            ++mEmpIdSeriesNum;
            break;
        }
        case CONTRACT:
        {
            
            EmpDetails sEmpDetails;
            sEmpDetails.mEmpType = (uint8_t)CONTRACT;
            getRandomizedEmpBasicDetails(&sEmpDetails, mEmpIdSeriesNum);

            XyzEmployeeIF* sXyzEmp = new XyzContractEmployee(sEmpDetails.mEmpName, sEmpDetails.mEmpId, sEmpDetails.mEmpStatus, sEmpDetails.mEmpType, sEmpDetails.mGender, sEmpDetails.mDob, sEmpDetails.mDoj);

            ActiveAndInactiveEmplObj.pushFront(sXyzEmp);

            ++mEmpIdSeriesNum;           
            break;
        }
        case INTERN:
        {

            EmpDetails sEmpDetails;

            sEmpDetails.mEmpType = (uint8_t)INTERN;
            getRandomizedEmpBasicDetails(&sEmpDetails, mEmpIdSeriesNum);

            XyzEmployeeIF* sXyzEmp = new XyzInternEmployee(sEmpDetails.mEmpName, sEmpDetails.mEmpId, sEmpDetails.mEmpStatus, sEmpDetails.mEmpType, sEmpDetails.mGender, sEmpDetails.mDob, sEmpDetails.mDoj);

            ActiveAndInactiveEmplObj.pushFront(sXyzEmp);

            ++mEmpIdSeriesNum;           
            break;
        }
        default:
        {
            cout << "Current size of queue is :" << ActiveAndInactiveEmplObj.getSize() << endl;
            break;
        }
    }
}

void XyzEmployeeManager::addEmployee(void)
{
    int sEmpType = 0;
    int sInput = 0;

    while(!(cin >> sInput))
    {
        cout << "Enter valid choice: " << endl;
        cin.clear();
        cin.ignore(1000, '\n');        
    }    

    switch(sInput)
    {
        case 1:
        {
            sEmpType = getRandomNumber(1,3);
            pAddEmployeeByType(sEmpType);
            break;
        }
        case 2:
        {
            cout << "choose the type of employee needed to be added 1: FullTime 2: Contract 3: Intern " << endl;

            while(!(cin >> sEmpType))
            {
                cout << "Enter valid choice: " << endl;
                cin.clear();
                cin.ignore(1000, '\n');        
            }

            pAddEmployeeByType(sEmpType);
            break;
        }
        default:
        {
            cout << "choose correct option" << endl;
            break;
        }
    }
}

void XyzEmployeeManager::removeEmployee(void)
{
    std::string sEmpId;
    cout << "Enter empid : " << endl;
    std::cin >> sEmpId;
    int sNodePos = 1;
    Node<XyzEmployeeIF*>* sCurrNode = nullptr;
    sCurrNode = ActiveAndInactiveEmplObj.mHead;

    while(sCurrNode != NULL)
    {
        if(sCurrNode->mdata->getEmployeeId() == sEmpId)
        {
            ActiveAndInactiveEmplObj.removeNodeAtParticularPosition(sNodePos);
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
    sCurrNode = ActiveAndInactiveEmplObj.mHead;

    while((sCurrNode != NULL))
    {
        if((sCurrNode->mdata->getEmployeeType() == EmpTypeParm))
        {
            if(sFlag == 0)
            {
                sCurrNode->mdata->printEmpSpecificHeader();
                sCurrNode->mdata->printEmpSpecifiDetails();
                sFlag = 1;
            }
            else
            {
                sCurrNode->mdata->printEmpSpecifiDetails();
            }
        }
        sCurrNode = sCurrNode->mNext;
    }    
}

void XyzEmployeeManager::printEmployeesByStatus(int EmpStatusParm)
{
    bool sFlag = 0;
    Node<XyzEmployeeIF*>* sCurrNode = nullptr;
    sCurrNode = ActiveAndInactiveEmplObj.mHead;

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
    sCurrNode = ActiveAndInactiveEmplObj.mHead;

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
    Node<XyzEmployeeIF*>* sCurrNode = ResignedEmplObj.mHead;

    sCurrNode->mdata->printResignedEmployeeSummaryHeader();

    while(sCurrNode != NULL)
    {
        sCurrNode->mdata->prinResignedEmployeeSummary();
        sCurrNode = sCurrNode->mNext;
    }    
}

void XyzEmployeeManager::printEmployeeSummary(void)
{
    Node<XyzEmployeeIF*>* sCurrNode = ActiveAndInactiveEmplObj.mHead;

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
    sCurrNode = ActiveAndInactiveEmplObj.mHead;
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
    sCurrNode = ActiveAndInactiveEmplObj.mHead;

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
    sCurrNode = ActiveAndInactiveEmplObj.mHead;

    while(sCurrNode != NULL)
    {
        if(sCurrNode->mdata->getEmployeeId() == sEmpId)
        {
            printParticularEmployeeSummary();
        }   
        sCurrNode = sCurrNode->mNext;
    } 
}

void XyzEmployeeManager::printEmployeeDetails(void)
{
    int sInput = 0;
    cin >> sInput;
    switch(sInput)
    {
        case 1: 
        {
            int sInput = 0;
            cout << "Enter Employee type : " << endl << "1. FullTime \n" << "2. Contract \n" "3. Intern \n" << endl;
            cin >> sInput;
            printEmployeesByType(sInput);
            break;
        }
        case 2: 
        {
            int sInput = 0;
            cout << "Enter Employee type : " << endl << "1. Male \n" << "2. Female \n"<< endl;
            cin >> sInput;
            printEmployeesByGender(sInput);
            break;
        }
        case 3: 
        {
            int sInput = 0;
            cout << "Enter Employee type : " << endl << "1. Active \n" << "2. Inactive \n"<< endl;
            cin >> sInput;
            printEmployeesByStatus(sInput);
            break;
        }
        case 4: 
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