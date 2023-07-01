
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

**GroupList.h**   
User can modify max length of list and type of item and group.

![화면 캡처 2023-06-20 235253](https://github.com/woo-in/DATA-STRUCTURES-Principles-and-Applications/assets/69314509/1e5e4a29-85a4-4600-8781-7fa20786ca0b)

If user changed type of item or group , should modify printf function conversion specification in PrintDesignatedElementGroupList. 

![화면 캡처 2023-06-20 235556](https://github.com/woo-in/DATA-STRUCTURES-Principles-and-Applications/assets/69314509/064532d0-ffbb-495f-bafd-4e42581744a6)

