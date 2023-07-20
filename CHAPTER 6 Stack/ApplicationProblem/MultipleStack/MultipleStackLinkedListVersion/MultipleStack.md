# Data :   
   
Successive individuals.

   

# Methods :   

**MultipleStack InitMultipleStack(const int stack_count)**   
Return new MultipleStack.     

**bool IsEmptyMultipleStack(MultipleStack current_multiple_stack, const int current_multiple_stack_order)**       
If current_multiple_stack's specific order stack is empty , return true.     
Otherwise , return false.     

**ItemType GetTopElementMultipleStack(MultipleStack current_multiple_stack, const int current_multiple_stack_order)**      
Return top element of current_multiple_stack's specific order stack.      

**void PushMultipleStack(MultipleStack current_multiple_stack, const int current_multiple_stack_order, const ItemType pushing_element)**       
Push pushing_element to current_multiple_stack's specific order stack.     

**ItemType PopMultipleStack(MultipleStack current_multiple_stack, const int current_multiple_stack_order)**     
Pop element from current_multiple_stack's specific order stack.      

**void RemoveMultipleStack(MultipleStack * remove_multiple_stack_address)**      
Remove MultipleStack.      

# Exceptions :

**Memory Lack**   
InitMultipleStack     

**InvalidStackCount**   
InitMultipleStack       

**InvalidMultipleStackOrder**   
IsEmptyMultipleStack , GetTopElementMultipleStack , PushMultipleStack , PopMultipleStack     

**EmptyMultipleStack**   
GetTopElementMultipleStack , PopMultipleStack     

**DeallocatedMultipleStack**
IsEmptyMultipleStack , GetTopElementMultipleStack , PushMultipleStack , PopMultipleStack , RemoveMultipleStack       

# besides : 

**MultipleStack.h**   
User can modify type of item.  

![화면 캡처 2023-07-19 002751](https://github.com/woo-in/DATA-STRUCTURES-Principles-and-Applications/assets/69314509/4a76c5c8-f84c-4083-b688-eac364aa07fb)
