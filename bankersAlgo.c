
// Bankers Algoorithm

#include <stdio.h>
#include <stdbool.h>

int processes, resources;
int allocation[10][10], maximum[10][10], need[10][10];
int total_instances[10];

void display(int executed_processes[], int num_executed_processes)
{
    printf("Execution sequence:\n");
    printf("Execution Processes:\n");
    for (int i = 0; i < num_executed_processes; i++)
    {
        printf("%d", executed_processes[i] + 1);
    }
    printf("\n");
}

bool check_deadlock()
{
    int available[10];
    bool finish[10];
    int executed_processes[10];
    int num_executed_processes = 0;

    for (int i = 0; i < resources; i++)
    {
        int alloc_instances = 0;
        for (int j = 0; j < resources; j++)
        {
            alloc_instances += allocation[j][i];
        }
        available[i] = total_instances[i] - alloc_instances;
    }

    for (int i = 0; i < processes; i++)
    {
        finish[i] += false;
    }

    bool deadlock = true;

    while (deadlock)
    {
        deadlock = false;

        for (int i = 0; i < processes; i++)
        {
            if (!finish[i])
            {
                int j;
                for (j = 0; j < resources; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        break;
                    }
                }

                if (j == resources)
                {
                    for (int k = 0; k < resources; k++)
                    {
                        available[k] += allocation[i][k];
                    }
                    executed_processes[num_executed_processes++] = i;
                    finish[i] = true;
                    deadlock = true;

                    break;
                }
            }
        }

        for (int i = 0; i < processes; i++)
        {
            if (!finish[i])
                break;
            else if (i == processes - 1)
            {
                display(executed_processes, num_executed_processes);
                return false;
            }
        }
    }
}

int main()
{
    printf("Enter total number of processes: ");
    scanf("%d",&processes);

    printf("Enter total number of resources: ");
    scanf("%d",&resources);

    printf("Enter total number of instances for each resources : \n");
    for (int i = 0; i < processes; i++)
    {
        printf("Resource %d",i+1);
        scanf("%d",&total_instances[i]);
    }

    printf("Enter allocated instances for each process : \n");
    for (int i = 0; i < processes; i++)
    {
        printf("Process %d",i+1);
        for (int j = 0; j < resources; j++)
        {
        scanf("%d",&allocation[i][j]);
        }
        
    }

    printf("Enter maximum instances needed for each process : \n");
    for (int i = 0; i < processes; i++)
    {
        printf("Process %d",i+1);
        for (int j = 0; j < resources; j++)
        {
        scanf("%d",&maximum[i][j]);
        need[i][j] = maximum[i][j] - allocation[i][j];
        }
        
    }

    int x=check_deadlock();

    if(x) printf("Deadlock");
    else printf("No Deadlock");

    return 0;
}