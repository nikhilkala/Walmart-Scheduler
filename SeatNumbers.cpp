#include "stdc++.h"
using namespace std;


class SeatNumbers
{
private:
    int row;
    int seat;
    const vector<char> seats= {'J', 'I', 'H', 'G',
        'F', 'E', 'D', 'C', 'B', 'A'};
public:
    //Set Seat's row and column for the Seat object
    SeatNumbers(int row, int seat) {
            this->row = row;
            this->seat = seat;
        }
        //Access row value
        int get_row() {
            return row;
        }
        //Access seat number
        int get_seat() {
            return seat;
        }
        //Returns seat in the format of ticket number, eg: 'A1,'B5'...
        string get_ticket() {
            return (seats[row] + to_string(seat+1));
        }
};
