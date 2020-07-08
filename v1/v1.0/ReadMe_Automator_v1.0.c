/*-----------------------------------|| OM NAMAH SHIVAYA || -----------------------------------
|   
|   APPLICATION NAME : ReadMe_Automator
|   VERSION          : v1.0
|   DESCRIPTION      : Interactive Consoled Based Application in C 
|                      used for generating and writing content to 'ReadMe.txt' file.
|   AUTHOR           : KSHITIJ BADKAS
|   WEBSITE          : https://appsecradar.net
|   GITHUB           : https://github.com/kshitij-badkas/ReadMe_Automator                                                            
|   CONTACT          : https://twitter.com/appsecradar                     
|                                                                                             
|------------------------------------- ||JAI SHREE RAAM || -----------------------------------*/


//Header files
#include <stdio.h>

//main()
int main(void)
{
    //Local variables
    FILE *pFile = NULL;

    int status_of_system_fun = 0;
    int is_File_Open = 0;
    char c;

    //About
    printf("\n--------------------------------------- || OM NAMAH SHIVAYA || -----------------------------------\n");
    printf("|\n");
    printf("| \t\t  APPLICATION NAME : ReadMe_Automator\n");
    printf("| \t\t  VERSION .........: v1.0\n");
    printf("| \t\t  DESCRIPTION .....: Interactive Consoled Based Application in C \n");
    printf("| \t\t                     used for generating and writing content to 'ReadMe.txt' file.\n");
    printf("| \t\t  AUTHOR ..........: KSHITIJ BADKAS\n");
    printf("| \t\t  WEBSITE .........: https://appsecradar.net\n");
    printf("| \t\t  GITHUB ..........: https://github.com/kshitij-badkas/ReadMe_Automator \n");
    printf("| \t\t  CONTACT .........: https://twitter.com/appsecradar \n");
    printf("|\n");
    printf("|--------------------------------------- ||JAI SHREE RAAM || -------------------------------------\n");

    //create and open ReadMe.txt to write
    is_File_Open = fopen_s(&pFile, "ReadMe.txt", "w");
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
    fprintf(pFile, "ReadMe_Automator - Version 1.0 - By Kshitij Badkas.\n");
    
    //shell command 'dir' to list files and folders in PWD.
    printf("\n\n HERE IS THE LIST OF FILES AND DIRECTORIES IN THE CURRENT DIRECTORY : \n\n", system("dir"));

    //close File
    fclose(pFile);
    pFile = NULL;


    return (0);
}
