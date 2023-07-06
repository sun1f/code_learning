#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <memory>
#include <mutex>

using namespace std;

class Matrix
{
public:
    Matrix(int row, int col) : _col(row), _row(row)
    {
        cout << "Matrix(int row, int col) : _col(row), _row(row)" << endl;
        _data = new float *[row];
        for (int i = 0; i < _row; ++i)
        {
            _data[i] = new float[col];
            for (int j = 0; j < _col; ++j)
            {
                _data[i][j] = 0;
            }
        }
    }

    Matrix(const Matrix &mat)
    {
        cout << "Matrix(const Matrix &mat)" << endl;
        _row = mat._row;
        _col = mat._col;
        _data = new float *[_row];
        for (int i = 0; i < _row; ++i)
        {
            _data[i] = new float[_col];
            for (int j = 0; j < _col; ++j)
            {
                _data[i][j] = mat._data[i][j];
            }
        }
    }

    Matrix(Matrix &&mat)
    {
        cout << "Matrix(Matrix &&mat)\n";
        _col = mat._col;
        _row = mat._row;
        _data = mat._data;
        mat._data = nullptr;
    }

    /*  Matrix operator+(const Matrix &mat)
     {
         cout << "Matrix operator+(const Matrix& mat)\n";
         if (_col != mat._col || _row != mat._col)
         {
             cout << "Error\n";
         }
         Matrix res(_col, _row);
         for (int i = 0; i < _row; ++i)
         {
             for (int j = 0; j < _col; ++j)
             {
                 res._data[i][j] = _data[i][j] + mat._data[i][j];
             }
         }
         return res;
     } */

    Matrix operator+(Matrix &mat) && // 这种写法也可以
    {
        cout << "Matrix operator+(const Matrix &mat) &&\n";
        if (_col != mat._col || _row != mat._col)
        {
            cout << "Error\n";
        }
        Matrix res = std::move(mat);
        for (int i = 0; i < _row; ++i)
        {
            for (int j = 0; j < _col; ++j)
            {
                res._data[i][j] += _data[i][j];
            }
        }
        return res;
    }

    friend Matrix operator+(const Matrix &mat1, const Matrix &mat2)
    {
        cout << "friend Matrix &operator+(const Matrix &mat1, const Matrix &mat2)" << endl;
        if (mat1._col != mat2._col || mat1._row != mat2._row)
        {
            cout << "Error\n";
        }
        Matrix res(mat1._row, mat1._col);
        for (int i = 0; i < mat1._row; ++i)
        {
            for (int j = 0; j < mat1._col; ++j)
            {
                res._data[i][j] = mat1._data[i][j] + mat2._data[i][j];
            }
        }
        return res;
    }

    /* friend Matrix operator+(Matrix &&mat1, const Matrix &mat2)
    {
        cout << "friend Matrix &operator+(const Matrix &&mat1, const Matrix &mat2)" << endl;
        if (mat1._col != mat2._col || mat1._row != mat2._row)
        {
            cout << "Error\n";
        }
        Matrix res = std::move(mat1); // 调用移动构造函数
        // Matrix res = mat1; // 这句代码会调用拷贝构造函数，而不是移动构造函数，因为右值引用是一左值
        for (int i = 0; i < mat2._row; ++i)
        {
            for (int j = 0; j < mat2._col; ++j)
            {
                res._data[i][j] += mat2._data[i][j];
            }
        }
        return res;
    } */

    ~Matrix()
    {
        cout << "~Matrix()\n";
        if (_data != nullptr)
        {
            for (int i = 0; i < _row; ++i)
            {
                if (_data[i])
                {
                    delete[] _data[i];
                    _data[i] = nullptr;
                }
            }
            delete[] _data;
            _data = nullptr;
        }
    }

private:
    int _row = 0;
    int _col = 0;
    float **_data = nullptr;
};

int main()
{
    cout << "Hello World" << endl;

    Matrix a(3, 4);
    Matrix b(3, 4);
    Matrix c(3, 4);
    Matrix d(3, 4);

    Matrix e = a + b + c + d;

    return 0;
}