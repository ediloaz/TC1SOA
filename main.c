#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>

sem_t semaphoreLeft;
sem_t semaphoreRigth;
int state = 0;
pthread_t last;
int bridge_size_secs = 5;

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
double ran_expo(double lambda, double current_time)
{
    double u;
    u = rand() / (RAND_MAX + 1.0);
    double exp = -lambda * log(u);
    return exp + current_time;
}

// Main function to simulate the process to pass cars through the bridge
void *thread_simulation(void *direction)
{
    
    const char *directionSymbol;
    if (direction==1) directionSymbol = "Right ➡️"; else directionSymbol = "Left  ⬅️";

    printf("\n%d (%s) Arrived a new car! 🚙💨 \n", pthread_self(), directionSymbol);


    if (state != direction && state != 0) // if there are cars in the opposite direction passing the bridge
    {
        printf("%d (%s) I'll wait because bridge is in use 🔴 \n", pthread_self(), directionSymbol);
        direction == 1 ? sem_wait(&semaphoreRigth) : sem_wait(&semaphoreLeft); // request semaphore
        direction == 1 ? sem_post(&semaphoreRigth) : sem_post(&semaphoreLeft); // release semaphore
        printf("%d (%s) Now is my turn, I'll prepare to pass 🟡 \n", pthread_self(), directionSymbol);
    }
    if (state == 0) // if the bridge is empty
    {
        printf("%d (%s) I'm the fist, I allow the %s direction 🟢 🟢 \n", pthread_self(), directionSymbol, directionSymbol);
        // request both semaphores
        sem_wait(&semaphoreRigth); 
        sem_wait(&semaphoreLeft);
        direction == 1 ? sem_post(&semaphoreRigth) : sem_post(&semaphoreLeft); // release semaphore of same direction
        state = direction;
    }
    else // if the bridge has cars of the same direction
    {
        printf("%d (%s) It's my same direction 🟢 \n", pthread_self(), directionSymbol);
        direction == 1 ? sem_wait(&semaphoreRigth) : sem_wait(&semaphoreLeft); // request semaphore
        direction == 1 ? sem_post(&semaphoreRigth) : sem_post(&semaphoreLeft); // release semaphore
    }
    last = pthread_self(); // update the last
    printf("%d (%s) I'll pass the bridge in a row, and now I'm the last 🟢 \n", pthread_self(), directionSymbol);
    sleep(bridge_size_secs); // pass the bridge
    printf("%d (%s) I passed the bridge 🟢 \n", pthread_self(), directionSymbol);
    if (last == pthread_self()) // validate if I am the last
    {
        state = 0;                                                             // return the bridge to state 0 / empty
        printf("%d (%s) I was the last, the bridge is empty 🟡 \n\n", pthread_self(), directionSymbol);
        direction == 1 ? sem_post(&semaphoreLeft) : sem_post(&semaphoreRigth); // release semaphore of the OTHER direction
    }

    return NULL;
}

int main(int argc, char **argv)
{
    sem_init(&semaphoreRigth, 0, 1);
    sem_init(&semaphoreLeft, 0, 1);

    int right_cars = 3;
    int left_cars = 3;
    int left_lambda = 5;
    int right_lambda = 5;

    //Parameters parsing
    if (argc > 2)
    {
        right_cars = atoi(argv[1]);
        left_cars = atoi(argv[2]);
    }
    if (argc > 4)
    {
        right_lambda = atoi(argv[3]);
        left_lambda = atoi(argv[4]);
    }

    printf("Parameters set at: East cars: %d, West cars: %d, East lambda: %d, West lambda: %d\n", right_cars, left_cars, right_lambda, left_lambda);

    srand(time(NULL));
    pthread_t thread_id;
    printf("Before Thread\n");

    double depart_time_left[left_cars];
    double depart_time_right[right_cars];
    int cars_direction[left_cars + right_cars];
    double depart_time_total[left_cars + right_cars];

    //Define times for left side
    double current_time = 0;
    for (int i = 0; i < left_cars; i++)
    {

        double depart_time = ran_expo(left_lambda, current_time);
        depart_time_left[i] = depart_time;
        current_time = depart_time;
    }

    printf("===================Left Times ============== \n");
    for (int i = 0; i < left_cars; i++)
    {
        printf("Time = %f \n", depart_time_left[i]);
    }

    //Define times for right side
    current_time = 0;
    for (int i = 0; i < right_cars; i++)
    {

        double depart_time = ran_expo(right_lambda, current_time);
        depart_time_right[i] = depart_time;
        current_time = depart_time;
    }

    printf("===================Right Times ============== \n");
    for (int i = 0; i < right_cars; i++)
    {
        printf("Time = %f \n", depart_time_right[i]);
    }

    //Sort both lists
    int aux_left = 0;
    int aux_right = 0;
    aux_right++;

    int i = 0, j = 0, k = 0;
    while (i < left_cars && j < right_cars)
    {
        cars_direction[k] = depart_time_left[i] < depart_time_right[j] ? -1 : 1;
        depart_time_total[k++] = depart_time_left[i] < depart_time_right[j] ? depart_time_left[i++] : depart_time_right[j++];
    }

    while (i < left_cars)
    {
        cars_direction[k] = -1;
        depart_time_total[k++] = depart_time_left[i++];
    }

    while (j < right_cars)
    {
        cars_direction[k] = 1;
        depart_time_total[k++] = depart_time_right[j++];
    }

    printf("===================Total Times and Direction ==============\n");
    for (int i = 0; i < left_cars + right_cars; i++)
    {
        printf("Time = %f Direction = %d \n", depart_time_total[i], cars_direction[i]);
    }

    printf("\n\n ** BEGIN PROCESS TO PASS THE BRIDGE ** \n\n");
    
    i = 0;
    pthread_t pthread;
    while (i < left_cars + right_cars)
    {
        if (i != 0)
        {
            sleep(depart_time_total[i] - depart_time_total[i - 1]);
        }
        pthread_create(&pthread, NULL, thread_simulation, (void *)cars_direction[i]);
        i++;
    }

    i = 0;
    while (i < left_cars + right_cars)
    {
        pthread_join(pthread, NULL);
        i++;
    }
    pthread_exit(0);
}
