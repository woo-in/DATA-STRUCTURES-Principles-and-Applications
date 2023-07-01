
# Data :   
   
Successive individuals

   

# Methods :   

rank : 1 , 2 , 3 , 4 , 5 ...

**List InitList()**   
Return new list. 

**int GetSizeList(List q_list)**   
Return q_list size (the number of individuals). 

**void ChangeRankElementList(List q_list, int rank, ItemType replace_item)**   
Replace specific rank item of q_list to replace_item.  

**void AddRankElementList(List q_list, int rank, ItemType add_item)**   
Add add_item specific rank of q_list.    
Rest of the part follows next.

**ItemType RemoveRankElementList(List q_list, const int rank)**   
Remove specific rank of q_list and return it.   
Rest of the part will be pulled.

**void RemoveList(List * remove_list_address)**  
Remove List.  

# Exceptions :

**Memory Lack**   
InitList

**Invalid Rank**   
ChangeRankElementList , AddRankElementList , RemoveRankElementList

**Full List**   
AddRankElementList    

**Empty List**   
RemoveRankElementList    

**Deallocated list**   
GetSizeList , GetRankElementList , AddRankElementList , RemoveRankElementList , RemoveList , ChangeRankElementList

# besides : 

**List.h**   
User can modify max length of list and type of item.    
( real max length is (MAX_LIST_LENGTH - 1 ) )


![githubn](https://github.com/woo-in/DATA-STRUCTURES-Principles-and-Applications/assets/69314509/a6f66287-8941-4d63-a255-7f0a2fd3f719)
