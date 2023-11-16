/* vulp.c*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define DELAY 10000

 int removeRootPrivileges(void)
 {
    const int uid = getuid();
    printf("UID %d: ", uid);

    // Quitar permisos de root
    // Se puede poner cualquier numero, excepto 0 que es el uid de root
   if (seteuid(500) == -1) {
        perror("seteuid");
        return 1;
    }
    else printf("No permission \n");

    return 1;
 }

int givesRootPrivileges(void)
 {
    // Dar permisos de root
    if (seteuid(getuid()) == -1) {
        perror("seteuid");
        return 1;
    }
     return 1;
 }

int main()
{
  removeRootPrivileges();
  char * fn = "/tmp/XYZ";
  char buffer[60];
  FILE *fp;
  long int i;

  /* get user input */
  scanf("%50s", buffer);

  givesRootPrivileges();

  if (!access(fn, W_OK)) {

    /* simulating delay */
    for (i = 0; i < DELAY; i++) {
      int a = i^2;
    }

    fp = fopen(fn, "a+");
    fwrite("\n", sizeof(char), 1, fp);
    fwrite(buffer, sizeof(char), strlen(buffer), fp);
    fclose(fp);
  }

  removeRootPrivileges();
}
