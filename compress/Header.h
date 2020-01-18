#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <cmath>

using namespace std;
		template<class K,class V>
			struct HashFunc
			{
				K key;
 				V value;
				HashFunc(){key="";value=0;}
				HashFunc (const K &k, const int &v) : value(v), key(k) {};
			};
	template<class K,class V>
		 class HashTable
        {
          public:	
			  explicit HashTable();
			  bool isKeyExist(K key);
			  V get(K key);
			 void add(K key,V val);
			 vector <HashFunc<K,V>> arr;
		private:
		V hash(K key){
			int hashVal = 0;
				 for (unsigned int i = 0; i < key.length();i++) 
			hashVal = 37 * hashVal + key[ i ];

			  hashVal = hashVal % 4096;
				  if (hashVal < 0) 
					hashVal = hashVal + 4096;
				 return(hashVal);
			}
			
		};
		 template<class K,class V>
		 HashTable<K,V> :: HashTable():arr(4096)
		{

			
			for(int z=0;z<256;z++)
			{
				char x = char(z);
				arr[z].key=x;
				arr[z].value=z;			
			}
				for(int q=256;q<4096;q++)
			{
				arr[q].key="empty";
				arr[q].value=q;
			}
		}
				template<class K,class V>
		bool HashTable<K,V> :: isKeyExist(K key)
		{
			if(key.length()==1)
				return true;
			for(int i=0;i<4096;i++)
			{
				if(arr[i].key==key)
					return true;
			}return false;
		}
		template<class K,class V>
		V HashTable<K,V> :: get(K key)
		{
			if(key.length()==1)
			{
				for(int a=0;a<256;a++)
				{
					if(arr[a].key==key)
						return arr[a].value;
				}
			}
			int a = hash(key);
			for(;a<4096;a++)
			{
				if(arr[a].key==key)
			return arr[a].value;
			}
		}
		template<class K,class V>
		void HashTable<K,V> :: add(K key,V val)
		{
			 if(arr[hash(key)].key=="empty")
			{
				arr[hash(key)].key=key;
				arr[hash(key)].value=val;
			}
			else if(arr[hash(key)].key!="empty")
			{
				int a=1;
				while(arr[(hash(key)+a)%4096].key!="empty")
					a++;
				arr[(hash(key)+a)%4096].key=key;
				arr[(hash(key)+a)%4096].value=val;
			}
			
		}