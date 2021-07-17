//
//  Temperature.h
//  WorkingWithArrays
//
//  Created by Panayotis Matsinopoulos on 17/7/21.
//

#ifndef Temperature_h
#define Temperature_h
#include <CoreFoundation/CoreFoundation.h>

typedef enum {
  Mon, Tue, Wed, Thu, Fri, Sat, Sun
} Date;

typedef struct {
  Date date;
  int maximum;
  int minimum;
} Temperature;

const char *TemperatureDate(Date d);
const void *TemperatureRetain (CFAllocatorRef allocator, const void *value);

void TemperatureRelease (CFAllocatorRef allocator, const void *value);

CFStringRef TemperatureCopyDescription (const void *value);

void TemperatureAppend(CFMutableArrayRef temperatures, Date date, int maximum, int minimum);

extern const CFArrayCallBacks kTemperatureCallbacks;

#endif /* Temperature_h */
