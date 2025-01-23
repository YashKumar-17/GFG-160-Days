Approach:
Interleave the Copy Nodes:

For every node in the original list, create a corresponding new node with the same data.
Insert the new node right after the original node to form an interleaved list structure.
Set Up Random Pointers:

Traverse the interleaved list and assign the random pointers for the copied nodes.
The random pointer of the copied node is set to temp->random->next, as the original node's random pointer points to its neighbor.
Separate the Lists:

Restore the original list by fixing the next pointers of the original nodes.
Extract the copied list by fixing the next pointers of the copied nodes.
Intuition:
The interleaving technique ensures that each copied node has access to the original node’s data and pointers, making it easy to set up random pointers. 
After setting up the random pointers, the lists are separated cleanly to return the copied list.

Steps:
Insert copied nodes into the original list.
Assign random pointers for the copied nodes using the interleaved structure.
Restore the original list and separate the copied list.
This approach avoids extra space for mapping and works efficiently in O(n) time with O(1) space (excluding the output list).

Node *cloneLinkedList(Node *head) {
        // Write your code here
       Node* temp=head;
       Node* copyhead=new Node(temp->data);
       Node* copynode=copyhead;
       copynode->next=temp->next;
       temp->next=copynode;
       temp=temp->next->next;
       while(temp!=NULL){
           Node* newnode=new Node(temp->data);
           copynode=newnode;
           copynode->next=temp->next;
           temp->next=copynode;
           temp=temp->next->next;
       }
       temp=head;
       copynode=copyhead;
      while(temp!=NULL){
          if(temp->random!=NULL){
          copynode->random=temp->random->next;
          }
          else{
              copynode->random=NULL;
          }
          temp=temp->next->next;
          if(copynode->next!=NULL){
          copynode=copynode->next->next;
          }
      }
       temp=head;
       copynode=copyhead;
      while(temp!=NULL){
          Node* cas;
          if(copynode->next!=NULL){
          cas=copynode->next->next;
          temp->next=copynode->next;
          temp=copynode->next;
          copynode->next=cas;
          copynode=cas;
          }
          else{
              temp->next=NULL;
              temp=temp->next;
          }
         
      }
       return copyhead;
    }
