# Programming-Fundamentals-Assignment-1
# Question 1 — Hotel Booking System

## PAC

### Problem
Make a hotel booking system for N guests. For every guest, take the season, room type and number of nights, then calculate the final price. A 15% discount is given if the guest stays for more than 7 nights. At the end, show the total revenue of the hotel.

### Analysis
The program will first take the season and room type and find the correct rate. Then it will multiply the rate by the number of nights. If the guest stays for more than 7 nights, 15% discount will be applied. The final amount will be shown and added to the hotel's total revenue.

### Conditions
- Peak season:
  - Standard = Rs. 5,000 per night
  - Deluxe = Rs. 8,000 per night
  - Suite = Rs. 12,000 per night
- Off-Peak season:
  - Standard = Rs. 3,000 per night
  - Deluxe = Rs. 5,000 per night
  - Suite = Rs. 8,000 per night
- If stay is more than 7 nights, apply 15% discount.
- Total price = (Rate × Nights) − Discount.
- The program processes N guests.

## IPO

### Input
- Number of guests
- Season (Peak or Off-Peak)
- Room type (Standard, Deluxe or Suite)
- Number of nights

### Process
1. Take the number of guests.
2. Take the season, room type and number of nights for each guest.
3. Select the room rate according to season and room type.
4. Calculate the total price.
5. Check if the guest stayed more than 7 nights.
6. Apply 15% discount when required.
7. Calculate the final price.
8. Add the final price to Hotel Total Revenue.
9. Repeat for all guests.

### Output
- Final price for each guest
- Hotel Total Revenue
