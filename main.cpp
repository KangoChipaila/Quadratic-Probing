#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct HashTable
{
    vector <vector<int>> hashTable;

    HashTable()
    {
        int noOfBuckets = 10;

        hashTable.resize(noOfBuckets);
    }

    int hashFunction(int key) //Simple hash function to map key to hash table.
    {
        return key % 7;
    }

    void insertKey(int key) //Function to insert values into the vector contained by the vector
    {
        int count = 0;
        int index = hashFunction(key);


        while(!hashTable[index].empty())
        {
            index = hashFunction(key) + pow(index, 2);
        }
        
        if (count <= 10)
        {
            hashTable[index].push_back(key);
            count++;
        }
        else
        {
            cout << "Hash table is full" << endl;
        }

    }

   void displayHashTable()
    {
        for (int hashIndex = 0; hashIndex < hashTable.size(); hashIndex++)
        {
            cout << hashIndex << " : ";
            
            for (int data = 0; data < hashTable[hashIndex].size(); data++)
            {
                cout << hashTable[hashIndex][data] << " ";
            }
            cout << endl;
        }
    }
    
};

//Driver code
int main()
{
    HashTable ht;
    
    ht.insertKey(22);
    ht.insertKey(30);
    ht.insertKey(50);
    
    ht.displayHashTable();

    return 0;
}
