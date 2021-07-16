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
  
  CFMutableArrayRef cfCustomers = CFArrayCreateMutable(kCFAllocatorDefault, NUMBER_OF_CUSTOMERS, &kCFTypeArrayCallBacks);
  
  CFStringRef customer = CFSTR("Peter Pan");
  
  CFArrayAppendValue(cfCustomers, customer);
  
  printf("Printing elements of array:\n");
  CFShow(cfCustomers);
  
  customer = CFSTR("John Woo");
  
  CFArrayAppendValue(cfCustomers, customer);
  
  printf("Printing elements of array:\n");
  CFShow(cfCustomers);
  
  CFRelease(cfCustomers);
  
  return 0;
}
