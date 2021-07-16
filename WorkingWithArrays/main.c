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
  
  CFIndex numberOfCustomers = CFArrayGetCount(cfCustomers);
  
  for (CFIndex i = 0; i < numberOfCustomers; i++) {
    CFStringRef v = (CFStringRef)CFArrayGetValueAtIndex(cfCustomers, i);
    CFShow(v);
  }
  
  CFRelease(cfCustomers);
  
  return 0;
}
