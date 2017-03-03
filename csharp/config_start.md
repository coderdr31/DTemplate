<head><meta charset="UTF-8"></head>
# install
> sudo apt install mono-complete monodevelop
> mcs 1.cs 生成1.exe —> mono 1.exe

# 基本语法
1. `Console.ReadKey();`、`Console.ReadLine();` 使得程序会等待一个按键的动作,防止程序会快速运行并关闭。
2. `Console.WriteLine("a = {0}, b = {1}, c = {2}", a, b, c);`
3. 接受来自用户的值
  System 命名空间中的 Console 类提供了一个函数 ReadLine()，用于接收来自用户的输入，并把它存储到一个变量中。
  ```
  int num;
  num = Convert.ToInt32(Console.ReadLine());
  ```
  函数 Convert.ToInt32() 把用户输入的数据转换为 int 数据类型，因为 Console.ReadLine() 只接受字符串格式的数据。
4. 字符串常量
  ```
  string c = "hello \t world";               // hello     world
  string d = @"hello \t world";               // hello \t world
  ```
  > const double pi = 3.14159; // 常量声明
5. 可空类型（Nullable） int? num1 = null;
6. 实例
  ```
  using System;   //using 关键字表明程序使用的是给定命名空间中的名称
  namespace HelloWorldApplication
  {
      class HelloWorld
      {
          static void Main(string[] args)
          {
              /* 我的第一个 C# 程序*/
              Console.WriteLine("Hello World!");  //使用 using 命名空间指令，这样在使用的时候就不用在前面加上命名空间名称。 System.Console.WriteLine("Hello World!");
              )
              Console.ReadKey();
          }
      }
  }
  ```
