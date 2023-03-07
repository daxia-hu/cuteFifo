#include "cute_fifo.h"
/**
 * @brief fifo对象初始化
 * @param f fifo对象
*/
void fifo_reset(fifo* f)
{
    f->num = 0;
    f->wp = 0;
    f->rp = 0;
}
/**
 * @brief 向fifo中推数据
 * @param f fifo对象
 * @param data 待推进去的数据
 * @return push结果
*/
uint8_t fifo_push(fifo *f, uint8_t data)
{
    if (f->max == f->num)
    {
        return RET_ERR;
    }
    printf("[push]-rp:%d ,wp:%d ",f->rp,f->wp);
    ((uint8_t *)f->p)[f->wp] = data;
    f->num += 1;
    if (f->max == (f->wp + 1))
    {
        f->wp = 0;
    }
    else
    {
        f->wp += 1;
    }
    printf("num:%d,data:%d\r\n",f->num,data);
    return RET_OK;
}
/**
 * @brief 从fifo中取数据
 * @param f fifo对象
 * @param data 取出数据后的数据指针
 * @return 取数据结果 
 */
uint8_t fifo_pull(fifo *f, uint8_t *data)
{
    if (0 == f->num)
    {
        return RET_ERR;
    }
    printf("pull-rp:%d ,wp:%d ",f->rp,f->wp);
    *data = ((uint8_t *)f->p)[f->rp];
    f->num -= 1;
    if (f->max == (f->rp + 1))
    {
        f->rp = 0;
    }
    else
    {
        f->rp += 1;
    }
    printf("num:%d data:%d\r\n",f->num,*data);
    return RET_OK;
}