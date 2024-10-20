# 什么事函数式编程

- 进行函数进行编程
- 函数是「一等公民」
- 具有「引用透明性」的编程方式

    > 「引用透明性」 ：  如果给定一个函数及其输入值，那么无论何时调用该函数，无论调用多少次，
    >  输出值都将始终相同
- 具有基于lambda演算的编程风格

作者认为最重要的是**没有赋值语句的编程**

```c
int n = 1;
int sum = 0;

int done() { return n > 10; }

void doSomething() {
  sum += n * n;
  ++n;
}


int sumFirstTenSquares() {
  while (!done()) {
    doSomething();
  }
}
```
上面的代码不是函数编程，因为`doSomething`有两条赋值语句，可以做一些改造

```c
int sumFirstTenSquaresHelper(int sum, int i) {
  if (i > 0)
    return sum;
  return sumFirstTenSquaresHelper(sum + i * i, i + 1);
}



int sumFirstTenSquares() {
  return sumFirstTenSquaresHelper(0, 1);
}
```
虽然是函数式的了，但是这个方式也是递归的， *如果想摆脱赋值语句，就必须使用递归*。但这种写法会消耗大量的栈空间。

尾调用优化(Tail Call Optimization, TCO): 最后一次调用`sumFirstTenSquaresHelper`时也是该函数最后一次使用sum和i，如果不为递归调用创建一个新的栈帧，而是通过`goto`跳回函数的顶部来重用当前的栈空间。其实可以这么看：

```c
int sumFirstTenSquaresHelper(int sum, int i) {
loop:
  if (i > 10)
    return sum;
  sum += i * i;
  i++;
  goto loop;
}

int sumFirstTenSquares() {
  return sumFirstTenSquaresHelper(0, 1);
}
```
那这是否意味着这个方式就是函数式编程呢，答案是不是的。



# 赋值的问题

首先为赋值下定义：**为变量赋值会将变量的原始值更改为新赋的值**。函数式编程就是没有变量的编程，函数式程序中的值不会变化。

条件编程的结果，也就是赋值进行编程的自然结果。
- 时序耦合
- 竞态条件


函数`f`不存在时许耦合，也就是说函数式程序是真函数，如果将函数式程序分解成多个小函数，那么每个小函数在数学意义上也是真函数，这被称为*引用透明性*


# 状态

函数式程序可以根据旧状态计算新状态，但并不改变旧状态。