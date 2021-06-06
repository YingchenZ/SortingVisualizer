#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <time.h>
#include <vector>
#include <string>

class HeapSort {
private:
	std::vector<int> arr = {};
	time_t begin = 0;
	long long exchange = 0;
	int LOAD;
public:

	HeapSort(std::vector<int> vec, int load) {
		arr = vec;
		LOAD = load;
	}

	void visualize(std::vector<int> arr, std::string type) {
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0f, 1.0f, 1.0f);
		std::string title = "Algorithm: " + type;
		std::string status = "Load = " + std::to_string(LOAD) + "    Swap = " + std::to_string(exchange) + "    Time = " + std::to_string((clock() - begin) / 1000.0) + "s";
		glRasterPos2i(0, 850);
		for (char c : title) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}
		glRasterPos2i(0, 830);
		for (char c : status) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
		}

		// White
		glColor3f(1.0f, 1.0f, 1.0f);
		for (int i = 0; i < LOAD; i++) {
			glRecti(i, 0, i + 1, arr[i]);
		}
		glFlush();
		Sleep(1);
	}

	void heapify(int lastPosition, int unsortedSize) {
		int parent = lastPosition;
		int leftChild = 2 * lastPosition + 1;
		int rightChild = 2 * lastPosition + 2;

		if (rightChild < unsortedSize && arr[parent] < arr[rightChild]) {
			parent = rightChild;
		}
		if (leftChild < unsortedSize && arr[parent] < arr[leftChild]) {
			parent = leftChild;
		}

		if (parent != lastPosition) {
			int temp = arr[lastPosition];
			arr[lastPosition] = arr[parent];
			arr[parent] = temp;
			++exchange;
			visualize(arr, "Heap Sort");
			heapify(parent, unsortedSize);
		}

	}

	void sort() {
		begin = clock();
		// make a heap
		for (int i = arr.size() / 2 - 1; i >= 0; i--) {
			heapify(i, arr.size() - 1);
		}

		for (int i = arr.size() - 1; i > 0; i--) {
			int temp = arr[i];
			arr[i] = arr[0];
			arr[0] = temp;
			++exchange;
			visualize(arr, "Heap Sort");
			heapify(0, i);

		}

	}
};

