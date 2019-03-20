#ifndef __StringTool_H
#define	__StringTool_H

#include <string.h>

int startWith(char source[] ,char sub[]);
int endWith(char source[] ,char sub[]);
int containWith(char source[] ,char sub[]);
int subString(char source[],char substr[],int start,int end);
#endif /*__StringTool_H*/
