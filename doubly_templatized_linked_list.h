

// doubly_templatized_linked_list.h
// Author: Siraj Qazi
// Templatized Linked List v3.1
// Dated: September 16th, 2018 10:01PM
// Class <Generic>Node's class definition header file



#include <iostream>
#include <typeinfo>
#include <string>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#pragma warning(suppress: 6031)

template<typename Generic>          // Templatizing the class to make it Generic
class Node
{
public:
	Node(Generic input) : nodeData(input),next(NULL),previous(NULL) {}
	Generic nodeData;               // Generic object nodeData
	Node* next;                     // (traditional) next pointer in a Node
	Node* previous;                // Doubly linked
	class LinkedList               // Nested Class LinkedList to apply same templatization to this class
	{
	public:
		LinkedList() :head(NULL), tail(NULL), nodeCount(0) {}
		Node* head;                 // Node* pointer to the first node
		Node* tail;                 // Node* pointer to the last node
		int nodeCount;              // To keep track of total nodes (helps in bounds checking)
		char operationMode;         // Store current operation mode of Linked List (int, float, char, etc)

		/*
		void checkInputType(Generic input)
		{
			bool valid = false;
			const char* strType = typeid(input).name();   // Extract user input type (at runtime)
			string inputTypeInString((LPCTSTR)strType);
		}
		*/

		//void commenceOperation(void);                     // Chief Operation Function

		//void insertionMenu(void);                         // INSERTION OPERATIONS 
		//void insertAtStart(Generic);
		//void insertAtEnd(Generic);
		//void insertAtLocation(Generic, int);
		//void continuousInputMode(void);

		//void deletionMenu(void);                         // DELETION OPERATIONS 
		//void deleteFirstNode(void);
		//void deleteLastNode(void);
		//void deleteSpecificNode(int);
		//void deleteSpecificValue(Generic);
		//void deleteList(void);

		//void searchMenu(void);                           // SEARCH OPERATIONS
		//void searchByIndex(int);
		//void searchByValue(Generic);

		//void printList(void);                            // PRINT OPERATIONS
		//void printReversedList(void);

		//void writeToFile(void);                          // FILE I/O OPERATIONS
		//void readFromFile(void);

		void insertAtStart(Generic input)     // Function to insert nodes to the left of the list [ O(1) ]
		{
			nodeCount++;
			if (head == NULL)
			{
				Node* temp = new Node(input);
				head = temp;
				tail = temp;
				tail->next = NULL;
				head->previous = NULL;
				cout << "\n Node created with data: " << temp->nodeData;
			}
			else
			{
				Node* temp = new Node(input);
				temp->next = head;
				head->previous = temp;
				head = temp;
				tail->next = NULL;
				head->previous = NULL;
				cout << "\n Node created with data: " << temp->nodeData << " ";
			}
		}

		void insertAtEnd(Generic input)  // Function to insert nodes to the right of the list [ O(1) ]
		{
			nodeCount++;
			if (head == NULL)
			{
				Node* temp = new Node(input);
				head = temp;
				tail = temp;
				tail->next = NULL;
				tail->previous = NULL;
				head->previous = NULL;
				head->next = NULL;
				cout << "\n Node created with data: " << temp->nodeData << " ";
			}
			else
			{
				Node* temp = new Node(input);
				tail->next = temp;
				temp->previous = tail;
				tail = temp;
				tail->next = NULL;
				cout << "\n Node created with data: " << temp->nodeData << " ";
			}
		}

		void insertAtLocation(Generic input, int location)   // Function to insert node at a specific location in the list [ O(n) ]
		{
			if (head == NULL)
			{
				cout << "\n No linked list created. Please create a linked list first.\n";
				_getch();
				insertionMenu();
			}

			else if (location > nodeCount)
			{
				cout << "\n Invalid location. Current linked list has only " << nodeCount << " node(s). ";
				Sleep(2000);
				insertionMenu();
			}

			nodeCount++;
			int i;
			Node* ptr = NULL;
			for (i = 1, ptr = head; i < location - 1 && i <= nodeCount; ptr = ptr->next, ++i)
			{
			}
			Node* temp = new Node(input);
			temp->next = ptr->next;
			temp->previous = ptr;
			ptr->next = temp;
			cout << "\n New node with data " << temp->nodeData << " created at location " << location << " ";
		}

		void continuousInputMode()
		{
			system("cls");
			Generic var;
			int size = 0;
			cout << "\n -------------------------------- CONTINUOUS INPUT M0DE --------------------------------\n";
			cout << "\n\n Keep entering successive node's data continuosly."
				<< "\n Use <spacebar> or <enter> to identify separate nodes data."
				<< "\n\n CIM requires the size of the list to operate: ";
			cin >> size;
			cout << "\n Begin entering data: ";
			for (int i = 0; i < size; ++i)
			{
				cout << "\n";
				cin >> var;
				insertAtEnd(var);
			}
			if (head != NULL && tail != NULL)
			{
				cout << "\n All " << size << " data items added successfully to linked list. ";
				Sleep(2500);
			}
			else
			{
				cout << "\n !!! SOME ERROR OCCURRED WHILE STORING DATA !!";
				Sleep(2000);
			}
			insertionMenu();
		}

		void deleteFirstNode()  // Function to delete first node of the list [ O(1) ]
		{
			if (head == NULL)
			{
				cout << "\n No linked list in memory. Please make one first. ";
				Sleep(2000);
				commenceOperation();
			}
			else
			{
				Node* temp = head;
				head = head->next;
				head->previous = NULL;
				cout << "\n First node with data " << temp->nodeData << " deleted successfully. ";
				delete temp;
			}
		}

		void deleteLastNode()  // Function to delete last node of the list [ O(1) ]
		{
			if (head == NULL)
			{
				cout << "\n No linked list in memory. Please make one first. ";
				Sleep(2000);
				commenceOperation();
			}
			else
			{
				//node* ptr;                 // Singly-linked implementation [ O(n) ]
				//for (ptr = head; ptr->next != tail; ptr = ptr->next) {}
				//ptr->next = null;       
				//cout << "\n last node with data " << tail->nodedata << " deleted successfully. ";
				//delete tail;
				//tail = ptr;

				Node* ptr = tail;            // Doubly-Linked implementation [ O(1) ]
				tail = tail->previous;
				tail->next = NULL;
				cout << "\n Last node with data " << ptr->nodeData << " deleted successfully. ";
				delete ptr;
			}
		}

		void deleteSpecificNode(int location)  // Function to delete a specific node of the list [ O(n) ]
		{
			if (head == NULL)
			{
				cout << "\n No linked list in memory. Please make one first. ";
				Sleep(2000);
				commenceOperation();
			}
			else
			{
				if (location > nodeCount)
				{
					cout << "\n Invalid location. Current linked list has only " << nodeCount << " node(s). ";
					Sleep(2000);
					deletionMenu();
				}
				/*Node* ptr;         // SINGLY-LINKED IMPLEMENTATION
				int i;
				for (ptr = head, i = 1; ptr->next != NULL && i < location - 1; ptr = ptr->next, ++i) {}
				Node* toBeDeleted = ptr->next;
				ptr->next = ptr->next->next;
				ptr->next->previous = ptr;
				cout << "\n Node " << location << " with data '" << toBeDeleted->nodeData << "' deleted successfully. ";
				delete toBeDeleted;*/

				Node* ptr;            //DOUBLY-LINKED IMPLEMENTATION    
				int i;
				for (ptr = head, i = 1; ptr->next != NULL && i < location ; ptr = ptr->next, ++i) {}
				ptr->previous->next = ptr->next;
				ptr->next->previous = ptr->previous;
				cout << "\n Node " << location << " with data '" << ptr->nodeData << "' deleted successfully. ";
				delete ptr;
			}
		}

		void deleteSpecificValue(Generic input)  // Function to delete a node containing specific data of the list [ O(n) ]
		{
			if (head == NULL)
			{
				cout << "\n No linked list in memory. Please make one first. ";
				Sleep(2000);
				commenceOperation();
			}
			else
			{
				Node* ptr = head;
				while (ptr != NULL && ptr->nodeData != input)
				{
					ptr = ptr->next;
				}
				if (ptr->next == NULL && ptr->nodeData!=input)
				{
					cout << "\n Data " << input << " not found in the list. ";
					Sleep(2000);
					deletionMenu();
				}
				else
				{
					if (ptr->next == NULL)
					{
						deleteLastNode();
						cout << "\n Node with data '" << input << "' deleted successfully. ";
						Sleep(2000);
						commenceOperation();
					}
					ptr->previous->next = ptr->next;  // DOUBLY-LINKED IMPLEMENTATION
					ptr->next->previous = ptr->previous;
					cout << "\n Node with data '" << ptr->nodeData << "' deleted successfully. ";
					delete ptr;
				}
				/*Node* ptr = head;
				while (ptr->next != NULL && ptr->next->nodeData != input)
				{
					ptr = ptr->next;
				}
				if (ptr->next == NULL)
				{
					cout << "\n Data " << input << " not found in the list. ";
					Sleep(2000);
					deletionMenu();
				}

				else
				{
					Node* toBeDeleted = ptr->next;
					ptr->next = ptr->next->next;
					cout << "\n Node with data '" << toBeDeleted->nodeData << "' deleted successfully. ";
					delete toBeDeleted;
				}*/
				/*for (ptr = head, i = 1; ((ptr->next != NULL && ptr->next->nodeData !=input) && i <= nodeCount); ++i) {}

				cout << "\n Node " << i << " with data '" << toBeDeleted->nodeData << "' deleted successfully. ";
				 */
			}
		}

		void deleteList()
		{
			cout << "\n This action is IRREVERSIBLE. Proceed (y/n)?";
			char c = _getch();
			if (c == 'n' || c == 'N')
				commenceOperation();
			else if (c != 'y' && c != 'Y')
			{
				cout << "\n Invalid input. ";
				Sleep(700);
				commenceOperation();
			}
			Node* temp = head;
			while (temp != NULL)
			{
				Node* first = temp;
				temp = temp->next;
				head = temp;
				delete first;
			}
			cout << "\n Deleting nodes";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".";
			cout << "\n Cleaning up memory";
			Sleep(500);
			cout << ".";
			Sleep(600);
			cout << ".";
			Sleep(800);
			cout << ".";
			cout << "\n\n Linked list successfully deleted from existence.\n";
		}



		void searchByIndex(int location)  // Function to display data in a specified node of the list [ O(n) ]
		{
			if (head == NULL)
			{
				cout << "\n No linked list in memory. Please make one first. ";
				Sleep(2800);
				commenceOperation();
			}
			else
			{
				if (location > nodeCount)
				{
					cout << "\n Invalid index. Current linked list has only " << nodeCount << " node(s). ";
					Sleep(2000);
					searchMenu();
				}
				Node* ptr;
				int i;
				for (ptr = head, i = 1; ptr->next != NULL && i < location; ++i)
				{
					ptr = ptr->next;
				}
				cout << "\n Data at Node '" << location << "' : '" << ptr->nodeData << "' ";
			}
		}

		void searchByValue(Generic data)
		{
			if (head == NULL)
			{
				cout << "\n No linked list in memory. Please make one first. ";
				Sleep(2800);
				commenceOperation();
			}
			else
			{
				bool found = false;
				Node* ptr;
				int i, foundCount = 0;
				for (ptr = head, i = 1; ptr != NULL && i <= nodeCount; ++i, ptr = ptr->next)
				{
					if (ptr->nodeData == data)
					{
						found = true;
						foundCount++;
						Sleep(200);
						cout << "\n '" << data << "' found at index '" << i << "'.";
						Sleep(200);
						cout << "\n\n Continuing search to look for duplicates..";
						Sleep(600);
						if (ptr->next == NULL)
							break;
					}
				}
				if (!ptr == NULL)
				{
					if (ptr->next == NULL && found == false)
						cout << "\n No search results for '" << data << "' ";
					/*else
					{
						cout << "\n\n Found " << foundCount << " matches to '" << data << "'.";
						_getch();
						searchMenu();
					} */
				}
				else
				{
					cout << "\n\n Found " << foundCount << " matches to '" << data << "'.";
					_getch();
					searchMenu();
				}


			}
		}

		void commenceOperation()
		{
			// Operation Mode
			std::string operatingType;
			switch (operationMode)
			{
			case '1':
				operatingType = "<INT>";
				break;
			case '2':
				operatingType = "<FLOAT>";
				break;
			case '3':
				operatingType = "<CHAR>";
				break;
			case '4':
				operatingType = "<STRING>";
				break;
			case '5':
				operatingType = "<BOOL>";
				break;
			}

			system("cls");
			system("color 0b");
			cout << "\n ############### DYNAMIC TEMPLATIZED LINKED-LIST IMPLEMENTATION IN C++ ###############\n\n"
				<< "                                     ~ Version 3.1 ~\n"
				<< "                                          @sqazi \n\n"
				<< "                          CURRENT MODE OF OPERATION :: " << operatingType << "\n";
			cout << "\n Press 1-9 to choose option:\n\n"
				<< "\t\t 1 - Insertion operations\n"
				<< "\t\t 2 - Deletion operations\n"
				<< "\t\t 3 - Search operations\n"
				<< "\t\t 4 - Delete current linked list\n"
				<< "\t\t 5 - Display current linked list\n"
				<< "\t\t 6 - Display (reversed) current linked list\n"
				<< "\t\t 7 - Change selected Data Structure type\n"
				<< "\t\t 8 - Write current linked list to a file\n"
				<< "\t\t 9 - Load a linked list from a file\n"
				<< "\t\t x - Exit\n ";
			char c = _getch();
			switch (c)
			{
			case '1':
				insertionMenu();
				commenceOperation();
				break;

			case '2':
				deletionMenu();
				commenceOperation();
				break;

			case '3':
				searchMenu();
				commenceOperation();
				break;

			case '4':
				if (head == NULL)
				{
					cout << "\n No list already in memory.\n";
					_getch();
					commenceOperation();
				}
				else
				{
					deleteList();
					Sleep(2000);
					commenceOperation();
				}
				break;

			case '5':
				printList();
				_getch();
				commenceOperation();

			case '6':
				printReversedList();
				_getch();
				commenceOperation();

			case '7':
				launchTemplatizedLinkedList();
				break;

			case '8':
				writeToFile();
				Sleep(2000);
				commenceOperation();

			case '9':
				readFromFile();
				Sleep(2000);
				commenceOperation();
				break;

			case ('x'||'X'):
				exit(0);

			default:
				cout << "\n Press 1-9 only. <Press any Key> ";
				_getch();
				commenceOperation();
			}
		}

		void insertionMenu()
		{
			system("cls");
			cout << "\n ------------------------------- INSERTION OPTIONS -------------------------------";
			cout << "\n\n Press 1-5 to select option:\n\n"
				<< "\t\t 1 > Insert a node at the beginning of the Linked List\n"
				<< "\t\t 2 > Insert a node at the end of the Linked List\n"
				<< "\t\t 3 > Insert a node at a location in the Linked List\n"
				<< "\t\t 4 > Continuous Data Input Mode\n"
				<< "\t\t 5 > Back to Main Menu\n";
			char c = _getch();
			Generic var;
			switch (c)
			{
			case '1':
				cout << "\n Enter data to store at the beginning of the linked list: ";
				cin >> var;
				insertAtStart(var);
				Sleep(2000);
				commenceOperation();
				break;

			case '2':
				cout << "\n Enter data to append to the end of the linked list: ";
				cin >> var;
				insertAtEnd(var);
				Sleep(2000);
				commenceOperation();
				break;

			case '3':
				cout << "\n Enter location where you want to insert a new node: ";
				int loc;
				cin >> loc;
				cin.clear();
				cout << "\n Enter data to store in the new node at location " << loc << " :";
				cin >> var;
				insertAtLocation(var, loc);
				Sleep(2000);
				commenceOperation();
				break;

			case '4':
				continuousInputMode();
				break;

			case '5':
				commenceOperation();
				break;

			default:
				cout << "\n Press 1-3 only. <Press any Key> ";

				_getch();
				insertionMenu();
				break;
			}
		}

		void deletionMenu()
		{
			system("cls");
			cout << "\n ------------------------------- DELETION OPTIONS -------------------------------";
			cout << "\n\n Press 1-4 to select option:\n\n"
				<< "\t\t 1 > Delete the first node of the Linked List\n"
				<< "\t\t 2 > Delete the last node of the Linked List\n"
				<< "\t\t 3 > Delete a node at a specific location in the Linked List\n"
				<< "\t\t 4 > Delete a node with a specific value in the Linked List\n"
				<< "\t\t 5 > Back to Main Menu\n";
			char c = _getch();
			Generic var;
			switch (c)
			{
			case '1':
				deleteFirstNode();
				nodeCount--;
				Sleep(2000);
				commenceOperation();
				break;

			case '2':
				deleteLastNode();
				nodeCount--;
				Sleep(2000);
				commenceOperation();
				break;

			case '3':
				cout << "\n Enter location where you want to delete a node: ";
				int loc;
				cin >> loc;
				cin.clear();
				deleteSpecificNode(loc);
				nodeCount--;
				Sleep(2000);
				commenceOperation();
				break;

			case '4':
				cout << "\n Enter the node data you want to delete: ";
				cin >> var;
				cin.clear();
				deleteSpecificValue(var);
				nodeCount--;
				Sleep(2000);
				commenceOperation();
				break;

			case '5':
				commenceOperation();

			default:
				cout << "\n Press 1-3 only. <Press any Key> ";
				_getch();
				insertionMenu();
				break;
			}
		}

		void searchMenu()
		{
			system("cls");
			cout << "\n ------------------------------- SEARCH OPTIONS -------------------------------";
			cout << "\n\n Press 1-3 to select option:\n\n"
				<< "\t\t 1 > Search data by index in the Linked List\n"
				<< "\t\t 2 > Search data by value the Linked List\n"
				<< "\t\t 3 > Back to Main Menu\n";
			char c = _getch();
			Generic var;
			switch (c)
			{
			case '1':
				int index;
				cout << "\n Enter (integer) index to check value at it: ";
				cin >> index;
				searchByIndex(index);
				Sleep(4000);
				commenceOperation();
				break;

			case '2':
				cout << "\n Enter data to search in the linked list: ";
				cin >> var;
				searchByValue(var);
				Sleep(4000);
				commenceOperation();
				break;

			case '3':
				commenceOperation();

			default:
				cout << "\n Press 1-3 only. <Press any Key> ";
				_getch();
				searchMenu();
				break;
			}
		}

		void printList()
		{
			std::cout << "\n\n -------------------------------- CURRENT LINKED LIST --------------------------------\n\n\t";
			for (Node* iter = head; iter != NULL; iter = iter->next)
			cout << " " << iter->nodeData;
			std::cout << "\n\n -------------------------------------------------------------------------------------\n";
		}

		void printReversedList()
		{
			std::cout << "\n\n -------------------------------- REVERSED LINKED LIST --------------------------------\n\n\t";

			for (Node* iter = tail; iter != NULL; iter = iter->previous)
				cout << " " << iter->nodeData;
			std::cout << "\n\n -------------------------------------------------------------------------------------\n";
		}

		void writeToFile()
		{
			if (head == NULL)
			{
				cout << "\n No list already in memory.\n";
				_getch();
				commenceOperation();
			}
			cout << "\n Enter name of the file to save: ";
			std::string fileName;
			cin >> fileName;
			fileName.append(".txt");
			std::ofstream outFile(fileName);

			for (Node* temp = head; temp != NULL; temp = temp->next)
				outFile << temp->nodeData << "\n";

			cout << "\n Current linked-list written to file " << fileName << " ";
		}

		void readFromFile()
		{
			cout << "\n Enter name of the file to load: ";
			std::string fileName;
			cin >> fileName;
			fileName.append(".txt");
			std::ifstream inFile(fileName);
			if (!inFile)
			{
				cout << "\n File Not found. \n";
				Sleep(1000);
				commenceOperation();
			}
			Generic data;
			while (inFile >> data)
			{
				Sleep(150);
				cout << "\n Reading data.. " << data;
				insertAtEnd(data);
			}

			if (head == NULL)
			{
				cout << "\n An error occured while loading file " << fileName << " :"
					<< "\n File's contents do not match Mode of Operation. ";
				Sleep(4900);
				commenceOperation();
			}
			cout << "\n Linked-list succssfully loaded from " << fileName << " ";
		}
	};
};