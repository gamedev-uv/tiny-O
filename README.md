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

### 1.  Bisection
WAP in C to find the root of the equation of $x^3 - x - 1$ using the interval $[0, 2]$.

`Answer` [bisection.c](src/Bisection/bisection.c)

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
WAP in C and represent the data for each interation in form of a table.

`Answer` [tabularBisection.c](src/Bisection/tabularBisection.c)

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