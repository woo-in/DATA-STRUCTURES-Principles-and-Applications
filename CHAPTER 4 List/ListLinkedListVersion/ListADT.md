# Data :   
   
Successive individuals

   

# Methods :   

rank : 1 , 2 , 3 , 4 , 5 ...

**List InitList()**   
Return new list. 

**int GetSizeList(List q_list)**   
Return q_list size (the number of individuals). 

**bool IsEmptyList(List q_list)**   
If q_list is empty , return true.     
Otherwise , return false. 

**ItemType GetRankElementList(List q_list, int rank)**   
Return specific rank item of q_list.

**void ChangeRankElementList(List q_list, int rank, ItemType replace_item)**   
Replace specific rank item of q_list to replace_item.  

**void AddRankElementList(List q_list, int rank, ItemType add_item)**   
Add add_item specific rank of q_list.    
Rest of the part follows next.

**void AddFirstElementList(List q_list, ItemType add_item)**   
Add add_item to first rank of q_list.    
Rest of the part follows next.  

**void AddLastElementList(List q_list, ItemType add_item)**   
Add add_item to the end of present part of q_list.

**ItemType RemoveRankElementList(List q_list, const int rank)**   
Remove specific rank of q_list and return it.   
Rest of the part will be pulled.

**ItemType RemoveFirstElementList(List q_list)**   
Remove first rank of q_list and return it.    
Rest of the part will be pulled. 

**ItemType RemoveLastElementList(List q_list)**   
Remove last rank of q_list and return it.   

**void RemoveList(List * remove_list_address)**  
Remove List.

# Exceptions :

**Memory Lack**   
InitList

**Invalid Rank**   
GetRankElementList , ChangeRankElementList , AddRankElementList , RemoveRankElementList

**Empty List**   
RemoveRankElementList , RemoveFirstElementList , RemoveLastElementList

**Deallocated list**   
GetSizeList , IsEmptyList , GetRankElementList , AddLastElementList , AddFirstElementList , AddRankElementList , ChangeRankElementList , RemoveLastElementList , RemoveFirstElementList , RemoveRankElementList , RemoveList

# besides : 

**ListArrayVersion.h**   
User can modify type of item.   

![usercan](https://github.com/woo-in/DATA-STRUCTURES-Principles-and-Applications/assets/69314509/c161f1be-1ea1-40e6-ba8e-cae2b1cd983c)

