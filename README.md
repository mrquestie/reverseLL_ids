The method to reverse the given linked list from one point to another:\
Suppose our linked list is as follows: \
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 \
We wish to reverse the linked list from node 2 (beg) to node 5 (end)

First we need the node before the beg node to do that:\
that is,
```
node =  0    1    2    3    4    5    6
        1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
             q   beg            end
```
We will reverse the linked list by the following method:

1. q is node before beg q->link points to beg.
2. head is always pointing to the beginning node(as you will see further in explanation).
3. We push the entire node next to head at the at the beginning as we traverse from beg to end nodes.

Explanation:
```
       q   head
  1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
	   beg            end
```
According to point 1 head always points to the beginning node & we change the value of beg node every time as we push a new node at the beginning.\
Suppose we push 4 at the beginnig:
	 
```
       q        head
  1 -> 2 -> 4 -> 3 -> 5 -> 6 -> 7
	   beg            end
```
Code:
```
struct node* q = start;
while (q->link != beg)
	q = q->link;
head = q->link;
	while (beg->info != end->info)
	{
		struct node* index = head->link->link;
		head->link->link = beg;
		beg = head->link;
		head->link = index;
		q->link = beg;
	}
end = head;
```
Explanation:\
Inside while loop:
```
1.
     q   head           
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
	 beg            end
2.
     q        head
1 -> 2 -> 4 -> 3 -> 5 -> 6 -> 7
	 beg            end
3.
     q             head
1 -> 2 -> 5 -> 4 -> 3 -> 6 -> 7
	 beg            end
4.
     q                  head
1 -> 2 -> 6 -> 5 -> 4 -> 3 -> 7
	 beg
                 end
```

After while loop ends
```
     q                  head
1 -> 2 -> 6 -> 5 -> 4 -> 3 -> 7
	 beg            end
```                 

Now we will look at the do-while loop inside int main():\
w.k.t., we have to reverse the increasing and decreasing sequence of components.\
For example:

```
   <------inc----->   <-dec->    <---dec--->
   1 -> 2 -> 3 -> 7 -> 4 -> 2 -> 9 -> 8 -> 7 

   7 -> 3 -> 2 -> 1 -> 2 -> 4 -> 7 -> 8 -> 9
```

We will only look at the if() part:\
Code:
```
if (q->info < q->link->info)
{
	beg = q;
	while (q->info < q->link->info)
	{
		q = q->link;
		if (q->link == NULL)
		{
			struct node* tmp = (struct node*)malloc(sizeof(struct node));
			tmp->info = q->info - 1;
			tmp->link = NULL;
			q->link = tmp;
			index++;
		}
	}
	end = q;
	q = reverse(beg, q);
	q = q->link;
}
```

Explanation:
1. The if() statement is for increasing sequence as we can see.
    Example(1):
```
  q                ~--> increasing sequence breaks at this point
  1 -> 2 -> 3 -> 7 -> 4 -> and so on.
```
- The while loop executes until it reaches the point at which the node after which the sequence breaks.
- i.e., in the example we can see that the while loop executes till 7 thus performing q = q->link.
- Finally when q->info > q->link->info (i.e., the value after is less) the loop condition becomes false thus ending execution of while loop.
- Thus after the while loop execution is complete we see q pointing to the end value (i.e., 7).
- We now push the value of q to end i.e., end = q;
2. beg points to the first value of the increasing statement and end the last one. 
3. We will talk about the if statement (q->link == NULL) later.
4. After we have assigned the value of beg and end we now call the function reverse(beg, end) to reverse the sequence.
5. After the execution of reverse() we assign the value of q which is pointing to the end of sequence to q->link that is the next node.

Example(1 cont.):\
After assigning the value of LL as q = q->link. As previously it was pointing at the end node.
```
		      q
  7 -> 3 -> 2 -> 1 -> 4 -> and so on.
```

6. Thus, the do while loop executes until it reaches its end condition and this is where things get tricky.

Examples important:\
Now we look at 2 cases to undestand the code better:\
Case 1:
```
1 -> 2 -> 3 -> 7 -> 4 -> 2 -> 9 -> 7 -> 8
<------inc----->   <-dec->   <-dec->
```
do-while loop is executed:\
4 times.\
first for 1 -> 2 -> 3 -> 7
- What we can see here is that the value of q as we go into the reverse function would be 0 as we discussed earlier that q is the node previous to the beg node.
- But we can see here there is no previous node.
- Thus,
in reverse() we have the if-else condition as follows performing reverse according to the requirement as follows:
      
```
if (start == beg){....}
else{....}
```
Here we have to change the value of start simultaneously.
```
1.
    start&
     head
      1 -> 2 -> 3 -> 7 -> ......
     beg            end
```

**While loop begins...**
```
2.
    start head
      2 -> 1 -> 3 -> 7 -> .....
     beg            end
3.
    start      head
      3 -> 2 -> 1 -> 7 -> .....
     beg            end
4.
    start           head
      7 -> 3 -> 2 -> 1 -> .....
     beg&
     end
```

**While loop ends.**\
assigning
```
end = head;
```
```
    start           head
      7 -> 3 -> 2 -> 1 -> .....
     beg            end
```

Now similarly the rest of the 2 decreasing sequence will execute (with else statement in reverse() function).\
Finally after execution of the second decreasing statement we reach at our last node.\
here,
```
q->link == NULL;
```

Thus the execution stops.\
Finally we print all the values.

Case 2:\
I was able to execute the base case until I came accross this example which broke the code ☹️.
```
1 -> 2 -> 3 -> 4 -> 5 -> 4 -> 3 -> 2 -> 1
```
What can we see here:
- 2 sequences 1st one increasing from 1 -> 2 -> 3 -> 4 -> 5 2nd one 4 -> 3 -> 2 -> 1
- The second sequence is the one which broke the code.
- What happens here:
```
1.
   q   head
     -> 4 -> 3 -> 2 -> 1
       beg            end
2.
   q        head
     -> 3 -> 4 -> 2 -> 1
       beg            end
3.
   q             head
     -> 2 -> 3 -> 4 -> 1
       beg            end
```

This is the stage where code breaks because:\
we have seen that in both if & else statement of the reverse() function we assign:
```
struct node *index = head->link->link;
```
 
But as we reach stage/point 3 the link of node (info = 1) points NULL. Thus we have to do something for it.\
Basically where the code breaks is not inside reverse() function but rather the while loop inside do-while loop of int main().

What happens:
```
beg = q;
while (q->info > q->link->info)
{
	q = q->link;
}
end = q;
```

```
   q
-> 4 -> 3 -> 2 -> 1
```

we set, beg = q\
**while loop begins...**
```
1.
while loop condition true as 4 > 3.
Thus,
	q = q->link;
              q
      -> 4 -> 3 -> 2 -> 1
2.
while loop condition true as 3 > 2.
Thus,
	q = q->link;
                    q
      -> 4 - > 3 -> 2 -> 1
3.
while loop condition true as 2 > 1.
Thus,
	q = q->link;
                        q
      -> 4 -> 3 -> 2 -> 1
```

4.\
while loop executes once again but since now q->link == NULL & since there is no value after 1 to compare to the code breaks.\
The problem cannot solved by adding q->link!=NULL 
```
while(q->info > q->link->info && q->link!=NULL){...}
```

So we apply a **BIG BRAIN MOVE** 🧠
inside the while loop inside conditional statements (if & else if) inside do-while loop inside int main()\
We add, after 
```
q = q->link;
```
The following: 
```
if (q->link == NULL)
{
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	tmp->info = q->info - 1;
	tmp->link = NULL;
	q->link = tmp;
	index++;
}
```
Explanation:\
after 2.\
while loop executes 2 > 1 true ✔️\
Thus,
```
q = q->link;
```
```
		  q
-> 4 -> 3 -> 2 -> 1
```
After this if statement checks whether q->link == NULL which is true.\
Thus if() executes and a node after 1 is added keeping in maind whether the sequence is increasing or decreasing breaking the sequence such that it cannot execute further.\
How it is done:\
Case 1: If the sequence is **increasing** \
Example:
```
                         q
  -> 5 -> 6 -> 7 -> 8 -> 9
```
We do the following:
```
-> make a new node tmp.
-> tmp->info = q->info - 1 (as the sequence is increasing.)
-> tmp->link = NULL;
-> q->link = tmp;
```
Result:
```
                         q ------ sequence breaks at this node
  -> 5 -> 6 -> 7 -> 8 -> 9 -> 8
```
Case 2: If the sequence is **decreasing**\
Example:
```                    q
     -> 9 -> 8 -> 7 -> 6
```
```
-> struct node *tmp = ....malloc(..);
```
```
-> tmp->info = q->info + 1 (as the sequence is decreasing)
-> tmp-> link = NULL;
-> q->link = tmp;
```
Result:
```
                    q ------ sequence breaks
  -> 9 -> 8 -> 7 -> 6 -> 7
```

Now you would be thinking the output would include the added node at the end of the linked list we have input.\
You are wrong! 😃 As it is in our hand as to what we can print!!!

```
void display(int nodes)
{
	struct node* q;
	if (start == NULL)
		printf("Empty!");
	else
	{
		q = start;
		for (size_t i = 0; i < nodes; i++)
		{
			printf("%d -> ", q->info);
			q = q->link;
		}
	}
}
```
We print only upto the last node (as inputted) not the one we added.

Thank You!! If you have read the explanation till this point. I'm very grateful to you.
