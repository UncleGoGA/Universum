#include <iostream>

using namespace std;

struct list
{
	int inf;
	bool checked;
	list* next;
};

bool NilList(list*& root) {
	return (root == NULL ? true : false);
}

void IncertList(list*& root, int x)
{
	if (root == NULL)
	{
		list* el = new list;
		el->inf = x;
		el->next = NULL;
		root = el;
	}
	else
		IncertList(root->next, x);
}

void FindList(list*& root, int x, list*& cur, list*& prev)
{
	cur = root;
	prev = NULL;
	while (cur != NULL && cur->inf != x)
	{
		prev = cur;
		cur = cur->next;
	}
	if (cur == NULL)
		prev = NULL;
}


void printm(list* array, int size) {
	while (array != NULL) {
		cout << array->inf;
		array = array->next;
	}
	cout << endl;
}

void DeleteDoplers(list*& root)
{
	while (true) {
		if (root->inf == root->next->inf) {
			root = root->next;
			continue;
		}
		else {
			break;
		}
	}
	list* cur1 = root;

	while (cur1 != NULL)
	{
		list* cur2 = cur1->next;
		list* prev = cur1;
		while (cur2 != NULL)
		{
			if (cur2->inf == cur1->inf)
				prev->next = cur2->next;
			else
				prev = cur2;
			cur2 = cur2->next;
		}
		cur1 = cur1->next;
	}
}

int main() {
	list* root = NULL;
	list* new_root = NULL;
	int size = 0;
	int new_size = 0;
	int value = 0;
	cout << "Enter size of list" << endl;
	cin >> size;
	cout << "Enter value" << endl;
	for (size_t i = 0; i < size; ++i) {
		cin >> value;
		IncertList(root, value);
	}
	cout << "Is list isnt created? - " << NilList(root) << endl;
	if (NilList(root) == false) {
		printm(root, size);
		DeleteDoplers(root);
		printm(root, size);
		
	}
	else {
		cout << "List cant be processed" << endl;
		return 0;
	}

	return 0;
}