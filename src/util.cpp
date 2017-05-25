/** @file util.cpp
 *  @copyright 2016 Peter Watkins. All rights reserved.
 */

#include "util.hpp"

// TODO: This looks like it was required before. Perhaps Sierra now includes it.
//#ifdef __MACH__
//#include <sys/time.h>
//clock_gettime is not implemented on OSX.
// TODO: Look into this implementation. Is this the proper thing to use
// for Linux and OS X?
// int clock_gettime(int /*clk_id*/, struct timespec* t) {
//     struct timeval now;
//     int rv = gettimeofday(&now, NULL);
//     if (rv) return rv;
//     t->tv_sec  = now.tv_sec;
//     t->tv_nsec = now.tv_usec * 1000;
//     return 0;
// }
//#endif