# Data :   
   
Successive individuals with Non-duplicated

   

# Methods :   


**Set InitSet(const int ( * sort_criteria)(ItemType a, ItemType b))**   
Return new Set.      
Function sort_criteria determines type of Set and order (ascending or descending) of printing element in PrintAllElment.    
If sort_criteria returns positive integer in      
a > b --> ascending order        
a < b --> desending order.       

**int GetSizeSet(const Set existing_set)**   
Return existing_set size (the number of individuals). 

**bool IsEmptySet(const Set existing_set)**   
If existing_set is empty , return true.     
Otherwise , return false. 
     
**void PrintAllElementSet(const Set existing_set)**    
Print all element of existing_set.    

**void AddElementSet(Set existing_set, const ItemType item_to_add)**      
Add new element(item_to_add) to existing_set.    

**void RemoveElementSet(Set existing_set, const ItemType item_to_remove)**      
Remove element(item_to_remove) from existing_set.    

**bool IsElementSet(const Set existing_set, const ItemType item_to_check)**        
If element(item_to_check) is element of existing_set , return true.
Otherwise , return false.     

**bool IsSubSet(const Set compare_set, const Set checked_set)**       
If checked_set is subset of compare_set , return true.
Otherwise , return false.    

**Set GetUnionSet(const Set A, const Set B)**     
Return union Set of A and B.    

**Set GetIntersectSet(const Set A, const Set B)**   
Return intersect Set of A and B.     

**Set GetSubtractSet(const Set A, const Set B)**   
Return subtract Set (A - B).     

**void RemoveSet(Set * remove_set_address)**  
Remove Set.    


# Exceptions :

**Memory Lack**   
InitSet 

**DifferentKindSet**   
IsSubset , GetUnionSet , GetIntersectSet , GetSubtractSet

**EmptySet**   
RemoveElementSet     

**DeallocatedSet**   
GetSizeSet , IsEmptySet , PrintAllElementSet , AddElementSet , RemoveElementSet , IsElementSet , IsSubSet , GetUnionSet , GetIntersectSet    
GetSubtractSet , RemoveSet

# besides : 

**Set.h**   
User can modify type of item.   

![화면 캡처 2023-07-07 004736](https://github.com/woo-in/DATA-STRUCTURES-Principles-and-Applications/assets/69314509/9ebc4f6c-b37d-4b07-82cb-8467ee4a4f69)

