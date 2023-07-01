
# Data :   
   
Successive < individuals , group name >  

   

# Methods :   

**GroupList InitGroupList()**   
Return new GroupList.

**void AddLastElementGroupList(GroupList q_list, const ItemType add_item, const GroupType add_group)**   
Add < add_item , add_group > to the end of present part of q_list. 

**void RemoveDesignatedElementGroupList(GroupList q_list, const GroupType designated_group)**   
Remove designated_group elements. 

**void PrintDesignatedElementGroupList(const GroupList q_list, const GroupType designated_group)**   
Print designated_group elements.   

**void RemoveGroupList(GroupList * remove_group_list_address)**   
Remove GroupList. 
 
# Exceptions :

**Memory Lack**   
InitGroupList

**Deallocated list**   
AddLastElementGroupList , PrintDesignatedElementGroupList , RemoveDesignatedElementGroupList , RemoveGroupList

# besides : 

**GroupList.h**    

User can modify type of item and group.     

![c1](https://github.com/woo-in/DATA-STRUCTURES-Principles-and-Applications/assets/69314509/a5610f4b-1a26-4c31-95c1-18472a9bbf64)     

If user changed type of item or group , should modify printf function conversion specification in PrintDesignatedElementGroupList.      

![c2](https://github.com/woo-in/DATA-STRUCTURES-Principles-and-Applications/assets/69314509/2cfd4511-55d7-43f1-af41-7d28f26e83bc)
