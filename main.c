#include <stdio.h>
#include <string.h>
#include "user.h"

int main()
{
    struct User user1 = {"motaz", "123456", "123456", "14404462", "motaz", "boubaker", "motazboubaker48@gmail.com", "1234567890", "Specialization", 19900101, 0, 1, 5, 1};

     struct User user2 = {"mohamed", "4567898", "4567898", "1425687", "mohamed", "boubaker", "mohamedboubaker48@gmail.com", "1234567890", "Specialization 2", 19900101, 0, 1, 5, 1};

    int x = addUser("user.txt", user1);

    if (x == 1)
        printf("\nUser added successfully");
    else
        printf("\nFailed to add user");

         //x = addUser("user.txt", user2);

    struct User newUser = {"ahmed", "654321", "654321", "14636254", "ahmed", "boubaker", "ahmedboubaker@example.com", "9876543210", "New Specialization", 19851205, 0, 1, 8, 1};


    x = modifyUser("user.txt", "motaz", newUser);
    if (x == 1)
        printf("\nUser modified successfully");
    else
        printf("\nFailed to modify user");

    x = removeUser("user.txt", "motaz");
    if (x == 1)
        printf("\nUser removed successfully");
    else
        printf("\nFailed to remove user");

    struct User foundUser = searchUser("user.txt", "ahmed");
    if (strcmp(foundUser.username, "Not Found") == 0)
        printf("\nUser not found");
    else
        printf("\nUser found: %s", foundUser.username);

    return 0;
}
