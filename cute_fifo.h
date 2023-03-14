#ifndef CUTE_FIFO_H
#define CUTE_FIFO_H
#include "stdint.h"
#include "stdio.h"
#include "string.h"
#define RET_ERR (0)
#define RET_OK (1)
typedef struct fifo_t
{
    uint16_t max;   //最大个数
    uint16_t num;   //当前实际个数
    uint16_t wp;    //写指针
    uint16_t rp;    //读指针
    void *p;        //数据池指针
}fifo;
/**
 * @brief fifo对象初始化
 * @param f fifo对象
*/
void fifo_reset(fifo* f);
/**
 * @brief 向fifo中推数据
 * @param f fifo对象
 * @param data 待推进去的数据
 * @return push结果
*/
uint8_t fifo_push(fifo *f,uint8_t data);
/**
 * @brief 从fifo中取数据
 * @param f fifo对象
 * @param data 取出数据后的数据指针
 * @return 取数据结果 
 */
uint8_t fifo_pull(fifo *f,uint8_t *data);
/**
 * @brief 向fifo中推变长数据
 * @param f fifo对象
 * @param data 待推进去的数据
 * @return push结果
*/
uint8_t fifo_push_bytes(fifo *f,uint8_t *data,uint16_t length);
/**
 * @brief 从fifo中取变长数据
 * @param f fifo对象
 * @param data 取出数据后的数据指针
 * @return 取数据结果 
 */
uint8_t fifo_pull_bytes(fifo *f,uint8_t *data,uint16_t length);
#endif