/*-----------------------------------|| OM NAMAH SHIVAYA || -----------------------------------
|   
|   APPLICATION NAME : ReadMe_Automator
|   VERSION          : v1.1
|   DESCRIPTION      : Interactive Consoled Based Application in C 
|                      used for generating and writing content to 'ReadMe.txt' file.
|   AUTHOR           : KSHITIJ BADKAS
|   WEBSITE          : https://appsecradar.net
|   GITHUB           : https://github.com/kshitij-badkas/ReadMe_Automator                                                            
|   CONTACT          : https://twitter.com/appsecradar                     
|                                                                                             
|------------------------------------- || JAI SHREE RAAM || -----------------------------------*/


/***************************************************************
    CHANGES IN v1.1-

    1. changed spacing in the Greeting
    2. file will now open in append(a+) mode
    3. write content to file through user interaction
    4. system call 'system()' gets called before the 'printf()' - 
        hence rearranged - first : printf, second : system()

*****************************************************************/

/*
    ToDO :

    1. fprintf(pFile, "ReadMe_Automator - Version 1.1 - By Kshitij Badkas.\n\n");
        fprintf(pFile, "NEW CHANGES SAVED AFTER THIS LINE.\n\n");

        must be written to file only once - at the time of creation.

    2. modify system call to open Readme.txt upon execution.

*/

//Header files
#include <stdio.h>

//define macro
#define STR_LENGTH 500

//main()
int main(void)
{
    //Local variables
    FILE *pFile = NULL;

    int status_of_system_fun = 0;
    int is_File_Open = 0;
    char str[STR_LENGTH];
    char c;

    //About
    printf("\n--------------------------------------- || OM NAMAH SHIVAYA || -----------------------------------\n");
    printf("|\n");
    printf("| \t\t  APPLICATION NAME : ReadMe_Automator\n");
    printf("| \t\t  VERSION .........: v1.1\n");
    printf("| \t\t  DESCRIPTION .....: Interactive Consoled Based Application in C \n");
    printf("| \t\t                     used for generating and writing content to 'ReadMe.txt' file.\n");
    printf("| \t\t  AUTHOR ..........: KSHITIJ BADKAS\n");
    printf("| \t\t  WEBSITE .........: https://appsecradar.net\n");
    printf("| \t\t  GITHUB ..........: https://github.com/kshitij-badkas/ReadMe_Automator \n");
    printf("| \t\t  CONTACT .........: https://twitter.com/appsecradar \n");
    printf("|\n");
    printf("|--------------------------------------- || JAI SHREE RAAM || -------------------------------------\n");

    //create and open ReadMe.txt in append + read + write mode (a+) 
    is_File_Open = fopen_s(&pFile, "ReadMe.txt", "a+");
    if(is_File_Open != 0)
    {
        //fail
        printf("\n\n CANNOT DESIRED FILE : 'ReadMe.txt'. EXITTING NOW.\n\n");
        exit(0);
    }
    //success
    else
        printf("\n\n 'ReadMe.txt' CREATED SUCCESSFULLY\n\n");
    
    //write to File
    fprintf(pFile, "ReadMe_Automator - Version 1.1 - By Kshitij Badkas.\n\n");
    fprintf(pFile, "NEW CHANGES SAVED AFTER THIS LINE.\n\n");

    //code to write content to file by user at run-time
    printf("\n\n");
    printf("Hello User!\n\n");
    printf("What's On Your Mind ?\n\n");
    gets(str);
    
    printf("\n\n");
    printf("You Have Entered The Following : \n '%s' \n", str);
    printf("\nDo You want to save this to the file (Y/N) ? \n");

    switch (c = getch())
    {
    case 'Y':// follow through
    case 'y':
        fputs(str, pFile);
        printf("\n\nCHANGES SAVED SUCCESSFULLY.\n\n");
        break;
    case 'N':// follow through
    case 'n':
        printf("\n\nCHANGES NOT SAVED TO FILE.\n\n");
        break;
    default:
        printf("\n\nINVALID INPUT DETECTED. PRESS 'Y/y' For YES & 'N/n' For NO.\n\n");
        break;
    }
    
    
    //shell command 'dir' to list files and folders in PWD.
    printf("\n\n HERE IS THE LIST OF FILES AND DIRECTORIES IN THE CURRENT DIRECTORY : \n\n"); 
    system("dir");
    

    //close File
    fclose(pFile);
    pFile = NULL;


    return (0);
}
