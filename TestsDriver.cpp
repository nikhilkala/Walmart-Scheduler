#include "Tests.cpp"
using namespace std;

// Tests Driver Function
int main()
{
    Tests test;
    cout<<"Testing Helper Functions"<<endl<<endl;
    sleep(1);
    test.test_validate_request1();
    test.test_validate_request2();
    test.test_create_exception1();
    test.test_create_exception2();
    cout<<"Testing File Outputs"<<endl<<endl;
    sleep(1);
    test.test_reserve_seats1();
    test.test_reserve_seats2();
    test.test_reserve_seats3();
    test.test_reserve_seats4();
    test.test_reserve_seats5();
    test.test_reserve_seats6();
}
