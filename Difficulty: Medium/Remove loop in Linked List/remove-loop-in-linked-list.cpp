

//Solution 1
// detect a loop 
// slow = head  
// slow=slow->next and fast=fast->next
// Break the loop

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
       
        // just remove the loop without losing any nodes
        Node*slow=head,*fast=head;

	    	// detect a loop (loop break hone ka mtlb ha ya to loop exist karta ya nahi karta ha )
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            break;
        }
        	//condition for loop not existing
        if(fast==NULL||fast->next==NULL)
        return;
        		// slow aur fast ko ek ek step aage badhao
                slow=head;              // Node*prev=NULL;
                while(slow!=fast)
                {
                    slow=slow->next;
                                        //prev=fast
                    fast=fast->next;
                }
                // here previous pointer concept will not work

	    		// to break loop slow pointer ko last node pe leke aao 
                while(slow->next!=fast)
                {
                    slow=slow->next;
                }
                slow->next=NULL;
         
    }
};


//Solution 2
// detect a loop 
// count no of nodes
// fast pointer ko no of nodes times agge bdha diya 
// slow=slow->next and fast=fast->next
// Break the loop
class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // just remove the loop without losing any nodes
        Node*slow=head,*fast=head;

	    // detect a loop (loop break hone ka mtlb ha ya to loop exist karta ya nahi karta ha )
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            break;
        }
        	// if loop does not exist 
        if(fast==NULL||fast->next==NULL)
        return;

	    // count no of nodes
        int count=1;
        slow=fast->next;
        while(slow!=fast)
        {
            count++;
            slow=slow->next;
        }

	    // fast pointer ko no of nodes times agge bdha diya 
        slow=head;
        fast=head;
        while(count--)
        {
            fast=fast->next;
        }
        	// jab tak slow and fast poointers milte nahi tab tak increment karenge 
	    	// isse dono loop ke joint pe aa jayenge
        while(slow!=fast)
        {
            fast=fast->next;
            slow=slow->next;
        }

	    	//loop break karna ha 
        while(slow->next!=fast)
        slow=slow->next;
        slow->next=NULL;
        
    }
};
