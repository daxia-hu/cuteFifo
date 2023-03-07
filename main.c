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
    uint8_t temp = 0;
    uint8_t ret = 0;

    fifo_push(&fifo_a,10);
    fifo_push(&fifo_a,20);
    fifo_push(&fifo_a,30);
    fifo_push(&fifo_a,40);
    fifo_pull(&fifo_a, &temp);
    fifo_pull(&fifo_a, &temp);
    fifo_push(&fifo_a,50);
    fifo_push(&fifo_a,60);

    fifo_pull(&fifo_a, &temp);
    fifo_pull(&fifo_a, &temp);
    fifo_pull(&fifo_a, &temp);
    fifo_pull(&fifo_a, &temp);
    fifo_pull(&fifo_a, &temp);
}