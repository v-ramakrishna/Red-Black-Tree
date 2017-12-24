// Name of Author: Vijay Ramakrishna
// ASU ID: 1202948495
// Homework Number: 5
// Description: This program generates a Red-Black Tree and then prompts the user to enter commands, which allow them
//              to manipulate the contents of the Red-Black Tree. The program parses these commands and calls a corresponding method
//              using user input as arguments. The program will keep asking a user to enter the
//              next command until the choice of 'quit' (Quit) is entered. This file is the
//              driver file for the program.

#include <iostream> // to manipulate input and output
#include <string> //to use strings
#include "RBTree.h" // to use Red-Black Trees

using namespace std;

void printMenu();

// Main
// Description: Driver to initialize and populate Red-Black Tree and run the program to issue commands.
// Will continue to ask for commands until the user quits the program.
int main()
{
    // Create variables to take and process commands
    string newCommand = "";
    string processCommand;
    string commandPrefix;
    string insertCommand;
    string endMarker = "\r";

    // Initialize Red-Black Tree
    RBTree * tree1 = new RBTree();

    //Print Menu
    printMenu();
    do  // will ask for user input
    {
        cout << endl << "Enter New Command: "; // Get User's Command
        getline(cin, newCommand);
        int saveLastPosition = newCommand.size()-1;
        if (saveLastPosition >= 0)
        {
            string analyzeCommand = newCommand.substr(saveLastPosition, 1); //Used to ensure compatibility with both Windows and UNIX machines
            if (analyzeCommand.compare(endMarker) == 0)
            {
                newCommand.erase(newCommand.size()-1);
            }
        }
        cout << "next command: " << newCommand <<endl<<endl; //print User Command
        commandPrefix = newCommand.substr(0,1); // find first letter of User Command

        if (commandPrefix == "t") // if first letter of User Command is "t"
        {
            processCommand = newCommand.substr (5,6); // Analyze letters 6-11 of the User Command
            if (processCommand == "inorde")
            {
                struct Athlete * treeRoot1 = tree1->getRoot(); // Find Tree Root
                tree1->inOrderTreeWalk(treeRoot1); // Call In Order Tree Walk, using Root as an argument
            }
            else if (processCommand == "preord")
            {
                struct Athlete * treeRoot2 = tree1->getRoot(); // Find Tree Root
                tree1->preOrderTreeWalk(treeRoot2); // Call Pre Order Tree Walk, using Root as an argument
            }
            else if (processCommand == "postor")
            {
                struct Athlete * treeRoot3 = tree1->getRoot(); // Find Tree Root
                tree1->postOrderTreeWalk(treeRoot3); // Call Post Order Tree Walk, using Root as an argument
            }
            else if (processCommand == "minimu")
            {
                tree1->treeMinimum(); // Call Tree Minimum
            }
            else if (processCommand == "maximu")
            {
                tree1->treeMaximum(); // Call Tree Maximum
            }
            else if (processCommand == "predec")
            {
                bool successPred = tree1->treePredecessor(newCommand); // Create new variable and set it equal to the return value of Tree Predecessor, using the User Command as an argument
                if (successPred == false)
                {
                    cout << "Bad Command" << endl << endl; // Print to console if command was invalid
                }
            }
            else if (processCommand == "succes")
            {
                bool successSucc = tree1->treeSuccessor(newCommand);// Create new variable and set it equal to the return value of Tree Successor, using the User Command as an argument
                if (successSucc == false)
                {
                    cout << "Bad Command" << endl << endl; // Print to console if command was invalid
                }
            }
            else if (processCommand == "search")
            {
                bool successSear = tree1->treeSearch(newCommand); // Create new variable and set it equal to the return value of Tree Search, using the User Command as an argument
                if (successSear == false)
                {
                    cout << "Bad Command" << endl << endl; // Print to console if command was invalid
                }
            }
            else if (processCommand == "insert")
            {
                tree1->treeInsert(newCommand); // Call Tree Insert, using User Command as an argument
            }
            else
            {
                cout << "Unknown action"<<endl<<endl; // Print to console if any other command is entered starting with the letter t

            }
        }
        else if (commandPrefix == "q")
        {
            processCommand = newCommand.substr (0,4);
            if (processCommand == "quit") // Verify User Command was indeed quit
            {
                tree1->destructor(); // Call destructor if the command was quit
            }
            else
            {
                cout << "Unknown action"<<endl<<endl; // Print to console "Unknown Action" is the command was anything else beginning with a q
            }
        }
        else if (commandPrefix == "?")
        {
            printMenu(); // Print Display Menu
        }
        else
        {
            cout << "Unknown action"<<endl<<endl; // Print to console that the action is unknown if the User Command does not begin with the letters t, q, or ?
        }

    } while (newCommand != "quit"); // Loop until user quits the program

    return 0;
}

// Print Menu
// Description: Displays Command options to the User
void printMenu()
{
    // Create text to print
    int lineSize = 85; // approximate size of largest item, character-wise, on left side of menu
    string commands = "Commands";
    string action = "Action";
    string lines = "------";
    string inorderText = "tree_inorder";
    string inorderText2 = "In-Order Tree Traversal";
    string preorderText = "tree_preorder";
    string preorderText2 = "Pre-Order Tree Traversal";
    string postorderText = "tree_postorder";
    string postorderText2 = "Post-Order Tree Traversal";
    string minimumText = "tree_minimum";
    string minimumText2 = "Find Tree Minimum";
    string maximumText = "tree_maximum";
    string maximumText2 = "Find Tree Maximum";
    string predText = "tree_predecessor,Discipline,Gender,Event,Athlete";
    string predText2 = "Find an Athlete's Tree Predecessor";
    string succText = "tree_successor,Discipline,Gender,Event,Athlete";
    string succText2 = "Find an Athlete's Tree Successor";
    string insertText = "tree_insert,Discipline,Gender,Team_or_Independent,Event,Venue,Medal,Athlete,Country";
    string insertText2 = "Add an Athlete";
    string searchText = "tree_search,Discipline,Gender,Event,Athlete";
    string searchText2 = "Search for an Athlete";
    string quitText = "quit";
    string quitText2 = "Quit";
    string questionText = "?";
    string questionText2 = "Display Help";

    // Format and Print Menu text to console
    cout <<commands << string(lineSize-commands.size(), ' ') <<action << endl;
    cout <<lines << string(lineSize-lines.size(), ' ') <<lines << endl;
    cout << inorderText << string(lineSize-inorderText.size(), ' ') <<inorderText2 << endl;
    cout << preorderText << string(lineSize-preorderText.size(), ' ') <<preorderText2 << endl;
    cout << postorderText << string(lineSize-postorderText.size(), ' ') <<postorderText2 << endl;
    cout << minimumText << string(lineSize-minimumText.size(), ' ') <<minimumText2 << endl;
    cout << maximumText << string(lineSize-maximumText.size(), ' ') <<maximumText2 << endl;
    cout << predText << string(lineSize-predText.size(), ' ') <<predText2 << endl;
    cout << succText << string(lineSize-succText.size(), ' ') <<succText2 << endl;
    cout <<searchText << string(lineSize-searchText.size(), ' ') <<searchText2 << endl;
    cout <<insertText << string(lineSize-insertText.size(), ' ') <<insertText2 << endl;
    cout <<quitText << string(lineSize-quitText.size(), ' ') <<quitText2 << endl;
    cout <<questionText << string(lineSize-questionText.size(), ' ') <<questionText2 << endl;
}

