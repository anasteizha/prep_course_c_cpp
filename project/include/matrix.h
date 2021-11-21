#pragma once // NOLINT

#include <vector>
#include <istream>

namespace prep {
class Matrix {
    std::vector <std::vector <double>> mtr;
    size_t rows;
    size_t columns;
    void fill_new_matrix(Matrix *new_matrix, size_t n, size_t del_col, size_t del_row) const;

 public:
    explicit Matrix(size_t num_rows = 0, size_t num_cols = 0);
    explicit Matrix(std::istream& is);
    Matrix(const Matrix& rhs) = default;
    Matrix& operator=(const Matrix& rhs) = default;
    ~Matrix() = default;

    size_t getRows() const;
    size_t getCols() const;

    double operator()(size_t i, size_t j) const;
    double& operator()(size_t i, size_t j);

    bool operator==(const Matrix& rhs) const;
    bool operator!=(const Matrix& rhs) const;

    Matrix operator+(const Matrix& rhs) const;
    Matrix operator-(const Matrix& rhs) const;
    Matrix operator*(const Matrix& rhs) const;

    Matrix operator*(double val) const;

    friend Matrix operator*(double val, const Matrix& matrix);
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

    Matrix transp() const;
    double det() const;
    Matrix adj() const;
    Matrix inv() const;
};

Matrix operator*(double val, const Matrix& matrix);
std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
}  // namespace prep
