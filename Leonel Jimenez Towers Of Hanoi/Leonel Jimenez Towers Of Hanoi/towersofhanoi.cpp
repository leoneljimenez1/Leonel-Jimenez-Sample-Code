#include <iostream>
#include <iomanip>
#include "linkedlist.h"
#include "adstack.h"
#include "linkedstack.h"

using std::cout;
using std::endl;
using std::boolalpha;

using namespace std;


void storeVariable(LinkedStack <int>& stack, int count)
{
	for (int i = count; i > 0; i--)
	{
		stack.push(i);
	}
}

void makeLegalMove(LinkedStack <int>& stack1, LinkedStack <int>& stack2)
{

	if (stack1.getSize() == 0)
	{
		int top = stack2.peek();
		stack1.push(top);
		stack2.pop();
	}

	else if (stack2.getSize() == 0)
	{
		int top = stack1.peek();
		stack2.push(top);
		stack1.pop();
	}

	else
	{
		if (stack1.peek() > stack2.peek())
		{
			int top = stack2.peek();
			stack1.push(top);
			stack2.pop();
		}
		else
		{
			int top = stack1.peek();
			stack2.push(top);
			stack1.pop();
		}
	}
}
void solvingTower(LinkedStack <int>& stack1, LinkedStack <int>& stack2, LinkedStack <int>& stack3)
{
	int amountOfDisksStack1 = stack1.getSize();
	int oddOrEven = amountOfDisksStack1 % 2;
	int amountofDisksStack2 = stack2.getSize();

	if (oddOrEven == 0) // even
	{
		while (true)
		{
			makeLegalMove(stack1, stack2);

			//printing out each move
			cout << stack1.toString() << endl;
			cout << stack2.toString() << endl;
			cout << stack3.toString() << endl;
			cout << "-------------------------" << endl;

			makeLegalMove(stack1, stack3);

			if (amountOfDisksStack1 == stack3.getSize())
			{
				break;
			}
			//printing out each move
			cout << stack1.toString() << endl;
			cout << stack2.toString() << endl;
			cout << stack3.toString() << endl;
			cout << "-------------------------" << endl;

			makeLegalMove(stack2, stack3);


			//printing out each move
			cout << stack1.toString() << endl;
			cout << stack2.toString() << endl;
			cout << stack3.toString() << endl;
			cout << "-------------------------" << endl;

			if (amountOfDisksStack1 == stack3.getSize())
			{
				break;
			}


		}


	}

	else if (oddOrEven == 1) // odd
	{
		while (true)
		{

			makeLegalMove(stack1, stack3);

			//printing out each move
			cout << stack1.toString() << endl;
			cout << stack2.toString() << endl;
			cout << stack3.toString() << endl;
			cout << "-------------------------" << endl;

			if (amountOfDisksStack1 == stack3.getSize())
			{
				break;
			}


			makeLegalMove(stack1, stack2);

			//printing out each move
			cout << stack1.toString() << endl;
			cout << stack2.toString() << endl;
			cout << stack3.toString() << endl;
			cout << "-------------------------" << endl;

			makeLegalMove(stack2, stack3);

			//printing out each move
			cout << stack1.toString() << endl;
			cout << stack2.toString() << endl;
			cout << stack3.toString() << endl;
			cout << "-------------------------" << endl;

			if (amountOfDisksStack1 == stack3.getSize())
			{
				break;
			}


		}


	}


}

int main(int argc, char* argv[])
{
	cout << "How many disks would you like to start with: ";

	int initialAmountOfDisks = 0;
	cin >> initialAmountOfDisks;

	LinkedStack <int >stackA;
	LinkedStack <int >stackB;
	LinkedStack <int >stackC;

	cout << "Initial Placement" << endl;

	storeVariable(stackA, initialAmountOfDisks); //Populating the first stack "Stack A"
	cout << stackA.toString() << endl;
	cout << stackB.toString() << endl;
	cout << stackC.toString() << endl;
	cout << "-------------------------" << endl;

	//makeLegalMove(stackA, stackB);

	solvingTower(stackA, stackB, stackC); // begins the process of solving the tower

	return 0;
}
