#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>
#include <windows.h>
#include <cstdlib>
#include <cstring>
#include <ctime>
/*
��������:������� ����� ���������,���-21
����:02-07-2022
�������:2
�������:1. ��������� �������� ������, ���������� n = 16 �����. �������������� � ����� �������� � ������� ������� ��������� ����� �
���������� D �� 0 �� 150.
2. ��������� �+ ������, ���������� n = 16 ����� � �������
������� m = 5. �������� ������ � ����� �������� � ������� �������
��������� ����� � ���������� D �� 0 �� 150.
3. ���������� ����� �������� ������ ������.
4. ��������� ����� �������� ����� �� �������� �����.
*/

using namespace std;
int MAX = 5;


class Node {
    	bool IS_LEAF;
   	 	int *key, size;
    	Node **ptr;
    	friend class BPTree;
		public:
    	Node();
	};

 



	class BPTree {
    	Node *root;
    	void insertInternal (int, Node *, Node *);
    	Node *findParent(Node *, Node *);

	public:
    	BPTree();
    	void search(int);
    	void insert(int);
    	void display(Node *);
    	Node *getRoot();

	};

	Node::Node() {
    	key = new int [MAX];
    	ptr = new Node *[MAX + 1];
	}
	BPTree::BPTree() {
		root = NULL;
	}


	void BPTree::search(int x) {
    	if (root == NULL) {
	cout << "������ �����\n";
	} 
	else {
		Node *cursor = root;
		while (cursor->IS_LEAF == false) {
			for (int i = 0; i < cursor->size; i++) {
			if (x < cursor->key[i]) {
			cursor = cursor->ptr[i];
			break;
			}	

		if (i == cursor->size - 1) {
			cursor = cursor->ptr[i + 1];
			break;
		}
			}
		}
	for (int i = 0; i < cursor->size; i++) {
		if (cursor->key[i] == x) {
		cout << "�������\n";
		return;
		}
	}

		cout << "�� �������\n";
	}
	}

	void BPTree::insert (int x) {
	if (root == NULL) {
	root = new Node;
	root->key[0] = x;
	root->IS_LEAF = true;
	root->size = 1;
	} 
	else {
    	Node *cursor = root;
		Node *parent;
		while (cursor->IS_LEAF == false) {
		parent = cursor;
			for (int i = 0; i < cursor->size; i++) {
			if (x < cursor->key[i]) {
			cursor = cursor->ptr[i];
			break;
			}

		if (i == cursor->size - 1) {
   			cursor = cursor->ptr[i + 1];
   			break;
	}
			}
		}
		
			if (cursor->size < MAX) {
			int i = 0;
			while (x > cursor->key[i] && i < cursor->size)
			i++;
			for (int j = cursor->size; j > i; j--) {
			cursor->key[j] = cursor->key[j - 1];
			}
			cursor->key[i] = x;
			cursor->size++;
			cursor->ptr[cursor->size] = cursor->ptr[cursor->size - 1];
			cursor->ptr[cursor->size - 1] = NULL;
			} 
		else {
				Node *newLeaf = new Node;
				int virtualNode[MAX + 1];
				for (int i = 0; i < MAX; i++) {
				virtualNode[i] = cursor->key[i];
				}

			int i=0, j;
			
			while (x > virtualNode[i] && i < MAX)
			i++;
			for (int j = MAX + 1; j > i; j--) {
			virtualNode[j] = virtualNode[j - 1];
			}

				virtualNode[i] = x;
				newLeaf->IS_LEAF = true;
				
				cursor->size = (MAX + 1) / 2;
				newLeaf -> size =  MAX + 1 - (MAX + 1) / 2;
				cursor->ptr[cursor->size] = newLeaf;
				newLeaf->ptr[newLeaf->size] = cursor->ptr[MAX];
				cursor->ptr[MAX] = NULL;

				for (i = 0; i < cursor->size; i++) {
				cursor->key[i] = virtualNode[i];
				}
				for (i = 0, j = cursor->size; i < newLeaf->size; i++, j++) {
				newLeaf->key[i] = virtualNode[j];
				}
				if (cursor == root) {
				Node *newRoot = new Node;
				newRoot->key[0] = newLeaf -> key[0];
				newRoot->ptr[0] = cursor;
				newRoot->ptr[1] = newLeaf;
				newRoot->IS_LEAF = false;
				newRoot->size = 1;
				root = newRoot;

				} 
				else {
				insertInternal(newLeaf->key[0], parent, newLeaf);
				}
			}
	}
	}

		void BPTree::insertInternal(int x, Node *cursor, Node *child) {
			if (cursor->size < MAX) {
			int i = 0;
			while (x > cursor->key[i] && i < cursor->size)
			i++;
				for (int j = cursor->size; j > i; j--) { 
			cursor->key[j] = cursor->key[j - 1];
			}
				for (int j = cursor->size + 1; j > i + 1; j--) {
				cursor->ptr[j] = cursor->ptr[j - 1];
				}
					cursor->key[i] = x;
		cursor->size++;
		cursor->ptr[i + 1] = child;
		
				} 
					else {

						Node *newInternal = new Node;
						
							int virtualKey[MAX + 1];
						
							Node *virtualPtr[MAX + 2];
						
							for (int i = 0; i < MAX; i++) {
							virtualKey[i] = cursor->key[i];
							}
								for (int i= 0; i < MAX +1; i++) {
								virtualPtr[i] = cursor->ptr[i];
							}
								int  i = 0, j;
								while (x > virtualKey[i] && i < MAX)
								i++;
								for (int j = MAX + 1; j > i; j--) {
								virtualKey[j] = virtualKey[j - 1];
							}
								virtualKey[i] = x;
									for (int j = MAX + 2; j > i + 1; j--) {
									virtualPtr[j] = virtualPtr[ j - 1];
									}
									virtualPtr[i + 1] = child;
									newInternal->IS_LEAF = false;
									cursor->size = (MAX + 1) / 2;
									newInternal->size = MAX - (MAX + 1) / 2;
								
									for (i= 0, j = cursor->size + 1; i < newInternal->size; i++, j++) {
									newInternal->key[i] = virtualKey[j];
									}
									for (i = 0,j = cursor->size + 1; i < newInternal->size + 1; i++, j++) {
										newInternal->ptr[i] = virtualPtr[j];
									}
										if (cursor == root) {
										Node *newRoot = new Node;
										newRoot->key[0] = cursor->key[cursor->size];
										newRoot->ptr[0] = cursor;
										newRoot->ptr[1] = newInternal;
										newRoot->IS_LEAF = false;
										newRoot->size = 1;
										root = newRoot;
										}
										 else {
										insertInternal(cursor->key[cursor->size], findParent(root, cursor), newInternal);
										}
						}
		}

											Node *BPTree::findParent(Node *cursor, Node *child) {
													Node *parent;
														if (cursor->IS_LEAF || (cursor->ptr[0])->IS_LEAF) {
														return 0;
														}
														for (int i = 0; i < cursor->size + 1; i++) {
													    
															if (cursor->ptr[i] == child) {
															parent = cursor;
															return parent; 
															} 
															else {
															parent = findParent(cursor->ptr[i], child);
															if (parent != 0)
															return parent;
															}
														}
													
															return parent;
														}
													
															void BPTree::display(Node *cursor) {
														if (cursor != 0) {
													for (int i = 0; i < cursor->size; i++) {
														cout << cursor->key[i] << " ";
														}
														cout << "\n";
														if (!cursor->IS_LEAF) {
															for (int i = 0; i < cursor -> size + 1; i++) {
													
															display(cursor->ptr[i]);
														}
														}
														}
															}		
													 
																Node *BPTree::getRoot() {
																return root;
															}
													
																int main() {
																	
													
																BPTree node;
																system("chcp 1251");
													
																	for (int i = 0; i < 16; ++i) {
																		node.insert(rand() % 150);
																	}
																		node.display(node.getRoot());
													
																		cout << "������� �������� ��� �� �����: " << endl;
																		int c;
																		cin >> c;
																		cout << "����� "<< c << ": \n";
																		node.search(c);
																		}
