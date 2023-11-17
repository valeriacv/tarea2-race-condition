/* vulp.c*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

#define DELAY 10000

int main()
{
  char * fn = "/tmp/XYZ";
  struct stat sb, sbBeforeWrite;
  long int originalInode, beforeWriteInode;

  if (!access(fn, W_OK)) {

    char buffer[60];
    FILE *fp;
    long int i;

    fp = fopen(fn, "r");
    fstat(fileno(fp), &sb);
    originalInode = sb.st_ino;
    printf("I-node number:  %ld\n", (long) originalInode);

    if (!access(fn, W_OK)) {
        /* get user input */
        scanf("%50s", buffer);

        if (!access(fn, W_OK)) {
          /* simulating delay */
          for (i = 0; i < DELAY; i++) {
            int a = i^2;
          }

          if (!access(fn, W_OK)) {
            fp = fopen(fn, "a+");
            fstat(fileno(fp), &sbBeforeWrite);
    		    beforeWriteInode = sbBeforeWrite.st_ino;
    		    printf("I-node number:  %ld\n", (long) beforeWriteInode);

            if (!access(fn, W_OK) &&  originalInode == beforeWriteInode) {
              fwrite("\n", sizeof(char), 1, fp);

              if (!access(fn, W_OK)) {
                fwrite(buffer, sizeof(char), strlen(buffer), fp);

                if (!access(fn, W_OK)) {
                  fclose(fp);
                }
                else printf("No permission \n");
              }
              else printf("No permission \n");
            }
            else printf("No permission \n");
          }
          else printf("No permission \n");
        }
        else printf("No permission \n");
    }
    else printf("No permission \n");
  }
  else printf("No permission \n");
}