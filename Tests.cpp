#include "stdc++.h"
#include <assert.h>
#include "Helper.cpp"
//#include "TheatreContainer.cpp"

using namespace std;
Helper helper;

class Tests
{
public:
    void test_validate_request1()
    {
        assert(helper.validate_request("R0001 4") == true);
        cout<<"Test Case 1: Test validate_request passed (success case)"<<"\xE2\x9C\x93\n";
    }
    
    
    void test_validate_request2()
    {
        assert(helper.validate_request("S0001 4") == false);
        cout<<"Test Case 2: Test validate_request passed (failure case)"<<"\xE2\x9C\x93\n"<<endl;
    }

    
    void test_create_exception1()
    {
        string exception = "ERROR";
        helper.create_exception(exception);
        assert(bookings_output.back() == "ERROR");
        cout<<"Test Case 3: Test create_request passed (failure case)"<<"\xE2\x9C\x93\n";
    }
    
    void test_create_exception2()
    {
        string exception = "ERROR";
        helper.create_exception(exception);
        assert(bookings_output.back() != "ERROR!");
        cout<<"Test Case 3: Test create_request passed (failure case)"<<"\xE2\x9C\x93\n"<<endl;
    }
    
    void test_reserve_seats1()
    {
        TheatreContainer theatre;
        vector<int> inputs = {2,4,4,3};
        string match_string = "J1J2J6J7J8J9J13J14J15J16I1I2I3";
        string test_string="";
        for(int i=0;i<inputs.size();i++)
        {
            auto seats = theatre.reserve_seats(inputs[i]);
            for(auto seat : seats)
            {
                test_string+=seat.get_ticket();
            }
        }
            assert(test_string == match_string);
        cout<<"Test Case 5: Example from Assignment passed(success case)"<<"\xE2\x9C\x93\n";
    }
    
    
    void test_reserve_seats2()
    {
        TheatreContainer theatre;
        vector<int> inputs = {2,4,4,3};
        string match_string = "J1J2J6J7J8J9J13J14J15J16I1I2I4";
        string test_string="";
        for(int i=0;i<inputs.size();i++)
        {
            auto seats = theatre.reserve_seats(inputs[i]);
            for(auto seat : seats)
            {
                test_string+=seat.get_ticket();
            }
        }
            assert(test_string != match_string);
        cout<<"Test Case 6: Example from Assignment passed(failure case)"<<"\xE2\x9C\x93\n"<<endl;
    }
    
    
    void test_reserve_seats3()
    {
        TheatreContainer theatre;
        vector<int> inputs = {4,3,2,4,4,3,2,4,4,3,1};
        string match_string = "J1J2J3J4J8J9J10J14J15I1I2I3I4I8I9I10I11I15I16I17J19J20H1H2H3H4H8H9H10H11H15H16H17G1";
        string test_string="";
        for(int i=0;i<inputs.size();i++)
        {
            auto seats = theatre.reserve_seats(inputs[i]);
            for(auto seat : seats)
            {
                test_string+=seat.get_ticket();
            }
        }
            assert(test_string == match_string);
        cout<<"Test Case 7: Tickets of back row getting assigned after bigger group in front passed(success case)"<<"\xE2\x9C\x93\n";
    }

    
    void test_reserve_seats4()
    {
        TheatreContainer theatre;
        vector<int> inputs = {4,3,2,4,4,3,2,4,4,3,1};
        string match_string = "J1J2J3J4J8J9J10J14J15I1I2I3I4I7I9I10I11I15I16I17J19J20H1H2H3H4H8H9H10H11H15H16H17G1";
        string test_string="";
        for(int i=0;i<inputs.size();i++)
        {
            auto seats = theatre.reserve_seats(inputs[i]);
            for(auto seat : seats)
            {
                test_string+=seat.get_ticket();
            }
        }
            assert(test_string != match_string);
        cout<<"Test Case 8: Tickets of back row getting assigned after bigger group in front passed(failure case)"<<"\xE2\x9C\x93\n"<<endl;
    }
    
    void test_reserve_seats5()
    {
        TheatreContainer theatre;
        vector<int> inputs = {20,20,20,20,20,20,20,20,20,20};
        string match_string = "J1J2J3J4J5J6J7J8J9J10J11J12J13J14J15J16J17J18J19J20I1I2I3I4I5I6I7I8I9I10I11I12I13I14I15I16I17I18I19I20H1H2H3H4H5H6H7H8H9H10H11H12H13H14H15H16H17H18H19H20G1G2G3G4G5G6G7G8G9G10G11G12G13G14G15G16G17G18G19G20F1F2F3F4F5F6F7F8F9F10F11F12F13F14F15F16F17F18F19F20E1E2E3E4E5E6E7E8E9E10E11E12E13E14E15E16E17E18E19E20D1D2D3D4D5D6D7D8D9D10D11D12D13D14D15D16D17D18D19D20C1C2C3C4C5C6C7C8C9C10C11C12C13C14C15C16C17C18C19C20B1B2B3B4B5B6B7B8B9B10B11B12B13B14B15B16B17B18B19B20A1A2A3A4A5A6A7A8A9A10A11A12A13A14A15A16A17A18A19A20";
        string test_string="";
        for(int i=0;i<inputs.size();i++)
        {
            auto seats = theatre.reserve_seats(inputs[i]);
            for(auto seat : seats)
            {
                test_string+=seat.get_ticket();
            }
        }
            assert(test_string == match_string);
        cout<<"Test Case 9: Entire Theatre Full - Groups of exactly 20 passed(success case)"<<"\xE2\x9C\x93\n";
    }
    
    void test_reserve_seats6()
    {
        TheatreContainer theatre;
        vector<int> inputs = {20,20,20,20,20,20,20,20,20,20};
        string match_string = "J1J2J3J4J5J6J7J8J9J10J11J12J13J14J15J16J17J18J19J20I1I2I3I4I5I6I7I8I9I10I11I12I13I14I15I16I17I18I19I20H1H2H3H4H5H6H7H8H9H10H11H12H13H14H15H16H17H18H19H20G1G2G3G4G5G6G7G8G9G10G11G12G13G14G15G16G17G18G19G20F1F2F3F4F5F6F7F8F9F10F11F12F13F14F15F16F17F18F19F20E1E2E3E4E5E6E7E8E9E10E11E12E13E14E15E16E17E18E19E20D1D2D3D4D5D6D7D8D9D10D11D12D13D14D15D16D17D18D19D20C1C2C3C4C5C6C7C8C9C10C11C12C13C14C15C16C17C18C19C20B1B2B3B4B5B6B7B8B9B10B11B12B13B14B15B16B17B18B19B20A1A2A3A4A5A6A7A8A9A10A11A12A13A14A15A16A17A18A19A2";
        string test_string="";
        for(int i=0;i<inputs.size();i++)
        {
            auto seats = theatre.reserve_seats(inputs[i]);
            for(auto seat : seats)
            {
                test_string+=seat.get_ticket();
            }
        }
            assert(test_string != match_string);
        cout<<"Test Case 10: Entire Theatre Full - Groups of exactly 20 passed(failure case)"<<"\xE2\x9C\x93\n"<<endl<<endl;
    }
};
