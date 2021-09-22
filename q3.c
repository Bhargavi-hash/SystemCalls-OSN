// Checking the permissions of output files and directory //
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        perror("Insufficient arguments");
        exit(1);
    }
    int i, sz;

    int Directory_Status = mkdir("Assignment", S_IRWXU);
    if (Directory_Status == EEXIST)
    {
        char msg[100];
        perror("Directory");
        sprintf(msg, "Directory is created: No\n\n");
        sz = 0;
        while (1)
        {
            if (msg[sz] == '\0')
                break;
            sz = sz + 1;
        }
        write(STDOUT_FILENO, msg, sz);
        exit(1);
    }
    else
    {
        char msg[100];
        sprintf(msg, "Directory is created: Yes\n\n");
        sz = 0;
        while (1)
        {
            if (msg[sz] == '\0')
                break;
            sz = sz + 1;
        }
        write(STDOUT_FILENO, msg, sz);
    }

    char OutPerm[29][100];
    char *outputFile1;
    outputFile1 = (char *)malloc(30);
    outputFile1[0] = '1';
    outputFile1[1] = '_';
    
    i = 0;
    long long int slash_index = 0;
    while (1)
    {   
        if(*(argv[1] + i) == '/')
            slash_index = i;
        if (*(argv[1] + i) == '\0')
            break;

        i = i + 1;
    }
    i = 0;
    long long int j = 0;
    
    if(slash_index == 0)
        j = 0;
    else
        j = slash_index + 1;

    while (1)
    {
        outputFile1[2 + i] = *(argv[1] + j);

        if (*(argv[1] + j) == '\0')
            break;

        i = i + 1;
        j = j + 1;
    }


    char pathFile1[50];
    sprintf(pathFile1, "%s/%s", "Assignment", outputFile1);

    struct stat st1;
    char status1[10][5];

    if (stat(pathFile1, &st1) != 0)
    {
        perror("Output File 1");
    }
    else
    {
        mode_t perm = st1.st_mode;
        sprintf(status1[0], "%s", (perm & S_IRUSR) ? "YES" : "NO");
        sprintf(status1[1], "%s", (perm & S_IWUSR) ? "YES" : "NO");
        sprintf(status1[2], "%s", (perm & S_IXUSR) ? "YES" : "NO");
        sprintf(status1[3], "%s", (perm & S_IRGRP) ? "YES" : "NO");
        sprintf(status1[4], "%s", (perm & S_IWGRP) ? "YES" : "NO");
        sprintf(status1[5], "%s", (perm & S_IXGRP) ? "YES" : "NO");
        sprintf(status1[6], "%s", (perm & S_IROTH) ? "YES" : "NO");
        sprintf(status1[7], "%s", (perm & S_IWOTH) ? "YES" : "NO");
        sprintf(status1[8], "%s", (perm & S_IXOTH) ? "YES" : "NO");
        *status1[9] = '\0';

        sprintf(OutPerm[0], "User has read permission on output_file_1:%s\n", status1[0]);
        sz = 0;
        while (1)
        {
            if (OutPerm[0][sz] == '\0')
                break;
            sz = sz + 1;
        }
        write(STDOUT_FILENO, OutPerm[0], sz);

        sprintf(OutPerm[1], "User has write permission on output_file_1:%s\n", status1[1]);
        sz = 0;
        while (1)
        {
            if (OutPerm[1][sz] == '\0')
                break;
            sz = sz + 1;
        }
        write(STDOUT_FILENO, OutPerm[1], sz);

        sprintf(OutPerm[2], "User has execute permission on output_file_1:%s\n\n", status1[2]);
        sz = 0;
        while (1)
        {
            if (OutPerm[2][sz] == '\0')
                break;
            sz = sz + 1;
        }
        write(STDOUT_FILENO, OutPerm[2], sz);

        sprintf(OutPerm[3], "Group has read permission on output_file_1:%s\n", status1[3]);
        sz = 0;
        while (1)
        {
            if (OutPerm[3][sz] == '\0')
                break;
            sz = sz + 1;
        }
        write(STDOUT_FILENO, OutPerm[3], sz);

        sprintf(OutPerm[4], "Group has write permission on output_file_1: %s\n", status1[4]);
        sz = 0;
        while (1)
        {
            if (OutPerm[4][sz] == '\0')
                break;
            sz = sz + 1;
        }
        write(STDOUT_FILENO, OutPerm[4], sz);

        sprintf(OutPerm[5], "Group has execute permission on output_file_1: %s\n\n", status1[5]);
        sz = 0;
        while (1)
        {
            if (OutPerm[5][sz] == '\0')
                break;
            sz = sz + 1;
        }
        write(STDOUT_FILENO, OutPerm[5], sz);

        sprintf(OutPerm[6], "Others has read permission on output_file_1: %s\n", status1[6]);
        sz = 0;
        while (1)
        {
            if (OutPerm[6][sz] == '\0')
                break;
            sz = sz + 1;
        }
        write(STDOUT_FILENO, OutPerm[6], sz);

        sprintf(OutPerm[7], "Others has write permission on output_file_1: %s\n", status1[7]);
        sz = 0;
        while (1)
        {
            if (OutPerm[7][sz] == '\0')
                break;
            sz = sz + 1;
        }
        write(STDOUT_FILENO, OutPerm[7], sz);

        sprintf(OutPerm[8], "Others has execute permission on output_file_1: %s\n\n", status1[8]);
        sz = 0;
        while (1)
        {
            if (OutPerm[8][sz] == '\0')
                break;
            sz = sz + 1;
        }
        write(STDOUT_FILENO, OutPerm[8], sz);
    }

    char *outputFile2;
    outputFile2 = (char *)malloc(30);
    outputFile2[0] = '2';
    outputFile2[1] = '_';

    i = 0;
    slash_index = 0;
    while (1)
    {   
        if(*(argv[1] + i) == '/')
            slash_index = i;
        if (*(argv[1] + i) == '\0')
            break;

        i = i + 1;
    }
    i = 0;
    j = 0;
    
    if(slash_index == 0)
        j = 0;
    else
        j = slash_index + 1;

    while (1)
    {
        outputFile2[2 + i] = *(argv[1] + j);

        if (*(argv[1] + j) == '\0')
            break;

        i = i + 1;
        j = j + 1;
    }


    char pathFile2[50];
    sprintf(pathFile2, "%s/%s", "Assignment", outputFile2);

    struct stat st2;
    char status2[10][5];

    if (stat(pathFile2, &st2) != 0)
    {
        perror("Output File 2");
    }
    else
    {
        mode_t perm = st2.st_mode;
        sprintf(status2[0], "%s", (perm & S_IRUSR) ? "YES" : "NO");
        sprintf(status2[1], "%s", (perm & S_IWUSR) ? "YES" : "NO");
        sprintf(status2[2], "%s", (perm & S_IXUSR) ? "YES" : "NO");
        sprintf(status2[3], "%s", (perm & S_IRGRP) ? "YES" : "NO");
        sprintf(status2[4], "%s", (perm & S_IWGRP) ? "YES" : "NO");
        sprintf(status2[5], "%s", (perm & S_IXGRP) ? "YES" : "NO");
        sprintf(status2[6], "%s", (perm & S_IROTH) ? "YES" : "NO");
        sprintf(status2[7], "%s", (perm & S_IWOTH) ? "YES" : "NO");
        sprintf(status2[8], "%s", (perm & S_IXOTH) ? "YES" : "NO");
        *status2[9] = '\0';

        sprintf(OutPerm[9], "User has read permission on output_file_2:%s\n", status2[0]);
        sz = 0;
        while (1)
        {
            if (OutPerm[9][sz] == '\0')
                break;
            sz = sz + 1;
        }
        write(STDOUT_FILENO, OutPerm[9], sz);

        sprintf(OutPerm[10], "User has write permission on output_file_2:%s\n", status2[1]);
        sz = 0;
        while (1)
        {
            if (OutPerm[10][sz] == '\0')
                break;
            sz = sz + 1;
        }
        write(STDOUT_FILENO, OutPerm[10], sz);

        sprintf(OutPerm[11], "User has execute permission on output_file_2:%s\n\n", status2[2]);
        sz = 0;
        while (1)
        {
            if (OutPerm[11][sz] == '\0')
                break;
            sz = sz + 1;
        }
        write(STDOUT_FILENO, OutPerm[11], sz);

        sprintf(OutPerm[12], "Group has read permission on output_file_2:%s\n", status2[3]);
        sz = 0;
        while (1)
        {
            if (OutPerm[12][sz] == '\0')
                break;
            sz = sz + 1;
        }
        write(STDOUT_FILENO, OutPerm[12], sz);

        sprintf(OutPerm[13], "Group has write permission on output_file_2: %s\n", status2[4]);
        sz = 0;
        while (1)
        {
            if (OutPerm[13][sz] == '\0')
                break;
            sz = sz + 1;
        }
        write(STDOUT_FILENO, OutPerm[13], sz);

        sprintf(OutPerm[14], "Group has execute permission on output_file_2: %s\n\n", status2[5]);
        sz = 0;
        while (1)
        {
            if (OutPerm[14][sz] == '\0')
                break;
            sz = sz + 1;
        }
        write(STDOUT_FILENO, OutPerm[14], sz);

        sprintf(OutPerm[15], "Others has read permission on output_file_2: %s\n", status2[6]);
        sz = 0;
        while (1)
        {
            if (OutPerm[15][sz] == '\0')
                break;
            sz = sz + 1;
        }
        write(STDOUT_FILENO, OutPerm[15], sz);

        sprintf(OutPerm[16], "Others has write permission on output_file_2: %s\n", status2[7]);
        sz = 0;
        while (1)
        {
            if (OutPerm[16][sz] == '\0')
                break;
            sz = sz + 1;
        }
        write(STDOUT_FILENO, OutPerm[16], sz);

        sprintf(OutPerm[17], "Others has execute permission on output_file_2: %s\n\n", status2[8]);
        sz = 0;
        while (1)
        {
            if (OutPerm[17][sz] == '\0')
                break;
            sz = sz + 1;
        }
        write(STDOUT_FILENO, OutPerm[17], sz);
    }

    struct stat st3;
    char status3[10][5];

    stat("Assignment", &st3);
    mode_t perm = st3.st_mode;
    sprintf(status3[0], "%s", (perm & S_IRUSR) ? "YES" : "NO");
    sprintf(status3[1], "%s", (perm & S_IWUSR) ? "YES" : "NO");
    sprintf(status3[2], "%s", (perm & S_IXUSR) ? "YES" : "NO");
    sprintf(status3[3], "%s", (perm & S_IRGRP) ? "YES" : "NO");
    sprintf(status3[4], "%s", (perm & S_IWGRP) ? "YES" : "NO");
    sprintf(status3[5], "%s", (perm & S_IXGRP) ? "YES" : "NO");
    sprintf(status3[6], "%s", (perm & S_IROTH) ? "YES" : "NO");
    sprintf(status3[7], "%s", (perm & S_IWOTH) ? "YES" : "NO");
    sprintf(status3[8], "%s", (perm & S_IXOTH) ? "YES" : "NO");
    *status3[9] = '\0';

    sprintf(OutPerm[18], "User has read permission on directory:%s\n", status3[0]);
    sz = 0;
    while (1)
    {
        if (OutPerm[18][sz] == '\0')
            break;
        sz = sz + 1;
    }
    write(STDOUT_FILENO, OutPerm[18], sz);

    sprintf(OutPerm[19], "User has write permission on directory:%s\n", status3[1]);
    sz = 0;
    while (1)
    {
        if (OutPerm[19][sz] == '\0')
            break;
        sz = sz + 1;
    }
    write(STDOUT_FILENO, OutPerm[19], sz);

    sprintf(OutPerm[20], "User has execute permission on directory:%s\n\n", status3[2]);
    sz = 0;
    while (1)
    {
        if (OutPerm[20][sz] == '\0')
            break;
        sz = sz + 1;
    }
    write(STDOUT_FILENO, OutPerm[20], sz);

    sprintf(OutPerm[21], "Group has read permission on directory:%s\n", status3[3]);
    sz = 0;
    while (1)
    {
        if (OutPerm[21][sz] == '\0')
            break;
        sz = sz + 1;
    }
    write(STDOUT_FILENO, OutPerm[21], sz);

    sprintf(OutPerm[22], "Group has write permission on directory: %s\n", status3[4]);
    sz = 0;
    while (1)
    {
        if (OutPerm[22][sz] == '\0')
            break;
        sz = sz + 1;
    }
    write(STDOUT_FILENO, OutPerm[22], sz);

    sprintf(OutPerm[23], "Group has execute permission on directory: %s\n\n", status3[5]);
    sz = 0;
    while (1)
    {
        if (OutPerm[23][sz] == '\0')
            break;
        sz = sz + 1;
    }
    write(STDOUT_FILENO, OutPerm[23], sz);

    sprintf(OutPerm[24], "Others has read permission on directory: %s\n", status3[6]);
    sz = 0;
    while (1)
    {
        if (OutPerm[24][sz] == '\0')
            break;
        sz = sz + 1;
    }
    write(STDOUT_FILENO, OutPerm[24], sz);

    sprintf(OutPerm[25], "Others has write permission on directory: %s\n", status3[7]);
    sz = 0;
    while (1)
    {
        if (OutPerm[25][sz] == '\0')
            break;
        sz = sz + 1;
    }
    write(STDOUT_FILENO, OutPerm[25], sz);

    sprintf(OutPerm[26], "Others has execute permission on directory: %s\n\n", status3[8]);
    sz = 0;
    while (1)
    {
        if (OutPerm[26][sz] == '\0')
            break;
        sz = sz + 1;
    }
    write(STDOUT_FILENO, OutPerm[26], sz);
}