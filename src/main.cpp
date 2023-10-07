#include <Arduino.h>

#include "src/SimplePath.h"

void setup() {

 const char* file = "c:\\folder1\\folder2\\file.txt";

 char** array = nullptr;
 int   size;

 const char* delim = "\\";



 SimplePath path;
 path.Split(file, array, size);


 char* root = path.GetRoot(file);
 char* last = path.GetLast(file);

 for (int i = 0; i < size; i++)
 {
     char * pos = array[i];
 }

 SimplePath test(delim, (char*)file);

 for (int i = 0; i < test.Length; i++)
 {
     char* pos = test.List[i];
 }
}

void loop() {
  
}

