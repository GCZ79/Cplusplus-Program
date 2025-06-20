#ifndef CLOCKS_H // Guard start to prevent multiple inclusions of this header
#define CLOCKS_H // Define the macro if not already defined

void display12Hour(int hour, int minute, int second);   // 12 Hours Format
void display24Hour(int hour, int minute, int second);   // 24 Hours Format
void displayClocks(int hour, int minute, int second);   // Display both clocks
void displayMenu();                                     // Display menu
void addOneHour(int& hour);                             // Add 1 hour to the time
void addOneMinute(int& hour, int& minute);              // Add 1 minute to the time
void addOneSecond(int& hour, int& minute, int& second); // Add 1 second to the time

#endif // End of include guard