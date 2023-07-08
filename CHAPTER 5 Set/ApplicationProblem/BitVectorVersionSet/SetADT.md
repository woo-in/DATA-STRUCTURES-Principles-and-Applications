# Data :   
   
Successive individuals with Non-duplicated and mappingable to integers
   

# Methods :   


**Set InitSet(const int max_set_size)**   
Return new Set.      
Range of mapped integers : 0 ~ (max_set_size - 1). 
Distinguished Set by (max_set_size). 

**int GetSizeSet(const Set existing_set)**   
Return existing_set size (the number of individuals). 

**bool IsEmptySet(const Set existing_set)**   
If existing_set is empty , return true.     
Otherwise , return false. 
     
**void PrintAllElementSet(const Set existing_set)**    
Print all element of existing_set.    

**void AddElementSet(Set existing_set, const int item_to_add)**      
Add new element(item_to_add) to existing_set.    

**void RemoveElementSet(Set existing_set, const int item_to_remove)**      
Remove element(item_to_remove) from existing_set.    

**bool IsElementSet(const Set existing_set, const int item_to_check)**        
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



**DifferentKindSet**   
IsSubset , GetUnionSet , GetIntersectSet , GetSubtractSet



**DeallocatedSet**   
GetSizeSet , IsEmptySet , PrintAllElementSet , AddElementSet , RemoveElementSet , IsElementSet , IsSubSet , GetUnionSet , GetIntersectSet    
GetSubtractSet , RemoveSet
