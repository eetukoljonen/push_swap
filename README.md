# push_swap

Push Swap is a sorting algorithm project that involves manipulating two stacks, a and b, to arrange a random set of numbers in ascending order within stack a. The goal is to achieve this by using a set of defined operations. This README will provide an overview of the project, its rules, and how to use it.

# Rules

1. **Stacks:** You have two stacks, a and b.

2. **Initial Configuration:**

   * Stack a contains a random assortment of negative and/or positive numbers, with no duplicates.
   * Stack b is initially empty.
3. **Objective:** The primary objective is to sort the numbers in stack a in ascending order.

# Operations
To achieve the sorting goal, you have the following operations at your disposal:

 * **sa** (swap a): Swap the first two elements at the top of stack a. If there's only one or no element, do nothing.

 * **sb** (swap b): Swap the first two elements at the top of stack b. If there's only one or no element, do nothing.

 * **ss** Perform sa and sb simultaneously.

 * **pa** (push a): Take the first element from the top of stack b and place it at the top of stack a. If stack b is empty, do nothing.

 * **pb** (push b): Take the first element from the top of stack a and place it at the top of stack b. If stack a is empty, do nothing.

 * **ra** (rotate a): Shift all elements in stack a up by one position. The first element becomes the last one.

 * **rb** (rotate b): Shift all elements in stack b up by one position. The first element becomes the last one.

 * **rr** Perform ra and rb simultaneously.

 * **rra** (reverse rotate a): Shift all elements in stack a down by one position. The last element becomes the first one.

 * **rrb** (reverse rotate b): Shift all elements in stack b down by one position. The last element becomes the first one.

 * **rrr** Perform rra and rrb simultaneously.

 # Usage

 To use Push Swap, follow these steps:

 1. Clone the repository to your local machine:
  ```
  git clone https://github.com/eetukoljonen/push_swap.git
  ```
2. Compile the program
  ```
  make
  ```
3. Run Push Swap with a list of integers you want to sort in stack a.
   Replace <numbers> with your list of integers:
```
./push_swap <numbers>
```
4. Push Swap will display a series of instructions that, when executed, will sort the numbers in stack a.

# Example
