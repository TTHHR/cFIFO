#include "CanFIFO.h"
/***************************************************************
  * @brief     初始化FIFO，写满0
  * @param     theFIFO : FIFO的注册信息
  * @retval    无
  **************************************************************/

void CanFIFOInit(aCanFIFO* theFIFO){
	int index=0;
	for(index=0;index<theFIFO->un16_maxSize;index++){
		theFIFO->un8_list[index]=0x00;
	}
	theFIFO->un8_Read=theFIFO->un8_list;
	theFIFO->un8_Write=theFIFO->un8_list;
}

/***************************************************************
  * @brief     向FIFO里面写入数据
  * @param     theFIFO : FIFO的注册信息
  *            Data    : 写入的数据
  * @retval    写入是否成功 1：成功  0：失败，容量已满
  **************************************************************/
uint8_t CanFIFOWrite(aCanFIFO* theFIFO, uint8_t Data){
	if(theFIFO->un16_Count>=theFIFO->un16_maxSize){//容量已满
		return 0;
	}else{

		theFIFO->un16_Count++;//容量加一
		*theFIFO->un8_Write=Data;//存入数据
		if(theFIFO->un8_Write+1>&theFIFO->un8_list[theFIFO->un16_maxSize-1]) {
			theFIFO->un8_Write=theFIFO->un8_list;//从头开始写
		} else {
		theFIFO->un8_Write++;
		}
		return 1;
	}

}
/***************************************************************
  * @brief     从FIFO里面读出数据
  * @param     theFIFO : FIFO的注册信息
  * @retval    读取的值
  **************************************************************/
uint8_t CanFIFORead(aCanFIFO* theFIFO){
	uint8_t tmp=0;
	if(theFIFO->un16_Count<=0)
        return 0;
    tmp=*theFIFO->un8_Read;
	*theFIFO->un8_Read=0;//读取完毕置0
	theFIFO->un16_Count--;
		if(theFIFO->un8_Read+1>&theFIFO->un8_list[theFIFO->un16_maxSize-1]) {
			theFIFO->un8_Read=theFIFO->un8_list;//从头开始读
		}
		else {
            theFIFO->un8_Read++;
		}
		return tmp;
}
