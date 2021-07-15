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
    CFSTR("Mary Foo"),
    CFSTR("Peter Pan")
  };
    
  CFArrayRef cfCustomers = CFArrayCreate(kCFAllocatorDefault,
                                         (const void **)customers,
                                         NUMBER_OF_CUSTOMERS,
                                         &kCFTypeArrayCallBacks);
  
  CFShow(cfCustomers);
  
  CFIndex searchResult = CFArrayBSearchValues(cfCustomers,
                                              CFRangeMake(0, CFArrayGetCount(cfCustomers)),
                                              CFSTR("Mary Foo"),
                                              (CFComparatorFunction)CFStringCompare,
                                              NULL);
  // Prints 1 for +searchResult+
  printf("Search Result: %lu\n", searchResult);
  
  searchResult = CFArrayBSearchValues(cfCustomers,
                                      CFRangeMake(0, CFArrayGetCount(cfCustomers)),
                                      CFSTR("Queen Mary"),
                                      (CFComparatorFunction)CFStringCompare,
                                      NULL);
  // Prints 3 for +searchResult+
  printf("Search Result: %lu\n", searchResult);

  searchResult = CFArrayBSearchValues(cfCustomers,
                                      CFRangeMake(0, CFArrayGetCount(cfCustomers)),
                                      CFSTR("King George"),
                                      (CFComparatorFunction)CFStringCompare,
                                      NULL);
  // Prints 1 for +searchResult+
  printf("Search Result: %lu\n", searchResult);

  CFRelease(cfCustomers);
  
  return 0;
}
