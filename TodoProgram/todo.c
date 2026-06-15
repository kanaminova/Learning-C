#include <stdio.h>
#include <stdlib.h>
#define MAX_TASKS 10

int addTask(char tasks[MAX_TASKS][100], int taskCount);
void viewTasks(char tasks[MAX_TASKS][100], int taskCount);
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
        printf("3. Exit\n");
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
                running = 0;
                break;
            default:
                printf("That's not an option!! >:C\n");
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
