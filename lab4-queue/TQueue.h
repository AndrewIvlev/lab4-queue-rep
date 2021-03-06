template <class T>
class TQueue{
	int first;
	int last;
	int Size;
	int MaxSize;
	T* mas;
public:
	TQueue(int s = 10);
	~TQueue(){ delete[] mas; }
	bool isempty(){return ( Size == 0 ); }
	bool isfull(){ return ( Size == MaxSize ); }
	TQueue(const TQueue &TQ);
	TQueue<T>& operator=(const TQueue<T> &TQ);
	T pop();
	void push(const T& el);
	T top();
	T First();
	T Last();
	T GetSize();
	T GetMaxSize();
};

template <class T>
TQueue<T>::TQueue(int s)
{
	if ( s < 0) throw -1;
	mas = new T[s];
	first = 0;
	last = -1;
	MaxSize = s;
	Size = 0;
}

/*template <class T>
TQueue<T>::TQueue(const TQueue &TQ)
{
	first = TQ.first;
	last = TQ.last;
	MaxSize = TQ.MaxSize;
	mas = new T[Size = TQ.Size];
	for ( int i = 0; i < MaxSize; i++ ) {
		mas[i] = TQ.mas[i];
	}
}*/

template <class T>
TQueue<T>& TQueue<T>::operator=(const TQueue<T> &TQ)
{
	delete[] mas;
	first = TQ.first;
	last = TQ.last;
	MaxSize = TQ.MaxSize;
	mas = new T[Size = TQ.Size];
	for ( int i=0; i < MaxSize; i++ )
		mas[i] = TQ.mas[i];
	return *this;
}

template <class T>
T TQueue<T>::pop()
{ 
	T tmp = mas[first];
	if ( isempty() ) throw 0;
	if ( first == MaxSize - 1 ) first = 0;
	else first++;
	Size--;
	return tmp;
}

template <class T>
void TQueue<T>::push(const T& el)
{
	if ( isfull() ) throw 0;
	if ( last == MaxSize - 1 ) last = 0;
	else last ++;
	mas[last] = el;
	Size++;
}

template <class T>
T TQueue<T>::top(){
	if ( isempty() ) throw 0;
	return mas[first];
}

template <class T>
T TQueue<T>::First(){
	return first;
}

template <class T>
T TQueue<T>::Last(){
	return last;
}

template <class T>
T TQueue<T>::GetSize(){
	return Size;
}

template <class T>
T TQueue<T>::GetMaxSize(){
	return MaxSize;
}