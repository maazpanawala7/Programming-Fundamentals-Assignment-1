# Question 4 — Online Shopping Bill Calculator

## PAC

### Problem
Make a Shopping Bill Calculator which takes the quantity purchased, price per item, discount percentage and tax percentage, and calculates the final bill.

### Analysis
First calculate the subtotal by multiplying quantity with price. Then calculate the discounted amount. After that, calculate the final bill by adding tax to the discounted amount. If any entered value is invalid, show an error message and stop the calculation.

### Conditions
- Subtotal = q × p
- Discounted Amount = s − (s × d) / 100
- Final Bill = a + (a × t) / 100
- q = quantity
- p = price per item
- d = discount percentage
- t = tax percentage
- Invalid values should result in an error message and termination.

## IPO

### Input
- Quantity purchased
- Price per item
- Discount percentage
- Tax percentage

### Process
1. Take quantity.
2. Take price per item.
3. Take discount percentage.
4. Take tax percentage.
5. Check whether the entered values are valid.
6. Calculate subtotal.
7. Calculate discounted amount.
8. Calculate tax.
9. Calculate final bill.
10. Store the bill details.
11. Display the final bill.

### Output
- Subtotal
- Discounted amount
- Tax amount
- Final bill
- Error message if an input is invalid
