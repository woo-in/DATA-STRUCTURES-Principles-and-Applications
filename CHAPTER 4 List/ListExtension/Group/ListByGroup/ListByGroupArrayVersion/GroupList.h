#ifndef GROUP_LIST_H
#define GROUP_LIST_H


////////////////////////////////////////////////////////
#define MAX_GROUP_LENGTH 10 
typedef int ItemType; 
// suppose that group name : 1 , 2 , 3 , ... (integer) 
////////////////////////////////////////////////////////



typedef struct GroupListType* GroupList; 

GroupList InitGroupList();
void AddLastElementGroupList(GroupList q_list, const ItemType add_item, const int designated_group);
void PrintDesignatedElementGroupList(const GroupList q_list, const int designated_group);
void RemoveAllElementDesignatedGroupList(GroupList q_list, const int designated_group);
void RemoveGroupList(GroupList* remove_group_list_address);

static void ErrorHandingFunction(enum ERROR_CODE code);

#endif