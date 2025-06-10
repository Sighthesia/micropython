#ifndef MICROPY_INCLUDED_STM32_LWIP_LWIPOPTS_H
#define MICROPY_INCLUDED_STM32_LWIP_LWIPOPTS_H

#define LWIP_NETIF_EXT_STATUS_CALLBACK  1

#define LWIP_LOOPIF_MULTICAST           1
#define LWIP_LOOPBACK_MAX_PBUFS         8

#define LWIP_IPV6                       0

#define LWIP_RAND() rng_get()

// Include common lwIP configuration.
#include "extmod/lwip-include/lwipopts_common.h"

#ifdef STM32N6
#undef MEM_SIZE
#undef TCP_MSS
#undef TCP_WND
#undef TCP_SND_BUF
#undef MEMP_NUM_TCP_SEG
#undef MEM_ALIGNMENT

#define MEM_SIZE                        (16 * 1024)
#define TCP_MSS                         (1460)
#define TCP_OVERSIZE                    (TCP_MSS)
#define TCP_WND                         (8 * TCP_MSS)
#define TCP_SND_BUF                     (8 * TCP_MSS)
#define TCP_SND_QUEUELEN                (2 * (TCP_SND_BUF / TCP_MSS))
#define TCP_QUEUE_OOSEQ                 (1)
#define MEMP_NUM_TCP_SEG                (2 * TCP_SND_QUEUELEN)
#define MEM_ALIGNMENT                   32
#endif

extern uint32_t rng_get(void);

#endif // MICROPY_INCLUDED_STM32_LWIP_LWIPOPTS_H
