#pragma once

constexpr double SQUARE_INIT_4x4[16] = 
{
    0, 1, 12, 7,
    11, 8, 0, 2,
    5, 10, 3, 0,
    4, 0, 6, 9
};

template<typename T>
class PtrWrapper
{
public:
    PtrWrapper() : ptr(nullptr) {}
    PtrWrapper(T* ptr) : ptr(ptr) {}
    PtrWrapper& operator=(T value) { *ptr = value; return *this; }
    operator T() const { return *ptr; }
private:
    T* ptr;
};

/** @brief Base class for all magic square solvers */
class SquareSolver
{
public:
    /**
     * @brief Construct a new Square Solver object by initializing array data with a
     *        specified length
     *
     * @param dataSize Length of the data array (practically number of cells in the square)
     */
    SquareSolver(int dataSize);

    virtual ~SquareSolver();
    /**
     * @brief Solves a Magic Square for a specified sum and stores the cell contents in
     *        tha data array by stacking all the rows behind each other
     * 
     * @param x Number that the sums of all rows, columns and diagonals should equal to
     * @return True if the Magic Square was solved successfully, otherwise false
     */
    virtual bool solveFor(int x) = 0;

    /** @brief Returns the width and height of the Magic Square */
    virtual int size() const = 0;

    /** @brief Returns the sizeof the data array */
    int dataSize() const;
    
    /**
     * @brief Returns contents of a cell specified by its 0-based X and Y coordinates
     *        (coords [0, 0] correspond to the top left cell)
     * 
     * @param x The X coordinate of the cell
     * @param y The Y coordinate of the cell
     * @return Contents of the specified cell
     */
    double getCell(int x, int y) const;

    /**
     * Array containing contents of all the cells. The array should be constructed
     * such that all the rows are stacked behind each other. eg:
     * \code {.unparsed}
     *  1 | 2 | 3 
     * ---+---+---
     *  4 | 5 | 6 
     * ---+---+---
     *  7 | 8 | 9 
     * \endcode
     * will be stored like this:
     * \code {.unparsed}
     * { 1, 2, 3, 4, 5, 6, 7, 8, 9 }
     * \endcode
     */
    double* data = nullptr;
private:
    int dataLen;
};

class SquareSolver4x4 : public SquareSolver
{
public:

    static constexpr int FREE_CELLS_CNT = 7;

    /**
     * @brief Construct a new Square Solver object for a 4x4 Magic Square
     */
    SquareSolver4x4();
    bool solveFor(int x) override;
    bool solveGoodLookingFor(int x, double(*rng)(), int attemptCnt = 50);
    int size() const override;
    PtrWrapper<double> getFreeCell(int idx) const;
private:
    double *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m, *n, *o, *p;
    PtrWrapper<double> freeCells[FREE_CELLS_CNT];
    double dataDigitCntMean();
    double dataDigitCntVariance();
};

class SquareSolver3x3 : public SquareSolver
{
public:
    /**
     * @brief Construct a new Square Solver object for a 3x3 Magic Square
     * 
     * @param bottomMid Constant value that will be at the bottom middle of the square
     * @param bottomRight Constant value that will be at the bottom right of the square
     */
    SquareSolver3x3(double bottomMid = 3, double bottomRight = 6);
    bool solveFor(int x) override;
    int size() const override;
private:
    double *a, *b, *c, *d, *e, *f, *g, *h, *i;
};