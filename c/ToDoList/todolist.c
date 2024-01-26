#include <stdio.h>

//tasks have an id, description, and isComplete
struct Task {
    int id; 
    char description[50]; 
    int isComplete;
};

//Function declarations: 
//& means address of, * is pointer
void addTask(struct Task tasks[], int *taskCount); 
void viewList(struct Task tasks[], int taskCount); 
void markAsComplete(struct Task tasks[], int taskCount); 
void deleteTask(struct Task tasks[], int *taskCount); 

int taskIDCount = 0; 
int generateUniqueID() {
    return ++taskIDCount;
};

int main() {
    struct Task tasks[50]; //stores all the tasks
    int taskCount = 0; 
    int choice; 

    do {
        //display menu
        printf("\n==== To Do List ====\n");
        printf("1. Add Task\n"); 
        printf("2. View List\n");
        printf("3. Mark as Complete\n");
        printf("4. Delete Task\n");
        printf("5. Exit\n");
        scanf("%d", &choice); 

        switch(choice) {
            case 1:
                addTask(tasks, &taskCount); 
                break;
            case 2:
                viewList(tasks, taskCount); 
                break;
            case 3:
                markAsComplete(tasks, taskCount); 
                break;
            case 4:
                deleteTask(tasks, &taskCount);
                break;
            case 5:
                printf("Exiting now. Goodbye!"); 
                break; 
            default:
                printf("invalid choice. Please enter a valid option.\n");
        }
    } while(choice != 5);

    return 0; 
}

void addTask(struct Task tasks[], int *taskCount) {
    struct Task a;
    a.id = generateUniqueID(); 
    a.isComplete = 0; 
    printf("Input the description of this task\n"); 
    scanf(" %[^\n]", a.description); 
    // printf(a.description); 


    tasks[(*taskCount)++] = a; 
    printf("Successfully added task!"); 
};

void PrintTask(struct Task task) {
    printf("\nTask: %d", task.id);
    printf(", Description: %s", task.description); 
    if(task.isComplete == 0) {
        printf(", Incomplete"); 
    } else {
        printf(", Complete"); 
    }
}

void viewList(struct Task tasks[], int taskCount) {
    for(int i=0; i<taskCount; i++) {
        PrintTask(tasks[i]); 
    }
};

void markAsComplete(struct Task tasks[], int taskCount) {
    int searchedID; 
    printf("Enter the ID of the task you'd like to mark as complete"); 
    scanf("%d", &searchedID); 
    if(tasks[searchedID].isComplete == 1) {
        printf("Task already marked as complete"); 
    } else {
        tasks[searchedID].isComplete = 1; 
    }
};

void deleteTask(struct Task tasks[], int *taskCount) {
    //so you don't actually delete it, you just override it with the one to the right and continue for all and then decrease size by 1
    int removeID; 
    printf("Enter the ID of the task you'd like to remove"); 
    scanf("%d", &removeID);

    for(int i = removeID; i < *taskCount - 1; i++) {
        tasks[i] = tasks[i + 1]; 
    }
    (*taskCount)--; 
};