#ifndef CUTE_FIFO_H
#define CUTE_FIFO_H
#include "stdint.h"
#include "stdio.h"
#define RET_ERR (0)
#define RET_OK (1)
typedef struct fifo_t
{
    uint16_t max;   //������
    uint16_t num;   //��ǰʵ�ʸ���
    uint16_t wp;    //дָ��
    uint16_t rp;    //��ָ��
    void *p;        //���ݳ�ָ��
}fifo;

/**
 * @brief fifo�����ʼ��
 * @param f fifo����
*/
void fifo_reset(fifo* f);
/**
 * @brief ��fifo��������
 * @param f fifo����
 * @param data ���ƽ�ȥ������
 * @return push���
*/
uint8_t fifo_push(fifo *f,uint8_t data);
/**
 * @brief ��fifo��ȡ����
 * @param f fifo����
 * @param data ȡ�����ݺ������ָ��
 * @return ȡ���ݽ�� 
 */
uint8_t fifo_pull(fifo *f,uint8_t *data);
#endif