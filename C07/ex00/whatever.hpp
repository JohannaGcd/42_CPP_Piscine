#ifndef WHATEVER_H
#define WHATEVER_H

template <typename T> void swap(T& x, T& y) {
	T z = x;
	x = y;
	y = z;
}

template <typename T> T min(const T& x, const T& y) {
	return (x < y) ? x : y;
}

template <typename T> T max(const T& x, const T& y) {
	return (x > y) ? x : y;
}

#endif