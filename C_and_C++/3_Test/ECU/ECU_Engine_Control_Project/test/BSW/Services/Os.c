#include "Os.h"
#define TASK_MAX      9u
pthread_t task_id[TASK_MAX];
int task_count;


void Os_Init(void){
    printf("Os Initialize\n");
    task_count = 0;
}

void Os_CreateTask(void* (*function)(void *), const char *taskName){
    
    if(task_count>TASK_MAX){
        printf("Error! Task full can't create thread");
    }

    printf("Create task: %s", taskName);
    /* pthread_create(pthread_t *th, const pthread_attr_t *attr, void *(* func)(void *), void *arg); 

    basiclly this function return a thread id;
    arg1 - address return of thread id 
    arg2 - này là dùng để cấu hình thread (như stack size, detached/joinable ...) không dùng nên điền NULL.
    arg3 -  điền function cần chạy 
    arg4 - tham số truyền vào function
    */
    pthread_create(&task_id[task_count],NULL,function,NULL);
    task_count++;
}

void Os_Delay(int miliTime){
    usleep(miliTime*1000);
}

void Os_Shutdown(void){

    int i;
    for (i = 0; i < task_count; i++)
    {
        /* pthread_join(pthread_t t, void **res);
        function này sẽ run thread từ cái thread id mình truyền vào.
        arg1 - thread mình muốn chạy, điền id của nó vào
        arg2 - này là điền địa chỉ của biến muốn lưu kêt quả trả về của hàm chạy thread.
        */
        pthread_join(task_id[i],NULL);
    }
    printf("Tasks complete. Shut down OS\n");
}

