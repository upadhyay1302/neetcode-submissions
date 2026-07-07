class Node{
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k, int v) : key(k), val(v), prev(NULL), next(NULL){};
};

class LRUCache {
public:
    unordered_map<int,Node*> mp;
    int size;
    Node* left;
    Node* right;

    void remove(Node* node){
        Node* prv = node -> prev;
        Node* nxt = node -> next;
        prv -> next = nxt;
        nxt -> prev = prv;
    }

    void insert(Node* node){
        Node* rightPrev = right -> prev;
        rightPrev -> next = node;
        node -> next = right;
        right -> prev = node;
        node -> prev = rightPrev;
    }
    LRUCache(int capacity) {
        size = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;

    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
     void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            remove(mp[key]);
        }
        Node* newNode = new Node(key, value);
        mp[key] = newNode;
        insert(newNode);

        if (mp.size() > size) {
            Node* lru = left->next;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};

