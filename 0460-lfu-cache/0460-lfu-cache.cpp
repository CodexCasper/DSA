class Node{
public:
    int key,val,cnt;
    Node* next;
    Node* prev;

    Node(int _key,int _val){
        key=_key;
        val=_val;
        cnt=1;
    }
};

class List{
public:
    int size;
    Node* head;
    Node* tail;

    List(){
        head=new Node(0,0);
        tail=new Node(0,0);

        head->next=tail;
        tail->prev=head;

        size=0;
    }

    void addFront(Node* node){

        Node* temp=head->next;

        node->next=temp;
        node->prev=head;

        head->next=node;
        temp->prev=node;

        size++;
    }

    void removeNode(Node* delNode){

        Node* delPrev=delNode->prev;
        Node* delNext=delNode->next;

        delPrev->next=delNext;
        delNext->prev=delPrev;

        size--;
    }
};

class LFUCache {

    map<int,Node*> keyNode;
    map<int,List*> freqListMap;

    int maxSizeCache;
    int minFreq;
    int curSize;

public:
    LFUCache(int capacity) {
        maxSizeCache=capacity;
        minFreq=0;
        curSize=0;
    }
    void updateFreqListMap(Node* node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt==minFreq &&
           freqListMap[node->cnt]->size==0){
            minFreq++;
        }
        List* nextHigherFreqList=new List();
        if(freqListMap.find(node->cnt+1)!=freqListMap.end()){
            nextHigherFreqList=freqListMap[node->cnt+1];
        }
        node->cnt+=1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt]=nextHigherFreqList;
        keyNode[node->key]=node;
    }

    int get(int key) {

        if(keyNode.find(key)!=keyNode.end()){

            Node* node=keyNode[key];

            int ans=node->val;

            updateFreqListMap(node);

            return ans;
        }

        return -1;
    }

    void put(int key,int value) {

        if(maxSizeCache==0) return;

        if(keyNode.find(key)!=keyNode.end()){

            Node* node=keyNode[key];

            node->val=value;

            updateFreqListMap(node);
        }

        else{

            if(curSize==maxSizeCache){

                List* list=freqListMap[minFreq];

                keyNode.erase(list->tail->prev->key);

                freqListMap[minFreq]->removeNode(list->tail->prev);

                curSize--;
            }

            curSize++;

            minFreq=1;

            List* listFreq=new List();

            if(freqListMap.find(minFreq)!=freqListMap.end()){

                listFreq=freqListMap[minFreq];
            }

            Node* node=new Node(key,value);
            listFreq->addFront(node);
            keyNode[key]=node;
            freqListMap[minFreq]=listFreq;
        }
    }
};