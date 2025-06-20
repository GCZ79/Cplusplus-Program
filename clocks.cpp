#include <iostream>            // Load library for cin/cout operations
#include <iomanip>             // Load library for output formatting (setw/fill)
#include "clocks.h"            // Load functions declarations

using namespace std;           // Use operations without std:: prefix

void printTwoDigit(int number) { // Add a 0 in front of single digit entries
    cout << setfill('0') << setw(2) << number; // to mantain correct formatting
}
void printDoubleStarLine() { // Print top/bottom borders for both clocks
    cout << string(23, '*') << " " << string(23, '*') << endl;
}

void printClocksDescr() { // Print the description of the two clocks
    cout << "*    12-Hour Clock    * *    24-Hour Clock    *" << endl;
}

void printStarLineTop() { // Print top border for the menu
    cout << string(23, '*') << "  Chada Tech | ISO 8601" << endl;
}

void printStarLineBottom() { // Print bottom border for the menu
    cout << string(23, '*') << endl;
}

void display12Hour(int hour, int minute, int second) { // **Display time**
    string meridiem = (hour < 12) ? "AM" : "PM"; // Set AM (0/11) or PM (12/23)
    int hour12 = hour % 12; // Use modulo operator to get values between 0/11
    if (hour12 == 0) hour12 = 12; // 0=midnight, 12=noon

    cout << "*     ";           // Print 12-hours clock
    printTwoDigit(hour12);
    cout << ":";
    printTwoDigit(minute);
    cout << ":";
    printTwoDigit(second);
    cout << " " << meridiem;    // Add AM/PM
}

void display24Hour(int hour, int minute, int second) {
    cout << "     * *       ";  // Print 24-hour clock
    printTwoDigit(hour);
    cout << ":";
    printTwoDigit(minute);
    cout << ":";
    printTwoDigit(second);
    cout << "      *" << endl;
}

void displayClocks(int hour, int minute, int second) {  // Display clocks
    printDoubleStarLine(); // Print top border for both clocks
    printClocksDescr(); // Print description of the clocks (12/24 hour)
    // Print time of the two cloks
    display12Hour(hour, minute, second), display24Hour(hour, minute, second);
    printDoubleStarLine(); // Print bottom border for both clocks
}

void displayMenu() { // Display menu
    printStarLineTop(); // Print top border for the menu
    cout << "* 1 - Add One Hour    *\n"; // Case 1 (h)
    cout << "* 2 - Add One Minute  *\n"; // Case 2 (m)
    cout << "* 3 - Add One Second  *\n"; // Case 3 (s)
    cout << "* 4 - Exit Program    *\n"; // Case 4 / Exit
    printStarLineBottom(); // Print bottom border for the menu
    cout << "Enter your choice: "; // User input choice
}

void addOneHour(int& hour) { // Add one hour
    hour = (hour + 1) % 24;
}

void addOneMinute(int& hour, int& minute) { // Add one minute
    minute++;
    if (minute >= 60) {
        minute = 0;
        addOneHour(hour);
    }
}

void addOneSecond(int& hour, int& minute, int& second) { // Add one second
    second++;
    if (second >= 60) {
        second = 0;
        addOneMinute(hour, minute);
    }
}