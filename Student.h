//
// Created by allenhsu on 2018/9/17.
//

#ifndef LEARNC_STUDENT_H
#define LEARNC_STUDENT_H

struct Student {
    char cName[20];  // 名字
    int iNumber;     // 学号
    struct Student *pNext;
};



int iCount;// 计算总数
struct Student *pHead; // 定义一个学生头

struct Student* Create();
void Print(struct Student* pHead);


#endif //LEARNC_STUDENT_H
