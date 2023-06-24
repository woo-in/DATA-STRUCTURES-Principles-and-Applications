# Data :   
   
Successive < individuals , group name >  

   

# Methods :   

**GroupList InitGroupList()**   
Return new GroupList.

**void AddLastElementGroupList(GroupList q_list, const ItemType add_item, const int designated_group)**   
Add < add_item , add_group > to the end of present part of q_list. 

**void RemoveDesignatedElementGroupList(GroupList q_list, const int designated_group)**   
Remove designated_group elements. 

**void PrintDesignatedElementGroupList(const GroupList q_list, const int designated_group)**   
Print designated_group elements.   

**void RemoveGroupList(GroupList * remove_group_list_address)**   
Remove GroupList. 
 
# Exceptions :

**Memory Lack**   
InitGroupList

**Invalid Group**   
AddLastElementGroupList , PrintDesignatedElementGroupList , RemoveAllElementDesignatedGroupList

**Deallocated list**   
AddLastElementGroupList , PrintDesignatedElementGroupList , RemoveDesignatedElementGroupList , RemoveGroupList

# besides : 

**ListLinkedListVersion.h**   
User can modify max length of  group list and type of item. ( group is int default )     

![화면 캡처 2023-06-24 231520](https://github.com/woo-in/DATA-STRUCTURES-Principles-and-Applications/assets/69314509/45a2480a-02cb-4f6a-9aeb-97b61b249ae3)   

If user changed type of item , should modify printf function conversion specification in PrintDesignatedElementGroupList.   

![f712](https://github.com/woo-in/DATA-STRUCTURES-Principles-and-Applications/assets/69314509/42e97b4f-c22f-4e01-ae5c-f8c10ec28790)
