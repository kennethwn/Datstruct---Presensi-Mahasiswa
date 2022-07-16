#ifndef MAHASISWA_INCLUDE
#define MAHASISWA_INCLUDE

// UAS - Data Structure - 2501973722 - Kenneth William Noverianto

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <malloc.h>

#define MxN 255
#define BSTMahasiswa NodeMahasiswa*

typedef struct {
	int hour;
	int min;
	int sec;
} DataTime;

typedef struct {
	char name[MxN];
	char NIM[MxN];
	DataTime time;
} DataMahasiswa;

typedef struct node {
	DataMahasiswa data;
	struct node *left;
	struct node *right;
} NodeMahasiswa;

BSTMahasiswa createNode (DataMahasiswa Data) {
	BSTMahasiswa node = (BSTMahasiswa)malloc(sizeof(NodeMahasiswa));
	node->data = Data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

BSTMahasiswa insertNode (DataMahasiswa Data, BSTMahasiswa root) {
	if (root == NULL) return createNode(Data);
	else if (strcmp(Data.NIM, root->data.NIM) < 0) root->left = insertNode(Data, root->left);
	else if (strcmp(Data.NIM, root->data.NIM) > 0) root->right = insertNode(Data, root->right);
	return root;
}

// Main Function
// Data Mahasiswa 
DataMahasiswa newDataMahasiswa (char *name, char *NIM) {
	DataMahasiswa dataMahasiswa;
	strcpy(dataMahasiswa.name, name);
	strcpy(dataMahasiswa.NIM, NIM);

	time_t now = time(NULL);
	struct tm *curr = localtime(&now);
	dataMahasiswa.time.hour = curr->tm_hour;
	dataMahasiswa.time.min = curr->tm_min;
	dataMahasiswa.time.sec = curr->tm_sec;

	return dataMahasiswa;
}

// Tambah Mahasiswa
void BSTMahasiswa_Insert (BSTMahasiswa *root, DataMahasiswa data) {
	*root = insertNode(data, *root);
}

//	Tampilkan Mahasiswa (preorder)
void BSTMahasiswa_Display (BSTMahasiswa root) {
	if (root != NULL) {
		printf(
				" %s : %02d:%02d:%02d - %s\n", 
				root->data.NIM,
				root->data.time.hour,
				root->data.time.min,
				root->data.time.sec,
				root->data.name
		);
		BSTMahasiswa_Display(root->left);
		BSTMahasiswa_Display(root->right);
	}
	else {
		return;
	}
}

// Searching Mahasiswa
BSTMahasiswa BSTMahasiswa_Search (BSTMahasiswa root, char *NIM) {
	if (root == NULL) return NULL;
	else if (strcmp(NIM, root->data.NIM) < 0) return BSTMahasiswa_Search (root->left, NIM);
	else if (strcmp(NIM, root->data.NIM) > 0) return BSTMahasiswa_Search (root->right, NIM);
	else return root;
}

#endif