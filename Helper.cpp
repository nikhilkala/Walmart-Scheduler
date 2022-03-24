#include "stdc++.h"
#include "TheatreContainer.cpp"
#include <unistd.h>
using namespace std;

int tickets;
string result_file_name = "bookings.txt",reservation;
vector<string> bookings_output;
TheatreContainer theatre;


class Helper
{
public:
// Checks if it is a number
bool is_number(const std::string &s)
{
  return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

    
//Return full path of the output file
void return_full_path()
    {
    char pwd[256];
    getcwd(pwd, 256);
    cout<<"Reservations are in the file:";
    cout<<pwd<<"/"<<result_file_name<<endl;
    }
    
// Creates exceptions for the errors in output file
void create_exception(string exception)
    {
    bookings_output.push_back(exception);
    }
    
    
//Validates each booking request
bool validate_request(string line)
{
    if(line[0]!='R')
    {
        create_exception("Format of Reservation Identifier is Invalid");
        return false;
    }
       
    size_t x =line.find(' ');
    if (x != string::npos)
    {
        string number = line.substr(x+1);
        if(is_number(number))
        {
            reservation = line.substr(0,x);
            tickets = stoi(number);
            if(tickets<=0)
            {
                //call exception class, push that exception to file
                create_exception("Tickets entered should be greater than 0!");
                return false;
            }
        }
        else
        {
            create_exception("Tickets entered should be a number!");
            return false;
        }
    }
    else
    {
        create_exception("Reservation Request must be separated by spaces");
        return false;
    }
    return true;
}


//Adds booking to output vector by taking reservation id and the tickets allocated as parameters
void add_booking_to_output(string reserve_id , vector<string> &seats_allocated)
{
    string output=reserve_id + " ";
    for(int i=0;i<seats_allocated.size(); i++)
    {
        if(i==seats_allocated.size()-1)
            output+=seats_allocated[i];
        else
            output+=seats_allocated[i]+",";
    }
    bookings_output.push_back(output);
}


// Writes the reservations to bookings.txt
void write_to_file()
{
    ofstream outfile (result_file_name);
    if (outfile.is_open())
    {
        for(auto book : bookings_output)
            outfile << book<<endl;
      outfile.close();
    }
}

    
//Sets reservation of selected tickets as CSV for file
void set_seats_csv(vector<SeatNumbers> &reservations) {
    vector<string> seats_allocated;
    for(auto seat_number : reservations)
    {
        seats_allocated.push_back(seat_number.get_ticket());
    }
    add_booking_to_output(reservation, seats_allocated);
}

    
//Uses Theatre object to reserve seats
void make_reservations()
{
    vector<SeatNumbers> reserved_seats = theatre.reserve_seats(tickets);
    if (reserved_seats.size() < tickets) {
        create_exception("Insufficient seats for reservation!");
        return;
    }
    set_seats_csv(reserved_seats);
}


//Reads reservations from file at filepath given in command line argument
void read_reservations(string argv)
{
    string line;
    ifstream infile (argv);
    if (infile.is_open())
    {
      while ( getline (infile,line) )
      {
           if (validate_request(line))
           {
               make_reservations();
           }
          
      }
      infile.close();
    }
    else
    {
        cout<<"File doesn't exist at the path"<<endl;
        exit(-1);
    }
}
};
