# Question 3 — Class Result Processing

## PAC

### Problem
Make a program that processes the results of N students. Every student has 5 subject marks. The program should calculate the average and give the result as Distinction, Pass or Fail. If any subject mark is below 33, the result should be "Fail — Subject Deficiency".

### Analysis
The program takes 5 marks for each student and adds them. The total is divided by 5 to get the average. The average is then checked to decide the result. Before finalizing the result, the program also checks if any subject mark is below 33.

### Conditions
- Each student has 5 marks out of 100.
- Average = Sum of 5 marks / 5.
- Average >= 80 → Distinction.
- Average >= 60 and below 80 → Pass.
- Average below 60 → Fail.
- If any single subject mark is below 33 → Fail — Subject Deficiency.
- Subject deficiency overrides the normal result.

## IPO

### Input
- Number of students
- Five subject marks for each student

### Process
1. Take the number of students.
2. Take 5 marks for each student.
3. Add all 5 marks.
4. Calculate the average.
5. Check if any mark is below 33.
6. If any mark is below 33, result is "Fail — Subject Deficiency".
7. Otherwise, check the average.
8. If average is 80 or above, result is "Distinction".
9. If average is 60 or above but below 80, result is "Pass".
10. Otherwise, result is "Fail".
11. Repeat for all students.

### Output
- Average of each student
- Result of each student
- Distinction
- Pass
- Fail
- Fail — Subject Deficiency
