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

int main(int argc, const char * argv[]) {
  const int NUMBER_OF_TEMPERATURES = 7;
  
  Temperature temperatures[NUMBER_OF_TEMPERATURES] = {
    { .date = Mon, .maximum = 41, .minimum = 31 },
    { .date = Tue, .maximum = 40, .minimum = 32 },
    { .date = Wed, .maximum = 34, .minimum = 28 },
    { .date = Thu, .maximum = 36, .minimum = 31 },
    { .date = Fri, .maximum = 30, .minimum = 26 },
    { .date = Sat, .maximum = 40, .minimum = 35 },
    { .date = Sun, .maximum = 42, .minimum = 38 },
  };
  Temperature *pTemperatures[NUMBER_OF_TEMPERATURES];
  for(int i = 0; i < NUMBER_OF_TEMPERATURES; i++) {
    pTemperatures[i] = &temperatures[i];
  }
  
  CFArrayCallBacks callbacks;
  callbacks.version = 0;
  callbacks.retain = TemperatureRetain;
  callbacks.release = TemperatureRelease;
  callbacks.copyDescription = TemperatureCopyDescription;
  
  CFArrayRef cfTemperatures = CFArrayCreate(kCFAllocatorDefault, (const void **)pTemperatures, NUMBER_OF_TEMPERATURES, &callbacks);
  
  CFShow(cfTemperatures);
  
  CFRelease(cfTemperatures);
  
  printf("Bye!\n");
  
  return 0;
}
