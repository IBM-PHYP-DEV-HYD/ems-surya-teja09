#include "Edll.H"
#include "XyzEmployeeManager.H"

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
        XyzEmpMgr.addEmployee();
    return 0;
}