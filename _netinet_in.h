#ifndef __GK_NETINET_IN_H
#define __GK_NETINET_IN_H

/* here we keep structure definitions and constants for networking that are required in both
     kernel and user space */
#include <inttypes.h>

typedef uint16_t in_port_t;
typedef uint32_t in_addr_t;

typedef uint32_t sa_family_t;
typedef uint32_t socklen_t;

struct sockaddr
{
    sa_family_t     ss_family;
};

struct in_addr
{
    in_addr_t       s_addr;
};

struct sockaddr_in
{
    sa_family_t     sin_family;
    struct in_addr  sin_addr;
    in_port_t       sin_port;
};

#define IPPROTO_RAW     0x7fffffff
#define IPPROTO_IP      0x0800
#define IPPROTO_TCP     0x06
#define IPPROTO_UDP     0x11
#define IPPROTO_ICMP    0x01

#define AF_UNIX         0
#define AF_INET         1

#define SOCK_DGRAM      0
#define SOCK_RAW        1
#define SOCK_SEQPACKET  2
#define SOCK_STREAM     3

#endif
