#include <stdio.h>

void Array(int*, int);
void temp(int*, int*);

void main(){
	FILE *fp;
	int i, j;
	int data[20];
//	int length = sizeof(data) / sizeof(int);


	fp = fopen("data.txt", "r"); //f_name �̸��� ������ �߰������� ����
	if (fp == NULL){
		printf("%s ���� ���� ����!\n", "data.txt"); exit(1);
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



	//�������� 
	for (j = 0; j < 20; j++){
		for (i = 0; i < (20-1)-j ; i++){
			if (data[i] > data[i + 1]){
				temp(&data[i + 1], &data[i]);
			}
		}

	} //�������� end

	Array(data, 20);

	fp = fopen("sat.txt", "w");

	for (j = 0; j < 20; j++){
		fprintf(fp, "%d", data[j]);
	}
	fclose(fp);
		//�̶� �ݴ� ������ sat.txt


}
//�� �迭 ���
void Array(int arr[], int size){
	//data �迭 >>> arr[]
	//data �迭 index �� >> size
	int i;
	for (i = 0; i < size; i++){
		printf("%d\n", arr[i]);
	}
	printf("\n");
}

//temp�� n , n+1�� temp��

void temp(int *n1, int *n2){
	int tmp;
	tmp = *n2;
	*n2 = *n1;
	*n1 = tmp;
}