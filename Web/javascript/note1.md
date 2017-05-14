<head><meta charset="UTF-8"></head>
# javascript-note1
## 基础
1. 花括号{...}内的语句具有缩进，通常是4个空格。
2. 注释：//，/*...*/
3. 调试: 查看变量的内容，在Console中输入console.log(a);
4. 语法: 每个语句以;结束。让JavaScript引擎自动加分号在某些情况下会改变程序的语义，导致运行结果与期望不一致。所以写的时候，自己加；。
5. JavaScript 对大小写是敏感的。

* `<script> 和 </script>` 之间的代码行包含了 JavaScript,JavaScript 是所有现代浏览器以及 HTML5 中的默认脚本语言。
*  一些小实例

```
<script>
// 写入 HTML 输出
document.write("<h1>This is a heading</h1>");

function myFunction()
{
x=document.getElementById("demo");  // 找到元素
x.innerHTML="Hello JavaScript!";    // 改变内容
}

function myFunction()
{
x=document.getElementById("demo") // 找到元素
x.style.color="#ff0000";          // 改变样式
}

function myFunction()
{
var x=document.getElementById("demo").value; // 验证输入
if(x==""||isNaN(x))
	{
	alert("Not Numeric");
	}
}
</script>

// 对事件做出反应
<button type="button" onclick="alert('Welcome!')">点击这里</button>

<button type="button" onclick="myFunction()">点击这里</button>
```

*  外部的 JavaScript `<script src="myScript.js"></script>`

## JS变量&数据类型
* 变量 var，JavaScript 拥有动态类型。这意味着相同的变量可用作不同的类型。
* JavaScript 数组
```
下面的代码创建名为 cars 的数组：
var cars=new Array();cars[0]="Audi";cars[1]="BMW";cars[2]="Volvo";
或者 (condensed array): var cars=new Array("Audi","BMW","Volvo");
或者 (literal array): var cars=["Audi","BMW","Volvo"];
```
* JavaScript 对象(属性、方法)
```
var person={firstname:"Bill", lastname:"Gates", id:5566};
对象属性有两种寻址方式：
name=person.lastname;
name=person["lastname"];
```
* 声明变量类型,(JavaScript 变量均为对象。当您声明一个变量时，就创建了一个新的对象。)
```
当您声明新变量时，可以使用关键词 "new" 来声明其类型：
var carname=new String;var x=      new Number;
var y=new Boolean;var cars=   new Array;var person= new Object;
```
* 变量作用范围
    * 局部 JavaScript 变量: 在 JavaScript 函数内部声明的变量（使用 var）是局部变量，所以只能在函数内部访问它。（该变量的作用域是局部的）。只要函数运行完毕，本地变量就会被删除。
    * 全局 JavaScript 变量: 在函数外声明的变量是全局变量，网页上的所有脚本和函数都能访问它。
    * avaScript 变量的生存期: 局部变量会在函数运行以后被删除。全局变量会在页面关闭后被删除。
    * 向未声明的 JavaScript 变量来分配值: 如果您把值赋给尚未声明的变量，该变量将被自动作为全局变量声明。这条语句：carname="Volvo";将声明一个全局变量 carname，即使它在函数内执行。
## JavaScript 错误 - Throw、Try 和 Catch
```
<script>
var txt="";
function message()
{
try
  {
  adddlert("Welcome guest!");
  }
catch(err)
  {
  txt="There was an error on this page.\n\n";
  txt+="Error description: " + err.message + "\n\n";
  txt+="Click OK to continue.\n\n";
  alert(txt);
  }
}
</script>

<script>
function myFunction()
{
try
  {
  var x=document.getElementById("demo").value;
  if(x=="")    throw "empty";
  if(isNaN(x)) throw "not a number";
  if(x>10)     throw "too high";
  if(x<5)      throw "too low";
  }
catch(err)
  {
  var y=document.getElementById("mess");
  y.innerHTML="Error: " + err + ".";
  }
}
</script>
```
## JavaScript HTML DOM
通过 HTML DOM，可访问 JavaScript HTML 文档的所有元素。
HTML DOM （文档对象模型）,当网页被加载时，浏览器会创建页面的文档对象模型（Document Object Model）。
* JavaScript 能够改变页面中的所有 HTML 元素
* JavaScript 能够改变页面中的所有 HTML 属性
* JavaScript 能够改变页面中的所有 CSS 样式
* JavaScript 能够对页面中的所有事件做出反应
