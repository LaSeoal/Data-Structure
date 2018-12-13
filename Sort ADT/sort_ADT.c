#include "sort_ADT.h"
#include <stdio.h>

void selection_sort( int list[], int last ) {
	int smallest;
	int hold;

	for(int current = 0; current <= last; current++) {
		smallest = current;

		for(int walker = current+1; walker <= last; walker++) {
			if(list[walker] < list[smallest])
				smallest = walker; // update smallest until last
		}

		//swap current value with found smallest one
		hold = list[current];
		list[current] = list[smallest];
		list[smallest] = hold;
		//Now, the smallest is ready at current
	}

}

void insertion_sort( int list[], int last ) {
	int walker;
	int hold;

	for(int current = 1; current <= last; current++) {
		hold = list[current];

		for(
			walker = current-1;
			walker >= 0 && hold < list[walker];
			walker--
		) {
			list[walker+1] = list[walker];	
	}
	//insertion on adequate location
	list[walker+1] = hold;
}

void median_left( int list[], int left, int right ) {
	int mid;
	int hold;

	mid = (left+right)/2;
	if(list[left] > list[mid]) {
		//send smaller value to left
		hold = list[left];
		list[left] = list[mid];
		list[mid] = hold;
	}

	if(list[left] > list[right]) {
		hold = list[left];
		list[left] = list[right];
		list[right] = hold;
	}

	if(list[mid] > list[right]) {
		hold = list[mid];
		list[mid] = list[right];
		list[right] = hold;	
	}

	// median is at the middle, exchange with left.
	hold = list[left];
	list[left] = list[mid];
	list[mid] = hold;
}

void insertion_sort_range( int list[], int first, int last ) {
	int walker;
	int hold;

	for(int current = first+1; current <= last; current++) {
		hold = list[current];

		for(
			walker = current-1;
			walker >= first && hold < list[walker];
			walker--
		) {
			list[walker+1] = list[walker];
		}

		list[walker+1] = list[walker];
	}

	list[walker+1] = hold; // insertion on adequate location
}

void quick_sort( int list[], int left, int right ) {
	#define MIN_SIZE 16
	int sort_left;
	int sort_right;
	int pivot;
	int hold;

	if((right-left) > MIN_SIZE) { // divide into sub tree
		//find pivot, place it in list[left]
		medain_left(list, left, right);
		pivot = list[left];
		sort_left = left+1;
		sort_right = right;

		while(sort_left <= sort_right) {
			//find key on left that belongs to right
			while(list[sort_left]<pivot)
				sort_left++;

			//find key on right that belongs to left
			while(list[sort_right]>=pivot)
				sort_right--;

			if(sort_left <= sort_right) {
				hold = list[sort_left];
				list[sort_left] = list[sort_right];
				list[sort_right] = hold;
				sort_left++;
				sort_right--;
			}
		}
		//prepare for next pass
		list[left] = list[sort_left-1];
		list[sort_left-1] = pivot;

		if(left < sort_right)
			quick_sort(list, left, sort_right-1);
		if(sort_left < right)
			quick_sort(list, sort_left, right);
	} else { // if group size is divided under 16, do insertion_sort
		insertion_sort_range(list, left, right);
	}
}