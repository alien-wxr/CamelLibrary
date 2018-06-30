/**
 * @brief Standard Argument Definition
 *
 * @file stdarg.h
 * @author Zhirui Dai
 * @date 2018-05-27
 */

#ifndef __STDARG_H__
#define __STDARG_H__

typedef char* my_va_list;

/**
 * @brief Calculate the size of type as a multiple of int.
 * @param type  The type to calculate
 */
#define _INTSIZEOF(type)    ((sizeof(type) + sizeof(int) - 1) & ~(sizeof(int) - 1))
/**
 * @brief Calculate the beginning of changable parameter list.
 * @param ap   The pointer to the parameter list (including fixed) for a function.
 * @param value    The type of the value before the changable parameter list.
 */
//#define my_va_start(ap, value)   (ap = (my_va_list)&value + _INTSIZEOF(value))
my_va_list my_va_start(char* value)
{
    while (*value) {
        value++;
    }
    return ++value;
}

/**
 * @brief Get the value which the pointer points to.
 * @param ap   The pointer to the current parameter to get.
 * @param type  The type of the current parameter.
 */
#define my_va_arg(ap, type)   (*(type*)(ap))

/**
 * @brief Set next parameter as the first one.
 * @param ap The pointer to the current parameter to update.
 * @param type The type of the current parameter.
 */
#define my_va_next(ap, type)   ((my_va_list)&(((type*)(ap))[1]))
/**
 * @brief Release the parameter pointer by setting it NULL.
 * @param ap   The pointer to the function parameter list.
 */
#define my_va_end(ap) (ap = (char*)0)

#endif
