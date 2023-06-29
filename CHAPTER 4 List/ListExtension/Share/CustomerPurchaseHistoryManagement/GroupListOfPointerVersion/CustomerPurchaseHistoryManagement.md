# Data :   
   
Customer's product purchase history 

   

# Methods :   

**CustomerPurchaseHistory InitHandler()**   
Return new CustomerPurchaseHistory.    
      
**void ApplyNewCustomer(CustomerPurchaseHistory customer_purchase_history, const char * customer_name, const int customer_number)**              
Apply new customer name and number. 

**void ApplyNewProduct(CustomerPurchaseHistory customer_purchase_history, const char * product_name, const int product_number)**   
Apply new product name and number. 

**void PurchaseNewProduct(CustomerPurchaseHistory customer_purchase_history, const char * purchase_customer_name, const char * purchase_product_name)**      
Purchase product. 

**void RefundProduct(CustomerPurchaseHistory customer_purchase_history, const char * refund_customer_name, const char * refund_product_name)**   
Refund product.      

**void PrintPurchaseHistory(const CustomerPurchaseHistory customer_purchase_history, const char * print_customer_name)** 
Print purchase history.       

**void RemoveCustomerPurchaseHistory(CustomerPurchaseHistory * remove_customer_purchase_history)**       
Remove CustomerPurchaseHistory.

 
# Exceptions :

**Memory Lack**   
InitHandler

**InvalidCustomer**   
PurchaseNewProduct , RefundProduct , PrintPurchaseHistory    

**InvalidProduct**     
PurchaseNewProduct

**Deallocated list**   
ApplyNewCustomer , ApplyNewProduct , PurchaseNewProduct , RefundProduct , PrintPurchaseHistory , RemoveCustomerPurchaseHistory
