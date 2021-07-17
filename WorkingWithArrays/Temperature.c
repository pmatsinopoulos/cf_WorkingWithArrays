//
//  Temperature.c
//  WorkingWithArrays
//
//  Created by Panayotis Matsinopoulos on 17/7/21.
//

#include "Temperature.h"

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

const void *TemperatureRetain (CFAllocatorRef allocator, const void *value) {
  return value;
}

void TemperatureRelease (CFAllocatorRef allocator, const void *value) {
  free((void *)value);
  value = NULL;
  return;
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

Boolean TemperatureEqual (const void *value1, const void *value2) {
  Temperature *t1 = (Temperature *)value1;
  Temperature *t2 = (Temperature *)value2;
  return (t1->date == t2->date &&
          t1->maximum == t2->maximum &&
          t1->minimum == t2->minimum);
}

const CFArrayCallBacks kTemperatureCallbacks = {
  .equal = TemperatureEqual,
  .copyDescription = TemperatureCopyDescription,
  .release = TemperatureRelease,
  .retain = TemperatureRetain,
  .version = 0
};
