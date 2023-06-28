#include "CustomerPurchaseHistoryManagement.h"
int main() {
	
	CustomerPurchaseHistory a = InitHandler();


	// assume that same customer name and same product name is not exist. 

	ApplyNewCustomer(a, "HANI", 1);
	ApplyNewCustomer(a, "HSSI", 2);
	ApplyNewCustomer(a, "SS", 3);
	ApplyNewCustomer(a, "SISI", 4);

	//tmptPRINT(a);

	ApplyNewProduct(a, "watch", 10);
	ApplyNewProduct(a, "cola", 30);
	ApplyNewProduct(a, "roshen", 20);
	ApplyNewProduct(a, "operation system book", 40);

	//tmptPRINT2(a);

	PurchaseNewProduct(a, "HANI", "watch");
	PurchaseNewProduct(a, "HANI", "operation system book");
	PurchaseNewProduct(a, "SS", "watch");
	PurchaseNewProduct(a, "SS", "watch");
	PurchaseNewProduct(a, "SS", "watch");
	PurchaseNewProduct(a, "SS", "watch");
	PurchaseNewProduct(a, "SISI", "roshen");
	PurchaseNewProduct(a, "SISI", "roshen");
	PurchaseNewProduct(a, "SISI", "watch");

	PurchaseNewProduct(a, "", "");

	RefundProduct(a, "SS", "watch");
	RefundProduct(a, "SS", "watch");
	RefundProduct(a, "SISI", "watch");

	PrintPurchaseHistory(a, "HANI");
	PrintPurchaseHistory(a, "SS");
	PrintPurchaseHistory(a, "SISI");





	RemoveCustomerPurchaseHistory(&a);

	return 0; 
}
