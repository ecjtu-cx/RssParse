# RssParse
使用tinyxml2库，解析RSS
### 解析之后的格式如下
```xml
<doc>
	<docid>1</docid>
	<title>...</title>
	<link>...</link>
	<description>...</description>
	<content>...</content>
</doc>
<doc>
	<docid>2</docid>
	<title>...</title>
	<link>...</link>
	<description>...</description>
	<content>...</content>
</doc>
<doc>
  ...
</doc>
```
### 环境
1.linux操作系统
2.g++编译器
3.使用cmake工具
### 文件说明
1.RssParse中是解析类的实现
2.TinyXml是tinyxml库的源文件
3. .cache文件中是vscode中clangd插件生成的索引，可以忽略