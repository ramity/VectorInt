#include <iostream>

using namespace std;

class VectorInt
{
public:
    VectorInt();
    VectorInt(int size, int value);
    VectorInt(VectorInt & input);
    ~VectorInt();
    void assign(int size, int value);
    int at(int position);
    int back();
    int begin();
    int getCapacity();
    void clear();
    bool empty();
    void erase(int position);
    void erase(int first, int last);
    int front();
    int insert(int position, int value);
    int insert(int position, int size, int value);
    int max_getSize();
    VectorInt & operator=(VectorInt & x);
    int & operator[](int position);
    void pop_back();
    void push_back(int value);
    int rbegin();
    int rend();
    void reserve(int reserveSize);
    void resize(int resizeSize, int value);
    int getSize();
    void swap(VectorInt & swap);
    void print();
private:
    int size;
    int capacity;
    int * buffer;
    int const static max_size = 1000000;
};

//http://www.cplusplus.com/reference/vector/vector/vector/

VectorInt::VectorInt()
{
    //construct an 1 element vector
    this->size = 1;
    this->capacity = 1;
    this->buffer = new int[1];
}

VectorInt::VectorInt(int size, int value)
{
    //construct a container with [size] elements each element is a copy of [value]
    this->size = size;
    this->capacity = size;

    this->buffer = new int[size];

    for(int i = 0;i < size;i++)
    {
        this->buffer[i] = value;
    }
}

VectorInt::VectorInt(VectorInt & input)
{
    //constructs a container with a copy of each of the elements in x, in the same order
    this->size = input.getSize();
    this->capacity = input.getCapacity();

    this->buffer = new int[this->capacity];

    for(int i = 0;i < input.getSize();i++)
    {
        this->buffer[i] = input[i];
    }
}

//http://www.cplusplus.com/reference/vector/vector/~vector/

VectorInt::~VectorInt()
{
    //destroys all container elements and deallocates the array
    delete [] this->buffer;
}

//http://www.cplusplus.com/reference/vector/vector/assign/

void VectorInt::assign(int size, int value)
{
    //the new contents are [size] elements each set to [value]

    //check if buffer capacity is less than param size
    if(this->getCapacity() < size)
    {
        //allocate the proper buffer using the this->reserve method
        this->reserve(size);
    }

    if(this->getSize() < size)
    {
        this->size = size;
    }

    //set all elements
    for(int i = 0;i < size;i++)
    {
        this->buffer[i] = value;
    }
}

//http://www.cplusplus.com/reference/vector/vector/at/

int VectorInt::at(int position)
{
    //returns the value at [position]

    return * (this->buffer + position);
}

//http://www.cplusplus.com/reference/vector/vector/back/

int VectorInt::back()
{
    //returns the value of the last element in the vector

    return * (this->buffer + this->size - 1);
}

//http://www.cplusplus.com/reference/vector/vector/begin/

//dropped as it returns an interator

//http://www.cplusplus.com/reference/vector/vector/capacity/

int VectorInt::getCapacity()
{
    //returns the size of the storage space currently allocated for the vector

    return this->capacity;
}

//http://www.cplusplus.com/reference/vector/vector/clear/

void VectorInt::clear()
{
    //removes all elements from the vector (destroyed) leaving the container with a size of 0

    this->size = 0;
}

//http://www.cplusplus.com/reference/vector/vector/empty/

bool VectorInt::empty()
{
    //returns whether the vector is empty (if size is 0)

    if(this->size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//http://www.cplusplus.com/reference/vector/vector/end/

//dropped as it returns an interator

//http://www.cplusplus.com/reference/vector/vector/erase/

void VectorInt::erase(int position)
{
    //removes elements at [position]

    for(int i = position; i < this->getSize() - 1;i++)
    {
        this->buffer[i] = this->buffer[i + 1];
    }

    //this effectively reduces the size by 1

    this->size--;
}

void VectorInt::erase(int first, int last)
{
    //removes elements from first to last
    for(int i = first; i <= last;i++)
    {
        this->buffer[i] = this->buffer[i + (last - first) + 1];
    }

    //this effectively reduces the size by the range from [first] to [last]
    this->size = this->size - (last - first) - 1;
}

//http://www.cplusplus.com/reference/vector/vector/front/

int VectorInt::front()
{
    //returns a reference to the first element in the vector
    return * (this->buffer);
}

//http://www.cplusplus.com/reference/vector/vector/insert/

int VectorInt::insert(int position, int value)
{
    //The vector is extended by inserting new elements before the element at the specified [position],
    //effectively increasing the container size by the number of elements inserted.

    //check if capacity does not allow size + 1
        //allocate if it does not

    if(position > this->size)
    {
        this->size = position;
    }

    if(position > this->capacity)
    {
        this->reserve(position);
    }

    for(int i = position;i < position + 1;i++)
    {
        this->buffer[i + 1] = this->buffer[i];
        this->buffer[i] = value;
    }

    //move all elements to the right of the element to the right 1
    //set buffer[position] = value
}

int VectorInt::insert(int position, int size, int value)
{
    //The vector is extended by inserting [size] elements before the element at the specified [position],
    //effectively increasing the container size by the number of elements inserted.

    //check if capacity does not allow size + param size
        //allocate if it does not

    if(position > this->size)
    {
        this->size = position;
    }

    if(position > this->capacity)
    {
        this->reserve(position);
    }

    for(int i = position;i < position + size;i++)
    {
        this->buffer[i + size] = this->buffer[i];
        this->buffer[i] = value;
    }

    //move all elements to the right of the element to the right by param size
    //for i = position; i < position + size; i++
        //set buffer[i] = value
}

//http://www.cplusplus.com/reference/vector/vector/max_size/

int VectorInt::max_getSize()
{
    //returns the maximum number of elements that the vector can hold
    return this->max_size;
}

//http://www.cplusplus.com/reference/vector/vector/operator=/

VectorInt & VectorInt::operator=(VectorInt & x)
{
    if(&x == this)
    {
        return * this;
    }

    this->size = 0;

    this->reserve(x.getSize());

    for(; this->size < x.getSize(); this->size++)
    	this->buffer[this->size] = x[this->size];

    return * this;
}

int & VectorInt::operator[](int position)
{
    return * (this->buffer + position);
}

//http://www.cplusplus.com/reference/vector/vector/operator[]/

//?

//http://www.cplusplus.com/reference/vector/vector/pop_back/

void VectorInt::pop_back()
{
    //removes the last element in the vector, effectively reducing the container size by one
    this->size--;
}

//http://www.cplusplus.com/reference/vector/vector/push_back/

void VectorInt::push_back(int value)
{
    //adds a new element at the end of the vector after its current last element with the value of [value]

    //check if capacity < size + 1
        //allocate space if needed

    if(this->capacity < this->size + 1)
    {
        this->reserve(this->size + 1);
    }

    this->buffer[this->size] = value;
    this->size++;
}

//http://www.cplusplus.com/reference/vector/vector/rbegin/

//dropped as it returns an interator

//http://www.cplusplus.com/reference/vector/vector/rend/

//dropped as it returns an interator

//http://www.cplusplus.com/reference/vector/vector/reserve/

void VectorInt::reserve(int reserveSize)
{
    //requests that the vector capacity be at least enough to contain [reserveSize] elements
    if(this->capacity < reserveSize)
    {
        int * sideBuffer = new int[reserveSize];

        for(int i = 0;i < this->size;i++)
        {
            sideBuffer[i] = this->buffer[i];
        }

        this->buffer = sideBuffer;
        this->capacity = reserveSize;
    }
}

//http://www.cplusplus.com/reference/vector/vector/resize/

void VectorInt::resize(int resizeSize, int value)
{
    //Resizes the container so that it contains [resizeSize] elements.

    //If [resizeSize] is smaller than the current container size, the content is reduced to its first [resizeSize] elements, removing those beyond (and destroying them).

    //If [resizeSize] is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of [resizeSize].
    //If [value] is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.

    //If [resizeSize] is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.

    if(this->size > resizeSize)
    {
        this->size = resizeSize;
    }

    if(this->size < resizeSize)
    {
        this->reserve(resizeSize);

        for(int i = this->size + 1;i < resizeSize;i++)
        {
            this->buffer[i] = value;
        }

        this->size = resizeSize;
    }
}

//http://www.cplusplus.com/reference/vector/vector/size/

int VectorInt::getSize()
{
    //returns the number of element in the vector
    return this->size;
}

//http://www.cplusplus.com/reference/vector/vector/swap/

void VectorInt::swap(VectorInt & swap)
{
    int * sideBuffer = this->buffer;

    //exchanges the contents of the container by the content of [swap]. Sizes may differ
    if(swap.getSize() < this->size && this->size > swap.getCapacity())
    {
        swap.reserve(this->size);
    }

    if(this->size < swap.getSize() && swap.getSize() > this->capacity)
    {
        this->reserve(swap.getSize());
    }

    this->clear();

    for(int i = 0;i < swap.getSize();i++)
    {
        this->push_back(swap[i]);
    }

    swap.clear();

    for(int i = 0;i < this->size;i++)
    {
        swap.push_back(sideBuffer[i]);
    }
}

void VectorInt::print()
{
    for(int i = 0;i < this->size;i++)
    {
        cout << i << " : " << this->buffer[i] << endl;
    }

    cout << endl;
}

int main()
{
    VectorInt test;

    test.assign(10, 5);
    test.print();
    cout << test.getSize() << endl;

    cout << "TEST: 5" << endl;
    cout << "ACTUAL: " << test[1] << endl;
    cout << endl;

    test.print();

    cout << "TEST: 5" << endl;
    cout << "ACTUAL: " << test.back() << endl;
    cout << endl;

    test.print();

    cout << "TEST: 10" << endl;
    cout << "ACTUAL: " << test.getCapacity() << endl;
    cout << endl;

    test.clear();
    test.print();

    cout << "TEST: 1" << endl;
    cout << "ACTUAL: " << test.empty() << endl;
    cout << endl;

    test.assign(20, 5);
    test.print();
    test[11] = 42;
    test.print();
    test.erase(10);

    cout << "TEST: 42" << endl;
    cout << "ACTUAL: " << test[10] << endl;
    cout << endl;

    test.assign(20, 5);
    test.print();
    test[10] = 42;
    test[11] = 42;
    test.print();
    test.erase(8, 9);
    test.print();

    cout << test[8] << endl;
    cout << test[9] << endl;
    cout << test[10] << endl;
    cout << test[11] << endl;

    cout << "TEST: 42" << endl;
    cout << "ACTUAL: " << test[8] << endl;
    cout << endl;

    cout << "TEST: 5" << endl;
    cout << "ACTUAL: " << test.front() << endl;
    cout << endl;

    test.insert(10, 60);

    cout << "TEST: 60" << endl;
    cout << "ACTUAL: " << test[10] << endl;
    cout << endl;

    test.insert(10, 2, 37);

    cout << "TEST: 37" << endl;
    cout << "ACTUAL: " << test[11] << endl;
    cout << endl;

    cout << "TEST: (determined limit set by designer)" << endl;
    cout << "ACTUAL: " << test.max_getSize() << endl;
    cout << endl;

    VectorInt equalTest(100, 7);
    equalTest[10] = test[10];

    cout << "TEST: 37" << endl;
    cout << "ACTUAL: " << equalTest[10] << endl;
    cout << endl;

    test = equalTest;

    cout << "TEST: 37" << endl;
    cout << "ACTUAL: " << equalTest[10] << endl;
    cout << endl;

    test.pop_back();

    cout << "TEST: 99" << endl;
    cout << "ACTUAL: " << test.getSize() << endl;
    cout << endl;

    test.push_back(40);

    cout << "TEST: 40" << endl;
    cout << "ACTUAL: " << test.back() << endl;
    cout << endl;

    test.reserve(200);

    cout << "TEST: 200" << endl;
    cout << "ACTUAL: " << test.getCapacity() << endl;
    cout << endl;

    test.resize(5, 5);

    cout << "TEST: 5" << endl;
    cout << "ACTUAL: " << test.getSize() << endl;
    cout << endl;

    VectorInt swapTest(100, 5);
    test.print();
    test.swap(swapTest);
    test.print();

    cout << "TEST: 5" << endl;
    cout << "ACTUAL: " << test[75] << endl;
    cout << endl;

    return 1;
}
