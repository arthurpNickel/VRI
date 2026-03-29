/* Program to sent commands for robot -> V1 (KKKK) */

#include <stdio.h>

int main()
{
    FILE *archive;
    short int command;

    archive = fopen("/dev/ttyS0", "w"); //Ou a?

    if (!archive) 
    {
        perror("Error opening file\n");
        return 1;
    }

    printf("Type the command you want to send to the robot:\n");
    scanf("%d", &command);

    fwrite(&command, 2, 1, archive);

    fclose(archive);

}