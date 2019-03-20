#include "CanFIFO.h"
/***************************************************************
  * @brief     ��ʼ��FIFO��д��0
  * @param     theFIFO : FIFO��ע����Ϣ
  * @retval    ��
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
  * @brief     ��FIFO����д������
  * @param     theFIFO : FIFO��ע����Ϣ
  *            Data    : д�������
  * @retval    д���Ƿ�ɹ� 1���ɹ�  0��ʧ�ܣ���������
  **************************************************************/
uint8_t CanFIFOWrite(aCanFIFO* theFIFO, uint8_t Data){
	if(theFIFO->un16_Count>=theFIFO->un16_maxSize){//��������
		return 0;
	}else{

		theFIFO->un16_Count++;//������һ
		*theFIFO->un8_Write=Data;//��������
		if(theFIFO->un8_Write+1>&theFIFO->un8_list[theFIFO->un16_maxSize-1]) {
			theFIFO->un8_Write=theFIFO->un8_list;//��ͷ��ʼд
		} else {
		theFIFO->un8_Write++;
		}
		return 1;
	}

}
/***************************************************************
  * @brief     ��FIFO�����������
  * @param     theFIFO : FIFO��ע����Ϣ
  * @retval    ��ȡ��ֵ
  **************************************************************/
uint8_t CanFIFORead(aCanFIFO* theFIFO){
	uint8_t tmp=0;
	if(theFIFO->un16_Count<=0)
        return 0;
    tmp=*theFIFO->un8_Read;
	*theFIFO->un8_Read=0;//��ȡ�����0
	theFIFO->un16_Count--;
		if(theFIFO->un8_Read+1>&theFIFO->un8_list[theFIFO->un16_maxSize-1]) {
			theFIFO->un8_Read=theFIFO->un8_list;//��ͷ��ʼ��
		}
		else {
            theFIFO->un8_Read++;
		}
		return tmp;
}
