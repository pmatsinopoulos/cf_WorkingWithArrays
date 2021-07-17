//
//  main.c
//  WorkingWithArrays
//
//  Created by Panayotis Matsinopoulos on 13/7/21.
//

#include <stdio.h>
#include <CoreFoundation/CoreFoundation.h>
#include "Temperature.h"

int main(int argc, const char * argv[]) {
  CFMutableArrayRef cfTemperatures = CFArrayCreateMutable(kCFAllocatorDefault, 0, &kTemperatureCallbacks);

  TemperatureAppend(cfTemperatures, Mon, 41, 39);
  TemperatureAppend(cfTemperatures, Tue, 40, 38);
  TemperatureAppend(cfTemperatures, Wed, 38, 35);
  TemperatureAppend(cfTemperatures, Thu, 39, 37);
  TemperatureAppend(cfTemperatures, Fri, 42, 39);
  TemperatureAppend(cfTemperatures, Sat, 37, 35);
  TemperatureAppend(cfTemperatures, Sun, 36, 34);
  
  CFShow(cfTemperatures);
  
  CFRelease(cfTemperatures);
  
  printf("Bye!\n");
  
  return 0;
}
