#ifndef __CANFIFO_H
#define	__CANFIFO_H

#include "POM_stm32f103.h"

typedef struct {
uint16_t un16_maxSize;  //�����������
  uint8_t *un8_list;      //����������
  uint8_t *un8_Read;     //��ָ��
  uint8_t *un8_Write;    //дָ��
  uint16_t un16_Count;    //��ǰ���ݸ���
}aCanFIFO; 



void CanFIFOInit(aCanFIFO* theFIFO);
uint8_t CanFIFOWrite(aCanFIFO* theFIFO, uint8_t Data);
uint8_t CanFIFORead(aCanFIFO* theFIFO);




#endif /*__CANFIFO_H*/
