#include <stdio.h>
#include <stdlib.h>

typedef struct data_t {
	int value;
	int key;
	int hashValue;
	struct data_t* next;
}data_t;

typedef struct bucket_t {
	data_t *data;
	
}bucket_t;

typedef struct hashTable_t {
	int dataCount;
	bucket_t** table;
	int tableSize;
}hashTable_t;

int getHashValue(int key, int value) {
	int hashValue;
	return hashValue = (key + 5) % 3 + value;
}
bucket_t* findBucket(bucket_t* start, int key) {
	while (start != NULL) {
		if (start->data->key == key) {
			return;
		}
	}
}
data_t* createData(int value, int key) {
	data_t* newData = (data_t*)malloc(sizeof(data_t));
	newData->key = key;
	newData->value = value;
	newData->hashValue = NULL;
	newData->next = NULL;
	return newData;
}
void insertData(hashTable_t* hashTable, int value, int key) {
	int hashValue = getHashValue(key, value);
	bucket_t* bucket = hashTable->table[hashValue];
	data_t* data = createData(value, key);
	data->hashValue = hashValue;
	//버킷이 비었다면
	if (bucket == NULL) {
		hashTable->dataCount++;
		bucket = (bucket_t*)malloc(sizeof(bucket));
		bucket->data = data;
		hashTable->table[hashValue] = bucket;
		return;
	}
	//비지않았다면 해당 버킷의 맨 앞에 데이터 추가 
	//버킷이 가르키는 데이터의 시작을 새로운 데이터로
	//원래 데이터는 뉴데이터가 가르키게끔
	data->next = bucket->data;
	bucket->data = data;
	hashTable->dataCount++;
}

void createHashTable(hashTable_t* hashTable) {
	hashTable->dataCount = 0;
	hashTable->tableSize = 100;
	hashTable->table = (bucket_t**)malloc(sizeof(bucket_t*)*hashTable->tableSize);
	for (int i = 0; i < hashTable->tableSize; i++) {
		hashTable->table[i] = NULL;
	}
}
void display(hashTable_t* hashTable) {
	if (hashTable->dataCount == 0) {
		printf("찍을 거 없다");
		return;
	}
	for (int i = 0; i < hashTable->tableSize; i++) {
		bucket_t* bucket = hashTable->table[i];
		if (bucket != NULL) {
			data_t* selectData = bucket->data;
			while (selectData->next != NULL) {
				printf("%d ", selectData->hashValue);
				selectData = selectData->next;
			}
			printf("\n");
		}
		
	}
}

int main() {
	hashTable_t* hashTable = (hashTable_t*)malloc(sizeof(hashTable_t));
	createHashTable(hashTable);
	for (int i = 0; i < 100; i++) {
		insertData(hashTable, 23, i);
	}
	display(hashTable);
}