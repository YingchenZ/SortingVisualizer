#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <time.h>
#include <vector>
#include <string>

class InsertionSort {
private:
	std::vector<int> arr = {};
	time_t begin = 0;
	long long exchange = 0;
	int LOAD;
public:
	InsertionSort(std::vector<int> vec, int load) {
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

	void sort() {
		begin = clock();
		for (int i = 1; i < arr.size(); i++) {
			for (int j = i; j >= 1; j--) {
				if (arr[j - 1] > arr[j]) {
					int temp = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = temp;
					++exchange;
					visualize(arr, "Insertion Sort");
				}
				else {
					break;
				}
			}
		}
	}
};

