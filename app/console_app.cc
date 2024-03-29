#include "functions/figures3d.h"  // dynamic library
#include <conio.h> // _getch()

using namespace std;

int get_key() {
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
}

// Menu of programm 
int menu1(const Space& space) {
	system("cls");
	cout << "Number of figures in space: " << space.get_size() << endl << endl;
	cout << "Add a figure by the index: Ins" << endl;
	cout << "Delete a figure by the index: Del" << endl;
	cout << "Write list of figures: Enter" << endl;
	cout << "Find the figure with the maximum volume: Space" << endl;
	cout << "\nExit: Esc" << endl;
	while (true) {
		int key = get_key();
		//Del			//Ins			//Space			//Esc			//Enter		   
		if ((key == 83) || (key == 82) || (key == 32) || (key == 27) || (key == 13)) return key;
	}

}

// Function of Exit
void exit() {
	while (true) {
		int key = get_key();
		if (key == 27) break;
	}
}

// Function Check number of figures in space
bool check_size(const Space& space) {
	if (space.get_size() == 0) {
		cout << "We don't have figures!" << endl;
		cout << "\nExit: Esc";
		exit();
		return true;
	}
	return false;
}

int main() {
	Space space;
	while (true) {
		int key = menu1(space);

		// Ins - Add the figure in space
		if (key == 82) {
			system("cls");
			int index;
			while (true) {
				cout << "Range of index: 0 - " << space.get_size() << endl;
				cout << "Write index: ";
				cin >> index;
				if (index >= 0 && index <= space.get_size()) break;
				system("cls");
				cout << "Invalid index!\n  Try again\n*------------*\n";
			}
			system("cls");
			int index_type;
			while (true) {
				cout << "List of figures:\nBALL - 1\nCYLINDER - 2\nPARALLELEPIPED - 3\n-----------\nWrite type of figure: ";
				cin >> index_type;
				if (index_type != 1 && index_type != 2 && index_type != 3){
					system("cls");
					cout << "Invalid type!\n  Try again\n*------------*\n";
					continue;
				}
				break;
			}
			system("cls");
			FigurePtr fig = nullptr;
			double radius = 0;
			double height = 0;
			double lenght = 0;
			switch (index_type) {
			case 1:

				while (true) {
					cout << "Write radius: ";
					cin >> radius;
					if (radius > 0) break;
					else
					{
						system("cls");
						cout << "Invalid radius!\n  Try again\n*------------*\n";
						continue;
					}
				}
				fig = make_shared<Ball>(radius);
				break;
			case 2:
				while (true)
				{
					cout << "Write radius: ";
					cin >> radius;
					if (radius > 0) break;
					else
					{
						system("cls");
						cout << "Invalid radius!\n  Try again\n*------------*\n";
						continue;
					}
				}
				while (true)
				{
					cout << "Write height: ";
					cin >> height;
					if (height > 0) break;
					else
					{
						system("cls");
						cout << "Invalid height!\n  Try again\n*------------*\n";
						continue;
					}
				}
				fig = make_shared<Cylinder>(radius, height);
				break;
			case 3:
				while (true)
				{
					cout << "Write first line: ";
					cin >> radius;
					if (radius > 0) break;
					else
					{
						system("cls");
						cout << "Invalid first line!\n  Try again\n*------------*\n";
						continue;
					}
				}
				while (true)
				{
					cout << "Write second line: ";
					cin >> height;
					if (height > 0) break;
					else
					{
						system("cls");
						cout << "Invalid second line!\n  Try again\n*------------*\n";
						continue;
					}
				}
				while (true)
				{
					cout << "Write third line: ";
					cin >> lenght;
					if (lenght > 0) break;
					else
					{
						system("cls");
						cout << "Invalid third line!\n  Try again\n*------------*\n";
						continue;
					}
				}
				fig = make_shared<Parallelepiped>(radius, height, lenght);
				break;
			default:
				fig = make_shared<Ball>(0);
			}
			space.add_figure(fig, index); // Add the figure in space
		}

		// Del - Delete figure in space
		if (key == 83) {
			system("cls");
			if (check_size(space)) continue;
			int index;
			while (true) {
				cout << "Range of index: 0 - " << space.get_size() - 1 << endl;
				cout << "Write index: ";
				cin >> index;
				if (index >= 0 && index <= space.get_size() - 1) break;
				system("cls");
				cout << "Invalid index!\n  Try again\n*------------*\n";
			}
			space.delete_figure(index); // Delete the figure in space
			system("cls");
			cout << "Figure deleted!" << endl << "Exit: Esc";
			exit();
		}

		// Enter - List of Figure in space
		if (key == 13) {
			system("cls");
			if (check_size(space)) continue;
			cout << "Exit: Esc\n\n";
			for (int i = 0; i < space.get_size(); ++i) {
				space.print_figures(i);
				cout << endl;
			}
			exit();
		}

		// Space - Figure with max volume 
		if(key == 32){
			system("cls");
			if (check_size(space)) continue;
			int index = space.get_figure_with_max_volume();
			cout << "Figure with max volume:" << endl << endl;
			space[index]->print(cout);
			cout << "\tVolume: " << space[index]->get_volume_figure() << endl;
			cout << "\nExit: Esc";
			exit();
		}

		// Escape - Exit
		if (key == 27) { break; }
	}
	return 0;
}