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
    if(argc != 2)
    {
        perror("Insuffiecient arguments passed");
        exit(1);
    }
    long long int fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1)
    {
        perror("Opening Input File");
        exit(1);
    }

    off_t sz = lseek(fd1, 0, SEEK_END);

    // Creating Directory named "Assignment" //

    char *DirectoryName = "Assignment";
    mkdir(DirectoryName, S_IRWXU);

    // Naming the output file as "1_<Input_File_Name>" //

    char *outputFile;
    outputFile = (char *)malloc(30);
    outputFile[0] = '1';
    outputFile[1] = '_';

    long long int i = 0;
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
        outputFile[2 + i] = *(argv[1] + j);

        if (*(argv[1] + j) == '\0')
            break;

        i = i + 1;
        j = j + 1;
    }

    // Permissions:
    // x(execute) = 1
    // w(write) = 2
    // r(read) = 4

    char pathFile[50];
    sprintf(pathFile, "%s/%s", DirectoryName, outputFile );

    long long int fd2 = open(pathFile, O_WRONLY | O_APPEND | O_CREAT | O_TRUNC, 0600);
    if (fd2 < 0)
    {
        perror("Opening output file");
        exit(1);
    }

    lseek(fd1, -1, SEEK_END); // setting the file pointer to the end
    lseek(fd2, 0, SEEK_SET);  // setting the file pointer at the start

    long long int bsz = sz / 100; // prefered byte size = file sie / 100
    long long int BytesToRead = (bsz == 0) ? 1 : bsz;

    char *c, *r;
    c = (char *)malloc(BytesToRead);
    r = (char *)malloc(BytesToRead);

    long long int start = ((sz - 1) / BytesToRead) * BytesToRead; // Start location
    long long int distance = sz - start;                          // length to move

    lseek(fd1, start, SEEK_SET); // Set the file pointer at start index.
    char percentage[70];
    float percent = 0;
    float BytesRead = 0;
    while (1)
    {
        long long int f_idx, l_idx;
        read(fd1, c, distance);
        for (f_idx = 0, l_idx = distance - 1; f_idx < distance; f_idx++, l_idx--)
        {
            r[f_idx] = c[l_idx]; // Storing the content in reverse order
        }
        r[distance] = '\0';

        BytesRead = BytesRead + distance;
        percent = (BytesRead/sz)*100;
        sprintf(percentage, "Percentage of the file read = %f", percent);
        long long int size = 0;
        while (1)
        {
            if (percentage[size] == '\0')
                break;
            size = size + 1;
        }
        write(STDOUT_FILENO, "\r", 1);
        fflush(stdout);
        write(STDOUT_FILENO, percentage, size);
        write(fd2, r, distance);

        if (lseek(fd1, 0, SEEK_CUR) - BytesToRead - distance < 0)
            break; // While reading the last chunk

        lseek(fd1, -BytesToRead - distance, SEEK_CUR);
        distance = BytesToRead;
    }
    write(STDOUT_FILENO, "\n", 1);
    //write(STDOUT_FILENO, "Percentage of the file read = %f", percent);

    if (close(fd1) < 0)
    {
        perror("Closing input file");
        exit(1);
    }
    if (close(fd2) < 0)
    {
        perror("Closing output file");
        exit(1);
    }
}
