#include <bits/stdc++.h>
using namespace std;

class HashTable {
    int TABLE_SIZE;
    vector<vector<int>> table;  // each index has a vector (chaining)

public:
    HashTable(int size) {
        TABLE_SIZE = size;
        table.resize(TABLE_SIZE);
    }

    // Simple hash function
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    // Insert a key
    void insertKey(int key) {
        int index = hashFunction(key);
        // avoid duplicate insert (optional)
        for (int x : table[index]) {
            if (x == key) {
                cout << key << " already present\n";
                return;
            }
        }
        table[index].push_back(key);
    }

    // Search a key
    bool searchKey(int key) {
        int index = hashFunction(key);
        for (int x : table[index]) {
            if (x == key) return true;
        }
        return false;
    }

    // Delete a key
    void deleteKey(int key) {
        int index = hashFunction(key);
        auto &bucket = table[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == key) {
                bucket.erase(it);
                cout << key << " deleted\n";
                return;
            }
        }
        cout << key << " not found\n";
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << " -> ";
            for (int x : table[i]) {
                cout << x << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    HashTable ht(7);  // TABLE_SIZE = 7

    ht.insertKey(15);
    ht.insertKey(22);
    ht.insertKey(7);
    ht.insertKey(29);

    ht.display();

    cout << "Search 22: " << (ht.searchKey(22) ? "Found\n" : "Not Found\n");
    cout << "Search 10: " << (ht.searchKey(10) ? "Found\n" : "Not Found\n");

    ht.deleteKey(22);
    ht.display();

    return 0;
}
