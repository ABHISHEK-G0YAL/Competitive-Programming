/*
 * Complete the 'condense' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST head as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

// Remove duplicates from linked list

SinglyLinkedListNode* condense(SinglyLinkedListNode* head) {
    bool arr[1005] = {false};
    SinglyLinkedListNode* temp = head;
    while(temp->next) {
        // printf("%d %d\n", temp->data, temp->next->data);
        arr[temp->data] = true;
        if(arr[temp->next->data])
            temp->next = temp->next->next;
        // printf("%d %d\n", temp->data, temp->next->data);
        else
            temp = temp->next;
    }
    return head;
}