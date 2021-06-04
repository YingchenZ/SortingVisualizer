#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <time.h>
#include <vector>
#include <string>

class MergeSort {
private:
	std::vector<int> arr = {};
	time_t begin = 0;
	long long exchange = 0;
	int LOAD;
public:

	MergeSort(std::vector<int> vec, int load) {
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

	void merge(std::vector<int>& arr, int left, int mid, int right) {
		int firstPart = left, secondPart = mid + 1;
		std::vector<int> temp = {};
		while (firstPart <= mid && secondPart <= right) {
			if (arr[firstPart] <= arr[secondPart]) {
				temp.push_back(arr[firstPart]);
				firstPart++;
			}
			else {
				temp.push_back(arr[secondPart]);
				secondPart++;
			}
		}

		while (firstPart <= mid) {
			temp.push_back(arr[firstPart]);
			firstPart++;
		}

		while (secondPart <= right) {
			temp.push_back(arr[secondPart]);
			secondPart++;
		}

		for (int i = left; i <= right; i++) {
			arr[i] = temp[i - left];
			++exchange;
			visualize(arr, "Merge Sort");
		}
	}

	void mergeSort(std::vector<int>& arr, int left, int right) {
		if (left >= right)	return;

		int mid = (left + right) / 2;
		// left part
		mergeSort(arr, left, mid);
		// right part
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
		return;
	}

	void sort() {
		begin = clock();
		mergeSort(arr, 0, arr.size() - 1);
	}
};

