#ifndef _PILA_HPP_
#define _PILA_HPP_

#include <cassert>

/*
 * TAD Pila con implementacion generica vectorial pseudoestatica
 * 
 * Vector de tamano especificado por el usuario es el encargado de almacenar
 * los valores que se inserten en la pila
 * 
 */

template <typename tElemento>
class Pila
{
public:
	/* Requiere pasar TamMax */
	explicit Pila( size_t );

	Pila( const Pila& );
	Pila& operator =( const Pila& );
	/* Funciones observadoras */
	bool vacia() const;
	bool llena() const;
	const tElemento& tope() const;
	
	void pop();
	void push( const tElemento& );

	~Pila();
private:
	/* Vector de elementos */
	tElemento* elementos;
	/* Tam del vector */
	size_t Lmax;
	/* Posicion del _tope */
	int _tope;
};

template <typename T>
Pila<T>::Pila( size_t TamMax ) :
	Lmax(TamMax),
	_tope(-1),
	elementos(new T[TamMax]) 
{ }

template <typename T>
Pila<T>::Pila( const Pila& P ) :
	elementos( new T[P.Lmax]),
	Lmax( P.Lmax ),
	_tope( P._tope )
{
	for( size_t i = 0; i < _tope; i++ )
	{
		elementos[i] = P.elementos[i];
	}
}

template <typename T>
Pila<T>& Pila<T>::operator =( const Pila<T>& P )
{
	/* Evitamos autoasignacion */
	if ( this != &P )
	{
		if ( Lmax != P.Lmax )
		{
			delete[] elementos;
			Lmax = P.Lmax;
			elementos = new T[Lmax];
		}
		_tope = P._tope;
		for ( size_t i = 0; i < _tope; i++ )
		{
			elementos[i] = P.elementos[i];
		}
	}
	return *this;
}

template <typename T>
inline bool Pila<T>::vacia() const
{
	return ( _tope == -1 );
}

template <typename T>
inline bool Pila<T>::llena() const
{
	return ( _tope == Lmax - 1);
}

template <typename T>
inline const T& Pila<T>::tope() const
{
	assert( !vacia() );
	return elementos[_tope];
}

template <typename T>
inline void Pila<T>::pop()
{
	assert( !vacia() );
	--_tope;
}

template <typename T>
inline void Pila<T>::push( const T& x )
{
	assert( !llena() );
	++_tope;
	elementos[_tope] = x;
}

template <typename T>
inline Pila<T>::~Pila()
{
	delete[] elementos; 
}

#endif
