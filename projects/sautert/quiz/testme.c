#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    //Create a char array of acceptable characters
    char charArray[9];
    charArray[0] = '[';
    charArray[1] = ']';
    charArray[2] = '{';
    charArray[3] = '}';
    charArray[4] = '(';
    charArray[5] = ')';
    charArray[6] = 'a';
    charArray[7] = 'x';
    charArray[8] = ' ';

    int randIndex = rand() % 9;

    return charArray[randIndex];
}

char *inputString()
{
    //Create a char array of acceptable characters to make into string
    char charArray[5];
    charArray[0] = 'r';
    charArray[1] = 'e';
    charArray[2] = 's';
    charArray[3] = 't';

    char* returnString = malloc(6 * sizeof(char));

    for(int i = 0; i < 5; i++)
    {
      int randIndex = rand() % 4;
      strncat(returnString, &charArray[randIndex], 1);
    }

    strncat(returnString, "\0", 1);

    return returnString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
