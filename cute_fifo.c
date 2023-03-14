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
    return RET_OK;
}
/**
 * @brief 向fifo中推变长数据
 * @param f fifo对象
 * @param data 待推进去的数据
 * @return push结果
*/
uint8_t fifo_push_bytes(fifo *f,uint8_t *data,uint16_t length)
{
    if ((f->num + length) > f->max)
    {
        return RET_ERR;
    }
    
    if(f->wp + length >= f->max)//分段写入
    {
        uint16_t len1 = f->max - f->wp; //计算max前面可以写入的数据长度
        memcpy(f->p + f->wp, data, len1);
        memcpy(f->p, data + len1, length - len1);
        f->wp +=  length - len1;
    }
    else
    {
        memcpy(f->p + f->wp,data,length);
        f->wp += length;
    }
    f->num += length;
    return RET_OK;
}
/**
 * @brief 从fifo中取变长数据
 * @param f fifo对象
 * @param data 取出数据后的数据指针
 * @return 取数据结果 
 */
uint8_t fifo_pull_bytes(fifo *f,uint8_t *data,uint16_t length)
{
    if (length > f->num)
    {
        return RET_ERR;
    }

    if (f->max - f->rp < length)
    {
        uint16_t len1 = f->max - f->rp;
        memcpy(data,f->p + f->rp,len1);
        memcpy(data + len1,f->p,length - len1);
        f->rp += (length - len1);
    }
    else
    {
        memcpy(data,f->p + f->rp,length);
        f->rp+= length;
    }
    f->num-= length;
    return RET_OK;
}