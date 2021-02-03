#ifndef H_MATH
#define H_MATH

/**//**
 * \brief Math library.
 *
 * A basic math library containing templated
 * methods.
 *
 * Operator checks will be implemented in the future.
 */
namespace Math {
    /**//**
     * Add two elements together and return result.
     * 
     * @param a,b must be of same type which have a
     * well defined the plus operator (+).
     */
    template<typename T>
    T add(T a, T b) {
        return a + b;
    }

    int testMethod(bool val);
}

#endif
