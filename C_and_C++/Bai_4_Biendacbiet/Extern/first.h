#ifndef __FIRST_H_
#define __FIRST_H_
#include <stdio.h>

/* nghĩa là nó sẽ lấy variable first_number and second_number another file, if 2 value is undefined from another file, it cannot find the value, bởi vì trên thực tế 2 biến này chưa được khai báo, extern này chỉ lấy các biến đã được khai báo từ file khác, nghĩa là phải định nghĩa 2 biến first and second_number từ 1 trong 2 file.c là first.c hoặc main.c */
extern int first_number;
extern int second_number;
int Tong(int a, int b);
#endif