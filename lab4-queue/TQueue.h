template <class T>
class TQueue{
	int first;
	int last;
	int Size;
	int MaxSize;
	T* mas;
public:
	TQueue(int s = 10);
	~TQueue(){	delete[] mas;	}
	bool isempty(){return ( Size == 0 ); }
	bool isfull(){ return ( Size == MaxSize ); }
	TQueue(const TQueue &TQ);
	TQueue& operator=(const TQueue &TQ);
	T pop();
	void push(const T& el);
	T top();
	T First();
	T Last();
	T GetSize();
};

template <class T>
TQueue<T>::TQueue(int s = 10)
{
	mas = new T[s];
	first = 0;
	last = -1;
	MaxSize = s;
	Size = 0;
}

template <class T>
TQueue<T>::TQueue(const TQueue &TQ)
{
	f = first = TQ.first;
	last = TQ.last;
	MaxSize = TQ.MaxSize;
	mas = new T[Size = TQ.Size];
	for ( int i = 0; i < Size; i++ ) {
		mas[i + f] = TQ.mas[i + f];
		if ( i + f == MaxSize - 1 ) f = -i;
	}
}

template <class T>
TQueue<T>& TQueue<T>::operator=(const TQueue &TQ)
{
	delete[] mas;
	first = TQ.first;
	last = TQ.last;
	MaxSize = TQ.MaxSize;
	mas = new T[Size = TQ.Size];
	for ( int i=0; i < Size; i++ )
		mas[i] = TQ.mas[i];
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
	return mas[first];
}

template <class T>
T TQueue<T>::Last(){
	return mas[last];
}

template <class T>
T TQueue<T>::GetSize(){
	return Size;
}