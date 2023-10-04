#pragma once

template <typename T> class Array
{
public:
	Array() = default;

	Array(int length);

	Array(const Array& Array);

	virtual ~Array();

	void erase();

	void reallocate(int newLength);

	void resize(int newLength);

	int& operator [](int i);

	int getLength() const;

	Array& operator=(const Array& Array);

	void insertBefore(T value, int i);

	void remove(int i);

	void insertAtBeginning(T value);

	void insertAtEnd(T value);

private:
	int m_length{};
	T* m_data{};
};
