#include <iostream>
#include <map>
#include <vector>
using namespace std;

class ListNode{
public:
    int data;
    ListNode* next;
    ListNode(int val){
        this->data = val;
        this->next = NULL;
    }
};

void TraverseLinkedList(ListNode* head){
    ListNode* tempPtr = head;
    while(tempPtr!=NULL){
        cout << tempPtr->data << " ";
        tempPtr = tempPtr->next;
    }
    cout << "\n";
}

// 1. Delete nth node from the end
ListNode* removeNthFromEnd(ListNode* head, int n){
    int currDiff = 0;
    ListNode* currPtr = head;
    ListNode* tempPtr = head;
    ListNode* thisPtr = NULL;
    bool found = false;
    int length = 1;
    while(tempPtr!=NULL && tempPtr->next!=NULL){
        if(n <= 0) return head;
        found = true;
        tempPtr = tempPtr->next;
        if(currDiff >= n){
            currPtr = currPtr->next;
        }
        currDiff++;
        length++;
    }
    // now delete
    if(length == n){
        return head->next;
    }
    if(!found) return NULL;
    ListNode* nextPtr = currPtr->next;
    currPtr->next = nextPtr->next;
    nextPtr->next = NULL;
    return head;
}

// DELETE DUPLICATE NODES 2
ListNode* deleteDuplicates1(ListNode* head) {
    map<int, int> hashmap;
    ListNode* tempPtr = head;
    while(tempPtr!=NULL){
        hashmap[tempPtr->data]++;
        tempPtr = tempPtr->next;
    }

    ListNode* ll = NULL;
    ListNode* temp = ll;
    for(auto val : hashmap){
        if(val.second > 1) continue;
        ListNode* n = new ListNode(val.first);
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

ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;

    ListNode* tempPtr1 = head->next;
    ListNode* tempPtr2 = head;
    bool hasDuplicates = false;

    while (tempPtr1 != NULL) {
        if (tempPtr1->data == tempPtr2->data) {
            hasDuplicates = true;
            while (tempPtr1->next != NULL && tempPtr1->data == tempPtr1->next->data) {
                tempPtr1 = tempPtr1->next;
            }
            tempPtr2->next = tempPtr1->next;
            tempPtr1 = tempPtr2->next;
        } else {
            if (hasDuplicates) {
                tempPtr2 = tempPtr1;
                hasDuplicates = false;
            } else {
                tempPtr2 = tempPtr1;
            }
            tempPtr1 = tempPtr1->next;
        }
    }

    // Handle the case where the last sequence has duplicates
    if (tempPtr2 != NULL && tempPtr2->next != NULL && tempPtr2->data == tempPtr2->next->data) {
        tempPtr2->next = NULL;
    }

    return head;
}

ListNode* reorderList(ListNode* head) {
    ListNode* tempPtr = head;
    vector<int> nodes;
    while(tempPtr!=NULL){
        nodes.push_back(tempPtr->data);
        tempPtr = tempPtr->next;
    }
    int low = 0;
    int high = nodes.size() - 1;
    bool first = true;
    ListNode* ll = NULL;
    ListNode* temp = ll;
    while(high >= low){
        if(first){
            ListNode* n = new ListNode(nodes[low++]);
            if(ll == NULL){
                ll = n;
                temp = ll;
            }else{
                temp->next = n;
                temp = temp->next;
            }
            first = false;
        }else{
            ListNode* n = new ListNode(nodes[high--]);
            if(ll == NULL){
                ll = n;
                temp = ll;
            }else{
                temp->next = n;
                temp = temp->next;
            }
            first = true;
        }
    }
    return ll;

}

// CHECK IF PALINDROME LINKED LIST - 
/*
ALGORITHM - 
1. The main algorithm for this is to reverse the second half of linked list and then check
*/
ListNode* reverseList(ListNode* head){
    ListNode* currPtr = head;
    ListNode* prevPtr = NULL;
    while(currPtr!=NULL){
        ListNode* n = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = n;
        
    }
    return prevPtr;
}

bool isPalindrome(ListNode* head) {
    // finding the middle node
    ListNode* slowPtr = head;
    ListNode* fastPtr = head;
    while(fastPtr!=NULL && fastPtr->next!=NULL){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }       

    ListNode* otherHalf = reverseList(slowPtr);

    // compare
    ListNode* ptr1 = head;
    ListNode* ptr2 = otherHalf;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data != ptr2->data){
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return true;
}



int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    TraverseLinkedList(head);

    ListNode* res = reorderList(head);
    TraverseLinkedList(res);
    return 0;
}
