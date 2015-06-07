//graph.cpp

//This is our .cpp file of our graph section of the assignment
//Here it exists our two structs,(vertex and node) we will
//create these to make an array of linear linked list in which
//our nodes will correspond to the array in which that is
//our adjacencyList. The user will type in an item and will 
//have the opportunity to change his key word any time he wants
//due to our efficiency of our graph. Our main function in here
//is our readIn function and that will insert into our adjacency
//list and add the nodes with the pointers to our adjacency list
//all at the same time. All through the one function.

//we will include our graph.h in which will
//contain our table class along with our 
//two structs
#include "graph.h" 

using namespace std;

//Our constructor. We gave it an integer size
//so it won't hold global integer variables.
//This is taught in lab
table::table(int size)
{
	//We make our adjacencyList into a new
	//pointer array
	adjacencyList = new vertex[size];

	//using a for loop we will go through 
	//our adjacencyList depending on how
	//many index's there are according to the
	//size
	for(int i = 0; i < size; ++i)
	{
		//we make adjacencyList keyWord into 
		//NULL because we want to allocate 
		//this node
		adjacencyList[i].keyWord = NULL;

		//we make adjacencyList sentence into
		//NULL because this is our constructor
		adjacencyList[i].sentence = NULL;

		//we are having our adjacencyList
		//head equal NULL
		adjacencyList[i].head = NULL;

		//we have to set our adjacencyList flag
		//to 0 because we are in the constructor.
		//Contemplating on setting it to 1 because
		//if we have a flag that is 1 then that means
		//it wouldve been true, and if that was true
		//then it would've gone by the nodes that 
		//were true instead of 0, and then we would
		//turn them into 0.
		adjacencyList[i].flag = 0;
	}	

	//make our private data member integer be 
	//equivalent to our set size that was set
	//in our constructor
	listSize = size; 
}

//our destructor. We have to deallocate all the nodes
//in our program at the end of the program. We are 
//going to call our removeAll function in which will
//delete everything in our adjacencyList
table::~table()
{
	//the removeAll function will remove all of
	//our adjacencyList items
	removeAll();
}

//the read in function that will read in from the
//file info.txt. This read in function is also the
//main part of this program because this is where
//we read in and also store our values into our 
//adjacencyList along with our edges. So without
//this function I would've had trouble making the
//graph data structure
int table::readIn()
{
	//the ifstream file in which will declare file
	//that will manipulate our file
	ifstream file;

	//we will open our info.txt file to manipulate it
	file.open("info.txt");		

	//we use a for loop to go through our vertex's
	//and manipulate each pointer in it
	for(int i = 0; i < listSize; ++i)
	{
		//make vertex a new pointer called temp
		vertex * temp = new vertex;

		//make keyWord in which is apart of the
		//vertex struct into a new char array
		temp -> keyWord = new char[100];

		//reads in from the file and stores in
		//the keyWord and stops until it reaches
		//the colin
		file.get(temp -> keyWord, 100, ',');
		file.ignore(100, ',');

		//makes a sentence in which is apart of
		//the vertex struct into a new char array
		temp -> sentence = new char[150];

		//reads in from the file and stores into
		//the sentence and stops until it reaches
		//the wall '|'
		file.get(temp -> sentence, 150, '|');
		file.ignore(100, '|');

		adjacencyList[i].copy(temp);
	
		//we perform a do while loop because in our
		//txt file we have declared numbers that 
		//are going to be the ones that connect
		//our nodes in which points to our 
		//adjacencyList depending on what index they
		//are
		do
		{
			//declare a new integer number
			int number;
			
			//grabs that number and reads in that 
			//number
			file >> number;

			//insert that number into the function insert
			//in which is from our struct and we declared
			//that function in our struct. All it does is
			//it will pass in that number in which is
			//the index of what to connect
			adjacencyList[i].insert(& adjacencyList[number]);
		
		//while the semi colon exists we won't stop looping
		//but when there isn't anymore semi colons we will
		//stop
		}while(file.get() == ',');

		//uses the copy function to copy whatever what was
		//passed into temp and temp is now copied into the
		//struct
		//adjacencyList[i].copy(temp);
	}
	//closes the file
	file.close();
}

//this is to insert a vertex node in our
//adjacencyList to form a linear linked list
//of pointers. The linear linked list of 
//pointers are to point to certain adjacency
//lists 
void vertex::insert(vertex * toAdd)
{
	//we make a new temporary pointer
	//that is a new node
	node * temp = new node;

	//we add our pointer into our new
	//temp pointer
	temp -> adjacent = toAdd;

	//since head exists, we can insert
	//in the front of our head but we
	//aren't done yet
	temp -> next = head;
	
	//make head equivalent to temp because
	//when you try to display with head
	//it won't display the new added node
	//because head hasn't been updated yet. 
	head = temp;
}

//a copy function for your vertex struct
//the reason why I made this a struct is 
//because I want to access my variables
//easily through it and call it through
//my readIn class graph function
int vertex::copy(vertex * copyWord)
{	
	//if the keyWord and sentence do not exist in the struct
	//then we will exit the program
	if(copyWord -> keyWord == NULL || copyWord -> sentence == NULL)
	{
		//we exit the program
		return 0;
	}
	
	//make an integer that is equivalent to the length
	//of our current keyWord
	int len = strlen(copyWord -> keyWord);

	//make a new keyWord that we will store in adding 1
	//the null pointer
	keyWord = new char[len + 1];

	//and then string copy our read in word into our new word
	//and store that into our vertex
	strcpy(keyWord, copyWord -> keyWord);

	//make a second integer that is equivalent to the
	//length of our urrent sentence
	int len2 = strlen(copyWord -> sentence);

	//make a new sentence ethat we will store in adding
	//1 to the null pointer
	sentence = new char[len2 + 1];

	//string copies our read in sentence into our new
	//sentence and store that into our vertex
	strcpy(sentence, copyWord -> sentence);
	
}

//this functil will take in a char response from the
//user in which is called from main. What this function 
//does is that the user can type in a keyWord and 
//whatever the keyword is we will display the chosen
//and available keyword and the sentence
int table::displayChosen(char * userResponse)
{
	//if the adjacencyList does not exist. We will
	//exit
	if(adjacencyList == NULL)
		return 0;
	
	//for how many adjacencyLists there are we will
	//go through the for loop to search for our keyword
	for(int i = 0; i < listSize; ++i)
	{
		//if the string compare user response is the same
		//as the keyword that is in our vertex struct then
		//we will display our keyword and sentence
		if(strcmp(userResponse, adjacencyList[i].keyWord) == 0)
		{
			//displays our keyword and sentence in which is located
			//through the for loop
			cout << '\n' << endl;
			cout << "Keyword: " << adjacencyList[i].keyWord << endl;
			cout << "Fact: " << adjacencyList[i].sentence << endl;
			cout << '\n' << endl;
		}
	}
}

//the wrapper function to displaySimilar. It takes in a character pointer
//in which is the user response in which they want to find the exact key
//word thta they want
int table::displaySimilar(char * userResponse)
{
	//goes through our list of adjacencyLists in which contains the
	//keywords and sentences
	for(int i = 0; i < listSize; ++i)
	{
		//if the userResponse is matching the keyword that is 
		//in our adjacencyList, then the if statement occurs
		if(strcmp(userResponse, adjacencyList[i].keyWord) == 0)
		{

			//calls the recursive function displaySimiliar so we dont
			//have to call it in main
			displaySimilar(adjacencyList[i].head);
		}
	}
}

//the function that will display the similar keyWords and sentences
//it passes in a node called head in which is made in this function.
int table::displaySimilar(node * head)
{
	//if the head doesn't exist
	if(head == NULL)
		return 0;

	//displays the keyword and the sentence through accessing
	//the vertex struct and through the node so we can access
	//our keyWord and sentence
	cout << '\n' << endl;
	cout << "Keyword: " << head -> adjacent -> keyWord << endl;
	cout << "Sentence: " << head -> adjacent -> sentence << endl;
	cout << '\n' << endl;
	
	//recursively calls the function all over again so we can
	//display our next node in the list
	displaySimilar(head -> next); 				
		
}

//our display function that we will use to display our
//whole graph
int table::display()
{
	cout << '\n' << endl;
	//goes through a for loop the size of our graph
	for(int i = 0; i < listSize; ++i)
	{
		cout << '\n' << endl;		

		//displays our keyword
		cout << "Keyword: " << adjacencyList[i].keyWord << endl;

		//displays our sentence
		cout << "Fact: " << adjacencyList[i].sentence << endl;
	}
	cout << '\n' << endl;
}

//if the responses are anything else other than 4, then we will
//ask the user if they would like to enter in another option in the
//program, and that is where the do while loop comes in. If yes,
//then we will do the program all over again, if no, they we will leave.

//The wrapper function in which we will traverse and display
int table::depthFirstDisplay(char * userResponse2)
{
	//we use a for loop to go through the list so we can look for 
	//our adjacencyList and the keyword so we can compare
	for(int i = 0; i < listSize; ++i)
	{
		//if the stringcompare user response and keyword are the 
		//same, we will recursively call the function again
		//because this is a wrapper function
		if(strcmp(userResponse2, adjacencyList[i].keyWord) == 0)
		{
			//calls the wrapper function in which is the
			//adjacencyList and we want to put on an 
			//ampersand because we were getting segmentation
			//faults and it needed to be passed in through
			//and ampersand
			depthFirstDisplay(& adjacencyList[i]);
		}
	}
	
	//we use a for loop to go through the list so we can look for 
	//our adjacencyList and the keyword so we can compare
	for(int i = 0; i < listSize; ++i)
	{
		//we are calling our adjacencyList flag because we are
		//basically marking a flagged terrotory. What that does
		//is that it will mark a node and if it is turned into
		//1 we will not ddisplay it anymore
		adjacencyList[i].flag = 0;
	}
}

//if the responses are anything else other than 4, then we will
//ask the user if they would like to enter in another option in the
//program, and that is where the do while loop comes in. If yes,
//then we will do the program all over again, if no, they we will leave.
int table::depthFirstDisplay(vertex * head)
{
	//if head doesnt exist or if it is NULL then we will return 0
	if(!head)
		return 0;
	
	//if the head flag is 1 then we will return 0
	if(head -> flag == 1)
		return 0;

	//head in which is passing in flag is going to be equal to
	//one because we need to "flag" our node in order to display
	//our next node without having to display it twice going
	//through the graph. 
	head -> flag = 1;

	//displays the keyword and the sentences
	cout << '\n' << endl;
	cout << "Keyword: " << head -> keyWord << endl;
	cout << "Sentence: " << head -> sentence << endl;
	cout << '\n' << endl;	

	//make a new current pointer equivalent to head in which
	//is passing in the vertex head. So this is just the 
	//right most pointer in the adjanccyList
	node * current = head -> head;
	
	//while the current exists 
	while(current)
	{
		//recursively calls the current goung through the 
		//adjancent list in which is the vertex. This is
		//basically how we display our graph
		depthFirstDisplay(current->adjacent); 

		//traverses down the linear linked list
		current = current -> next; 
	}
}

//this is a function that will remove all the nodes
//but will only remove all the nodes from one index of
//the array
int table::removeAllNodes(node * & head)
{
	//if head is null, that means the list is empty
	//which means we will exit the program
	if(!head)
		return 0;

	//make a recursive call which will traverse all the
	//way to the end and which will keep on returning
	//to the last node until it deletes all the nodes
	removeAllNodes(head -> next);

	//deletes head each time until it reaches NULL
	delete head;

	//always set our HEAD to null once we are done or 
	//else we will leak memory and get a segmentation
	//fault
	head = NULL;
	
}

//we are going to remove all of our array 
int table::removeAll()
{
	//if the adjacencyList is empty, then we leave the program
	if(!adjacencyList)
		return 0;

	//we use a for loop that will go through the array of
	//linear linked list depending on how many are in the
	//list
	for(int i = 0; i < listSize; ++i)
	{
	
		//if the adjacency list information exists
		//this if condition initializes
		if(adjacencyList[i].keyWord && adjacencyList[i].sentence)
		{
			//calls the remove all nodes in which will 
			//remove all the nodes calling the 
			//head index of adjacency list index head
			removeAllNodes(adjacencyList[i].head);
		}
		//after everything hs been deleted we set 
		//head to NULL
		adjacencyList[i].head = NULL;
		
	}
	//after our for loop we would want to delete our 
	//adjacency list because that is what we are 
	//trying to do in our destructor
	delete adjacencyList;

	//always set adjacencyList to NULL or else we will
	//get a segmentation fault
	adjacencyList = NULL; 
}

