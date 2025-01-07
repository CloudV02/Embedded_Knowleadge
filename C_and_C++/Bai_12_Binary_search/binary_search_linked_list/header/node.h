
#include "../header/main.h"

#ifndef     __NODE_H__
#define     __NODE_H__

typedef struct Node_Member{

    InfoMember dataMember;
    struct Node_Member *next_Node;
    struct Node_Member *last_Node;
}Node_Member;
static Node_Member *HEAD_Node = NULL;

void New_Node(const InfoMember infoMember);
void Sort_Member(Node_Member *Node);


#endif