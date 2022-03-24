#include "SeatNumbers.cpp"
#include "stdc++.h"
using namespace std;

class TheatreContainer
{

private:
    bool seats_matrix[10][20];

public:
    
//Initialise all seats as empty
TheatreContainer()
{
        for(int i = 0; i < 10; i++)
            for (int j = 0; j < 20; j++)
                seats_matrix[i][j] = false;
}
    

// Find first Available seat from given row and seat number.
SeatNumbers get_first_available_seat(int starting_row_number, int starting_seat_number) {
        int consecutiveEmptySeats = 0;
        int i, j = 0;
        for(i = starting_row_number; i < 10; i++) {
            for (j = starting_seat_number; j < 20; j++) {
                if (! seats_matrix[i][j]) {
                    consecutiveEmptySeats++;
                    // If seat 1,2,3 and nobody at left
                    if (j < 3 && consecutiveEmptySeats >= j)
                        return  SeatNumbers(i, j);
                    //If gap of three from previous seat
                    else if (consecutiveEmptySeats == 4)
                        return  SeatNumbers(i, j);
                }
                else {
                    consecutiveEmptySeats = 0;
                }
            }
        }
        return SeatNumbers(-1, -1);
    }


//Checks if seats are available for the entire group
 bool are_seats_continuos(int starting_row_number, int starting_seat_number, int tickets_needed) {
        int seat_count = 0;
        for(int i = starting_row_number; i < 10; i++) {
            for(int j = starting_seat_number; j < 20; j++) {
                if (!seats_matrix[i][j])
                    seat_count++;
                else
                    seat_count = 0;
                // Tickets will be given only for same row & booking limit is of 20 tickets
                if (j == 19 && seat_count < tickets_needed)
                    return false;
                else if (seat_count == tickets_needed)
                    return true;
            }
        }
        return false;
    }

    
//Books the tickets and returns vector of seat objects
vector<SeatNumbers> book_tickets(int starting_row_number, int starting_seat_number, int tickets_needed) {
        int seat_count = 0;
        vector<SeatNumbers> booked_tickets;
        for(int i = starting_row_number; i < 10; i++) {
            for (int j = starting_seat_number; j < 20; j++) {
                if (seat_count < tickets_needed)
                {
                    seats_matrix[i][j] = true;
                    booked_tickets.push_back(SeatNumbers(i, j));
                    seat_count++;
                }
                else
                    break;
            }
        }
        return booked_tickets;
    }

    
// Reserves seats for the tickets that are passed, if not possible returns empty vector.
 vector<SeatNumbers> reserve_seats(int tickets_needed) {
        int starting_row_number = 0, starting_seat_number = 0;
        do {
            SeatNumbers first_valid_seat = get_first_available_seat(starting_row_number, starting_seat_number);
            if (first_valid_seat.get_row() == -1) {
                return (vector<SeatNumbers>{});
            }

            if (are_seats_continuos(first_valid_seat.get_row(), first_valid_seat.get_seat(), tickets_needed)) {
                return book_tickets(first_valid_seat.get_row(), first_valid_seat.get_seat(), tickets_needed);
            }
            else {
                starting_row_number = first_valid_seat.get_row();
                starting_seat_number = first_valid_seat.get_seat();

                // Check from Next Row
                if (starting_row_number < 9) {
                    starting_row_number++;
                    starting_seat_number = 0;
                }
                else
                    break;  // break if we've run out of rows AKA run out of seats in the theater
            }
        } while (true);
     return (vector<SeatNumbers>{});
    }
};
