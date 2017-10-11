//FILE LRU_cache.cpp
/*
INVARIANT for the LRU cache class:
    1. The number of items in the cache is in the member variable "used".
	2. *head points to the most recently used element.
	3. *tail points to the least recently used element.
*/

#include <iostream>
#include <unordered_map>
#include "LRU_cache.h"
using namespace std;

namespace main_yao {
	LRU::LRU(int c) {
		used = 0;
		capacity = c;
		head = NULL;
		tail = NULL;
	}

	void LRU::put(int key, int value) {
		if (used == 0) {
			cache[key] = {key, value, NULL, NULL};
			head = &cache[key];
			tail = head;
			used++;
			return;
		}

		if (cache.find(key) != cache.end()) {
			Node *n = &cache[key];
			n->value = value;
			if (n->prev != NULL) n->prev->next = n->next;
			if (n->next != NULL) n->next->prev = n->prev;
			if (n != head) n->next = head;
			n->prev = NULL;
			head = n;
			return;
		}
			if (used == capacity) {
			tail = tail->prev;
			cache.erase(tail->next->key);
			tail->next = NULL;
			used--;
		}
		cache[key] = {key, value, NULL, head};
		head->prev = &cache[key];
		head = &cache[key];
		used++;
	}
	int LRU::get(int key) {
		if (cache.find(key) == cache.end()) return -1;
		else {
			Node *n = &cache[key];
			if (n->prev != NULL) n->prev->next = n->next;
			if (n->next != NULL) n->next->prev = n->prev;
			if (n != head) n->next = head;
			n->prev = NULL;
			head = n;
			
			return n->value;
		}
	}
}
