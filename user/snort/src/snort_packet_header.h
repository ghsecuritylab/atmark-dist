#ifndef __SNORT_PKT_HEADER_H__
#define __SNORT_PKT_HEADER_H__

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifdef WIN32
#include <winsock2.h>
#else
#include <sys/time.h>
#endif

#include <stdlib.h>
#include <time.h>
#include <sys/types.h>


/* this is equivalent to the pcap pkthdr struct, but we need one for
 * portability once we introduce the pa_engine code 
 */
typedef struct _SnortPktHeader
{
    struct timeval ts;     /* packet timestamp */
    u_int32_t caplen;      /* packet capture length */
    u_int32_t pktlen;      /* packet "real" length */
} SnortPktHeader;


#endif // __SNORT_PKT_HEADER_H__
