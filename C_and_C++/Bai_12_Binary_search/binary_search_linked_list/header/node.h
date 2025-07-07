/***************************************************************************
 * @file    node.h
 * @brief   Khai báo các hàm và cấu trúc liên quan đến node
 * @details File này cung cấp giao diện cho việc điều khiển động cơ, bao gồm
 *          khởi tạo, đặt tốc độ, và dừng động cơ.
 * @version 1.0
 * @date    2025-02-24
 * @author  Lê Phúc Lâm
 ***************************************************************************/

#ifndef     __NODE_H__
#define     __NODE_H__
#include "../header/main.h"
typedef struct Node_Member{

    InfoMember dataMember;
    struct Node_Member *next_Node;
    struct Node_Member *last_Node;
}Node_Member;


void New_Node(const InfoMember infoMember);
void Sort_Member(Node_Member *Node);


#endif