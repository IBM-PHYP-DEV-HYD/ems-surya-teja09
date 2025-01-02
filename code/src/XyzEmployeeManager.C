#include "XyzEmployeeManager.H"
   
XyzEmployeeManager::XyzEmployeeManager()
{
    
    mEmpIdSeriesNum = 0;
}

void XyzEmployeeManager::addEmployee(void)
{
    unsigned int sEmpType = 0;

    cout << "choose the type of employee needed to be added 1: FullTime 2: Contract 3: Intern " << endl;

    while(!(cin >> sEmpType))
    {
        cout << "Enter valid choice: " << endl;
        cin.clear();
        cin.ignore(1000, '\n');        
    }

    switch(sEmpType)
    {
        case FULL_TIME:
        {
            XyzEmployeeIF* sXyzEmp = new XyzFullTimeEmployee();

            EmpDetails sEmpDetails;

            sEmpDetails.mEmpType = (uint8_t)FULL_TIME;
            getRandomizedEmpBasicDetails(&sEmpDetails, mEmpIdSeriesNum);
            sXyzEmp->setEmployeeBasicDetails(&sEmpDetails);

            int sNumLeaves = 0;
            sNumLeaves = getRandomNumber(1, 22);
            //cout << sNumLeaves << endl;
            sXyzEmp->setLeaveDetails(sNumLeaves);
 
            ActiveAndInactiveEmpl.pushFront(sXyzEmp);

            ++mEmpIdSeriesNum;
            break;
        }
        case CONTRACT:
        {
            XyzEmployeeIF* sXyzEmp = new XyzContractEmployee();

            EmpDetails sEmpDetails;
            sEmpDetails.mEmpType = (uint8_t)CONTRACT;
            getRandomizedEmpBasicDetails(&sEmpDetails, mEmpIdSeriesNum);
            sXyzEmp->setEmployeeBasicDetails(&sEmpDetails);

            int sExtAgency = getRandomizedEmployeeAgency();
            sXyzEmp->setExtAgency(sExtAgency);

            ActiveAndInactiveEmpl.pushFront(sXyzEmp);

            ++mEmpIdSeriesNum;           
            break;
        }
        case INTERN:
        {
            XyzEmployeeIF* sXyzEmp = new XyzInternEmployee();

            EmpDetails sEmpDetails;

            sEmpDetails.mEmpType = (uint8_t)INTERN;
            getRandomizedEmpBasicDetails(&sEmpDetails, mEmpIdSeriesNum);
            sXyzEmp->setEmployeeBasicDetails(&sEmpDetails);

            InternDetails sInternDetails;
            getRandomizedInternDetails(&sInternDetails);
            sXyzEmp->setInternSpecificDetails(sInternDetails);

            ActiveAndInactiveEmpl.pushFront(sXyzEmp);

            ++mEmpIdSeriesNum;           
            break;
        }
        default:
        {
            cout << "Current size of queue is :" << ActiveAndInactiveEmpl.getSize() << endl;
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
    sCurrNode = ActiveAndInactiveEmpl.mHead;

    while(sCurrNode != NULL)
    {
        if(sCurrNode->mdata->getEmployeeId() == sEmpId)
        {
            cout << ActiveAndInactiveEmpl.getSize() << ":" << sNodePos;
            cout << "step 3" << endl;
            cout << "Id Found : " << sCurrNode->mdata->getEmployeeId();
            //cout << ActiveAndInactiveEmpl.getSize() << ":" << sNodePos;
            ActiveAndInactiveEmpl.removeNodeAtParticularPosition(sNodePos);
        }  
        else
        {
            ++sNodePos;
            cout << "step 2" << endl;
        } 
        sCurrNode = sCurrNode->mNext;
        cout << "step 1" << endl;
    } 
}

void XyzEmployeeManager::printEmployeesByType(int EmpTypeParm)
{
    bool sFlag = 0;
    Node<XyzEmployeeIF*>* sCurrNode = nullptr;
    sCurrNode = ActiveAndInactiveEmpl.mHead;

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
    sCurrNode = ActiveAndInactiveEmpl.mHead;

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
    sCurrNode = ActiveAndInactiveEmpl.mHead;

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

}

void XyzEmployeeManager::printEmployeeSummary(void)
{
    Node<XyzEmployeeIF*>* sCurrNode = ActiveAndInactiveEmpl.mHead;

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

}

void XyzEmployeeManager::searchEmployeeByName(void)
{

}

void XyzEmployeeManager::searchEmployeeById(void)
{

}

void XyzEmployeeManager::printEmployeeDetails(void)
{
    int sInput = 0;
    printEmployeedetailsMenu();
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