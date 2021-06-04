#include <iostream>
#include "BubbleSort.cpp";
#include "InsertionSort.cpp";
#include "SelectionSort.cpp";
#include "MergeSort.cpp";
#include "HeapSort.cpp";
#include "BinaryInsertion.cpp"
#define LOAD 1500
#define WIDTH 1350
#define HEIGHT 864

int window;
void another();
std::vector<int> generateArray() {
	srand((unsigned)time(0));
	std::vector<int> arr = {};
	for (int i = 0; i < LOAD; i++) {
		arr.push_back(rand() % (HEIGHT - 100));
	}
	return arr;
}


void render(){
	std::vector<int> newArray = generateArray();
	// =================== Bubble Sort ===================
	/*
	
	BubbleSort* bubble = new BubbleSort(newArray, LOAD);
	bubble->sort();
	Sleep(1000);
	
	InsertionSort* insertion = new InsertionSort(newArray, LOAD);
	insertion->sort();
	Sleep(1000);
	
	BinaryInsertionSort* binaryinsertion = new BinaryInsertionSort(newArray, LOAD);
	binaryinsertion->sort();
	Sleep(1000);

	SelectionSort* selection = new SelectionSort(newArray, LOAD);
	selection->sort();
	Sleep(1000);
	*/

	// ============= Not Done =============


	MergeSort* merge = new MergeSort(newArray, LOAD);
	merge->sort();
	Sleep(1000);
	
	// ============== The algorithm itself still buggy ==============
	HeapSort* heap = new HeapSort(newArray, LOAD);
	heap->sort();
	std::cout << "Done" << std::endl;
	Sleep(2000);
	
	//glutDestroyWindow(window);
	//another();
	glutLeaveMainLoop();
}


void start(int argc, char* argv[]) {
	// Initialize GLUT
	glutInit(&argc, argv);
	// Set up some memory buffers for our display

	// Set the window size
	glutInitWindowSize(WIDTH, HEIGHT);

	// Create the window with the title "Hello,GL"
	window = glutCreateWindow("Sorting Visualization");
	// Bind the two functions (above) to respond when necessary

	glutDisplayFunc(render);
	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	gluOrtho2D(0, 1536, 0, 864);

	
	glutMainLoop();
	
}
void another() {
	int choice = 0;
	std::cout << "Enter your choice: ";
	std::cin >> choice;
	if (choice == 1)
		std::cout << "Destroy Windows done from another" << std::endl;
	else {
		std::cout << "not choosing a" << std::endl;
	}
}



int main(int argc, char* argv[]) {
	start(argc, argv);

	return 0;
}