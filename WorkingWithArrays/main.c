//
//  main.c
//  WorkingWithArrays
//
//  Created by Panayotis Matsinopoulos on 13/7/21.
//

#include <stdio.h>
#include <CoreFoundation/CoreFoundation.h>

CFComparisonResult CustomersComparator (const void *val1, const void *val2, void *context) {
  CFStringRef customer1 = (CFStringRef)val1;
  CFStringRef customer2 = (CFStringRef)val2;
  
  CFArrayRef customer1Parts = CFStringCreateArrayBySeparatingStrings(kCFAllocatorDefault,
                                                                     customer1,
                                                                     CFSTR(" "));
  CFStringRef customer1LastName = CFArrayGetValueAtIndex(customer1Parts, 1);
  CFStringRef customer1FirstName = CFArrayGetValueAtIndex(customer1Parts, 0);

  CFArrayRef customer2Parts = CFStringCreateArrayBySeparatingStrings(kCFAllocatorDefault,
                                                                     customer2,
                                                                     CFSTR(" "));
  CFStringRef customer2LastName = CFArrayGetValueAtIndex(customer2Parts, 1);
  CFStringRef customer2FirstName = CFArrayGetValueAtIndex(customer2Parts, 0);

  CFComparisonResult result = CFStringCompare(customer1LastName, customer2LastName, 0);
  
  if ( result == kCFCompareEqualTo) {
    result = CFStringCompare(customer1FirstName, customer2FirstName, 0);
  }
    
  CFRelease(customer1Parts);
  CFRelease(customer2Parts);
  
  return result;
}

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
                    (CFComparatorFunction)CustomersComparator, NULL);

  printf("After sorting:\n");
  CFShow(cfCustomers);

  CFRelease(cfCustomers);
  
  return 0;
}
