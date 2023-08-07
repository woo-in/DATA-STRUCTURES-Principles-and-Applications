# Data :     

Hierarchical data    

# Methods :       
         
**Tree InitializeTree(const int max_tree_len, const int root_node_item)**        
Return new tree.        

**void RemoveTree(Tree * removing_tree)**         
Remove tree.      

**bool IsEmptyTree(Tree current_tree)**          
Reture true , if current_tree is empty.       
else , return false.         

**int GetSizeOfTree(Tree current_tree)**       
Return size of tree.     

**ItemType GetRootNodeItemOfTree(Tree current_tree)**        
Return root node item.       

**ItemType GetParentNodeItemInTree(Tree current_tree, const int node_index)**        
Return parent node item.     

**ItemType GetLeftChildrenNodeItemInTree(Tree current_tree, const int node_index)**         
Return left child node item.      

**ItemType GetRightChildrenNodeItemInTree(Tree current_tree, const int node_index)**      
Return right child node item.       

**ItemType GetNodeItemInTree(Tree current_tree, const int node_index)**       
Return node item.       

**bool IsInternalNodeInTree(Tree current_tree, const int node_index)**        
If internal node , return true.      
else , return false.      

**bool IsExternalNodeInTree(Tree current_tree, const int node_index)**        
If external node , return true.      
else , return false.     

**void SetLeftChildNodeInTree(Tree current_tree, const int node_index, const ItemType left_child_item)**      
Set left child.      

**void SetRightChildNodeInTree(Tree current_tree, const int node_index, const ItemType right_child_item)**       
Set right child.       

**void SwapNodeItemInTree(Tree current_tree, const int node_index_swap1, const int node_index_swap2)**       
Swap node item.      

**ItemType RemoveExternalNodeInTree(Tree current_tree, const int node_index)**         
If external node , remove it.       

**int GetDepthOfNodeInTree(Tree current_tree, const int node_index)**      
Return depth of node.     

**int GetHeightOfNodeInTree(Tree current_tree, const int node_index)**      
Return height of node.       

**void PreOrderTraverseAndPrintNodeInTree(Tree current_tree, const int node_index)**       
Traverse preorder and print node item.       

**void PostOrderTraverseAndPrintNodeInTree(Tree current_tree, const int node_index)**          
Traverse postorder and print node item.       

**void InOrderTraverseAndPrintNodeInTree(Tree current_tree, const int node_index)**      
Traverse inorder and print node item.       

**void LevelOrderTraverseAndPrintNodeInTree(Tree current_tree, const int node_index)**       
Traverse levelorder and print node item.       

**void EulerOrderTraverseAndPrintNodeInTree(Tree current_tree, const int node_index)**      
Traverse eulerorder and print node item.       


# ApplicationProblem    

1. Successor

          
**int PreOrderSuccessor(Tree current_tree, const int node_index)**     
Return next node index in preorder traverse.      

**int InOrderSuccessor(Tree current_tree, const int node_index)**       
Return next node index in inorder traverse.      

**int PostOrderSuccessor(Tree current_tree, const int node_index)**      
Return next node index in postorder travese.      

2 . Roman             

           
**int RomanSize(Tree current_tree, const int node_index)**         
Return roman size.        




# besides : 

**Tree.h**   
User can modify type of item.      

![화면 캡처 2023-07-19 002751](https://github.com/woo-in/DATA-STRUCTURES-Principles-and-Applications/assets/69314509/b839d7c0-82ee-4d96-9cc3-fb5c9e5c5826)
