#include <Arduino.h>

#include "src/SimplePath.h"

void setup() {

  char* file = (char *)"d:\\aa";

char** array = nullptr;
int   length;

char delim = '\\';

SimplePath path(delim, (char*)file);

char* l1 = path.GetLast((char*)"d:\\aa\\bb");
char* l2 = path.GetLast((char*)"d:\\aa");
char* l3 = path.GetLast((char*)"d:\\");
char* l4 = path.GetLast((char*)"\\aa\\bb");
char* l5 = path.GetLast((char*)"\\aa");
char* l6 = path.GetLast((char*)"\\");

char* r1 = path.GetRoot((char*)"d:\\aa\\bb");
char* r2 = path.GetRoot((char*)"d:\\aa");
char* r3 = path.GetRoot((char*)"d:\\");
char* r4 = path.GetRoot((char*)"\\aa\\bb");
char* r5 = path.GetRoot((char*)"\\aa");
char* r6 = path.GetRoot((char*)"\\");

char* pp1 = path.GetParentPath((char*)"d:\\aa\\bb");
char* pp2 = path.GetParentPath((char*)"d:\\aa");
char* pp3 = path.GetParentPath((char*)"d:\\");
char* pp4 = path.GetParentPath((char*)"\\aa\\bb");
char* pp5 = path.GetParentPath((char*)"\\aa");
char* pp6 = path.GetParentPath((char*)"\\");



path.Split((char*)"d:\\aa\\bb", array, length);
for (int i = 0; i < length; i++)
{
    char * position = array[i];
}
// =>d:
 // =>aa
 // =>bb

path.Split((char*)"d:\\aa", array, length);
for (int i = 0; i < length; i++)
{
    char * position = array[i];
}
// =>d:
 // =>aa

path.Split((char*)"d:\\", array, length);
for (int i = 0; i < length; i++)
{
    char * position = array[i];
}
// =>d:


path.Split((char*)"\\aa\\bb", array, length);
for (int i = 0; i < length; i++)
{
    char * position = array[i];
}
// =>\
// =>aa
// =>bb

path.Split((char*)"\\aa", array, length);
for (int i = 0; i < length; i++)
{
    char * position = array[i];
}
// =>\
// =>aa

path.Split((char*)"\\", array, length);
for (int i = 0; i < length; i++)
{
    char * position = array[i];
}
// =>\



char* par0 = path.GetParent(file, 0);
char* par1 = path.GetParent(file, 1);
char* par2 = path.GetParent(file, 2);

}

void loop() {
  
}

