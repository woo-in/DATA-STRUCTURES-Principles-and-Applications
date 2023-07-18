# Data :   
   
Successive individuals.

   

# Methods :   

**MultipleStack InitMultipleStack(const int total_stack_length, const int stack_count)**   
Return new MultipleStack.     

**int GetSizeMultipleStack(const MultipleStack current_multiple_stack, const int current_multiple_stack_order)**   
Return current_multiple_stack's specific order stack size (the number of individuals).     

**bool IsEmptyMultipleStack(const MultipleStack current_multiple_stack, const int current_multiple_stack_order)**       
If current_multiple_stack's specific order stack is empty , return true.     
Otherwise , return false.     

**bool IsFullMultipleStack(const MultipleStack current_multiple_stack, const int current_multiple_stack_order)**      
If current_multiple_stack's specific order stack is full , return true.     
Otherwise , return false.     

**ItemType GetTopElementMultipleStack(const MultipleStack current_multiple_stack, const int current_multiple_stack_order)**
Return top element of current_multiple_stack's specific order stack.      

**void PushMultipleStack(const MultipleStack current_multiple_stack, const int current_multiple_stack_order, const ItemType pushing_element)**       
Push pushing_element to current_multiple_stack's specific order stack.     

**ItemType PopMultipleStack(const MultipleStack current_multiple_stack, const int current_multiple_stack_order)**     
Pop element from current_multiple_stack's specific order stack.      

**void RemoveMultipleStack(MultipleStack * remove_multiple_stack_address)**      
Remove MultipleStack.      

# Exceptions :

**Memory Lack**   
InitMultipleStack     

**InvalidLength**   
InitMultipleStack       

**InvalidMultipleStackOrder**   
GetSizeMultipleStack , IsEmptyMultipleStack , IsFullMultipleStack , GetTopElementMultipleStack , PushMultipleStack , PopMultipleStack     

**EmptyMultipleStack**   
GetTopElementMultipleStack , PopMultipleStack     

**FullMultipleStack**       
PushMultipleStack     

**DeallocatedMultipleStack**
GetSizeMultipleStack , IsEmptyMultipleStack , IsFullMultipleStack , GetTopElementMultipleStack , PushMultipleStack , PopMultipleStack , RemoveMultipleStack       

# besides : 

**MultipleStack.h**   
User can modify type of item.  

![화면 캡처 2023-07-19 002751](https://github.com/woo-in/DATA-STRUCTURES-Principles-and-Applications/assets/69314509/4a76c5c8-f84c-4083-b688-eac364aa07fb)

