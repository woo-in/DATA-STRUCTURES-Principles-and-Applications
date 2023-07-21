# Data :   
   
Successive individuals.

   

# Methods :   

**Queue InitQueue()**   
Return new Queue.     

**int GetSizeQueue(Queue current_queue)**   
Return current_queue size (the number of individuals). 

**bool IsEmptyQueue(Queue current_queue)**   
If current_queue is empty , return true.     
Otherwise , return false.     

**ItemType GetFrontItem(Queue current_queue)**
Return front element of current_queue.     

**void EnQueue(Queue current_queue, const ItemType inserting_item)**
Push inserting_item to current_queue.       

**ItemType DeQueue(Queue current_queue)**     
Pop element from current_queue.     

**void RemoveQueue(Queue * removing_queue)**  
Remove queue.     

# Exceptions :

**Memory Lack**   
InitStack     

**Full Queue**   
EnQueue     

**Empty Queue**   
DeQueue , GetFrontItem      

**Deallocated Queue**   
GetSizeQueue , IsEmptyQueue , EnQueue , DeQueue , GetFrontItem , RemoveQueue      

# besides : 

**Queue.h**   
User can modify max length of queue and type of item.     

![화면 캡처 2023-07-21 175034](https://github.com/woo-in/DATA-STRUCTURES-Principles-and-Applications/assets/69314509/eb98d67d-18e0-4f6c-83f6-eddfc9fabbe8)

