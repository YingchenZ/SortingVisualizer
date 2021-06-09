#include <Windows.h>
#include <GL\glew.h>
#include <time.h>
#include <GL\freeglut.h>
#include <vector>
#include <string>


class BinaryInsertionSort {
private:
	std::vector<int> arr = {};
	time_t begin = 0;
	long long exchange = 0;
	int LOAD;
public:
	BinaryInsertionSort(std::vector<int> vec, int load) {
		arr = vec;
		LOAD = load;
	}

	void visualize(std::vector<int> arr, std::string type) {
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0f, 1.0f, 1.0f);
		std::string title = "Algorithm: " + type + "    Load = " + std::to_string(LOAD);
		std::string status = "Swap = " + std::to_string(exchange) + "    Time = " + std::to_string((clock() - begin) / 1000.0) + "s";
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

	int findSpot(int current){
		if (arr[current] >= arr[current - 1]) return -1;
		int left = 0, right = current - 1;
		int mid = 0;
		while (left < right) {
			mid = (left + right) / 2;
			if (arr[mid] > arr[current]) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
	}

	void sort() {
		begin = clock();
		for (int i = 1; i < arr.size(); i++) {
			int rightSpot = findSpot(i);

			if (rightSpot == -1) continue;
			
			for (int j = i - 1; j >= rightSpot; j--) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				++exchange;
				visualize(arr, "Binary Insertion");
			}
		}
	}
};