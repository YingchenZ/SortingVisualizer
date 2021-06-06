#include <iostream>
#include "BubbleSort.cpp";
#include "InsertionSort.cpp";
#include "SelectionSort.cpp";
#include "MergeSort.cpp";
#include "HeapSort.cpp";
#include "BinaryInsertion.cpp"
#include "QuickSort.cpp";

#define LOAD 1500
#define WIDTH 1350
#define HEIGHT 864

int window;

std::vector<int> generateArray(int load) {
	srand((unsigned)time(0));
	std::vector<int> arr = {};
	for (int i = 0; i < load; i++) {
		arr.push_back(rand() % (HEIGHT - 100));
	}
	return arr;
}

void renderBubble() {
	std::vector<int> newArray = generateArray(600);

	BubbleSort* bubble = new BubbleSort(newArray, 600);
	bubble->sort();
	Sleep(1000);
	glutDestroyWindow(window);
}

void renderInsertion() {
	std::vector<int> newArray = generateArray(600);

	InsertionSort* insertion = new InsertionSort(newArray, 600);
	insertion->sort();
	Sleep(1000);
	glutDestroyWindow(window);
}


void renderBinaryInsertion() {
	std::vector<int> newArray = generateArray(LOAD);

	BinaryInsertionSort* binaryinsertion = new BinaryInsertionSort(newArray, LOAD);
	binaryinsertion->sort();
	Sleep(1000);
	glutDestroyWindow(window);
}

void renderSelection() {
	std::vector<int> newArray = generateArray(LOAD);

	SelectionSort* selection = new SelectionSort(newArray, LOAD);
	selection->sort();
	Sleep(1000);
	glutDestroyWindow(window);
}

void renderQuick() {
	std::vector<int> newArray = generateArray(LOAD);

	QuickSort* quick = new QuickSort(newArray, LOAD);
	quick->sort();
	Sleep(1000);
	glutDestroyWindow(window);
}

void renderMerge() {
	std::vector<int> newArray = generateArray(LOAD);

	MergeSort* merge = new MergeSort(newArray, LOAD);
	merge->sort();
	Sleep(1000);
	glutDestroyWindow(window);
}

void renderHeap() {
	std::vector<int> newArray = generateArray(LOAD);

	HeapSort* heap = new HeapSort(newArray, LOAD);
	heap->sort();
	Sleep(1000);
	glutDestroyWindow(window);
}

void createWindow(int option) {

	// Set the window size
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 1200) / 2,
		(glutGet(GLUT_SCREEN_HEIGHT) - 1000) / 2);
	// Create the window with the title "Hello,GL"
	window = glutCreateWindow("Sorting Visualization");
	// Set up some memory buffers for our display
	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	gluOrtho2D(0, 1536, 0, 864);

	// Bind the two functions (above) to respond when necessary
	if (option == 1) {
		glutDisplayFunc(renderBubble);
	}
	else if (option == 2) {
		glutDisplayFunc(renderInsertion);
	}
	else if (option == 3) {
		glutDisplayFunc(renderBinaryInsertion);
	}
	else if (option == 4) {
		glutDisplayFunc(renderSelection);
	}
	else if (option == 5) {
		glutDisplayFunc(renderQuick);
	}
	else if (option == 6) {
		glutDisplayFunc(renderMerge);
	}
	else if (option == 7) {
		glutDisplayFunc(renderHeap);
	}
	else {
		return;
	}
}

void menu() {
	std::cout << "0.\tQuit" << std::endl;
	std::cout << "1.\tBubble Sort" << std::endl;
	std::cout << "2.\tInsertion Sort" << std::endl;
	std::cout << "3.\tBinary Insertion Sort" << std::endl;
	std::cout << "4.\tSelection Sort" << std::endl;
	std::cout << "5.\tQuick Sort" << std::endl;
	std::cout << "6.\tMerge Sort" << std::endl;
	std::cout << "7.\tHeap Sort" << std::endl;
}

void start(int argc, char* argv[]) {
	// Initialize GLUT
	glutInit(&argc, argv);

	int choice = 0;
	std::cout << "\t\tSorting Visualizer" << std::endl;
	menu();
	std::cout << "Pick an algorithm, 0 to quit: ";
	std::cin >> choice;
	while (choice != 0) {
		createWindow(choice);
		glutMainLoopEvent();
		menu();
		std::cout << "Pick an algorithm, 0 to quit: ";
		std::cin >> choice;
	}
	std::cout << "Bye Bye" << std::endl;
}



int main(int argc, char* argv[]) {
	start(argc, argv);
	return 0;
}