if(FRONT == -1)  // Condition for unsderflow
Print “Underflow”
end Dequeue
end if
if(FRONT == REAR)  // Deleting the only element in the queue
FRONT = REAR = -1
end if
temp = QUEUE[FRONT] 
FRONT = FRONT + 1    // Increment front
delete(element)   // Delete the front element
end Dequeue