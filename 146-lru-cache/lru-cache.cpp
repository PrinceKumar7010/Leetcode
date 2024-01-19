struct Node{
    int val;
    int key;
    Node* prev;
    Node* next;
    Node(int value, int keyValue){
        key=keyValue;
        val=value;
        prev=NULL;
        next=NULL;
    }
};
class LRUCache {
public:
    int size;
    int currSize;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        size=capacity;
        currSize=0;
        Node* newNode1= new Node(-7, -7);
        Node* newNode2=new Node(-7, -7);
        head=newNode1;
        tail=newNode2;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
        // return key;

            Node* node=mp[key];
            //removing link
            Node* prevNode= node->prev;
            Node* nextNode=node->next;
            prevNode->next=nextNode;
            nextNode->prev=prevNode;

            //Inserting the node in front
            Node* curr=head;
            Node* headNext=curr->next;
            curr->next=node;
            node->prev=curr;
            node->next=headNext;
            headNext->prev=node;
            return node->val;
        }

        return -1;
    }
    
    void put(int key, int value) {

        if(mp.find(key)!=mp.end()){

            Node* node=mp[key];
            node->val=value;
            //removing link
            Node* prevNode= node->prev;
            Node* nextNode=node->next;
            prevNode->next=nextNode;
            nextNode->prev=prevNode;

            //Inserting the node in front
            Node* curr=head;
            Node* headNext=curr->next;
            curr->next=node;
            node->prev=curr;
            node->next=headNext;
            headNext->prev=node;

        }else{

            if(currSize==size){
                Node* lastNode=tail->prev;
                Node* beforeLast=lastNode->prev;
                mp.erase(lastNode->key);
                beforeLast->next=tail;
                tail->prev=beforeLast;
                currSize-=1;
            }

            Node* newNode=new Node(value, key);

            Node* curr=head;
            Node* headNext=curr->next;

            mp[key]=newNode;

            curr->next=newNode;
            newNode->prev=curr;
            newNode->next=headNext;
            headNext->prev=newNode;

            currSize+=1;

        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */