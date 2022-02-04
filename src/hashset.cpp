#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "hashset.hpp"
#define FACTOR(n) n+((n)*0.3)
#define TRUE 1
#define FALSE 0
#define WAS_NEVER_OCCUPIED 0
#define NOT_OCCUPIED_ANYMORE 1
#define OCCUPIED 2


struct Hash
{
	void** m_data;
	char* m_state;
	HashFunction m_hashFunc;
	EqualityFunction m_equalityFunc;
	size_t m_hashSize;            /*original size given by the client*/
	size_t m_capacity;             /*real hash size */
	size_t m_numOfItems;      
	size_t m_maxOfRehashOperations; /*maximum amount of rehash operations which have been done over one insertion*/
	size_t m_counterOfInsertions; /*total amount of insertions into the table*/
	size_t m_allRehashOperations; /*all rehash operations mutual counter*/
};

/*############## internal functions #########################################*/
size_t CalculateCapacity(size_t _num);
static int IsDataExist(Hash *_hash, void *_data, size_t *_indx, size_t *_MaxRehash);
/*###########################################################################*/

Hash* HashCreate(size_t _size, HashFunction _hashFunc, EqualityFunction _equalityFunc)
{
	Hash *pHash;
	size_t capacity;
	if(_hashFunc == NULL || _equalityFunc == NULL|| _size == 0)
	{
		return NULL;
	}
	pHash = (Hash*)malloc(sizeof(Hash));
	if(pHash == NULL)
	{
		return NULL;
	}
	capacity = CalculateCapacity(_size);
	pHash->m_data = (void**)malloc(capacity * sizeof(void*));
	if(pHash->m_data == NULL)
	{
		free(pHash);
		return NULL;
	}
	pHash->m_state = (char*)calloc(capacity, sizeof(char));
	if(pHash->m_state == NULL)
	{
		free(pHash->m_data);
		free(pHash);
		return NULL;
	}

	pHash->m_hashFunc = _hashFunc;
	pHash->m_equalityFunc = _equalityFunc;
	pHash->m_hashSize = _size;
	pHash->m_capacity = capacity;
	pHash->m_numOfItems = 0;
	pHash->m_maxOfRehashOperations = 0;
	pHash->m_counterOfInsertions = 0;
	pHash->m_allRehashOperations = 0;
	
	return pHash;
}
/*****************************************************************************/

void HashDestroy(Hash **_hash, void (*_keyDestroy)(void *_data))
{	
	size_t i;
	if(_hash == NULL || *_hash == NULL)
	{
		return;
	}
	if(_keyDestroy != NULL)
	{
		for(i = 0; i < (*_hash)->m_capacity; i++)
		{
			if((*_hash)->m_state[i] == OCCUPIED)
			{
				(*_keyDestroy)((*_hash)->m_data[i]);
			}
			
		}
	}
	free((*_hash)->m_state);
	free((*_hash)->m_data);
	free(*_hash);
	*_hash = NULL;
}
/*****************************************************************************/

HashSet_Result HashInsert(Hash *_hash, void *_data)
{
	size_t indx, MaxRehash;
	if(_hash == NULL || _data == NULL)
	{
		return SET_UNINITIALIZED;
	}
	if(_hash->m_numOfItems == _hash->m_hashSize || _hash->m_numOfItems == _hash->m_capacity)
	{
		return SET_OVERFLOW;
	} 
	if(IsDataExist(_hash, _data, &indx, &MaxRehash) == TRUE)
	{
		return SET_KEY_DUPLICATE;
	}
		
	_hash->m_data[indx] = _data;
	_hash->m_state[indx] = OCCUPIED;
	_hash->m_numOfItems++;
	_hash->m_counterOfInsertions++;
	_hash->m_allRehashOperations += MaxRehash;
	if(MaxRehash > _hash->m_maxOfRehashOperations)
	{
		_hash->m_maxOfRehashOperations = MaxRehash;
	}
	return SET_SUCCESS;
}
/*****************************************************************************/
HashSet_Result HashRemove(Hash *_hash, void *_key, void **_data)
{
	size_t indx, i = 0;
	if(_hash == NULL || _data == NULL)
	{
		return SET_UNINITIALIZED;
	}
	if(_key == NULL){return SET_KEY_NOT_FOUND;}
	if(_hash->m_numOfItems == 0){return SET_UNDERFLOW;}
	
	indx = _hash->m_hashFunc(_key) % _hash->m_capacity; 	
   	do
   	{
		if(_hash->m_state[indx] == OCCUPIED)
		{
			if(_hash->m_equalityFunc(_key, _hash->m_data[indx]) == TRUE)
			{
				*_data = _hash->m_data[indx];
				_hash->m_data[indx] = NULL;
				_hash->m_state[indx] = NOT_OCCUPIED_ANYMORE;
				_hash->m_numOfItems--;
				return SET_SUCCESS;
			}
		}
		indx = (indx + 1) % _hash->m_capacity;
		i++;
   	} while (i < _hash->m_maxOfRehashOperations || _hash->m_state[indx] == WAS_NEVER_OCCUPIED);
	
	return SET_KEY_NOT_FOUND;
}
/*****************************************************************************/

int HashIsFound(const Hash *_hash, void *_key)
{
	size_t indx, i = 0;
	if(_hash == NULL || _key == NULL || _hash->m_numOfItems == 0)
	{
		return FALSE;
	}	
	indx = _hash->m_hashFunc(_key) % _hash->m_capacity; 	
   	do
   	{
		// printf("key: %d\n", *(int*)_key);
        // printf("i: %ld   elem: %d\n", indx, *(int*)_hash->m_data[indx]);

        if(_hash->m_state[indx] == OCCUPIED)
		{
			if(_hash->m_equalityFunc(_key, _hash->m_data[indx]) == TRUE)
			{
				return TRUE;
			}
		}
		indx = (indx + 1) % _hash->m_capacity;
		i++;
   	} while (i < _hash->m_maxOfRehashOperations || _hash->m_state[indx] != WAS_NEVER_OCCUPIED);
	
	return FALSE;
}
/*****************************************************************************/

size_t HashNumOfItems(const Hash *_hash)
{
	if(_hash == NULL)
	{
		return 0;
	}
	return _hash->m_numOfItems;
}
/*****************************************************************************/

size_t HashCapacity(const Hash *_hash)
{
	if(_hash == NULL)
	{
		return 0;
	}
	return _hash->m_hashSize;
}
/*****************************************************************************/

double HashAverageRehashes(const Hash *_hash)
{
	if(_hash == NULL || _hash->m_counterOfInsertions == 0)
	{
		return 0;
	}
	return (double)(_hash->m_allRehashOperations) / _hash->m_counterOfInsertions;		
}
/*****************************************************************************/

size_t HashMaxReHash(const Hash *_hash)
{
	if(_hash == NULL)
	{
		return 0;
	}
	return _hash->m_maxOfRehashOperations;
}
/*****************************************************************************/

void HashPrint(const Hash *_hash, void (*PrintKey)(void *_data))
{
	size_t i;
	if(_hash == NULL || PrintKey == NULL)
	{
		return;
	}
	
	for(i = 0; i < _hash->m_capacity; i++)
	{
		if(_hash->m_state[i] == OCCUPIED)
		{
			(*PrintKey)(_hash->m_data[i]);
		}
	}
	printf("\n");
}

/*############## internal functions #########################################*/

size_t CalculateCapacity(size_t _num)
{
	size_t j = 2;
	int isPrime = FALSE;
	size_t result = FACTOR(_num);
	
	while(isPrime == FALSE)
	{
		isPrime = TRUE;
		for(j = 2 ; j < sqrt(result); j++) 
		{
			if(result % j == 0)
			{
				isPrime = FALSE;
				break;
			}
		}
		if(isPrime == TRUE)
		{
			return result;
		}
		result++;
	}	
	return result;
}
/*---------------------------------------------------------------------------*/
/*find the index to insert data, and return error if new data dlready exist */
static int IsDataExist(Hash *_hash, void *_data, size_t *_indx, size_t *_MaxRehash)
{
	size_t i, j, countRehash = 0, found = FALSE;
	i = _hash->m_hashFunc(_data) % _hash->m_capacity;
	
	for(j = 0; j < _hash->m_capacity; j++)
	{
		if(_hash->m_state[i] == OCCUPIED)
		{
			if(_hash->m_equalityFunc(_data, _hash->m_data[i]) == TRUE)
			{
				return TRUE;
			}	
		}
		
		if(found == FALSE && _hash->m_state[i] != OCCUPIED)  
		{
			*_indx = i;
			*_MaxRehash = countRehash;
			found = TRUE;
		}
		i = (i + 1) % _hash->m_capacity;
		countRehash++;
		
		if(j >= _hash->m_maxOfRehashOperations && found == TRUE)
		{
			break;
		}
	}
	return FALSE;
}
/*---------------------------------------------------------------------------*/
/*****************************************/
size_t GetCapacity(const Hash *_hash)
{
	if(_hash == NULL)
	{
		return 0;
	}
	return _hash->m_capacity;
}

