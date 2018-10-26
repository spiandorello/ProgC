#ifndef MACROS_H_INCLUDED
#define MACROS_H_INCLUDED

#define SET_BIT(y,bit) y = (y | (1 << bit))
#define CLR_BIT(y,bit) y = (y & ~(1 << bit))
#define CPL_BIT(y,bit) y = (y ^ (1 << bit)) //(^) operador xor
#define TST_BIT(y,bit) y & (1 << bit)

#endif // MACROS_H_INCLUDED
