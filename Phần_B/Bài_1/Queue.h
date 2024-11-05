#ifndef __Queue__
#define __Queue__
#include <bits/stdc++.h>

using namespace std;

template<class T>

class Queue{
    // f: front, r: rear, size: number of elements, space: capacity
    int f, r, size, space;
    T* elem;
public:
    // Constructor
    Queue() : f(0), r(0), size(0), space(0){
        elem = new T[space];
    }
    // Destructor
    ~Queue(){
        if(elem != NULL) delete[] elem;
    }
    // Kiểm tra xem trong hàng đợi có phần tử hay không
    bool empty(){
        return size == 0;
    }
    // Lấy số lượng phần tử trong hàng đợi
    int get_size(){
        return size;
    }
    // Lấy phần tử ở vị trí đầu tiên
    T& front(){     
        return elem[f];
    }
    // Lấy phần tử ở vị trí cuối cùng
    T& back(){
        // Khi r = 0 => chỉ số r đã quay lại đầu mảng(do cơ chế vòng tròn) => phần tử cuối cùng là phần tử ở vị trí space - 1
        if(r == 0) return elem[space - 1];
        return elem[r - 1];
    }
    // Gán toàn bộ dữ liệu và trạng thái của hàng đợi other vào hàng đợi hiện tại (this)
    Queue<T>& operator=(Queue<T>& other){
        this->size = other.size;
        this->space = other.space;
        this->f = other.f;
        this->r = other.r;
        T* tmp = new T[space];
        for(int i = 0; i < size; i++){
            tmp[i] = other.elem[i];
        }
        if(elem != NULL) delete[] elem;
        tmp = elem;
        return *this;
    }
    // Thêm 1 phần tử vào cuối hàng đợi
    void push(T val){
        if(size == space){
            space = space == 0 ? 1 : space * 2;
            T* tmp = new T[space];
            for(int i = 0, j = f; i < size; i++, j++){
                tmp[i] = elem[j % size];
            }
            if(elem != NULL) delete[] elem;
            elem = tmp;
            f = 0; // Mảng mới được tạo ra => f = 0
            r = size; // Chỉ số cuối cùng (r) được thiết lập bằng với kích thước mới của hàng đợi
        } 
        elem[r] = val;
        size++;
        r = (r + 1) % space; // Nếu r vượt quá space thì quay lại đầu mảng nhờ phép mod => đảm bảo cơ chế vòng tròn
    }
    // Xóa phần tử ở vị trí đầu tiên
    void pop(){
        if(size == 0) return;
        f = (f + 1) % space; // f tăng lên 1 đơn vị, nếu vượt quá space thì quay lại đầu mảng
        size--;
    }
};
#endif