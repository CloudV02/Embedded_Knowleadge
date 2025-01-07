#include "../header/node.h"


void New_Node(const InfoMember infoMember){
    Node_Member *Node = (Node_Member*)malloc(sizeof(Node_Member));
    Node->dataMember.c_address = infoMember.c_address;
    Node->dataMember.c_fullName = infoMember.c_fullName;
    Node->dataMember.l_numberPhone = infoMember.l_numberPhone;
    Node->dataMember.u16_age = infoMember.u16_age;
    Node->next_Node = NULL;

    if(HEAD_Node == NULL){
        HEAD_Node = Node;
        Node->last_Node = NULL;
        return;
    }
    Node_Member *ptr = HEAD_Node;
    if (HEAD_Node->next_Node == NULL)
    {
        Node->last_Node = HEAD_Node;
    }
    while (ptr->next_Node != NULL) /* 0-1-2-NULL */
    {
        if(ptr->next_Node->next_Node==NULL){
            Node->last_Node = ptr->next_Node;
        }
        ptr = ptr->next_Node;
    }
    ptr->next_Node = Node;
    
    Sort_Member(Node);
}

void Sort_Member(Node_Member *Node)
{
    Node_Member *ptr = Node->last_Node;
    while (ptr->dataMember.l_numberPhone > Node->dataMember.l_numberPhone)
    {
        if(ptr->next_Node->next_Node != NULL){
            ptr->next_Node->next_Node->last_Node = ptr;
        }
        if (ptr->last_Node == NULL)
        {
            ptr->next_Node = Node->next_Node;
            Node->last_Node = ptr->last_Node;
            Node->next_Node = ptr;
            ptr->last_Node = Node;
            ptr = ptr->last_Node;
            HEAD_Node = ptr;
            return ;
        }
        ptr->last_Node->next_Node = ptr->next_Node;
        ptr->next_Node = Node->next_Node;
        Node->last_Node = ptr->last_Node;
        Node->next_Node = ptr;
        ptr->last_Node = Node;
        ptr = ptr->last_Node->last_Node;
    }
    
}
