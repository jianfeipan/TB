#include<iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    ListNode *current=head;
    while(current!=NULL){
        current=current->next;
        if(current==NULL)
            return false;
        if(current==head)
            return true;
    }
    return hasCycle(current);
};

/*faster and slower runner*/
bool hasCycle2(ListNode *head) {
    if(head == NULL || head->next==NULL)
        return false;
        
    ListNode *fast = head;
    ListNode *slow = head;

    while(fast -> next && fast -> next -> next){
        fast = fast -> next -> next;
        slow = slow -> next;
        if(fast == slow)
            return true;
    }

    return false;
}

int main(){
	ListNode a = ListNode(1);
	ListNode* pa = &a;
	pa->next = pa;
	cout<<hasCycle(pa);
	return 0;
}


