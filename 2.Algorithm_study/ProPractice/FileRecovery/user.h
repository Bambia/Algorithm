#pragma once
#ifndef USER_H_
#define USER_H_

#define MAX_DELETE		1000

typedef struct
{
	int count;
	int delDataList[MAX_DELETE];
}RESULT;

RESULT compareFile();

#endif /* USER_H_ */