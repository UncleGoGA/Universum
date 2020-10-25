#include <iostream>
//#typedef long usize_t

template <class Ma>
class Matrix
{
    size_t rows;
    size_t cols;
    Ma **matr;
    /*double det;
    bool is_det;
    inline void GetMatr(Ma **mas, Ma **p, int i, int j, int m)
    {
        int ki, kj, di, dj;
        di = 0;
        for (ki = 0; ki < m - 1; ki++)
        { // проверка индекса строки
            if (ki == i)
                di = 1;
            dj = 0;
            for (kj = 0; kj < m - 1; kj++)
            { // проверка индекса столбца
                if (kj == j)
                    dj = 1;
                p[ki][kj] = mas[ki + di][kj + dj];
            }
        }
    }
    inline void Determinant(int **mas, int m, double det)
    {
        for (i = 0; i < m; i++)
        {
            GetMatr(mas, p, i, 0, m);
            det = det + k * mas[i][0] * Determinant(p, n);
            k = -k;
        }
    }*/

public:
    // Matrix()
    // {
    //     cols = rows = 1;
    //     matr = new Ma[rows];
    //     /*if (cols == rows)
    //     {
    //         is_det = true;
    //     }
    //     else
    //     {
    //         is_det = false;
    //     }*/
    //     for (size_t i = 0; i < rows; ++i)
    //     {
    //         matr[i] = new Ma[cols];
    //         for (size_t j = 0; j < cols; ++j)
    //         {
    //             matr[i][j] = 0;
    //         }
    //     }
    //     /*if (is_det == true)
    //     {
    //         if (rows == 1)
    //         {
    //             det = matr[0][0];
    //         }
    //         else if (rows == 2)
    //         {
    //             det = matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
    //         }
    //         else if (rows == 3)
    //         {
    //             det = (matr[0][0] * matr[1][1] * matr[2][2] + matr[0][1] * matr[1][2] * matr[2][0] + matr[0][2] * matr[1][0] * matr[2][1]) -
    //             (matr[0][2] * matr[1][1] * matr[2][0] + matr[0][1] * matr[1][0] * matr[2][2] + matr[0][0] * matr[1][2] * matr[2][1]);
    //         }
    //         else
    //         {

    //         }
    //     }*/
    // }
    Matrix() = delete;
    Matrix(size_t rows = 1, size_t cols = 1)
    {
        this->rows = rows;
        this->cols = cols;
        matr = new Ma[rows];
        for (size_t i = 0; i < rows; ++i)
        {
            matr[i] = new Ma[cols];
            for (size_t j = 0; j < cols; ++j)
            {
                matr[i][j] = 0;
            }
        }
    }
    Matrix(Matrix &matr2)
    {
        rows = matr2.rows;
        cols = matr2.cols;
        matr = new Ma[rows];
        for (size_t i = 0; i < rows; ++i)
        {
            matr[i] = new Ma[cols];
            for (size_t j = 0; j < cols; ++j)
            {
                matr[i][j] = matr2[i][j];
            }
        }
    }
    ~Matrix()
    {
        for (size_t i = 0; i < rows; ++i)
        {
            delete[] matr[i];
        }
        delete[] matr;
    }
    size_t get_rows()
    {
        return rows;
    }
    size_t get_cols()
    {
        return cols;
    }
    Matrix operator[](size_t i)
    {
        return matr[i];
    }

    void operator*(double number)
    {
        for (size_t i = 0; i < rows; ++i)
        {
            for (size_t j = 0; j < cols; ++j)
            {
                matr[i][j] *= number;
            }
        }
    }

    Matrix operator*(const Matrix &M)
    {
        if (rows != M.m_cols)
            exit(-1);
        else
        {
            Matrix A(cols, M.m_rows); //Создаем матрциу под нужный размер
            for (int i = 0; i < A.m_cols; i++)
                for (int j = 0; j < A.m_rows; j++)
                    for (int k = 0; k < cols; j++)
                        A.matr[i][j] += matr[i][k] * A.matr[k][j];
            return A;
        }
    }

    void operator=(Matrix &matr2)
    {
        //it can copy whole matr2 only if they have sample size(etc: rows and cols)
        for (size_t i = 0; i < rows; ++i)
        {
            for (size_t j = 0; j < cols; ++j)
            {
                matr[i][j] = matr2[i][j];
            }
        }
    }

    void operator+(Matrix &matr2)
    {
        //it can summate whole matr2 only if they have sample size(etc: rows and cols)
        for (size_t i = 0; i < rows; ++i)
        {
            for (size_t j = 0; j < cols; ++j)
            {
                matr[i][j] += matr2[i][j];
            }
        }
    }

    void operator-(Matrix &matr2)
    {
        //it can desum whole math2 only if they have sample size(etc: rows and cols)
        for (size_t i = 0; i < rows; ++i)
        {
            for (size_t j = 0; j < cols; ++j)
            {
                matr[i][j] - +matr2[i][j];
            }
        }
    }

    size_t size()
    {
        return rows * cols;
    }

    void print()
    {
        for (size_t i = 0; i < rows; ++i)
        {
            for (size_t j = 0; j < cols; ++j)
            {
                std::cout << matr[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }

    bool operator==(Matrix &matr2)
    {
        if (rows != matr2.get_rows())
        {
            return false;
        }
        else if (cols != matr2.get_cols())
        {
            return false;
        }
        else
        {
            for (size_t i = 0; i < rows; ++i)
            {
                for (size_t j = 0; j < cols; ++j)
                {
                    if (matr[i][j] != matr2[i][j])
                    {
                        return false;
                    }
                }
            }
            return true;
        }
    }
    bool operator!=(Matrix &matr2)
    {
        if (rows != matr2.get_rows())
        {
            return true;
        }
        else if (cols != matr2.get_cols())
        {
            return true;
        }
        else
        {
            for (size_t i = 0; i < rows; ++i)
            {
                for (size_t j = 0; j < cols; ++j)
                {
                    if (matr[i][j] != matr2[i][j])
                    {
                        return true;
                    }
                }
            }
            return false;
        }
    }
    void resize(size_t rows, size_t cols)
    {
        //delete all data
        Matrix semi(rows, cols);
        // for(size_t i = 0; i < rows; ++i){
        //     for(size_t j = 0; j < cols; ++j){
        //         semi.matr[i][j] = matr[i][j];
        //     }
        // }
        for (size_t i = 0; i < this->rows; ++i)
        {
            delete[] matr[i];
        }
        delete[] matr;
        matr = semi.matr;
    }
    void input()
    {
        for (size_t i = 0; i < rows; ++i)
        {
            std::cout << "Remain " << rows - i << " strings" << std::endl;
            for (size_t j = 0; j < cols; ++j)
            {
                std::cin >> matr[i][j];
            }
        }
    }
};

int main()
{
    
    return 0;
}