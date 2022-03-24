#include "Helper.cpp"
#include "Validator.cpp"
using namespace std;


int main(int argc, char **argv)
{
    Validator validator;
    validator.validate_args(argc);
    Helper helper;
    helper.read_reservations(argv[1]);
    helper.write_to_file();
    helper.return_full_path();
    return 0;
}
