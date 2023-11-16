/* vulp.c*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define DELAY 10000

int main()
{
  char * fn = "/tmp/XYZ";
  if (!access(fn, W_OK)) {
	
    char buffer[60];
    FILE *fp;
    long int i;
    fp = fopen(fn, "r");
    fclose(fp);

    /* get user input */
    scanf("%50s", buffer);
    fp = fopen(fn, "r");
    fclose(fp);


    if (!access(fn, W_OK)) {
      /* simulating delay */
      for (i = 0; i < DELAY; i++) {
        int a = i^2;
      }
      if (!access(fn, W_OK)) {
        fp = fopen(fn, "a+");
        fwrite("\n", sizeof(char), 1, fp);
        fwrite(buffer, sizeof(char), strlen(buffer), fp);
        fclose(fp);
      }
    }
    else printf("No permission \n");
  }

	else printf("No permission \n");
}