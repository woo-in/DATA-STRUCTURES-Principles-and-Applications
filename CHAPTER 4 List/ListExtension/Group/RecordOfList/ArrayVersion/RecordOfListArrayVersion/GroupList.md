
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

**Full List**   
AddLastElementGroupList

**Deallocated list**   
AddLastElementGroupList , PrintDesignatedElementGroupList , RemoveDesignatedElementGroupList , RemoveGroupList

# besides : 

**ListArrayVersion.h**   
User can modify max length of list and type of item.
