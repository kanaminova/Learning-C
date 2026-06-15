#include <stdio.h>

int addTask(char tasks[10][100], int taskCount);
void viewTasks(char tasks[10][100], int taskCount);

int main(){

    char tasks[10][100];
    char selection[10];
    int taskCount = 0;
    int running = 1;

    while(running){
        
        printf("Whaddya wanna do? :3\n");
        printf("1. Add a task\n");
        printf("2. View tasks\n");
        printf("3. Exit\n");
        printf("Enter your selection here, okie?: ");
        
        fgets(selection, 10, stdin);

        if(selection[0] == '1'){
            taskCount = addTask(tasks, taskCount);
        }

        if(selection[0] == '2'){
            viewTasks(tasks, taskCount);
        }

        if(selection[0] == '3'){
            running = 0;
        }

    }

    return 0;

}

int addTask(char tasks[10][100], int taskCount){
    if(taskCount >= 10){
        printf("Sorry, you've reached the limit for tasks! :C\n");

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

void viewTasks(char tasks[10][100], int taskCount){
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
