//
//  main.c
//  WorkingWithArrays
//
//  Created by Panayotis Matsinopoulos on 13/7/21.
//

#include <stdio.h>
#include <CoreFoundation/CoreFoundation.h>

typedef enum {
  Mon, Tue, Wed, Thu, Fri, Sat, Sun
} Date;

typedef struct {
  Date date;
  int maximum;
  int minimum;
} Temperature;

const void *TemperatureRetain (CFAllocatorRef allocator, const void *value) {
  return value;
}

void TemperatureRelease (CFAllocatorRef allocator, const void *value) {
  free((void *)value);
  value = NULL;
  return;
}

const char *TemperatureDate(Date d) {
  switch (d) {
    case Mon:
      return "Mon";
      break;
    case Tue:
      return "Tue";
    case Wed:
      return "Wed";
    case Thu:
      return "Thu";
    case Fri:
      return "Fri";
    case Sat:
      return "Sat";
    case Sun:
      return "Sun";
    default:
      fprintf(stderr, "Wrong date: %d\n", d);
      exit(1);
  }
}

CFStringRef TemperatureCopyDescription (const void *value) {
  Temperature *pTemperature = (Temperature *)value;
  int NUMBER_OF_CHARS = 1000;
  char valueDesc[NUMBER_OF_CHARS];
  memset(valueDesc, 0, NUMBER_OF_CHARS);
  sprintf(valueDesc, "date = %s, maximum = %d, minimum = %d", TemperatureDate(pTemperature->date), pTemperature->maximum, pTemperature->minimum);
  
  return CFStringCreateWithCString(kCFAllocatorDefault, valueDesc, CFStringGetSystemEncoding());
}

void TemperatureAppend(CFMutableArrayRef temperatures, Date date, int maximum, int minimum) {
  Temperature *temperature = malloc(sizeof(Temperature));

  temperature->date = date;
  temperature->maximum = maximum;
  temperature->minimum = minimum;

  CFArrayAppendValue(temperatures, temperature);
}

int main(int argc, const char * argv[]) {
  CFArrayCallBacks callbacks;
  callbacks.version = 0;
  callbacks.retain = TemperatureRetain;
  callbacks.release = TemperatureRelease;
  callbacks.copyDescription = TemperatureCopyDescription;
  
  CFMutableArrayRef cfTemperatures = CFArrayCreateMutable(kCFAllocatorDefault, 0, &callbacks);

  TemperatureAppend(cfTemperatures, Mon, 41, 39);
  TemperatureAppend(cfTemperatures, Tue, 40, 38);
  TemperatureAppend(cfTemperatures, Wed, 38, 35);
  TemperatureAppend(cfTemperatures, Thu, 39, 37);
  TemperatureAppend(cfTemperatures, Fri, 42, 39);
  TemperatureAppend(cfTemperatures, Sat, 37, 35);
  TemperatureAppend(cfTemperatures, Sun, 36, 34);
  
  CFShow(cfTemperatures);
  
  CFRelease(cfTemperatures);
  
  printf("Bye!\n");
  
  return 0;
}
