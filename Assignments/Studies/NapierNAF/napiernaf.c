#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>
#include "napiernaf.h"

// Returns -1 if value is negative.
// Returns 1 if value is positive.
static int Znak(const int value) {
    return (value < 0 ? -1 : 1);
}

// Tries to allocate array for size int elements and return pointer.
// Asserts if allocation was correct.
static int *Allocate(int size) {
    int *ptr = malloc(sizeof(int) * (unsigned int) size);
    assert(ptr != NULL || size == 0);
    return ptr;
}

// Tries to reallcate present at adress ptr and resize it for size int elements.
// Returns pointer to new addres of an array.
// Asserts if allocation was correct.
static int *Reallocate(int *ptr, int size) {
    ptr = realloc(ptr, sizeof(int) * (unsigned int) size);
    assert(ptr != NULL || size == 0);
    return ptr;
}

// Returns symetric value.
// Helpful in compering powers.
// Absolute of return value is always power +1.
// Sign means if bit is positive or positive.
static int Symetric(int value) {
    if (value >= 0)
        value++;
    return value;
}

// Returns symetric value disregarding the sign.
static int SymetricAbs(int value) {
    value = Symetric(value);
    value = abs(value);
    return value;
}

// Converts symetric value to unsymetric.
// Unsymetric value is used to store number.
static int UnSymetric(int value) {
    if (value > 0)
        value--;
    return value;
}

// Nagates number written in tab bit by bit.
static void NegateNumber(int tab[], const int n) {
    for (int iter = 0; iter < n; iter++) {
        tab[iter] = UnSymetric(-Symetric(tab[iter]));
    }
}

// Converts Number in NapierNAF notation to standard binary.
// From table a to table result.
// Works only for numbers greated or equal to 0.
static void FromNapier(const int a[], const int an, int *result[], int *result_n) {
    if (an == 0) {
        *result = NULL;
        *result_n = 0;
    }
    else {
        int limit = a[an - 1] + 10;
        int *b = Allocate(limit);

        int iter_b = 0;
        int iter_a = 0;
        int overflow = 0;

        while (iter_b < limit && iter_a < an) {
            b[iter_b] = overflow;
            overflow = 0;
            if (iter_a < an && iter_b == SymetricAbs(a[iter_a]) - 1) {
                b[iter_b] += Znak(a[iter_a]);
                iter_a++;
            }
            // Move any value other than 0,1 to next bit.
            // Works assuming that negative values will cancel out in the future.
            if (b[iter_b] < 0)
                overflow = (b[iter_b] - 1) / 2;
            else if (b[iter_b] > 1) 
                overflow = b[iter_b] / 2;

            b[iter_b] -= 2 * overflow;
            iter_b++;
        }
        *result = Reallocate(b, iter_b);
        *result_n = iter_b;
    }
}

// Copies number represented in a to b.
// Copy is created with new address that does not impact a.
static void Copy(const int a[], const int an, int *b[], int *bn) {
    *b = Allocate(an);
    *bn = an;

    for (int iter = 0; iter < an; iter++) {
        (*b)[iter] = a[iter];
    }
}

// Adds values from table from with indexes from start (including) to ends (excluding).
// Values are added to table tab, *iter changes to accomodate accurate table size.
static void AddRest(const int from[], int start, const int ends, int tab[], int *iter) {
    while (start < ends) {
        tab[*iter] = from[start];
        (*iter)++;
        start++;
    }
}

// Compare function for Sort in CompleteCorrect.
// Compares values based on power it represents.
static int comp(const void *a, const void *b) {
    int val1 = SymetricAbs(*((int*)a));
    int val2 = SymetricAbs(*((int*)b));

    if (val1 < val2)
        return -1;
    else if (val1 == val2)
        return 0;
    else
        return 1;
}

// Checks if value is even
static bool Even(int value) {
    return !(value & 1);
}

// If counter is uneven then tries to add a sigle bit in position bit.
// Prepares values in bit and counter for next iteration.
static void AddBit(int array[], int *an, int *bit, int *counter) {
    if (!Even(*counter)) {
        // Checks if adding bit normaly would make NapierNAF invalid.
        if (*an > 0 && SymetricAbs(array[*an - 1]) + 1 == *bit) {
            int val = array[*an - 1];
            array[*an - 1] = UnSymetric(-Symetric(val));
            *counter += 2 * Znak(val);
        }
        else {
            array[*an] = UnSymetric(*bit * Znak(*counter));
            (*an)++;
        }
    }
    (*bit)++;
    *counter /= 2;
}

// Iterates bits until limit is hit or there are no bits to be counted left.
static void IterateBit(int array[], int *an, int *bit, int *counter, int limit) {
    while (*counter != 0 && *bit < limit) {
        AddBit(array, an, bit, counter);
    }
}

// Iterates through all bits and converts number in array to proper NapierNAF.
static void InterateAll(int array[], int an, int *ends) {
    int last = -1;
    int val;
    int counter = 0;
    for (int iter = 0; iter < an; iter++) {
        val = SymetricAbs(array[iter]);
        if (val != last) {
            IterateBit(array, ends, &last, &counter, val);
            last = val;
        }
        counter += Znak(array[iter]);
    }
    IterateBit(array, ends, &last, &counter, INT_MAX);
}

// Converts array to NapierNAF correct form 
// based on the assumption that values are valid and correct.
static void CompleteCorrect(int *array[], int *an, bool sorted) {
    int *tab = *array;
    if (!sorted)
        qsort(tab, (size_t) *an, sizeof(int), comp);
    // Iterate all bit and save how much space is required.
    int ends = 0;
    InterateAll(tab, *an, &ends);
    
    // Cut unnecessary array size and set values for result.
    *array = Reallocate(tab, ends);
    *an = ends;
}

// Performs given operation on a and b.
// Returns results to a.
static void InPlace(int *a[], int *an, int b[], int bn, 
    void(*func)(int*, int, int*, int, int**, int*)) {
    int *c, cn;
    func(*a, *an, b, bn, &c, &cn);
    free(*a);
    *a = c;
    *an = cn;
}

// Multiplies number represented in table a by number in b.
static void MultiplyInPlace(int *a[], int *an, int b[], int bn) {
    InPlace(a, an, b, bn, nmul);
}

// Subtract number represented in table b from number in a.
static void SubtractInPlace(int *a[], int *an, int b[], int bn) {
    InPlace(a, an, b, bn, nsub);
}

// Adds number represented in table b to number in a.
static void AddInPlace(int *a[], int *an, int b[], int bn) {
    InPlace(a, an, b, bn, nadd);
}

// Merges numbers in a and b bit by bit sustaining sorted order of bits.
// Merged result is written in table result.
// It assumes result will fit in allocated space.
static void Merge(int a[], int an, int b[], int bn, int result[], int *result_n) {
    int iter = 0;
    int iter_a = 0, iter_b = 0;
    int val_a, val_b;
    while (iter_a < an && iter_b < bn) {
        val_a = SymetricAbs(a[iter_a]);
        val_b = SymetricAbs(b[iter_b]);

        if (val_a <= val_b) {
            result[iter] = a[iter_a];
            iter_a++;
        }
        else {
            result[iter] = b[iter_b];
            iter_b++;
        }
        iter++;
    }
    AddRest(a, iter_a, an, result, &iter);
    AddRest(b, iter_b, bn, result, &iter);
    *result_n = iter;
}

// Multiplies each bit in number represented in a 
// by a constant value.
static void MultiplyConst(int a[], const int an, const int value) {
    for (int iter = 0; iter < an; iter++) {
        a[iter] = (SymetricAbs(a[iter]) + SymetricAbs(value) - 1) * Znak(iter[a]) * Znak(value);
        a[iter] = UnSymetric(a[iter]);
    }
}

// Converts number x to NapierNAF in dynamically allocated array *a with *n elements.
// Performs standard conversion to NapierNAF according to exercise. 
void iton(int x, int **a, int *n) {
    int *wynik = Allocate(64);

    int iter = 0; // iterator for first not used element in array.
    int c;
    int power = 1; // Real power is 1 less.
    while (x) {
        c = 0;
        if(!Even(x)) {
            c = (Even((x + 1) / 2) ? -1 : 1);
            wynik[iter] = UnSymetric(c * power);
            iter++;
        }
        x = (x - c) / 2;
        power++;
    }
    *a = Reallocate(wynik, iter);
    *n = iter;
}

// Return standard representation of number in table a size n.
// Returns 0 if number does not fit in INT data type.
int ntoi(int *a, int n) {
    long long wynik = 0;

    for (int z = 0; z < n; z++) {
        // Checks if 2^{exponent} fits in long long.
        long long power = SymetricAbs(a[z]) - 1;
        if (power <= 62)
            wynik += (long long) Znak(a[z]) * ((long long) 1 << power);
        else
            return 0;
    }

    // Checks if answer fits in INT data type.
    return (INT_MIN <= wynik  && wynik <= INT_MAX ? ((int) wynik) : 0);
}

// Function adding numbers in tables a,b and setting c as a result.
// Works by adding bits in sorted order.
void nadd(int *a, int an, int *b, int bn, int **c, int *cn) {
    int *wynik = Allocate(an + bn);
    int iter = 0;

    Merge(a, an, b, bn, wynik, &iter);
    CompleteCorrect(&wynik, &iter, true);

    *c = wynik;
    *cn = iter;
}

// Subtracts number in b from a by
// negating b adding it and returning to start state.
void nsub(int *a, int an, int *b, int bn, int **c, int *cn) {
    NegateNumber(b, bn);
    nadd(a, an, b, bn, c, cn);
    NegateNumber(b, bn);
}

// Multiplies numbers in a and b and returns result to c.
void nmul(int *a, int an, int *b, int bn, int **c, int *cn) {
    int *wynik, index = 0;
    int *new_b, new_bn;
    wynik = Allocate(1);
    
    for (int iter_a = 0; iter_a < an; iter_a++) {
        Copy(b, bn, &new_b, &new_bn);
        MultiplyConst(new_b, new_bn, a[iter_a]);
        AddInPlace(&wynik, &index, new_b, new_bn);
        free(new_b);
    }
    *c = wynik;
    *cn = index;
}

// Raises number stored in a to power of number stored in b.
// Sets result to dynamically allocated table c.
void nexp(int *a, int an, int *b, int bn, int **c, int *cn) {
    int *power, power_n;
    FromNapier(b, bn, &power, &power_n);

    int *result, result_n;
    iton(1, &result, &result_n);

    int *multiplicant, multiplicant_n;
    Copy(a, an, &multiplicant, &multiplicant_n);

    // Fast exponent algorithm
    for (int iter = 0; iter < power_n; iter++) {
        if (power[iter])
            MultiplyInPlace(&result, &result_n, multiplicant, multiplicant_n);
        MultiplyInPlace(&multiplicant, &multiplicant_n, multiplicant, multiplicant_n);
    }
    free(multiplicant);
    free(power);
    *c = result;
    *cn = result_n;
}   

// Performs Euclidean Division of numbers stored in NapierNAF form.
// Divides number a by b.
// Sets quotient to q and remaider to r.
void ndivmod(int *a, int an, int *b, int bn, int **q, int *qn, int **r, int *rn) {
    int *result, result_n = 0;
    int *rest, rest_n = 0;
    if (an > 0) {
        Copy(a, an, &rest, &rest_n);
        result = Allocate(a[an - 1] + 10);
        int *change, change_n;
        int div;

        while (rest_n > 0 && 
                (div = SymetricAbs(rest[rest_n - 1]) - SymetricAbs(b[bn - 1])) >= 0) {
            nmul(&div, 1, b, bn, &change, &change_n);
            div++;

            if (Znak(rest[rest_n - 1]) == Znak(b[bn - 1])) {
                SubtractInPlace(&rest, &rest_n, change, change_n);
            }
            else {
                AddInPlace(&rest, &rest_n, change, change_n);
                div *= -1;
            }
            
            result[result_n] = UnSymetric(div);
            result_n++;
            free(change);
        }
        // Means that rest is negative.
        if (rest_n > 0 && Znak(rest[rest_n - 1]) < 0) {
            result[result_n] = UnSymetric(-Znak(b[bn - 1]));
            result_n++;

            if (Znak(b[bn - 1]) > 0) 
                AddInPlace(&rest, &rest_n, b, bn);
            else 
                SubtractInPlace(&rest, &rest_n, b, bn);
        }
        CompleteCorrect(&result, &result_n, false);
    }
    *q = result;
    *qn = result_n;
    *r = rest;
    *rn = rest_n;
}