#include "cute_fifo.h"
#include "stdio.h"
uint8_t data_arr[5];
int main()
{
    fifo fifo_a = 
    {
        .max = 5,
        .p = data_arr,
    };
    fifo_reset(&fifo_a);
    uint8_t send_data[5] = {10,20,30,40,50};
    fifo_push_bytes(&fifo_a,send_data,5);

    uint8_t r1 = 0;
    fifo_pull(&fifo_a,&r1);
    printf("r1:%d\r\n",r1);
    fifo_pull(&fifo_a,&r1);
    printf("r1:%d\r\n",r1);
    fifo_pull(&fifo_a,&r1);
    printf("r1:%d\r\n",r1);

    uint8_t send_data1[2] = {70,80};
    fifo_push_bytes(&fifo_a,send_data1,2);

    uint8_t recv_data[5] = {0};
    fifo_pull_bytes(&fifo_a,recv_data,4);
    for(int i = 0;i<4;i++)
    {
        printf("%d\r\n",recv_data[i]);
    }
}