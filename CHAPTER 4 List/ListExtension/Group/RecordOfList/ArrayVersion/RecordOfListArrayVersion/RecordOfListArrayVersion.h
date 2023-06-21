#ifndef RECORD_OF_LIST_ARRAY_VERSION_H
#define RECORD_OF_LIST_ARRAY_VERSION_H

#include <stdbool.h>

/////////////////////////////////////////////////////////////////////////////
#define MAX_GROUP_LIST_LENGTH 10 // user can modify max length of list     //
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

#endif 
