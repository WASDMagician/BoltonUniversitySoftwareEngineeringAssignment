#ifndef _VECTOR2_H_
#define _VECTOR2_H_

template <class T, class T2>

class Vector2
{
public:
	Vector2(void);
	Vector2(T nx, T2 ny);
	~Vector2();
	T x;
	T2 y;

	bool operator >(float incoming);
	bool operator >=(float incoming);
	bool operator >(Vector2<T, T2> incoming);
	bool operator >=(Vector2<T, T2> incoming);

	bool operator <(float incoming);
	bool operator <=(float incoming);
	bool operator <(Vector2<T, T2> incoming);
	bool operator <=(Vector2<T, T2> incoming);

	bool operator ==(float incoming);
	bool operator ==(Vector2<T, T2> incoming);

	bool operator !=(float incoming);
	bool operator !=(Vector2<T, T2> incoming);

	
};


template <class T, class T2>
Vector2<T, T2>::Vector2(void)
{

}

template <class T, class T2>
Vector2<T, T2>::Vector2(T nx, T2 ny)
{
	this->x = nx;
	this->y = ny;
}


template <class T, class T2>
bool Vector2<T, T2>:: operator >= (float incoming)
{
	return (this->x >= incoming && this->y > incoming)
}

template <class T, class T2>
bool Vector2<T, T2>:: operator >(float incoming)
{
	return (this->x > incoming && this->y > incoming)
}


template <class T, class T2>
bool Vector2<T, T2>:: operator > (Vector2<T, T2> incoming)
{
	return (this->x > incoming.x && this->y > incoming->y);
}

template <class T, class T2>
bool Vector2<T, T2>:: operator >= (Vector2<T, T2> incoming)
{
	return(this->x >= incoming.x && this->y >= incoming.y);
}

template <class T, class T2>
bool Vector2<T, T2>:: operator < (float incoming)
{
	return(this->x < incoming && this->y < incoming);
}

template <class T, class T2>
bool Vector2<T, T2>:: operator <= (float incoming)
{
	return(this->x <= incoming && this->y <= incoming);
}

template <class T, class T2>
bool Vector2<T, T2>:: operator < (Vector2<T, T2> incoming)
{
	return(this->x < incoming.x && this->y < incoming.y);
}

template <class T, class T2>
bool Vector2<T, T2>:: operator <= (Vector2<T, T2> incoming)
{
	return(this->x <= incoming.x && this->y <= incoming.y);
}



template <class T, class T2>
bool Vector2<T, T2>:: operator == (float incoming)
{
	return(this->x == incoming && this->y == incoming);
}

template <class T, class T2>
bool Vector2<T, T2>:: operator == (Vector2<T, T2> incoming)
{
	return(this->x == incoming.x && this->y == incoming.y);
}

template <class T, class T2>
bool Vector2<T, T2>:: operator != (float incoming)
{
	return(this->x != incoming || this->y != incoming);
}

template <class T, class T2>
bool Vector2<T, T2>:: operator != (Vector2<T, T2> incoming)
{
	return(this->x != incoming.x || this->y != incoming.y);
}

#endif //_VECTOR2_H_