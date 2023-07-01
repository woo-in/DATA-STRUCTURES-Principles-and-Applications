#ifndef LIST_ARRAY_VERSION_H
#define LIST_ARRAY_VERSION_H

#include <stdbool.h>

/////////////////////////////////////////////////////////////////////////
#define MAX_LIST_LENGTH 10 // user can modify max length of list       //
typedef int ItemType ;// user can modify type of item                 // 
///////////////////////////////////////////////////////////////////////// 


typedef struct ListType* List; // incompelete type of information hiding 

List InitList();
int GetSizeList(List q_list);
bool IsEmptyList(List q_list);
ItemType GetRankElementList(List q_list, int rank);
void ChangeRankElementList(List q_list, int rank, ItemType replace_item);
void AddRankElementList(List q_list, int rank, ItemType add_item);
void AddFirstElementList(List q_list, ItemType add_item);
void AddLastElementList(List q_list, ItemType add_item);
ItemType RemoveRankElementList(List q_list, const int rank);
ItemType RemoveFirstElementList(List q_list);
ItemType RemoveLastElementList(List q_list);
void RemoveList(List* remove_list_address);
static void ErrorHandingFunction(enum ERROR_CODE code);


#endif 
