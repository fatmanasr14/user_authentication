#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

User users[MAX_USERS];
int userCount = 0;

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }

    User newUser;

    printf("Enter username: ");
    scanf("%s", newUser.username);

    // Check if the username already exists
    for (int i = 0; i < userCount; i++) {
        if (strcmp(newUser.username, users[i].username) == 0) {
            printf("Username already exists. Please choose a different username.\n");
            return;
        }
    }

    printf("Enter password: ");
    scanf("%s", newUser.password);

    users[userCount] = newUser;
    userCount++;

    printf("Registration successful.\n");
}

int authenticateUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            return 1; // Authentication successful
        }
    }

    return 0; // Authentication failed
}

int main() {
    int choice;

    do {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (authenticateUser()) {
                    printf("Authentication successful. You are now logged in.\n");
                } else {
                    printf("Authentication failed. Invalid username or password.\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    } while (choice != 3);

    return 0;
}