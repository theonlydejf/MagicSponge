#include "solver.h"
#include <math.h>

SquareSolver::SquareSolver(int dataSize) : data(new double[dataSize]), dataLen(dataSize) {}
SquareSolver::~SquareSolver() { delete [] data; }

double SquareSolver::getCell(int x, int y) const
{
    int size = this->size();
    if(x >= size || y >= size)
        return 0;
    
    return data[y * size + x];
}

int SquareSolver::dataSize() const { return dataLen; }

int SquareSolver4x4::size() const { return 4; }

SquareSolver4x4::SquareSolver4x4() : SquareSolver(16)
{
    for(int i = 0; i < 16; i++)
        data[i] = SQUARE_INIT_4x4[i];
    a = data;
    b = data + 1;
    c = data + 2;
    d = data + 3;
    e = data + 4;
    f = data + 5;
    g = data + 6;
    h = data + 7;
    i = data + 8;
    j = data + 9;
    k = data + 10;
    l = data + 11;
    m = data + 12;
    n = data + 13;
    o = data + 14;
    p = data + 15;

    freeCells[0] = a;
    freeCells[1] = b;
    freeCells[2] = c;
    freeCells[3] = e;
    freeCells[4] = f;
    freeCells[5] = g;
    freeCells[6] = i;
}

int getDigitCnt(double num)
{
    int add = 1;
    if(num < 0)
    {
        num = -num;
        add++;
    }
    return floor(log10(abs(num))) + add;
}

double SquareSolver4x4::dataDigitCntMean()
{
    double sum = 0;
    for(int i = 0; i < dataSize(); i++)
        sum += getDigitCnt(data[i]);
    return sum / dataSize();
}

double SquareSolver4x4::dataDigitCntVariance()
{
    double mean = dataDigitCntMean();
    double sum = 0;
    for(int i = 0; i < dataSize(); i++)
        sum += pow(getDigitCnt(data[i]) - mean, 2);
    return sum / dataSize();
}

bool SquareSolver4x4::solveGoodLookingFor(int x, double(*rng)(), int attemptCnt)
{
    double bestVariance = 999999;
    double bestFreeCells[FREE_CELLS_CNT];
    bool found = false;
    for (size_t attempt = 0; attempt < attemptCnt; attempt++)
    {
        for(int i = 0; i < FREE_CELLS_CNT; i++)
            getFreeCell(i) = rng();
        solveFor(x);
        bool valid = true;

        for(int i = 0; i < dataSize(); i++)
        {
            if(data[i] == x)
            {
                valid = false;
                break;
            }
        }

        if(!valid)
            continue;
        double currVariance = dataDigitCntVariance();
        if(currVariance < bestVariance)
        {
            found = true;
            bestVariance = currVariance;

            for(int i = 0; i < FREE_CELLS_CNT; i++)
                bestFreeCells[i] = getFreeCell(i);
        }
    }

    for (int i = 0; i < FREE_CELLS_CNT; i++)
        getFreeCell(i) = bestFreeCells[i];
    solveFor(x);
    return true;
}

bool SquareSolver4x4::solveFor(int x)
{
    *d = -*a - *b - *c + x;
    *h = -*e - *f - *g + x;
    *j = 2 * *a + *b + *c + *e - *g + *i - x;
    *k = -2 * *a - *b - *c - *e - *f - *i + 2 * x;
    *l = *f + *g - *i;
    *m = -*a - *e - *i + x;
    *n = -2 * *a - 2 * *b - *c - *e - *f + *g - *i + 2 * x;
    *o = 2 * *a + *b + *e + *f - *g + *i - x;
    *p = *a + *b + *c + *e + *i - x;
    return true;
}

PtrWrapper<double> SquareSolver4x4::getFreeCell(int idx) const
{
    return freeCells[idx];
}

int SquareSolver3x3::size() const { return 3; }

SquareSolver3x3::SquareSolver3x3(double bottomMid, double bottomRight) : SquareSolver(9)
{
    a = data;
    b = data + 1;
    c = data + 2;
    d = data + 3;
    e = data + 4;
    f = data + 5;
    g = data + 6;
    h = data + 7;
    i = data + 8;

    *h = bottomMid;
    *i = bottomRight;
}

bool SquareSolver3x3::solveFor(int x)
{
    if(x % 3 != 0)
        return false;
    *g = x - *h - *i;
    *f = -*h - 2 * *i + (4 * x) / 3.;
    *e = x / 3.;
    *d = *h + 2 * *i - (2 * x) / 3;
    *c = *h + *i - x / 3.;
    *b = -*h + (2 * x) / 3.;
    *a = -*i + (2 * x) / 3;
    return true;
}
