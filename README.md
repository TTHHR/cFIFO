# cFIFO
c语言先入先出队列

用法

uint8_t RxData[90];
aCanFIFO canFifo={90,RxData,RxData,RxData,0};

写入
for(length=0;length<RxMessage.DLC;length++)
	{
		CanFIFOWrite(&canFifo,RxMessage.Data[length]);
	}
  
  读取
  for(tmp=0;tmp<length;tmp++)
		data[tmp]=CanFIFORead(&canFifo);


# StringTool
c语言字符串工具

用法

看源代码