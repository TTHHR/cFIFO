#ifndef __CANFIFO_H
#define	__CANFIFO_H

#include "POM_stm32f103.h"

typedef struct {
uint16_t un16_maxSize;  //数组最大容量
  uint8_t *un8_list;      //被控制数组
  uint8_t *un8_Read;     //读指针
  uint8_t *un8_Write;    //写指针
  uint16_t un16_Count;    //当前数据个数
}aCanFIFO; 



void CanFIFOInit(aCanFIFO* theFIFO);
uint8_t CanFIFOWrite(aCanFIFO* theFIFO, uint8_t Data);
uint8_t CanFIFORead(aCanFIFO* theFIFO);




#endif /*__CANFIFO_H*/
