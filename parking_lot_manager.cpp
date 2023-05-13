#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void print_menu() {
  cout << "----------\n";
  cout << "|  MENU  |\n";
  cout << "----------\n";
  cout << "Please use one of the following commands:\n";
  cout << "  - (CT) check time\n";
  cout << "  - (AT) advance time\n";
  cout << "  - (SS) show spots\n";
  cout << "  - (TS) take spot\n";
  cout << "  - (CP) check price\n";
  cout << "  - (LS) leave spot\n";
  cout << "  - (CS) check stats\n";
  cout << "  - (EX) exit the program\n";
}
int main() {
  string input_command;
  string command;
  string time;
  int spot[24] = {};
  int minute;
  int hour;
  string shour;
  string sminute;
  int total_time = 0;
  bool boolean;
  int rows = 4;
  int columns = 6;
  string TS_row;
  string TS_column;
  string TS_plate;
  int TS_introw;
  int TS_intcolumn;
  int position;
  string plate[24] = {};
  string CP_row;
  string CP_column;
  int CP_introw;
  int CP_intcolumn;
  int clock[24] = {};
  int temp_pos = 0;
  int money;
  string LS_row;
  string LS_column;
  int LS_introw;
  int LS_intcolumn;
  int current_park = 0;
  int total_money = 0;
  int total_car = 0;
  int left_car;
  int glob_time = 0;
  int input1;
  int input2;

  cout << "----------\n";
  cout << "Hello! Welcome to the parking lot manager.\n";
  cout << "I'll help you find a spot!\n";
  cout << "----------\n";
  cout << endl;
  print_menu();
  boolean = false;
  while (boolean != true) {
    cin >> input_command;
    getline(cin, time);
    command = input_command.substr(0, 2);
    time = time.erase(0, 1);
    if (command == "CT") {
      cout << "We have been open for " << glob_time << " minutes!\n";
      cout << endl;
      print_menu();
    } else if (command == "AT") {
      input1 = time.size();                   // 123
      input2 = to_string(stoi(time)).size();  // 123
      if (input1 == input2) {
        // cout << "hi" << endl;
        minute = stoi(time);
        total_time += minute;
        glob_time += minute;
        clock[temp_pos] += total_time;
        total_time = 0;
      } else {
        // cout << "hi1" << endl;
        string delimiter = " ";
        shour = time.substr(0, time.find(delimiter));
        hour = stoi(shour);
        time.erase(0, time.find(delimiter) + delimiter.length());
        sminute = time.substr(0, time.find(delimiter));
        minute = stoi(sminute);
        time.erase(0, time.find(delimiter) + delimiter.length());
        total_time += (hour * 60);
        total_time += minute;
        glob_time += hour * 60;
        glob_time += minute;
        clock[temp_pos] += total_time;

        total_time = 0;
      }
      cout << endl;
      print_menu();
    } else if (command == "SS") {
      if (time == "O") {
        cout << "Open spots:\n";
        for (int row = 0; row < rows; row++) {
          cout << "Row " << row + 1 << ":";
          for (int column = 0; column < columns; column++) {
            if (spot[row * columns + column] == 0) {
              cout << " " << (row * columns + column) + 1;
            }
          }
          cout << endl;
        }
      } else if (time == "T") {
        cout << "Taken spots:\n";
        for (int row = 0; row < rows; row++) {
          cout << "Row " << row + 1 << ":";
          for (int column = 0; column < columns; column++) {
            if (spot[row * columns + column] == 1) {
              cout << " " << (row * columns + column) + 1;
            }
          }
          cout << endl;
        }
      } else if (time == "A") {
        cout << "Open spots:\n";
        for (int row = 0; row < rows; row++) {
          cout << "Row " << row + 1 << ":";
          for (int column = 0; column < columns; column++) {
            if (spot[row * columns + column] == 0) {
              cout << " " << (row * columns + column) + 1;
            }
          }
          cout << endl;
        }
        cout << endl;
        cout << "Taken spots:\n";
        for (int row = 0; row < rows; row++) {
          cout << "Row " << row + 1 << ":";
          for (int column = 0; column < columns; column++) {
            if (spot[row * columns + column] == 1) {
              cout << " " << (row * columns + column) + 1;
            }
          }
          cout << endl;
        }
      }
      cout << endl;
      print_menu();
    } else if (command == "TS") {
      string delimiter = " ";
      TS_row = time.substr(0, time.find(delimiter));
      TS_introw = stoi(TS_row) - 1;
      time.erase(0, time.find(delimiter) + delimiter.length());
      TS_column = time.substr(0, time.find(delimiter));
      TS_intcolumn = stoi(TS_column) - 1;
      time.erase(0, time.find(delimiter) + delimiter.length());
      TS_plate = time.substr(0, time.find(delimiter));
      position = TS_introw * columns + TS_intcolumn;
      if (spot[position] != 1) {
        spot[position] = 1;
        plate[position] = TS_plate;
        temp_pos = position;
        cout << "Parked " << TS_plate << " in spot " << position + 1 << "."
             << endl;
        total_car += 1;
      } else if (position < 23) {
        for (int p = position; p < 24; p++) {
          if (spot[p] != 1) {
            spot[p] = 1;
            plate[p] = TS_plate;
            temp_pos = p;
            cout << "Parked " << TS_plate << " in spot " << p + 1 << "."
                 << endl;
            total_car += 1;
            break;
          } else if (spot[23] == 1) {
            cout << "Sorry, you've passed all the open spots already!\n";
            break;
          }
        }
      } else if (position == 23) {
        if (spot[position] == 1) {
          cout << "Sorry, you've passed all the open spots already!\n";
        }
      }
      cout << endl;
      print_menu();
    } else if (command == "CP") {
      int fix = 300 * (0.16666666666666666666666666667);
      if (time.size() > 3 || time.size() < 3) {  // plate
        for (int i = 0; i < 24; i++) {
          if (time == plate[i]) {
            cout << "Vehicle " << plate[i] << " has been in " << i + 1
                 << " for " << clock[i] << " minutes." << endl;
            money = clock[i] * (0.16666666666666666666666666667);
            if (clock[i] <= 300) {
              cout << "It owes $" << money << " at the moment." << endl;
            } else if (clock[i] >= 301 && clock[i] <= 365) {
              cout << "It owes $" << fix << " at the moment." << endl;
            } else {
              cout << "It owes $" << money - 10 << " at the moment." << endl;
            }
          }
        }
      } else {
        string delimiter = " ";
        CP_row = time.substr(0, time.find(delimiter));
        CP_introw = stoi(CP_row) - 1;
        time.erase(0, time.find(delimiter) + delimiter.length());
        CP_column = time.substr(0, time.find(delimiter));
        CP_intcolumn = stoi(CP_column) - 1;
        time.erase(0, time.find(delimiter) + delimiter.length());
        position = CP_introw * columns + CP_intcolumn;
        cout << "Vehicle " << plate[position] << " has been in " << position + 1
             << " for " << clock[position] << " minutes." << endl;
        money = clock[position] * (0.16666666666666666666666666667);
        if (clock[position] <= 300) {
          cout << "It owes $" << money << " at the moment.\n";
        } else if (clock[position] >= 301 && clock[position] <= 365) {
          cout << "It owes $" << fix << " at the moment." << endl;
        } else {
          cout << "It owes $" << money - 10 << " at the moment.\n";
        }
      }
      cout << endl;
      print_menu();
    } else if (command == "LS") {
      bool dig = false;
      if (isdigit(time[0]) == true) {
        dig = true;
      }
      if (dig == false) {  // plate
        for (int i = 0; i < 24; i++) {
          if (time == plate[i]) {
            money = clock[i] * (0.1666666666666666666666666667);
            cout << "Vehicle " << plate[i] << " left spot " << i + 1 << "."
                 << endl;
            if (clock[i] <= 300) {
              cout << "It was parked there for " << clock[i]
                   << " minutes and paid $" << money << "." << endl;
              total_money += (money);
            } else {
              cout << "It was parked there for " << clock[i]
                   << " minutes and paid $" << money - 10 << "." << endl;
              total_money += (money - 10);
            }
          }
        }
        left_car += 1;
        clock[temp_pos] = 0;
        spot[temp_pos] = 0;
      } else {
        string delimiter = " ";
        LS_row = time.substr(0, time.find(delimiter));
        LS_introw = stoi(LS_row) - 1;
        time.erase(0, time.find(delimiter) + delimiter.length());
        LS_column = time.substr(0, time.find(delimiter));
        LS_intcolumn = stoi(LS_column) - 1;
        time.erase(0, time.find(delimiter) + delimiter.length());
        position = LS_introw * columns + LS_intcolumn;
        money = clock[position] * (0.1666666666666666666666666667);
        cout << "Vehicle " << plate[position] << " left spot " << position + 1
             << "." << endl;
        if (clock[position] <= 300) {
          cout << "It was parked there for " << clock[position]
               << " minutes and paid $" << money << "." << endl;
          total_money += (money);
        } else {
          cout << "It was parked there for " << clock[position]
               << " minutes and paid $" << money - 10 << "." << endl;
          total_money += (money - 10);
        }
        spot[temp_pos] = 0;
        clock[temp_pos] = 0;
        left_car += 1;
      }
      cout << endl;
      print_menu();
    } else if (command == "CS") {
      current_park = 0;
      for (int i = 0; i < 24; i++) {
        if (spot[i] == 1) {
          current_park += 1;
        }
      }
      int final;
      final = total_car - current_park;
      cout << "Total vehicles parked: " << total_car << endl;
      cout << "Vehicles currently parked: " << current_park << endl;
      cout << "Total amount charged: $" << total_money << endl;
      if (final == 0) {
        cout << "Average charge per vehicle: $0" << endl;
      } else {
        cout << "Average charge per vehicle: $" << total_money / final << endl;
      }
      cout << endl;
      print_menu();
    } else if (command == "EX") {
      cout << "Goodbye!" << endl;
      exit(0);
    } else {
      cout << "Sorry, that command is invalid." << endl;
      cout << endl;
      print_menu();
    }
  }
  return 0;
}
