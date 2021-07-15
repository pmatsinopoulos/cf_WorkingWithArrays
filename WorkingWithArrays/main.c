//
//  main.c
//  WorkingWithArrays
//
//  Created by Panayotis Matsinopoulos on 13/7/21.
//

#include <stdio.h>
#include <CoreFoundation/CoreFoundation.h>

int main(int argc, const char * argv[]) {
  const int NUMBER_OF_CUSTOMERS = 6;
  
  CFStringRef customers[NUMBER_OF_CUSTOMERS] = {
    CFSTR("John Woo"),
    CFSTR("Peter Pan"),
    CFSTR("Mary Foo"),
    CFSTR("Peter Pan"),
    CFSTR("Queen Mary"),
    CFSTR("Peter Pan")
  };
  
  CFArrayRef cfCustomers = CFArrayCreate(kCFAllocatorDefault,
                                         (const void **)customers,
                                         NUMBER_OF_CUSTOMERS,
                                         &kCFTypeArrayCallBacks);
  
  CFIndex positionFound = CFArrayGetFirstIndexOfValue(cfCustomers,
                                                      CFRangeMake(0, CFArrayGetCount(cfCustomers)),
                                                      CFSTR("Peter Pan"));
  // Prints "1"
  printf("Found at position: %ld\n", positionFound);
  
  positionFound = CFArrayGetLastIndexOfValue(cfCustomers,
                                             CFRangeMake(0, CFArrayGetCount(cfCustomers)),
                                             CFSTR("Peter Pan"));
  // Prints "5"
  printf("Found at position: %ld\n", positionFound);
  

  positionFound = CFArrayGetLastIndexOfValue(cfCustomers,
                                             CFRangeMake(0, CFArrayGetCount(cfCustomers)),
                                             CFSTR("King George"));
  // Prints "-1"
  printf("Found at position: %ld\n", positionFound);

  CFRelease(cfCustomers);
  
  return 0;
}
