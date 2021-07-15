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
    CFSTR("John Woo"),
    CFSTR("Peter Pan"),
    CFSTR("Mary Foo")
  };
  
  CFArrayRef cfCustomers = CFArrayCreate(kCFAllocatorDefault,
                                         (const void **)customers,
                                         NUMBER_OF_CUSTOMERS,
                                         &kCFTypeArrayCallBacks);
  
  Boolean foundResult = CFArrayContainsValue(cfCustomers,
                                             CFRangeMake(0, CFArrayGetCount(cfCustomers)),
                                             CFSTR("Mary Foo"));
  // Prints "YES"
  printf("found: %s\n", foundResult ? "YES" : "NO");
  
  foundResult = CFArrayContainsValue(cfCustomers,
                                     CFRangeMake(0, CFArrayGetCount(cfCustomers)),
                                     CFSTR("Bob The Builder"));
  // Prints "YES"
  printf("found: %s\n", foundResult ? "YES" : "NO");
  
  CFRelease(cfCustomers);
  
  return 0;
}
