#include<stdio.h>
#include<iostream>
using namespace std;

int main() {
	int size;
	int* arr = NULL, * caculate_arr = NULL;
	int result = 0;
	cout << "Enter array size : " ;
	cin >> size;
	arr = (int*)calloc(size, sizeof(int));
	caculate_arr = (int*)calloc(size, sizeof(int));//动态数组
	cout << "Enter array data :" ;
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}//输入注意用空格隔开数字，逗号会被错误识别
	caculate_arr[0] = arr[0];
	for (int i = 1; i < size; i++) {//动态规划方法找最大值
		if (caculate_arr[i - 1] > 0) {
			caculate_arr[i] = caculate_arr[i - 1] + arr[i];
		}
		else {
			caculate_arr[i] = arr[i];
		}
		result = max(result, caculate_arr[i]);
	}
	cout << "Result is : " << result << endl;
	return 0;
}