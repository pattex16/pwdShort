#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//argc = arguments count
//argv[0] = ./argv[1]Short
//argv[1] = $ARGV[1]
//argv[2] = $ARGV[2]

bool isCurrentDir(char* s)
{
  bool result = true;
  int i = 0;
  while (s[i] != '\0') {
    if (s[i] == '/')
      result = false;
    i++;
  }
  return result;
}

int main(int argc, char* argv[])
{

  long int pwdLen = strlen(argv[1]);
  long int homeLen = strlen(argv[2]);

  bool tilde = true;
  for (int i = 0; i < homeLen; i++)
    if (argv[1][i] != argv[2][i]) //check if you are in a subdirectory of your argv[2]
      tilde = false;

  int i;
  if (tilde) {
    printf("~"); //argv[2] directory is substituded with a ~
    i = homeLen - 1;
  } else
    i = 0 - 1; //if you are not in a subdirectory of your argv[2], '/' is left

  int threeCharMax = 0;
  while (true) {
    i++;

    if (isCurrentDir(&argv[1][i])) {  //current directory is printed with all of its characters
      printf("%c", argv[1][i]);
      if (argv[1][i + 1] == '\0')
        break;
      continue;
    }
    if (argv[1][i] == '/') { //print each
      threeCharMax = 0;
      printf("%c", argv[1][i]);
      continue;
    }
    if (!isCurrentDir(&argv[1][i]) && threeCharMax < 3) { //for each subdirectory print the first 3 chars
      threeCharMax++;
      if (argv[1][i] == '.'){ //.dotdirs should have 4 chars, including the dot
        printf("%c%c", argv[1][i], argv[1][i+1]); 
        i++;
      }
      else
        printf("%c", argv[1][i]);
      continue;
    }
  }
  printf("%c",'\0'); //end with a nice '\0'
  return 0;
}
