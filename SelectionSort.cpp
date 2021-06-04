#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <time.h>
#include <vector>
#include <string>

class SelectionSort {
private:
	std::vector<int> arr = {};
	time_t begin = 0;
	long long exchange = 0;
	int LOAD;
public:
	SelectionSort(std::vector<int> vec, int load) {
		arr = vec;
		LOAD = load;
	}

	void visualize(std::vector<int> arr, std::string type) {
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0f, 1.0f, 1.0f);
		std::string status = "Algorithm: " + type + "\tSwap = " + std::to_string(exchange) + "\tTime = " + std::to_string((clock() - begin) / 1000.0) + "s";
		glRasterPos2i(0, 850);
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

	void sort() {
		begin = clock();
		for (int lastSorted = 0; lastSorted < arr.size(); lastSorted++) {
			int smallest = lastSorted;
			for (int j = lastSorted; j < arr.size(); j++) {
				if (arr[j] < arr[smallest]) {
					smallest = j;
				}
			}
			int temp = arr[smallest];
			arr[smallest] = arr[lastSorted];
			arr[lastSorted] = temp;
			visualize(arr, "Selection Sort");
		}
	}
};

