#ifndef DLIST_H
#define DLIST_H

template<typename TYPE>
struct Node
{
	TYPE data;
	Node* next;
	Node* previous;

	Node(const TYPE& value)
	{
		data = value;
		next = NULL;
		previous = NULL;
	}

};



template<class TYPE>
class DList
{
private:
	Node<TYPE>* start;
	Node<TYPE>* end;

public:
	DList()
	{
		start = NULL;
		end = NULL;
	}

	Node<TYPE>* getStart()
	{
	
		return start;
	}

	Node<TYPE>* getEnd()
	{
	
		return end;
	
	}
	

	void Add(const TYPE& oneNode)
	{
		if (oneNode != NULL)
		{
			Node<TYPE>* tmpNode = new Node<TYPE>(oneNode);

			if (start != NULL) //In case there's 1 or more nodes
			{
				tmpNode->previous = end;
				end->next = tmpNode;
				end = tmpNode;
			}
			else // In case the list is empty
			{
				start = tmpNode;
				end = tmpNode;
			}
			
		}

	}



	bool RemoveElement(Node<TYPE>* nodeToRemove)
	{

		if (nodeToRemove != NULL)
		{
			if (start != NULL)
			{
			
				if (nodeToRemove->next == NULL)//If it's the end
				{

					nodeToRemove->previous->next = NULL;
					end = nodeToRemove->previous;

				}
				else if (nodeToRemove->previous == NULL)//if it's at the beginning
				{
					if (nodeToRemove->next == NULL)//If there's only one node left
					{
						start = NULL;
						end = NULL;
					}
					else//If the node is at the beginning but there's more nodes after it
					{
						nodeToRemove->next->previous = NULL;//We set null to the next node after the first that is being removed
						start = nodeToRemove->next;
					}
					

				}
				else//If it's in the middle
				{
					nodeToRemove->previous->next = nodeToRemove->next;
					nodeToRemove->next->previous = nodeToRemove->previous;
				}
		
			}s
			else
			{
				return false;
		
			}

			delete nodeToRemove;
			return true;
		}
		return false;
	}

	void clear()
	{
		Node<TYPE>*   tmp_data;
		Node<TYPE>*   tmp_next;
		tmp_data = start;

		while (tmp_data != NULL)
		{
			tmp_next = tmp_data->next;
			delete (tmp_data);
			tmp_data = tmp_next;
		}

		start = end = NULL;
	}

	Node<TYPE>* getElementAtPos(unsigned int i)
	{
		Node<TYPE>* tmp = start;

		if (tmp != NULL && i < Count())
		{
			for (int c = 0; c < i; c++)
			{
				tmp = tmp->next;
			}
			return tmp;
		}

		return NULL;

	}

	void PrintNode(Node<TYPE>* n)
	{
		if (n != NULL)
		{
			printf("%d", n->data);
		}
		else
		{
			printf("No node in this position");
		}
	}

	void PrintList()
	{
		Node<TYPE>* tmp;
		tmp = start;

		while(tmp != NULL)
		{
			printf("%d\n ", tmp->data);
			tmp = tmp->next;
		}

	
	}



	bool isIn(const TYPE& toFind )
	{
		Node<TYPE>* tmp = this->getStart();
		bool comprovation = false;

		while (tmp != NULL)
		{
			if (tmp->data == toFind)
			{
				comprovation = true;
			}
			tmp = tmp->next;
		}
		return comprovation;
	}



	int Count()
	{
		int count = 0;

		if (start != NULL)
		{
			Node<TYPE>* n;
			n = start;
			
			while (n!=NULL)
			{
				n = n->next;
				count++;
			}
			return count;
		}
		else
		{
		
			return 0;
		}
	
	
	}

	const TYPE& operator [](const unsigned int n)
	{
		Node<TYPE>* tmp;
		tmp = start;

		if (n > Count())
		{
			return NULL;
		}

		for (int i = 0; i < n; i++)
		{
			if (i == n)
			{
				return tmp->data;
			}

			tmp = tmp->next;
		}


	
	}

	void Swap(Node<TYPE>* a, Node<TYPE>* b)
	{
		Node<TYPE>* tmp = a;
		a = b;
		
		a->previous = tmp->previous;
		a->next = tmp->next;
		tmp->next = b->next;
		tmp->previous = b->previous;
		


		tmp->previous->next = tmp;
		a->next->previous = a;

	
		b = tmp;

	}

	void Flip()
	{
		Node<TYPE>* tmpFirst = start;
		Node<TYPE>* tmpLast = end;

		for (; tmpFirst->previous != tmpLast || tmpLast->next != tmpFirst; tmpFirst = tmpFirst->previous, tmpLast = tmpLast->next)
		{
			Swap(tmpFirst, tmpLast);
		}
	
	}


	/*
	double BubbleSort()
	{

		bool swapped = true;
		int counter = 0;
		Node<TYPE>* tmp;


		while (swapped)
		{
			swapped = false;
			tmp = start;
			while (tmp->next != NULL)
			//for (int i = 0; i < num_elements - 1; i++)
			{
				counter++;
				if (tmp->data > tmp->next->data)
				{
					Swap(tmp->data, tmp->next->data);
					
					swapped = true;
				}
				tmp = tmp->next;
			}

		}
		return counter;

	}

	*/

	double BubbleSort()
	{

		bool swapped = true;
		int counter = 0;
		Node<TYPE>* tmp;


		while (swapped)
		{
			swapped = false;
			tmp = start;
			while (tmp->next != NULL)
			{
				counter++;
				if (tmp->data > tmp->next->data)
				{
					Swap(tmp, tmp->next);

					swapped = true;
				}
				tmp = tmp->next;
			}

		}
		return counter;

	}

	void CopyIntoArray(dynamicArray<TYPE>& arr)
	{
		arr.Clear();
		Node<TYPE>* pt;
		
		pt = start;
		
		while (pt)
		{
			arr.PushBack(pt->data);
			pt=pt->next;
		}
		arr.PrintArray();
	}





	~DList()
	{
		clear();
	}



};


#endif