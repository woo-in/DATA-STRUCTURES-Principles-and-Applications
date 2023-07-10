# Data :   
   
Successive individuals.

   

# Methods :   

**Stack InitStack()**   
Return new Stack.    

**int GetSizeStack(const Stack current_stack)**   
Return current_stack size (the number of individuals). 

**bool IsEmptyStack(const Stack current_stack)**   
If current_stack is empty , return true.     
Otherwise , return false.     

**ItemType GetTopElementStack(const Stack current_stack)**
Return top element of current_stack.     

**void PushStack(Stack current_stack, ItemType pushing_element)**
Push pushing_element to current_stack.      

**ItemType PopStack(Stack current_stack)**     
Pop element from current_stack.      

**void RemoveStack(Stack * remove_stack_address)**  
Remove Stack.     

# Exceptions :

**Memory Lack**   
InitStack     

**Empty Stack**   
PopStack , GetTopElementStack

**Deallocated Stack**   
PushStack , PopStack , GetTopElementStack , GetSizeStack , IsEmptyStack , RemoveStack

# besides : 

**Stack.h**   
User can modify type of item.     

![화면 캡처 2023-07-10 225517](https://github.com/woo-in/DATA-STRUCTURES-Principles-and-Applications/assets/69314509/93b659dd-dde4-4658-8b7d-565e84bcb6d5)
