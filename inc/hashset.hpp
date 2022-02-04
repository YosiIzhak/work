#ifndef __HASHSET_HPP__
#define __HASHSET_HPP__


typedef enum HashSet_Result
{
	SET_SUCCESS = 0,
	SET_UNINITIALIZED,
	SET_KEY_DUPLICATE,
	SET_KEY_NOT_FOUND,
	SET_OVERFLOW,
	SET_UNDERFLOW

}HashSet_Result;

typedef struct Hash Hash;

typedef size_t (*HashFunction)(void* _data);


typedef int (*EqualityFunction)(void* _firstData, void* _secondData);


/*Create a new hash set with given size, increase size by 30 percent, and find the
*next prime number, and set it to real capacity. 
*input- _hashFunction- to calculate the index to insert, 
*_equalityFunction - to compare between items
*return- pointer to new hash set or NULL in failure */
Hash* HashCreate(size_t _size, size_t (*_hashFunction)(void*), int(*_equalityFunction)(void*, void*));

/*destroy hash set, and if needed- the data inside too
*
*
*/
void HashDestroy(Hash** _hash, void (*_keyDestroy)(void* _data));


HashSet_Result HashInsert(Hash* _hash, void* _data);


HashSet_Result HashRemove(Hash* _hash, void* _key, void** _data);


int HashIsFound(const Hash* _hash, void* _key);


size_t HashNumOfItems(const Hash* _hash);


size_t HashCapacity(const Hash* _hash);


double HashAverageRehashes(const Hash* _hash);


size_t HashMaxReHash(const Hash* _hash);


void HashPrint(const Hash* _hash, void (*PrintKey)(void*));

#endif  



