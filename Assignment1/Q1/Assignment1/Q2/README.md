# Question 2 — Elevator Simulation

## PAC

### Problem
Make an elevator simulation that starts from Floor 0 and processes N floor requests one by one. The program should tell whether the elevator is moving up, moving down, or opening its doors.

### Analysis
The elevator starts at Floor 0. For every requested floor, compare it with the current floor. If the requested floor is higher, print "Moving Up". If it is lower, print "Moving Down". If both floors are the same, print "Doors Opening". Then update the current floor.

### Conditions
- Elevator starts at Floor 0.
- Process N floor requests.
- Requested floor > current floor → "Moving Up".
- Requested floor < current floor → "Moving Down".
- Requested floor = current floor → "Doors Opening".
- After every request, current floor becomes the requested floor.

## IPO

### Input
- Number of floor requests
- Requested floor for each request

### Process
1. Set current floor to 0.
2. Take the number of requests.
3. Take one requested floor.
4. Compare it with the current floor.
5. If requested floor is greater, print "Moving Up".
6. If requested floor is smaller, print "Moving Down".
7. If both are equal, print "Doors Opening".
8. Update the current floor.
9. Repeat for all requests.

### Output
- Moving Up
- Moving Down
- Doors Opening
- Updated current floor
