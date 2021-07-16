//
//  main.c
//  WorkingWithArrays
//
//  Created by Panayotis Matsinopoulos on 13/7/21.
//

#include <stdio.h>
#include <CoreFoundation/CoreFoundation.h>

int main(int argc, const char * argv[]) {
  CFMutableArrayRef cfCustomers = CFArrayCreateMutable(kCFAllocatorDefault,
                                                       0,
                                                       &kCFTypeArrayCallBacks);
  
  CFStringRef customer = CFSTR("Peter Pan");
  CFArrayAppendValue(cfCustomers, customer);
  
  customer = CFSTR("John Woo");
  CFArrayAppendValue(cfCustomers, customer);
  
  customer = CFSTR("Mary Foo");
  CFArrayAppendValue(cfCustomers, customer);

  printf("Before sorting:\n");
  CFShow(cfCustomers);
  
  CFArraySortValues(cfCustomers,
                    CFRangeMake(0, CFArrayGetCount(cfCustomers)),
                    (CFComparatorFunction)CFStringCompare, NULL);

  printf("After sorting:\n");
  CFShow(cfCustomers);

  CFRelease(cfCustomers);
  
  return 0;
}
