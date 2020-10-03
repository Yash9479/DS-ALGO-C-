if ((FRONT == 0) and (REAR == N - 1)) // Condition for overflow
Print “Queue Overflow”
end Algorithm_Enqueue
end if
if (FRONT == -1)   //Inserting an element in an empty queue
FRONT = REAR = 0
end if
else
 REAR = REAR +1    //  Increment rear
end else
QUEUE [REAR] =  element    //    Assign the inserted element to the queue
end Enqueue