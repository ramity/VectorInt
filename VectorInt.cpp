class VectorInt
{
private:
    int size;
    int capacity;
    int [] * buffer;
public:
    explicit VectorInt::VectorInt()
    explicit VectorInt::VectorInt(int size, int value)
    VectorInt::VectorInt(const VectorInt & input)
    VectorInt::~VectorInt()
    void VectorInt::assign(int size, int value)
    int VectorInt::at(int position)
    int VectorInt::back()
    int VectorInt::begin()
    int VectorInt::capacity()
    void VectorInt::clear()
    bool VectorInt::empty()
    int VectorInt::end()
    VectorInt::erase(int position)
    VectorInt::erase(int first, int last)
    int VectorInt::front()
    int VectorInt::insert(int position, int value)
    int VectorInt::insert(int position, int size, int value)
    int VectorInt::max_size()
    vectorInt & vectorInt::operator(const vectorInt & x)
    void VectorInt::pop_back()
    void VectorInt::push_back(int value)
    int VectorInt::rbegin()
    int VectorInt::rend()
    void VectorInt::reserve(int reserveSize)
    void VectorInt::resize(int resizeSize, int value = null)
    int VectorInt::size()
    void VectorInt::swap(VectorInt swap)
}

//http://www.cplusplus.com/reference/vector/vector/vector/

explicit VectorInt::VectorInt()
{
    //construct an "empty" container with no elements
}

explicit VectorInt::VectorInt(int size, int value)
{
    //construct a container with [size] elements each element is a copy of [value]
}

VectorInt::VectorInt(const VectorInt & input)
{
    //constructs a container with a copy of each of the elements in x, in the same order
}

//http://www.cplusplus.com/reference/vector/vector/~vector/

VectorInt::~VectorInt()
{
    //destroys all container elements and deallocates the array
}

//http://www.cplusplus.com/reference/vector/vector/assign/

void VectorInt::assign(int size, int value)
{
    //the new contents are [size] elements each set to [value]
}

//http://www.cplusplus.com/reference/vector/vector/at/

int VectorInt::at(int position)
{
    //returns the value at [position]
}

//http://www.cplusplus.com/reference/vector/vector/back/

int VectorInt::back()
{
    //returns the value of the last element in the vector
}

//http://www.cplusplus.com/reference/vector/vector/begin/

int VectorInt::begin()
{
    //return the value of the first element in the vector
}

//http://www.cplusplus.com/reference/vector/vector/capacity/

int VectorInt::capacity()
{
    //returns the size of the storage space currently allocated for the vector
}

//http://www.cplusplus.com/reference/vector/vector/clear/

void VectorInt::clear()
{
    //removes all elements from the vector (destroyed) leaving the container with a size of 0
}

//http://www.cplusplus.com/reference/vector/vector/empty/

bool VectorInt::empty()
{
    //returns whether the vector is empty (if size is 0)
}

//http://www.cplusplus.com/reference/vector/vector/end/

int VectorInt::end()
{
    //Returns the position referring to the past-the-end element in the vector container.

    //If the container is empty, this function returns the same as vector::begin
}

//http://www.cplusplus.com/reference/vector/vector/erase/

VectorInt::erase(int position)
{
    //removes elements at [position]

    //this effectively reduces the size by 1
}

VectorInt::erase(int first, int last)
{
    //removes elements from first to last

    //this effectively reduces the size by the range from [first] to [last]
}

//http://www.cplusplus.com/reference/vector/vector/front/

int VectorInt::front()
{
    //returns a reference to the first element in the vector
}

//http://www.cplusplus.com/reference/vector/vector/insert/

int VectorInt::insert(int position, int value)
{
    //The vector is extended by inserting new elements before the element at the specified [position],
    //effectively increasing the container size by the number of elements inserted.
}

int VectorInt::insert(int position, int size, int value)
{
    //The vector is extended by inserting [size] elements before the element at the specified [position],
    //effectively increasing the container size by the number of elements inserted.
}

//http://www.cplusplus.com/reference/vector/vector/max_size/

int VectorInt::max_size()
{
    //returns the maximum number of elements that the vector can hold
}

//http://www.cplusplus.com/reference/vector/vector/operator=/

vectorInt & vectorInt::operator(const vectorInt & x)
{
    if(&x == this)
    {
        return *this;
    }

    this.size = 0;

    this.reserve(x.size());

    for(; this.size < x.size(); this.size++)
    	this.buffer[this.size] = x[this.size];

    return *this;
}

//http://www.cplusplus.com/reference/vector/vector/operator[]/

//?

//http://www.cplusplus.com/reference/vector/vector/pop_back/

void VectorInt::pop_back()
{
    //removes the last element in the vector, effectively reducing the container size by one
}

//http://www.cplusplus.com/reference/vector/vector/push_back/

void VectorInt::push_back(int value)
{
    //adds a new element at the end of the vector after its current last element with the value of [value]
}

//http://www.cplusplus.com/reference/vector/vector/rbegin/

int VectorInt::rbegin()
{
    //returns a reverse iterator pointing to the last element in the vecor (its reverse beginning)
}

//http://www.cplusplus.com/reference/vector/vector/rend/

int VectorInt::rend()
{
    //returns a reverse iterator pointing to the theoretical element preceding the first element in the vector
    //which is consisered its reverse end
}

//http://www.cplusplus.com/reference/vector/vector/reserve/

void VectorInt::reserve(int reserveSize)
{
    //requests that the vector capacity be at least enough to contain [reserveSize] elements
}

//http://www.cplusplus.com/reference/vector/vector/resize/

void VectorInt::resize(int resizeSize, int value = null)
{
    //Resizes the container so that it contains [resizeSize] elements.

    //If [resizeSize] is smaller than the current container size, the content is reduced to its first [resizeSize] elements, removing those beyond (and destroying them).

    //If [resizeSize] is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of [resizeSize].
    //If [value] is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.

    //If [resizeSize] is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.
}

//http://www.cplusplus.com/reference/vector/vector/size/

int VectorInt::size()
{
    //returns the number of element in the vector
}

//http://www.cplusplus.com/reference/vector/vector/swap/

void VectorInt::swap(VectorInt swap)
{
    //exchanges the contents of the container by the content of [swap]. Sizes may differ
}
