![](.README/header.png)

# tinyO
Numerical optimization assignments and lab work completed as part of my undergraduate coursework at Sister Nivedita University. 

Can't figure out how to run the code? Have a look at [Setup](#setup).

--- 

## Questions
| Sl. No. | Name | Link | 
|  :-     | :-   | :-   |
|  1.     | Bisection | [Link](#1--bisection) |
|  2.     | Tabular Bisection | [Link](#2-tabular-bisection) |
|  3.     | Regula Falsi | [Link](#3-regula-falsi) |
|  4.     | Newton Raphson | [Link](#4-newton-raphson) |
|  5.     | Integration    | [Link](#5-integration) |
|  6.     | Differential Equation  | [Link](#6-differential-equations) |

### 1.  Bisection
WAP in C to find the root of the equation of $x^3 - x - 1$ using the interval $[0, 2]$.

`Answer` [bisection.c](src/Roots/bisection.c)

`Output Terminal`
```
Finding root of the equation x^3 + x - 1. Using a = 0, b = 2
--- INPUT ---
 - Enter precision: 0.005

--- OUTPUT ---
Approximate root: 1.324219. After 9 iterations
```

> [!NOTE]
> Bisection is one of the methods used to approximate the root of an equation. It works by finding two points where the value of the function has opposite signs, i.e., $f(a) \times f(b) < 0$, and then finds the root using the [Intermediate Value Theorem](https://en.wikipedia.org/wiki/Intermediate_value_theorem).
>
> As it divides its length in half each iteration, given the target precision, we can calculate the least number of iterations required to reach that precision.

Let the target precision be $p$ and the initial length be $l$:

$$
\begin{aligned}
\frac{l}{2^i} &\le p \\
\frac{l}{p} &\le 2^i \\
i &\ge \log_2{\left(\frac{l}{p}\right)}
\end{aligned}
$$

So, the minimum number of iterations should be $\log_2{\left(\frac{l}{p}\right)}$. In the program, we use the `ceil` function to round it up to the nearest integer.

### 2. Tabular Bisection
WAP in C to approximate the root of a given equation using Bisection and represent the data for each interation in form of a table.

`Answer` [tabularBisection.c](src/Roots/tabularBisection.c)

`Output Terminal`
```
--- [INPUT] ---
 - Enter number of iterations/precision: 0.01

--- [OUTPUT] ---
| i  |     a      |      b     |    f(a)    |    f(b)    |     m      |    f(m)    |
------------------------------------------------------------------------------------
| 01 |  0.000000  |  2.000000  | -1.000000  |  5.000000  |  1.000000  | -1.000000  |
| 02 |  1.000000  |  2.000000  | -1.000000  |  5.000000  |  1.500000  |  0.875000  |
| 03 |  1.000000  |  1.500000  | -1.000000  |  0.875000  |  1.250000  | -0.296875  |
| 04 |  1.250000  |  1.500000  | -0.296875  |  0.875000  |  1.375000  |  0.224609  |
| 05 |  1.250000  |  1.375000  | -0.296875  |  0.224609  |  1.312500  | -0.051514  |
| 06 |  1.312500  |  1.375000  | -0.051514  |  0.224609  |  1.343750  |  0.082611  |
| 07 |  1.312500  |  1.343750  | -0.051514  |  0.082611  |  1.328125  |  0.014576  |
| 08 |  1.312500  |  1.328125  | -0.051514  |  0.014576  |  1.320313  | -0.018711  |
```

```
--- [INPUT] ---
 - Enter number of iterations/precision: 3

--- [OUTPUT] ---
| i  |     a      |      b     |    f(a)    |    f(b)    |     m      |    f(m)    |
------------------------------------------------------------------------------------
| 01 |  0.000000  |  2.000000  | -1.000000  |  5.000000  |  1.000000  | -1.000000  |
| 02 |  1.000000  |  2.000000  | -1.000000  |  5.000000  |  1.500000  |  0.875000  |
| 03 |  1.000000  |  1.500000  | -1.000000  |  0.875000  |  1.250000  | -0.296875  |
```

> [!TIP]
> The program supports both number of iterations and a specific precision value. That is being done by checking whether the input value is a whole number or not. In this program we are checking that by comparing the rounded off number with itself, but there are several other ways of doing it as well.

> [!NOTE]
> The programs following this for root finding will use the tabular version of the program as it is easier to view the steps.

### 3. Regula Falsi
WAP in C to approximate the root of a given equation using [Regula Falsi](https://en.wikipedia.org/wiki/Regula_falsi) and represent the data for each interation in form of a table.

> [!TIP]
> Regula Falsi is very similar to Bisection. The major difference lies as to how the new point is found. In Bisection we find it by finding the mid point of the interval points. Where as in Regula Falsi we find it using the given formula -  
> ```math 
> m = \frac{a \times f(b) - b \times f(a)}{f(b) - f(a)}
> ```

`Answer` [regulaFalsi.c](src/Roots/regulaFalsi.c)

`Output Terminal`
```
--- [INPUT] ---
 - A: 2
 - B: 3
 - Iterations/precision: 5

--- [OUTPUT] ---
| i  |     a      |      b     |    f(a)    |    f(b)    |     m      |    f(m)    |
------------------------------------------------------------------------------------
| 01 |  2.000000  |  3.000000  | -9.000000  |  6.000000  |  2.600000  | -1.824002  |
| 02 |  2.600000  |  3.000000  | -1.824002  |  6.000000  |  2.693252  | -0.237225  |
| 03 |  2.693252  |  3.000000  | -0.237225  |  6.000000  |  2.704918  | -0.028912  |
| 04 |  2.704918  |  3.000000  | -0.028912  |  6.000000  |  2.706333  | -0.003497  |
| 05 |  2.706333  |  3.000000  | -0.003497  |  6.000000  |  2.706504  | -0.000424  |
Approximate root: 2.706504
```

```
--- [INPUT] ---
 - A: 2
 - B: 3
 - Iterations/precision: 0.5

--- [OUTPUT] ---
| i  |     a      |      b     |    f(a)    |    f(b)    |     m      |    f(m)    |
------------------------------------------------------------------------------------
| 01 |  2.000000  |  3.000000  | -9.000000  |  6.000000  |  2.600000  | -1.824002  |
| 02 |  2.600000  |  3.000000  | -1.824002  |  6.000000  |  2.693252  | -0.237225  |
Approximate root: 2.693252
```

> [!NOTE]
> Unlike Bisection we don't have a set formula to reach a certain precision using `n` steps. Thus we manually check the value and iterate till the value is under the target precision.

### 4. Newton Raphson
WAP in C to approximate the root of a given equation using [ Newton Raphson](https://en.wikipedia.org/wiki/Newton%27s_method) and represent the data for each interation in form of a table.

> [!NOTE]
> This method unlike the previously discussed methods doesn't use an interval, instead it uses an initial point and then calculates the next points using a specific formula - 
> ```math
> x_{n+1} = x_n - \frac{f(x_n)}{f'(x_n)}
> ```

`Answer` [newtonRaphson.c](src/Roots/newtonRaphson.c)

`Output Terminal`
```
--- [INPUT] ---
 - x_0: 0
 - Iterations/precision: 4
| i  |      x      |    f(x)    |    f'(x)    |
-----------------------------------------------
| 01 |   0.000000  |  3.000000  | -9.000000  |
| 02 |   0.333333  |  0.037037  | -8.666667  |
| 03 |   0.337607  |  0.000018  | -8.658065  |
| 04 |   0.337609  | -0.000000  | -8.658061  |

--- [OUTPUT] ---
Root: 0.337609
```

```
--- [INPUT] ---
 - x_0: 0
 - Iterations/precision: 0.5
| i  |      x      |    f(x)    |    f'(x)    |
-----------------------------------------------
| 01 |   0.000000  |  3.000000  | -9.000000  |
| 02 |   0.333333  |  0.037037  | -8.666667  |

--- [OUTPUT] ---
Root: 0.333333
```

### 5. Integration
WAP in C to approxiate the definite integral of a given function using 
- [Midpoint Method](https://math.libretexts.org/Courses/Mount_Royal_University/Calculus_for_Scientists_II/2%3A_Techniques_of_Integration/2.5%3A_Numerical_Integration_-_Midpoint%2C_Trapezoid%2C_Simpson's_rule)
- [Trapeziodal Method](https://en.wikipedia.org/wiki/Trapezoidal_rule)
- [Simpson's $\frac{1}{3}^{rd}$ Method](https://en.wikipedia.org/wiki/Simpson%27s_rule)

`Answer` [integration.c](src/Integration/integration.c)

`Output Terminal`
```
--- INPUT ---
 - Enter n: 6
 - Enter interval: 1 3

--- OUTPUT ---
 - Midpoint  Appoximation  : 8.648149
 - Trapeziod Approximation : 8.703704
 - Simpsons  Approximation : 8.666667
```

### 6. Differential Equations
WAP in C to approximate the value of a function at a given point `x`. Using the derivate. Using the following methods - 
- [Euler's Method](https://en.wikipedia.org/wiki/Euler_method)
- [RK4 Method](https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta_methods)

`Answer` [differentialEquations.c](src/DifferentialEquations/differentialEquations.c)

`Output Terminal`
```
--- INPUT ---
 - x0: 0
 - y0: 1
 -  h: 0.2
 - xT: 5

--- OUTPUT ---
Euler's Method: f(5.000000): 184.792542
RK 4    Method: f(5.000000): 290.809784
```

### Setup
All C programs in this repository were written and tested on Windows using:

- [MinGW](https://www.mingw-w64.org/) as the GCC compiler
- [Visual Studio Code](https://code.visualstudio.com/) as the editor
- [Code Runner extension](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner) to easily compile and run .c files with a single shortcut key

#### Installing MinGW using Chocolatey
To install the MinGW compiler, I used [Chocolatey](https://chocolatey.org/), a Windows package manager. If you want to install choco, you can follow this [guide](https://chocolatey.org/install).

And then you can install the compiler by pasting this command in your command prompt  
```
choco install mingw
```
> [!TIP]
> You will be recommended to do this while running the shell as an Administrator.

#### Running  the code
Press `Ctrl + Alt + N` to compile and run the code (using the [Code Runner extension](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)).
The output will appear in the `OUTPUT` tab of the integrated terminal. You can also change the keyboard shortcut in `Settings` or create a custom macro for it.