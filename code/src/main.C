#include "Edll.H"
#include "XyzEmployeeManager.H"

int main()
{
    XyzEmployeeManager sXyzEmpMgr;
    int sMainchoice = 0;
    
    while(1)
    {
        printmainmenu();
        cin >> sMainchoice;

        switch(sMainchoice)
        {
            case ADD_EMPLOYEE: 
            {
                printEmployeeOption();
                int sInput = 0;
                EmpDetails sEmpDetails;
                while(!(cin >> sInput))
                {
                    cout << "Enter valid choice: " << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');        
                }
                if(sInput == RANDOM)
                {
                    sEmpDetails.mEmpType = getRandomNumber(1,3);
                }

                getRandomizedEmpBasicDetails(&sEmpDetails, sXyzEmpMgr.mEmpCount);

                if(sInput == USER_DEFINED)
                {
                    cout << "Enter Employee Type : 1. Full Time  2. Contract  3. Intern" << endl;
                    cin >> sEmpDetails.mEmpType;

                    cout << "Enter Emp Name: " << endl;
                    cin >> sEmpDetails.mEmpName;

                    cout << "Enter Emp Gender: 1. Male 2. Female " << endl;
                    cin >> sEmpDetails.mGender; 
                } 

                sXyzEmpMgr.addEmployee(sEmpDetails);
                break;
            }
            case REMOVE_EMPLOYEE:
            {
                std::string sEmpId;
                cout << "Enter empid : " << endl;
                std::cin >> sEmpId;
                sXyzEmpMgr.removeEmployee(sEmpId);
                break;
            }
            case PRINT_EMPLOYEE:
            {
                printEmployeedetailsMenu();
                int sEmpFilterType = 0, sEmpFilterValue;

                while(!(cin >> sEmpFilterType))
                {
                    cout << "Enter valid choice: " << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');        
                }
                switch(sEmpFilterType)
                {
                    case TYPE: 
                    {
                        cout << "Enter Employee type : " << endl << "1. FullTime \n" << "2. Contract \n" "3. Intern \n" << endl;
                        cin >> sEmpFilterValue;
                        break;
                    }
                    case GENDER: 
                    {
                        cout << "Enter Employee type : " << endl << "1. Male \n" << "2. Female \n"<< endl;
                        cin >> sEmpFilterValue;
                        break;
                    }
                    case STATUS: 
                    {
                        cout << "Enter Employee type : " << endl << "1. Active \n" << "2. Inactive \n"<< endl;
                        cin >> sEmpFilterValue;
                        break;
                    }  
                }
                sXyzEmpMgr.printEmployeeDetails(sEmpFilterType, sEmpFilterValue);
                break;
            }
            case OTHERS:
            {
                printEmployeeOtherdetailsMenu(); 
                int sInput = 0;
                cout << "Enter Input :" << endl;
                cin >> sInput;       
                switch(sInput)
                {
                    case ADD_LEAVES:
                    {
                        int sNoLeaves = 0;
                        cout << "Enter Number of leaves to be added :" << endl;
                        cin >> sNoLeaves;
                        if(sNoLeaves <= 22)
                        {
                            sXyzEmpMgr.addLeaves(sNoLeaves);
                        }
                        else
                        {
                            cout << "Add leaves less than or equal to 22" << endl;
                        }
                        break;
                    }
                    case CONVERT_EMP:
                    {
                        sXyzEmpMgr.makeInternOrContractAsFullTimeEmployees();
                        break;
                    }
                    case EMP_ID_SEARCH:
                    {
                        std::string sEmpId;
                        cout << "Enter empid : " << endl;
                        std::cin >> sEmpId;
                        sXyzEmpMgr.searchEmployeeById(sEmpId);
                        break;
                    }
                    case EMP_NAME_SEARCH:
                    {
                        std::string sEmpName;
                        cout << "Enter Name : " << endl;
                        std::cin >> sEmpName;
                        sXyzEmpMgr.searchEmployeeByName(sEmpName);
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
                //Do Nothing
                break;
            }
        }
    }
    return 0;
}