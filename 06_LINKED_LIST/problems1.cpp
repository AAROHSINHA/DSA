#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

// make a listnode
ListNode* createLinkedList(const std::vector<int> values) {
    if (values.empty()) return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;

    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}
void printLinkedList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// 1. MERGE TWO SORTED LISTS
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* ll = nullptr;
    ListNode* temp = ll;
    ListNode* tempPtr1 = list1;
    ListNode* tempPtr2 = list2;
    while(tempPtr1!=NULL && tempPtr2!=NULL){
        ListNode* n;
        if(tempPtr1->val > tempPtr2->val){
            n = new ListNode(tempPtr2->val);
            tempPtr2 = tempPtr2->next;
        }else{
            n = new ListNode(tempPtr1->val);
            tempPtr1 = tempPtr1->next;
        }

        // add to ll
        if(ll == nullptr){
            ll = n;
            temp = ll;
        }else{
            temp->next = n;
            temp = temp->next;
        }
    }
    
    while(tempPtr1!=NULL){
        ListNode* n = new ListNode(tempPtr1->val);
        if(ll == nullptr){
            ll = n;
            temp = ll;
        }else{
            temp->next = n;
            temp = temp->next;
        }
        tempPtr1 = tempPtr1->next;
    }
    while(tempPtr2!=NULL){
        ListNode* n = new ListNode(tempPtr2->val);
        if(ll == nullptr){
            ll = n;
            temp = ll;
        }else{
            temp->next = n;
            temp = temp->next;
        }
        tempPtr2 = tempPtr2->next;
    }
    return ll;
}

// 2. Delete duplicated from a linked list
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* ll = nullptr;
    ListNode* temp = ll;
    ListNode* tempPtr = head;
    while(tempPtr!=NULL && tempPtr->next!=NULL){
        if(tempPtr->val != tempPtr->next->val){
            ListNode* n = new ListNode(tempPtr->val);
            if(ll == NULL){
                ll = n;
                temp = ll;
            }else{
                temp->next = n;
                temp = temp->next;
            }
        }
        tempPtr = tempPtr->next;
    }      
    if(tempPtr!=NULL || temp!=NULL || temp->val!=tempPtr->val){
        ListNode* n = new ListNode(tempPtr->val);
            if(ll == NULL){
                ll = n;
                temp = ll;
            }else{
                temp->next = n;
                temp = temp->next;
            }
    }

    return ll;
}

// 3. Check linked list cycle
// 1. Hashmap method
bool hasCycle1(ListNode *head) {
    unordered_map<ListNode*, bool> hashmap;
    ListNode* tempPtr = head;
    while(tempPtr!=NULL){
        if(hashmap.find(tempPtr)!=hashmap.end()){
            return true;
        }
        hashmap[tempPtr] = true;
        tempPtr =tempPtr->next; 
    }
    return false;
}

// 2. slow and fastptr method
bool hasCycle(ListNode* head){
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        while(fastPtr!=NULL && fastPtr->next!=NULL && slowPtr!=NULL){
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
            if(fastPtr == slowPtr) return true;
        }
        return false;
}

// 4. Remove linked list elements
// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
// i. Creating a new linked list
ListNode* removeElements1(ListNode* head, int val) {
    ListNode* ll = nullptr;
    ListNode* temp = ll;
    ListNode* tempPtr = head;
    while(tempPtr!=NULL){
        if(tempPtr->val == val){
            tempPtr = tempPtr->next;
            continue;
        }
        ListNode* n = new ListNode(tempPtr->val);
        if(ll == NULL){
            ll = n;
            temp = ll;
        }else{
            temp->next = n;
            temp = temp->next;
        }
        tempPtr = tempPtr->next;
    }
    return ll;
}

// 2. removal in same ll
ListNode* removeElements(ListNode* head, int val){
    // 1. if head == null or if one element present and that is it
    if(head == NULL) return head;
    if(head->next == NULL){
        if(head->val == val) return nullptr;
        return head;
    }
    ListNode* tempPtr = head;
    // until first element is val
    while(tempPtr!=NULL && tempPtr->val == val){
        tempPtr = tempPtr->next;
        head = tempPtr;
    }
    // now others
    while(tempPtr!=NULL && tempPtr->next!=NULL){
        if(tempPtr->next->val!=val){
            tempPtr = tempPtr->next;
            continue;
        }

        ListNode* curr = tempPtr->next->next;
        tempPtr->next->next = nullptr;
        tempPtr->next = curr;
    }

    return head;
}

// 5. REVERSE LINKED LIST
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = head->next;
    while(next!=NULL && curr!=NULL){
        ListNode* that = next;
        curr->next = prev;
        next->next = curr;
        prev = curr;
        curr = next;
        next = that;
    }       
    return prev;
}

int main(){
    ListNode* head1 = createLinkedList({1, 2, 3, 4, 5});
    ListNode* res = reverseList(head1);
    printLinkedList(res);
    
    return 0;
}