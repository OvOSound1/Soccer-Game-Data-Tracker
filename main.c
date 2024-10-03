#include <stdio.h>

struct GameData {
    int goals;
    float minutes;
    struct GameData* next;
};

int main() {

    struct GameData* head = NULL;
    struct GameData* current = NULL;
    struct GameData* temp = NULL;
    int gameNumber = 1;
    int totalGoals = 0;
    float totalMinutes = 0.0;

    while (1) {

        int goals;
        printf("Enter the number of goals allowed in game %d (-1 to quit): ", gameNumber);
        scanf("%d", &goals);


        if (goals == -1) {
            break;
        }

        float minutes;
        printf("Enter the minutes played in game %d: ", gameNumber);
        scanf("%f", &minutes);

        temp = (struct GameData*)malloc(sizeof(struct GameData));
        temp->goals = goals;
        temp->minutes = minutes;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            current = temp;
        } else {
            current->next = temp;
            current = temp;
        }

        totalGoals += goals;
        totalMinutes += minutes;

        gameNumber++;
    }

    printf("\nGame  Goals  Minutes\n");

    current = head;
    gameNumber = 1;
    while (current != NULL) {
        printf("%-5d %-6d %-6.1f\n", gameNumber, current->goals, current->minutes);
        current = current->next;
        gameNumber++;
    }

    float goalsAgainstAverage = (float)totalGoals / totalMinutes * 60;
    printf("\nGoals Against Average: %.2f\n", goalsAgainstAverage);

    current = head;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
