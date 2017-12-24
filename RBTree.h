// Name of Author: Vijay Ramakrishna
// ASU ID: 1202948495
// Homework Number: 5
// Description: This program generates a Red-Black Tree and then prompts the user to enter commands, which allow them
//              to manipulate the contents of the Red-Black Tree. The program parses these commands and calls a corresponding method
//              using user input as arguments. The program will keep asking a user to enter the
//              next command until the choice of 'quit' (Quit) is entered. This file is the
//              Red-Black Tree class file for the program.

#include <iostream> //to use cout
#include <iomanip> //to format output
#include <string> //to use strings
#include <stdlib.h> // to free nodes

using namespace std;

//struct Athlete represents some Athlete information
struct Athlete
{
    char color;
    string key;
    string discipline;
    string gender;
    string team_or_ind;
    string event;
    string venue;
    string medal;
    string athlete;
    string country;
    struct Athlete * parent;
    struct Athlete * left;
    struct Athlete * right;
};

//class RBTree will be a Red-Black Tree of Athletes
class RBTree
{
    private:
        struct Athlete * root;
    public:
        RBTree();
        struct Athlete * getRoot();
        void preOrderTreeWalk(Athlete * n);
        void inOrderTreeWalk(Athlete * n);
        void postOrderTreeWalk(Athlete * n);
        void treeMinimum();
        void treeMaximum();
        bool treePredecessor(string iKey);
        bool treeSuccessor(string iKey);
        bool treeSearch(string iKey);
        void treeInsert(string iKey);
        void treeInsertFixup(Athlete * insertedNode);
        void treeLeftRotate(Athlete * n);
        void treeRightRotate(Athlete * n);
        void treeDelete(Athlete * deletionNode);
        void treeTransplant(Athlete * originalNode, Athlete * replacementNode);
        void destructor();
};

// Red-Black Tree Constructor
// Description: Constructor to initialize a Red Black Tree
RBTree::RBTree()
{
    root = NULL;
}

// Get Root
// Description: Getter for the root of the RBTree, used for driving all Tree Walk methods
Athlete * RBTree::getRoot()
{
    return root;
}

// Pre-Order Tree Walk
// Description: Traverses and prints the contents of each node, using Pre-Order
// traversal algorithm. (Root, Left, Right)or prints the tree is empty. This is
// done using recursion.
void RBTree::preOrderTreeWalk(Athlete * n)
{
    if (root == NULL)
    {
        cout << "tree is empty"<<endl<<endl;
    }
    else
    {
        // Print root, recursively call function on left and then right child
        struct Athlete * currentPointer = n;
        cout << "discipline: " << currentPointer->discipline << endl << "gender: " << currentPointer->gender << endl << "team_or_ind: " << currentPointer->team_or_ind << endl << "event: " << currentPointer->event << endl << "venue: " << currentPointer->venue << endl << "medal: " << currentPointer->medal << endl << "athlete: " << currentPointer->athlete << endl << "country: " << currentPointer->country << endl << endl;
        if (n->left != NULL)
        {
            preOrderTreeWalk(n->left);
        }
        if (n->right != NULL)
        {
            preOrderTreeWalk(n->right);
        }
    }
}

// In-Order Tree Walk
// Description: Traverses and prints the contents of each node, using In-Order
// traversal algorithm. (Left, Root, Right)or prints the tree is empty. This is
// done using recursion.
void RBTree::inOrderTreeWalk(Athlete * n)
{
    if (root == NULL)
    {
        cout << "tree is empty"<<endl<<endl;
    }
    else
    {
        // Recursively call function on left child, Print Root, Recursively call function on right child
        if (n->left != NULL)
        {
            inOrderTreeWalk(n->left);
        }
        struct Athlete * currentPointer = n;
        cout << "discipline: " << currentPointer->discipline << endl << "gender: " << currentPointer->gender << endl << "team_or_ind: " << currentPointer->team_or_ind << endl << "event: " << currentPointer->event << endl << "venue: " << currentPointer->venue << endl << "medal: " << currentPointer->medal << endl << "athlete: " << currentPointer->athlete << endl << "country: " << currentPointer->country << endl << endl;
        if (n->right != NULL)
        {
            inOrderTreeWalk(n->right);
        }
    }
}

// Post-Order Tree Walk
// Description: Traverses and prints the data of each node, using Post-Order
// traversal algorithm (Left, Right, Root) or prints the tree is empty. This is
// done using recursion.
void RBTree::postOrderTreeWalk(Athlete * n)
{
    if (root == NULL)
    {
        cout << "tree is empty"<<endl<<endl;
    }
    else
    {
        // Recursively call function on left child, Recursively call function on right child, Print Root
        if (n->left != NULL)
        {
            postOrderTreeWalk(n->left);
        }
        if (n->right != NULL)
        {
            postOrderTreeWalk(n->right);
        }
        struct Athlete * currentPointer = n;
        cout << "discipline: " << currentPointer->discipline << endl << "gender: " << currentPointer->gender << endl << "team_or_ind: " << currentPointer->team_or_ind << endl << "event: " << currentPointer->event << endl << "venue: " << currentPointer->venue << endl << "medal: " << currentPointer->medal << endl << "athlete: " << currentPointer->athlete << endl << "country: " << currentPointer->country << endl << endl;
    }
}

// Tree Minimum
// Description: Finds and prints the first node in the tree's data (lowest ranking key) or prints the tree is empty
void RBTree::treeMinimum()
{
    if (root == NULL)
    {
        cout << "tree is empty"<<endl<<endl;
    }
    else
    {
        //find leftmost node starting from root
        struct Athlete * n = root;
        while (n->left != NULL)
        {
            n = n->left;
        }
        cout << "The first athlete is: " <<endl<<endl;
        cout << "discipline: " << n->discipline << endl << "gender: " << n->gender << endl << "team_or_ind: " << n->team_or_ind << endl << "event: " << n->event << endl << "venue: " << n->venue << endl << "medal: " << n->medal << endl << "athlete: " << n->athlete << endl << "country: " << n->country << endl << endl;
    }
}

// Tree Maximum
// Description: Finds and prints the last node in the tree's data (highest ranking key)or prints the tree is empty
void RBTree::treeMaximum()
{
    if (root == NULL)
    {
        cout << "tree is empty"<<endl<<endl;
    }
    else
    {
        //find rightmost node starting from root
        struct Athlete * n = root;
        while (n->right != NULL)
        {
            n = n->right;
        }
        cout << "The last athlete is: " << endl<<endl;
        cout << "discipline: " << n->discipline << endl << "gender: " << n->gender << endl << "team_or_ind: " << n->team_or_ind << endl << "event: " << n->event << endl << "venue: " << n->venue << endl << "medal: " << n->medal << endl << "athlete: " << n->athlete << endl << "country: " << n->country << endl << endl;
    }
}

// Tree Predecessor
// Description: Parses user input to generate a key and looks for the corresponding node with a matching key
// Upon finding this node, finds and prints data for its In-Order Traversal Predecessor. If a bad input is entered
// will return false. If a valid entry is entered, but the entry has no predecessor, will print a message
// indicating no predecessor. If tree is empty will print message indicating this.
bool RBTree::treePredecessor(string iKey)
{
    if (root == NULL)
    {
        cout << "tree is empty"<< endl << endl;
        return true;
    }
    // Validate Search Entry
    int commaCounter = 0;
    // Count the number of commas in the search command
    for (int i = 0; i < iKey.size(); i++)
    {
        if (iKey.substr(i, 1) == ",")
        {
            commaCounter++;
        }
    }
    // If the number of commas is not 4, immediately end the search and return false
    if(commaCounter != 4)
    {
        return false;
    }

    // Create strings to hold data from commands
    string mDiscipline = "";
    string mGender = "";
    string mEvent = "";
    string mAthlete = "";

    //Create size_t variables to mark comma positions
    size_t treeToken;
    size_t disciplineToken;
    size_t genderToken;
    size_t eventToken;
    size_t athleteToken;

    // Find commas in search command
    treeToken = iKey.find(",");
    disciplineToken = iKey.find(",", treeToken+1, 1);
    genderToken = iKey.find(",", disciplineToken+1, 1);
    eventToken = iKey.find(",", genderToken+1, 1);
    athleteToken = iKey.find(",", eventToken+1, 1);

    // Assign values to previously created strings, based on comma positions
    mDiscipline = iKey.substr(treeToken+ 1, disciplineToken - treeToken - 1);
    mGender = iKey.substr(disciplineToken + 1, genderToken - disciplineToken - 1);
    mEvent = iKey.substr(genderToken + 1, eventToken - genderToken - 1);
    mAthlete = iKey.substr(eventToken+1, athleteToken-eventToken-1);

    // Generate key by appending discipline, event, gender, and athlete
    string mKey;
    mKey.append(mDiscipline);
    mKey.append(mEvent);
    mKey.append(mGender);
    mKey.append(mAthlete);

    struct Athlete * compareNode = root;
    struct Athlete * predecessor;
    bool currentNodeFound = false;
    bool predecessorFound = false;

    // Search for node with matching key
    while (compareNode != NULL)
    {
        int comparator = mKey.compare(compareNode->key);
        if (comparator == 0)
        {
            currentNodeFound = true;
            break;
        }
        else if (comparator > 0)
        {
            compareNode = compareNode->right;
        }
        else if (comparator < 0)
        {
            compareNode = compareNode->left;
        }
    }

    // Search for predecessor to matching node
    if (currentNodeFound == true)
    {
        if (compareNode->left != NULL)
        {
            // Search child's subtree for predecessor
            Athlete * n = compareNode->left;
            while (n->right != NULL)
            {
                n = n->right;
            }
            predecessor = n;
            predecessorFound = true;
        }
        else
        {
            // Search parent's parents and subtree for predecessor
            Athlete * y = compareNode->parent;
            while (y != NULL && compareNode == y->left)
            {
                compareNode = y;
                y = y->parent;
            }
            predecessor = y;
            if (predecessor!= NULL)
            {
                predecessorFound = true;
            }
        }
    }
    if (predecessorFound == false || currentNodeFound == false)
    {
        cout << "The medal recipient " << mAthlete << " for " << mDiscipline << " with event " << mEvent << " does not have any predecessor" << endl << endl;
    }
    else
    {
        cout << "The predecessor of the medal recipient " << mAthlete << " for " << mDiscipline << " with event " << mEvent << " is: " << endl << endl;
        cout << "discipline: " << predecessor->discipline << endl << "gender: " << predecessor->gender << endl << "team_or_ind: " << predecessor->team_or_ind << endl << "event: " << predecessor->event << endl << "venue: " << predecessor->venue << endl << "medal: " << predecessor->medal << endl << "athlete: " << predecessor->athlete << endl << "country: " << predecessor->country << endl << endl;
    }
    return true;
}

// Tree Successor
// Description: Parses user input to generate a key and looks for the corresponding node with a matching key
// Upon finding this node, finds and prints data for its In-Order Traversal Successor. If a bad input is entered
// will return false. If a valid entry is entered, but the entry has no predecessor, will print a message
// indicating no predecessor. If tree is empty will print message indicating this.
bool RBTree::treeSuccessor(string iKey)
{
    if (root == NULL)
    {
        cout << "tree is empty"<< endl << endl;
        return true;
    }
    // Validate Search Entry
    int commaCounter = 0;
    // Count the number of commas in the search command
    for (int i = 0; i < iKey.size(); i++)
    {
        if (iKey.substr(i, 1) == ",")
        {
            commaCounter++;
        }
    }
    // If the number of commas is not 4, immediately end the search and return false
    if(commaCounter != 4)
    {
        return false;
    }

    // Create strings to hold data from commands
    string mDiscipline = "";
    string mGender = "";
    string mEvent = "";
    string mAthlete = "";

    //Create size_t variables to mark comma positions
    size_t treeToken;
    size_t disciplineToken;
    size_t genderToken;
    size_t eventToken;
    size_t athleteToken;

    // Find commas in search command
    treeToken = iKey.find(",");
    disciplineToken = iKey.find(",", treeToken+1, 1);
    genderToken = iKey.find(",", disciplineToken+1, 1);
    eventToken = iKey.find(",", genderToken+1, 1);
    athleteToken = iKey.find(",", eventToken+1, 1);

    // Assign values to previously created strings, based on comma positions
    mDiscipline = iKey.substr(treeToken+ 1, disciplineToken - treeToken - 1);
    mGender = iKey.substr(disciplineToken + 1, genderToken - disciplineToken - 1);
    mEvent = iKey.substr(genderToken + 1, eventToken - genderToken - 1);
    mAthlete = iKey.substr(eventToken+1, athleteToken-eventToken-1);

    // Generate key by appending discipline, event, gender, and athlete
    string mKey;
    mKey.append(mDiscipline);
    mKey.append(mEvent);
    mKey.append(mGender);
    mKey.append(mAthlete);

    struct Athlete * compareNode = root;
    struct Athlete * successor;
    bool currentNodeFound = false;
    bool successorFound = false;

    //Search for node with matching key
    while (compareNode != NULL)
    {
        int comparator = mKey.compare(compareNode->key);
        if (comparator == 0)
        {
            currentNodeFound = true;
            break;
        }
        else if (comparator > 0)
        {
            compareNode = compareNode->right;
        }
        else if (comparator < 0)
        {
            compareNode = compareNode->left;
        }
    }
    // Search for successor to matching node
    if (currentNodeFound == true)
    {
        if (compareNode->right != NULL)
        {
            // Search child's subtree for successor
            Athlete * n = compareNode->right;
            while (n->left != NULL)
            {
                n = n->left;
            }
            successor = n;
            successorFound = true;
        }
        else
        {
            // Search parent's parents and subtree for successor
            Athlete * y = compareNode->parent;
            while (y != NULL && compareNode == y->right)
            {
                compareNode = y;
                y = y->parent;
            }
            successor = y;
            if (successor != NULL)
            {
                successorFound = true;
            }
        }
    }
    if (successorFound == false || currentNodeFound == false)
    {
        cout << "The medal recipient " << mAthlete << " for " << mDiscipline << " with event " << mEvent << " does not have any successor" << endl << endl;
    }
    else
    {
        cout << "The successor of the medal recipient " << mAthlete << " for " << mDiscipline << " with event " << mEvent << " is: " << endl << endl;
        cout << "discipline: " << successor->discipline << endl << "gender: " << successor->gender << endl << "team_or_ind: " << successor->team_or_ind << endl << "event: " << successor->event << endl << "venue: " << successor->venue << endl << "medal: " << successor->medal << endl << "athlete: " << successor->athlete << endl << "country: " << successor->country << endl << endl;
    }
    return true;
}

// Tree Search
// Description: Parses user input to generate a key and looks for the corresponding node with a matching key
// and prints medal information corresponding with that node. If a bad input is entered
// will return false. If node is not found, will print a message indicating as much.
// If tree is empty will print message indicating this.
bool RBTree::treeSearch(string iKey)
{
    if (root == NULL)
    {
        cout << "tree is empty"<< endl << endl;
        return true;
    }
// Validate Search Entry
    int commaCounter = 0;
    // Count the number of commas in the search command
    for (int i = 0; i < iKey.size(); i++)
    {
        if (iKey.substr(i, 1) == ",")
        {
            commaCounter++;
        }
    }
    // If the number of commas is not 4, immediately end the search and return false
    if(commaCounter != 4)
    {
        return false;
    }

    // Create strings to hold data from commands
    string mDiscipline = "";
    string mGender = "";
    string mEvent = "";
    string mAthlete = "";

    //Create size_t variables to mark comma positions
    size_t treeToken;
    size_t disciplineToken;
    size_t genderToken;
    size_t eventToken;
    size_t athleteToken;

    // Find commas in search command
    treeToken = iKey.find(",");
    disciplineToken = iKey.find(",", treeToken+1, 1);
    genderToken = iKey.find(",", disciplineToken+1, 1);
    eventToken = iKey.find(",", genderToken+1, 1);
    athleteToken = iKey.find(",", eventToken+1, 1);

    // Assign values to previously created strings, based on comma positions
    mDiscipline = iKey.substr(treeToken+ 1, disciplineToken - treeToken - 1);
    mGender = iKey.substr(disciplineToken + 1, genderToken - disciplineToken - 1);
    mEvent = iKey.substr(genderToken + 1, eventToken - genderToken - 1);
    mAthlete = iKey.substr(eventToken+1, athleteToken-eventToken-1);

    // Generate key by appending discipline, event, gender, and athlete
    string mKey;
    mKey.append(mDiscipline);
    mKey.append(mEvent);
    mKey.append(mGender);
    mKey.append(mAthlete);

    bool found = false;
    struct Athlete * x = root;

    // Search for node with matching key
    while (x != NULL)
    {
        int comparator = mKey.compare(x->key);
        if (comparator == 0)
        {
            found = true;
            break;
        }
        else if (comparator > 0)
        {
            x = x->right;
        }
        else if (comparator < 0)
        {
            x = x->left;
        }
    }
    if (found == false)
    {
        cout << mAthlete << " for " << mDiscipline << " with event " << mEvent << " not found" <<endl<<endl;
    }
    else
    {
        cout << "The medal recipient " << x->athlete << " has the medal of " << x->medal << endl;
    }
    return true;
}

// Tree Insert
// Description: Parses user input to generate data for a new node, and creates and stores this data
// in a new node. The node is then inserted into the Red-Black Tree using BST Insertion. After BST
// insertion, another method is called, Tree Insert Fix-up, which edits colors and calls the Left
// Rotate and Right Rotate methods to ensure that Red-Black Tree properties are not violated.
void RBTree::treeInsert(string iKey)
{
    // Validate New Entry
    int commaCounter = 0;
    // Count the number of commas in the entry
    for (int i = 0; i < iKey.size(); i++)
    {
        if (iKey.substr(i, 1) == ",")
        {
            commaCounter++;
        }
    }
    // If the number of commas is not 8, immediately end insertion and return false
    if(commaCounter != 8)
    {
        cout << "Bad Command" << endl<<endl;
        return;
    }

    // Create and Initialize strings for new Athlete entry
    string mDiscipline = "";
    string mGender = "";
    string mTeam_or_ind = "";
    string mEvent = "";
    string mVenue = "";
    string mMedal = "";
    string mAthlete = "";
    string mCountry = "";
    string mKey = "";

    // Declare size_t variables to find commas
    size_t treeToken;
    size_t disciplineToken;
    size_t genderToken;
    size_t teamToken;
    size_t eventToken;
    size_t venueToken;
    size_t medalToken;
    size_t athleteToken;
    size_t countryToken;

    // Find commas in new entry
    treeToken = iKey.find(",");
    disciplineToken = iKey.find(",", treeToken+1, 1);
    genderToken = iKey.find(",", disciplineToken+1, 1);
    teamToken = iKey.find(",", genderToken+1, 1);
    eventToken = iKey.find(",", teamToken+1, 1);
    venueToken = iKey.find(",", eventToken+1, 1);
    medalToken = iKey.find(",", venueToken+1, 1);
    athleteToken = iKey.find(",", medalToken+1, 1);
    countryToken = iKey.find(",", athleteToken+1, 1);

    // Assign previously declared strings values depending on comma positions
    mDiscipline = iKey.substr(treeToken+ 1, disciplineToken - treeToken - 1);
    mGender = iKey.substr(disciplineToken + 1, genderToken - disciplineToken - 1);
    mTeam_or_ind = iKey.substr(genderToken + 1, teamToken - genderToken - 1);
    mEvent = iKey.substr(teamToken + 1, eventToken - teamToken - 1);
    mVenue = iKey.substr(eventToken + 1, venueToken-eventToken-1);
    mMedal = iKey.substr(venueToken+1, medalToken-venueToken-1);
    mAthlete = iKey.substr(medalToken+1, athleteToken-medalToken-1);
    mCountry = iKey.substr(athleteToken+1, countryToken-athleteToken-1);

    // Generate key by appending discipline, event, gender, and athlete
    mKey.append(mDiscipline);
    mKey.append(mEvent);
    mKey.append(mGender);
    mKey.append(mAthlete);

    struct Athlete * newAthlete = new Athlete;
    struct Athlete * x = root;
    struct Athlete * y = NULL;

    // Populate the new node with data
    newAthlete->discipline = mDiscipline;
    newAthlete->gender = mGender;
    newAthlete->team_or_ind = mTeam_or_ind;
    newAthlete->event = mEvent;
    newAthlete->venue = mVenue;
    newAthlete->medal = mMedal;
    newAthlete->athlete = mAthlete;
    newAthlete->country = mCountry;
    newAthlete->key = mKey;

    // Insert new node in RB Tree using BST Insertion
    while (x != NULL) // determine correct position to place new node, and determine if the node already exists. If it does, print to console and exit insertion
    {
        int comparator = mKey.compare(x->key);
        y = x;
        if (comparator < 0)
        {
            x=x->left;
        }
        else if (comparator > 0)
        {
            x = x->right;
        }
        else if (comparator == 0)
        {
            cout << "The medal recipient " << mAthlete << " for " << mDiscipline << " with event " << mEvent << " NOT inserted" <<endl<<endl;
            return;
        }
    }
    // Place new node in correct position, connect to parent
    newAthlete->parent = y;
    if (y == NULL)
    {
        root = newAthlete;
    }
    else
    {
        int parentComparator = mKey.compare(y->key);
        if (parentComparator >0)
        {
            y->right = newAthlete;
        }
        else if (parentComparator < 0)
        {
            y->left = newAthlete;
        }
    }
    newAthlete->left = NULL;
    newAthlete->right = NULL;
    newAthlete->color = 'r';
    // Call Tree Insert Fix-up to edit Tree to maintain Red-Black Tree Properties
    treeInsertFixup(newAthlete);
    cout << "The medal recipient " << mAthlete << " for " << mDiscipline << " with event " << mEvent << " inserted" <<endl<<endl;
    return;
}

// Tree Insert Fix-up
// Description: Swaps colors and calls the Left Rotate and Right Rotate methods
// to ensure that Red-Black Tree properties are not violated. The exact way this is done
// depends on the insertion case.
void RBTree::treeInsertFixup(Athlete * insertedNode)
{
    if (root == insertedNode) // if the new  node is the root, color it black and end
    {
        insertedNode->color = 'b';
        return;
    }
    else
    {
        struct Athlete * mUncle = NULL;
        while (insertedNode->parent != NULL && insertedNode->parent->color == 'r' ) //checks that insertedNode has parent and grandparent as if parent's color is red, it must also have a black parent
        {
            if (insertedNode->parent->parent->left == insertedNode->parent)
            {
                mUncle = insertedNode->parent->parent->right; // find Uncle
                if (mUncle != NULL && mUncle->color == 'r')
                {
                    insertedNode->parent->parent->color = 'r'; // Case 1: Recolor Grandparent, Parent, Uncle, then look at Grandparent
                    insertedNode->parent->color = 'b';
                    mUncle->color = 'b';
                    insertedNode = insertedNode->parent->parent;
                }
                else
                {
                    if (insertedNode->parent->right == insertedNode)
                    {
                        insertedNode = insertedNode->parent; // Case 2: Look at parent node and Left Rotate it
                        treeLeftRotate(insertedNode);
                    }
                    insertedNode->parent->color = 'b'; //Case 3: Recolor Parent, Grandparent, Right Rotate Grandparent
                    insertedNode->parent->parent->color = 'r';
                    treeRightRotate(insertedNode->parent->parent);
                }
            }
            else
            {
                mUncle = insertedNode->parent->parent->left; // find Uncle
                if (mUncle != NULL && mUncle->color == 'r')
                {
                    insertedNode->parent->parent->color = 'r'; // Case 4: Recolor Grandparent, Parent, Uncle, then look at Grandparent
                    insertedNode->parent->color = 'b';
                    mUncle->color = 'b';
                    insertedNode = insertedNode->parent->parent;
                }
                else
                {
                    if (insertedNode->parent->left == insertedNode)
                    {
                        insertedNode = insertedNode->parent; // Case 5: Look at parent node and Right Rotate it
                        treeRightRotate(insertedNode);
                    }
                    insertedNode->parent->color = 'b'; // Case 6:  Recolor Parent, Grandparent, Left Rotate Grandparent
                    insertedNode->parent->parent->color = 'r';
                    treeLeftRotate(insertedNode->parent->parent);
                }
            }
        }
        root->color = 'b'; // Color root black
    }
}

// Tree Left Rotate
// Description: If the node to be rotated has a right child, will rotate the node to
// the left. Otherwise, will do nothing.
void RBTree::treeLeftRotate(Athlete * n)
{
    if (n->right == NULL) // if n does not have a right child, do nothing
    {
        return;
    }
    else
    {
        // Left Rotate node
        struct Athlete * y = n->right;
        n->right = y->left;
        if (y->left != NULL)
        {
            y->left->parent = n;
        }
        y->parent = n->parent;
        if (n->parent == NULL)
        {
            root = y;
        }
        else if (n == n->parent->left)
        {
            n->parent->left = y;
        }
        else
        {
            n->parent->right = y;
        }
        y->left = n;
        n->parent = y;
    }
}

// Tree Right Rotate
// Description: If the node to be rotated has a right child, will rotate the node to
// the right. Otherwise, will do nothing.
void RBTree::treeRightRotate(Athlete * n)
{
    if (n->left == NULL) // if n does not have a left child, do nothing
    {
        return;
    }
    else
    {
        // Right Rotate node
        struct Athlete * y = n->left;

        n->left = y->right;
        if (y->right != NULL)
        {
            y->right->parent = n;
        }
        y->parent = n->parent;
        if (n->parent == NULL)
        {
            root = y;
        }
        else if (n == n->parent->left)
        {
            n->parent->left = y;
        }
        else
        {
            n->parent->right = y;
        }
        y->right = n;
        n->parent = y;
    }
}

// Tree Delete
// Description: BST Deletion. Called by the destructor. First determines which, if any of the
// nodes should replace the deleted node's position, and then calls the
// Tree Transplant method to actually do this. After this is done, frees
// memory allocated to the node.
void RBTree::treeDelete(Athlete * deletionNode)
{
    if (deletionNode->left == NULL)
    {
        treeTransplant(deletionNode, deletionNode->right); // Case where node has no left node, replace with right child
    }
    else if (deletionNode->right == NULL)
    {
        treeTransplant(deletionNode, deletionNode->left); // case where node has no right node, replace with left child
    }
    else // Case where node has two children
    {
        // Find Successor and replace original node with it
        struct Athlete * y = deletionNode->right;
        while (y->left != NULL)
        {
            y = y->left;
        }
        if (y->parent != deletionNode)
        {
            treeTransplant(y, y->right);
            y->right = deletionNode->right;
            y->right->parent = y;
        }
        treeTransplant(deletionNode, y);
        y->left = deletionNode->left;
        y->left->parent = y;
    }
    free(deletionNode); // Free memory allocated to node deleted
}

// Tree Transplant
// Description: Replaces one node with another.
void RBTree::treeTransplant(Athlete * originalNode, Athlete * replacementNode)
{
    if(originalNode->parent == NULL)
    {
        root = replacementNode; // Replacement node becomes root if Original node was root
    }
    else if (originalNode == originalNode->parent->left)
    {
        originalNode->parent->left = replacementNode; // Makes replacement node left child of original node's parent
    }
    else
    {
        originalNode->parent->right = replacementNode; // Makes replacement node right child of original node's parent
    }
    if (replacementNode != NULL)
    {
        replacementNode->parent = originalNode->parent; // Makes replacement node's parent equal to original node's parent.
    }
}

// Red-Black Tree Destructor
// Description: Destructor for the Red-Black Tree. While the root of the Red-Black Tree is not null, will call
// the Tree Delete method on the root of the tree, and counts each node as it
// deletes it. After deleted nodes, prints how many nodes were deleted.
void RBTree::destructor()
{
    int deletionCounter = 0;
    while (root != NULL)
    {
        treeDelete(root); // Delete node
        deletionCounter++; // Increment deletion counter by 1
    }
    cout << "the number of nodes deleted: " << deletionCounter << endl << endl;

}
