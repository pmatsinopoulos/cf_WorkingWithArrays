//
//  main.c
//  WorkingWithArrays
//
//  Created by Panayotis Matsinopoulos on 13/7/21.
//

#include <stdio.h>
#include <CoreFoundation/CoreFoundation.h>

void CustomersShowApplier (const void *value, void *context) {
  printf("%s %s\n", (const char *)context, CFStringGetCStringPtr((CFStringRef)value, CFStringGetSystemEncoding()));
}

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
  
  const char *greeting = "Hello";
  CFArrayApplyFunction(cfCustomers,
                       CFRangeMake(0, CFArrayGetCount(cfCustomers)),
                       CustomersShowApplier,
                       (void *)greeting);
    
  CFRelease(cfCustomers);
  
  return 0;
}
