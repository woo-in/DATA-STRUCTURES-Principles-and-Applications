#ifndef GROUP_LIST_H
#define GROUP_LIST_H

#include <stdbool.h>

/////////////////////////////////////////////////////////////////////////////
typedef int ItemType; // user can modify type of item                      //
typedef char GroupType; // user can modify type of group                   // 
///////////////////////////////////////////////////////////////////////////// 

typedef struct GroupListType* GroupList; // incompelete type of information hiding 

GroupList InitGroupList();
void AddLastElementGroupList(GroupList q_list, const ItemType add_item, const GroupType add_group);
void PrintDesignatedElementGroupList(const GroupList q_list, const GroupType designated_group);
void RemoveDesignatedElementGroupList(GroupList q_list, const GroupType designated_group);
void RemoveGroupList(GroupList* remove_group_list_address);

static void ErrorHandingFunction(enum ERROR_CODE code);

static struct Node* Get_Node(); 
#endif 