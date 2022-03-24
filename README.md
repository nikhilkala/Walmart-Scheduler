
# MOVIE THEATER SEATING CHALLENGE - 2020

## Language used: C++

## Program Description:

This program takes an input file containing customer's requests for reserving seats in a movie theater and processes these requests to maximise customer satisfaction and customer safety . This program also takes public safety into account by keeping a buffer of 3 seats and/or a row between two groups of customers. Customer satisfaction is achieved by assigning customers the last available rows and not splitting the groups.

## Assumptions:

1. A good metric for customer satisfaction is that all groups of customers want to be seated as far away from the screen as possible.
2. The rows furthest from the screen give the most customer satisfaction, and it decreases as the seats assigned are closer to the screen.
3. A group of people who are booking the tickets want to be seated together, they won't be split.
4. The reservation requests that arrive first should be handled first. (First Come First Serve)


## Algorithm:

The algorithm takes a Greedy approach by starting the seat assigning process from the first available seat in the farthest row possible and then moving forward.

## Complexity:
All the operations are linear in terms of the array, but since only 200 seats are there, it is O(1) time and O(1) space. 

## Future enhancements:

1. Customers should be able cancel/change their seats.
2. Fitting in as many customers as possible by splitting groups of people when consecutive seats are unavailable.

## Run program:

Step 1 -> Create Executable File
g++ -std=c++20 -o main main.cpp

Step 2 -> Run Executable
./main </path/to/file>

## Run Tests:

Step 1 -> Create Test Executable File
g++ -std=c++20 -o test TestsDriver.cpp

Step 2 -> Run Executable
./test



