#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <vector>
#include <time.h>
#include <string>

class BubbleSort {
private:
	std::vector<int> arr = {};
	time_t begin = 0;
	long long exchange;
	int LOAD;
public:
	
	BubbleSort(std::vector<int> vec, int load) {
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
		for (int i = 0; i < arr.size(); i++) {
			for (int j = 1; j < arr.size() - i; j++) {
				if (arr[j] < arr[j - 1]) {
					int temp = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = temp;
					++exchange;
					visualize(arr, "Bubble Sort");
				}
			}
		}
	}
};

