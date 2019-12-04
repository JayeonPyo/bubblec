#include <stdio.h>

void Array(int*, int);
void temp(int*, int*);

void main(){
	FILE *fp;
	int i, j;
	int data[20];
//	int length = sizeof(data) / sizeof(int);


	fp = fopen("data.txt", "r"); //f_name 이름의 파일을 추가용으로 열기
	if (fp == NULL){
		printf("%s 파일 열기 에러!\n", "data.txt"); exit(1);
	}

	else {
		j = 0;
	}


	while (fscanf(fp, "%d\n", &i) != EOF){
		data[j] = i;
		j++;
	}
	fclose(fp);

	Array(data, 20);
	
	printf("\n");



	//버블정렬 
	for (j = 0; j < 20; j++){
		for (i = 0; i < (20-1)-j ; i++){
			if (data[i] > data[i + 1]){
				temp(&data[i + 1], &data[i]);
			}
		}

	} //버블정렬 end

	Array(data, 20);

	fp = fopen("sat.txt", "w");

	for (j = 0; j < 20; j++){
		fprintf(fp, "%d", data[j]);
	}
	fclose(fp);
		//이때 닫는 파일은 sat.txt


}
//걍 배열 출력
void Array(int arr[], int size){
	//data 배열 >>> arr[]
	//data 배열 index 수 >> size
	int i;
	for (i = 0; i < size; i++){
		printf("%d\n", arr[i]);
	}
	printf("\n");
}

//temp로 n , n+1을 temp함

void temp(int *n1, int *n2){
	int tmp;
	tmp = *n2;
	*n2 = *n1;
	*n1 = tmp;
}