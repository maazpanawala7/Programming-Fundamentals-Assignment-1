#include <stdio.h>
#include <string.h>

void displayMenu() {
    printf("\n--- Library Menu ---\n");
    printf("1. Register Member\n");
    printf("2. Display Books\n");
    printf("3. Borrow Book\n");
    printf("4. Return Book\n");
    printf("5. Display Member Record\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

void registerMember(char name[], int *studentID, int *memberType) {
    printf("Enter name: ");
    scanf(" %[^\n]s", name);
    printf("Enter student ID: ");
    scanf("%d", studentID);
    printf("Enter membership type (1 for Student, 2 for Faculty): ");
    scanf("%d", memberType);
}

void displayBooks(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks) {
    printf("\nID\t| Title\t\t\t| Copies\n");
    printf("-----------------------------------------\n");
    int i;
    for(i = 0; i < totalBooks; i++) {
        printf("%d\t| %s\t\t| %d\n", bookIDs[i], bookTitles[i], availableCopies[i]);
    }
}

void borrowBook(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks, int borrowedBookIDs[], int *borrowedCount, int memberType) {
    if(*borrowedCount >= 3) {
        printf("Error: Member can borrow a maximum of 3 books at a time.\n");
        return;
    }
    
    int target_id;
    printf("Enter book ID to borrow: ");
    scanf("%d", &target_id);
    
    int found_idx = -1;
    int i;
    for(i = 0; i < totalBooks; i++) {
        if(bookIDs[i] == target_id) {
            found_idx = i;
            break;
        }
    }
    
    if(found_idx == -1) {
        printf("Invalid book ID.\n");
        return;
    }
    
    if(availableCopies[found_idx] <= 0) {
        printf("No copies available for this book.\n");
        return;
    }
    
    int days;
    printf("Enter intended days to keep: ");
    scanf("%d", &days);
    if(days <= 0) {
        printf("Days must be positive.\n");
        return;
    }
    
    borrowedBookIDs[*borrowedCount] = target_id;
    (*borrowedCount)++;
    availableCopies[found_idx]--;
    printf("Book borrowed successfully!\n");
}

float returnBook(int bookIDs[], int availableCopies[], int totalBooks, int borrowedBookIDs[], int *borrowedCount, int memberType, float *totalFine) {
    if(*borrowedCount == 0) {
        printf("No borrowed books to return.\n");
        return 0;
    }
    
    int target_id;
    printf("Enter book ID to return: ");
    scanf("%d", &target_id);
    
    int pos = -1;
    int i;
    for(i = 0; i < *borrowedCount; i++) {
        if(borrowedBookIDs[i] == target_id) {
            pos = i;
            break;
        }
    }
    
    if(pos == -1) {
        printf("Error: You have not borrowed this book.\n");
        return 0;
    }
    
    int actual_days;
    printf("Enter actual days kept: ");
    scanf("%d", &actual_days);
    
    int allowed_days = (memberType == 1) ? 14 : 30;
    float current_fine = 0;
    
    if(actual_days > allowed_days) {
        int extra = actual_days - allowed_days;
        float rate = (memberType == 1) ? 20.0 : 10.0;
        current_fine = extra * rate;
    }
    
    *totalFine += current_fine;
    
    for(i = 0; i < totalBooks; i++) {
        if(bookIDs[i] == target_id) {
            availableCopies[i]++;
            break;
        }
    }
    
    for(i = pos; i < *borrowedCount - 1; i++) {
        borrowedBookIDs[i] = borrowedBookIDs[i + 1];
    }
    (*borrowedCount)--;
    
    printf("Book returned successfully. Fine for this return: Rs. %.2f\n", current_fine);
    return current_fine;
}

void displayMemberRecord(char name[], int studentID, int memberType, int borrowedBookIDs[], int borrowedCount, float totalFine, float fineAfterWaiver) {
    printf("\n--- Member Record ---\n");
    printf("Name: %s\n", name);
    printf("Student ID: %d\n", studentID);
    printf("Membership Type: %s\n", (memberType == 1) ? "Student" : "Faculty");
    printf("Currently Borrowed Book IDs: ");
    int i;
    for(i = 0; i < borrowedCount; i++) {
        printf("%d ", borrowedBookIDs[i]);
    }
    printf("\nTotal Fine Before Waiver: Rs. %.2f\n", totalFine);
    printf("Final Fine Payable After Waiver: Rs. %.2f\n", fineAfterWaiver);
}

int main() {
    int bookIDs[4] = {101, 102, 103, 104};
    char bookTitles[4][50] = {"Programming in C", "Data Structures", "Database Systems", "Computer Networks"};
    int availableCopies[4] = {5, 3, 0, 4};
    int totalBooks = 4;
    
    char name[50] = "Not Registered";
    int studentID = 0;
    int memberType = 1;
    int borrowedBookIDs[3];
    int borrowedCount = 0;
    float totalFine = 0;
    float fineAfterWaiver = 0;
    
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                registerMember(name, &studentID, &memberType);
                break;
            case 2:
                displayBooks(bookIDs, bookTitles, availableCopies, totalBooks);
                break;
            case 3:
                borrowBook(bookIDs, bookTitles, availableCopies, totalBooks, borrowedBookIDs, &borrowedCount, memberType);
                break;
            case 4: {
                float fine = returnBook(bookIDs, availableCopies, totalBooks, borrowedBookIDs, &borrowedCount, memberType, &totalFine);
                char code[20];
                printf("Enter membership code (or type NONE): ");
                scanf("%s", code);
                if(strcmp(code, "LIB2026") == 0) {
                    fineAfterWaiver = totalFine * 0.5;
                    printf("50%% waiver applied successfully!\n");
                } else {
                    fineAfterWaiver = totalFine;
                }
                break;
            }
            case 5:
                displayMemberRecord(name, studentID, memberType, borrowedBookIDs, borrowedCount, totalFine, fineAfterWaiver);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 6);
    
    return 0;
}
