//main.cpp

//This file, main.cpp, is supposed to be the user function in which
//will output something and input something from the user. The user
//is going to chose from types of keyWords and then the keyWords will
//display individually and will display the rest of the similarities.
//But notice some of these aren't relaly similarities but just connection
//points.

//We include our graph.h file because that is our only file
#include "graph.h"

using namespace std;

int main()
{
	//we have an instance of our table call in which we will use
	//throughout the mainfunction in order to call our table
	//functions
	table tableCall;

	//our local variables that only contain the user response and 
	//other factors that will make our main function better and easier
	//to read and implement
	int response;
	char response2 = 'Y';

	//we're using a do while loop because we want to be able to ask
	//the user if they want to work on the program all over again.
	do
	{

		cout << "This is the assignment #5 for CS 163" << endl;
		cout << '\n' << endl;
		cout << "You are going to enter in a key value" << endl;
		cout << "and we will return to you information" << endl;
		cout << "about that key value. If you want to" << endl;
		cout << "you have the option to change the subject" << endl;
		cout << "that is closely related" << endl;
		cout << '\n' << endl;
		cout << "|||||||||||||||||||||||||||||||" << endl;
		cout << '\n' << endl;
		cout << "Here are your options" << endl;
		cout << "(1) Load from a file" << endl;
		cout << "(2) Display all" << endl;
		cout << "(3) Display one" << endl;
		cout << "(4) Display related keywords and topic sentences" << endl; 
		cout << "(5) Display a path" << endl;
		cout << "(6) Exit the Program" << endl;
		cout << '\n' << endl;
		cout << "||||||||||||||||||||||||||||||||" << endl;
		cout << '\n' << endl;

		//takes in the user integer response. There results are a couple
		//lines over this statement and if the user enters in any numbers
		//from 1-4, depending on what number they chose the program 
		//executes a practice that was coded
		cin >> response;
		cin.ignore(100, '\n');

		//if the user respons is 1, the option they chose is to load in from
		//the file and also display all of their choices	
		if(response == 1)
		{
			cout << '\n' << endl;
			
			//from the graph class in which will read in from the file
			tableCall.readIn();
			
			cout << "Okay you have uploaded your keyword and terms" << endl;
			cout << '\n' << endl;
			cout << "Display them if you want to take a look at your" << endl;
			cout << "keywords and terms" << endl;
			cout << '\n' << endl;
		}

		//else if their response is 2, they can display EVERYTHING from the graph
		else if(response == 2)
		{
			cout << "Here are all your options you can chose from" << endl;
			cout << '\n' << endl;

			//will display all of whatever is in your graph. ALL OF IT
			tableCall.display();
			cout << '\n' << endl;	
		}

		//else if the response is 3, we can display a single graph from the
		//user input
		else if(response == 3)
		{
			//makes a character response. The user is going to enter
			//in a key word and we are going to display just one object
			//from the adjacencyList through a for loop
			char * response3 = new char[50];
			cout << "What key word are you going to enter in to display?" << endl;
			cin.get(response3, 50, '\n');
			cin.ignore(100, '\n');

			//will display the user's chosen keyWord and sentence through
			//keyword input
			tableCall.displayChosen(response3);	
		}
		
		//else if the response is 4, we can display our similar keywords and sentences
		// of whatever the user enters in depending on their response
		else if(response == 4)
		{
			//we make a temporary pointer in which we can just store that into
			//our dynamically allocated array later
			char temp[100];
			cout << "What key word are you going to enter in to display" << endl;
			cout << "a line of similar key words and sentences? " << endl;
			cin.get(temp, 100, '\n');
			cin.ignore(100, '\n');

			//dynamically allocate response4 into the string length of temp
			char * response4 = new char[strlen(temp) + 1];

			//string copy the user response into our dynamically allocated
			//array
			strcpy(response4, temp);

			//calls the display path function in which will take in a character
			//response and we will pass that into our function and that will
			//display through the path starting from our keyword
			tableCall.displaySimilar(response4);
		}

		//else if the response is 5, we can display a whole path starting off at 
		//the keyword the user picks
		else if(response == 5)
		{
			//makes a temporary array in which we will transfer that into our
			//dynamically allocated array later
			char temp[100];
			cout << "What key word are you going to enter to display a whole path?" << endl;
			cin.get(temp,100, '\n');
			cin.ignore(100, '\n');

			//dynamically allocates a new character for response5
			char * response5 = new char[strlen(temp) + 1];
			
			//string copies the user response temp into our newly dyncamilly alocated
			//array
			strcpy(response5, temp);

			//calls the depth first display. This means that this will display in 
			//order. Its nothing like the BST depth first display because the BST will
			//just go straight down a tree. The graph will go down through the path
			//and any path. In this case it needs a flag so it can mark that it has 
			//been to that node, and that we have touched that node.
			tableCall.depthFirstDisplay(response5);	
		}

		//if the user response is 5, then the goodbye message will display and
		//we will leave the program
		else if(response == 6)
		{
			//return 0 will just leave the program
			cout << "goodbye" << endl;
			return 0;
		}
		//if the responses are anything else other than 4, then we will
		//ask the user if they would like to enter in another option in the
		//program, and that is where the do while loop comes in. If yes,
		//then we will do the program all over again, if no, they we will leave.
		cout << "Would you like to enter in another option in the program" << endl;
		cout << "(y) for yes, or (n) for no" << endl;
		cin >> response2;
		cin.ignore(100, '\n');

	//when the user response is y, then we start over the do while loop or if it is
	//no then we will end the program. 
	}while(toupper(response2) == 'Y');

	//return 0 will just leave the program
	return 0;
}
