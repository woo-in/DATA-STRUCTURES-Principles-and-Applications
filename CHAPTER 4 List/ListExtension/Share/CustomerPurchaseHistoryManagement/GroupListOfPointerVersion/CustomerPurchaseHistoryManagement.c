#include "CustomerPurchaseHistoryManagement.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
	char name[50]; 
	int number;
	struct Product* next_product; 
};

struct Customer {
	char name[50];
	int number;
	struct Purchase* purchase_list; 
	struct Customer* next_customer; 
};

struct Purchase {
	struct Product* purchase_product; 
	struct Purchase* next_purchase;
};


struct CustomerPurchaseHistoryType {
	struct Product* product_list; 
	struct Customer* customer_list; 
};

enum ERROR_CODE { Memorylack, InvalidCustomer, InvalidProduct ,  DeallocatedList };
// invalid name = NULL , DeallocatedList !! 
// O(1)
CustomerPurchaseHistory InitHandler() {
	CustomerPurchaseHistory init_customer_purchase_history = malloc(sizeof(*init_customer_purchase_history));
	if (init_customer_purchase_history == NULL) {
		ErrorHandler(Memorylack);
	}

	init_customer_purchase_history->customer_list = MakeNewCustomer("", 0);
	init_customer_purchase_history->product_list = MakeNewProduct("", 0);

	return init_customer_purchase_history; 
}

// O(1) 
void ApplyNewCustomer(CustomerPurchaseHistory customer_purchase_history, const char* customer_name, const int customer_number) {
	struct Customer* new_customer = MakeNewCustomer(customer_name, customer_number);

	new_customer->next_customer = customer_purchase_history->customer_list; 
	customer_purchase_history->customer_list = new_customer;

	return; 
}

// O(1) 
void ApplyNewProduct(CustomerPurchaseHistory customer_purchase_history, const char* product_name, const int product_number) {
	struct Product* new_product = MakeNewProduct(product_name, product_number);

	new_product->next_product = customer_purchase_history->product_list;
	customer_purchase_history->product_list = new_product;

	return; 
}


// O(N+M) , N : 고객수 M : 상품수 
void PurchaseNewProduct(CustomerPurchaseHistory customer_purchase_history, const char* purchase_customer_name, const char* purchase_product_name) {
	struct Customer* purchase_customer = customer_purchase_history->customer_list; 
	while (purchase_customer != NULL) {
		if (strcmp(purchase_customer->name, purchase_customer_name) == 0)
			break; 
		purchase_customer = purchase_customer->next_customer;
	}
	if (purchase_customer == NULL) {
		ErrorHandler(InvalidCustomer);
	}

	struct Product* purchase_product = customer_purchase_history->product_list;
	while (purchase_product != NULL) {
		if (strcmp(purchase_product->name, purchase_product_name) == 0)
			break;
		purchase_product = purchase_product->next_product; 
	}
	if (purchase_product == NULL) {
		ErrorHandler(InvalidProduct);
	}

	struct Purchase* init_purchase = MakeNewPurchase();
	init_purchase->purchase_product = purchase_product;

	init_purchase->next_purchase = purchase_customer->purchase_list->next_purchase;
	purchase_customer->purchase_list->next_purchase = init_purchase; 

	return; 
}

// O(N+M) , N : 고객수 M : 고객의 구매 상품 수 
void RefundProduct(CustomerPurchaseHistory customer_purchase_history, const char* refund_customer_name, const char* refund_product_name) {
	struct Customer* refund_customer = customer_purchase_history->customer_list;
	while (refund_customer != NULL) {
		if (strcmp(refund_customer->name, refund_customer_name) == 0)
			break;
		refund_customer = refund_customer->next_customer;
	}
	if (refund_customer == NULL) {
		ErrorHandler(InvalidCustomer);
	}

	struct Purchase* refund_purchase = refund_customer->purchase_list; 
	struct Purchase* refund_purchase_prev = NULL; 
	while (refund_purchase != NULL) {
		if (strcmp(refund_purchase->purchase_product->name, refund_product_name) == 0) {
			refund_purchase_prev->next_purchase = refund_purchase->next_purchase; 
			free(refund_purchase);
			printf("REFUND SUCCESS!!\n\n");
			break; 
		}
		refund_purchase_prev = refund_purchase; 
		refund_purchase = refund_purchase->next_purchase;
	}
	if (refund_purchase == NULL) {
		printf("REFUND FAILED CUSTOMER DID NOT BUY CORRESPONDING PRODUCT!!\n\n");
		return; 
	}
}

// O(N+M) , N : 고객수 M : 고객의 구매 상품 수
void PrintPurchaseHistory(const CustomerPurchaseHistory customer_purchase_history, const char* print_customer_name) {
	struct Customer* print_customer = customer_purchase_history->customer_list;
	while (print_customer != NULL) {
		if (strcmp(print_customer->name, print_customer_name) == 0)
			break;
		print_customer = print_customer->next_customer;
	}
	if (print_customer == NULL) {
		ErrorHandler(InvalidCustomer);
	}

	printf("%s PURCHASES : "); 

	struct Purchase* print_purchase = print_customer->purchase_list->next_purchase; 
	while (print_purchase != NULL) {
		printf(" %s", print_purchase->purchase_product->name);
		print_purchase = print_purchase->next_purchase; 
	}

	printf("\n");

	return; 
}

// O(N+M+K) , N : 고객수 M : 고객의 구매 상품 수 K : 고객의 상품 구매수 
void RemoveCustomerPurchaseHistory(CustomerPurchaseHistory* remove_cutomer_purchase_history) {
	struct Customer* remove_customer = (*remove_cutomer_purchase_history)->customer_list;
	struct Customer* remove_customer_next = remove_customer->next_customer; 
	struct Purchase* remove_purchase = NULL; 
	struct Purchase* remove_purchase_next = NULL; 
	while (remove_customer != NULL) {

		remove_purchase = remove_customer->purchase_list; 
		remove_purchase_next = remove_purchase->next_purchase; 
		while (remove_purchase != NULL) {
			free(remove_purchase);
			remove_purchase = remove_purchase_next; 
			if (remove_purchase_next != NULL)
				remove_purchase_next = remove_purchase_next->next_purchase; 
		}

		free(remove_customer);
		remove_customer = remove_customer_next; 
		if(remove_customer_next != NULL)
			remove_customer_next = remove_customer_next->next_customer; 
	}

	struct Product* remove_product = (*remove_cutomer_purchase_history)->product_list;
	struct Product* remove_product_next = remove_product->next_product; 
	while (remove_product != NULL) {
		free(remove_product);
		remove_product = remove_product_next; 
		if (remove_product_next != NULL)
			remove_product_next = remove_product_next->next_product; 
	}

	free(*remove_cutomer_purchase_history); 

	*remove_cutomer_purchase_history = NULL;  
	return;
}




// O(1)
static struct Product* MakeNewProduct(const char* product_name, const int product_number) {
	struct Product* new_product = malloc(sizeof(*new_product));
	if (new_product == NULL) {
		ErrorHandler(Memorylack);
	}

	strcpy(new_product->name, product_name);
	new_product->number = product_number; 
	new_product->next_product = NULL; ;

	return new_product; 
}

// O(1) 
static struct Purchase* MakeNewPurchase() {
	struct Purchase* new_purchase = malloc(sizeof(*new_purchase));
	if (new_purchase == NULL) {
		ErrorHandler(Memorylack);
	}

	new_purchase->purchase_product = NULL; 
	new_purchase->next_purchase = NULL; 

	return new_purchase; 
}

// O(1) 
static struct Customer* MakeNewCustomer(const char* customer_name, const int customer_number) {
	struct Customer* new_customer = malloc(sizeof(*new_customer));
	if (new_customer == NULL) {
		ErrorHandler(Memorylack);
	}

	strcpy(new_customer->name, customer_name);
	new_customer->number = customer_number; 
	new_customer->next_customer = NULL; 
	new_customer->purchase_list = MakeNewPurchase();

	return new_customer;
}

// O(1) 
static void ErrorHandler(enum ERROR_CODE code) {
	switch (code)
	{
	case Memorylack: printf("ERROR : MEMORY IS NOT ENOUGH\n\n"); break;
	case InvalidCustomer: printf("ERROR : CUSTOMER IS INVALID\n\n"); break;
	case InvalidProduct: printf("ERROR : PRODUCT IS FULL\n\n"); break;
	case DeallocatedList: printf("ERROR : LIST IS DEALLOCATED\n\n"); break;

	default: printf("ERROR : ERROR CODE EXCEPTION\n\n"); break;
	}

	exit(0);
}