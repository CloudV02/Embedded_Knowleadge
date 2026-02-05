
#include "./BSW/Services/Os.h"

/* void *arg để truyền tham số từ hàm pthread_create */
void *Task_TorqueControl(void *arg){

    // Torque Control Init();

    while (1)
    {
        //Torque Control update;
    }
    
    return NULL; 
}

int main(){
    // khoi tao OS
    OS_Init();

    // Add task
    Os_CreateTask(Task_TorqueControl, "Torque Control");

    // Shut
    Os_Shutdown();
}