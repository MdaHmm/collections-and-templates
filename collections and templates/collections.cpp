#include <iostream>
#include <string>

// коллекции и шаблонные классы
// типы коллекций:
// - линейный массив
//      - динамический  vector
//      - статический   array
// - списки 
//      - односвязные forward_list
//      - двусвязные списки list
//          - кольца
// - деревья set, map, и их производные
// - графы
// ---------
//  * очереди FIFO first inside first outside | queue
//  * стэки   FILO first inside last outside  | stack
//

class DinamiArray {
public:
    DinamiArray():data_(nullptr),size_(0){}

    //конструктор копирования
    DinamiArray(const DinamiArray& other) {
        this->size_ = other.size_;
        this->data_ = new float[size_];
        for (int i = 0; i < size_; i++){
            data_[i] = other.data_[i];
        }
    }

    //конструктор переноса
    DinamiArray(DinamiArray&& other) {
        this->size_ = 0;
        this->data_ = nullptr;
        std::swap(data_, other.data_);
        std::swap(size_, other.size_);
    }

    ~DinamiArray() {
        if (data_) {
            delete[] data_;
        }
    }

    void AddBack(float value) {
        if (data_) {
            auto tmp = new float[size_ + 1];
            for (int i = 0; i < size_; i++){
                tmp[i] = data_[i];
            }
            tmp[size_] = value;
            std::swap(tmp, data_);
            size_ += 1;
            delete[] tmp;
        }
        else {
            data_ = new float[1] {value};
            size_ += 1;
        }
    }

    void PopBack() {
        if (data_) {
            auto tmp = new float[size_ - 1];
            for (int i = 0; i < size_ - 1; i++) {
                tmp[i] = data_[i];
            }
            std::swap(tmp, data_);
            size_ -= 1;
            delete[] tmp;
            if (size_ == 0) {
                delete[] data_;
                data_ = nullptr;
            }
        }
    }

    float& operator[](int n) {
        return data_[n];
    }

    const float& operator[](int n)const {
        return data_[n];
    }

    //оператор присваивания копированием
    DinamiArray& operator = (const DinamiArray& other) {
        if (data_) {
            delete[] data_;
        }
        size_ = other.size_;
        data_ = new float[size_];
        for (int i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
        return *this;
    }

    //оператор присваивания переносом
    DinamiArray& operator = (DinamiArray&& other) {
        std::swap(data_, other.data_);
        std::swap(size_, other.size_);
        return *this;
    }

    int size()const;

private:
    float* data_;
    int size_;
    //int capacity_; требуется для более сложной 
    // но эфективной работы с выделенной памятью
};


void F00(DinamiArray obj){}

DinamiArray Gen(int length) {
    DinamiArray result;
    for (size_t i = 0; i < length; i++)
    {
        result.AddBack(::rand() % 10);
    }
    return result;
}

int main()
{
    //std::cout << "Hello World!\n";
    //auto tmp =  std::to_string(2.65);
    //std::cout << tmp;

    DinamiArray arrd;
    arrd.AddBack(1234.5);
    std::cout << arrd[0];
    F00(arrd);
    arrd.PopBack();
    DinamiArray arrd2 = Gen(15);
    DinamiArray();
    return 0;
}