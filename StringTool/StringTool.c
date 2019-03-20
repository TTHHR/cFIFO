/******************************************************
 *     COPYRIGHT NOTICE
 *     Copyright (c) 2018,上海锐铎自动化有限公司
 *     All rights reserved.
 *
 * @file       StringTool.c
 * @brief      字符串的操作
 * @author     田浩然
 * @version    1.0
 * @date       2018.3.15
 *******************************************************/



#include "StringTool.h"

/***************************************************************
  * @brief     判断字符串是否为指定字符串开始
  * @param     source  :等待判断的字符串
  *            sub    : 指定的字符串
  * @retval    是否符合指定字符串开始 1：符合  0：不符合
  **************************************************************/
int startWith(char source[] ,char sub[]){
		int isStartWith=1;
		int i=strlen(sub);
	if(i>strlen(source))//子字符串比原字符串还长，直接判定不符合
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
  * @brief     判断字符串是否为指定字符串结束
  * @param     source  :等待判断的字符串
  *            sub    : 指定的字符串
  * @retval    是否符合指定字符串开始 1：符合  0：不符合
  **************************************************************/
int endWith(char source[] ,char sub[]){
		int isEndWith=1;
		int i=strlen(sub);
	int length=strlen(source);
	if(i>length)//子字符串比原字符串还长，直接判定不符合
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
  * @brief     判断字符串是否包含指定字符串
  * @param     source  :等待判断的字符串
  *            sub    : 指定的字符串
  * @retval    是否包含指定字符串 1：符合  0：不符合
  **************************************************************/
int containWith(char source[] ,char sub[]){
		int isContainWith=1;
		int i=strlen(sub);
	int length=strlen(source);
	if(i>length)//子字符串比原字符串还长，直接判定不符合
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
  * @brief     获取字符串的子字符串
  * @param     source  :原始字符串
  *            substr    : 子字符串
  * @retval    子字符穿的长度
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



