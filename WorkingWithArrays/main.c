//
//  main.c
//  WorkingWithArrays
//
//  Created by Panayotis Matsinopoulos on 13/7/21.
//

#include <stdio.h>
#include <CoreFoundation/CoreFoundation.h>

int main(int argc, const char * argv[]) {
  const int NUMBER_OF_CUSTOMERS = 3;
  
  CFStringRef customers[NUMBER_OF_CUSTOMERS] = {
    CFSTR("Peter Pan"),
    CFSTR("Mary Foo"),
    CFSTR("John Woo")
  };
  
  CFArrayRef cfCustomers = CFArrayCreate(kCFAllocatorDefault, (const void **)customers, NUMBER_OF_CUSTOMERS, &kCFTypeArrayCallBacks);
  
  CFShow(cfCustomers);
  
  CFRelease(cfCustomers);
  
  return 0;
}
