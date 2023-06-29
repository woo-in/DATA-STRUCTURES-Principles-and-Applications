#ifndef LIST_H
#define LIST_H

/////////////////////////////////////////////////////////////////////////
#define MAX_LIST_LENGTH 10 // user can modify max length of list       //
typedef int ItemType;// user can modify type of item                 // 
///////////////////////////////////////////////////////////////////////// 


typedef struct ListType* List; // incompelete type of information hiding 

List InitList();
int GetSizeList(List q_list);
ItemType GetRankElementList(List q_list, int rank);
void ChangeRankElementList(List q_list, int rank, ItemType replace_item);
void AddRankElementList(List q_list, int rank, ItemType add_item);
ItemType RemoveRankElementList(List q_list, const int rank);
void RemoveList(List* remove_list_address);
static void ErrorHandingFunction(enum ERROR_CODE code);

void PRINT(List q_list);


#endif 