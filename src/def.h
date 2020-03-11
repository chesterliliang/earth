#ifndef __PRIME_DEF_
#define __PRIME_DEF_

typedef unsigned int UINT32;
typedef unsigned short UINT16;
typedef unsigned char UINT8;
#define IN
#define OUT


#define PRIME_INTERNAL
//LEN && size & time
#define PRIME_MAX_LEN            256
#define PRIME_HEADER_LEN         8
#define PRIME_CRC_LEN            2
#define PRIME_SIMPLE_CMD_LEN     10
#define PRIME_DELAY_LONG         2000000 //2s
#define PRIME_DELAY_MID          500000 //500mss
#define PRIME_DELAY_COMMON       50000   //50ms

//PACKAGE HEADER
//////OFFSET
#define PRIME_SYNC_OFFSET        0
#define PRIME_CMD_OFFSET         3
#define PRIME_COMM_OFFSET        4
#define PRIME_OP_OFFSET          5
#define PRIME_LEN_OFFSET         6
#define PRIME_DATA_OFFSET        8
//////const value
#define PRIME_SYNC_1             0x55
#define PRIME_SYNC_2             0xaa
//////command
#define PRIME_CMD_ENROLL         1
#define PRIME_CMD_IDENTIFY       2
#define PRIME_CMD_DELETE         3
#define PRIME_CMD_ABORT          4
#define PRIME_CMD_GETLIST        5
#define PRIME_CMD_GETVERSION     0x7f
#define PRIME_CMD_CALIBRATE      7 
#define PRIME_CMD_GETSTATE       0x0c 
#define PRIME_CMD_GETID         0x0d 
#define PRIME_CMD_PIN         0x53 
//Error code
#define PRIME_OK                     0
#define PRIME_ERROR_PARA             0x80
#define PRIME_ERROR_COMM             0x81
#define PRIME_ERROR_DEVICE           0x82
#define PRIME_ERROR_NO_FINGER        0x83
#define PRIME_ERROR_CRC              0x84
//enroll status
#define PRIME_STATUS_TIMEOUT         0x12
#define PRIME_STATUS_REDUNANT        0x19
#define PRIME_STATUS_BAD             0x20
#define PRIME_STATUS_GOOD            0x21
#define PRIME_STATUS_WAIT            0x25
#define PRIME_STATUS_WERID           0x26
#define PRIME_STATUS_QUICK           0x27
#define PRIME_STATUS_PART            0x28
#define PRIME_STATUS_IDLE            0x3f

//identify
#define PRIME_STATUS_MATCH           0x00
#define PRIME_STATUS_NOT_MATCH       0x01

#include "config.h"

#if (_PRIME_PLATFORM== _PRIME_LINUX_)
#include "platform/x_uart.h"
#include <unistd.h> //sleep
#include <string.h> //memcpy
#endif

#endif