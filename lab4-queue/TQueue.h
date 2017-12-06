template <class T>
calss TQueue{
	int first;
	int last;
	int Size;
	int MaxSize;
	T* mas;
public:
	TQueue(int s = 10);
	~TQueue(){	delete[] mas;	}
	TQueue(TQueue TQ);
	TQueue opetator=(TQueue TQ);
	bool isempty(){return ( Size == 0 ); }
	bool isfull(){ return ( Size == MaxSize ); }
	T pop();
	void push(const T& el);
	T top();
	T First();
	T Last();
};

template <class T>
TQueue<T>::TQueue(int s = 10)
{
	mas = new T[s];
	first = 1;
	last = 0;
	MaxSize = s;
	Size = last;
}

template <class T>
TQueue<T>::TQueue(TQueue TQ)
{
	first = TQ.first;
	last = TQ.last;
	MaxSize = TQ.MaxSize;
	mas = new T[Size = TQ.Size];
	for ( int i=0; i < Size; i++ )
		mas[i] = TQ.mas[i];
}

template <class T>
TQueue<T>::TQueue opetator=(TQueue TQ)
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
	if ( isempty() ) throw 0;
	if ( first = MaxSize - 1 ) first = 0;
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
T Tqueue<T>::top(){
}

template <class T>
T Tqueue<T>::First(){
}

template <class T>
T Tqueue<T>::Last(){
}