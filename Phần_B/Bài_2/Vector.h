#include <iostream>
using namespace std;

#ifndef __VECTOR__
#define __VECTOR__

template <class T>
class Vector {
private:
    T *elem;      // Mảng lưu trữ các phần tử
    int size;   // Số lượng phần tử hiện tại
    int space;   // Dung lượng hiện tại, số lượng phần tử tối đa có thể chứa
public:
    // Hàm khởi tạo mặc định
    Vector() : size(0), space(1) {
        elem = new T[space];
    }
    // Hàm khởi tạo với số lượng phần tử (n)
    Vector(int n, T value) : size(n), space(n) {
        elem = new T[space];
        for (int i = 0; i < n; i++) {
            elem[i] = value;
        }
    }
    // Destructor
    ~Vector(){
        if (elem != nullptr) {
            delete[] elem;
        }
    }
    // Hàm lấy số lượng phần tử hiện tại
    int get_size() {
        return size;
    }
    // hàm kiểm tra vector có rỗng không
    bool empty() {
        return size == 0;
    }   
    // Hàm lấy dung lượng hiện tại
    int capacity() {
        return space;
    }
    // hàm xóa phần tử cuối cùng của vector
    void pop_back() {
        if (size > 0) {
            size--;
        } else {
            cout << "Khong co phan tu nao!";
        }
    }
    // hàm trả về tham chiếu tới phần tử cuối cùng trong vector
    T &back() {
        if (size == 0) cout << "Phan tu cuoi khong ton tai!";
        return elem[size - 1];
    }
    // hàm trả về tham chiếu tới phần tử đầu tiên trong vector
    T &front() {
        if (size == 0) cout << "Phan tu dau khong ton tai!";
        return elem[0];
    }
    // hàm tăng dung lượng của vector lên new_space nếu dung lượng hiện tại (space) nhỏ hơn new_space
    void reserve(int new_space) {
        if (new_space <= space) return;  // Nếu dung lượng mới không lớn hơn hiện tại, không làm gì cả
        space = new_space;
        T *tmp = new T[space];
        for (int i = 0; i < size; i++) {
            tmp[i] = elem[i];
        }
        delete[] elem;  // Giải phóng bộ nhớ cũ
        elem = tmp;     // Gán lại mảng
    }
    // hàm thêm phần tử (value) vào cuối vector
    void push_back(T value) {
        if (size == space) {
            reserve(space * 2); // Tăng dung lượng gấp đôi khi không còn chỗ
        }
        elem[size] = value;
        ++size;
    }
    // hàm chèn phần tử (x) vào vị trí pos trong vector
    void insert(int pos, T x) {
        if (size == space) {
            reserve(space * 2);
        }
        for (int i = size - 1; i >= pos; i--) { // dịch chuyển các phần tử sang phải để tạo chỗ trống cho phần tử mới
            elem[i + 1] = elem[i];
        }
        elem[pos] = x;
        ++size;
    }
    // hàm xóa phần tử ở vị trí pos trong vector
    void erase(int pos) {
        if (pos < 0 || pos >= get_size()) {
            cout << "Chi so khong hop le!";
            return;
        }
        for (; pos < size - 1; pos++){ // vòng lặp dùng để dịch các phần tử sau vị trí pos sang trái 1 vị trí trong mảng
            elem[pos] = elem[pos + 1];
        }
        size--;
    }
    // hàm truy cập phần tử ở vị trí i trong vector
    T &operator[](int i) {
        if (i < 0 || i >= size) {
            cout << "Chi so khong hop le!";
        }
        return elem[i];
    }
    // hàm gán vector b cho vector hiện tại
    Vector &operator=(const Vector<T> &other) {
        if (this != &other) { // nếu vector hiện tại không phải là other thì gán như bên dưới
            delete[] elem;  // Giải phóng bộ nhớ cũ
            size = other.size;
            space = other.space;
            elem = new T[space];
            for (int i = 0; i < size; i++) {
                elem[i] = other.elem[i];
            }
        }
        return *this;
    }
    // hàm thay đổi kích thước vector thành new_size, các phần tử mới có giá trị mặc định là default_value
    void resize(int new_size, const T &default_value = T()) {
        if (new_size > space) {
            reserve(new_size);  // Tăng dung lượng nếu cần thiết
        }
        for (int i = size; i < new_size; i++) {
            elem[i] = default_value;  // Gán giá trị mặc định cho các phần tử mới
        }
        size = new_size; // Cập nhật số lượng phần tử
    }
    // duyệt qua các phần tử trong vector (dùng con trỏ)
    typedef T *iterator;
    // trả về con trỏ tới phần tử đầu tiên trong vector
    iterator begin() {
        return elem;
    }
    // trả về con trỏ tới phần tử cuối cùng trong vector
    iterator end() {
        return elem + size;
    }
};
#endif