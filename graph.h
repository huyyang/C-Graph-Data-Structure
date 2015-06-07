//graph.h

//This is our .h file of our graph section of the assignment
//Here it exists our two structs,(vertex and node) we will
//create these to make an array of linear linked list in which
//our nodes will correspond to the array in which that is
//our adjacencyList. The user will type in an item and will 
//have the opportunity to change his key word any time he wants
//due to our efficiency of our graph.

//we are including our read in file that reads
//in from the file. We will then store each read
//in, into our vertex information
#include <iostream>
#include <cctype>
#include <cstring>

//we have to include our fstream because we are extracting from
//an external file. We need to to read in or write out into a 
//file
#include <fstream>


//a struct vertex. This holds a pointer to 
//a set of nodes and also holds our information
struct vertex
{
	//we will pass in our information into
	//our vertex so we will have a total of
	//6 set vertex's. In that we store our
	//read in characters into the keyword 
	//and the sentence
	char * keyWord;
	char * sentence;

	//This function is inside of our struct. What this
	//function is going to do is add our edges. We 
	//have to do it inside our vertex because when
	//I try to call it in our class table it is
	//out of bounds
	void insert(vertex * toAdd);
	
	//we have a flag integer because we need it to
	//set our nodes to 1 everytime it is being touched
	//This is so it can display once instead of twice
	//or even three times. That's why we set a flag.
	//So we can set it to 1 everytime it has been
	//passed
	int flag;

	//a copy function that will copy the keyword
	//and the sentence into our struct. We pass in
	//the read in keyword and sentence is why we 
	//need a copy function for this specific
	//assignment
	int copy(vertex * copyWord);

	//we call the node head here because
	//we will still need some recursive statements
	//and we have head pointing to the beginning
	//of this vertex
	struct node * head;
};

//each node will be a strand starting at each vertex
struct node
{
	//each node is represented as adjacentlist
	//it holds strands of linear linked lists
	//connected to each other such as graphs
	vertex * adjacent;

	//a next pointer for the address of the next
	//node in the linear linked list in which
	//is stranded from adjacenyLists
	node * next;
};

//we make a class table because we are practically 
//making an array of linear linked lists
class table
{
	public:
		//our constructor in which we set our size
		//to a size of 6. We can change our size any
		//time we want. But in this case we oonly have 6
		//key items along with information
		table(int size = 15);

		//our destructor in which we will deallocate each
		//node and adjacencyList in our program at the end
		//of our program
		~table();


		//we will display all of our graph
		int display();

		//this function will remove all the nodes in a 
		//linear linked list
		int removeAllNodes(node * & head);

		//this function will remove all of our adjacency list
		//along with all the nodes in a linear linekd list
		int removeAll();

		//we will display our chosen response in which the 
		//user types in to match with our keyWord in which
		//is in our struct
		int displayChosen(char * userResponse);

		//this will display our path depending on what 
		//key word the user says
		int displaySimilar(node * head);

		//the wrapper function because we cannot call it
		//in main
		int displaySimilar(char * userResponse);

		//this function is practically how we make our graph.
		//As we readd into our external file (info.txt) we also
		//insert our data members into our adjacencyList along
		//with our edges at the same time. The edges to insert
		//are possible because I added integers into my 
		//external file
		int readIn();

		//if the responses are anything else other than 4, then we will
		//ask the user if they would like to enter in another option in the
		//program, and that is where the do while loop comes in. If yes,
		//then we will do the program all over again, if no, they we will leave.
		int depthFirstDisplay(char * userResponse2);
		int depthFirstDisplay(vertex * head);
	
	private:
		//we make a vertex of adjacencyLists in which acts
		//as our array because they are correctly and precisely
		//indexed like an array and we will make it like an
		//array in our constructor and delete it like an array
		//in a destructor
		vertex * adjacencyList;

		//this is our set size integer for our adjacencyList
		//in which it will have 6 of them because we will set
		//this integer in our constructor
		int listSize;
 
};
