/*****************************************
 *  Author:      GCZ79                   *
 *  Date:        05-24-2025              *
 *  Description: Chada Tech dual clock   *
 *                                       *
 *****************************************/

#include <iostream>            // Load library for cin/cout operations
#include "clocks.h"            // Load functions declarations
using namespace std;           // Use operations without std:: prefix

int main() {                   // **Start**
    int hour, minute, second;  // Declare variables to setup initial time
    int choice;                // Declare variable to increase time

    // **Get user input for initial time**
    cout << "Enter initial time:" << endl; 
    cout << "Hour (0-23): ";
     cin >> hour;              // Enter initial hour
    cout << "Minute (0-59): ";
     cin >> minute;            // Enter initial minute
    cout << "Second (0-59): ";
     cin >> second;            // Enter initial second

    if (hour < 0 || hour > 23 ||     // Validate h/m/s (format: 0/23 hours,
        minute < 0 || minute > 59 || // 0/59 minutes/seconds)
        second < 0 || second > 59) {
        cout << "Invalid time entered. Exiting." << endl; // Error message
        return 1;                                         // Exit status 1
    }
    // Program/loop runs indefinitely until user selects exit (case 4)
    while (true) {
        displayClocks(hour, minute, second); // **Display time**
        displayMenu();                       // **Display menu**
        cin >> choice;                       // Modify h/m/s (+1)

        switch (choice) {
            case 1: // **Add hour?**
                addOneHour(hour); // Add one hour to clocks
                break;
            case 2: // **Add minute?**
                addOneMinute(hour, minute); // Add one minute to clocks
                break;
            case 3: // **Add second?**
                addOneSecond(hour, minute, second);// Add one second to clocks
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl; // Exit loop/program
                return 0; // **End**
            default: // Handle invalid input (anything != 1/4)
                cout << "Invalid input. Please choose between 1 and 4." << endl;
        }
    }
}
