# Data :   
   
Successive individuals.

   

# Methods :   

**Queue InitQueue()**   
Return new Queue.     

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

**Empty Queue**   
DeQueue , GetFrontItem      

**Deallocated Queue**   
 IsEmptyQueue , EnQueue , DeQueue , GetFrontItem , RemoveQueue      

# besides : 

**Queue.h**   
User can modify type of item.      

![화면 캡처 2023-07-19 002751](https://github.com/woo-in/DATA-STRUCTURES-Principles-and-Applications/assets/69314509/b839d7c0-82ee-4d96-9cc3-fb5c9e5c5826)
