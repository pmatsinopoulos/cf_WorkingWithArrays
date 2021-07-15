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
  
  CFIndex numOfOcc = CFArrayGetCountOfValue(cfCustomers,
                                            CFRangeMake(0, CFArrayGetCount(cfCustomers)),
                                            CFSTR("Peter Pan"));
  // Prints "3"
  printf("Number of times found: %lu\n", numOfOcc);
  
  numOfOcc = CFArrayGetCountOfValue(cfCustomers,
                                    CFRangeMake(0, CFArrayGetCount(cfCustomers)),
                                    CFSTR("King George"));
  // Prints "0"
  printf("Number of times found: %lu\n", numOfOcc);
  
  CFRelease(cfCustomers);
  
  return 0;
}
