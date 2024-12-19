#include "Edll.H"
#include "XyzEmployeeManager.H"

int Loopcount = 0;

int main()
{
#if 0
    Edll<int> Actedll;
    Actedll.pushFront(4);
    Actedll.pushFront(3);
    Actedll.pushFront(1);
    Actedll.print();
    Actedll.addNodeAtParticularPosition(2, 1);
    Actedll.print();
    Actedll.removeNodeAtParticularPosition(4);
    Actedll.print();
#endif
    XyzEmployeeManager XyzEmpMgr;
    while(1)
    {
        XyzEmpMgr.addEmployee();
        Loopcount++;
        if((Loopcount % 5) == 0)
        {
            string empid;
            cout << "Enter EmpID : " << endl;
            cin >> empid;
            XyzEmpMgr.removeEmployee(empid);
        }
    }
        

    return 0;
}