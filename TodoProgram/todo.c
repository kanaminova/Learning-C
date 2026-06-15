#include <stdio.h>
#include <stdlib.h>
#define MAX_TASKS 10

int addTask(char tasks[MAX_TASKS][100], int taskCount);
void viewTasks(char tasks[MAX_TASKS][100], int taskCount);
int removeTask(char tasks[MAX_TASKS][100], int taskCount);
void clearScreen();

int main(){

    char tasks[MAX_TASKS][100];
    char selection[10];
    int taskCount = 0;
    int running = 1;

    while(running){
        clearScreen();

        printf("Whaddya wanna do? :3\n");
        printf("1. Add a task\n");
        printf("2. View tasks\n");
        printf("3. Remove tasks\n");
        printf("4. Exit\n");
        printf("Enter your selection here, okie?: ");
        
        fgets(selection, 10, stdin);

        switch(selection[0]){

            case '1':
                clearScreen();
                taskCount = addTask(tasks, taskCount);
                break;
            case '2':
                clearScreen();
                viewTasks(tasks, taskCount);
                printf("Press enter to continue...");
                fgets(selection, 10, stdin);
                break;
            case '3':
                clearScreen();
                taskCount = removeTask(tasks, taskCount);
                break;
            case '4':
                running = 0;
                break;
            default:
                clearScreen();
                printf("That's not an option!! >:C\n");
                printf("Press enter to continue...");
                fgets(selection, 10, stdin);
                break;
        }

    }

    return 0;

}

int addTask(char tasks[MAX_TASKS][100], int taskCount){
    if(taskCount >= MAX_TASKS){
        printf("Sorry, you've reached the limit for tasks! :C\n");
        return taskCount;
    }
    else{
        printf("What task do yuo want to add? :3\n");
        fgets(tasks[taskCount], 100, stdin);
        int i = 0;
        while(tasks[taskCount][i] != '\0'){
            if(tasks[taskCount][i] == '\n'){
                tasks[taskCount][i] = '\0';
                break;
            }
            i++;
        }
        taskCount++;
    }
    return taskCount;
}

int removeTask(char tasks[MAX_TASKS][100], int taskCount){
    if(taskCount == 0){
        printf("No tasks to remove! :C\n");
        printf("Press enter to continue...");
        getchar();
        return taskCount;
    }

    viewTasks(tasks, taskCount);

    int index;
    printf("\nWhich task do you wanna remove? (1-%d): ", taskCount);
    scanf("%d", &index);

    index--;

    if(index < 0 || index >= taskCount){
        printf("Invalid task number! :C\n");
        printf("Press enter to continue...");
        getchar();
        return taskCount;
    }

    for(int i = index; i < taskCount -1; i++){
        int j = 0;
        while(tasks[i+1][j] != '\0'){
            tasks[i][j] = tasks[i+1][j];
            j++;
        }
        tasks[i][j] = '\0';
    }

    taskCount--;

    printf("Okay, it gone now :3\n");
    printf("Press enter to continue...");
    getchar();
    return taskCount;
}


void viewTasks(char tasks[MAX_TASKS][100], int taskCount){
    if(taskCount == 0){
        printf("No tasks to display! :C\n");
    }
    else{
        printf("Here are your tasks: :3\n");
        for(int i = 0; i < taskCount; i++){
            printf("%d. %s\n", i + 1, tasks[i]);
        }
    }
}

void clearScreen(){
    system("cls");
}
