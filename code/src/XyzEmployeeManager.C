#include "XyzEmployeeManager.H"
   
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

            EmpDetails EmpDetailsParm;

            EmpDetailsParm.mEmpType = (uint8_t)FULL_TIME;
            getEmpBasicDetails(&EmpDetailsParm, mEmpIdSeriesNum);
            
            sXyzEmp->setEmployeeBasicDetails(&EmpDetailsParm);
            uint8_t sNumLeaves = getRandomNumber(1, 22);

            ActiveAndInactiveEmpl.pushFront(sXyzEmp);

            ++mEmpIdSeriesNum;
            break;
        }
        case CONTRACT:
        {
            XyzEmployeeIF* sXyzEmp = new XyzContractEmployee();

            EmpDetails EmpDetailsParm;

            EmpDetailsParm.mEmpType = (uint8_t)CONTRACT;
            getEmpBasicDetails(&EmpDetailsParm, mEmpIdSeriesNum);

            sXyzEmp->setEmployeeBasicDetails(&EmpDetailsParm);

            //Add a way to randomly assign hiring agency to contract employee

            ActiveAndInactiveEmpl.pushFront(sXyzEmp);
            ++mEmpIdSeriesNum;           
            break;
        }
        case INTERN:
        {
            XyzEmployeeIF* sXyzEmp = new XyzInternEmployee();

            EmpDetails EmpDetailsParm;

            EmpDetailsParm.mEmpType = (uint8_t)INTERN;
            getEmpBasicDetails(&EmpDetailsParm, mEmpIdSeriesNum);

            sXyzEmp->setEmployeeBasicDetails(&EmpDetailsParm);

            //Add a way to randomly assign hiring college and hiring branch to intern employee

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

}

void XyzEmployeeManager::printFullTimeEmpoloyees(void)
{
    
}

void XyzEmployeeManager::printContractEmpoloyees(void)
{

}

void XyzEmployeeManager::printInternEmpoloyees(void)
{

}

void XyzEmployeeManager::printResignedEmployees(void)
{
 
}

void XyzEmployeeManager::printEmployeeSummary(void)
{

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