# Parking Lot Manager

## Description

This program simulates a parking lot manager that allows users to perform various actions such as checking the time, advancing the time, showing parking spots, taking a spot, checking the price, leaving a spot, and checking statistics. It is designed to help manage a small parking lot with a simple command-line interface.

## Features

- **Check Time (CT):** Displays the total time the parking lot has been open.
- **Advance Time (AT):** Advances the internal clock by a specified number of minutes or hours and minutes.
- **Show Spots (SS):** Displays open or taken spots, or both.
- **Take Spot (TS):** Assigns a parking spot to a vehicle based on its license plate.
- **Check Price (CP):** Calculates the parking fee for a vehicle based on the time it has been parked.
- **Leave Spot (LS):** Removes a vehicle from a parking spot and calculates the total fee.
- **Check Stats (CS):** Displays total statistics such as total vehicles parked, currently parked vehicles, total amount charged, and average charge per vehicle.
- **Exit Program (EX):** Exits the program.

## Usage

1. **Compile the Program:**
   ```bash
   g++ -o parking_lot_manager parking_lot_manager.cpp

2. **Run the Program:**
   ```bash
   ./parking_lot_manager
3. **Follow the On-Screen Instruction:**
   - The menu will be displayed with the available commands.
   - Enter the command folloed by the required parameters(if any)
  
## Commands
- (CT) Check Time: Displays the total time the parking lot has been open.
  ```bash
  CT
- (AT) Advance Time: Advances the internal clock by the specified minutes or hours and minutes.
  ```bash
  AT [minutes]
  AT [hours] [minutes]
- (SS) Show Spots: Displays open spots (O), taken spots (T), or both (A).
  ```bash
  SS O
  SS T
  SS A
- (TS) Take Spot: Assigns a parking spot to a vehicle.
  ```bash
  TS [row] [column] [plate]
- (CP) Check Price: Calculates the parking fee for a vehicle based on the license plate or spot.
  ```bash
  CP [plate]
  CP [row] [column]
- (LS) Leave Spot: Removes a vehicle from a parking spot based on the license plate or spot.
  ```bash
  LS [plate]
  LS [row] [column]
- (CS) Check Stats: Displays total statistics.
  ```bash
  CS
- (EX) Exit Program: Exits the program.
  ```bash
  EX

## Example
    ```bash
    ----------
    Hello! Welcome to the parking lot manager.
    I'll help you find a spot!
    ----------
    
    ----------
    |  MENU  |
    ----------
    Please use one of the following commands:
      - (CT) check time
      - (AT) advance time
      - (SS) show spots
      - (TS) take spot
      - (CP) check price
      - (LS) leave spot
      - (CS) check stats
      - (EX) exit the program
    
    CT
    We have been open for 0 minutes!
    
    AT 120
    # Advances the time by 120 minutes
    
    TS 1 1 ABC123
    Parked ABC123 in spot 1.
    
    SS O
    Open spots:
    Row 1:  2 3 4 5 6
    Row 2:  7 8 9 10 11 12
    Row 3:  13 14 15 16 17 18
    Row 4:  19 20 21 22 23 24
    
    CP ABC123
    Vehicle ABC123 has been in 1 for 120 minutes.
    It owes $20 at the moment.
    
    LS ABC123
    Vehicle ABC123 left spot 1.
    It was parked there for 120 minutes and paid $20.
    
    CS
    Total vehicles parked: 1
    Vehicles currently parked: 0
    Total amount charged: $20
    Average charge per vehicle: $20
    
    EX
    Goodbye!

## Notes
Notes
- The parking lot is assumed to have a fixed size of 4 rows and 6 columns, totaling 24 spots.
- The parking fee is calculated at a rate of $0.16666666666666666666666666667 per minute for the first 300 minutes. After that, a fixed fee of $50 applies for up to 365 minutes. Beyond 365 minutes, the rate returns to the per-minute calculation with a $10 discount.
- The program uses a simple internal clock to manage time advancement and parking duration calculations.

## License
This project is open-source and available under the MIT License.



