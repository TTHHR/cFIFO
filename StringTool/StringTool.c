/******************************************************
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2018,�Ϻ������Զ������޹�˾
 *     All rights reserved.
 *
 * @file       StringTool.c
 * @brief      �ַ����Ĳ���
 * @author     ���Ȼ
 * @version    1.0
 * @date       2018.3.15
 *******************************************************/



#include "StringTool.h"

/***************************************************************
  * @brief     �ж��ַ����Ƿ�Ϊָ���ַ�����ʼ
  * @param     source  :�ȴ��жϵ��ַ���
  *            sub    : ָ�����ַ���
  * @retval    �Ƿ����ָ���ַ�����ʼ 1������  0��������
  **************************************************************/
int startWith(char source[] ,char sub[]){
		int isStartWith=1;
		int i=strlen(sub);
	if(i>strlen(source))//���ַ�����ԭ�ַ���������ֱ���ж�������
    {
        return 0;
    }

		for(i--;i>=0;i--)
	{
			if(sub[i]!=source[i]) {
				isStartWith=0;
				break;
			}
	}
		
	return isStartWith;
}

/***************************************************************
  * @brief     �ж��ַ����Ƿ�Ϊָ���ַ�������
  * @param     source  :�ȴ��жϵ��ַ���
  *            sub    : ָ�����ַ���
  * @retval    �Ƿ����ָ���ַ�����ʼ 1������  0��������
  **************************************************************/
int endWith(char source[] ,char sub[]){
		int isEndWith=1;
		int i=strlen(sub);
	int length=strlen(source);
	if(i>length)//���ַ�����ԭ�ַ���������ֱ���ж�������
    {
        return 0;
    }

for(i--,length--;i>=0;i--,length--)
	{
			if(sub[i]!=source[length]) {
				isEndWith=0;
				break;
			}
	}
	return isEndWith;
}

/***************************************************************
  * @brief     �ж��ַ����Ƿ����ָ���ַ���
  * @param     source  :�ȴ��жϵ��ַ���
  *            sub    : ָ�����ַ���
  * @retval    �Ƿ����ָ���ַ��� 1������  0��������
  **************************************************************/
int containWith(char source[] ,char sub[]){
		int isContainWith=1;
		int i=strlen(sub);
	int length=strlen(source);
	if(i>length)//���ַ�����ԭ�ַ���������ֱ���ж�������
    {
        return 0;
    }
		if(strstr(source,sub)==NULL)
		{
			isContainWith=0;
		}

	return isContainWith;
}

/***************************************************************
  * @brief     ��ȡ�ַ��������ַ���
  * @param     source  :ԭʼ�ַ���
  *            substr    : ���ַ���
  * @retval    ���ַ����ĳ���
  **************************************************************/

int subString(char source[],char substr[],int start,int end){
    int i=0;
    int length=strlen(source);
    if(start<0||start>length-1||end<start||end>length-1)
        return 0;
    for(i=0;start<=end;start++,i++)
        substr[i]=source[start];

    substr[i]='\0';

    return i;
}



