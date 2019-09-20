/*
	Minha implementacao da Heap Binaria 
	com base nas anotacoes das aulas
*/

#include <iostream>

class heap_binaria
{
private:
	int* h;
	int heap_size;
	int size;
public:

	heap_binaria()
	{
		this->h = new int[1];
		this->heap_size = 0;
		this->size = 1;
	}

	int size_potencia_2(int n)
	{
		int i = 1;
		for(i; i < n; i *= 2);
		return i;
	}

	void heapify(int i)
	{
		int m = i;
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		if (l < this->heap_size && this->h[l] > this->h[m])
		{
			m = l;
		}
		if (r < this->heap_size && this->h[r] > this->h[m])
		{
			m = r;
		}
		if (m != i)
		{
			int temp = this->h[i];
			this->h[i] = this->h[m];
			this->h[m] = temp;
			this->heapify(m);
		}
	}

	void build_heap()
	{
		for (int i = (this->heap_size / 2) - 1; i >= 0; i--) this->heapify(i);
	}

	heap_binaria(int* arr, int n)
	{
		this->heap_size = n;
		this->size = size_potencia_2(n);
		this->h = new int[this->size];
		for (int i = 0; i < n; i++) this->h[i] = arr[i];
		this->build_heap();
	}

	void bubble_up()
	{
		int i = this->heap_size - 1;
		while (i > 0 && this->h[i] > this->h[(i / 2) - 1])
		{
			int temp = this->h[i];
			this->h[i] = this->h[i / 2 - 1];
			this->h[i / 2 - 1] = temp;
		}
	}

	void heap_insert(int v)
	{
		if (this->heap_size == this->size)
		{
			int* aux = new int [2 * this->size];
			for (int i = 0; i < this->heap_size; i++) aux[i] = this->h[i];
			delete [] h;
			this->h = aux;
			this->size *= 2;
		}
		this->h[this->heap_size] = v;
		this->heap_size++;
		this->bubble_up();
	}

	int heap_extract()
	{
		int r = this->h[0];
		int temp = this->h[0];
		this->h[0] = this->h[this->heap_size - 1];
		this->h[this->heap_size - 1] = temp;
		this->heap_size--;
		heapify(0);
		return r;
	}

	int* heap_sort()
	{
		int n = this->heap_size;
		int* aux = new int [n];
		for(int i = n - 1; i >= 0 ; i--) aux[i] = heap_extract();
		return aux;
	}

	void print_heap()
	{
		for (int i = 0; i < this->heap_size; i++) std::cout << this->h[i] << " ";
		std::cout << std::endl;
	}
};

int main(int argc, char *argv[])
{
	int* arr = new int[10];
	int n = 10;
	arr[0] = 4;
	arr[1] = 1;
	arr[2] = 3;
	arr[3] = 2;
	arr[4] = 16;
	arr[5] = 9;
	arr[6] = 10;
	arr[7] = 14;
	arr[8] = 8;
	arr[9] = 7;
	heap_binaria bin(arr, n);
	bin.print_heap();
	int* aux = bin.heap_sort();
	for(int i = 0; i < 10; i++)	std::cout << aux[i] << " ";
	return 0;
}
