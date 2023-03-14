#include "functions/figures3d.h"
#include <conio.h>
#include <iostream>

using namespace std;

int get_key() {
	int key = _getch();
	if ((key == 0) || (key == 224)) key = _getch();
	return key;
}

int menu1(Space space) {
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

void exit() {
	while (true) {
		int key = get_key();
		if (key == 27) break;
	}
}

bool check_size(Space& space) {
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
			FigureType type;
			int index_type;
			while (true) {
				cout << "List of figures:\nBALL - 0\nCYLINDER - 1\nPARALLELEPIPED - 2\n-----------\nWrite type of figure: ";
				cin >> index_type;
				switch (index_type) {
				case 0:
					type = BALL;
					break;
				case 1:
					type = CYLINDER;
					break;
				case 2:
					type = PARALLELEPIPED;
					break;
				default:
					system("cls");
					cout << "Invalid type!\n  Try again\n*------------*\n";
					continue;
				}
				break;
			}
			system("cls");
			double radius = 0;
			double height = 0;
			double lenght = 0;
			switch (type) {
			case BALL:

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
				break;
			case CYLINDER:
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
				break;
			case PARALLELEPIPED:
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
				break;
			}
			Figure3D figure(type, radius, height, lenght);
			space.add_figure(figure, index);
		}

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
			space.delete_figure(index);
			system("cls");
			cout << "Figure deleted!" << endl << "Exit: Esc";
			exit();
		}

		if (key == 13) {
			system("cls");
			if (check_size(space)) continue;
			cout << "Exit: Esc\n\n";
			cout << space;
			exit();
		}

		if(key == 32){
			system("cls");
			if (check_size(space)) continue;
			cout << "Figure with max volume:" << endl;
			cout << space.get_figure_with_max_volume();
			cout << "\tVolume: " << space.get_figure_with_max_volume().get_volume_figure() << endl;
			cout << "\nExit: Esc";
			exit();
		}

		if (key == 27) { break; }
	}

	return 0;
}