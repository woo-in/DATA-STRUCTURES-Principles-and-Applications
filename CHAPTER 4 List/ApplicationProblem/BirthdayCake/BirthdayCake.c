#include "BirthdayCake.h"
#include "List.h"
#include <stdio.h>

static List BuildList(List list_k, int cake_size);
static int RunSimulation(List list_k, int cake_size, int interval);

int Candle(int cake_size, int interval) {
	List list_k = InitList();

	BuildList(list_k, cake_size);
	int result = RunSimulation(list_k, cake_size, interval);
	RemoveList(&list_k);

	return result; 
}

static List BuildList(List list_k, int cake_size) {
	// error handling 
	if (MAX_LIST_LENGTH < cake_size) {
		printf("ERROR : CAKE SIZE IS TO BIG MODIFY\nMODIFY MAXIMUM LIST LENGTH IN LIST HEADER FILE\n");
		exit(0);
	}

	// insert element 
	for (int i = 0; i < cake_size; i++)
		AddLastElementList(list_k, i + 1);

	return list_k; 
}

static int RunSimulation(List list_k, int cake_size, int interval) {
	int candle_rank = 1;
	int drawn_candle_count = 0; 
	int interval_count = 0; 

	for (;;) {

		// find interval next candle_rank
		interval_count = 0;
		while (interval_count < interval) {

			// next candle 
			candle_rank = (candle_rank % cake_size) + 1; 
			// if value 0 ==> drawn candle 
			if(GetRankElementList(list_k , candle_rank)!= 0)
				interval_count++;
		}

		// turn off candle and drawn 
		ChangeRankElementList(list_k, candle_rank, 0);
		drawn_candle_count++; 

		// find next candle_rank 
		do {
			candle_rank = (candle_rank % cake_size) + 1;
		} while (GetRankElementList(list_k, candle_rank) == 0);
		
		// return last_candle_rank 
		if (cake_size - 1 == drawn_candle_count)
			return candle_rank; 

	}

}