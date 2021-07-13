//
//  main.c
//  WorkingWithArrays
//
//  Created by Panayotis Matsinopoulos on 13/7/21.
//

#include <stdio.h>
#include <CoreFoundation/CoreFoundation.h>

const void * CustomersCallBackRetain (CFAllocatorRef allocator, const void *value) {
  return CFRetain(value);
}

void CustomersCallBackRelease (CFAllocatorRef allocator, const void *value) {
  CFRelease(value);
}

CFStringRef CustomersCallBackCopyDescription (const void *value) {
  return (CFStringRef)value;
}

Boolean CustomersCallBacksEqual(const void *value1, const void *value2) {
  return CFStringCompare((CFStringRef)value1,
                         (CFStringRef)value2,
                         0) == kCFCompareEqualTo;
}

int main(int argc, const char * argv[]) {
  const int NUMBER_OF_CUSTOMERS = 3;
  
  CFStringRef customers[NUMBER_OF_CUSTOMERS] = {
    CFSTR("Peter Pan"),
    CFSTR("Mary Foo"),
    CFSTR("John Woo")
  };
  
  CFArrayCallBacks cfCustomersCallBacks = {
    0,
    CustomersCallBackRetain,
    CustomersCallBackRelease,
    CustomersCallBackCopyDescription,
    CustomersCallBacksEqual
  };
  
  CFArrayRef cfCustomers = CFArrayCreate(kCFAllocatorDefault,
                                         (const void **)customers,
                                         NUMBER_OF_CUSTOMERS,
                                         &cfCustomersCallBacks);
  
  CFShow(cfCustomers);
  
  CFRelease(cfCustomers);
  
  return 0;
}
