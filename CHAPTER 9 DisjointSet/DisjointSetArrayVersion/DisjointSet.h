#ifndef _DISJOINT_SET_H_
#define _DISJOINT_SET_H_ 

#define MAX_ELEMENT_COUNT 100 // possible element --> (0 ~ 99) 
typedef struct DisjointSetType* DisjointSet; // incompelete type of information hiding 

DisjointSet InitializeDisjointSet();
void AddElementInDisjointSet(DisjointSet current_disjoint_set, const char current_set_name, const int current_element);
char GetSetNameOfElementInDisjointSet(DisjointSet current_disjoint_set, const int current_element); 
void ChangeAllElementOfSetInDisjointSet(DisjointSet current_disjoint_set, const char before_change_set, const char after_change_set); 
void RemoveDisjointSet(DisjointSet* removing_disjoint_set_address); 


#endif 