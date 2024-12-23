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

            uint8_t sNumLeaves = 0;
            sNumLeaves = getRandomNumber(1, 22);
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

            ExternalAgency sExtAgency = getRandomizedEmployeeAgency();
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

void XyzEmployeeManager::removeEmployee(string EmpIdParm)
{
    Node<XyzEmployeeIF*>* sCurrNode = nullptr;
    sCurrNode = ActiveAndInactiveEmpl.mHead;

    if(sCurrNode != nullptr)
    {
        cout << "NodeCount: " << ActiveAndInactiveEmpl.getSize() << endl;
        cout << "EmpId:" << sCurrNode->mdata->getEmployeeId() << endl;
    }    
}

void XyzEmployeeManager::printFullTimeEmpoloyees(void)
{
    Node<XyzEmployeeIF*>* sCurrNode = ActiveAndInactiveEmpl.mHead;

    while(sCurrNode != NULL)
    {
        sCurrNode = sCurrNode->mNext;
    }

}

void XyzEmployeeManager::printContractEmpoloyees(void)
{
    Node<XyzEmployeeIF*>* sCurrNode = ActiveAndInactiveEmpl.mHead;

    while(sCurrNode != NULL)
    {
        sCurrNode = sCurrNode->mNext;
    }
}

void XyzEmployeeManager::printInternEmpoloyees(void)
{
    Node<XyzEmployeeIF*>* sCurrNode = ActiveAndInactiveEmpl.mHead;

    while(sCurrNode != NULL)
    {
        sCurrNode = sCurrNode->mNext;
    }
}

void XyzEmployeeManager::printResignedEmployees(void)
{

}

void XyzEmployeeManager::printEmployeeSummary(void)
{
    Node<XyzEmployeeIF*>* sCurrNode = ActiveAndInactiveEmpl.mHead;

    while(sCurrNode != NULL)
    {
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