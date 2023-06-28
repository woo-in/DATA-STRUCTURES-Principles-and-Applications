#ifndef _CUSTOMER_PURCHASE_HISTORY_MANAGEMENT_H
#define _CUSTOMER_PURCHASE_HISTORY_MANAGEMENT_H



typedef struct CustomerPurchaseHistoryType* CustomerPurchaseHistory; 

CustomerPurchaseHistory InitHandler();
void ApplyNewCustomer(CustomerPurchaseHistory customer_purchase_history, const char* customer_name, const int customer_number);
void ApplyNewProduct(CustomerPurchaseHistory customer_purchase_history, const char* product_name, const int product_number);
void PurchaseNewProduct(CustomerPurchaseHistory customer_purchase_history, const char* purchase_customer_name, const char* purchase_product_name);
void RefundProduct(CustomerPurchaseHistory customer_purchase_history, const char* refund_customer_name, const char* refund_product_name);
void PrintPurchaseHistory(const CustomerPurchaseHistory customer_purchase_history, const char* print_customer_name);
void RemoveCustomerPurchaseHistory(CustomerPurchaseHistory* remove_customer_purchase_history);

static struct Product* MakeNewProduct(const char* product_name, const int product_number);
static struct Purchase* MakeNewPurchase();
static struct Customer* MakeNewCustomer(const char* customer_name, const int customer_number);
static void ErrorHandler(enum ERROR_CODE code); 

void tmptPRINT(CustomerPurchaseHistory a);
void tmptPRINT2(CustomerPurchaseHistory a);
#endif