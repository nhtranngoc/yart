/*
 * This include file describes the functions exported by clock.c
 */
#ifndef __CLOCK_H
#define __CLOCK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/*
 * Definitions for functions being abstracted out
 */
void milli_sleep(uint32_t);
uint32_t mtime(void);
void clock_setup(void);

#ifdef __cplusplus
}
#endif

#endif /* generic header protector */

