#pragma once
#ifndef sqlist_h
#define sqlist_h
#define Status int
#define ListSize 6
#define ListIncrease 2
#define ERROR 0
#define OK 1
template <class T>
struct Elem
{
	T num, sco;
};
template <class T>
class Sqlist
{
private:
	Elem<T> *elem;
	int length;//实际存放元素个数
	int listsize;//可容纳最大元素个数
public:
	Sqlist();
	~Sqlist();
	void InputList_Sq();
	void OutputList_Sq();
	Status ListInsert_Sq(int i,T e);
	Status ListDelete_Sq(int i,T &e);
	Status MergeList_Sq(Sqlist &La, Sqlist &Lb);
};
template <class T>
Sqlist<T>::Sqlist()
{
	elem = new Elem<T>[ListSize];
	length = 0;
	listsize = ListSize;
}
template <class T>
Sqlist<T>::~Sqlist()
{
	delete[] elem;
}
template <class T>
void Sqlist<T>::InputList_Sq()
{
	cin >> length;//输入学号个数
	for (int i = 0; i < length; i++)
		cin >> elem[i].num >> elem[i].sco;
}
template <class T>
void Sqlist<T>::OutputList_Sq()
{
	for (int i = 0; i < length; i++)
		cout << elem[i].num<<","<<elem[i].sco << endl;
}
template <class T>
Status Sqlist<T>::ListInsert_Sq(int i, T e)
{    //在第i个元素前插入元素e
	T *p;
	if (i < 1 || i > length + 1) return ERROR;
	if (length >= ListSize)
	{//容量已满，增加容量
		T *newbase = new Elem<T>[ListSize + ListIncrease];
		if (!newbase) return ERROR;
		p = elem;
		elem = newbase;
		//复制原来的数据
		for (int i = 0; i <=listsize; i++)
			elem[i] = p[i];
		listsize += ListIncrease;
	}
	T *q = &(elem[i - 1]);
	for (p = &(elem[length - 1]); p >= q; p--)
		*(p + 1) = *p;
	*q = e;
	length++;
	return OK;

}
template <class T>
Status Sqlist<T>::ListDelete_Sq(int i, T &e)
{  //删除第i个元素，并用e返还值
	if (i < 1 || i > length) return 1;
	T *p = &elem[i - 1];
	e = *p;
	T *q = &elem[length - 1];
	for (; p <= q; p++)
		*p = *(p + 1);
	length--;
	return OK;
}
template <class T>
Status Sqlist<T>::MergeList_Sq(Sqlist &La, Sqlist &Lb)
{//已知La和Lb的元素按值非递减排列
	Elem<T> *pa, *pb, *pa_last, *pb_last,*pc;
	pa = La.elem, pb = Lb.elem;
	listsize = length = La.length + Lb.length;
	elem=pc= new Elem<T>[listsize];
	if (!elem) exit(OVERFLOW);//空间分配失败
	pa_last = La.elem + La.length - 1;
	pb_last = Lb.elem + Lb.length - 1;
	while (pa <= pa_last && pb <= pb_last)
	{
		if (pa->num<pb->num) *pc++ = *pa++;

		else *pc++ = *pb++;
	}

		while (pa <= pa_last) *pc++ = *pa++;

		while (pb <= pb_last) *pc++ = *pb++;
		
}
#endif