1. Concat generally works between lists of the same representation because they can be merged easily.
LinkedList and ArrayList both store their data differently, LinkedList being through pointers and nodes,
while ArrayList uses an array. If you would've tried to combine both using concat, it would need to copy each
data into another new representation instead of just merging or connecting the lists. This makes the process
take longer, which is not efficient and idea.
2. You need prev in order to keep track of the previous node (when flipping so it becomes next), then current
which is the node that will turn keep hold of your current spot, and lastly next, which would turn into previous
when flipping/reversing the order. Losing track of any of these could create an issue of losing what comes next/before
when reversing.
3. addAnywhere's valid positions would be anything from 0 to the list's size because a new element or object can be inserted
anywhere and at the end. However, deleteAnywhere's positions are from 0 to size-1 because there has to be an element to delete.
What my implementation for addAnywhere should do if a caller is passed when the position is invalid or outside of the range is print out a message
that states it's an invalid position, then return without performing it. But for addAnywhere, it does the same but also delete
the new value to prevent any memory leaks.
4. The reason concat in LinkedList had to walk to the end of the list first is so it can reach the last node of the list then connect
it to the first node of the other list. If it had a tail pointer, I would be able to turn concat's runtime to O(1) instead of O(n).
But I would need to update the tail pointer whenever new nodes are added, deleted, or if the list is reversed or concatenated.
5. I'm choosing addAnywhere, when adding an element in the middle in an Arraylist, I would need to shift all the existing elements one position
to the right, starting from the last element then moving backward. Shifting in the wrong direction could cause data overwrite in elements
before actually moving them, which can get data lost.
6. In my main.cpp file, the line table->reverse() is  the line that changes the direction of play. If this call was missing, then the
uno reverse card wouldn't go into action, which would cause the game to continue going the same it was rather than flipping directions.