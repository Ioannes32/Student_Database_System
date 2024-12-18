#include <stdio.h>
#include <string.h>

#define Max_studID 50
#define Max_Stud 200
//Student Database System with C.

void displayMenu(){
    
    printf("\n===== Student Database System =====\n");
    printf("1. Create Student Database\n");
    printf("2. Display Student Database\n");
    printf("3. Find Student by ID\n");
    printf("4. About\n");
    printf("5. Exit\n");

    for(int i = 1; i < 36; i++){
        printf("-");
    }
    printf("\n");
}
//Function to display the about.
void displayAbout(){
    
    printf("\n\n");
    for(int i = 1; i < 56; i++){
        printf("-");
    }
    printf("\n| About: %-45s|\n", " ");
    printf("|%-53s|\n", " ");
    printf("| This is a simple student database system using C. %-2s|\n", " ");
    printf("| It allows you to create, display, %-18s|\n", " ");
    printf("| find and exit the system.%-27s|", " ");
    printf("\n| Developed by: Aloro John Stephen %-19s|\n", " ");
    for(int i = 1; i < 56; i++){
        printf("-");
    }
    printf("\n\n");
}
//Function to create student database
void createData(char studName[Max_Stud][100], char studID[Max_Stud][Max_studID], int size){
        printf("Enter student details:\n");

        for(int i = 0; i < size; i++){  
            printf("Name %d: ", i + 1);
            scanf(" %[^\n]s", studName[i]);
            printf("Student ID for %s: ", studName[i]);
            scanf(" %s", studID[i]);
            printf("\n");
            for (int j = 0; j < i; j++) {
                if (strcmp(studID[j], studID[i]) == 0) {
                    printf("Duplicate ID detected.\nEnter a unique Student ID: ");
                    scanf(" %s", studID[i]);
                    j = -1;
                }
            }

        }
}
//Function to display the created student database
void displayData(char studName[Max_Stud][100], char studID[Max_Stud][Max_studID], int size){
            
    if (size == 0) {
        printf("\nDatabase is empty. Create a database first.\n\n");
        return;
    }
            
    printf("\n\n");
    for(int i = 1; i < 44; i++){
        printf("-");
    }
    printf("\n|%-13s%-27s |\n", " ", "Student Database");
    for(int i = 1; i < 44; i++){
        printf("-");
    }
    printf("\n|%-5s | %-15s | %-15s|", "No.", "Student Name", "Student-ID" );
    printf("\n");
    for(int i = 0; i < size; i++){
        printf("|%-5d | %-15s | %-15s|\n", i + 1, studName[i], studID[i]);
            for (int j = 1; j < 44; j++) {
                    printf("-");
                }
                printf("\n");
    }
    printf("\n");
}
//Function to find student using Unique ID.
void findingDataByID(char studName[Max_Stud][100], char studID[Max_Stud][Max_studID], int size, char searchID[]) {
    if (size == 0) {
        printf("\nDatabase is empty. Create a database first.\n\n");
        return;
    }

    int found = 0; // Track if a student is found
    for (int i = 0; i < size; i++) {
        if (strcmp(studID[i], searchID) == 0) {
            if (!found) {
                printf("\nStudent ID found. Displaying Data...\n\n");
                for (int j = 1; j < 44; j++) printf("-");
                printf("\n| %-5s| %-15s | %-15s|\n", "No.", "Student Name", "Student ID");
                for (int j = 1; j < 44; j++) printf("-");
            }
            printf("\n| %-5d| %-15s | %-15s|\n", i + 1, studName[i], studID[i]);
            for (int j = 1; j < 44; j++) printf("-");
            printf("\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nNo matching record found for Student ID '%s'.\n\n", searchID);
    }
}

//Function to find student using name.
void findingDataByName(char studName[Max_Stud][100], char studID[Max_Stud][Max_studID], int size, char searchName[]) {
    if (size == 0) {
        printf("\nDatabase is empty. Create a database first.\n\n");
        return;
    }

    int found = 0; // Track if a student is found
    for (int i = 0; i < size; i++) {
        if (strcasecmp(studName[i], searchName) == 0) {
            if (!found) {
                printf("\nStudent Name found. Displaying Data...\n\n");
                for (int j = 1; j < 44; j++) printf("-");
                printf("\n| %-5s| %-15s | %-15s|\n", "No.", "Student Name", "Student ID");
                for (int j = 1; j < 44; j++) printf("-");
            }
            printf("\n| %-5d| %-15s | %-15s|\n", i + 1, studName[i], studID[i]);
            for (int j = 1; j < 44; j++) printf("-");
            printf("\n");
            found = 1;
        }
    }

    if (!found) {
        printf("\nNo matching record found for Student Name '%s'.\n\n", searchName);
    }
}


int main(void){
    
    int sysChoice, size = 0;
    char studName[Max_Stud][100];
    char studID[Max_Stud][Max_studID];
    char num[50];

    while (1) {

        displayMenu();

        printf("Enter your choice: ");
        scanf("%d", &sysChoice);
        
        switch (sysChoice){
            case 1:
                printf("\nEnter the number of student (Max: %d): ", Max_Stud);
                scanf("%d", &size);

                if(size > Max_Stud){
                    printf("\nMaximum number of students reached.\n");
                    printf("\nEnter the number of student (Max: %d): ", Max_Stud);
                    scanf("%d", &size);
                }
        
                createData(studName, studID, size);

                printf("\nDatabase created successfully!\n\n");
                break;

            case 2:
                displayData(studName, studID, size);
                break;
            
            case 3:
                printf("\nSearch by:\n1. Student ID\n2. Student Name\nEnter your choice: ");
                int searchChoice;
                scanf("%d", &searchChoice);

                if (searchChoice == 1) {
                    printf("\nEnter the Student ID to find: ");
                        scanf(" %s", num);
                    findingDataByID(studName, studID, size, num);
                }
                else if (searchChoice == 2) {
                    printf("\nEnter the Student Name to find: ");
                    scanf(" %[^\n]s", num);
                    findingDataByName(studName, studID, size, num);
                }
                else {
                    printf("\nInvalid choice. Returning to Menu...\n");
                }
                break;
                
            case 4:
                displayAbout();
                break;
            case 5:
                printf("\nThank you for using this system.\nExiting....");
                return 0;

            default:
                printf("\nInvalid choice.\n");
        }
    }
    
    return 0;
}
