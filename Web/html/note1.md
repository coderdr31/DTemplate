<head><meta charset="UTF-8"></head>

## 基础
* 标题 <h1> - <h6>
* 段落 <p>
* 链接 <a> `<a href="http://www.w3school.com.cn">This is a link</a>`
  ```
  HTML 链接 - name 属性 - 命名锚
  实例
  首先，我们在 HTML 文档中对锚进行命名（创建一个书签）：
  <a name="tips">基本的注意事项 - 有用的提示</a>
  然后，我们在同一个文档中创建指向该锚的链接：
  <a href="#tips">有用的提示</a>
  您也可以在其他页面中创建指向该锚的链接：
  <a href="http://www.w3school.com.cn/html/html_links.asp#tips">有用的提示</a>
  在上面的代码中，我们将 # 符号和锚名称添加到 URL 的末端，就可以直接链接到 tips 这个命名锚了。
  注释：请始终将正斜杠添加到子文件夹
  ```
* 图像 <img> `<img src="w3school.jpg" alt="替换文本图无显" width="104" height="142" />`
* 换行 <br />
* 水平线 <hr />
* 注释 `<!-- This is a comment -->`
* 样式style `<p style="font-family:arial;color:red;font-size:20px;">A paragraph.</p>`
  font-family、color 以及 font-size 、text-align 属性分别定义元素中文本的字体系列、颜色和字体尺寸、水平对齐方式
* 预格式文本 <pre> 它保留了空格和换行,很适合显示计算机代码。 <code> 元素不保留多余的空格和折行
* 表格 <table> <tr> <td> &nbsp;空格占位符
* 列表
  无序列表始于 <ul> 标签。每个列表项始于 <li>。
  有序列表始于 <ol> 标签。每个列表项始于 <li> 标签。
  自定义列表以 <dl> 标签开始。每个自定义列表项以 <dt> 开始。每个自定义列表项的定义以 <dd> 开始。
* 框架 <frameset>
* 脚本 `<script> <script type="text/javascript">`
* 表单 <form>

* 元素(标签)、属性、内容
* 浏览器忽略了源代码中的排版,所有连续的空格或空行都会被算作一个空格。需要注意的是，HTML 代码中的所有连续的空行（换行）也被显示为一个空格。

### HTML 块
块级元素在浏览器显示时，通常会以新行来开始（和结束）。`例子：<h1>, <p>, <ul>, <table>, <div>`
<div> 元素是块级元素，它是可用于组合其他 HTML 元素的容器。

内联元素在显示时通常不会以新行开始。`例子：<b>, <td>, <a>, <img>, <span>`
<span> 元素是内联元素，可用作文本的容器。

Box Model: 任意一个块级元素均由content(内容), padding(控制块级元素内部, content与border之间的距离), background(包括背景颜色和图片), border(边框), margin(控制块级元素之间的距离, 它们是透明不可见的)五个部分组成.

### HTML 类
分类块级元素
```
<style>
.cities {
    background-color:black;
    padding:20px;
}
</style>
<div class="cities">
<h2>London</h2>
<p>London is the capital city of England.
with a metropolitan area of over 13 million inhabitants.</p>
</div>
```

分类行内元素
```
<style>
  span.red {color:red;}
</style>

<h1>My <span class="red">Important</span> Heading</h1>
```
### 框架
```
<frameset cols="25%,75%">
   <frame src="frame_a.htm">
   <frame src="frame_b.htm">
</frameset>
```
内联框架 `<iframe src="URL"></iframe>`

