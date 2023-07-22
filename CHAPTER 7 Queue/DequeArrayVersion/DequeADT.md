# Data :   
   
Successive individuals.

   

# Methods :   

**Deque InitDeque()**   
Return new Deque.     

**int GetSizeDeque(Deque current_deque)**   
Return current_deque size (the number of individuals). 

**bool IsEmptyDeque(Deque current_deque)**   
If current_deque is empty , return true.     
Otherwise , return false.     

**ItemType GetFrontItem(Deque current_deque)**         
Return front element of current_deque.     

**ItemType GetRearItem(Deque current_deque)**       
Return rear element of current_deque.     

**void InsertRearDeque(Deque current_deque, const ItemType inserting_item)**         
Insert inserting_item to rear of current_deque.      

**ItemType DeleteRearDeque(Deque current_deque)**         
Return and delete item from rear of current deque.      

**void InsertFrontDeque(Deque current_deque, const ItemType inserting_item)**         
Insert inserting_item to front of current_deque.        

**ItemType DeleteFrontDeque(Deque current_deque)**        
Return and delete item from front of current deque.       

**void RemoveDeque(Deque * removing_deque)**       
Remove deque.       

# Exceptions :

**Memory Lack**   
InitStack     

**Full Deque**   
InsertRearDeque , InsertFrontDeque       

**Empty Deque**      
GetFrontItem , GetRearItem , DeleteRearDeque , DeleteFrontDeque       

**Deallocated Deque**        
GetSizeDeque , IsEmptyDeque , GetFrontItem , GetRearItem , InsertRearDeque , DeleteRearDeque , InsertFrontDeque , DeleteFrontDeque , RemoveDeque      

# besides : 

**Deque.h**   
User can modify max length of deque and type of item.      
![화면 캡처 2023-07-22 010949](https://github.com/woo-in/DATA-STRUCTURES-Principles-and-Applications/assets/69314509/66835cbd-5083-48cd-b904-b7f265bfc587)
