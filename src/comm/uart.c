#include "def.h"
#include "x_uart.h"
#include "uart.h"

UINT32 prime_uart_write(
    UINT8    *data,
    UINT16    len
)
{
#if (_PRIME_PLATFORM== _PRIME_LINUX_)
    UINT32 rv = 0;
    rv = uart_write(data,len);
    if(rv>0)
        return PRIME_OK;
    else
        return PRIME_ERROR_COMM;
#endif

}

UINT32 prime_uart_read(
    UINT8    *data,
    UINT16    len
)
{
#if (_PRIME_PLATFORM== _PRIME_LINUX_)
    int rv = 0;
    rv = uart_read(data,len);
    //printf("tmp read len = %d \n", rv);
    if(rv>0){
       // printf("tmp OK\n");
        return PRIME_OK;
    }   
    else{
       // printf("tmp err\n");
        return PRIME_ERROR_COMM;
    }
        
#endif
}